#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "manage.h"
#include "ui_manage.h"
#include "booking.h"
#include "ui_booking.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMovie>
#include <QtSql>

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_Password->setEchoMode(QLineEdit::Password);
    QIcon pic;
    pic.addPixmap(QPixmap(":/images/eyeview.png"), QIcon::Normal, QIcon::On);
    ui->btn_passhideview->setIcon(pic);
    passwordecho = 2;
    ui->error_lbl->hide();
    QMovie *movie = new QMovie(":/images/logo.gif");
    ui->logo_lbl->setMovie(movie);
    movie->start();
    dbopened();
    if (!dbopened()){ui->db_lbl->setText("Failed to connect to UFMS...");}
    else{ui->db_lbl->setText("Connected to UFMS!");
        QDateTime date = QDateTime::currentDateTime();
        QString datetdy = date.toString("yyyy-MM-dd");
        QTime time = QTime::currentTime();
        QString currenttime = time.toString("hhmm");
        QString datefromdb, timefromdb;
        QString timereached = timefromdb.right(4);
        QSqlQueryModel checkdate;
        QSqlQuery updatestatus;
        checkdate.setQuery("select * from userbookingdata where status = 'BOOKED' order by booking_id asc");
        for (int i = 0; i< checkdate.rowCount();i++){
            datefromdb = checkdate.record(i).value("dateofbooked").toString();
            timefromdb = checkdate.record(i).value("timeofbooked").toString();
            if (datefromdb <= datetdy){
                if(timereached >= currenttime){
                updatestatus.exec("update userbookingdata set status = 'OBSOLETE' where dateofbooked = '"+datefromdb+"'");}
                else{}}
            else{}}
        dbclosed();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_Register_clicked()
{
    hide();
    Register *reg;
    reg = new Register(this);
    reg->show();
}

bool MainWindow::dbopened(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Kelvi/Desktop/VV-UFMS/Source Codes/ufms.db");
    if (!db.open()){return false;}
    else{return true;}
}

void MainWindow::dbclosed(){
    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
}

void MainWindow::on_btn_Login_clicked()
{
    username = ui->lineEdit_Username->text();
    password = ui->lineEdit_Password->text();
    dbopened();
    QSqlQueryModel qry;
    qry.setQuery("select * from userdata order by acc_id");
    for (int i = 0; i < qry.rowCount();i++){
        accid = qry.record(i).value("acc_id").toString();
        user = qry.record(i).value("username").toString();
        pass = qry.record(i).value("password").toString();
        ui->error_lbl->hide();
        if ((username != user && password == pass) ||
            (username == user && password != pass) ||
            (username != user && password != pass)){
            ui->error_lbl->show();}
        if (username == user && password == pass){
            QMessageBox::information(this, "Success", "Login Success!");
            QFile currentuser("C:/Users/Kelvi/Desktop/VV-UFMS/Source Codes/currentuser.txt");
            currentuser.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::ReadWrite | QIODevice::Truncate);
            QTextStream stream(&currentuser);
            stream << username << " " <<accid;
            dbclosed();
            ui->error_lbl->hide();
            hide();
            Manage *m;
            m = new Manage(this);
            if (username == "admin" && accid == "0"){
                m->ui->frameadmin->show();
                m->ui->frameuser->hide();
                m->ui->frame1->hide();
                m->ui->frameupdatestatus->hide();
            }
            else{
                m->ui->frameadmin->hide();
                m->ui->frameuser->show();
                m->ui->frame1->hide();
                m->ui->frameupdatestatus->hide();
            }
            m->show();
            break;
        }else{}
    }
}

void MainWindow::on_btn_passhideview_clicked()
{
    while(passwordecho != 0 || 2){
        if(passwordecho == 2){
            ui->lineEdit_Password->setEchoMode(QLineEdit::Normal);
            QIcon pic;
            pic.addPixmap(QPixmap(":/images/eyehide.png"), QIcon::Normal, QIcon::On);
            ui->btn_passhideview->setIcon(pic);
            passwordecho = 0;
            break;}
        if(passwordecho == 0){
            ui->lineEdit_Password->setEchoMode(QLineEdit::Password);
            QIcon pic;
            pic.addPixmap(QPixmap(":/images/eyeview.png"), QIcon::Normal, QIcon::On);
            ui->btn_passhideview->setIcon(pic);
            passwordecho = 2;
            break;}
    }
}

void MainWindow::on_btn_Resetpw_clicked()
{
    hide();
    ResetPW *re;
    re = new ResetPW(this);
    re->show();
}
