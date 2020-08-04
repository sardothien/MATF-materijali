# U direktorijumu utakmice se nalaze datoteke sa ekstenzijom .json koje 
# sadrze podatke o utakmicama (timovi koji se takmice i vreme pocetka 
# utakmice) za svaki sport posebno u sledecem formatu:
# [{"Timovi": "Liverpool - Arsenal", "Vreme": "18:00"},...]
# Napisati program koji sa standardnog ulaza ucitava podatke o pocetku 
# i kraju vremenskog intervala u formatu %H:%M i iz datoteka ucitava 
# podatke o utakmicama za sve sportove, i na standardni izlaz ispisuje 
# listu utakmica cije se vreme pocetka nalazi u opsegu unesenog vremenskog
# intervala.

import json, os
from datetime import datetime

p = raw_input("Unesite pocetak intervala: ")
k = raw_input("Unesite kraj intervala: ")

pocetak = datetime.strptime(p, "%H:%M")
kraj = datetime.strptime(k, "%H:%M")

mapa = {}
for dat in os.listdir("utakmice"):
    with open("utakmice/" + dat, 'r') as f:
        utakmice = json.load(f)
        mapa[dat] = utakmice

for sport in mapa:
    for utakmica in mapa[sport]:
        vreme = datetime.strptime(utakmica["Vreme"], "%H:%M")
        if vreme >= pocetak and vreme <= kraj:
            print json.dumps(utakmica)