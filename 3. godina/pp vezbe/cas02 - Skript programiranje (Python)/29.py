# Implementirati klasu Oblik, koja kao argumente ima boju
# kao i informaciju o popunjenosti unustrasnosti oblika bojom.
# Definisati metode za dohvatanje i postavljanje ovih atributa.
# Definisati klase Krug i Pravougaonik koje nasledjuju klasu
# oblik, od dodatnih atributa imaju informaciju o poluprecniku,
# odnosno stranicama redom, i implementiraju funkcije racunanja
# obima i povrsine.

import math

class Shape:
    def __init__(self, color = 'black', filled = False):
        self.__color = color
        self.__filled = filled

    def getColor(self):
        return self.__color

    def getFilled(self):
        return self.filled

    def setFilled(self, filled):
        self.__filled = filled

class Rectangle(Shape):
    def __init__(self, width, length):
        super().__init__(color = 'red')
        self.__width = width
        self.__length = length

    def getArea(self):
        return self.__width * self.__length

    def getPerimeter(self):
        return 2 * (self.__width + self.__length)

class Circle(Shape):
    def __init__(self, radius):
        super().__init__(color = 'yellow')
        self.__radius = radius

    def getArea(self):
        return math.pi * (self.__radius**2)

    def getPerimeter(self):
        return 2 * math.pi * self.__radius

s1 = Rectangle(10.5, 5.3)
print(s1.getArea(), s1.getPerimeter())

s2 = Circle(6.1)
print(s2.getArea(), s2.getPerimeter())