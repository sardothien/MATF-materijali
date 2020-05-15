# Napisati program koji dodeljuje razlicite vrednosti razlicitim
# karakterima tako da suma bude zadovoljena: TWO + TWO = FOUR.

import constraint

problem = constraint.Problem()

problem.addVariables('TF', range(1, 10))
problem.addVariables('WOUR', range(0, 10))

def ogranicenje(t, w, o, f, u, r):
    if 2 * (100*t + 10*w + o) == 1000*f + 100*o + 10*u + r:
        return True

problem.addConstraint(constraint.AllDifferentConstraint())
problem.addConstraint(ogranicenje, "TWOFUR")

resenje = problem.getSolutions()

for r in resenje:
    print("-----------")
    print("   " + str(r['T']) + str(r['W']) + str(r['O']))
    print(" + " + str(r['T']) + str(r['W']) + str(r['O']))
    print("= " + str(r['F']) + str(r['O']) + str(r['U']) + str(r['R']))