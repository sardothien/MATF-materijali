# Napisati program koji obilazi direktorijume rekurzivno i racuna broj
# datoteka za sve postojece ekstenzije u tim direktorijumima. Sa 
# standardnog ulaza se unosi putanja do pocetnog direktorijuma, a 
# rezultat se ispisuje u datoteku rezultat.json.

import json
import os

putanja = input("Unesite putanju do direktorijuma: ")

ekstenzije = {}

for (trendir, poddir, datoteke) in os.walk(putanja):
    for dat in datoteke:
        poz = dat.find('.')
        if poz >= 0:
            if dat[poz:] in ekstenzije:
                ekstenzije[dat[poz:]] += 1
            else:
                ekstenzije[dat[poz:]] = 1

with open('rez.json', 'w') as f:
    json.dump(ekstenzije, f)