#include "resetpw.h"
#include "ui_resetpw.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QByteArray>

ResetPW::ResetPW(QWidget *parent) :QMainWindow(parent), ui(new Ui::ResetPW)
{
    ui->setupUi(this);
    ui->error_lbl->hide();
    ui->lineEdit_studid->setInputMask("9999999999");
    ui->display1->hide();
    ui->display2->hide();
    MainWindow m;
    if (!m.dbopened()){ui->db_lbl->setText("Failed to connect to UFMS...");}
    else{ui->db_lbl->setText("Connected to UFMS!");}
}

ResetPW::~ResetPW()
{
    delete ui;
}


void ResetPW::on_continue_btn_clicked()
{
    studentid_cin = ui->lineEdit_studid->text();
    MainWindow m;
    m.dbopened();
    if (!m.dbopened()){ui->db_lbl->setText("Failed to connect to UFMS...");}
    else{ui->db_lbl->setText("Connected to UFMS!");}
    QSqlQueryModel readstudentid;
    readstudentid.setQuery("select * from userdata");
    for (int i = 0; i < readstudentid.rowCount();i++){
        studentid = readstudentid.record(i).value("student_id").toString();
        QString comboboxindexval = readstudentid.record(i).value("sq_index").toString();
        comboboxindex = comboboxindexval.split(" ")[0].toInt();
        seqanswer = readstudentid.record(i).value("sq_ans").toString();
        user = readstudentid.record(i).value("username").toString();
        passw = readstudentid.record(i).value("password").toString();
        if(studentid_cin != studentid || studentid_cin == ""){
            ui->error_lbl->show();}
        if (studentid == studentid_cin && studentid_cin != ""){
            ui->error_lbl->hide();
            ui->display0->hide();
            ui->display1->show();
            on_display1_clicked();
            m.dbclosed();
            break;}
        else{}}
}

void ResetPW::on_display1_clicked()
{
    ui->label_currentstudid->setText(studentid);
    ui->label_currentstudid_2->setText(studentid);
    ui->error_lbl_2->hide();
    switch(comboboxindex){
    case 0:
        ui->seques_lbl->setText("What is your favorite color?");
        break;
    case 1:
        ui->seques_lbl->setText("Where is your primary school?");
        break;
    case 2:
        ui->seques_lbl->setText("What is your first pet's name?");
        break;
    case 3:
        ui->seques_lbl->setText("Who is your favorite author?");
        break;
    case 4:
        ui->seques_lbl->setText("What is your lucky number?");
        break;
    }
}

void ResetPW::on_continue_btn_2_clicked()
{
    seqanswer_cin= ui->lineEdit_answer->text();
    if (seqanswer_cin == seqanswer && seqanswer_cin != ""){
        ui->error_lbl_2->hide();
        ui->display1->hide();
        ui->display2->show();
        ui->error_lbl_3->hide();
    }
    else {
        ui->error_lbl_2->show();
    }
}

void ResetPW::on_btn_rback2login_2_clicked()
{
    QMessageBox::StandardButton selection = QMessageBox::question(this,"Returning to Login Page...","Are you sure you want to terminate the current process?", QMessageBox::Yes | QMessageBox::No);
    if (selection == QMessageBox::Yes){
        hide();
        MainWindow *m;
        m = new MainWindow(this);
        m->show();
    }
    else{;}
}

void ResetPW::on_btn_rback2login_clicked()
{
    QMessageBox::StandardButton selection = QMessageBox::question(this,"Returning to Login Page...","Are you sure you want to terminate the current process?", QMessageBox::Yes | QMessageBox::No);
    if (selection == QMessageBox::Yes){
        hide();
        MainWindow *m;
        m = new MainWindow(this);
        m->show();
    }
    else{;}
}

void ResetPW::on_btn_rback2login_3_clicked()
{
    QMessageBox::StandardButton selection = QMessageBox::question(this,"Returning to Login Page...","Are you sure you want to terminate the current process?", QMessageBox::Yes | QMessageBox::No);
    if (selection == QMessageBox::Yes){
        hide();
        MainWindow *m;
        m = new MainWindow(this);
        m->show();
    }
    else{;}
}

void ResetPW::on_btn_changepw_clicked()
{
    QString newpw = ui->lineEdit_password->text();
    if (newpw == passw){
        ui->error_lbl_3->show();
        ui->error_lbl_3->setText("New password cannot be the same as old password!");
    }
    if (newpw == ""){
        ui->error_lbl_3->show();
        ui->error_lbl_3->setText("Input cannot be empty!");
    }
    if(newpw != "" && newpw == user && newpw != passw){
        ui->error_lbl_3->show();
        ui->error_lbl_3->setText("New password cannot be the same as username!");
    }
    if (newpw != passw && newpw != "" && newpw != user){
        ui->error_lbl_3->hide();
        MainWindow m;
        m.dbopened();
        QSqlQuery changepassw;
        changepassw.exec("update userdata set password = '"+newpw+"' where student_id = '"+studentid+"'");
        QMessageBox::information(this, "Congratulations!", "Password Changed!");
        hide();
        MainWindow *main;
        main = new MainWindow(this);
        main->show();
        m.dbclosed();
    }}
