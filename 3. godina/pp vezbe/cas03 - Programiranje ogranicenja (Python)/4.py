# Napisati program koji redja brojeve u magican kvadrat. Magican
# kvadrat je kvadrat dimenzija 3x3 takav da je suma svih brojeva
# u svakom redu, svakoj koloni i svakoj dijagonali jednak 15 i 
# svi brojevi razliciti.

import constraint

def ogranicenje(x, y, z):
    if x + y + z == 15:
        return True

problem = constraint.Problem()

problem.addVariables("abcdefghi", range(1, 10))

problem.addConstraint(constraint.AllDifferentConstraint())

# Ogranicenja za svaku vrstu
problem.addConstraint(ogranicenje, "abc")
problem.addConstraint(ogranicenje, "def")
problem.addConstraint(ogranicenje, "ghi")
# Ogranicenje za svaku kolonu
problem.addConstraint(ogranicenje, "adg")
problem.addConstraint(ogranicenje, "beh")
problem.addConstraint(ogranicenje, "cfi")
# Ogranicenje za dijagonale
problem.addConstraint(ogranicenje, "aei")
problem.addConstraint(ogranicenje, "ceg")

resenje = problem.getSolutions()

for r in resenje:
    print("-------------")
    print("{0:d} {1:d} {2:d}".format(r['a'], r['b'], r['c']))
    print("{0:d} {1:d} {2:d}".format(r['d'], r['e'], r['f']))
    print("{0:d} {1:d} {2:d}".format(r['g'], r['h'], r['i']))