/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *te_code_area;
    QTextBrowser *tb_compilation_log;
    QTextBrowser *tb_status;
    QPushButton *bt_new;
    QPushButton *bt_open;
    QPushButton *bt_save;
    QPushButton *bt_copy;
    QPushButton *bt_paste;
    QPushButton *bt_cut;
    QPushButton *bt_compile;
    QPushButton *bt_team;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1010, 530);
        MainWindow->setMinimumSize(QSize(1010, 530));
        MainWindow->setMaximumSize(QSize(1010, 530));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        te_code_area = new QTextEdit(centralWidget);
        te_code_area->setObjectName(QString::fromUtf8("te_code_area"));
        te_code_area->setGeometry(QRect(110, 0, 900, 400));
        te_code_area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        te_code_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        te_code_area->setLineWrapMode(QTextEdit::NoWrap);
        tb_compilation_log = new QTextBrowser(centralWidget);
        tb_compilation_log->setObjectName(QString::fromUtf8("tb_compilation_log"));
        tb_compilation_log->setGeometry(QRect(110, 400, 900, 100));
        tb_compilation_log->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tb_compilation_log->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tb_compilation_log->setLineWrapMode(QTextEdit::NoWrap);
        tb_status = new QTextBrowser(centralWidget);
        tb_status->setObjectName(QString::fromUtf8("tb_status"));
        tb_status->setGeometry(QRect(0, 500, 1010, 30));
        bt_new = new QPushButton(centralWidget);
        bt_new->setObjectName(QString::fromUtf8("bt_new"));
        bt_new->setGeometry(QRect(0, 0, 110, 62));
        bt_new->setFlat(true);
        bt_open = new QPushButton(centralWidget);
        bt_open->setObjectName(QString::fromUtf8("bt_open"));
        bt_open->setGeometry(QRect(0, 62, 110, 62));
        bt_open->setFlat(true);
        bt_save = new QPushButton(centralWidget);
        bt_save->setObjectName(QString::fromUtf8("bt_save"));
        bt_save->setGeometry(QRect(0, 124, 110, 62));
        bt_save->setFlat(true);
        bt_copy = new QPushButton(centralWidget);
        bt_copy->setObjectName(QString::fromUtf8("bt_copy"));
        bt_copy->setGeometry(QRect(0, 186, 110, 62));
        bt_copy->setFlat(true);
        bt_paste = new QPushButton(centralWidget);
        bt_paste->setObjectName(QString::fromUtf8("bt_paste"));
        bt_paste->setGeometry(QRect(0, 248, 110, 62));
        bt_paste->setFlat(true);
        bt_cut = new QPushButton(centralWidget);
        bt_cut->setObjectName(QString::fromUtf8("bt_cut"));
        bt_cut->setGeometry(QRect(0, 310, 110, 62));
        bt_cut->setFlat(true);
        bt_compile = new QPushButton(centralWidget);
        bt_compile->setObjectName(QString::fromUtf8("bt_compile"));
        bt_compile->setGeometry(QRect(0, 372, 110, 62));
        bt_compile->setFlat(true);
        bt_team = new QPushButton(centralWidget);
        bt_team->setObjectName(QString::fromUtf8("bt_team"));
        bt_team->setGeometry(QRect(0, 434, 110, 62));
        bt_team->setFlat(true);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Tsoxic Code Editor", nullptr));
        bt_new->setText(QApplication::translate("MainWindow", "New", nullptr));
        bt_open->setText(QApplication::translate("MainWindow", "Open", nullptr));
        bt_save->setText(QApplication::translate("MainWindow", "Save", nullptr));
        bt_copy->setText(QApplication::translate("MainWindow", "Copy", nullptr));
        bt_paste->setText(QApplication::translate("MainWindow", "Paste", nullptr));
        bt_cut->setText(QApplication::translate("MainWindow", "Cut", nullptr));
        bt_compile->setText(QApplication::translate("MainWindow", "Compile", nullptr));
        bt_team->setText(QApplication::translate("MainWindow", "Team", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
