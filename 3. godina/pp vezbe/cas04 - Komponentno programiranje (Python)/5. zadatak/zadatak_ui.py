# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'prozor.ui'
#
# Created by: PyQt5 UI code generator 5.9.2
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(538, 637)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.frame = QtWidgets.QFrame(self.centralwidget)
        self.frame.setGeometry(QtCore.QRect(20, 20, 491, 541))
        self.frame.setStyleSheet("background-color: rgb(170, 255, 255)")
        self.frame.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.frame.setFrameShadow(QtWidgets.QFrame.Raised)
        self.frame.setObjectName("frame")
        self.lineEdit = QtWidgets.QLineEdit(self.frame)
        self.lineEdit.setGeometry(QtCore.QRect(30, 20, 431, 71))
        self.lineEdit.setStyleSheet("background-color: rgb(255, 255, 127);\n"
"font: 22pt \"Ani\";")
        self.lineEdit.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lineEdit.setObjectName("lineEdit")
        self.btnC = QtWidgets.QPushButton(self.frame)
        self.btnC.setGeometry(QtCore.QRect(30, 110, 221, 81))
        self.btnC.setStyleSheet("background-color: rgb(255, 85, 0);\n"
"font: 75 18pt \"Ubuntu\";\n"
"font-weight: bold;")
        self.btnC.setObjectName("btnC")
        self.btnDEL = QtWidgets.QPushButton(self.frame)
        self.btnDEL.setGeometry(QtCore.QRect(250, 110, 111, 81))
        self.btnDEL.setStyleSheet("background-color: rgb(170, 170, 255);\n"
"font: 75 18pt \"Ubuntu\";\n"
"font-weight: bold;")
        self.btnDEL.setObjectName("btnDEL")
        self.btnMOD = QtWidgets.QPushButton(self.frame)
        self.btnMOD.setGeometry(QtCore.QRect(360, 110, 101, 81))
        self.btnMOD.setStyleSheet("background-color: rgb(255, 170, 0);\n"
"font: 22pt \"Ani\";")
        self.btnMOD.setObjectName("btnMOD")
        self.btnDIV = QtWidgets.QPushButton(self.frame)
        self.btnDIV.setGeometry(QtCore.QRect(360, 190, 101, 81))
        self.btnDIV.setStyleSheet("background-color: rgb(255, 170, 0);\n"
"font: 22pt \"Ani\";")
        self.btnDIV.setObjectName("btnDIV")
        self.btnMUL = QtWidgets.QPushButton(self.frame)
        self.btnMUL.setGeometry(QtCore.QRect(360, 270, 101, 81))
        self.btnMUL.setStyleSheet("background-color: rgb(255, 170, 0);\n"
"font: 22pt \"Ani\";")
        self.btnMUL.setObjectName("btnMUL")
        self.btnMinus = QtWidgets.QPushButton(self.frame)
        self.btnMinus.setGeometry(QtCore.QRect(360, 350, 101, 81))
        self.btnMinus.setStyleSheet("background-color: rgb(255, 170, 0);\n"
"font: 22pt \"Ani\";")
        self.btnMinus.setObjectName("btnMinus")
        self.btnPlus = QtWidgets.QPushButton(self.frame)
        self.btnPlus.setGeometry(QtCore.QRect(360, 430, 101, 81))
        self.btnPlus.setStyleSheet("background-color: rgb(255, 170, 0);\n"
"font: 22pt \"Ani\";")
        self.btnPlus.setObjectName("btnPlus")
        self.btn9 = QtWidgets.QPushButton(self.frame)
        self.btn9.setGeometry(QtCore.QRect(250, 190, 111, 81))
        font = QtGui.QFont()
        font.setFamily("Ani")
        font.setPointSize(22)
        font.setBold(False)
        font.setItalic(False)
        font.setWeight(50)
        self.btn9.setFont(font)
        self.btn9.setStyleSheet("background-color: rgb(0, 255, 255);\n"
"font: 22pt \"Ani\";")
        self.btn9.setObjectName("btn9")
        self.btn8 = QtWidgets.QPushButton(self.frame)
        self.btn8.setGeometry(QtCore.QRect(140, 190, 111, 81))
        self.btn8.setStyleSheet("background-color: rgb(0, 255, 255);\n"
"font: 22pt \"Ani\";")
        self.btn8.setObjectName("btn8")
        self.btn7 = QtWidgets.QPushButton(self.frame)
        self.btn7.setGeometry(QtCore.QRect(30, 190, 111, 81))
        self.btn7.setStyleSheet("background-color: rgb(0, 255, 255);\n"
"font: 22pt \"Ani\";")
        self.btn7.setObjectName("btn7")
        self.btn5 = QtWidgets.QPushButton(self.frame)
        self.btn5.setGeometry(QtCore.QRect(140, 270, 111, 81))
        self.btn5.setStyleSheet("background-color: rgb(0, 255, 255);\n"
"font: 22pt \"Ani\";")
        self.btn5.setObjectName("btn5")
        self.btn4 = QtWidgets.QPushButton(self.frame)
        self.btn4.setGeometry(QtCore.QRect(30, 270, 111, 81))
        self.btn4.setStyleSheet("background-color: rgb(0, 255, 255);\n"
"font: 22pt \"Ani\";")
        self.btn4.setObjectName("btn4")
        self.btn6 = QtWidgets.QPushButton(self.frame)
        self.btn6.setGeometry(QtCore.QRect(250, 270, 111, 81))
        self.btn6.setStyleSheet("background-color: rgb(0, 255, 255);\n"
"font: 22pt \"Ani\";")
        self.btn6.setObjectName("btn6")
        self.btn2 = QtWidgets.QPushButton(self.frame)
        self.btn2.setGeometry(QtCore.QRect(140, 350, 111, 81))
        self.btn2.setStyleSheet("background-color: rgb(0, 255, 255);\n"
"font: 22pt \"Ani\";")
        self.btn2.setObjectName("btn2")
        self.btn1 = QtWidgets.QPushButton(self.frame)
        self.btn1.setGeometry(QtCore.QRect(30, 350, 111, 81))
        self.btn1.setStyleSheet("background-color: rgb(0, 255, 255);\n"
"font: 22pt \"Ani\";")
        self.btn1.setObjectName("btn1")
        self.btn3 = QtWidgets.QPushButton(self.frame)
        self.btn3.setGeometry(QtCore.QRect(250, 350, 111, 81))
        self.btn3.setStyleSheet("background-color: rgb(0, 255, 255);\n"
"font: 22pt \"Ani\";")
        self.btn3.setObjectName("btn3")
        self.btnEqv = QtWidgets.QPushButton(self.frame)
        self.btnEqv.setGeometry(QtCore.QRect(250, 430, 111, 81))
        self.btnEqv.setStyleSheet("background-color: rgb(170, 170, 255);\n"
"font: 22pt \"Ani\";")
        self.btnEqv.setObjectName("btnEqv")
        self.btn0 = QtWidgets.QPushButton(self.frame)
        self.btn0.setGeometry(QtCore.QRect(30, 430, 221, 81))
        self.btn0.setStyleSheet("background-color: rgb(0, 255, 255);\n"
"font: 22pt \"Ani\";")
        self.btn0.setObjectName("btn0")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 538, 29))
        self.menubar.setObjectName("menubar")
        self.menuinfo = QtWidgets.QMenu(self.menubar)
        self.menuinfo.setObjectName("menuinfo")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.actionAbout = QtWidgets.QAction(MainWindow)
        self.actionAbout.setObjectName("actionAbout")
        self.actionType_Here = QtWidgets.QAction(MainWindow)
        self.actionType_Here.setObjectName("actionType_Here")
        self.menuinfo.addAction(self.actionAbout)
        self.menubar.addAction(self.menuinfo.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.btnC.setText(_translate("MainWindow", "C"))
        self.btnDEL.setText(_translate("MainWindow", "DEL"))
        self.btnMOD.setText(_translate("MainWindow", "%"))
        self.btnDIV.setText(_translate("MainWindow", "/"))
        self.btnMUL.setText(_translate("MainWindow", "x"))
        self.btnMinus.setText(_translate("MainWindow", "-"))
        self.btnPlus.setText(_translate("MainWindow", "+"))
        self.btn9.setText(_translate("MainWindow", "9"))
        self.btn8.setText(_translate("MainWindow", "8"))
        self.btn7.setText(_translate("MainWindow", "7"))
        self.btn5.setText(_translate("MainWindow", "5"))
        self.btn4.setText(_translate("MainWindow", "4"))
        self.btn6.setText(_translate("MainWindow", "6"))
        self.btn2.setText(_translate("MainWindow", "2"))
        self.btn1.setText(_translate("MainWindow", "1"))
        self.btn3.setText(_translate("MainWindow", "3"))
        self.btnEqv.setText(_translate("MainWindow", "="))
        self.btn0.setText(_translate("MainWindow", "0"))
        self.menuinfo.setTitle(_translate("MainWindow", "info"))
        self.actionAbout.setText(_translate("MainWindow", "About"))
        self.actionType_Here.setText(_translate("MainWindow", "Type Here"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())

