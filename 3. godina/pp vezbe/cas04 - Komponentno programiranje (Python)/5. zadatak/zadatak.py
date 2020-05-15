from PyQt5 import QtCore, QtGui, QtWidgets
import zadatak_ui
import sys, re

class Calculator(zadatak_ui.Ui_MainWindow, QtWidgets.QMainWindow):
    def __init__(self):
        super(Calculator, self).__init__()
        self.setupUi(self)

        # Akcije za izbor brojeva
        self.btn0.clicked.connect(lambda: self.display_screen('0'))
        self.btn1.clicked.connect(lambda: self.display_screen('1'))
        self.btn2.clicked.connect(lambda: self.display_screen('2'))
        self.btn3.clicked.connect(lambda: self.display_screen('3'))
        self.btn4.clicked.connect(lambda: self.display_screen('4'))
        self.btn5.clicked.connect(lambda: self.display_screen('5'))
        self.btn6.clicked.connect(lambda: self.display_screen('6'))
        self.btn7.clicked.connect(lambda: self.display_screen('7'))
        self.btn8.clicked.connect(lambda: self.display_screen('8'))
        self.btn9.clicked.connect(lambda: self.display_screen('9'))

        # Akcija za C
        self.btnC.clicked.connect(self.lineEdit.clear)

        # Akcija za DEL
        self.btnDEL.clicked.connect(self.lineEdit.backspace)

        # Akcije za operacije
        self.btnMOD.clicked.connect(lambda: self.display_operator('%'))
        self.btnDIV.clicked.connect(lambda: self.display_operator('/'))
        self.btnMUL.clicked.connect(lambda: self.display_operator('*'))
        self.btnPlus.clicked.connect(lambda: self.display_operator('+'))
        self.btnMinus.clicked.connect(lambda: self.display_operator('-'))

        # Akcija za =
        self.btnEqv.clicked.connect(self.calculate)

    def display_screen(self, digit):
        self.lineEdit.insert(digit)

    def display_operator(self, operator):
        if len(self.lineEdit.text()) > 0 and self.lineEdit.text()[-1] not in ['+', '-', '*', '/', '%']:
            self.lineEdit.insert(operator)

    def calculate(self):
        data = str(self.lineEdit.text())
        operands = re.split('[+-]', data)
        operators = list(filter(lambda c: c in ['+', '-'], data))
        
        assert len(operators) + 1 == len(operands)
        operands = list(map(lambda expression: self.evaluate(expression), operands))

        result = int(operands[0])
        for i in range(0, len(operators)):
            nextOperand = operands[i+1]
            nextOperator = operators[i]

            if nextOperator == '+':
                result += int(nextOperand)
            else:
                result -= int(nextOperand)
            
        self.lineEdit.setText(str(result))

    def evaluate(self, data):
        operands = re.split('[\*%/]', data)
        
        if len(operands) == 1:
            return data

        operators = list(filter(lambda c: c in ['*', '/', '%'], data))
        assert len(operators) + 1 == len(operands)

        result = int(operands[0])
        for i in range(0, len(operators)):
            nextOperand = operands[i+1]
            nextOperator = operators[i]

            if nextOperator == '*':
                result *= int(nextOperand)
            elif nextOperator == '%':
                result = result % int(nextOperand)
            else:
                result = int(result/float(nextOperand))
            
        return result

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    calculator = Calculator()
    calculator.show()
    sys.exit(app.exec_())