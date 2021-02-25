/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QLabel *label_origin;
    QLabel *label_after;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_2;
    QPushButton *pushButton;
    QComboBox *cbox_filer;
    QLabel *label_3;
    QPushButton *pb_apply;
    QLabel *label_4;
    QComboBox *cbox_edge;
    QSlider *threshold;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 900);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(".QWidget{\n"
"	border-image:url(back_(1).png);\n"
"}"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(140, 170, 300, 300));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget{\n"
" background-color:rgb(216 ,232 , 251);\n"
" border-radius:15px;\n"
" color:rgb(0 ,45 , 115);\n"
"}"));
        label_origin = new QLabel(centralwidget);
        label_origin->setObjectName(QString::fromUtf8("label_origin"));
        label_origin->setGeometry(QRect(640, 190, 421, 311));
        label_origin->setStyleSheet(QString::fromUtf8("QLabel {\n"
" background-color:rgb(104 ,168 , 239);\n"
" border-radius:10px;\n"
"}"));
        label_origin->setFrameShape(QFrame::Box);
        label_after = new QLabel(centralwidget);
        label_after->setObjectName(QString::fromUtf8("label_after"));
        label_after->setGeometry(QRect(640, 550, 421, 311));
        label_after->setStyleSheet(QString::fromUtf8("QLabel {\n"
" background-color:rgb(104 ,168 , 239);\n"
" border-radius:10px;\n"
"}"));
        label_after->setFrameShape(QFrame::Box);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1040, 110, 121, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("PingFang SC Medium"));
        label->setFont(font);
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(290, 490, 151, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Taipei Sans TC Beta"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        spinBox->setFont(font1);
        spinBox->setStyleSheet(QString::fromUtf8("QSpinBox{\n"
" background-color:rgb(216 ,232 , 251);\n"
" border-radius:5px;\n"
" color:rgb(0 ,45 , 115);\n"
"}"));
        spinBox->setMinimum(3);
        spinBox->setSingleStep(2);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 500, 131, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Taipei Sans TC Beta"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        label_2->setAutoFillBackground(false);
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
" color:rgb(0 ,45 , 115);\n"
"\n"
"}"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 800, 291, 51));
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" background-color:rgb(216 ,232 , 251);\n"
" border-radius:15px;\n"
" color:rgb(0 ,45 , 115);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
""));
        cbox_filer = new QComboBox(centralwidget);
        cbox_filer->setObjectName(QString::fromUtf8("cbox_filer"));
        cbox_filer->setGeometry(QRect(290, 550, 151, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Taipei Sans TC Beta"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        cbox_filer->setFont(font3);
        cbox_filer->setStyleSheet(QString::fromUtf8("QComboBox{\n"
" background-color:rgb(216 ,232 , 251);\n"
" border-radius:5px;\n"
" color:rgb(0 ,45 , 115);\n"
"}"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(130, 560, 151, 41));
        label_3->setFont(font2);
        label_3->setAutoFillBackground(false);
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
" color:rgb(0 ,45 , 115);\n"
"\n"
"}"));
        pb_apply = new QPushButton(centralwidget);
        pb_apply->setObjectName(QString::fromUtf8("pb_apply"));
        pb_apply->setGeometry(QRect(140, 730, 291, 51));
        pb_apply->setFont(font2);
        pb_apply->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" background-color:rgb(216 ,232 , 251);\n"
" border-radius:15px;\n"
" color:rgb(0 ,45 , 115);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
""));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(130, 620, 151, 41));
        label_4->setFont(font2);
        label_4->setAutoFillBackground(false);
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
" color:rgb(0 ,45 , 115);\n"
"\n"
"}"));
        cbox_edge = new QComboBox(centralwidget);
        cbox_edge->setObjectName(QString::fromUtf8("cbox_edge"));
        cbox_edge->setGeometry(QRect(290, 610, 151, 51));
        cbox_edge->setFont(font3);
        cbox_edge->setStyleSheet(QString::fromUtf8("QComboBox{\n"
" background-color:rgb(216 ,232 , 251);\n"
" border-radius:5px;\n"
" color:rgb(0 ,45 , 115);\n"
"}"));
        threshold = new QSlider(centralwidget);
        threshold->setObjectName(QString::fromUtf8("threshold"));
        threshold->setGeometry(QRect(320, 680, 121, 20));
        threshold->setMaximum(255);
        threshold->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(130, 670, 181, 41));
        label_5->setFont(font2);
        label_5->setAutoFillBackground(false);
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
" color:rgb(0 ,45 , 115);\n"
"\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_origin->setText(QString());
        label_after->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "R08631007 HW3", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "filter size", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Load Image", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "select filter", nullptr));
        pb_apply->setText(QCoreApplication::translate("MainWindow", "Apply Filter", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "edge detect", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "zero_c thresh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
