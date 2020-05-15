# Marija se bavi grncarstvom i pravi solje i tanjire. Da bi
# se napravila solja, potrebno je 6 minuta, dok je za tanjir
# potrebno 3 minuta. Pri pravljenju solje potrosi se 75 gr,
# dok se za tanjir potrosi 100 gr gline. Ukoliko ima 20 sati
# na raspolaganju za izradu svih proizvoda i 250 kg gline, a 
# zarada koju ostvari iznosi 2 evra po svakoj solji i 1.5 evra 
# po tanjiru, koliko solja i tanjira treba da napravi kako bi 
# ostvarila maksimalnu zaradu?

import constraint

problem = constraint.Problem()

# min{1200/6, 250000/75} = min{200, 3333.33} = 200
problem.addVariable('S', range(201))
# min{1200/3, 250000/100} = min{400, 2500} = 400
problem.addVariable('T', range(401))

def ogr_vreme(s, t):
    if 6*s + 3*t <= 1200:
        return True

def ogr_matrijal(s, t):
    if 75*s + 100*t <= 250000:
        return True

problem.addConstraint(ogr_vreme, 'ST')
problem.addConstraint(ogr_matrijal, 'ST')

resenje = problem.getSolutions()

max_zarada = 0
max_S = 0
max_T = 0

for r in resenje:
  if 2*r['S'] + 1.5*r['T'] > max_zarada:
    max_zarada = 2*r['S'] + 1.5*r['T']
    max_S = r['S']
    max_T = r['T']

print("Najveca zarada: {}, {} solja i {} tanjira.".format(max_zarada, max_S, max_T))
