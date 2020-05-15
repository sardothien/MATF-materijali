# Napisati program koji sa standardnog ulaza ucitava ime
# datoteke i broj n i racuna broj pojavljivanja svakog
# n-grama u datoteci koji su sacinjeni od proizvoljnih 
# karaktera i rezultat upisuje u datoteku rez.json.

import json

ime = input("Unesite ime datoteke: ")
n = int(input("Unesite n: "))

with open(ime, 'r') as f:
    sadrzaj = f.read()
    
recnik = {}
i = 0
while i < len(sadrzaj)-n:
    ngram = sadrzaj[i:i+n]
    if ngram in recnik:
        recnik[ngram] = recnik[ngram] + 1
    else:
        recnik[ngram] = 1
    i = i + 1

with open("rez.json", 'w') as f:
    json.dump(recnik, f)