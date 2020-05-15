# Napisati program koji rasporedjuje brojeve 1-9 u dve 
# linije koje se seku u jednom broju. Svaka linija sadrzi 
# 5 brojeva takvih da je njihova suma u obe linije 25 i 
# brojevi su u rastucem redosledu.

import constraint

problem = constraint.Problem()

problem.addVariables('abcdefghi', range(1, 10))

def ogranicenje(a, b, c, d, e):
    if a < b < c < d < e and a + b + c + d + e == 25:
        return True

# Ogranicenje za linije
problem.addConstraint(ogranicenje, 'abcde')
problem.addConstraint(ogranicenje, 'fgchi')
problem.addConstraint(constraint.AllDifferentConstraint())

resenje = problem.getSolutions()

for r in resenje:
    print("--------------------")
    print("{}      {}".format(r['a'], r['f']))
    print("  {}  {}  ".format(r['b'], r['g']))
    print("    {}    ".format(r['c']))
    print("  {}  {}  ".format(r['h'], r['d']))
    print("{}      {}".format(r['i'], r['e']))