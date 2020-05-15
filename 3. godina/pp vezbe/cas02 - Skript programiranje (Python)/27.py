# Koriscenjem liste implementirati klasu stek.

class Stack:
    # konstruktor
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        try:
            return self.items.pop()
        except IndexError:
            print("Stack is empty!")
            return None

    def top(self):
        try:
            return self.items[-1]
        except IndexError:
            print("Stack is empty!")
            return None

s = Stack()
s.push(1)
s.push(2)
s.push(3)
print(s.top())
s.pop()
print(s.top())
s.pop()