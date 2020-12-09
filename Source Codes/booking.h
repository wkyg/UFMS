#ifndef BOOKING_H
#define BOOKING_H

#include <QMainWindow>
#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace Ui {
class Booking;
}

class Booking : public QMainWindow
{
    Q_OBJECT

public:
    Ui::Booking *ui;
    explicit Booking(QWidget *parent = nullptr);
    QString facselected, facid, facval, facbooked;
    QString username, accid, newfaccount;
    QString FAC[35], facmax[35];
    int facint[35], facmaxint[35];
    QString customtimefrom, customtimeto, customdatefrom, customdateto, customday;
    QString getday(){return day;}
    QString getmonth(){return month;}
    QString getyear(){return year;}
    QString getdaytdy(){return daytdy;}
    QString getmonthtdy(){return monthtdy;}
    QString getyeartdy(){return yeartdy;}
    QString getdateselectLabel(){return dateselectLabel;}
    QString gettimeselectLabel(){return timeselectedLabel;}
    QString getdatetdylabel(){return datetdylbl;}
    ~Booking();

private slots:
    void on_btn_clicked();
    void on_btn_confirm_clicked();
    void currentsession();
    void on_btn_logout_clicked();
    void on_btn_lectureroom_clicked();
    void on_btn_lecturehall_clicked();
    void on_btn_tutorialroom_clicked();
    void on_btn_meetingroom_clicked();
    void on_btn_oslab_clicked();
    void faccurrentavailability();
    void on_btn_reset_clicked();
    void on_btn_pclab_clicked();
    void on_btn_explab_clicked();
    void on_btn_engineerlab_clicked();
    void on_btn_vidshootroom_clicked();
    void on_btn_artroom_clicked();
    void on_btn_greensroom_clicked();
    void on_btn_audioroom_clicked();
    void on_btn_videoeditroom_clicked();
    void on_btn_eventhall_clicked();
    void on_btn_corridor_clicked();
    void on_btn_plaza_clicked();
    void on_btn_basketballcourt_clicked();
    void on_btn_tenniscourt_clicked();
    void on_btn_badmintoncourt_clicked();
    void on_btn_pool_clicked();
    void on_btn_field_clicked();
    void on_btn_volleycourt_clicked();
    void on_btn_gym_clicked();
    void on_btn_skatepark_clicked();
    void on_btn_broom_clicked();
    void on_btn_mop_clicked();
    void on_btn_table_clicked();
    void on_btn_chair_clicked();
    void on_btn_ladder_clicked();
    void on_btn_queuebarrier_clicked();
    void on_btn_bannerstand_clicked();
    void on_btn_bucket_clicked();
    void on_btn_waterbucket_clicked();
    void on_btn_waterpipe_clicked();
    void on_btn_waterwiper_clicked();
    void displaytime();
    void disabletimebtn();
    void on_calendarWidget_clicked(const QDate &date);
    void on_btn_8am_clicked();
    void on_btn_9am_clicked();
    void on_btn_10am_clicked();
    void on_btn_11am_clicked();
    void on_btn_12pm_clicked();
    void on_btn_1pm_clicked();
    void on_btn_2pm_clicked();
    void on_btn_3pm_clicked();
    void on_btn_4pm_clicked();
    void on_btn_5pm_clicked();
    void on_btn_6pm_clicked();
    void on_btn_7pm_clicked();
    void on_btn_8pm_clicked();
    void on_btn_9pm_clicked();
    void on_btn_wholeday_clicked();
    void on_btn_reset_3_clicked();
    void on_btn_reset_2_clicked();
    void on_btn_return_clicked();
    void on_timecmbBox_currentIndexChanged(int index);
    void on_btn_12pm_4_clicked();
    void on_btn_4pm_4_clicked();
    void on_btn_8am_4_clicked();
    void on_btn_wholeday_4_clicked();
    void on_btn_11am_3_clicked();
    void on_btn_2pm_3_clicked();
    void on_btn_5pm_3_clicked();
    void on_btn_8am_3_clicked();
    void on_btn_8pm_3_clicked();
    void on_btn_wholeday_3_clicked();
    void on_btn_10am_2_clicked();
    void on_btn_12pm_2_clicked();
    void on_btn_2pm_2_clicked();
    void on_btn_4pm_2_clicked();
    void on_btn_6pm_2_clicked();
    void on_btn_8am_2_clicked();
    void on_btn_8pm_2_clicked();
    void on_btn_wholeday_2_clicked();
    void on_timefromcmbbox_currentIndexChanged(int index);
    void on_btn_customconfirm_clicked();
    void on_btn_customreset_clicked();
    void disablefacs();

private:
    QString day, month, year, daytdy, monthtdy, yeartdy;
    QString dateselectLabel, timeselectedLabel;
    QDateTime datetdy = QDateTime::currentDateTime();
    QString datetdylbl = datetdy.toString("dd/MM/yyyy");
};

#endif // BOOKING_H
