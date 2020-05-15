# U datoteci korpa.json se nalazi spisak kupljenog voca u 
# json formatu. U datotekama maxi_cene.json, idea_cene.json,
# shopngo_cene.json se nalaze cene voca u json formatu.
# Napisati program koji izracunava ukupan racun korpe u 
# svakoj prodavnici i ispisuje cene na standardni izlaz.

import json

def cena_voca(prodavnica, voce):
    for v in prodavnica:
        if v['ime'] == voce:
            return v['cena']

with open("korpa.json", 'r') as f:
    korpa = json.load(f)

with open("maxi_cene.json", 'r') as f:
    maxi = json.load(f)

with open("idea_cene.json", 'r') as f:
    idea = json.load(f)

with open("shopngo_cene.json", 'r') as f:
    shopngo = json.load(f)

maxi_racun = 0
idea_racun = 0
shopngo_racun = 0

i = 0
while i < len(korpa):
    ime = korpa[i]['ime']

    maxi_racun += korpa[i]['kolicina'] * cena_voca(maxi, ime)
    idea_racun += korpa[i]['kolicina'] * cena_voca(idea, ime)
    shopngo_racun += korpa[i]['kolicina'] * cena_voca(shopngo, ime)

    i += 1

print("Maxi: {}".format(maxi_racun))
print("Idea: {}".format(idea_racun))
print("Shop&Go: {}".format(shopngo_racun))