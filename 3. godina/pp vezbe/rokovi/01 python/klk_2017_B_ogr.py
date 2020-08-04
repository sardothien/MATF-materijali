# Napisati Python program koji dodeljuje razlicite vrednosti
# razlicitim karakterima tako da sledeci izraz bude zadovoljen:
#    TWO
#  * TWO
#  + EIGHT
# = TWELVE

import constraint

problem = constraint.Problem()

problem.addVariables("TE", range(1, 10))
problem.addVariables("WOIGHLV", range(0, 10))

problem.addConstraint(constraint.allDifferentConstraint())

def ogr(t, w, o, e, i, g, h, l, v):
    return (100*t + 10*w + e)*(100*t + 10*w + e) + (10000*e + 1000*i + 100*g + 10*h + t) == (100000*t + 10000*w + 1000*e + 100*l + 10*v + e)

problem.addConstraint(ogr, "TWOEIGHLV")

resenje = problem.getSolutions()

for r in resenje:
    two = 100*r['T'] + 10*r['W'] + r['O']
    eight = 10000*r['E'] + 1000*r['I'] + 100*r['G'] + 10*r['H'] + r['T']
    twelve = 100000*r['T'] + 10000*r['W'] + 1000*r['E'] + 100*r['L'] + 10*r['V'] + r['E']
    print "{0:d} * {1:d} + {2:d} = {3:d}".format(two, two, eight, twelve)