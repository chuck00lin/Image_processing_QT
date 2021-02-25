# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'TEST.ui'
#
# Created by: PyQt5 UI code generator 5.13.2
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(1200, 900)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setStyleSheet(".QWidget{\n"
"    border-image:url(back_(1).png);\n"
"}")
        self.centralwidget.setObjectName("centralwidget")
        self.tableWidget = QtWidgets.QTableWidget(self.centralwidget)
        self.tableWidget.setGeometry(QtCore.QRect(140, 170, 300, 300))
        self.tableWidget.setStyleSheet("QTableWidget{\n"
" background-color:rgb(216 ,232 , 251);\n"
" border-radius:15px;\n"
" color:rgb(0 ,45 , 115);\n"
"}")
        self.tableWidget.setObjectName("tableWidget")
        self.tableWidget.setColumnCount(0)
        self.tableWidget.setRowCount(0)
        self.label_origin = QtWidgets.QLabel(self.centralwidget)
        self.label_origin.setGeometry(QtCore.QRect(640, 190, 421, 311))
        self.label_origin.setStyleSheet("QLabel {\n"
" background-color:rgb(104 ,168 , 239);\n"
" border-radius:10px;\n"
"}")
        self.label_origin.setFrameShape(QtWidgets.QFrame.Box)
        self.label_origin.setText("")
        self.label_origin.setObjectName("label_origin")
        self.label_after = QtWidgets.QLabel(self.centralwidget)
        self.label_after.setGeometry(QtCore.QRect(640, 550, 421, 311))
        self.label_after.setStyleSheet("QLabel {\n"
" background-color:rgb(104 ,168 , 239);\n"
" border-radius:10px;\n"
"}")
        self.label_after.setFrameShape(QtWidgets.QFrame.Box)
        self.label_after.setText("")
        self.label_after.setObjectName("label_after")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(1040, 110, 121, 41))
        font = QtGui.QFont()
        font.setFamily("PingFang SC Medium")
        self.label.setFont(font)
        self.label.setObjectName("label")
        self.spinBox = QtWidgets.QSpinBox(self.centralwidget)
        self.spinBox.setGeometry(QtCore.QRect(290, 490, 151, 51))
        font = QtGui.QFont()
        font.setFamily("Taipei Sans TC Beta")
        font.setPointSize(14)
        font.setBold(True)
        font.setWeight(75)
        self.spinBox.setFont(font)
        self.spinBox.setStyleSheet("QSpinBox{\n"
" background-color:rgb(216 ,232 , 251);\n"
" border-radius:5px;\n"
" color:rgb(0 ,45 , 115);\n"
"}")
        self.spinBox.setMinimum(3)
        self.spinBox.setSingleStep(2)
        self.spinBox.setObjectName("spinBox")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(130, 500, 131, 41))
        font = QtGui.QFont()
        font.setFamily("Taipei Sans TC Beta")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label_2.setFont(font)
        self.label_2.setAutoFillBackground(False)
        self.label_2.setStyleSheet("QLabel {\n"
" color:rgb(0 ,45 , 115);\n"
"\n"
"}")
        self.label_2.setObjectName("label_2")
        self.pushButton = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton.setGeometry(QtCore.QRect(140, 800, 291, 51))
        font = QtGui.QFont()
        font.setFamily("Taipei Sans TC Beta")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.pushButton.setFont(font)
        self.pushButton.setStyleSheet("QPushButton{\n"
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
"")
        self.pushButton.setObjectName("pushButton")
        self.cbox_filer = QtWidgets.QComboBox(self.centralwidget)
        self.cbox_filer.setGeometry(QtCore.QRect(290, 550, 151, 51))
        font = QtGui.QFont()
        font.setFamily("Taipei Sans TC Beta")
        font.setPointSize(12)
        font.setBold(True)
        font.setWeight(75)
        self.cbox_filer.setFont(font)
        self.cbox_filer.setStyleSheet("QComboBox{\n"
" background-color:rgb(216 ,232 , 251);\n"
" border-radius:5px;\n"
" color:rgb(0 ,45 , 115);\n"
"}")
        self.cbox_filer.setObjectName("cbox_filer")
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setGeometry(QtCore.QRect(130, 560, 151, 41))
        font = QtGui.QFont()
        font.setFamily("Taipei Sans TC Beta")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label_3.setFont(font)
        self.label_3.setAutoFillBackground(False)
        self.label_3.setStyleSheet("QLabel {\n"
" color:rgb(0 ,45 , 115);\n"
"\n"
"}")
        self.label_3.setObjectName("label_3")
        self.pb_apply = QtWidgets.QPushButton(self.centralwidget)
        self.pb_apply.setGeometry(QtCore.QRect(140, 730, 291, 51))
        font = QtGui.QFont()
        font.setFamily("Taipei Sans TC Beta")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.pb_apply.setFont(font)
        self.pb_apply.setStyleSheet("QPushButton{\n"
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
"")
        self.pb_apply.setObjectName("pb_apply")
        self.label_4 = QtWidgets.QLabel(self.centralwidget)
        self.label_4.setGeometry(QtCore.QRect(130, 620, 151, 41))
        font = QtGui.QFont()
        font.setFamily("Taipei Sans TC Beta")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label_4.setFont(font)
        self.label_4.setAutoFillBackground(False)
        self.label_4.setStyleSheet("QLabel {\n"
" color:rgb(0 ,45 , 115);\n"
"\n"
"}")
        self.label_4.setObjectName("label_4")
        self.cbox_edge = QtWidgets.QComboBox(self.centralwidget)
        self.cbox_edge.setGeometry(QtCore.QRect(290, 610, 151, 51))
        font = QtGui.QFont()
        font.setFamily("Taipei Sans TC Beta")
        font.setPointSize(12)
        font.setBold(True)
        font.setWeight(75)
        self.cbox_edge.setFont(font)
        self.cbox_edge.setStyleSheet("QComboBox{\n"
" background-color:rgb(216 ,232 , 251);\n"
" border-radius:5px;\n"
" color:rgb(0 ,45 , 115);\n"
"}")
        self.cbox_edge.setObjectName("cbox_edge")
        self.threshold = QtWidgets.QSlider(self.centralwidget)
        self.threshold.setGeometry(QtCore.QRect(320, 680, 121, 20))
        self.threshold.setMaximum(255)
        self.threshold.setOrientation(QtCore.Qt.Horizontal)
        self.threshold.setObjectName("threshold")
        self.label_5 = QtWidgets.QLabel(self.centralwidget)
        self.label_5.setGeometry(QtCore.QRect(130, 670, 181, 41))
        font = QtGui.QFont()
        font.setFamily("Taipei Sans TC Beta")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.label_5.setFont(font)
        self.label_5.setAutoFillBackground(False)
        self.label_5.setStyleSheet("QLabel {\n"
" color:rgb(0 ,45 , 115);\n"
"\n"
"}")
        self.label_5.setObjectName("label_5")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 1200, 24))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.label.setText(_translate("MainWindow", "R08631007 HW3"))
        self.label_2.setText(_translate("MainWindow", "filter size"))
        self.pushButton.setText(_translate("MainWindow", "Load Image"))
        self.label_3.setText(_translate("MainWindow", "select filter"))
        self.pb_apply.setText(_translate("MainWindow", "Apply Filter"))
        self.label_4.setText(_translate("MainWindow", "edge detect"))
        self.label_5.setText(_translate("MainWindow", "zero_c thresh"))
