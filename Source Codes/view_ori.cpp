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

view::view(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::view)
{
    ui->setupUi(this);
}

view::~view()
{
    delete ui;
}

bool view::avopen(){
    av = QSqlDatabase::addDatabase("QSQLITE");
    av.setDatabaseName("G:/Degree/Sem3(1910)/TSE2101 - Software Engineering Fundamentals/Assignments/Programming/Combine/Combine/ufms.db");
    if (!av.open()){return false;}
    else{return true;}
}

void view::avclosed(){
    av.close();
    av.removeDatabase(QSqlDatabase::defaultConnection);
}

void view::on_listView_activated(const QModelIndex &index)
{
    QString val=ui->listView->model()->data(index).toString();
    ui->label->setText(val);

}

void view::on_pushButton_clicked()
{

        //av.setHostName("ufms");
//        if(!av.open())
//            qDebug()<<"ret error";
//        local_db = QSqlDatabase::addDatabase("QSQLITE","localdb");
//        local_db.setDatabaseName("localdb.sqlite");
//        local_db_query = QSqlQuery(local_db);
//        local_db_query.prepare( "SELECT * FROM sample_table" );
//        local_db_query.exec();
        avopen();





//    MainWindow m;
//    m.dbopened();
    //QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery qry;
    QSqlQuery qry1;

    QFile currentuser("G:/Degree/Sem3(1910)/TSE2101 - Software Engineering Fundamentals/Assignments/Programming/Combine/Combine/currentuser.txt");
    currentuser.open(QIODevice::ReadOnly);
    QTextStream in(&currentuser);
    in >> u1 >>c1;

    val=ui->label->text();



      //qry.prepare("Delete from userbookingdata,userdata,facilitiesavailability where facilitiesavailability.FACILITIES_NAME='"+val+"'(userbookingdata.acc_id = '"+c1+"' and facilitiesavailability.facilities_id=userbookingdata.facilities_id group by userbookingdata.booking_id)");
      qry1.exec("Update facilitiesavailability,userbookingdata,userdata set FACILITIES_COUNT=FACILITIES_COUNT+FACILITIES_BOOKED where userbookingdata.acc_id = '"+c1+"' and facilitiesavailability.facilities_id=userbookingdata.facilities_id group by userbookingdata.booking_id");
      //qry.exec("Update facilitiesavailability set FACILITIES_COUNT=FACILITIES_COUNT+FACILITIES_BOOKED");
      qry.exec("Delete from userbookingdata where userbookingdata.acc_id = '"+c1+"' and userbookingdata.BOOKING_ID='"+val+"'");
      QMessageBox msgBox;
      msgBox.setText("Selected booked venue has been deleted.");
      msgBox.exec();

//    //qry.exec("Update facilitiesavailability,userbookingdata,userdata set FACILITIES_COUNT=FACILITIES_COUNT+FACILITIES_BOOKED where FACILITIES_NAME='"+val+"'(userbookingdata.acc_id = '"+c1+"' and facilitiesavailability.facilities_id=userbookingdata.facilities_id group by userbookingdata.booking_id)");
//    m.dbclosed();

//    hide();
//    view *v;
//    v = new view(this);
//    m.dbopened();

//    qry.prepare("Select facilitiesavailability.facilities_name,userbookingdata.facilities_booked,userbookingdata.date,userbookingdata.time from userdata,userbookingdata,facilitiesavailability where userbookingdata.acc_id = '"+c1+"' and facilitiesavailability.facilities_id=userbookingdata.facilities_id group by userbookingdata.booking_id ");
//    qry.exec();
//    modal->setQuery(qry);
//    ui->tableView->setModel(modal);

//    qry.prepare("Select facilities_name from userdata,userbookingdata,facilitiesavailability where userbookingdata.acc_id = '"+c1+"' and facilitiesavailability.facilities_id=userbookingdata.facilities_id group by userbookingdata.booking_id ");
//    qry.exec();
//    modal->setQuery(qry);
//    ui->listView->setModel(modal);

//    m.dbclosed();
//    v->show();
      avclosed();
      hide();
      Manage *m;
      m = new Manage(this);
      m->show();
}

void view::on_pushButton_2_clicked()
{
    hide();
    Manage *m;
    m = new Manage(this);
    m->show();
}

void view::on_pushButton_3_clicked()
{
    avopen();

    QSqlQuery qry,qry2;

    QFile currentuser("G:/Degree/Sem3(1910)/TSE2101 - Software Engineering Fundamentals/Assignments/Programming/Combine/Combine/currentuser.txt");
    currentuser.open(QIODevice::ReadOnly);
    QTextStream in(&currentuser);
    in >> u1 >>c1;

    qry2.exec("Update facilitiesavailability,userbookingdata,userdata set FACILITIES_COUNT=FACILITIES_COUNT+FACILITIES_BOOKED where userbookingdata.acc_id = '"+c1+"'");
    qry.exec("Delete from userbookingdata where userbookingdata.acc_id = '"+c1+"'");
    QMessageBox msgBox;
    msgBox.setText("All booked venue has been deleted.");
    msgBox.exec();

    avclosed();
    hide();
    Manage *m;
    m = new Manage(this);
    m->show();
}
