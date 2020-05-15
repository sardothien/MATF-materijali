# U datoteci radnici.json se nalaze podaci o radnom vremenu zaposlenih
# u preduzecu. Napisati program koji u zavisnosti od unete opcije poslodavcu 
# ispisuje trenutno dostupne radnike odnosno radnike koji su na odmoru. 
# Moguće opcije su ’d’ - trenutno dostupni radnici i ’o’ - radnici koji su
# na odmoru. Radnik je dostupan ukoliko nije na odmoru i trenutno vreme je
# u okviru njegovog radnog vremena.

import json, os, sys
from datetime import datetime

opcija = input("Unesite opciju koju zelite: ")
if opcija != 'd' and opcija != 'o':
    print("Opcija nije podrzana!")
    exit()

try:
    with open('radnici.json', 'r') as f:
        radnici = json.load(f)
except FileNotFoundError:
    print("Datoteka ne postoji!")
    exit()

trendatum = datetime.now()

for radnik in radnici:
    kraj_odmora = datetime.strptime(radnik['odmor'][1], "%d.%m.%Y.").date()
    pocetak_odmora = datetime.strptime(radnik['odmor'][0], "%d.%m.%Y.").date()
    kraj_rad_vremena = datetime.strptime(radnik['radno_vreme'][1], "%H:%M").time()
    pocetak_rad_vremena = datetime.strptime(radnik['radno_vreme'][0], "%H:%M").time()

    if opcija == 'o':
        if pocetak_odmora < trendatum.date() < kraj_odmora:
            print(radnik["ime"])
        else:
            if not (pocetak_odmora < trendatum.date() < kraj_odmora) and pocetak_rad_vremena < trendatum.time() < kraj_rad_vremena:
                print(radnik["ime"])