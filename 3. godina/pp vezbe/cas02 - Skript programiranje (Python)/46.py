# Napisati program koji racuna odnos kardinalnosti skupova duze i sire za 
# zadati direktorijum. Datoteka pripada skupu duze ukoliko ima vise redova
# od maksimalnog broja karaktera po redu, u suprotnom pripada skupu sire.
# Sa standardnog ulaza se unosi putanja do direktorijuma. Potrebno je obici 
# sve datoteke u zadatom direktorijumu i njegovim poddirektorijumima
# (koristiti funkciju os.walk()) i ispisati odnos kardinalnosti skupova
# duze i sire.

import os

def obilazak(ime):
    brLinija = 0
    najduza = 0

    with open(ime, 'r') as f:
        for linija in f:
            brLinija += 1
            if len(linija) > najduza:
                najduza = len(linija)

    if brLinija > najduza:
        return 1
    else:
        return 0

putanja = input("Unesite putanju do direktorijuma: ")

sire = 0
duze = 0

for (trendir, poddir, datoteke) in os.walk(putanja):
    for dat in datoteke:
        if obilazak(os.path.join(trendir, dat)) == 0:
            sire += 1
        else:
            duze += 1

print("Duze: {}".format(duze))
print("Sire: {}".format(sire))