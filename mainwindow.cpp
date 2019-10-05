#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "common.h"

#include <QString>
#include <QFileDialog>
#include <QFile>
#include <iostream>
#include <QTextBrowser>
#include <QInputDialog>
#include <QIODevice>
#include <QTextStream>
#include <QShortcut>

extern FILE *yyin;
int yyline;
extern char *yytext;
extern int line_num;
extern "C" int yylex();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), this, SLOT(close()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_N), this, SLOT(on_bt_new_clicked()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_O), this, SLOT(on_bt_open_clicked()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_S), this, SLOT(on_bt_save_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bt_new_clicked()
{
    if (file)
        return;
   QString fileName = QInputDialog::getText(this, "File name", "Name to be saved");
   ui->tb_status->setText(fileName);
   file = new QFile(fileName);
   file->open(QIODevice::ReadWrite | QIODevice::Text);
}

void MainWindow::on_bt_open_clicked()
{
    if (file)
        return;
    QString fileName = QFileDialog::getOpenFileName(this,"Open Tsoxic File", "", "Tsoxic Files (*.tsx)");
    ui->tb_status->setText(fileName);
    file = new QFile(fileName);
    if (!file->open(QIODevice::ReadWrite | QIODevice::Text))
        return;

    while (!file->atEnd()) {
        QString buf = file->readLine();
        buf[buf.size() - 1] = '\0';
        ui->te_code_area->append(buf);
    }
}

void MainWindow::on_bt_save_clicked()
{
    if (!file)
        return;

    file->resize(0);

    QTextStream out(file);

    out << ui->te_code_area->toPlainText();

}

void MainWindow::on_bt_copy_clicked()
{
    ui->te_code_area->copy();
}

void MainWindow::on_bt_paste_clicked()
{
    ui->te_code_area->paste();
}

void MainWindow::on_bt_cut_clicked()
{
    ui->te_code_area->cut();
}

void MainWindow::on_bt_team_clicked()
{
    teamDialog = new TeamDialog();
    teamDialog->show();
}

void MainWindow::on_bt_compile_clicked()
{
    if (!file){
        ui->tb_status->setText("None file open");
        return;
    }

    int i;

    ui->tb_compilation_log->clear();

    yyin = fopen(file->fileName().toStdString().c_str(), "r");

    if (!yyin) {
        ui->tb_status->setText("Failed to load file");
        return;
    }

    while((i = yylex()) != 0) {
        std::string f = "Found ";

        bool error = false;

        switch (i) {
            case SYMBOL: {
                f.append("SYMBOL ");
                break;
            }
            case KEYWORD: {
                f.append("KEYWORD ");
                break;
            }
            case ID_INT: {
                f.append("ID_INT ");
                break;
            }
            case ID_FLOAT: {
                f.append("ID_FLOAT ");
                break;
            }
            case ID_STR: {
                f.append("ID_STR ");
                break;
            }
            case ID_BOOL: {
                f.append("ID_BOOL ");
                break;
            }
            case ID_COMP: {
                f.append("ID_COMP ");
                break;
            }
            case C_INT: {
                f.append("C_INT ");
                break;
            }
            case C_FLOAT: {
                f.append("C_FLOAT ");
                break;
            }
            case C_STR: {
                f.append("C_STR ");
                break;
            }
            case ERR_ID: {
                f.append("ERR_ID ");
                error = true;
                break;
            }
            case ERR_STR: {
                f.append("ERR_STR ");
                error = true;
                break;
            }
            case ERR_BLK: {
                f.append("ERR_BLK ");
                error = true;
                break;
            }
            case ERR_UNK: {
                f.append("ERR_UNK ");
                error = true;
                break;
            }
        }

        f.append("at line: " + std::to_string(yyline));
        f+=" (";
        f.append(yytext);
        f+=")";

        ui->tb_compilation_log->append(QString::fromStdString(f));

        if (error) break;
    }

    line_num = 1;

    fclose(yyin);
}
