# Napisati program koji pronalazi sve vrednosti promenljivih 
# X,Y,Z za koje vazi da je X >= Z i 2*X + Y*X + Z <= 34 pri
# cemu promenljive pripadaju narednim domenima X = {1,...,90},
# Y = {2, 4,..., 60} i Z = {1, 4, 9,..., 100}.

import constraint

problem = constraint.Problem()

problem.addVariable('X', range(1, 91))
problem.addVariable('Y', range(2, 60, 2))

domenZ = []
for i in range(1, 11):
    domenZ.append(i**2)
problem.addVariable('Z', domenZ)

def ogr1(x, z):
    if x >= z:
        return True
    
def ogr2(x, y, z):
    if 2*x + x*y + z <= 34:
        return True

problem.addConstraint(ogr1, 'XY')
problem.addConstraint(ogr2, 'XYZ')

resenje = problem.getSolutions()

for r in resenje:
    print("-----------------------")
    print("X = {}, Y = {}, Z = {}".format(r['X'], r['Y'], r['Z']))