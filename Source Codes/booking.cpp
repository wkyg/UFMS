#include "booking.h"
#include "ui_booking.h"
#include "mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QtSql>
#include <QDebug>

Booking::Booking(QWidget *parent) :QMainWindow(parent), ui(new Ui::Booking)
{
    ui->setupUi(this);
    ui->selecteddis_lbl_3->hide();
    ui->spinBox->hide();
    ui->dayselectLabel->hide();
    ui->dayselectedLabel->hide();
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(displaytime()));
    timer->start();
    QString dateLabel = datetdy.toString(":  yyyy-MM-dd");
    QString dateLabel2 = datetdy.toString("yyyy-MM-dd");
    daytdy = datetdy.toString("dd"); monthtdy = datetdy.toString("MM"); yeartdy = datetdy.toString("yyyy");
    ui->datedisplay->setText(dateLabel);
    ui->datedisplay_2->setText(dateLabel2);
    ui->datedisplay_3->setText(dateLabel2);
    ui->calendarWidget->setGridVisible(true);
    ui->calendarWidget->setMinimumDate(QDate::currentDate());
    ui->dateEditfrom->setMinimumDate(QDate::currentDate());
    ui->dateEditto->setMinimumDate(QDate::currentDate());
    connect(ui->calendarWidget, SIGNAL(timeout()), this, SLOT(disabletimebtn()));
    connect(timer, SIGNAL(timeout()), this, SLOT(currentsession()));
    MainWindow m;
    m.dbopened();
    if (!m.dbopened()){ui->db_lbl->setText("Failed to connect to UFMS...");}
    else{ui->db_lbl->setText("Connected to UFMS!");}
    QSqlQueryModel qry;
    qry.setQuery("select * from facilitiesavailability order by facilities_id");
    for (int i = 0; i < qry.rowCount();i++){
        FAC[i] = qry.record(i).value("facilities_count").toString();
        facint[i] = FAC[i].split(" ")[0].toInt();
        facmax[i] = qry.record(i).value("facilities_max").toString();
        facmaxint[i] = facmax[i].split(" ")[0].toInt();}
    m.dbclosed();
    disablefacs();
    faccurrentavailability();
    ui->timetocmbbox->addItems({"0900","1000","1100","1200","1300","1400","1500","1600","1700","1800","1900","2000","2100","2200"});
    ui->time1hourbox->show();
    ui->time2hourbox->hide();
    ui->time3hourbox->hide();
    ui->time4hourbox->hide();
    ui->timecustomize->hide();
}
void Booking::displaytime(){
    QTime time = QTime::currentTime();
    QString timeLabel = time.toString("hh : mm : ss");
    ui->timedisplay->setText(timeLabel);
}

