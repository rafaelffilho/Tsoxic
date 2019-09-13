#ifndef TEAMDIALOG_H
#define TEAMDIALOG_H

#include <QDialog>

namespace Ui {
class TeamDialog;
}

class TeamDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TeamDialog(QWidget *parent = nullptr);
    ~TeamDialog();

private:
    Ui::TeamDialog *ui;
};

#endif // TEAMDIALOG_H
