#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QFileDialog>
#include <QFile>
#include <iostream>
#include <QTextBrowser>
#include <QInputDialog>
#include <QIODevice>
#include <QTextStream>
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
