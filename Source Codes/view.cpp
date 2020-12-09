#include "view.h"
#include "ui_view.h"
#include "manage.h"
#include "ui_manage.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QTimer>
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include <QtSql>
#include <QDebug>
#include <QDataStream>
#include <QMessageBox>
#include <QDialog>

view::view(QWidget *parent) : QMainWindow(parent), ui(new Ui::view)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(displaytime()));
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(currentsession()));
    MainWindow m;
    m.dbopened();
    if (!m.dbopened()){ui->db_lbl->setText("Failed to connect to UFMS...");}
    else{ui->db_lbl->setText("Connected to UFMS!");}
    m.dbclosed();

}

view::~view()
{
    delete ui;
}

void view::currentsession(){
    QFile currentuser("G:/Degree/Sem3(1910)/TSE2101 - Software Engineering Fundamentals/Assignments/Programming/Combine/Combine/currentuser.txt");
    currentuser.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&currentuser);
    in>>username>>accid;
    ui->currentuser_lbl->setText(username);
    currentuser.flush();
    currentuser.close();
}

void view::on_listView_activated(const QModelIndex &index)
{
    bookidval=ui->listView->model()->data(index).toString();
    ui->label->setText(bookidval);

}

void view::on_pushButton_clicked()
{
    bookid=ui->label->text();
    MainWindow m;
    m.dbopened();
    QSqlQuery qry, qry1;
    QSqlQueryModel getfacbooked, getfaccount;
    getfacbooked.setQuery("Select facilities_booked, facilities_id from userbookingdata where booking_id = '"+bookidval+"'");
    for (int i = 0; i < getfacbooked.rowCount(); i++){
        facbooked = getfacbooked.record(i).value("facilities_booked").toString();
        facid = getfacbooked.record(i).value("facilities_id").toString();}
    int facbookval = facbooked.split(" ")[0].toInt();
    getfaccount.setQuery("Select facilities_count from facilitiesavailability where facilities_id = '"+facid+"'");
    for (int i = 0; i < getfaccount.rowCount(); i++){
        faccount = getfaccount.record(i).value("facilities_booked").toString();}
    int faccountval = faccount.split(" ")[0].toInt();
    int newcount = facbookval + faccountval;
    QString newfaccount = QString::number(newcount);
    qry1.exec("Update facilitiesavailability,userbookingdata,userdata set FACILITIES_COUNT = '"+newfaccount+"' where userbookingdata.acc_id = '"+accid+"' and facilitiesavailability.facilities_id=userbookingdata.facilities_id group by userbookingdata.booking_id");
    qry.exec("Delete from userbookingdata where userbookingdata.acc_id = '"+accid+"' and userbookingdata.BOOKING_ID='"+bookid+"'");
    QMessageBox msgBox;
    msgBox.setText("Selected booked venue has been deleted.");
    msgBox.exec();

    m.dbclosed();
    hide();
    Manage *manage;
    manage = new Manage(this);
    manage->show();
}

void view::on_buttonreturn_clicked()
{
    hide();
    Manage *m;
    m = new Manage(this);
    m->show();
}


