#include "manage.h"
#include "ui_manage.h"
#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include "booking.h"
#include "ui_booking.h"
#include <QFile>
#include <QTimer>
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include <QtSql>
#include <QDebug>
#include <QDataStream>




Manage::Manage(QWidget *parent) :QMainWindow(parent),ui(new Ui::Manage)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(currentsession()));
    timer->start();
    currentsession();
    if (username == "admin" && accid == "0"){
        ui->frameadmin->show();
        ui->frameuser->hide();
        ui->frame1->hide();
        ui->frameupdatestatus->hide();
    }
    else{
        ui->frameadmin->hide();
        ui->frameuser->show();
        ui->frame1->hide();
        ui->frameupdatestatus->hide();
    }
}

void Manage::currentsession(){
    QFile currentuser("G:/Degree/Sem3(1910)/TSE2101 - Software Engineering Fundamentals/Assignments/Programming/Combine/Combine/currentuser.txt");
    currentuser.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&currentuser);
    in>>username>>accid;
    ui->currentuser_lbl->setText(username);
    currentuser.flush();
    currentuser.close();
}

Manage::~Manage()
{
    delete ui;
}

void Manage::on_btn_logout_clicked()
{
    QMessageBox::StandardButton selection = QMessageBox::question(this,"Logout Confirmation","Are you sure you want to logout?", QMessageBox::Yes | QMessageBox::No);
    if (selection == QMessageBox::Yes){
        hide();
        MainWindow *m;
        m = new MainWindow(this);
        m->show();}
    else{}
}

void Manage::on_btn_newbook_clicked()
{
    hide();
    Booking *b;
    b = new Booking(this);
    b->ui->frameadmin2->hide();
    b->ui->frameadmin->hide();
    b->ui->frameuser->show();
    b->show();
}

void Manage::on_btn_viewbook_clicked()
{
    MainWindow m;
    m.dbopened();
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(m.db);
    qry->exec("Select booking_id, facilities_name, facilities_booked, dateofbooked, timeofbooked, status from userbookingdata where acc_id = '"+accid+"' group by booking_id");
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    QSqlQueryModel *modal1 = new QSqlQueryModel();
    QSqlQuery *qry1 = new QSqlQuery(m.db);
    qry1->exec("Select booking_id from userbookingdata where acc_id = '"+accid+"' AND status = 'OBSOLETE' group by booking_id");
    modal1->setQuery(*qry1);
    ui->listView->setModel(modal1);
    m.dbclosed();
    ui->frameuser->hide();
    ui->frame1->show();

}

void Manage::on_listView_activated(const QModelIndex &index)
{
    bookid = ui->listView->model()->data(index).toString();
    ui->label_4->setText(bookid);
}

void Manage::on_btn_return_clicked(){
    if (ui->label_4->text() == ""){QMessageBox::warning(this, "Warning", "Selection cannot be empty!");}
    else{
    MainWindow m;
    m.dbopened();
    QSqlQuery requestreturn;
    requestreturn.prepare("update userbookingdata set status = 'PENDING' where booking_id = '"+bookid+"' AND acc_id = '"+accid+"' AND status = 'OBSOLETE'");
    if(requestreturn.exec()){QMessageBox::information(this, "Return Success", "System is processing the current request!");}
    else{QMessageBox::information(this, "Return Failed", "System failed to process the current request!");}
    m.dbclosed();

    hide();
    Manage *manage;
    manage = new Manage(this);
    if (username == "admin" && accid == "0"){
        ui->frameadmin->show();
        ui->frameuser->hide();
        ui->frame1->hide();
        ui->frameupdatestatus->hide();
    }
    else{
        ui->frameadmin->hide();
        ui->frameuser->show();
        ui->frame1->hide();
        ui->frameupdatestatus->hide();
    }
    manage->show();}
}


void Manage::on_btn_returnall_clicked()
{
    MainWindow m;
    m.dbopened();
    QSqlQuery requestreturnall;
    requestreturnall.exec("update userbookingdata set status = 'PENDING' where acc_id = '"+accid+"' AND status = 'OBSOLETE'");
    m.dbclosed();
    QMessageBox::information(this, "Return Success", "System is processing the current request!");
    hide();
    Manage *manage;
    manage = new Manage(this);
    if (username == "admin" && accid == "0"){
        ui->frameadmin->show();
        ui->frameuser->hide();
        ui->frame1->hide();
        ui->frameupdatestatus->hide();
    }
    else{
        ui->frameadmin->hide();
        ui->frameuser->show();
        ui->frame1->hide();
        ui->frameupdatestatus->hide();
    }
    manage->show();
}


void Manage::on_btn_back_clicked()
{
    ui->frame1->hide();
    ui->frameuser->show();
}

