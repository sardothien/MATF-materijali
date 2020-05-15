# Jovanin komsija preprodaje racunare i racunarsku opremu.
# Ocekuje isporuku racunara i stampaca. Pri tom, racunari 
# su spakovani tako da njihova kutija zauzima 360 kubnih
# decimetara prostora, dok se stampaci pakuju u kutijama
# koje zauzimaju 240 kubnih decimetara prostora. Komsija
# se trudi da mesecno proda najmanje 30 racunara i da taj 
# broj bude bar za 50% veci od broja prodatih stampaca. 
# Racunari kostaju 200 evra po nabavnoj ceni, a prodaju se
# po ceni od 400 evra, dok stampaci kostaju u nabavci 60 evra
# i prodaju se za 140 evra. Magacin kojim komsija raspolaze ima
# svega 30000 kubnih decimetara prostora i mesecno moze da nabavi
# robu u iznosu od najvise 14000 evra. Koliko racunara, a koliko 
# stampaca komsija treba da proda kako bi se maksimalno obogatio?

import constraint

problem = constraint.Problem()

# min{30000/360, 14000/200} = min{83.33, 70} = 70
problem.addVariable('R', range(71))
# min{30000/240, 14000/60} = min{125, 233.33} = 125
problem.addVariable('S', range(126))

def ogr(r, s):
	if r >= (3.0*s/2):
		return True

problem.addConstraint(constraint.MaxSumConstraint(30000, [360, 240]), 'RS')
problem.addConstraint(constraint.MaxSumConstraint(14000, [200, 60]), 'RS')
problem.addConstraint(ogr, 'RS')

resenje = problem.getSolutions()

max_zarada = 0
max_R = 0
max_S = 0

for r in resenje:
	if max_zarada < r['R']*200 + r['S']*80:
		max_zarada = r['R']*200 + r['S']*80
		max_R = r['R']
		max_S = r['S']

print("Maksimalna zarada je: {}, broj racunara: {}, broj stampaca: {}".format(max_zarada, max_R, max_S))
