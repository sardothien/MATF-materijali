# Napisati program koji iz datoteke dat.json ucitava JSON objekat,
# a potom na standardni izlaz ispisuje podatke o imenu, prezimenu
# i godinama.

import json

try:
    with open("dat.json", "r") as datoteka:
        x = json.load(datoteka)
        print(x['Ime'])
        print(x['Prezime'])
        print(x['Godine'])
except FileNotFoundError:
    print("Datoteka ne postoji!")
    exit(1)