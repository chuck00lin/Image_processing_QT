/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_import;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_show_A1;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_5;
    QPushButton *pb_trapezoidal;
    QPushButton *pb_Circular;
    QPushButton *pb_Wavelet;
    QLabel *label_11;
    QLabel *label_20;
    QPushButton *pb_applykmeans;
    QPushButton *pb_wavy;
    QLabel *label_22;
    QSlider *horizontalSlider_A;
    QSlider *horizontalSlider_F;
    QLabel *label_23;
    QLabel *label_origin;
    QLabel *label_A;
    QLabel *label_B;
    QLabel *label_show_B1;
    QMenuBar *menubar;
    QMenu *file;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1078, 750);
        action_import = new QAction(MainWindow);
        action_import->setObjectName(QString::fromUtf8("action_import"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(".QWidget{\n"
"	 background-color:rgb(84 ,84 , 84);\n"
"}"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(390, 80, 631, 461));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_show_A1 = new QLabel(gridLayoutWidget);
        label_show_A1->setObjectName(QString::fromUtf8("label_show_A1"));
        label_show_A1->setFrameShape(QFrame::Box);

        gridLayout->addWidget(label_show_A1, 2, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(40, 290, 321, 401));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(gridLayoutWidget_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMinimumSize(QSize(200, 200));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea{\\n background-color:rgb(84 ,84 , 84);}"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Sunken);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setEnabled(true);
        scrollAreaWidgetContents->setGeometry(QRect(0, -110, 302, 509));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        scrollAreaWidgetContents->setMinimumSize(QSize(200, 509));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
" background-color:rgb(84 ,84 , 84);\n"
"}"));
        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 0, 301, 41));
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
" background-color:rgb(48 ,48 , 48);\n"
" color:rgb(255 ,255 ,255);\n"
"}"));
        label_5->setFrameShape(QFrame::NoFrame);
        pb_trapezoidal = new QPushButton(scrollAreaWidgetContents);
        pb_trapezoidal->setObjectName(QString::fromUtf8("pb_trapezoidal"));
        pb_trapezoidal->setGeometry(QRect(10, 50, 281, 31));
        pb_trapezoidal->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:rgb(255,255,255);\n"
"}"));
        pb_Circular = new QPushButton(scrollAreaWidgetContents);
        pb_Circular->setObjectName(QString::fromUtf8("pb_Circular"));
        pb_Circular->setGeometry(QRect(10, 240, 281, 31));
        pb_Circular->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:rgb(255,255,255);\n"
"}"));
        pb_Wavelet = new QPushButton(scrollAreaWidgetContents);
        pb_Wavelet->setObjectName(QString::fromUtf8("pb_Wavelet"));
        pb_Wavelet->setGeometry(QRect(10, 330, 281, 31));
        pb_Wavelet->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:rgb(255,255,255);\n"
"}"));
        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(0, 280, 301, 41));
        label_11->setStyleSheet(QString::fromUtf8("QLabel {\n"
" background-color:rgb(48 ,48 , 48);\n"
" color:rgb(255 ,255 ,255);\n"
"}"));
        label_11->setFrameShape(QFrame::NoFrame);
        label_20 = new QLabel(scrollAreaWidgetContents);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(0, 380, 301, 41));
        label_20->setStyleSheet(QString::fromUtf8("QLabel {\n"
" background-color:rgb(48 ,48 , 48);\n"
" color:rgb(255 ,255 ,255);\n"
"}"));
        label_20->setFrameShape(QFrame::NoFrame);
        pb_applykmeans = new QPushButton(scrollAreaWidgetContents);
        pb_applykmeans->setObjectName(QString::fromUtf8("pb_applykmeans"));
        pb_applykmeans->setGeometry(QRect(10, 430, 281, 31));
        pb_applykmeans->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:rgb(255,255,255);\n"
"}"));
        pb_wavy = new QPushButton(scrollAreaWidgetContents);
        pb_wavy->setObjectName(QString::fromUtf8("pb_wavy"));
        pb_wavy->setGeometry(QRect(10, 190, 281, 31));
        pb_wavy->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:rgb(255,255,255);\n"
