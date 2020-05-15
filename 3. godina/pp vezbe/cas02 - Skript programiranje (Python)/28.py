# Implementirati klasu Robot, koja ce biti svesna broja
# trenutno zivih instanci ove klase. Klasa kao atribut ima
# naziv robota. Od metoda definisati metod oglasavanja robota,
# kao i staticki metod koji na standardni izlaz ispisuje broj
# trenutno aktivnih instanci ove klase.

class Robot:

    population = 0

    def __init__(self, name):
        self.name = name
        Robot.population += 1
        print("{} is created!".format(self.name))

    def __del__(self):
        print("{} is deleted!".format(self.name))
        Robot.population -= 1

    def say_hi(self):
        print("Hello from {}!".format(self.name))

    @classmethod # staticki metod
    def how_many(cls):
        print("{} robots.".format(cls.population))

robot1 = Robot("R2-D2")
robot1.say_hi()
Robot.how_many()

robot2 = Robot("C-3P0")
robot2.say_hi()
Robot.how_many()

del robot1
del robot2
Robot.how_many()