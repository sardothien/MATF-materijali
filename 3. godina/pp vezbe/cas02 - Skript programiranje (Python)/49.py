# Napisati program koji ucitava ime datoteke sa standardnog ulaza i na 
# standardni izlaz ispisuje putanje do svih direktorijuma u kojima se 
# nalazi ta datoteka.

import os

ime = input("Unesite naziv datoteke: ")

for (trendir, poddir, datoteke) in os.walk("/"):
    for dat in datoteke:
        if dat == ime:
            print(os.path.join(os.path.abspath(trendir), ime))