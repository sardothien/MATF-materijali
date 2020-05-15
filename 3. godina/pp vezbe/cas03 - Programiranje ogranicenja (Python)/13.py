# Napisati program koji rasporedjuje 8 dama na sahovsku
# tablu tako da se nikoje dve dame ne napadaju.

import constraint, math

problem = constraint.Problem()

problem.addVariables("12345678", range(1,9))

problem.addConstraint(constraint.AllDifferentConstraint())

for k1 in range(1,9):
    for k2 in range(1,9):
        if k1 < k2:
            def ogr(vrsta1, vrsta2, kolona1 = k1, kolona2 = k2):
                if math.fabs(vrsta1 - vrsta2) != math.fabs(kolona1 - kolona2):
                    return True
            problem.addConstraint(ogr, [str(k1), str(k2)])

resenje = problem.getSolutions()

print("Broj resenja: {}".format(len(resenje)))

for r in resenje:
    print("===========")
    for i in "12345678":
        for j in range(1,9):
            if r[i] == j:
                print("D", end='')
            else:
                print("-", end='')
        print("")
    print("===========")