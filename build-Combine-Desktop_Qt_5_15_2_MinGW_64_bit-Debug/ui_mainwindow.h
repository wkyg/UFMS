/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btn_Login;
    QPushButton *btn_Register;
    QLineEdit *lineEdit_Password;
    QLabel *label_Password;
    QLabel *label_Username;
    QLineEdit *lineEdit_Username;
    QPushButton *btn_passhideview;
    QFrame *line;
    QPushButton *btn_Resetpw;
    QLabel *logo_lbl;
    QFrame *oframe2;
    QFrame *oframe1;
    QFrame *oframe3;
    QLabel *copyright;
    QFrame *oframe4;
    QLabel *error_lbl;
    QLabel *db_lbl;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        btn_Login = new QPushButton(centralWidget);
        btn_Login->setObjectName(QString::fromUtf8("btn_Login"));
        btn_Login->setGeometry(QRect(350, 347, 101, 41));
        QFont font;
        font.setPointSize(13);
        btn_Login->setFont(font);
        btn_Login->setCursor(QCursor(Qt::PointingHandCursor));
        btn_Register = new QPushButton(centralWidget);
        btn_Register->setObjectName(QString::fromUtf8("btn_Register"));
        btn_Register->setGeometry(QRect(350, 485, 101, 41));
        btn_Register->setFont(font);
        btn_Register->setCursor(QCursor(Qt::PointingHandCursor));
        lineEdit_Password = new QLineEdit(centralWidget);
        lineEdit_Password->setObjectName(QString::fromUtf8("lineEdit_Password"));
        lineEdit_Password->setEnabled(true);
        lineEdit_Password->setGeometry(QRect(330, 281, 211, 31));
        lineEdit_Password->setFont(font);
        lineEdit_Password->setMouseTracking(false);
        lineEdit_Password->setMaxLength(20);
        lineEdit_Password->setClearButtonEnabled(true);
        label_Password = new QLabel(centralWidget);
        label_Password->setObjectName(QString::fromUtf8("label_Password"));
        label_Password->setGeometry(QRect(230, 281, 101, 27));
        label_Password->setFont(font);
        label_Username = new QLabel(centralWidget);
        label_Username->setObjectName(QString::fromUtf8("label_Username"));
        label_Username->setGeometry(QRect(230, 249, 101, 20));
        label_Username->setFont(font);
        lineEdit_Username = new QLineEdit(centralWidget);
        lineEdit_Username->setObjectName(QString::fromUtf8("lineEdit_Username"));
        lineEdit_Username->setGeometry(QRect(330, 245, 211, 31));
        lineEdit_Username->setFont(font);
        lineEdit_Username->setMouseTracking(false);
        lineEdit_Username->setMaxLength(15);
        lineEdit_Username->setClearButtonEnabled(true);
        btn_passhideview = new QPushButton(centralWidget);
        btn_passhideview->setObjectName(QString::fromUtf8("btn_passhideview"));
        btn_passhideview->setGeometry(QRect(540, 280, 33, 33));
        btn_passhideview->setCursor(QCursor(Qt::PointingHandCursor));
        btn_passhideview->setIconSize(QSize(35, 35));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 460, 781, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        btn_Resetpw = new QPushButton(centralWidget);
        btn_Resetpw->setObjectName(QString::fromUtf8("btn_Resetpw"));
        btn_Resetpw->setGeometry(QRect(310, 430, 181, 21));
        QFont font1;
        font1.setUnderline(true);
        btn_Resetpw->setFont(font1);
        btn_Resetpw->setCursor(QCursor(Qt::PointingHandCursor));
        btn_Resetpw->setAutoRepeatDelay(0);
        btn_Resetpw->setAutoRepeatInterval(0);
        btn_Resetpw->setFlat(true);
        logo_lbl = new QLabel(centralWidget);
        logo_lbl->setObjectName(QString::fromUtf8("logo_lbl"));
        logo_lbl->setGeometry(QRect(124, 60, 551, 161));
        QFont font2;
        font2.setPointSize(15);
        logo_lbl->setFont(font2);
        logo_lbl->setScaledContents(true);
        logo_lbl->setAlignment(Qt::AlignCenter);
        oframe2 = new QFrame(centralWidget);
        oframe2->setObjectName(QString::fromUtf8("oframe2"));
        oframe2->setGeometry(QRect(10, 0, 781, 16));
        oframe2->setFrameShape(QFrame::HLine);
        oframe2->setFrameShadow(QFrame::Sunken);
        oframe1 = new QFrame(centralWidget);
        oframe1->setObjectName(QString::fromUtf8("oframe1"));
        oframe1->setGeometry(QRect(0, 10, 20, 581));
        oframe1->setFrameShape(QFrame::VLine);
        oframe1->setFrameShadow(QFrame::Sunken);
        oframe3 = new QFrame(centralWidget);
        oframe3->setObjectName(QString::fromUtf8("oframe3"));
        oframe3->setGeometry(QRect(780, 10, 20, 581));
        oframe3->setFrameShape(QFrame::VLine);
        oframe3->setFrameShadow(QFrame::Sunken);
        copyright = new QLabel(centralWidget);
        copyright->setObjectName(QString::fromUtf8("copyright"));
        copyright->setGeometry(QRect(12, 570, 111, 16));
        oframe4 = new QFrame(centralWidget);
        oframe4->setObjectName(QString::fromUtf8("oframe4"));
        oframe4->setGeometry(QRect(10, 580, 781, 20));
        oframe4->setFrameShape(QFrame::HLine);
        oframe4->setFrameShadow(QFrame::Sunken);
        error_lbl = new QLabel(centralWidget);
        error_lbl->setObjectName(QString::fromUtf8("error_lbl"));
        error_lbl->setGeometry(QRect(256, 320, 291, 20));
        QFont font3;
        font3.setPointSize(9);
        error_lbl->setFont(font3);
        error_lbl->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        db_lbl = new QLabel(centralWidget);
        db_lbl->setObjectName(QString::fromUtf8("db_lbl"));
        db_lbl->setGeometry(QRect(688, 570, 101, 16));
        MainWindow->setCentralWidget(centralWidget);
        QWidget::setTabOrder(lineEdit_Username, lineEdit_Password);
        QWidget::setTabOrder(lineEdit_Password, btn_Login);
        QWidget::setTabOrder(btn_Login, btn_passhideview);
        QWidget::setTabOrder(btn_passhideview, btn_Resetpw);
        QWidget::setTabOrder(btn_Resetpw, btn_Register);

        retranslateUi(MainWindow);
        QObject::connect(lineEdit_Password, SIGNAL(returnPressed()), btn_Login, SLOT(click()));
        QObject::connect(lineEdit_Username, SIGNAL(returnPressed()), lineEdit_Password, SLOT(setFocus()));
        QObject::connect(lineEdit_Username, SIGNAL(editingFinished()), lineEdit_Password, SLOT(setFocus()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "University Faclilities Management System (UFMS)", nullptr));
        btn_Login->setText(QCoreApplication::translate("MainWindow", "LOGIN", nullptr));
        btn_Register->setText(QCoreApplication::translate("MainWindow", "REGISTER", nullptr));
        label_Password->setText(QCoreApplication::translate("MainWindow", "PASSWORD:", nullptr));
        label_Username->setText(QCoreApplication::translate("MainWindow", "USERNAME:", nullptr));
        btn_passhideview->setText(QString());
        btn_Resetpw->setText(QCoreApplication::translate("MainWindow", "Forgot Password? Click HERE", nullptr));
        logo_lbl->setText(QString());
        copyright->setText(QCoreApplication::translate("MainWindow", "\302\251 SLAUATRON 2019.", nullptr));
        error_lbl->setText(QCoreApplication::translate("MainWindow", "Username or password is incorrect. Please try again.", nullptr));
        db_lbl->setText(QCoreApplication::translate("MainWindow", "Connected to UFMS!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
