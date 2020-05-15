# Napisati program koji sa standardnog ulaza ucitava listu
# celih brojeva, a zatim na standardni izlaz ispisuje njenu
# duzinu, sumu njenih elemenata, njen maksimalni element kao 
# i broj pojavljivanja broja jedan u unetoj listi.

lista = list(input("Uneti elemente liste: "))
print(lista, type(lista))

lista += [4, 5]
print(lista)

lista = [1, 2, 5, 4, 5]
print(len(lista))
print(sum(lista))
print(max(lista))
for l in lista:
    print(lista.count(l), end=' ')
print()

lista.append(6)
print(lista)

lista = [1, 2, "Matf", 13.2, [1, 2, 3], [[1, 2], [3, 4]], 1]
print(lista)
print(lista[2:])
print(lista[:3])
print(lista[-2])

try:
    print(max(lista))
except TypeError:
    print("Python3 ne poredi razlicite tipove!")