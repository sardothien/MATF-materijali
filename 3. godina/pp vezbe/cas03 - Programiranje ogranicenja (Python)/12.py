# Napisati program koji rasporedjuje 8 topova na sahovsku
# tablu tako da se nikoja dva topa ne napadaju.

import constraint

problem = constraint.Problem()

problem.addVariables("12345678", range(1,9))

problem.addConstraint(constraint.AllDifferentConstraint())

resenje = problem.getSolutions()

print("Broj resenja: {}".format(len(resenje)))

for r in resenje:
    print("===========")
    for i in "12345678":
        for j in range(1,9):
            if r[i] == j:
                print("T", end='')
            else:
                print("-", end='')
        print("")
    print("===========")