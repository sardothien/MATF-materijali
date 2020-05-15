# Napisati program koji aproksimira broj PI koriscenjem metode Monte Karlo. Sa 
# standardnog ulaza unosi se broj N. Nakon toga N puta se bira tacka na slucajan
# nacin tako da su obe koordinate tacke iz intervala [0,1]. Broj PI se racuna po
# sledecoj formuli: PI = 4 ∗ A/B. A je broj slucajno izabranih tacaka koje pripadaju 
# krugu poluprecnika 0.5, sa centrom u tacki (0.5, 0.5). B je broj slucajno izabranih 
# tacaka koje pripadaju kvadratu cija temena su tacke (0, 0), (0, 1), (1, 1), (1, 0).

import random
import math

def dist(A, B):
    "Funkcija izracunava euklidsko rastojanje izmedju tacaka A i B"
    return math.sqrt((A[0] - B[0])**2 + (A[1] - B[1])**2)

try:
    n = int(input("Unesite ceo broj n: "))
except ValueError:
    print("Nije unet ceo broj!")
    exit(1)

A = 0
B = 0

for i in range(n):
    tacka = (random.random(), random.random())
    if dist(tacka, (0.5, 0.5)) <= 0.5:
        A = A + 1
    B = B + 1

print("Resenje: {}".format(4.0 * A / B))