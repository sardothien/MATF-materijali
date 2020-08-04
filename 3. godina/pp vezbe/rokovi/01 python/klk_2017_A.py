# Datoteke sa ekstenzijom .json sadrze podatke o fudbalerima (ime, nacionalnost 
# i broj golova) u sledecem formatu:
# [{"Ime" : "Alexis Sanchez", "Nacionalnost" :"Cile", "Golovi" : 17}, ...]
# Napisati program koji iz izabrane datoteke izdvaja fudbalere odredjene 
# nacionalnosti i sortira ih rastuce po broju golova. Zeljena nacionalnost 
# (npr. 'Engleska') i ime datoteke u kojoj se nalaze podaci o fudbalerima se
# zadaju kao argumenti komandne linije, a rezultat rada programa se upisuje u 
# datoteku izabrana_nacionalnost.json (npr. Engleska_nacionalnost.json). U 
# slucaju greske prilikom pokretanja programa, ispisati tekst Greska na standardni 
# izlaz.

import sys, json

if len(sys.argv) != 3:
    print("Greska")
    exit(1)

nacionalnost = sys.argv[1]
datoteka = sys.argv[2]

igraci = []

with open(datoteka, 'r') as f:
    dat = json.load(f)
    for linija in dat:
        if linija["Nacionalnost"] == nacionalnost:
            igraci.append(linija)

igraci.sort()

with open(nacionalnost + "_nacionalnost.json", 'w') as f:
    json.dump(igraci, f)