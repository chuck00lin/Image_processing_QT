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
    QPushButton *pb_RGB;
    QPushButton *pb_HSI;
    QPushButton *pb_XYZ;
    QPushButton *pb_YUV;
    QPushButton *pb_Lab;
    QPushButton *pb_Hot;
    QPushButton *pb_Rainbow;
    QLabel *label_11;
    QLabel *label_20;
    QPushButton *pb_applykmeans;
    QPushButton *pb_CMY;
    QLabel *label_22;
    QSlider *horizontalSlider_Kmean;
    QPushButton *pb_Winter;
    QPushButton *pb_Autumn;
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
        gridLayoutWidget_2->setGeometry(QRect(40, 230, 321, 461));
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
        scrollAreaWidgetContents->setGeometry(QRect(0, -407, 302, 1000));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        scrollAreaWidgetContents->setMinimumSize(QSize(200, 1000));
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
        pb_RGB = new QPushButton(scrollAreaWidgetContents);
        pb_RGB->setObjectName(QString::fromUtf8("pb_RGB"));
        pb_RGB->setGeometry(QRect(10, 50, 281, 31));
        pb_RGB->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:rgb(255,255,255);\n"
"}"));
        pb_HSI = new QPushButton(scrollAreaWidgetContents);
        pb_HSI->setObjectName(QString::fromUtf8("pb_HSI"));
        pb_HSI->setGeometry(QRect(10, 130, 281, 31));
        pb_HSI->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:rgb(255,255,255);\n"
"}"));
        pb_XYZ = new QPushButton(scrollAreaWidgetContents);
        pb_XYZ->setObjectName(QString::fromUtf8("pb_XYZ"));
        pb_XYZ->setGeometry(QRect(10, 170, 281, 31));
        pb_XYZ->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:rgb(255,255,255);\n"
"}"));
        pb_YUV = new QPushButton(scrollAreaWidgetContents);
        pb_YUV->setObjectName(QString::fromUtf8("pb_YUV"));
        pb_YUV->setGeometry(QRect(10, 250, 281, 31));
        pb_YUV->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:rgb(255,255,255);\n"
"}"));
        pb_Lab = new QPushButton(scrollAreaWidgetContents);
        pb_Lab->setObjectName(QString::fromUtf8("pb_Lab"));
        pb_Lab->setGeometry(QRect(10, 210, 281, 31));
        pb_Lab->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:rgb(255,255,255);\n"
"}"));
        pb_Hot = new QPushButton(scrollAreaWidgetContents);
        pb_Hot->setObjectName(QString::fromUtf8("pb_Hot"));
        pb_Hot->setGeometry(QRect(10, 380, 281, 31));
        pb_Hot->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:rgb(255,255,255);\n"
"}"));
        pb_Rainbow = new QPushButton(scrollAreaWidgetContents);
        pb_Rainbow->setObjectName(QString::fromUtf8("pb_Rainbow"));
        pb_Rainbow->setGeometry(QRect(10, 340, 281, 31));
        pb_Rainbow->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:rgb(255,255,255);\n"
"}"));
        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(0, 290, 301, 41));
        label_11->setStyleSheet(QString::fromUtf8("QLabel {\n"
" background-color:rgb(48 ,48 , 48);\n"
" color:rgb(255 ,255 ,255);\n"
"}"));
        label_11->setFrameShape(QFrame::NoFrame);
        label_20 = new QLabel(scrollAreaWidgetContents);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(0, 500, 301, 41));
        label_20->setStyleSheet(QString::fromUtf8("QLabel {\n"
" background-color:rgb(48 ,48 , 48);\n"
" color:rgb(255 ,255 ,255);\n"
"}"));
        label_20->setFrameShape(QFrame::NoFrame);
        pb_applykmeans = new QPushButton(scrollAreaWidgetContents);
        pb_applykmeans->setObjectName(QString::fromUtf8("pb_applykmeans"));
        pb_applykmeans->setGeometry(QRect(10, 600, 281, 31));
        pb_applykmeans->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:rgb(255,255,255);\n"
"}"));
        pb_CMY = new QPushButton(scrollAreaWidgetContents);
        pb_CMY->setObjectName(QString::fromUtf8("pb_CMY"));
        pb_CMY->setGeometry(QRect(10, 90, 281, 31));
        pb_CMY->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:rgb(255,255,255);\n"
"}"));
        label_22 = new QLabel(scrollAreaWidgetContents);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(70, 560, 171, 20));
        label_22->setStyleSheet(QString::fromUtf8("QLabel {\n"
" color:rgb(255 ,255 ,255);\n"
"}"));
        label_22->setAlignment(Qt::AlignCenter);
        horizontalSlider_Kmean = new QSlider(scrollAreaWidgetContents);
        horizontalSlider_Kmean->setObjectName(QString::fromUtf8("horizontalSlider_Kmean"));
        horizontalSlider_Kmean->setGeometry(QRect(10, 580, 281, 18));
        horizontalSlider_Kmean->setMinimum(2);
        horizontalSlider_Kmean->setMaximum(30);
        horizontalSlider_Kmean->setSingleStep(2);
        horizontalSlider_Kmean->setPageStep(2);
        horizontalSlider_Kmean->setOrientation(Qt::Horizontal);
        pb_Winter = new QPushButton(scrollAreaWidgetContents);
        pb_Winter->setObjectName(QString::fromUtf8("pb_Winter"));
        pb_Winter->setGeometry(QRect(10, 420, 281, 31));
        pb_Winter->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:rgb(255,255,255);\n"
"}"));
        pb_Autumn = new QPushButton(scrollAreaWidgetContents);
        pb_Autumn->setObjectName(QString::fromUtf8("pb_Autumn"));
        pb_Autumn->setGeometry(QRect(10, 460, 281, 31));
        pb_Autumn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:rgb(255,255,255);\n"
"}"));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);

        label_origin = new QLabel(centralwidget);
        label_origin->setObjectName(QString::fromUtf8("label_origin"));
        label_origin->setGeometry(QRect(40, 40, 321, 181));
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
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_import->setText(QCoreApplication::translate("MainWindow", "import", nullptr));
#if QT_CONFIG(shortcut)
        action_import->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        label_show_A1->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "  Color Mode Convert", nullptr));
        pb_RGB->setText(QCoreApplication::translate("MainWindow", "RGB", nullptr));
        pb_HSI->setText(QCoreApplication::translate("MainWindow", "HSI", nullptr));
        pb_XYZ->setText(QCoreApplication::translate("MainWindow", "XYZ", nullptr));
        pb_YUV->setText(QCoreApplication::translate("MainWindow", "YUV", nullptr));
        pb_Lab->setText(QCoreApplication::translate("MainWindow", "Lab", nullptr));
        pb_Hot->setText(QCoreApplication::translate("MainWindow", "Hot", nullptr));
        pb_Rainbow->setText(QCoreApplication::translate("MainWindow", "Rainbow", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "  Pseudo Color", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", " K-means", nullptr));
        pb_applykmeans->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        pb_CMY->setText(QCoreApplication::translate("MainWindow", "CMY", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "K-means Cluster Num (2-30)", nullptr));
        pb_Winter->setText(QCoreApplication::translate("MainWindow", "Winter", nullptr));
        pb_Autumn->setText(QCoreApplication::translate("MainWindow", "Autumn", nullptr));
        label_origin->setText(QString());
        label_A->setText(QString());
        label_B->setText(QString());
        label_show_B1->setText(QString());
        file->setTitle(QCoreApplication::translate("MainWindow", "file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
