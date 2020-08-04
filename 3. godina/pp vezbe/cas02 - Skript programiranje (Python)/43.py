# U datoteci dat.json se nalaze podaci o tackam. Napisati
# program koji ucitava podatke o tackama iz datoteke i sortira
# ih po udaljenosti od koordinatnog pocetka. Na standardni
# izlaz ispisati podatke pre i posle sortiranja.

import json
import math

try:
    with open("dat.json", "r") as f:
        tacke = json.load(f)
except FileNotFoundError:
    print("Datoteka ne postoji!")
    exit(1)

sortirano = sorted(tacke, key=lambda x: math.sqrt(x['koordinate'][0]**2 + x['koordinate'][1]**2))

for item in tacke:
    print(item["teme"], end=' ')
print()

for item in sortirano:
    print(item["teme"], end=' ')
print()