#include "teamdialog.h"
#include "ui_teamdialog.h"

TeamDialog::TeamDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeamDialog)
{
    ui->setupUi(this);
}

TeamDialog::~TeamDialog()
{
    delete ui;
}
