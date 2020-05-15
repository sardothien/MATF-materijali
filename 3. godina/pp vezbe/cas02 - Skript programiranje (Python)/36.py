# Korisnik na standardni ulaz unosi podatke o imenu, prezimenu
# i godinama. Program potom kreira JSON objekat junak, koji ima
# podatke Ime, Prezime i Godine, i ispisuje ga na standardni
# izlaz, a potom i u datoteku dat.txt.

import json

ime = input("Unesite ime: ")
prezime = input("Unesite prezime: ")
godine = int(input("Unesite godine: "))

junak = {"Ime" : ime, "Prezime" : prezime, "Godine" : godine}
print(json.dumps(junak))

f = open("dat.json", 'w')
json.dump(junak, f)
f.close()