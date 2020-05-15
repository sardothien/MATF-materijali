# Korisnik sa standardnog ulaza unosi ceo broj n, a potom
# ciklicno pomeren rastuce sortiran niz koji ima n elemenata.
# Napisati program koji na standardni izlaz ispisuje sortiran
# niz bez ponavaljanja elemenata.

try:
    n = int(input("Uneti ceo broj: "))
except ValueError:
    print("Nije unet ceo broj!")
    exit(1)

elementi = []
for i in range(n):
    elem = int(input())
    if not elem in elementi:
        elementi.append(elem)

k = 0
for i in range(n-1):
    if elementi[i] > elementi[i+1]:
        k = i+1
        break

prvi_deo = elementi[0:k]
drugi_deo = elementi[k:]

sort = drugi_deo + prvi_deo
for elem in sort:
    print(elem)