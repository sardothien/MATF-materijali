# Napisati program koji implementira igricu ”Pogodi broj”. Na pocetku igre racunar
# zamislja jedan slucajan broj u intervalu [0,100]. Nakon toga igrac unosi svoje ime
# i zapocinje igru. Igrac unosi jedan po jedan broj sve dok ne pogodi koji broj je 
# racunar zamislio. Svaki put kada igrac unese broj, u zavisnosti od toga da li je
# broj koji je unet veci ili manji od zamisljenog broja ispisuje se odgovarajuca 
# poruka. Igra se zavrsava u trenutku kada igrac pogodio zamisljen broj.

import random

zamisljeni_broj = random.randint(0, 100)

ime = input("Unesite Vase ime: ")

print("Zdravo {}.\nZamislio sam neki broj od 1 do 100. Pogodi?".format(ime))

pogodio = False
while not pogodio:
    print("Unesi broj: ")
    broj = int(input())
    
    if broj == zamisljeni_broj:
        pogodio = True
    elif broj < zamisljeni_broj:
        print("Zamisljeni broj je veci od broja {}".format(broj))
    else:
        print("Zamisljeni broj je manji od broja {}".format(broj))

print("POGODILI STE BROJ!!!")