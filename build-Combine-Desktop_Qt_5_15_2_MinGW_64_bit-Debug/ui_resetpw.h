/********************************************************************************
** Form generated from reading UI file 'resetpw.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETPW_H
#define UI_RESETPW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResetPW
{
public:
    QWidget *centralwidget;
    QGroupBox *display0;
    QLineEdit *lineEdit_studid;
    QPushButton *continue_btn;
    QLabel *label_StudentID;
    QFrame *oframe2;
    QFrame *oframe4;
    QFrame *oframe3;
    QLabel *copyright;
    QFrame *oframe1;
    QLabel *label;
    QPushButton *btn_rback2login;
    QLabel *error_lbl;
    QGroupBox *display1;
    QLineEdit *lineEdit_answer;
    QPushButton *continue_btn_2;
    QLabel *label_StudentIDlbl;
    QFrame *oframe2_2;
    QFrame *oframe4_2;
    QFrame *oframe3_2;
    QLabel *copyright_2;
    QFrame *oframe1_2;
    QLabel *label_2;
    QPushButton *btn_rback2login_2;
    QLabel *error_lbl_2;
    QLabel *label_currentstudid;
    QLabel *label_seq;
    QLabel *seques_lbl;
    QLabel *label_ans;
    QGroupBox *display2;
    QLineEdit *lineEdit_password;
    QPushButton *btn_changepw;
    QLabel *label_StudentIDlbl_2;
    QFrame *oframe2_4;
    QFrame *oframe4_4;
    QFrame *oframe3_4;
    QLabel *copyright_4;
    QFrame *oframe1_4;
    QPushButton *btn_rback2login_3;
    QLabel *error_lbl_3;
    QLabel *label_currentstudid_2;
    QLabel *label_ans_2;
    QLabel *db_lbl;

    void setupUi(QMainWindow *ResetPW)
    {
        if (ResetPW->objectName().isEmpty())
            ResetPW->setObjectName(QString::fromUtf8("ResetPW"));
        ResetPW->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        ResetPW->setWindowIcon(icon);
        centralwidget = new QWidget(ResetPW);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        display0 = new QGroupBox(centralwidget);
        display0->setObjectName(QString::fromUtf8("display0"));
        display0->setGeometry(QRect(0, 0, 800, 600));
        lineEdit_studid = new QLineEdit(display0);
        lineEdit_studid->setObjectName(QString::fromUtf8("lineEdit_studid"));
        lineEdit_studid->setGeometry(QRect(288, 260, 231, 31));
        QFont font;
        font.setPointSize(13);
        lineEdit_studid->setFont(font);
        lineEdit_studid->setMouseTracking(false);
        lineEdit_studid->setAcceptDrops(true);
        lineEdit_studid->setMaxLength(10);
        lineEdit_studid->setCursorMoveStyle(Qt::LogicalMoveStyle);
        lineEdit_studid->setClearButtonEnabled(true);
        continue_btn = new QPushButton(display0);
        continue_btn->setObjectName(QString::fromUtf8("continue_btn"));
        continue_btn->setGeometry(QRect(350, 320, 111, 51));
        continue_btn->setFont(font);
        label_StudentID = new QLabel(display0);
        label_StudentID->setObjectName(QString::fromUtf8("label_StudentID"));
        label_StudentID->setGeometry(QRect(288, 230, 231, 27));
        label_StudentID->setFont(font);
        oframe2 = new QFrame(display0);
        oframe2->setObjectName(QString::fromUtf8("oframe2"));
        oframe2->setGeometry(QRect(10, 0, 781, 16));
        oframe2->setFrameShape(QFrame::HLine);
        oframe2->setFrameShadow(QFrame::Sunken);
        oframe4 = new QFrame(display0);
        oframe4->setObjectName(QString::fromUtf8("oframe4"));
        oframe4->setGeometry(QRect(10, 580, 781, 16));
        oframe4->setFrameShape(QFrame::HLine);
        oframe4->setFrameShadow(QFrame::Sunken);
        oframe3 = new QFrame(display0);
        oframe3->setObjectName(QString::fromUtf8("oframe3"));
        oframe3->setGeometry(QRect(780, 10, 20, 581));
        oframe3->setFrameShape(QFrame::VLine);
        oframe3->setFrameShadow(QFrame::Sunken);
        copyright = new QLabel(display0);
        copyright->setObjectName(QString::fromUtf8("copyright"));
        copyright->setGeometry(QRect(12, 570, 111, 16));
        oframe1 = new QFrame(display0);
        oframe1->setObjectName(QString::fromUtf8("oframe1"));
        oframe1->setGeometry(QRect(0, 10, 20, 581));
        oframe1->setFrameShape(QFrame::VLine);
        oframe1->setFrameShadow(QFrame::Sunken);
        label = new QLabel(display0);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 501, 51));
        QFont font1;
        font1.setPointSize(15);
        label->setFont(font1);
        btn_rback2login = new QPushButton(display0);
        btn_rback2login->setObjectName(QString::fromUtf8("btn_rback2login"));
        btn_rback2login->setGeometry(QRect(590, 16, 191, 51));
        btn_rback2login->setFont(font);
        error_lbl = new QLabel(display0);
        error_lbl->setObjectName(QString::fromUtf8("error_lbl"));
        error_lbl->setGeometry(QRect(295, 292, 221, 20));
        QFont font2;
        font2.setPointSize(9);
        error_lbl->setFont(font2);
        error_lbl->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        display1 = new QGroupBox(centralwidget);
        display1->setObjectName(QString::fromUtf8("display1"));
        display1->setGeometry(QRect(0, 0, 800, 600));
        lineEdit_answer = new QLineEdit(display1);
        lineEdit_answer->setObjectName(QString::fromUtf8("lineEdit_answer"));
        lineEdit_answer->setGeometry(QRect(328, 260, 231, 31));
        lineEdit_answer->setFont(font);
        lineEdit_answer->setMouseTracking(false);
        lineEdit_answer->setAcceptDrops(true);
        lineEdit_answer->setMaxLength(10);
        lineEdit_answer->setCursorMoveStyle(Qt::LogicalMoveStyle);
        lineEdit_answer->setClearButtonEnabled(true);
        continue_btn_2 = new QPushButton(display1);
        continue_btn_2->setObjectName(QString::fromUtf8("continue_btn_2"));
        continue_btn_2->setGeometry(QRect(350, 320, 111, 51));
        continue_btn_2->setFont(font);
        label_StudentIDlbl = new QLabel(display1);
        label_StudentIDlbl->setObjectName(QString::fromUtf8("label_StudentIDlbl"));
        label_StudentIDlbl->setGeometry(QRect(15, 10, 101, 27));
        label_StudentIDlbl->setFont(font);
        oframe2_2 = new QFrame(display1);
        oframe2_2->setObjectName(QString::fromUtf8("oframe2_2"));
        oframe2_2->setGeometry(QRect(10, 0, 781, 16));
        oframe2_2->setFrameShape(QFrame::HLine);
        oframe2_2->setFrameShadow(QFrame::Sunken);
        oframe4_2 = new QFrame(display1);
        oframe4_2->setObjectName(QString::fromUtf8("oframe4_2"));
        oframe4_2->setGeometry(QRect(10, 580, 781, 16));
        oframe4_2->setFrameShape(QFrame::HLine);
        oframe4_2->setFrameShadow(QFrame::Sunken);
        oframe3_2 = new QFrame(display1);
        oframe3_2->setObjectName(QString::fromUtf8("oframe3_2"));
        oframe3_2->setGeometry(QRect(780, 10, 20, 581));
        oframe3_2->setFrameShape(QFrame::VLine);
        oframe3_2->setFrameShadow(QFrame::Sunken);
        copyright_2 = new QLabel(display1);
        copyright_2->setObjectName(QString::fromUtf8("copyright_2"));
        copyright_2->setGeometry(QRect(12, 570, 111, 16));
        oframe1_2 = new QFrame(display1);
        oframe1_2->setObjectName(QString::fromUtf8("oframe1_2"));
        oframe1_2->setGeometry(QRect(0, 10, 20, 581));
        oframe1_2->setFrameShape(QFrame::VLine);
        oframe1_2->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(display1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 10, 501, 51));
        label_2->setFont(font1);
        btn_rback2login_2 = new QPushButton(display1);
        btn_rback2login_2->setObjectName(QString::fromUtf8("btn_rback2login_2"));
        btn_rback2login_2->setGeometry(QRect(590, 16, 191, 51));
        btn_rback2login_2->setFont(font);
        error_lbl_2 = new QLabel(display1);
        error_lbl_2->setObjectName(QString::fromUtf8("error_lbl_2"));
        error_lbl_2->setGeometry(QRect(298, 293, 221, 20));
        error_lbl_2->setFont(font2);
        error_lbl_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        label_currentstudid = new QLabel(display1);
        label_currentstudid->setObjectName(QString::fromUtf8("label_currentstudid"));
        label_currentstudid->setGeometry(QRect(120, 10, 101, 27));
        label_currentstudid->setFont(font);
        label_seq = new QLabel(display1);
        label_seq->setObjectName(QString::fromUtf8("label_seq"));
        label_seq->setGeometry(QRect(328, 192, 181, 27));
        label_seq->setFont(font);
        seques_lbl = new QLabel(display1);
        seques_lbl->setObjectName(QString::fromUtf8("seques_lbl"));
        seques_lbl->setGeometry(QRect(170, 220, 461, 27));
        seques_lbl->setFont(font);
        seques_lbl->setAlignment(Qt::AlignCenter);
        label_ans = new QLabel(display1);
        label_ans->setObjectName(QString::fromUtf8("label_ans"));
        label_ans->setGeometry(QRect(248, 262, 71, 27));
        label_ans->setFont(font);
        display2 = new QGroupBox(centralwidget);
        display2->setObjectName(QString::fromUtf8("display2"));
        display2->setGeometry(QRect(0, 0, 800, 600));
        lineEdit_password = new QLineEdit(display2);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(358, 260, 231, 31));
        lineEdit_password->setFont(font);
        lineEdit_password->setMouseTracking(false);
        lineEdit_password->setAcceptDrops(true);
        lineEdit_password->setMaxLength(20);
        lineEdit_password->setCursorMoveStyle(Qt::LogicalMoveStyle);
        lineEdit_password->setClearButtonEnabled(true);
        btn_changepw = new QPushButton(display2);
        btn_changepw->setObjectName(QString::fromUtf8("btn_changepw"));
        btn_changepw->setGeometry(QRect(300, 320, 211, 51));
        btn_changepw->setFont(font);
        label_StudentIDlbl_2 = new QLabel(display2);
        label_StudentIDlbl_2->setObjectName(QString::fromUtf8("label_StudentIDlbl_2"));
        label_StudentIDlbl_2->setGeometry(QRect(15, 10, 101, 27));
        label_StudentIDlbl_2->setFont(font);
        oframe2_4 = new QFrame(display2);
        oframe2_4->setObjectName(QString::fromUtf8("oframe2_4"));
        oframe2_4->setGeometry(QRect(10, 0, 781, 16));
        oframe2_4->setFrameShape(QFrame::HLine);
        oframe2_4->setFrameShadow(QFrame::Sunken);
        oframe4_4 = new QFrame(display2);
        oframe4_4->setObjectName(QString::fromUtf8("oframe4_4"));
        oframe4_4->setGeometry(QRect(10, 580, 781, 20));
        oframe4_4->setFrameShape(QFrame::HLine);
        oframe4_4->setFrameShadow(QFrame::Sunken);
        oframe3_4 = new QFrame(display2);
        oframe3_4->setObjectName(QString::fromUtf8("oframe3_4"));
        oframe3_4->setGeometry(QRect(780, 10, 20, 581));
        oframe3_4->setFrameShape(QFrame::VLine);
        oframe3_4->setFrameShadow(QFrame::Sunken);
        copyright_4 = new QLabel(display2);
        copyright_4->setObjectName(QString::fromUtf8("copyright_4"));
        copyright_4->setGeometry(QRect(12, 570, 111, 16));
        oframe1_4 = new QFrame(display2);
        oframe1_4->setObjectName(QString::fromUtf8("oframe1_4"));
        oframe1_4->setGeometry(QRect(0, 10, 20, 581));
        oframe1_4->setFrameShape(QFrame::VLine);
        oframe1_4->setFrameShadow(QFrame::Sunken);
        btn_rback2login_3 = new QPushButton(display2);
        btn_rback2login_3->setObjectName(QString::fromUtf8("btn_rback2login_3"));
        btn_rback2login_3->setGeometry(QRect(590, 16, 191, 51));
        btn_rback2login_3->setFont(font);
        error_lbl_3 = new QLabel(display2);
        error_lbl_3->setObjectName(QString::fromUtf8("error_lbl_3"));
        error_lbl_3->setGeometry(QRect(268, 292, 291, 20));
        error_lbl_3->setFont(font2);
        error_lbl_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        error_lbl_3->setAlignment(Qt::AlignCenter);
        label_currentstudid_2 = new QLabel(display2);
        label_currentstudid_2->setObjectName(QString::fromUtf8("label_currentstudid_2"));
        label_currentstudid_2->setGeometry(QRect(120, 10, 101, 27));
        label_currentstudid_2->setFont(font);
        label_ans_2 = new QLabel(display2);
        label_ans_2->setObjectName(QString::fromUtf8("label_ans_2"));
        label_ans_2->setGeometry(QRect(218, 261, 141, 27));
        label_ans_2->setFont(font);
        db_lbl = new QLabel(centralwidget);
        db_lbl->setObjectName(QString::fromUtf8("db_lbl"));
        db_lbl->setGeometry(QRect(688, 570, 101, 16));
        ResetPW->setCentralWidget(centralwidget);
        display2->raise();
        db_lbl->raise();
        display0->raise();
        display1->raise();

        retranslateUi(ResetPW);
        QObject::connect(lineEdit_studid, SIGNAL(returnPressed()), continue_btn, SLOT(click()));
        QObject::connect(lineEdit_answer, SIGNAL(returnPressed()), continue_btn_2, SLOT(click()));
        QObject::connect(lineEdit_password, SIGNAL(returnPressed()), btn_changepw, SLOT(click()));

        QMetaObject::connectSlotsByName(ResetPW);
    } // setupUi

    void retranslateUi(QMainWindow *ResetPW)
    {
        ResetPW->setWindowTitle(QCoreApplication::translate("ResetPW", "University Faclilities Management System (UFMS)", nullptr));
        display0->setTitle(QString());
        continue_btn->setText(QCoreApplication::translate("ResetPW", "CONTINUE", nullptr));
        label_StudentID->setText(QCoreApplication::translate("ResetPW", "PLEASE INSERT STUDENT ID :", nullptr));
        copyright->setText(QCoreApplication::translate("ResetPW", "\302\251 SLAUATRON 2019.", nullptr));
        label->setText(QString());
        btn_rback2login->setText(QCoreApplication::translate("ResetPW", "BACK TO LOGIN PAGE", nullptr));
        error_lbl->setText(QCoreApplication::translate("ResetPW", "Student ID not found. Please try again.", nullptr));
        display1->setTitle(QString());
        continue_btn_2->setText(QCoreApplication::translate("ResetPW", "CONTINUE", nullptr));
        label_StudentIDlbl->setText(QCoreApplication::translate("ResetPW", "STUDENT ID:", nullptr));
        copyright_2->setText(QCoreApplication::translate("ResetPW", "\302\251 SLAUATRON 2019.", nullptr));
        label_2->setText(QString());
        btn_rback2login_2->setText(QCoreApplication::translate("ResetPW", "BACK TO LOGIN PAGE", nullptr));
        error_lbl_2->setText(QCoreApplication::translate("ResetPW", "Answer incorrect. Please try again.", nullptr));
        label_currentstudid->setText(QCoreApplication::translate("ResetPW", "studentid", nullptr));
        label_seq->setText(QCoreApplication::translate("ResetPW", "SEQURITY QUESTION:", nullptr));
        seques_lbl->setText(QCoreApplication::translate("ResetPW", "seques_lbl", nullptr));
        label_ans->setText(QCoreApplication::translate("ResetPW", "ANSWER:", nullptr));
        display2->setTitle(QString());
        btn_changepw->setText(QCoreApplication::translate("ResetPW", "CHANGE PASSWORD", nullptr));
        label_StudentIDlbl_2->setText(QCoreApplication::translate("ResetPW", "STUDENT ID:", nullptr));
        copyright_4->setText(QCoreApplication::translate("ResetPW", "\302\251 SLAUATRON 2019.", nullptr));
        btn_rback2login_3->setText(QCoreApplication::translate("ResetPW", "BACK TO LOGIN PAGE", nullptr));
        error_lbl_3->setText(QCoreApplication::translate("ResetPW", "New password cannot be the same as old password!", nullptr));
        label_currentstudid_2->setText(QCoreApplication::translate("ResetPW", "studentid", nullptr));
        label_ans_2->setText(QCoreApplication::translate("ResetPW", "NEW PASSWORD:", nullptr));
        db_lbl->setText(QCoreApplication::translate("ResetPW", "Connected to UFMS!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResetPW: public Ui_ResetPW {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETPW_H
