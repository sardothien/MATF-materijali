from PyQt5 import QtCore, QtGui, QtWidgets
import zadatak_ui
import sys, os, random, string, time

class HackerApp(zadatak_ui.Ui_MainWindow, QtWidgets.QMainWindow):
    def __init__(self):
        super(HackerApp, self).__init__()
        self.setupUi(self)

        self.bStart.clicked.connect(self.pressed)

    def pressed(self):
        print("Engine started...")
        for i in range(0, 100):
            print("...{}...".format(''.join(random.choices(string.ascii_uppercase + string.digits, k = random.randint(20,40)))))
            self.progressBar.setProperty("value", i)

            if i % 2 == 0:
                self.lblProgress.setText(''.join(random.choices(string.ascii_uppercase + string.digits, k = random.randint(20, 40))))
            
            time.sleep(1)

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    hacker = HackerApp()
    hacker.show()
    sys.exit(app.exec_())