void Booking::currentsession(){
    QFile currentuser("G:/Degree/Sem3(1910)/TSE2101 - Software Engineering Fundamentals/Assignments/Programming/Combine/Combine/currentuser.txt");
    currentuser.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&currentuser);
    in>>username>>accid;
    ui->currentuser_lbl->setText(username);
    currentuser.flush();
    currentuser.close();
}
void Booking::disabletimebtn(){
    QTime time = QTime::currentTime();
    QString timeLabel = time.toString("hh : mm : ss");
    if (year==yeartdy && month==monthtdy && day==daytdy){
        ui->btn_wholeday->setEnabled(true);
        if (timeLabel >= "09 : 00 : 00"){
            ui->btn_8am->setEnabled(false);
            ui->btn_8am_2->setEnabled(false);
            ui->btn_8am_4->setEnabled(false);}
        if (timeLabel >= "10 : 00 : 00"){
            ui->btn_8am->setEnabled(false);
            ui->btn_9am->setEnabled(false);
            ui->btn_wholeday->setEnabled(false);
            ui->btn_8am_2->setEnabled(false);
            ui->btn_wholeday_2->setEnabled(false);
            ui->btn_8am_3->setEnabled(false);
            ui->btn_wholeday_3->setEnabled(false);
            ui->btn_8am_4->setEnabled(false);
            ui->btn_wholeday_4->setEnabled(false);}
        if (timeLabel >= "11 : 00 : 00"){ui->btn_8am->setEnabled(false);
                                        ui->btn_9am->setEnabled(false);
                                        ui->btn_10am->setEnabled(false);
                                        ui->btn_wholeday->setEnabled(false);
                                        ui->btn_8am_2->setEnabled(false);
                                        ui->btn_10am_2->setEnabled(false);
                                        ui->btn_wholeday_2->setEnabled(false);
                                        ui->btn_8am_3->setEnabled(false);
                                        ui->btn_11am_3->setEnabled(false);
                                        ui->btn_wholeday_3->setEnabled(false);
                                        ui->btn_8am_4->setEnabled(false);
                                        ui->btn_wholeday_4->setEnabled(false);}
        if (timeLabel >= "12 : 00 : 00"){ui->btn_8am->setEnabled(false);
                                         ui->btn_9am->setEnabled(false);
                                         ui->btn_10am->setEnabled(false);
                                         ui->btn_11am->setEnabled(false);
                                         ui->btn_wholeday->setEnabled(false);
                                         ui->btn_8am_2->setEnabled(false);
                                         ui->btn_10am_2->setEnabled(false);
                                         ui->btn_12pm_2->setEnabled(false);
                                         ui->btn_wholeday_2->setEnabled(false);
                                         ui->btn_8am_3->setEnabled(false);
                                         ui->btn_11am_3->setEnabled(false);
                                         ui->btn_wholeday_3->setEnabled(false);
                                         ui->btn_8am_4->setEnabled(false);
                                         ui->btn_12pm_4->setEnabled(false);
                                         ui->btn_wholeday_4->setEnabled(false);}
        if (timeLabel >= "13 : 00 : 00"){ui->btn_8am->setEnabled(false);
                                         ui->btn_9am->setEnabled(false);
                                         ui->btn_10am->setEnabled(false);
                                         ui->btn_11am->setEnabled(false);
                                         ui->btn_12pm->setEnabled(false);
                                         ui->btn_wholeday->setEnabled(false);
                                         ui->btn_8am_2->setEnabled(false);
                                         ui->btn_10am_2->setEnabled(false);
                                         ui->btn_12pm_2->setEnabled(false);
                                         ui->btn_wholeday_2->setEnabled(false);

                                         ui->btn_8am_3->setEnabled(false);
                                         ui->btn_11am_3->setEnabled(false);
                                         ui->btn_wholeday_3->setEnabled(false);
                                         ui->btn_8am_4->setEnabled(false);
                                         ui->btn_12pm_4->setEnabled(false);
                                         ui->btn_wholeday_4->setEnabled(false);}
        if (timeLabel >= "14 : 00 : 00"){ui->btn_8am->setEnabled(false);
                                         ui->btn_9am->setEnabled(false);
                                         ui->btn_10am->setEnabled(false);
                                         ui->btn_11am->setEnabled(false);
                                         ui->btn_12pm->setEnabled(false);
                                         ui->btn_1pm->setEnabled(false);
                                         ui->btn_wholeday->setEnabled(false);
                                         ui->btn_8am_2->setEnabled(false);
                                         ui->btn_10am_2->setEnabled(false);
                                         ui->btn_12pm_2->setEnabled(false);
                                         ui->btn_2pm_2->setEnabled(false);
                                         ui->btn_wholeday_2->setEnabled(false);
                                         ui->btn_8am_3->setEnabled(false);
                                         ui->btn_11am_3->setEnabled(false);
                                         ui->btn_2pm_3->setEnabled(false);
                                         ui->btn_wholeday_3->setEnabled(false);
                                         ui->btn_8am_4->setEnabled(false);
                                         ui->btn_12pm_4->setEnabled(false);
                                         ui->btn_wholeday_4->setEnabled(false);}
        if (timeLabel >= "15 : 00 : 00"){ui->btn_8am->setEnabled(false);
                                         ui->btn_9am->setEnabled(false);
                                         ui->btn_10am->setEnabled(false);
                                         ui->btn_11am->setEnabled(false);
                                         ui->btn_12pm->setEnabled(false);
                                         ui->btn_1pm->setEnabled(false);
                                         ui->btn_2pm->setEnabled(false);
                                         ui->btn_wholeday->setEnabled(false);
                                         ui->btn_8am_2->setEnabled(false);
                                         ui->btn_10am_2->setEnabled(false);
                                         ui->btn_12pm_2->setEnabled(false);
                                         ui->btn_2pm_2->setEnabled(false);
                                         ui->btn_wholeday_2->setEnabled(false);
                                         ui->btn_8am_3->setEnabled(false);
                                         ui->btn_11am_3->setEnabled(false);
                                         ui->btn_2pm_3->setEnabled(false);
                                         ui->btn_wholeday_3->setEnabled(false);
                                         ui->btn_8am_4->setEnabled(false);
                                         ui->btn_12pm_4->setEnabled(false);
                                         ui->btn_wholeday_4->setEnabled(false);}
        if (timeLabel >= "16 : 00 : 00"){ui->btn_8am->setEnabled(false);
                                         ui->btn_9am->setEnabled(false);
                                         ui->btn_10am->setEnabled(false);
                                         ui->btn_11am->setEnabled(false);
                                         ui->btn_12pm->setEnabled(false);
                                         ui->btn_1pm->setEnabled(false);
                                         ui->btn_2pm->setEnabled(false);
                                         ui->btn_3pm->setEnabled(false);
                                         ui->btn_wholeday->setEnabled(false);
                                         ui->btn_8am_2->setEnabled(false);
                                         ui->btn_10am_2->setEnabled(false);
                                         ui->btn_12pm_2->setEnabled(false);
                                         ui->btn_2pm_2->setEnabled(false);
                                         ui->btn_4pm_2->setEnabled(false);
                                         ui->btn_wholeday_2->setEnabled(false);
                                         ui->btn_8am_3->setEnabled(false);
                                         ui->btn_11am_3->setEnabled(false);
                                         ui->btn_2pm_3->setEnabled(false);
                                         ui->btn_wholeday_3->setEnabled(false);
                                         ui->btn_8am_4->setEnabled(false);
                                         ui->btn_12pm_4->setEnabled(false);
                                         ui->btn_4pm_4->setEnabled(false);
                                         ui->btn_wholeday_4->setEnabled(false);}
        if (timeLabel >= "17 : 00 : 00"){ui->btn_8am->setEnabled(false);
                                         ui->btn_9am->setEnabled(false);
                                         ui->btn_10am->setEnabled(false);
                                         ui->btn_11am->setEnabled(false);
                                         ui->btn_12pm->setEnabled(false);
                                         ui->btn_1pm->setEnabled(false);
                                         ui->btn_2pm->setEnabled(false);
                                         ui->btn_3pm->setEnabled(false);
                                         ui->btn_4pm->setEnabled(false);
                                         ui->btn_wholeday->setEnabled(false);
                                         ui->btn_8am_2->setEnabled(false);
                                         ui->btn_10am_2->setEnabled(false);
                                         ui->btn_12pm_2->setEnabled(false);
                                         ui->btn_2pm_2->setEnabled(false);
                                         ui->btn_4pm_2->setEnabled(false);
                                         ui->btn_wholeday_2->setEnabled(false);
                                         ui->btn_8am_3->setEnabled(false);
                                         ui->btn_11am_3->setEnabled(false);
                                         ui->btn_2pm_3->setEnabled(false);
                                         ui->btn_5pm_3->setEnabled(false);
                                         ui->btn_wholeday_3->setEnabled(false);
                                         ui->btn_8am_4->setEnabled(false);
                                         ui->btn_12pm_4->setEnabled(false);
                                         ui->btn_4pm_4->setEnabled(false);
                                         ui->btn_wholeday_4->setEnabled(false);}
        if (timeLabel >= "18 : 00 : 00"){ui->btn_8am->setEnabled(false);
                                         ui->btn_9am->setEnabled(false);
                                         ui->btn_10am->setEnabled(false);
                                         ui->btn_11am->setEnabled(false);
                                         ui->btn_12pm->setEnabled(false);
                                         ui->btn_1pm->setEnabled(false);
                                         ui->btn_2pm->setEnabled(false);
                                         ui->btn_3pm->setEnabled(false);
                                         ui->btn_4pm->setEnabled(false);
                                         ui->btn_5pm->setEnabled(false);
                                         ui->btn_wholeday->setEnabled(false);
                                         ui->btn_8am_2->setEnabled(false);
                                         ui->btn_10am_2->setEnabled(false);
                                         ui->btn_12pm_2->setEnabled(false);
                                         ui->btn_2pm_2->setEnabled(false);
                                         ui->btn_4pm_2->setEnabled(false);
                                         ui->btn_6pm_2->setEnabled(false);
                                         ui->btn_wholeday_2->setEnabled(false);
                                         ui->btn_8am_3->setEnabled(false);
                                         ui->btn_11am_3->setEnabled(false);
                                         ui->btn_2pm_3->setEnabled(false);
                                         ui->btn_5pm_3->setEnabled(false);
                                         ui->btn_wholeday_3->setEnabled(false);
                                         ui->btn_8am_4->setEnabled(false);
                                         ui->btn_12pm_4->setEnabled(false);
                                         ui->btn_4pm_4->setEnabled(false);
                                         ui->btn_wholeday_4->setEnabled(false);}
        if (timeLabel >= "19 : 00 : 00"){ui->btn_8am->setEnabled(false);
                                         ui->btn_9am->setEnabled(false);
                                         ui->btn_10am->setEnabled(false);
                                         ui->btn_11am->setEnabled(false);
                                         ui->btn_12pm->setEnabled(false);
                                         ui->btn_1pm->setEnabled(false);
                                         ui->btn_2pm->setEnabled(false);
                                         ui->btn_3pm->setEnabled(false);
                                         ui->btn_4pm->setEnabled(false);
                                         ui->btn_5pm->setEnabled(false);
                                         ui->btn_6pm->setEnabled(false);
                                         ui->btn_wholeday->setEnabled(false);
                                         ui->btn_8am_2->setEnabled(false);
                                         ui->btn_10am_2->setEnabled(false);
                                         ui->btn_12pm_2->setEnabled(false);
                                         ui->btn_2pm_2->setEnabled(false);
                                         ui->btn_4pm_2->setEnabled(false);
                                         ui->btn_6pm_2->setEnabled(false);
                                         ui->btn_wholeday_2->setEnabled(false);
                                         ui->btn_8am_3->setEnabled(false);
                                         ui->btn_11am_3->setEnabled(false);
                                         ui->btn_2pm_3->setEnabled(false);
                                         ui->btn_5pm_3->setEnabled(false);
                                         ui->btn_wholeday_3->setEnabled(false);
                                         ui->btn_8am_4->setEnabled(false);
                                         ui->btn_12pm_4->setEnabled(false);
                                         ui->btn_4pm_4->setEnabled(false);
                                         ui->btn_wholeday_4->setEnabled(false);}
        if (timeLabel >= "20 : 00 : 00"){ui->btn_8am->setEnabled(false);
                                         ui->btn_9am->setEnabled(false);
                                         ui->btn_10am->setEnabled(false);
                                         ui->btn_11am->setEnabled(false);
                                         ui->btn_12pm->setEnabled(false);
                                         ui->btn_1pm->setEnabled(false);
                                         ui->btn_2pm->setEnabled(false);
                                         ui->btn_3pm->setEnabled(false);
                                         ui->btn_4pm->setEnabled(false);
                                         ui->btn_5pm->setEnabled(false);
                                         ui->btn_6pm->setEnabled(false);
                                         ui->btn_7pm->setEnabled(false);
                                         ui->btn_wholeday->setEnabled(false);
                                         ui->btn_8am_2->setEnabled(false);
                                         ui->btn_10am_2->setEnabled(false);
                                         ui->btn_12pm_2->setEnabled(false);
                                         ui->btn_2pm_2->setEnabled(false);
                                         ui->btn_4pm_2->setEnabled(false);
                                         ui->btn_6pm_2->setEnabled(false);
                                         ui->btn_8pm_2->setEnabled(false);
                                         ui->btn_wholeday_2->setEnabled(false);
                                         ui->btn_8am_3->setEnabled(false);
                                         ui->btn_11am_3->setEnabled(false);
                                         ui->btn_2pm_3->setEnabled(false);
                                         ui->btn_5pm_3->setEnabled(false);
                                         ui->btn_8pm_3->setEnabled(false);
                                         ui->btn_wholeday_3->setEnabled(false);
                                         ui->btn_8am_4->setEnabled(false);
                                         ui->btn_12pm_4->setEnabled(false);
                                         ui->btn_4pm_4->setEnabled(false);
                                         ui->btn_wholeday_4->setEnabled(false);}
        if (timeLabel >= "21 : 00 : 00"){ui->btn_8am->setEnabled(false);
                                         ui->btn_9am->setEnabled(false);
                                         ui->btn_10am->setEnabled(false);
                                         ui->btn_11am->setEnabled(false);
                                         ui->btn_12pm->setEnabled(false);
                                         ui->btn_1pm->setEnabled(false);
                                         ui->btn_2pm->setEnabled(false);
                                         ui->btn_3pm->setEnabled(false);
                                         ui->btn_4pm->setEnabled(false);
                                         ui->btn_5pm->setEnabled(false);
                                         ui->btn_6pm->setEnabled(false);
                                         ui->btn_7pm->setEnabled(false);
                                         ui->btn_8pm->setEnabled(false);
                                         ui->btn_wholeday->setEnabled(false);
                                         ui->btn_8am_2->setEnabled(false);
                                         ui->btn_10am_2->setEnabled(false);
                                         ui->btn_12pm_2->setEnabled(false);
                                         ui->btn_2pm_2->setEnabled(false);
                                         ui->btn_4pm_2->setEnabled(false);
                                         ui->btn_6pm_2->setEnabled(false);
                                         ui->btn_8pm_2->setEnabled(false);
                                         ui->btn_wholeday_2->setEnabled(false);
                                         ui->btn_8am_3->setEnabled(false);
                                         ui->btn_11am_3->setEnabled(false);
                                         ui->btn_2pm_3->setEnabled(false);
                                         ui->btn_5pm_3->setEnabled(false);
                                         ui->btn_8pm_3->setEnabled(false);
                                         ui->btn_wholeday_3->setEnabled(false);
                                         ui->btn_8am_4->setEnabled(false);
                                         ui->btn_12pm_4->setEnabled(false);
                                         ui->btn_4pm_4->setEnabled(false);
                                         ui->btn_wholeday_4->setEnabled(false);}
        if (timeLabel >= "22 : 00 : 00"){ui->btn_8am->setEnabled(false);
                                         ui->btn_9am->setEnabled(false);
                                         ui->btn_10am->setEnabled(false);
                                         ui->btn_11am->setEnabled(false);
                                         ui->btn_12pm->setEnabled(false);
                                         ui->btn_1pm->setEnabled(false);
                                         ui->btn_2pm->setEnabled(false);
                                         ui->btn_3pm->setEnabled(false);
                                         ui->btn_4pm->setEnabled(false);
                                         ui->btn_5pm->setEnabled(false);
                                         ui->btn_6pm->setEnabled(false);
                                         ui->btn_7pm->setEnabled(false);
                                         ui->btn_8pm->setEnabled(false);
                                         ui->btn_9pm->setEnabled(false);
                                         ui->btn_wholeday->setEnabled(false);
                                         ui->btn_8am_2->setEnabled(false);
                                         ui->btn_10am_2->setEnabled(false);
                                         ui->btn_12pm_2->setEnabled(false);
                                         ui->btn_2pm_2->setEnabled(false);
                                         ui->btn_4pm_2->setEnabled(false);
                                         ui->btn_6pm_2->setEnabled(false);
                                         ui->btn_8pm_2->setEnabled(false);
                                         ui->btn_wholeday_2->setEnabled(false);
                                         ui->btn_8am_3->setEnabled(false);
                                         ui->btn_11am_3->setEnabled(false);
                                         ui->btn_2pm_3->setEnabled(false);
                                         ui->btn_5pm_3->setEnabled(false);
                                         ui->btn_8pm_3->setEnabled(false);
                                         ui->btn_wholeday_3->setEnabled(false);
                                         ui->btn_8am_4->setEnabled(false);
                                         ui->btn_12pm_4->setEnabled(false);
                                         ui->btn_4pm_4->setEnabled(false);
                                         ui->btn_wholeday_4->setEnabled(false);}}
    else{
        ui->btn_8am->setEnabled(true);
        ui->btn_9am->setEnabled(true);
        ui->btn_10am->setEnabled(true);
        ui->btn_11am->setEnabled(true);
        ui->btn_12pm->setEnabled(true);
        ui->btn_1pm->setEnabled(true);
        ui->btn_2pm->setEnabled(true);
        ui->btn_3pm->setEnabled(true);
        ui->btn_4pm->setEnabled(true);
        ui->btn_5pm->setEnabled(true);
        ui->btn_6pm->setEnabled(true);
        ui->btn_7pm->setEnabled(true);
        ui->btn_8pm->setEnabled(true);
        ui->btn_9pm->setEnabled(true);
        ui->btn_wholeday->setEnabled(true);

        ui->btn_8am_2->setEnabled(true);
        ui->btn_10am_2->setEnabled(true);
        ui->btn_12pm_2->setEnabled(true);
        ui->btn_2pm_2->setEnabled(true);
        ui->btn_4pm_2->setEnabled(true);
        ui->btn_6pm_2->setEnabled(true);
        ui->btn_8pm_2->setEnabled(true);
        ui->btn_wholeday_2->setEnabled(true);

        ui->btn_8am_3->setEnabled(true);
        ui->btn_11am_3->setEnabled(true);
        ui->btn_2pm_3->setEnabled(true);
        ui->btn_5pm_3->setEnabled(true);
        ui->btn_8pm_3->setEnabled(true);
        ui->btn_wholeday_3->setEnabled(true);

        ui->btn_8am_4->setEnabled(true);
        ui->btn_12pm_4->setEnabled(true);
        ui->btn_4pm_4->setEnabled(true);
        ui->btn_wholeday_4->setEnabled(true);
    }

}


