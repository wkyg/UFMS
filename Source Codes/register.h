#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QtSql>
#include "mainwindow.h"

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    QString user, pass,studid,index,ans;
    QString getusername_reg(){return username_reg;}
    QString getpassword_reg(){return password_reg;}
    QString getstudentid_reg(){return studentid_reg;}
    QString getseqanswer_reg(){return seqanswer_reg;}
    int getcomboboxindex(){return comboboxindex;}
    ~Register();

private slots:
    void on_btn_register_reg_clicked();
    void on_btn_rback2login_clicked();

private:
    Ui::Register *ui;
    QString username_reg, password_reg, studentid_reg, seqanswer_reg;
    int comboboxindex;
};


#endif // REGISTER_H