void Manage::on_btn_viewava_clicked()
{
    hide();
    Booking *b;
    b = new Booking(this);
    MainWindow m;
    m.dbopened();
    QSqlQueryModel *modal4 = new QSqlQueryModel();
    QSqlQuery *qry4 = new QSqlQuery(m.db);
    qry4->prepare("Select * from facilitiesavailability group by facilities_id");
    qry4->exec();
    modal4->setQuery(*qry4);
    b->ui->table_availability->setModel(modal4);
    m.dbclosed();
    b->ui->frameadmin2->hide();
    b->ui->frameadmin->show();
    b->ui->frameuser->hide();
    b->show();
}

void Manage::on_btn_viewbooked_clicked()
{
    hide();
    Booking *b;
    b = new Booking(this);
    MainWindow m;
    m.dbopened();
    QSqlQueryModel *modal3 = new QSqlQueryModel();
    QSqlQuery *qry3 = new QSqlQuery(m.db);
    qry3->prepare("Select * from userbookingdata group by booking_id having status = 'OBSOLETE' OR status = 'PENDING' OR status = 'RETURNED' OR status = 'BOOKED'");
    qry3->exec();
    modal3->setQuery(*qry3);
    b->ui->table_bookings->setModel(modal3);
    m.dbclosed();
    b->ui->frameadmin2->show();
    b->ui->frameadmin->hide();
    b->ui->frameuser->hide();
    b->show();
}

void Manage::on_btn_updatestatus_clicked()
{
    ui->frameadmin->hide();
    ui->frameuser->hide();
    ui->frame1->hide();
    ui->frameupdatestatus->show();
    MainWindow m;
    m.dbopened();
    QSqlQueryModel *modalstatus = new QSqlQueryModel();
    QSqlQuery *loadstatus = new QSqlQuery(m.db);
    loadstatus->prepare("Select booking_id, status, acc_id, facilities_id,facilities_name,dateofbooked,timeofbooked from userbookingdata where status = 'PENDING' OR status = 'OBSOLETE' OR status = 'RETURNED' OR status = 'BOOKED'");
    loadstatus->exec();
    modalstatus->setQuery(*loadstatus);
    ui->tablestatus->setModel(modalstatus);
    QSqlQueryModel *modalstatus1 = new QSqlQueryModel();
    QSqlQuery *updatestatus = new QSqlQuery(m.db);
    updatestatus->prepare("Select booking_id from userbookingdata where status = 'PENDING'");
    updatestatus->exec();
    modalstatus1->setQuery(*updatestatus);
    ui->listViewstatus->setModel(modalstatus1);
    m.dbclosed();

}

void Manage::on_listViewstatus_clicked(const QModelIndex &index)
{
    selectedstatus = ui->listViewstatus->model()->data(index).toString();
    ui->labelselectedstatus->setText(selectedstatus);
}

void Manage::on_btn_update_clicked()
{
    MainWindow m;
    m.dbopened();
    QSqlQuery execupdate;
    qDebug()<<selectedstatus;
    execupdate.exec("update userbookingdata set status = 'RETURNED' where booking_id = '"+selectedstatus+"'");
    QSqlQueryModel readfaccount, readfacbooked;
    readfacbooked.setQuery("Select * from userbookingdata where booking_id = '"+selectedstatus+"'");
    for (int i = 0; i < readfacbooked.rowCount(); i++){
        facbooked = readfacbooked.record(i).value("facilities_booked").toString();
        facid = readfacbooked.record(i).value("facilities_id").toString();}
    readfaccount.setQuery("select facilities_count from facilitiesavailability where facilities_id = '"+facid+"'");
    for (int i = 0; i < readfaccount.rowCount();i++){
        facval = readfaccount.record(i).value("facilities_count").toString();}
    qDebug()<<facval<<"FACCOUNT";
    for (int i = 0; i < readfacbooked.rowCount(); i++){
        facbooked = readfacbooked.record(i).value("facilities_booked").toString();
        facid = readfacbooked.record(i).value("facilities_id").toString();}
    int facbookval = facbooked.split(" ")[0].toInt();
    int faccount = facval.split(" ")[0].toInt();
    int newcount = faccount + facbookval;
    QString newfaccount = QString::number(newcount);
    QSqlQuery update;
    update.exec("update facilitiesavailability set facilities_count = '"+newfaccount+"' where facilities_id = '"+facid+"'");
    m.dbclosed();
    hide();
    Manage *manage;
    manage = new Manage(this);
    if (username == "admin" && accid == "0"){
        ui->frameadmin->show();
        ui->frameuser->hide();
        ui->frame1->hide();
        ui->frameupdatestatus->hide();
    }
    else{
        ui->frameadmin->hide();
        ui->frameuser->show();
        ui->frame1->hide();
        ui->frameupdatestatus->hide();
    }
    manage->show();
}

void Manage::on_btn_back_2_clicked()
{
    ui->frameadmin->show();
    ui->frameuser->hide();
    ui->frame1->hide();
    ui->frameupdatestatus->hide();
}
