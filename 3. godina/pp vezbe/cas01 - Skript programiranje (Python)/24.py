# Napisati program koji implementira igricu X-O sa dva igraca.

import random

# Ispisivanje table
def ispisi_tablu(tabla):
    print("TABLA")
    print("    1    2   3")
    print("   ---  --- ---")

    indeks = 1
    for i in tabla:
        print(indeks, "|", i[0], "|", i[1], "|", i[2], "|")
        print("   ---  --- ---")
        indeks += 1
    print()

# Da li imamo pobednika?
def pobedio(tabla):
    if (tabla[0][0] != '-' and tabla[0][2] != '-') and ((tabla[0][0] == tabla[1][1] == tabla[2][2]) or (tabla[0][2] == tabla[1][1] == tabla[2][0])):
        return True
    
    for i in range(3):
        if (tabla[0][i] != '-' and tabla[i][0] != '-') and ((tabla[0][i] == tabla[1][i] == tabla[2][i]) or (tabla[i][0] == tabla[i][1] == tabla[i][2])):
            return True

    return False

def ucitaj_koordinate(ime):
    while True:
        print("{}, unesite koordinate polja koje zelite da popunite.".format(ime))
        x = int(input("Vrsta: "))
        y = int(input("Kolona: "))
        if 1 <= x <= 3 and 1 <= y <= 3:
            return x-1, y-1
        else:
            "Morate uneti brojeve izmedju 1 i 3"

# Sledeci korak
def korak(igrac):
    while True:
        x, y = ucitaj_koordinate(igrac[0])
        if tabla[x][y] == '-':
            tabla[x][y] = igrac[1]
            ispisi_tablu(tabla)
            break
        else:
            print(tabla[x][y])
            print("Uneto polje je popunjeno!")

ime1 = input("Unesite ime prvog igraca: ")
print("Zdravo {}!".format(ime1))

ime2 = input("Unesite ime drugog igraca: ")
print("Zdravo {}!".format(ime2))

indikator = random.randint(1, 2)
if indikator == 1:
    prvi_igrac = (ime1, 'X')
    drugi_igrac = (ime2, 'O')
else:
    prvi_igrac = (ime2, 'X')
    drugi_igrac = (ime1, 'O')

print("Igrac {} igra prvi.".format(prvi_igrac))
print("X : {}".format(prvi_igrac[0]))
print("O : {}".format(drugi_igrac[0]))

tabla = [['-', '-', '-'], ['-', '-', '-'], ['-', '-', '-']]

print("Zapocnimo igru!")

ispisi_tablu(tabla)

na_redu = 0
iteracija = 0
igraci = [prvi_igrac, drugi_igrac]

while iteracija < 9:
    korak(igraci[na_redu])
    if pobedio(tabla) == True:
        print("POBEDIO JE IGRAC: {}!!!!".format(igraci[na_redu][0]))
        break
    na_redu = (na_redu + 1) % 2
    iteracija += 1

if iteracija == 9:
    print("NERESENO!!!")