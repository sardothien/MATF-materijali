# U datoteci tacke.json se nalaze podaci o tackama. Napisati
# program koji ucitava podatke o tackama iz datoteke i sortira
# ih po udaljenosti od koordinatnog pocetka opadajuce. Program
# na standardni izlaz treba da ispise tacku iz zadatog kvadranta,
# koja je najudaljenija od koordinatnog pocetka. Kvadrant se zadaje
# kao argument komandne linije.

import json, math, sys
from functools import partial

# Da li tacka pripada kvadrantu?
def pripada(kvadrant, tacka):
    koordinate = tacka['koordinate']

    if kvadrant == 1:
        return koordinate[0] >= 0 and koordinate[1] >= 0
    elif kvadrant == 2:
        return koordinate[0] <= 0 and koordinate[1] >= 0
    elif kvadrant == 3:
        return koordinate[0] <= 0 and koordinate[1] <= 0
    else:
        return koordinate[0] >= 0 and koordinate[1] <= 0

if len(sys.argv) != 2:
    print("Niste naveli kvadrant!")
    exit(1)

try:
    with open('tacke.json', 'r') as f:
        tacke = json.load(f)
except IOError:
    print("Datoteka ne postoji!")
    exit(1)

try:
    kvadrant = int(sys.argv[1])
except ValueError:
    print('Niste uneli ceo broj!')
    exit(1)

# fiksiramo kvadrant
uslov = partial(pripada, kvadrant)
kvadrant_tacke = list(filter(uslov, tacke))

if len(kvadrant_tacke) > 0:
    print(max(kvadrant_tacke, key = lambda x: x['koordinate'][0]**2 + x['koordinate'][1]**2))
else:
    print("Trazena tacka ne postoji!")