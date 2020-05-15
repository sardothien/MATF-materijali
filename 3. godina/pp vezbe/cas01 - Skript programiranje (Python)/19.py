# Napisati program koji za uneti prirodan broj n ispisuje
# vrednost funkcije x^2 u celobrojnim tackama u intervalu 
# [0, n]. Zadatak resiti koriscenjem mape.

mapa = {}

try:
    n = int(input("Uneti ceo broj: "))
except ValueError:
    print("Nije unet ceo broj!")
    exit(1)

for x in range(n):
    mapa[x] = x**2

for k in mapa:
    print(str(k), str(mapa[k]))