"}"));
        label_22 = new QLabel(scrollAreaWidgetContents);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(70, 90, 171, 20));
        label_22->setStyleSheet(QString::fromUtf8("QLabel {\n"
" color:rgb(255 ,255 ,255);\n"
"}"));
        label_22->setAlignment(Qt::AlignCenter);
        horizontalSlider_A = new QSlider(scrollAreaWidgetContents);
        horizontalSlider_A->setObjectName(QString::fromUtf8("horizontalSlider_A"));
        horizontalSlider_A->setGeometry(QRect(10, 110, 281, 18));
        horizontalSlider_A->setMinimum(2);
        horizontalSlider_A->setMaximum(100);
        horizontalSlider_A->setSingleStep(2);
        horizontalSlider_A->setPageStep(2);
        horizontalSlider_A->setOrientation(Qt::Horizontal);
        horizontalSlider_F = new QSlider(scrollAreaWidgetContents);
        horizontalSlider_F->setObjectName(QString::fromUtf8("horizontalSlider_F"));
        horizontalSlider_F->setGeometry(QRect(10, 150, 281, 18));
        horizontalSlider_F->setMinimum(30);
        horizontalSlider_F->setMaximum(300);
        horizontalSlider_F->setSingleStep(20);
        horizontalSlider_F->setPageStep(20);
        horizontalSlider_F->setValue(30);
        horizontalSlider_F->setOrientation(Qt::Horizontal);
        label_23 = new QLabel(scrollAreaWidgetContents);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(70, 130, 171, 20));
        label_23->setStyleSheet(QString::fromUtf8("QLabel {\n"
" color:rgb(255 ,255 ,255);\n"
"}"));
        label_23->setAlignment(Qt::AlignCenter);
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);

        label_origin = new QLabel(centralwidget);
        label_origin->setObjectName(QString::fromUtf8("label_origin"));
        label_origin->setGeometry(QRect(40, 40, 321, 231));
        label_origin->setFrameShape(QFrame::Box);
        label_A = new QLabel(centralwidget);
        label_A->setObjectName(QString::fromUtf8("label_A"));
        label_A->setGeometry(QRect(390, 40, 631, 31));
        label_A->setStyleSheet(QString::fromUtf8("QLabel {\n"
" background-color:rgb(48 ,48 , 48);\n"
" color:rgb(255 ,255 ,255);\n"
"}"));
        label_B = new QLabel(centralwidget);
        label_B->setObjectName(QString::fromUtf8("label_B"));
        label_B->setGeometry(QRect(390, 560, 631, 31));
        label_B->setStyleSheet(QString::fromUtf8("QLabel {\n"
" background-color:rgb(48 ,48 , 48);\n"
" color:rgb(255 ,255 ,255);\n"
"}"));
        label_show_B1 = new QLabel(centralwidget);
        label_show_B1->setObjectName(QString::fromUtf8("label_show_B1"));
        label_show_B1->setGeometry(QRect(390, 600, 631, 81));
        label_show_B1->setFrameShape(QFrame::Box);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1078, 24));
        menubar->setStyleSheet(QString::fromUtf8("QMenuBar\n"
"{\n"
"	 background-color:rgb(34 ,34 , 34);\n"
"color:rgb(255,255,255);\n"
"}"));
        file = new QMenu(menubar);
        file->setObjectName(QString::fromUtf8("file"));
        file->setStyleSheet(QString::fromUtf8("QMenu{\n"
"\n"
"}"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(file->menuAction());
        file->addAction(action_import);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action_import->setText(QApplication::translate("MainWindow", "import", nullptr));
#ifndef QT_NO_SHORTCUT
        action_import->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        label_show_A1->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Geometric Transformation", nullptr));
        pb_trapezoidal->setText(QApplication::translate("MainWindow", "Trapezoidal Transformation", nullptr));
        pb_Circular->setText(QApplication::translate("MainWindow", "Circular Transformation", nullptr));
        pb_Wavelet->setText(QApplication::translate("MainWindow", "Wavelet transform", nullptr));
        label_11->setText(QApplication::translate("MainWindow", " Image Fusion Using Wavelet Transform", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "Hough Transform", nullptr));
        pb_applykmeans->setText(QApplication::translate("MainWindow", " Hough transform", nullptr));
        pb_wavy->setText(QApplication::translate("MainWindow", "Wavy Transformation", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "amplitude", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "freqency", nullptr));
        label_origin->setText(QString());
        label_A->setText(QString());
        label_B->setText(QString());
        label_show_B1->setText(QString());
        file->setTitle(QApplication::translate("MainWindow", "file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
