#include "register.h"
#include "ui_register.h"
#include <QTimer>
#include <QTime>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <stdio.h>
#include <QMovie>
#include <QPixmap>
#include <QThread>
#include <QDebug>
#include <QtSql>

Register::Register(QWidget *parent) : QDialog(parent), ui(new Ui::Register)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatecheckexist()));
    timer->start();
    ui->lineEdit_studid->setInputMask("9999999999");
    ui->error_lbl->hide();
    ui->error_lbl_2->hide();
    ui->error_lbl_3->hide();
    ui->error_lbl_4->hide();
    ui->error_lbl_5->hide();
    ui->error_lbl_6->hide();
    QMovie *movie = new QMovie("G:/Degree/Sem3(1910)/TSE2101 - Software Engineering Fundamentals/Assignments/Programming/Combine/Combine/checkexisting.gif");
    movie->start();

    MainWindow m;
    if (!m.dbopened()){
        ui->db_lbl->setText("Failed to connect to UFMS...");
    }
    else{
        ui->db_lbl->setText("Connected to UFMS!");
    }
}

Register::~Register()
{
    delete ui;
}

void Register::on_btn_register_reg_clicked()
{
    studentid_reg = ui->lineEdit_studid->text();
    username_reg = ui->lineEdit_username_reg->text();
    password_reg = ui->lineEdit_password_reg->text();
    comboboxindex = ui->seq_comboBox->currentIndex();
    QString seq_index_reg = QString::number(comboboxindex);
    seqanswer_reg = ui->lineEdit_seqanswer->text();
    MainWindow m;
    m.dbopened();
    QSqlQueryModel qry1;
    qry1.setQuery("select * from userdata order by acc_id asc");
    for (int i=0;i<qry1.rowCount();i++){
        studid = qry1.record(i).value("student_id").toString();
        user = qry1.record(i).value("username").toString();
        pass = qry1.record(i).value("password").toString();
        if ((studentid_reg == studid)&&(username_reg == user)){
            ui->error_lbl->hide();
            ui->error_lbl_2->hide();
            ui->error_lbl_3->hide();
            ui->error_lbl_4->hide();
            ui->error_lbl_5->show();
            ui->error_lbl_6->hide();
        }
        if ((studentid_reg == studid)&&(username_reg != user)){
            ui->error_lbl->hide();
            ui->error_lbl_2->hide();
            ui->error_lbl_3->hide();
            ui->error_lbl_4->show();
            ui->error_lbl_5->hide();
            ui->error_lbl_6->hide();
        }
        if ((studentid_reg != studid)&&(username_reg == user)){
            ui->error_lbl->hide();
            ui->error_lbl_2->hide();
            ui->error_lbl_3->show();
            ui->error_lbl_4->hide();
            ui->error_lbl_5->hide();
            ui->error_lbl_6->hide();
        }
        if (((studentid_reg == "") && (username_reg == "")) ||
            ((studentid_reg != "") && (username_reg == "")) ||
            ((studentid_reg == "") && (username_reg != ""))){
            ui->error_lbl->hide();
            ui->error_lbl_2->show();
            ui->error_lbl_3->hide();
            ui->error_lbl_4->hide();
            ui->error_lbl_5->hide();
            ui->error_lbl_6->hide();
        }
        if (username_reg == password_reg){
            ui->error_lbl->show();
            ui->error_lbl_2->hide();
            ui->error_lbl_3->hide();
            ui->error_lbl_4->hide();
            ui->error_lbl_5->hide();
            ui->error_lbl_6->hide();}
        if ((username_reg == user) && (studentid_reg == studid) && (password_reg == pass)){
            ui->error_lbl->hide();
            ui->error_lbl_2->hide();
            ui->error_lbl_3->hide();
            ui->error_lbl_4->hide();
            ui->error_lbl_5->hide();
            ui->error_lbl_6->show();
        }
    }
    if ((studentid_reg != studid) && (username_reg != user) && (studentid_reg != "") && (username_reg != "") && (password_reg != pass) && (username_reg != password_reg)){
        QSqlQuery qry;
        qry.exec("insert into USERDATA (USERNAME,PASSWORD,STUDENT_ID,SQ_INDEX,SQ_ANS)" "values ('"+username_reg+"','"+password_reg+"','"+studentid_reg+"','"+seq_index_reg+"','"+seqanswer_reg+"')");
        ui->error_lbl->hide();
        ui->error_lbl_2->hide();
        ui->error_lbl_3->hide();
        ui->error_lbl_4->hide();
        ui->error_lbl_5->hide();
        ui->error_lbl_6->hide();
        QMessageBox::warning(this, "Success", "Register Success!");
        m.dbclosed();
        hide();
        MainWindow *m;
        m = new MainWindow(this);
        m->show();}
}

void Register::on_btn_rback2login_clicked()
{
    QMessageBox::StandardButton selection = QMessageBox::question(this,"Returning to Login Page...","Are you sure you want to terminate the current registration?", QMessageBox::Yes | QMessageBox::No);
    if (selection == QMessageBox::Yes){
        hide();
        MainWindow *m;
        m = new MainWindow(this);
        m->show();
    }
    else{;}
}
