#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_bt_new_clicked();

    void on_bt_open_clicked();

    void on_bt_save_clicked();

    void on_bt_copy_clicked();

    void on_bt_paste_clicked();

    void on_bt_cut_clicked();

private:
    QFile *file = nullptr;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
