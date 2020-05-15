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
        MainWindow.resize(691, 476)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.pbClear = QtWidgets.QPushButton(self.centralwidget)
        self.pbClear.setGeometry(QtCore.QRect(220, 330, 281, 51))
        self.pbClear.setObjectName("pbClear")
        self.lblInsert = QtWidgets.QLabel(self.centralwidget)
        self.lblInsert.setGeometry(QtCore.QRect(20, 100, 231, 51))
        self.lblInsert.setObjectName("lblInsert")
        self.leName = QtWidgets.QLineEdit(self.centralwidget)
        self.leName.setGeometry(QtCore.QRect(260, 110, 411, 31))
        self.leName.setObjectName("leName")
        self.lblHeader = QtWidgets.QLabel(self.centralwidget)
        self.lblHeader.setGeometry(QtCore.QRect(50, 20, 461, 61))
        self.lblHeader.setObjectName("lblHeader")
        self.lblOutput = QtWidgets.QLabel(self.centralwidget)
        self.lblOutput.setGeometry(QtCore.QRect(210, 190, 271, 71))
        font = QtGui.QFont()
        font.setFamily("Purisa")
        font.setPointSize(16)
        font.setBold(True)
        font.setItalic(True)
        font.setWeight(75)
        self.lblOutput.setFont(font)
        self.lblOutput.setObjectName("lblOutput")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 691, 29))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        self.pbClear.clicked.connect(self.leName.clear)
        self.leName.textChanged['QString'].connect(self.lblOutput.setText)
        self.pbClear.clicked.connect(self.lblOutput.clear)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.pbClear.setText(_translate("MainWindow", "Clear name"))
        self.lblInsert.setText(_translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">Insert your name:</span></p></body></html>"))
        self.lblHeader.setText(_translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; font-style:italic;\">Hello World to signal handler!</span></p></body></html>"))
        self.lblOutput.setText(_translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-style:italic;\"></span></p></body></html>"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())

