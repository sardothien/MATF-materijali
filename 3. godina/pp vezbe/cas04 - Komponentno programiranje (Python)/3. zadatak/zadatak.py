# Napisati program koji implementira SimplePad aplikaciju: 
# jednostavan tekstualni editor koji podrzava osnovne komande 
# (kreiranja, otvaranja i cuvanja dokumenata), dodatno opcije
# kopiranja, lepljenja i isecanja delova teksta - bazne operacije
# za rad sa tekstom.

import zadatak_ui
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import QFileDialog
import sys, os

class SimplePadClass(zadatak_ui.Ui_MainWindow, QtWidgets.QMainWindow):
    def __init__(self):
        super(SimplePadClass, self).__init__()
        self.setupUi(self)

        self.path = None

        self.actionNew.triggered.connect(lambda: self.OpenMe())
        self.actionSave.triggered.connect(lambda: self.SaveMe())
        self.actionSave_As.triggered.connect(lambda: self.SaveMeAs())

    def __title(self):
        self.setWindowTitle("{} - SimplePad".format(os.path.basename(self.path) if self.path is not None else 'Untitled'))

    def __dialog(self, message):
        box = QMessageBox(self)
        box.setText(message)
        box.show()

    def __save_util(self, path):
        data = self.plainTextEdit.toPlainText()

        try:
            with open(path, 'w') as f:
                f.write(data)
        except Exception as e:
            self.__dialog(str(e))
        else:
            self.path = path
            self.__title()

    def OpenMe(self):
        path,_ = QFileDialog.getOpenFileName(self, "Open file", "", "All files (*.*);")

        if path:
            try:
                with open(path, 'r') as f:
                    data = f.read()
            except Exception as e:
                self.__dialog(str(e))
            else:
                self.path = path
                self.plainTextEdit.setPlainText(data)
                self.__title()

    def SaveMe(self):
        if self.path is None:
            return self.SaveMeAs()
        self.__save_util(self.path)

    def SaveMeAs(self):
        path,_ = QFileDialog.getSaveFileName(self, "Save file", "", "All files (*.*);")
        
        if not path:
            return 
        self.__save_util(path)

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    simplePad = SimplePadClass()
    simplePad.show()
    sys.exit(app.exec_())