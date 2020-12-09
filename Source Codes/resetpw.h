#ifndef RESETPW_H
#define RESETPW_H

#include <QMainWindow>
#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace Ui {
class ResetPW;
}

class ResetPW : public QMainWindow
{
    Q_OBJECT

public:
    explicit ResetPW(QWidget *parent = nullptr);
    QString getuser(){return user;}
    QString getpassw(){return passw;}
    QString getstudentid(){return studentid;}
    QString getstudentid_cin(){return studentid_cin;}
    QString getseqanswer(){return seqanswer;}
    QString getseqanswer_cin(){return seqanswer_cin;}
    int getcomboboxindex(){return comboboxindex;}
    ~ResetPW();

private slots:
    void on_continue_btn_clicked();
    void on_display1_clicked();
    void on_continue_btn_2_clicked();
    void on_btn_rback2login_2_clicked();
    void on_btn_rback2login_clicked();
    void on_btn_rback2login_3_clicked();
    void on_btn_changepw_clicked();

private:
    Ui::ResetPW *ui;
    QString user, passw, studentid, studentid_cin, seqanswer, seqanswer_cin;
    int comboboxindex;
};

#endif // RESETPW_H
