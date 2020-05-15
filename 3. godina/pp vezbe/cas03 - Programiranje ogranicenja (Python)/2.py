# Napisati program koji pronalazi trocifreni broj ABC tako da je
# kolicnik ABC / (A+B+C) minimalan i A,B,C su razliciti brojevi.

import constraint

problem = constraint.Problem()

problem.addVariable('A', range(1, 10))
problem.addVariable('B', range(0, 10))
problem.addVariable('C', range(0, 10))

problem.addConstraint(constraint.AllDifferentConstraint())

resenje = problem.getSolutions()

min_kolicnik = 999
min_resenje = {}
for r in resenje:
    a = r['A']
    b = r['B']
    c = r['C']
    kolicnik = (a*100 + b*10 + c) / (a + b + c)

    if kolicnik < min_kolicnik:
        min_kolicnik = kolicnik
        min_resenje = r

print(min_resenje['A']*100 + min_resenje['B']*10 + min_resenje['C'])