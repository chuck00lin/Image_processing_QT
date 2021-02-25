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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pb_show_origin;
    QPushButton *pb_grayscaleAB;
    QPushButton *pb_diff_AB;
    QPushButton *pb_binary;
    QPushButton *pb_equalization;
    QSlider *slider_brightness;
    QLabel *label_6;
    QSlider *slider_contrast;
    QLabel *label_7;
    QLabel *label_10;
    QLineEdit *lineEdit;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_11;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBox_3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *histo_1;
    QLabel *lb_chart_a;
    QLabel *lb_img_a;
    QLabel *lb_img_b;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *histo_2;
    QLabel *lb_char_b;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_3;
    QLabel *lb_oringimg;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1074, 747);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 310, 253, 371));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(verticalLayoutWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMinimumSize(QSize(251, 0));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -361, 232, 800));
        scrollAreaWidgetContents->setMinimumSize(QSize(200, 800));
        pb_show_origin = new QPushButton(scrollAreaWidgetContents);
        pb_show_origin->setObjectName(QString::fromUtf8("pb_show_origin"));
        pb_show_origin->setGeometry(QRect(10, 20, 211, 51));
        pb_grayscaleAB = new QPushButton(scrollAreaWidgetContents);
        pb_grayscaleAB->setObjectName(QString::fromUtf8("pb_grayscaleAB"));
        pb_grayscaleAB->setGeometry(QRect(10, 410, 211, 51));
        pb_diff_AB = new QPushButton(scrollAreaWidgetContents);
        pb_diff_AB->setObjectName(QString::fromUtf8("pb_diff_AB"));
        pb_diff_AB->setGeometry(QRect(10, 470, 211, 51));
        pb_binary = new QPushButton(scrollAreaWidgetContents);
        pb_binary->setObjectName(QString::fromUtf8("pb_binary"));
        pb_binary->setGeometry(QRect(100, 530, 121, 51));
        pb_equalization = new QPushButton(scrollAreaWidgetContents);
        pb_equalization->setObjectName(QString::fromUtf8("pb_equalization"));
        pb_equalization->setGeometry(QRect(10, 80, 211, 51));
        slider_brightness = new QSlider(scrollAreaWidgetContents);
        slider_brightness->setObjectName(QString::fromUtf8("slider_brightness"));
        slider_brightness->setGeometry(QRect(30, 190, 160, 18));
        slider_brightness->setSliderPosition(50);
        slider_brightness->setOrientation(Qt::Horizontal);
        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(60, 210, 101, 41));
        label_6->setAlignment(Qt::AlignCenter);
        slider_contrast = new QSlider(scrollAreaWidgetContents);
        slider_contrast->setObjectName(QString::fromUtf8("slider_contrast"));
        slider_contrast->setGeometry(QRect(30, 250, 160, 18));
        slider_contrast->setSliderPosition(50);
        slider_contrast->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(60, 150, 101, 41));
        label_7->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(120, 280, 101, 41));
        label_10->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(scrollAreaWidgetContents);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(12, 533, 81, 31));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 570, 58, 15));
        doubleSpinBox = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(30, 290, 91, 31));
        doubleSpinBox->setMinimum(1.000000000000000);
        doubleSpinBox->setMaximum(10.000000000000000);
        doubleSpinBox->setSingleStep(0.100000000000000);
        doubleSpinBox_2 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(30, 340, 91, 31));
        doubleSpinBox_2->setDecimals(1);
        doubleSpinBox_2->setMinimum(0.100000000000000);
        doubleSpinBox_2->setMaximum(1.000000000000000);
        doubleSpinBox_2->setSingleStep(0.100000000000000);
        doubleSpinBox_2->setStepType(QAbstractSpinBox::DefaultStepType);
        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(120, 330, 101, 41));
        label_11->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(110, 590, 101, 41));
        label_12->setAlignment(Qt::AlignCenter);
        doubleSpinBox_3 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(20, 600, 91, 31));
        doubleSpinBox_3->setMinimum(2.000000000000000);
        doubleSpinBox_3->setMaximum(256.000000000000000);
        doubleSpinBox_3->setSingleStep(2.000000000000000);
        doubleSpinBox_3->setValue(4.000000000000000);
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(300, 440, 351, 241));
        histo_1 = new QHBoxLayout(horizontalLayoutWidget);
        histo_1->setObjectName(QString::fromUtf8("histo_1"));
        histo_1->setContentsMargins(0, 0, 0, 0);
        lb_chart_a = new QLabel(horizontalLayoutWidget);
        lb_chart_a->setObjectName(QString::fromUtf8("lb_chart_a"));
        lb_chart_a->setAlignment(Qt::AlignCenter);

        histo_1->addWidget(lb_chart_a);

        lb_img_a = new QLabel(centralwidget);
        lb_img_a->setObjectName(QString::fromUtf8("lb_img_a"));
        lb_img_a->setGeometry(QRect(300, 70, 351, 351));
        lb_img_a->setFrameShape(QFrame::WinPanel);
        lb_img_b = new QLabel(centralwidget);
        lb_img_b->setObjectName(QString::fromUtf8("lb_img_b"));
        lb_img_b->setGeometry(QRect(680, 70, 351, 351));
        lb_img_b->setFrameShape(QFrame::WinPanel);
        lb_img_b->setFrameShadow(QFrame::Plain);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(310, 30, 101, 41));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(690, 30, 101, 41));
        label_5->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(680, 440, 351, 241));
        histo_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        histo_2->setObjectName(QString::fromUtf8("histo_2"));
        histo_2->setContentsMargins(0, 0, 0, 0);
        lb_char_b = new QLabel(horizontalLayoutWidget_2);
        lb_char_b->setObjectName(QString::fromUtf8("lb_char_b"));
        lb_char_b->setAlignment(Qt::AlignCenter);

        histo_2->addWidget(lb_char_b);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(20, 60, 251, 242));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea_2 = new QScrollArea(verticalLayoutWidget_2);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setMinimumSize(QSize(240, 240));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 300, 300));
        scrollAreaWidgetContents_3->setMinimumSize(QSize(300, 300));
        lb_oringimg = new QLabel(scrollAreaWidgetContents_3);
        lb_oringimg->setObjectName(QString::fromUtf8("lb_oringimg"));
        lb_oringimg->setGeometry(QRect(0, 0, 221, 221));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lb_oringimg->sizePolicy().hasHeightForWidth());
        lb_oringimg->setSizePolicy(sizePolicy);
        lb_oringimg->setAutoFillBackground(false);
        lb_oringimg->setFrameShape(QFrame::StyledPanel);
        scrollArea_2->setWidget(scrollAreaWidgetContents_3);

        verticalLayout_2->addWidget(scrollArea_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1074, 24));
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
        pb_show_origin->setText(QCoreApplication::translate("MainWindow", "Show Origin ", nullptr));
        pb_grayscaleAB->setText(QCoreApplication::translate("MainWindow", "Gray Scale A/B", nullptr));
        pb_diff_AB->setText(QCoreApplication::translate("MainWindow", "Difference Between A/B ", nullptr));
        pb_binary->setText(QCoreApplication::translate("MainWindow", "Binary Thresh", nullptr));
        pb_equalization->setText(QCoreApplication::translate("MainWindow", "Historgram Equalization", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Brightness", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Contrast", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Enlarge", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "0-255", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Shrink", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Graylevel", nullptr));
        lb_chart_a->setText(QString());
        lb_img_a->setText(QString());
        lb_img_b->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Gray Scale : A", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Gray Scale : B", nullptr));
        lb_char_b->setText(QString());
        lb_oringimg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
