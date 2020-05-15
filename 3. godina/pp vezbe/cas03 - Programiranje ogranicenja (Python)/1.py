# Napisati program koji na standardni izlaz ispisuje sve
# kombinacije oblika xyz, gde je x = {a,b,c}, y = {1,2,3},
# z = {0.1, 0.2, 0.3} tako da vazi da je 10*z = y.

import constraint

# Definisemo problem
problem = constraint.Problem()

# Dodajemo promenljive
problem.addVariable('x', ['a', 'b', 'c'])
problem.addVariable('y', [1, 2, 3])
problem.addVariable('z', [0.1, 0.2, 0.3])

# Ogranicenje
def ogranicenje(y, z):
    if y / 10.0 == z:
        return True

problem.addConstraint(ogranicenje, ['y', 'z'])

resenje = problem.getSolutions()
for r in resenje:
    print(str(r['x']) + ' ' + str(r['y']) + ' ' + str(r['z']))