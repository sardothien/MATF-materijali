# Cistacica Mica sredjuje i cisti kuce i stanove. Da bi 
# sredila i pocistila jedan stan potrebno joj je 1 sat,
# dok joj je za kucu potrebno 1.5 sati. Prilikom ciscenja,
# Mica potrosi neku kolicinu deterdzenta, 120ml po stanu, 
# odnosno 100ml po kuci. Mica zaradi 1000 dinara po svakom
# stanu, odnosno 1500 dinara po kuci. Ukoliko Mica radi 40
# sati nedeljno i ima 5l deterdzenta na raspolaganju, koliko
# stanova i kuca je potrebno da ocisti kako bi imala najvecu zaradu?

import constraint

problem = constraint.Problem()

# min {40/1, 5000/120} = min{40, 41.666} = 40
problem.addVariable('S', range(41))
# min{40/1.5, 5000/100} = min{26.6667, 50} = 26
problem.addVariable('K', range(27))

def ogr_vreme(s, k):
    if 1*s + 1.5*k <= 40:
        return True

def ogr_deterdzenta(s, k):
    if 120*s + 100*k <= 5000:
        return True

problem.addConstraint(ogr_vreme, 'SK')
problem.addConstraint(ogr_deterdzenta, 'SK')

resenje = problem.getSolutions()

max_zarada = 0
max_S = 0
max_K = 0

for r in resenje:
    if 1000*r['S'] + 1500*r['K'] > max_zarada:
        max_S = r['S']
        max_K = r['K']
        max_zarada = 1000*r['S'] + 1500*r['K']

print("Najveca zarada: {}, {} stanova i {} kuca.".format(max_zarada, max_S, max_K))