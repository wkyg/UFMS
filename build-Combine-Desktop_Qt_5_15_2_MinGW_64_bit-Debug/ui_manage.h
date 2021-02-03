/********************************************************************************
** Form generated from reading UI file 'manage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGE_H
#define UI_MANAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Manage
{
public:
    QWidget *centralwidget;
    QFrame *oframe4;
    QLabel *copyright;
    QFrame *oframe2;
    QFrame *oframe1;
    QFrame *oframe3;
    QLabel *currentuser_lbl;
    QPushButton *btn_logout;
    QLabel *userLabel;
    QFrame *frameuser;
    QPushButton *btn_newbook;
    QPushButton *btn_viewbook;
    QFrame *frame1;
    QTableView *tableView;
    QListView *listView;
    QPushButton *btn_return;
    QFrame *line_2;
    QPushButton *btn_returnall;
    QLabel *label;
    QPushButton *btn_back;
    QFrame *line_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QFrame *frameadmin;
    QPushButton *btn_viewava;
    QPushButton *btn_viewbooked;
    QPushButton *btn_updatestatus;
    QFrame *frameupdatestatus;
    QTableView *tablestatus;
    QListView *listViewstatus;
    QLabel *label_5;
    QLabel *labelselectedstatus;
    QLabel *label_7;
    QPushButton *btn_update;
    QLabel *label_8;
    QFrame *line_4;
    QPushButton *btn_back_2;

    void setupUi(QMainWindow *Manage)
    {
        if (Manage->objectName().isEmpty())
            Manage->setObjectName(QString::fromUtf8("Manage"));
        Manage->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Manage->setWindowIcon(icon);
        centralwidget = new QWidget(Manage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        oframe4 = new QFrame(centralwidget);
        oframe4->setObjectName(QString::fromUtf8("oframe4"));
        oframe4->setGeometry(QRect(10, 580, 781, 20));
        oframe4->setFrameShape(QFrame::HLine);
        oframe4->setFrameShadow(QFrame::Sunken);
        copyright = new QLabel(centralwidget);
        copyright->setObjectName(QString::fromUtf8("copyright"));
        copyright->setGeometry(QRect(12, 570, 111, 16));
        oframe2 = new QFrame(centralwidget);
        oframe2->setObjectName(QString::fromUtf8("oframe2"));
        oframe2->setGeometry(QRect(10, 0, 781, 16));
        oframe2->setFrameShape(QFrame::HLine);
        oframe2->setFrameShadow(QFrame::Sunken);
        oframe1 = new QFrame(centralwidget);
        oframe1->setObjectName(QString::fromUtf8("oframe1"));
        oframe1->setGeometry(QRect(0, 10, 20, 581));
        oframe1->setFrameShape(QFrame::VLine);
        oframe1->setFrameShadow(QFrame::Sunken);
        oframe3 = new QFrame(centralwidget);
        oframe3->setObjectName(QString::fromUtf8("oframe3"));
        oframe3->setGeometry(QRect(780, 10, 20, 581));
        oframe3->setFrameShape(QFrame::VLine);
        oframe3->setFrameShadow(QFrame::Sunken);
        currentuser_lbl = new QLabel(centralwidget);
        currentuser_lbl->setObjectName(QString::fromUtf8("currentuser_lbl"));
        currentuser_lbl->setGeometry(QRect(100, 10, 81, 16));
        btn_logout = new QPushButton(centralwidget);
        btn_logout->setObjectName(QString::fromUtf8("btn_logout"));
        btn_logout->setGeometry(QRect(710, 10, 75, 23));
        btn_logout->setAutoDefault(false);
        btn_logout->setFlat(false);
        userLabel = new QLabel(centralwidget);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));
        userLabel->setGeometry(QRect(16, 10, 81, 16));
        frameuser = new QFrame(centralwidget);
        frameuser->setObjectName(QString::fromUtf8("frameuser"));
        frameuser->setGeometry(QRect(10, 30, 781, 541));
        frameuser->setFrameShape(QFrame::StyledPanel);
        frameuser->setFrameShadow(QFrame::Raised);
        btn_newbook = new QPushButton(frameuser);
        btn_newbook->setObjectName(QString::fromUtf8("btn_newbook"));
        btn_newbook->setGeometry(QRect(270, 150, 261, 71));
        QFont font;
        font.setPointSize(13);
        font.setBold(false);
        font.setWeight(50);
        btn_newbook->setFont(font);
        btn_newbook->setCursor(QCursor(Qt::PointingHandCursor));
        btn_viewbook = new QPushButton(frameuser);
        btn_viewbook->setObjectName(QString::fromUtf8("btn_viewbook"));
        btn_viewbook->setGeometry(QRect(270, 270, 261, 71));
        btn_viewbook->setFont(font);
        btn_viewbook->setCursor(QCursor(Qt::PointingHandCursor));
        frame1 = new QFrame(centralwidget);
        frame1->setObjectName(QString::fromUtf8("frame1"));
        frame1->setGeometry(QRect(10, 10, 781, 581));
        frame1->setFrameShape(QFrame::StyledPanel);
        frame1->setFrameShadow(QFrame::Raised);
        tableView = new QTableView(frame1);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 70, 761, 271));
        tableView->setSelectionMode(QAbstractItemView::NoSelection);
        tableView->horizontalHeader()->setMinimumSectionSize(120);
        tableView->horizontalHeader()->setDefaultSectionSize(120);
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->setVisible(false);
        listView = new QListView(frame1);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(10, 370, 561, 181));
        btn_return = new QPushButton(frame1);
        btn_return->setObjectName(QString::fromUtf8("btn_return"));
        btn_return->setGeometry(QRect(630, 440, 93, 41));
        line_2 = new QFrame(frame1);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 20, 781, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        btn_returnall = new QPushButton(frame1);
        btn_returnall->setObjectName(QString::fromUtf8("btn_returnall"));
        btn_returnall->setGeometry(QRect(630, 500, 93, 28));
        label = new QLabel(frame1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(590, 380, 151, 21));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        btn_back = new QPushButton(frame1);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(700, 0, 75, 23));
        line_3 = new QFrame(frame1);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(0, 340, 781, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(frame1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 131, 21));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        label_3 = new QLabel(frame1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(590, 400, 51, 21));
        label_3->setFont(font1);
        label_4 = new QLabel(frame1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(640, 400, 101, 21));
        label_4->setFont(font1);
        frameadmin = new QFrame(centralwidget);
        frameadmin->setObjectName(QString::fromUtf8("frameadmin"));
        frameadmin->setGeometry(QRect(10, 30, 781, 541));
        frameadmin->setFrameShape(QFrame::StyledPanel);
        frameadmin->setFrameShadow(QFrame::Raised);
        btn_viewava = new QPushButton(frameadmin);
        btn_viewava->setObjectName(QString::fromUtf8("btn_viewava"));
        btn_viewava->setGeometry(QRect(270, 140, 261, 71));
        btn_viewava->setFont(font);
        btn_viewava->setCursor(QCursor(Qt::PointingHandCursor));
        btn_viewbooked = new QPushButton(frameadmin);
        btn_viewbooked->setObjectName(QString::fromUtf8("btn_viewbooked"));
        btn_viewbooked->setGeometry(QRect(270, 240, 261, 71));
        btn_viewbooked->setFont(font);
        btn_viewbooked->setCursor(QCursor(Qt::PointingHandCursor));
        btn_updatestatus = new QPushButton(frameadmin);
        btn_updatestatus->setObjectName(QString::fromUtf8("btn_updatestatus"));
        btn_updatestatus->setGeometry(QRect(270, 340, 261, 71));
        btn_updatestatus->setFont(font);
        btn_updatestatus->setCursor(QCursor(Qt::PointingHandCursor));
        frameupdatestatus = new QFrame(centralwidget);
        frameupdatestatus->setObjectName(QString::fromUtf8("frameupdatestatus"));
        frameupdatestatus->setGeometry(QRect(10, 10, 781, 581));
        frameupdatestatus->setFrameShape(QFrame::StyledPanel);
        frameupdatestatus->setFrameShadow(QFrame::Raised);
        tablestatus = new QTableView(frameupdatestatus);
        tablestatus->setObjectName(QString::fromUtf8("tablestatus"));
        tablestatus->setGeometry(QRect(10, 70, 761, 271));
        tablestatus->horizontalHeader()->setStretchLastSection(true);
        listViewstatus = new QListView(frameupdatestatus);
        listViewstatus->setObjectName(QString::fromUtf8("listViewstatus"));
        listViewstatus->setGeometry(QRect(10, 371, 561, 181));
        listViewstatus->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        label_5 = new QLabel(frameupdatestatus);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 40, 131, 21));
        label_5->setFont(font2);
        labelselectedstatus = new QLabel(frameupdatestatus);
        labelselectedstatus->setObjectName(QString::fromUtf8("labelselectedstatus"));
        labelselectedstatus->setGeometry(QRect(640, 400, 101, 21));
        labelselectedstatus->setFont(font1);
        label_7 = new QLabel(frameupdatestatus);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(590, 380, 151, 21));
        label_7->setFont(font1);
        btn_update = new QPushButton(frameupdatestatus);
        btn_update->setObjectName(QString::fromUtf8("btn_update"));
        btn_update->setGeometry(QRect(630, 460, 93, 51));
        label_8 = new QLabel(frameupdatestatus);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(590, 400, 51, 21));
        label_8->setFont(font1);
        line_4 = new QFrame(frameupdatestatus);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(0, 340, 781, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        btn_back_2 = new QPushButton(frameupdatestatus);
        btn_back_2->setObjectName(QString::fromUtf8("btn_back_2"));
        btn_back_2->setGeometry(QRect(700, 0, 75, 23));
        Manage->setCentralWidget(centralwidget);
        oframe4->raise();
        copyright->raise();
        oframe2->raise();
        oframe1->raise();
        oframe3->raise();
        currentuser_lbl->raise();
        userLabel->raise();
        btn_logout->raise();
        frame1->raise();
        frameadmin->raise();
        frameuser->raise();
        frameupdatestatus->raise();

        retranslateUi(Manage);

        btn_logout->setDefault(false);


        QMetaObject::connectSlotsByName(Manage);
    } // setupUi

    void retranslateUi(QMainWindow *Manage)
    {
        Manage->setWindowTitle(QCoreApplication::translate("Manage", "University Facilities Management System (UFMS)", nullptr));
        copyright->setText(QCoreApplication::translate("Manage", "\302\251 SLAUATRON 2019.", nullptr));
        currentuser_lbl->setText(QCoreApplication::translate("Manage", "USERNAME", nullptr));
        btn_logout->setText(QCoreApplication::translate("Manage", "LOGOUT", nullptr));
        userLabel->setText(QCoreApplication::translate("Manage", "Current Session:", nullptr));
        btn_newbook->setText(QCoreApplication::translate("Manage", "MAKE A NEW BOOKING", nullptr));
        btn_viewbook->setText(QCoreApplication::translate("Manage", "MANAGE BOOKING(S)", nullptr));
        btn_return->setText(QCoreApplication::translate("Manage", "RETURN \n"
"SELECTION", nullptr));
        btn_returnall->setText(QCoreApplication::translate("Manage", "RETURN ALL", nullptr));
        label->setText(QCoreApplication::translate("Manage", "Double-Click the box on the left", nullptr));
        btn_back->setText(QCoreApplication::translate("Manage", "RETURN", nullptr));
        label_2->setText(QCoreApplication::translate("Manage", "BOOKING(S)", nullptr));
        label_3->setText(QCoreApplication::translate("Manage", "Selection: ", nullptr));
        label_4->setText(QString());
        btn_viewava->setText(QCoreApplication::translate("Manage", "VIEW AVAILABILITY", nullptr));
        btn_viewbooked->setText(QCoreApplication::translate("Manage", "VIEW ALL BOOKED \n"
"VENUE/FACILITIES", nullptr));
        btn_updatestatus->setText(QCoreApplication::translate("Manage", "UPDATE STATUS OF\n"
" VENUE/FACILITIES", nullptr));
        label_5->setText(QCoreApplication::translate("Manage", "BOOKING(S)", nullptr));
        labelselectedstatus->setText(QString());
        label_7->setText(QCoreApplication::translate("Manage", "Double-Click the box on the left", nullptr));
        btn_update->setText(QCoreApplication::translate("Manage", "APPROVE \n"
"REQUEST", nullptr));
        label_8->setText(QCoreApplication::translate("Manage", "Selection: ", nullptr));
        btn_back_2->setText(QCoreApplication::translate("Manage", "RETURN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Manage: public Ui_Manage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGE_H
