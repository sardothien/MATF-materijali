import json, sys, math

if len(sys.argv) != 2:
    print("Greska")
    exit(1)

def rastojanje(x1, y1, x2, y2):
    sirina1 = math.radians(x1)
    duzina1 = math.radians(y1)
    sirina2 = math.radians(x2)
    duzina2 = math.radians(y2)

    a = math.sin(((sirina2 - sirina1) / 2.0)**2) + math.cos(sirina1)*math.cos(sirina2)*math.sin(((duzina1 - duzina2) / 2.0)**2)
    c = math.atan(math.sqrt(a) / math.sqrt(1-a))
    udaljenost = 6371*c

    return udaljenost

def agenti_u_okolini(agenti, tr_lokacija, d):
    a = tr_lokacija[0]
    b = tr_lokacija[1]

    return list(filter(lambda x: rastojanje(a, b, x['lokacija'][0], x['lokacija'][1] < d), agenti))

with open(sys.argv[1], 'r') as f:
    datoteka = json.load(f)

sirina = float(input())
duzina = float(input())
d = int(input())

tr_lokacija = [sirina, duzina]

for a in agenti_u_okolini(datoteka, tr_lokacija, d):
    print(a)
print()

agenti = agenti_u_okolini(datoteka, tr_lokacija, d)
agenti.sort(lambda x: x['dokument'])

for a in agenti:
    print(a['ime'])