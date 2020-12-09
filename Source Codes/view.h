#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QtSql>
#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace Ui {
class view;
}

class view : public QMainWindow
{
    Q_OBJECT

public:
    explicit view(QWidget *parent = nullptr);
    ~view();
     Ui::view *ui;
     QString bookid, bookidval, username, accid, facbooked, facid, faccount;

private slots:
     void currentsession();
     void on_listView_activated(const QModelIndex &index);
     void on_pushButton_clicked();
     void on_buttonreturn_clicked();
     void on_pushButton_3_clicked();

private:

};

#endif // VIEW_H
