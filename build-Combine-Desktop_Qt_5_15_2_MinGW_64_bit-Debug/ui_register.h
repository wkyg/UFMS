/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QPushButton *btn_register_reg;
    QFrame *oframe3;
    QLabel *copyright;
    QFrame *oframe2;
    QFrame *oframe4;
    QFrame *oframe1;
    QLineEdit *lineEdit_username_reg;
    QLabel *label_Username;
    QLineEdit *lineEdit_password_reg;
    QLabel *label_Password;
    QLabel *label;
    QComboBox *seq_comboBox;
    QLabel *label_SEQues;
    QLabel *label_Username_2;
    QLineEdit *lineEdit_studid;
    QPushButton *btn_rback2login;
    QLabel *label_Answer;
    QLineEdit *lineEdit_seqanswer;
    QLabel *error_lbl;
    QLabel *db_lbl;
    QLabel *logo_lbl;
    QLabel *error_lbl_2;
    QLabel *error_lbl_3;
    QLabel *error_lbl_4;
    QLabel *error_lbl_5;
    QLabel *error_lbl_6;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Register->setWindowIcon(icon);
        btn_register_reg = new QPushButton(Register);
        btn_register_reg->setObjectName(QString::fromUtf8("btn_register_reg"));
        btn_register_reg->setGeometry(QRect(340, 406, 111, 51));
        QFont font;
        font.setPointSize(13);
        btn_register_reg->setFont(font);
        oframe3 = new QFrame(Register);
        oframe3->setObjectName(QString::fromUtf8("oframe3"));
        oframe3->setGeometry(QRect(780, 10, 20, 581));
        oframe3->setFrameShape(QFrame::VLine);
        oframe3->setFrameShadow(QFrame::Sunken);
        copyright = new QLabel(Register);
        copyright->setObjectName(QString::fromUtf8("copyright"));
        copyright->setGeometry(QRect(12, 570, 111, 16));
        oframe2 = new QFrame(Register);
        oframe2->setObjectName(QString::fromUtf8("oframe2"));
        oframe2->setGeometry(QRect(10, 0, 781, 16));
        oframe2->setFrameShape(QFrame::HLine);
        oframe2->setFrameShadow(QFrame::Sunken);
        oframe4 = new QFrame(Register);
        oframe4->setObjectName(QString::fromUtf8("oframe4"));
        oframe4->setGeometry(QRect(10, 580, 781, 20));
        oframe4->setFrameShape(QFrame::HLine);
        oframe4->setFrameShadow(QFrame::Sunken);
        oframe1 = new QFrame(Register);
        oframe1->setObjectName(QString::fromUtf8("oframe1"));
        oframe1->setGeometry(QRect(0, 10, 20, 581));
        oframe1->setFrameShape(QFrame::VLine);
        oframe1->setFrameShadow(QFrame::Sunken);
        lineEdit_username_reg = new QLineEdit(Register);
        lineEdit_username_reg->setObjectName(QString::fromUtf8("lineEdit_username_reg"));
        lineEdit_username_reg->setGeometry(QRect(330, 220, 211, 31));
        lineEdit_username_reg->setFont(font);
        lineEdit_username_reg->setMouseTracking(false);
        lineEdit_username_reg->setMaxLength(15);
        lineEdit_username_reg->setCursorMoveStyle(Qt::VisualMoveStyle);
        lineEdit_username_reg->setClearButtonEnabled(true);
        label_Username = new QLabel(Register);
        label_Username->setObjectName(QString::fromUtf8("label_Username"));
        label_Username->setGeometry(QRect(230, 224, 101, 20));
        label_Username->setFont(font);
        lineEdit_password_reg = new QLineEdit(Register);
        lineEdit_password_reg->setObjectName(QString::fromUtf8("lineEdit_password_reg"));
        lineEdit_password_reg->setEnabled(true);
        lineEdit_password_reg->setGeometry(QRect(330, 256, 211, 31));
        lineEdit_password_reg->setFont(font);
        lineEdit_password_reg->setMouseTracking(false);
        lineEdit_password_reg->setMaxLength(20);
        lineEdit_password_reg->setClearButtonEnabled(true);
        label_Password = new QLabel(Register);
        label_Password->setObjectName(QString::fromUtf8("label_Password"));
        label_Password->setGeometry(QRect(230, 258, 101, 27));
        label_Password->setFont(font);
        label = new QLabel(Register);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 85, 341, 51));
        QFont font1;
        font1.setPointSize(15);
        label->setFont(font1);
        seq_comboBox = new QComboBox(Register);
        seq_comboBox->addItem(QString());
        seq_comboBox->addItem(QString());
        seq_comboBox->addItem(QString());
        seq_comboBox->addItem(QString());
        seq_comboBox->addItem(QString());
        seq_comboBox->setObjectName(QString::fromUtf8("seq_comboBox"));
        seq_comboBox->setGeometry(QRect(330, 292, 211, 31));
        QFont font2;
        font2.setPointSize(11);
        seq_comboBox->setFont(font2);
        seq_comboBox->setCursor(QCursor(Qt::PointingHandCursor));
        label_SEQues = new QLabel(Register);
        label_SEQues->setObjectName(QString::fromUtf8("label_SEQues"));
        label_SEQues->setGeometry(QRect(154, 294, 181, 27));
        label_SEQues->setFont(font);
        label_Username_2 = new QLabel(Register);
        label_Username_2->setObjectName(QString::fromUtf8("label_Username_2"));
        label_Username_2->setGeometry(QRect(220, 186, 111, 20));
        label_Username_2->setFont(font);
        lineEdit_studid = new QLineEdit(Register);
        lineEdit_studid->setObjectName(QString::fromUtf8("lineEdit_studid"));
        lineEdit_studid->setGeometry(QRect(330, 184, 211, 31));
        lineEdit_studid->setFont(font);
        lineEdit_studid->setMouseTracking(false);
        lineEdit_studid->setAcceptDrops(true);
        lineEdit_studid->setMaxLength(10);
        lineEdit_studid->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_studid->setCursorMoveStyle(Qt::LogicalMoveStyle);
        lineEdit_studid->setClearButtonEnabled(true);
        btn_rback2login = new QPushButton(Register);
        btn_rback2login->setObjectName(QString::fromUtf8("btn_rback2login"));
        btn_rback2login->setGeometry(QRect(590, 20, 191, 51));
        btn_rback2login->setFont(font);
        label_Answer = new QLabel(Register);
        label_Answer->setObjectName(QString::fromUtf8("label_Answer"));
        label_Answer->setGeometry(QRect(252, 330, 81, 27));
        label_Answer->setFont(font);
        lineEdit_seqanswer = new QLineEdit(Register);
        lineEdit_seqanswer->setObjectName(QString::fromUtf8("lineEdit_seqanswer"));
        lineEdit_seqanswer->setEnabled(true);
        lineEdit_seqanswer->setGeometry(QRect(330, 328, 211, 31));
        lineEdit_seqanswer->setFont(font);
        lineEdit_seqanswer->setMouseTracking(false);
        lineEdit_seqanswer->setClearButtonEnabled(true);
        error_lbl = new QLabel(Register);
        error_lbl->setObjectName(QString::fromUtf8("error_lbl"));
        error_lbl->setGeometry(QRect(250, 370, 291, 20));
        QFont font3;
        font3.setPointSize(9);
        error_lbl->setFont(font3);
        error_lbl->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        error_lbl->setAlignment(Qt::AlignCenter);
        db_lbl = new QLabel(Register);
        db_lbl->setObjectName(QString::fromUtf8("db_lbl"));
        db_lbl->setGeometry(QRect(688, 570, 101, 16));
        logo_lbl = new QLabel(Register);
        logo_lbl->setObjectName(QString::fromUtf8("logo_lbl"));
        logo_lbl->setGeometry(QRect(20, 10, 341, 91));
        logo_lbl->setFont(font1);
        logo_lbl->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        logo_lbl->setScaledContents(true);
        logo_lbl->setAlignment(Qt::AlignCenter);
        error_lbl_2 = new QLabel(Register);
        error_lbl_2->setObjectName(QString::fromUtf8("error_lbl_2"));
        error_lbl_2->setGeometry(QRect(250, 370, 291, 20));
        error_lbl_2->setFont(font3);
        error_lbl_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        error_lbl_2->setAlignment(Qt::AlignCenter);
        error_lbl_3 = new QLabel(Register);
        error_lbl_3->setObjectName(QString::fromUtf8("error_lbl_3"));
        error_lbl_3->setGeometry(QRect(250, 370, 291, 20));
        error_lbl_3->setFont(font3);
        error_lbl_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        error_lbl_3->setAlignment(Qt::AlignCenter);
        error_lbl_4 = new QLabel(Register);
        error_lbl_4->setObjectName(QString::fromUtf8("error_lbl_4"));
        error_lbl_4->setGeometry(QRect(250, 370, 291, 20));
        error_lbl_4->setFont(font3);
        error_lbl_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        error_lbl_4->setAlignment(Qt::AlignCenter);
        error_lbl_5 = new QLabel(Register);
        error_lbl_5->setObjectName(QString::fromUtf8("error_lbl_5"));
        error_lbl_5->setGeometry(QRect(250, 370, 291, 20));
        error_lbl_5->setFont(font3);
        error_lbl_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        error_lbl_5->setAlignment(Qt::AlignCenter);
        error_lbl_6 = new QLabel(Register);
        error_lbl_6->setObjectName(QString::fromUtf8("error_lbl_6"));
        error_lbl_6->setGeometry(QRect(250, 370, 291, 20));
        error_lbl_6->setFont(font3);
        error_lbl_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        error_lbl_6->setAlignment(Qt::AlignCenter);
        QWidget::setTabOrder(lineEdit_studid, lineEdit_username_reg);
        QWidget::setTabOrder(lineEdit_username_reg, lineEdit_password_reg);
        QWidget::setTabOrder(lineEdit_password_reg, seq_comboBox);
        QWidget::setTabOrder(seq_comboBox, lineEdit_seqanswer);
        QWidget::setTabOrder(lineEdit_seqanswer, btn_register_reg);
        QWidget::setTabOrder(btn_register_reg, btn_rback2login);

        retranslateUi(Register);
        QObject::connect(lineEdit_studid, SIGNAL(returnPressed()), lineEdit_username_reg, SLOT(setFocus()));
        QObject::connect(lineEdit_username_reg, SIGNAL(returnPressed()), lineEdit_password_reg, SLOT(setFocus()));
        QObject::connect(lineEdit_password_reg, SIGNAL(returnPressed()), seq_comboBox, SLOT(setFocus()));
        QObject::connect(lineEdit_seqanswer, SIGNAL(returnPressed()), btn_register_reg, SLOT(click()));

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "University Faclilities Management System (UFMS)", nullptr));
        btn_register_reg->setText(QCoreApplication::translate("Register", "REGISTER", nullptr));
        copyright->setText(QCoreApplication::translate("Register", "\302\251 SLAUATRON 2019.", nullptr));
        label_Username->setText(QCoreApplication::translate("Register", "USERNAME:", nullptr));
        label_Password->setText(QCoreApplication::translate("Register", "PASSWORD:", nullptr));
        label->setText(QCoreApplication::translate("Register", "Create an account to access to UFMS", nullptr));
        seq_comboBox->setItemText(0, QCoreApplication::translate("Register", "What is your favorite color?", nullptr));
        seq_comboBox->setItemText(1, QCoreApplication::translate("Register", "Where is your primary school?", nullptr));
        seq_comboBox->setItemText(2, QCoreApplication::translate("Register", "What is your first pet's name?", nullptr));
        seq_comboBox->setItemText(3, QCoreApplication::translate("Register", "Who is your favorite author?", nullptr));
        seq_comboBox->setItemText(4, QCoreApplication::translate("Register", "What is your lucky number?", nullptr));

        label_SEQues->setText(QCoreApplication::translate("Register", "SECURITY QUESTION:", nullptr));
        label_Username_2->setText(QCoreApplication::translate("Register", "STUDENT ID:", nullptr));
        btn_rback2login->setText(QCoreApplication::translate("Register", "BACK TO LOGIN PAGE", nullptr));
        label_Answer->setText(QCoreApplication::translate("Register", "ANSWER:", nullptr));
        error_lbl->setText(QCoreApplication::translate("Register", "Username cannot be the same as password!", nullptr));
        db_lbl->setText(QCoreApplication::translate("Register", "Connected to UFMS!", nullptr));
        logo_lbl->setText(QString());
        error_lbl_2->setText(QCoreApplication::translate("Register", "Student ID or username cannot be empty!", nullptr));
        error_lbl_3->setText(QCoreApplication::translate("Register", "Username is already been taken!", nullptr));
        error_lbl_4->setText(QCoreApplication::translate("Register", "ID is already been taken!", nullptr));
        error_lbl_5->setText(QCoreApplication::translate("Register", "ID and Username is already been taken!", nullptr));
        error_lbl_6->setText(QCoreApplication::translate("Register", "User already existed!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
