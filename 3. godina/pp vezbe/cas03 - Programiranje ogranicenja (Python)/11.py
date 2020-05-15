# Kompanija Start ima 250 zaposlenih radnika. Rukovodstvo kompanije
# je odlucilo da svojim radnicima obezbedi dodatnu edukaciju. Da bi 
# se radnik obucio programskom jeziku Elixir potrebno je platiti 
# 100 evra po osobi za kurs, ali bi njegovo produktivno znanje ovog
# programskog jezika donelo 150 projekat/sati mesecno, sto bi za 
# kompaniju znacilo dobit od 5 evra po projekat/satu. Da bi se 
# radnik obucio programskom jeziku Dart potrebno je platiti 105 evra 
# po osobi za kurs, ali bi njegovo produktivno znanje ovog programskog
# jezika donelo 170 projekat/sati mesecno, koji bi za kompaniju znacili
# dobit od 6 evra po satu. Ukoliko Start ima na raspolaganju 26000 evra
# za obuku i maksimalan broj 51200 mogucih projekat/sati mesecno, odrediti
# na koji nacin kompanija treba da obuci svoje zaposlene kako bi ostvarila 
# maksimalnu dobit.

import constraint

problem = constraint.Problem()

problem.addVariables('ED', range(0,251))

def ukupno_radnika(e, d):
    if e + d == 250:
        return True

def ogr_projekat_sati(e, d):
    if 150*e + 170*d <= 51200:
        return True

def ogr_sredstava(e, d):
    if 100*e + 105*d <= 26000:
        return True

problem.addConstraint(ogr_projekat_sati, 'ED')
problem.addConstraint(ogr_sredstava, 'ED')
problem.addConstraint(ukupno_radnika, 'ED')

resenje = problem.getSolutions()

maxE = 0
maxD = 0

for r in resenje:
    if 150*5*r['E'] + 170*6*r['D'] - (100*r['E'] + 105*r['D']) > 150*5*maxE + 170*6*maxD - (100*maxE + 105*maxD):
        maxE = r['E']
        maxD = r['D']

print("Max zarada: {}, Elixir: {}, Dart: {}".format(170*6*maxE + 150*5*maxD - (100*maxE + 150*maxD), maxE, maxD))