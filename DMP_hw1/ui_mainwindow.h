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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionopen_image;
    QAction *actionopen_image_2;
    QWidget *centralwidget;
    QLabel *label_showimage;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *histo;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_showsecond;
    QLabel *label_3;
    QPushButton *pb_add;
    QLineEdit *lineEdit;
    QPushButton *pb_sub;
    QPushButton *pb_multi;
    QPushButton *pb_avg;
    QPushButton *pb_func;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *histo_2;
    QLabel *label_4;
    QMenuBar *menubar;
    QMenu *menuhwq;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1012, 805);
        actionopen_image = new QAction(MainWindow);
        actionopen_image->setObjectName(QString::fromUtf8("actionopen_image"));
        actionopen_image_2 = new QAction(MainWindow);
        actionopen_image_2->setObjectName(QString::fromUtf8("actionopen_image_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_showimage = new QLabel(centralwidget);
        label_showimage->setObjectName(QString::fromUtf8("label_showimage"));
        label_showimage->setGeometry(QRect(10, 60, 241, 241));
        label_showimage->setFrameShape(QFrame::Box);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(260, 50, 691, 271));
        histo = new QHBoxLayout(horizontalLayoutWidget);
        histo->setObjectName(QString::fromUtf8("histo"));
        histo->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAutoFillBackground(true);
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Plain);

        histo->addWidget(label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 10, 131, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Rounded MT Bold"));
        font.setPointSize(12);
        label_2->setFont(font);
        label_showsecond = new QLabel(centralwidget);
        label_showsecond->setObjectName(QString::fromUtf8("label_showsecond"));
        label_showsecond->setGeometry(QRect(10, 360, 241, 241));
        label_showsecond->setFrameShape(QFrame::Box);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 310, 131, 31));
        label_3->setFont(font);
        pb_add = new QPushButton(centralwidget);
        pb_add->setObjectName(QString::fromUtf8("pb_add"));
        pb_add->setGeometry(QRect(280, 640, 121, 71));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 640, 241, 71));
        pb_sub = new QPushButton(centralwidget);
        pb_sub->setObjectName(QString::fromUtf8("pb_sub"));
        pb_sub->setGeometry(QRect(410, 640, 121, 71));
        pb_multi = new QPushButton(centralwidget);
        pb_multi->setObjectName(QString::fromUtf8("pb_multi"));
        pb_multi->setGeometry(QRect(540, 640, 121, 71));
        pb_avg = new QPushButton(centralwidget);
        pb_avg->setObjectName(QString::fromUtf8("pb_avg"));
        pb_avg->setGeometry(QRect(670, 640, 121, 71));
        pb_func = new QPushButton(centralwidget);
        pb_func->setObjectName(QString::fromUtf8("pb_func"));
        pb_func->setGeometry(QRect(800, 640, 121, 71));
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(260, 350, 691, 271));
        histo_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        histo_2->setObjectName(QString::fromUtf8("histo_2"));
        histo_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAutoFillBackground(true);
        label_4->setFrameShape(QFrame::NoFrame);

        histo_2->addWidget(label_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1012, 24));
        menuhwq = new QMenu(menubar);
        menuhwq->setObjectName(QString::fromUtf8("menuhwq"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuhwq->menuAction());
        menuhwq->addAction(actionopen_image_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionopen_image->setText(QCoreApplication::translate("MainWindow", "open image", nullptr));
        actionopen_image_2->setText(QCoreApplication::translate("MainWindow", "open image", nullptr));
        label_showimage->setText(QString());
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Input Image", nullptr));
        label_showsecond->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Output Image", nullptr));
        pb_add->setText(QCoreApplication::translate("MainWindow", "ADD", nullptr));
        pb_sub->setText(QCoreApplication::translate("MainWindow", "SUB", nullptr));
        pb_multi->setText(QCoreApplication::translate("MainWindow", "MULTIPLE", nullptr));
        pb_avg->setText(QCoreApplication::translate("MainWindow", "AVG", nullptr));
        pb_func->setText(QCoreApplication::translate("MainWindow", "f(x,y)-f(x-1,y)", nullptr));
        label_4->setText(QString());
        menuhwq->setTitle(QCoreApplication::translate("MainWindow", "file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
