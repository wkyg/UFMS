#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "register.h"
#include "ui_register.h"
#include "manage.h"
#include "ui_manage.h"
#include "booking.h"
#include "ui_booking.h"
#include "resetpw.h"
#include "ui_resetpw.h"
#include <QtSql>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    int passwordecho;
    QString accid;
    QString user, pass, username, password;
    QSqlDatabase db;
    void dbclosed();
    bool dbopened();
    ~MainWindow();

private slots:
    void on_btn_Register_clicked();
    void on_btn_Login_clicked();
    void on_btn_passhideview_clicked();
    void on_btn_Resetpw_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
