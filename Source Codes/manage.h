#ifndef MANAGE_H
#define MANAGE_H

#include <QMainWindow>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "booking.h"
#include "ui_booking.h"

namespace Ui {
class Manage;
}

class Manage : public QMainWindow
{
    Q_OBJECT

public:
    explicit Manage(QWidget *parent = nullptr);
    Ui::Manage *ui;
    QString selectedstatus;
    QString username,accid, bookid, facbooked, facid, facval;
    ~Manage();

private slots:
    void on_btn_logout_clicked();
    void currentsession();
    void on_btn_newbook_clicked();
    void on_btn_viewbook_clicked();
    void on_btn_return_clicked();
    void on_btn_back_clicked();
    void on_btn_returnall_clicked();
    void on_listView_activated(const QModelIndex &index);
    void on_btn_viewava_clicked();
    void on_btn_viewbooked_clicked();
    void on_btn_updatestatus_clicked();
    void on_listViewstatus_clicked(const QModelIndex &index);
    void on_btn_update_clicked();
    void on_btn_back_2_clicked();

private:

};

#endif // MANAGE_H
