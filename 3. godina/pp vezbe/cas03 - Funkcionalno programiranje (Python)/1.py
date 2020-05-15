# Napisati program koji sa standardnog ulaza ucitava
# dva broja i na standardni izlaz ispisuje njihov zbir.

a = int(input("Uneti prvi broj: "))
b = int(input("Uneti drugi broj: "))

suma = lambda a,b: a + b

print("Suma: {}".format(suma(a, b)))