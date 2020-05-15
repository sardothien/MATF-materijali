# U datoteci korpa.json se nalazi spisak kupljenog voca. 
# U datotekama maxi_cene.json, idea_cene.json i 
# shopngo_cene.json se nalaze cene voca. Napisati program
# koji izracunava ukupan racun korpe u svakoj prodavnici
# i ispisuje cene na standardni izlaz.

import json
from functools import reduce 

def cena_voca(prodavnica, ime_voca):
    for voce in prodavnica:
        if voce['ime'] == ime_voca:
            return voce['cena']

try:
    with open('korpa.json', 'r') as f:
        korpa = json.load(f)
    with open('maxi_cene.json', 'r') as f:
        maxi = json.load(f)
    with open('idea_cene.json', 'r') as f:
        idea = json.load(f)
    with open('shopngo_cene.json', 'r') as f:
        shopngo = json.load(f)
except IOError:
    print("Neuspeno otvaranje fajla!")
    exit(1)

maxi_racun = reduce(lambda a,b: a+b, [voce['kolicina']*cena_voca(maxi, voce['ime']) for voce in korpa])
idea_racun = reduce(lambda a,b: a+b, [voce['kolicina']*cena_voca(idea, voce['ime']) for voce in korpa])
shopngo_racun = reduce(lambda a,b: a+b, [voce['kolicina']*cena_voca(shopngo, voce['ime']) for voce in korpa])

print("Maxi: {}".format(str(maxi_racun)))
print("Idea: {}".format(str(idea_racun)))
print("Shop&Go: {}".format(str(shopngo_racun)))