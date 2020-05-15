# Pekara Kiflica proizvodi hleb i kifle. Za mesanje hleba 
# potrebno je 10 minuta, dok je za kiflu potrebno 12 minuta.
# Vreme potrebno za pecenje cemo zanemariti. Testo za hleb 
# sadrzi 300g brasna, a testo za kiflu sadrzi 120g brasna.
# Zarada koja se ostvari prilikom prodaje jednog hleba je 
# 7 dinara, a prilikom prodaje jedne kifle je 9 dinara. 
# Ukoliko pekara ima 20 radnih sati za mesanje peciva i 
# 20kg brasna, koliko komada hleba i kifli treba da se umesi 
# kako bi se ostvarila maksimalna zarada (pod pretpostavkom
# da ce pekara sve prodati)?

import constraint

problem = constraint.Problem()

problem.addVariable('H', range(0, 122))
problem.addVariable('K', range(0, 68))

def ogr_vreme(h, k):
    if 10*h + 12*k <= 1200:
        return True

def ogr_materijal(h, k):
    if 300*h + 120*k <= 20000:
        return True

problem.addConstraint(ogr_vreme, 'HK')
problem.addConstraint(ogr_materijal, 'HK')

resenje = problem.getSolutions()

max_H = 0
max_K = 0

for r in resenje:
    if 7*r['H'] + 9*r['K'] > 7*max_H + 9*max_K:
        max_K = r['K']
        max_H = r['H']

print("Max zarada: {}; {} hleba i {} kifli.".format(7*max_H + 9*max_K, max_H, max_K))