void Booking::on_calendarWidget_clicked(const QDate &date)
{
    ui->timeselectedLabel->setText("-");
    dateselectLabel = date.toString("yyyy-MM-dd");
    day = date.toString("dd"); month = date.toString("MM"); year = date.toString("yyyy");
    ui->dateselectedLabel->setText((dateselectLabel));
    disabletimebtn();
}

void Booking::on_btn_logout_clicked()
{
    QMessageBox::StandardButton selection = QMessageBox::question(this,"Logout Confirmation","Are you sure you want to logout?", QMessageBox::Yes | QMessageBox::No);
    if (selection == QMessageBox::Yes){
        hide();
        MainWindow *m;
        m = new MainWindow(this);
        m->show();}
    else{}
}

void Booking::on_btn_clicked()
{
    ui->calendarWidget->setSelectedDate(QDate::currentDate());
    year = yeartdy; month = monthtdy; day = daytdy;
    ui->dateselectedLabel->setText(datetdylbl);
    disabletimebtn();
}

Booking::~Booking()
{
    delete ui;
}

void Booking::on_btn_8am_clicked(){timeselectedLabel = "0800 ~ 0900"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_9am_clicked(){timeselectedLabel = "0900 ~ 1000"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_10am_clicked(){timeselectedLabel = "1000 ~ 1100"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_11am_clicked(){timeselectedLabel = "1100 ~ 1200"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_12pm_clicked(){timeselectedLabel = "1200 ~ 1300"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_1pm_clicked(){timeselectedLabel = "1300 ~ 1400"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_2pm_clicked(){timeselectedLabel = "1400 ~ 1500"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_3pm_clicked(){timeselectedLabel = "1500 ~ 1600"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_4pm_clicked(){timeselectedLabel = "1600 ~ 1700"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_5pm_clicked(){timeselectedLabel = "1700 ~ 1800"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_6pm_clicked(){timeselectedLabel = "1800 ~ 1900"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_7pm_clicked(){timeselectedLabel = "1900 ~ 2000"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_8pm_clicked(){timeselectedLabel = "2000 ~ 2100"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_9pm_clicked(){timeselectedLabel = "2100 ~ 2200"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_wholeday_clicked(){timeselectedLabel = "0000 ~ 2359"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_wholeday_2_clicked(){timeselectedLabel = "0000 ~ 2359"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_wholeday_3_clicked(){timeselectedLabel = "0000 ~ 2359"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_wholeday_4_clicked(){timeselectedLabel = "0000 ~ 2359"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_12pm_4_clicked(){timeselectedLabel = "1200 ~ 1600"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_4pm_4_clicked(){timeselectedLabel = "1600 ~ 2000"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_8am_4_clicked(){timeselectedLabel = "0800 ~ 1200"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_11am_3_clicked(){timeselectedLabel = "1100 ~ 1400"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_2pm_3_clicked(){timeselectedLabel = "1400 ~ 1700"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_5pm_3_clicked(){timeselectedLabel = "1700 ~ 2000"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_8am_3_clicked(){timeselectedLabel = "0800 ~ 1100"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_8pm_3_clicked(){timeselectedLabel = "2000 ~ 2200"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_10am_2_clicked(){timeselectedLabel = "1000 ~ 1200"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_12pm_2_clicked(){timeselectedLabel = "1200 ~ 1400"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_2pm_2_clicked(){timeselectedLabel = "1400 ~ 1600"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_4pm_2_clicked(){timeselectedLabel = "1600 ~ 1800"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_6pm_2_clicked(){timeselectedLabel = "1800 ~ 2000"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_8am_2_clicked(){timeselectedLabel = "0800 ~ 1000"; ui->timeselectedLabel->setText(timeselectedLabel);}
void Booking::on_btn_8pm_2_clicked(){timeselectedLabel = "2000 ~ 2200"; ui->timeselectedLabel->setText(timeselectedLabel);}


void Booking::on_btn_reset_clicked()
{
    ui->dateselectedLabel->setText("-");
    ui->timeselectedLabel->setText("-");
    ui->btn_8am->setEnabled(true);
    ui->btn_9am->setEnabled(true);
    ui->btn_10am->setEnabled(true);
    ui->btn_11am->setEnabled(true);
    ui->btn_12pm->setEnabled(true);
    ui->btn_1pm->setEnabled(true);
    ui->btn_2pm->setEnabled(true);
    ui->btn_3pm->setEnabled(true);
    ui->btn_4pm->setEnabled(true);
    ui->btn_5pm->setEnabled(true);
    ui->btn_6pm->setEnabled(true);
    ui->btn_7pm->setEnabled(true);
    ui->btn_8pm->setEnabled(true);
    ui->btn_9pm->setEnabled(true);
    ui->btn_wholeday->setEnabled(true);
    ui->tabWidget->setEnabled(true);
    ui->facselected_lbl->setText("-");
    ui->maxfac_lbl->setText("-");
    ui->selecteddis_lbl_3->hide();
    ui->spinBox->hide();
}

void Booking::faccurrentavailability(){
    ui->fac0000_lbl->setText(FAC[0]);
    ui->fac0001_lbl->setText(FAC[1]);
    ui->fac0002_lbl->setText(FAC[2]);
    ui->fac0003_lbl->setText(FAC[3]);
    ui->fac0004_lbl->setText(FAC[4]);
    ui->fac0005_lbl->setText(FAC[5]);
    ui->fac0006_lbl->setText(FAC[6]);
    ui->fac0007_lbl->setText(FAC[7]);
    ui->fac0008_lbl->setText(FAC[8]);
    ui->fac0009_lbl->setText(FAC[9]);
    ui->fac0010_lbl->setText(FAC[10]);
    ui->fac0011_lbl->setText(FAC[11]);
    ui->fac0012_lbl->setText(FAC[12]);
    ui->fac0013_lbl->setText(FAC[13]);
    ui->fac0014_lbl->setText(FAC[14]);
    ui->fac0015_lbl->setText(FAC[15]);
    ui->fac0016_lbl->setText(FAC[16]);
    ui->fac0017_lbl->setText(FAC[17]);
    ui->fac0018_lbl->setText(FAC[18]);
    ui->fac0019_lbl->setText(FAC[19]);
    ui->fac0020_lbl->setText(FAC[20]);
    ui->fac0021_lbl->setText(FAC[21]);
    ui->fac0022_lbl->setText(FAC[22]);
    ui->fac0023_lbl->setText(FAC[23]);
    ui->fac0024_lbl->setText(FAC[24]);
    ui->fac0025_lbl->setText(FAC[25]);
    ui->fac0026_lbl->setText(FAC[26]);
    ui->fac0027_lbl->setText(FAC[27]);
    ui->fac0028_lbl->setText(FAC[28]);
    ui->fac0029_lbl->setText(FAC[29]);
    ui->fac0030_lbl->setText(FAC[30]);
    ui->fac0031_lbl->setText(FAC[31]);
    ui->fac0032_lbl->setText(FAC[32]);
    ui->fac0033_lbl->setText(FAC[33]);
    ui->fac0034_lbl->setText(FAC[34]);
}

void Booking::on_btn_lectureroom_clicked()
{
    facselected = "Lecture Room";
    facid = "FAC0000";
    facval = FAC[0];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[0]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[0]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_lecturehall_clicked()
{
    facselected = "Lecture Hall";
    facid = "FAC0001";
    facval = FAC[1];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[1]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[1]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_tutorialroom_clicked()
{
    facselected = "Tutorial Room";
    facid = "FAC0002";
    facval = FAC[2];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[2]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[2]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_meetingroom_clicked()
{
    facselected = "Meeting Room";
    facid = "FAC0003";
    facval = FAC[3];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[3]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[3]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_oslab_clicked()
{
    facselected = "OS Laboratory";
    facid = "FAC0004";
    facval = FAC[4];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[4]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[4]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_pclab_clicked()
{
    facselected = "PC Laboratory";
    facid = "FAC0005";
    facval = FAC[5];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[5]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[5]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_explab_clicked()
{
    facselected = "Experimental Laboratory";
    facid = "FAC0006";
    facval = FAC[6];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[6]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[6]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_engineerlab_clicked()
{
    facselected = "Engineering Laboratory";
    facid = "FAC0007";
    facval = FAC[7];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[7]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[7]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_vidshootroom_clicked()
{
    facselected = "Video Shooting Room";
    facid = "FAC0008";
    facval = FAC[8];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[8]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[8]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_artroom_clicked()
{
    facselected = "Art Room";
    facid = "FAC0009";
    facval = FAC[9];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[9]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[9]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_greensroom_clicked()
{
    facselected = "Green Screen Room";
    facid = "FAC0010";
    facval = FAC[10];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[10]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[10]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_audioroom_clicked()
{
    facselected = "Acoustic Audio Record Room";
    facid = "FAC0011";
    facval = FAC[11];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[11]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[11]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_videoeditroom_clicked()
{
    facselected = "Video Editing Room";
    facid = "FAC0012";
    facval = FAC[12];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[12]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[12]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_eventhall_clicked()
{
    facselected = "Event Hall";
    facid = "FAC0013";
    facval = FAC[13];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[13]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[13]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_corridor_clicked()
{
    facselected = "Corridor";
    facid = "FAC0014";
    facval = FAC[14];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[14]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[14]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_plaza_clicked()
{
    facselected = "Plaza";
    facid = "FAC0015";
    facval = FAC[15];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[15]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[15]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_basketballcourt_clicked()
{
    facselected = "Basketball Court";
    facid = "FAC0016";
    facval = FAC[16];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[16]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[16]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_tenniscourt_clicked()
{
    facselected = "Tennis Court";
    facid = "FAC0017";
    facval = FAC[17];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[17]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[17]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_badmintoncourt_clicked()
{
    facselected = "Badminton Court";
    facid = "FAC0018";
    facval = FAC[18];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[18]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[18]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_pool_clicked()
{
    facselected = "Swimming Pool";
    facid = "FAC0019";
    facval = FAC[19];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[19]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[19]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_field_clicked()
{
    facselected = "Field";
    facid = "FAC0020";
    facval = FAC[20];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[20]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[20]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_volleycourt_clicked()
{
    facselected = "Volleyball Court";
    facid = "FAC0021";
    facval = FAC[21];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[21]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[21]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_gym_clicked()
{
    facselected = "Gym";
    facid = "FAC0022";
    facval = FAC[22];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[22]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[22]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_skatepark_clicked()
{
    facselected = "Skatepark";
    facid = "FAC0023";
    facval = FAC[23];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[23]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[23]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_broom_clicked()
{
    facselected = "Broom";
    facid = "FAC0024";
    facval = FAC[24];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[24]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[24]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_mop_clicked()
{
    facselected = "Mop";
    facid = "FAC0025";
    facval = FAC[25];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[25]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[25]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_table_clicked()
{
    facselected = "Table";
    facid = "FAC0026";
    facval = FAC[26];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[26]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[26]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_chair_clicked()
{
    facselected = "Chair";
    facid = "FAC0027";
    facval = FAC[27];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[27]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[27]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_ladder_clicked()
{
    facselected = "Ladder";
    facid = "FAC0028";
    facval = FAC[28];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[28]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[28]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_queuebarrier_clicked()
{
    facselected = "Queue Barrier";
    facid = "FAC0029";
    facval = FAC[29];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[29]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[29]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_bannerstand_clicked()
{
    facselected = "Banner Stand";
    facid = "FAC0030";
    facval = FAC[30];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[30]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[30]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_bucket_clicked()
{
    facselected = "Bucket";
    facid = "FAC0031";
    facval = FAC[31];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[31]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[31]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_waterbucket_clicked()
{
    facselected = "Water Bucket";
    facid = "FAC0032";
    facval = FAC[32];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[32]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[32]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_waterpipe_clicked()
{
    facselected = "Water Pipe";
    facid = "FAC0033";
    facval = FAC[33];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[33]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[33]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_waterwiper_clicked()
{
    facselected = "Water Wiper";
    facid = "FAC0034";
    facval = FAC[34];
    ui->facselected_lbl->setText(facselected);
    ui->maxfac_lbl->setText(facmax[34]);
    ui->selecteddis_lbl_3->show();
    ui->spinBox->show();
    ui->spinBox->setValue(1);
    ui->spinBox->setMaximum(facmaxint[34]);
    ui->spinBox->setMinimum(1);
    ui->tabWidget->setEnabled(false);
}

void Booking::on_btn_confirm_clicked()
{
    if (ui->dateselectedLabel->text() == "-" || ui->timeselectedLabel->text() == "-" || ui->facselected_lbl->text() == "-") {QMessageBox::information(this,"Warning!","Selection cannnot be EMPTY!");}
    if (ui->dateselectedLabel->text() != "-" && ui->timeselectedLabel->text() != "-" && ui->facselected_lbl->text() != "-"){
        facbooked = ui->spinBox->text();
        QString finalconfirm = "Date Selected : " + dateselectLabel + "\nTime Selected: " + timeselectedLabel + "\nVenue/Facilities Selected : " + facselected + "\nAmount of Venue/Facilities Booked: " + facbooked;
        QString initstatus = "BOOKED";
        QMessageBox::StandardButton selection = QMessageBox::question(this,"Confirmation",finalconfirm , QMessageBox::Yes | QMessageBox::No);
        if (selection == QMessageBox::Yes){
            MainWindow m;
            m.dbopened();
            int facbook = facbooked.split(" ")[0].toInt();
            int faccount = facval.split(" ")[0].toInt();
            int newcount = faccount - facbook;
            newfaccount = QString::number(newcount);
            QSqlQuery savebooking;
            savebooking.exec("insert into USERBOOKINGDATA (ACC_ID,FACILITIES_ID,FACILITIES_NAME,FACILITIES_BOOKED,DATECUSTOMBOOKED,DATEOFBOOKED,TIMEOFBOOKED,DAYOFBOOKED,STATUS)"
                                "values ('"+accid+"' , '"+facid+"' , '"+facselected+"' , '"+facbooked+"' ,'"+customdatefrom+"' , '"+dateselectLabel+"' , '"+timeselectedLabel+"' , '"+customday+"' , '"+initstatus+"')");
            QMessageBox::information(this, "Success", "Booking Success!");
            QSqlQuery update;
            update.exec("update facilitiesavailability set facilities_count = '"+newfaccount+"' where facilities_id = '"+facid+"'");
            m.dbclosed();
            hide();
            Manage *manage;
            manage = new Manage(this);
            if (username == "admin" && accid == "0"){
                manage->ui->frameadmin->show();
                manage->ui->frameuser->hide();
                manage->ui->frame1->hide();
                manage->ui->frameupdatestatus->hide();
            }
            else{
                manage->ui->frameadmin->hide();
                manage->ui->frameuser->show();
                manage->ui->frame1->hide();
                manage->ui->frameupdatestatus->hide();
            }
            manage->show();}
        else{}
}}

void Booking::on_btn_reset_3_clicked()
{
    ui->tabWidget->setEnabled(true);
    ui->facselected_lbl->setText("-");
    ui->maxfac_lbl->setText("-");
    ui->selecteddis_lbl_3->hide();
    ui->spinBox->hide();
}

void Booking::on_btn_reset_2_clicked()
{
    ui->dateselectedLabel->setText("-");
    ui->timeselectedLabel->setText("-");
    ui->btn_8am->setEnabled(true);
    ui->btn_9am->setEnabled(true);
    ui->btn_10am->setEnabled(true);
    ui->btn_11am->setEnabled(true);
    ui->btn_12pm->setEnabled(true);
    ui->btn_1pm->setEnabled(true);
    ui->btn_2pm->setEnabled(true);
    ui->btn_3pm->setEnabled(true);
    ui->btn_4pm->setEnabled(true);
    ui->btn_5pm->setEnabled(true);
    ui->btn_6pm->setEnabled(true);
    ui->btn_7pm->setEnabled(true);
    ui->btn_8pm->setEnabled(true);
    ui->btn_9pm->setEnabled(true);
}

void Booking::on_btn_return_clicked()
{
    hide();
    Manage *manage;
    manage = new Manage(this);
    manage->show();
}


void Booking::on_timecmbBox_currentIndexChanged(int index)
{
    switch(index){
        case 0:
            ui->calendarWidget->setEnabled(true);
            ui->time1hourbox->show();
            ui->time2hourbox->hide();
            ui->time3hourbox->hide();
            ui->time4hourbox->hide();
            ui->timecustomize->hide();
            break;
        case 1:
            ui->calendarWidget->setEnabled(true);
            ui->time1hourbox->hide();
            ui->time2hourbox->show();
            ui->time3hourbox->hide();
            ui->time4hourbox->hide();
            ui->timecustomize->hide();
            break;
        case 2:
            ui->calendarWidget->setEnabled(true);
            ui->time1hourbox->hide();
            ui->time2hourbox->hide();
            ui->time3hourbox->show();
            ui->time4hourbox->hide();
            ui->timecustomize->hide();
            break;
        case 3:
            ui->calendarWidget->setEnabled(true);
            ui->time1hourbox->hide();
            ui->time2hourbox->hide();
            ui->time3hourbox->hide();
            ui->time4hourbox->show();
            ui->timecustomize->hide();
            break;
        case 4:
            ui->calendarWidget->setEnabled(false);
            ui->time1hourbox->hide();
            ui->time2hourbox->hide();
            ui->time3hourbox->hide();
            ui->time4hourbox->hide();
            ui->timecustomize->show();
            break;
    }
}


void Booking::on_timefromcmbbox_currentIndexChanged(int index)
{
    switch(index){
        case 0:
            ui->timetocmbbox->clear();
            ui->timetocmbbox->setEnabled(true);
            ui->timetocmbbox->addItems({"0900","1000","1100","1200","1300","1400","1500","1600","1700","1800","1900","2000","2100","2200"});
            break;
        case 1:
            ui->timetocmbbox->clear();
            ui->timetocmbbox->setEnabled(true);
            ui->timetocmbbox->addItems({"1000","1100","1200","1300","1400","1500","1600","1700","1800","1900","2000","2100","2200"});
            break;
        case 2:
            ui->timetocmbbox->clear();
            ui->timetocmbbox->setEnabled(true);
            ui->timetocmbbox->addItems({"1100","1200","1300","1400","1500","1600","1700","1800","1900","2000","2100","2200"});
            break;
        case 3:
            ui->timetocmbbox->clear();
            ui->timetocmbbox->setEnabled(true);
            ui->timetocmbbox->addItems({"1200","1300","1400","1500","1600","1700","1800","1900","2000","2100","2200"});
            break;
        case 4:
            ui->timetocmbbox->clear();
            ui->timetocmbbox->setEnabled(true);
            ui->timetocmbbox->addItems({"1300","1400","1500","1600","1700","1800","1900","2000","2100","2200"});
            break;
        case 5:
            ui->timetocmbbox->clear();
            ui->timetocmbbox->setEnabled(true);
            ui->timetocmbbox->addItems({"1400","1500","1600","1700","1800","1900","2000","2100","2200"});
            break;
        case 6:
            ui->timetocmbbox->clear();
            ui->timetocmbbox->setEnabled(true);
            ui->timetocmbbox->addItems({"1500","1600","1700","1800","1900","2000","2100","2200"});
            break;
        case 7:
            ui->timetocmbbox->clear();
            ui->timetocmbbox->setEnabled(true);
            ui->timetocmbbox->addItems({"1600","1700","1800","1900","2000","2100","2200"});
            break;
        case 8:
            ui->timetocmbbox->clear();
            ui->timetocmbbox->setEnabled(true);
            ui->timetocmbbox->addItems({"1700","1800","1900","2000","2100","2200"});
            break;
        case 9:
            ui->timetocmbbox->clear();
            ui->timetocmbbox->setEnabled(true);
            ui->timetocmbbox->addItems({"1800","1900","2000","2100","2200"});
            break;
        case 10:
            ui->timetocmbbox->clear();
            ui->timetocmbbox->setEnabled(true);
            ui->timetocmbbox->addItems({"1900","2000","2100","2200"});
            break;
        case 11:
            ui->timetocmbbox->clear();
            ui->timetocmbbox->setEnabled(true);
            ui->timetocmbbox->addItems({"2000","2100","2200"});
            break;
        case 12:
            ui->timetocmbbox->clear();
            ui->timetocmbbox->setEnabled(true);
            ui->timetocmbbox->addItems({"2100","2200"});
            break;
        case 13:
            ui->timetocmbbox->clear();
            ui->timetocmbbox->setEnabled(true);
            ui->timetocmbbox->addItems({"2200"});
            break;
    }
}

void Booking::on_btn_customconfirm_clicked()
{
    customtimefrom = ui->timefromcmbbox->currentText();
    customtimeto = ui->timetocmbbox->currentText();
    customdatefrom = ui->dateEditfrom->text();
    customdateto = ui->dateEditto->text();
    customday = ui->daycmbbox->currentText();
    dateselectLabel = customdateto;
    timeselectedLabel = customtimefrom + " ~ " + customtimeto;
    ui->dateselectedLabel->setText(customdatefrom + " ~ " + customdateto);
    ui->timeselectedLabel->setText(timeselectedLabel);
    ui->dayselectLabel->show();
    ui->dayselectedLabel->show();
    ui->dayselectedLabel->setText(customday);
}

void Booking::on_btn_customreset_clicked()
{
    ui->timefromcmbbox->setCurrentIndex(0);
    ui->dateEditfrom->setDate(QDate::currentDate());
    ui->daycmbbox->setCurrentIndex(0);
    ui->dateselectedLabel->setText("-");
    ui->timeselectedLabel->setText("-");
    ui->dayselectLabel->hide();
    ui->dayselectedLabel->hide();
}

void Booking::disablefacs(){
    if (facint[0] < facmaxint[0] || facint[0] == 0){ui->btn_lecturehall->setEnabled(false);}
    else{ui->btn_lecturehall->setEnabled(true);}
    if (facint[1] < facmaxint[1] || facint[1] == 0){ui->btn_lectureroom->setEnabled(false);}
    else{ui->btn_lectureroom->setEnabled(true);}
    if (facint[2] < facmaxint[2] || facint[2] == 0){ui->btn_tutorialroom->setEnabled(false);}
    else{ui->btn_tutorialroom->setEnabled(true);}
    if (facint[3] < facmaxint[3] || facint[3] == 0){ui->btn_oslab->setEnabled(false);}
    else{ui->btn_oslab->setEnabled(true);}
    if (facint[4] < facmaxint[4] || facint[4] == 0){ui->btn_pclab->setEnabled(false);}
    else{ui->btn_pclab->setEnabled(true);}
    if (facint[5] < facmaxint[5] || facint[5] == 0){ui->btn_explab->setEnabled(false);}
    else{ui->btn_explab->setEnabled(true);}
    if (facint[6] < facmaxint[6] || facint[6] == 0){ui->btn_engineerlab->setEnabled(false);}
    else{ui->btn_engineerlab->setEnabled(true);}
    if (facint[7] < facmaxint[7] || facint[7] == 0){ui->btn_meetingroom->setEnabled(false);}
    else{ui->btn_meetingroom->setEnabled(true);}
    if (facint[8] < facmaxint[8] || facint[8] == 0){ui->btn_artroom->setEnabled(false);}
    else{ui->btn_artroom->setEnabled(true);}
    if (facint[9] < facmaxint[9] || facint[9] == 0){ui->btn_greensroom->setEnabled(false);}
    else{ui->btn_greensroom->setEnabled(true);}
    if (facint[10] < facmaxint[10] || facint[10] == 0){ui->btn_vidshootroom->setEnabled(false);}
    else{ui->btn_vidshootroom->setEnabled(true);}
    if (facint[11] < facmaxint[11] || facint[11] == 0){ui->btn_audioroom->setEnabled(false);}
    else{ui->btn_audioroom->setEnabled(true);}
    if (facint[12] < facmaxint[12] || facint[12] == 0){ui->btn_videoeditroom->setEnabled(false);}
    else{ui->btn_videoeditroom->setEnabled(true);}
    if (facint[13] < facmaxint[13] || facint[13] == 0){ui->btn_eventhall->setEnabled(false);}
    else{ui->btn_eventhall->setEnabled(true);}
    if (facint[14] < facmaxint[14] || facint[14] == 0){ui->btn_corridor->setEnabled(false);}
    else{ui->btn_corridor->setEnabled(true);}
    if (facint[15] < facmaxint[15] || facint[15] == 0){ui->btn_plaza->setEnabled(false);}
    else{ui->btn_plaza->setEnabled(true);}
    if (facint[16] < facmaxint[16] || facint[16] == 0){ui->btn_basketballcourt->setEnabled(false);}
    else{ui->btn_basketballcourt->setEnabled(true);}
    if (facint[17] < facmaxint[17] || facint[17] == 0){ui->btn_tenniscourt->setEnabled(false);}
    else{ui->btn_tenniscourt->setEnabled(true);}
    if (facint[18] < facmaxint[18] || facint[18] == 0){ui->btn_badmintoncourt->setEnabled(false);}
    else{ui->btn_badmintoncourt->setEnabled(true);}
    if (facint[19] < facmaxint[19] || facint[19] == 0){ui->btn_pool->setEnabled(false);}
    else{ui->btn_pool->setEnabled(true);}
    if (facint[20] < facmaxint[20] || facint[20] == 0){ui->btn_field->setEnabled(false);}
    else{ui->btn_field->setEnabled(true);}
    if (facint[21] < facmaxint[21] || facint[21] == 0){ui->btn_volleycourt->setEnabled(false);}
    else{ui->btn_volleycourt->setEnabled(true);}
    if (facint[22] < facmaxint[22] || facint[22] == 0){ui->btn_gym->setEnabled(false);}
    else{ui->btn_gym->setEnabled(true);}
    if (facint[23] < facmaxint[23] || facint[23] == 0){ui->btn_skatepark->setEnabled(false);}
    else{ui->btn_skatepark->setEnabled(true);}
    if (facint[24] < facmaxint[24] || facint[24] == 0){ui->btn_broom->setEnabled(false);}
    else{ui->btn_broom->setEnabled(true);}
    if (facint[25] < facmaxint[25] || facint[25] == 0){ui->btn_mop->setEnabled(false);}
    else{ui->btn_mop->setEnabled(true);}
    if (facint[26] < facmaxint[26] || facint[26] == 0){ui->btn_table->setEnabled(false);}
    else{ui->btn_table->setEnabled(true);}
    if (facint[27] < facmaxint[27] || facint[27] == 0){ui->btn_chair->setEnabled(false);}
    else{ui->btn_chair->setEnabled(true);}
    if (facint[28] < facmaxint[28] || facint[28] == 0){ui->btn_ladder->setEnabled(false);}
    else{ui->btn_ladder->setEnabled(true);}
    if (facint[29] < facmaxint[29] || facint[29] == 0){ui->btn_queuebarrier->setEnabled(false);}
    else{ui->btn_queuebarrier->setEnabled(true);}
    if (facint[30] < facmaxint[30] || facint[30] == 0){ui->btn_bannerstand->setEnabled(false);}
    else{ui->btn_bannerstand->setEnabled(true);}
    if (facint[31] < facmaxint[31] || facint[31] == 0){ui->btn_bucket->setEnabled(false);}
    else{ui->btn_bucket->setEnabled(true);}
    if (facint[32] < facmaxint[32] || facint[32] == 0){ui->btn_waterbucket->setEnabled(false);}
    else{ui->btn_waterbucket->setEnabled(true);}
    if (facint[33] < facmaxint[33] || facint[33] == 0){ui->btn_waterpipe->setEnabled(false);}
    else{ui->btn_waterpipe->setEnabled(true);}
    if (facint[34] < facmaxint[34] || facint[34] == 0){ui->btn_waterwiper->setEnabled(false);}
    else{ui->btn_waterwiper->setEnabled(true);}

}
