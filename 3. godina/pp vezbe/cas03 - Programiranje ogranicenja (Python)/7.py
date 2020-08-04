# Napisati program koji pronalazi sve vrednosti promenljivih 
# X,Y,Z,W za koje vazi da je X >= 2*W, 3+Y <= Z i
# X - 11*W + Y + 11*Z <= 100 pri cemu promenljive pripadaju
# narednim domenima X = {1, 2,...,10}, Y = {1, 3, 5,...,51},
# Z = {10, 20,..., 100} i W = {1, 8, 27,...,1000}.

import constraint

problem = constraint.Problem()

problem.addVariable('X', range(1,11))
problem.addVariable('Y', range(1,52,2))
problem.addVariable('Z', range(10, 101, 10))

domenW = []
for i in range(1,11):
    domenW.append(i**3)
problem.addVariable('W', domenW)

def ogr1(x, w):
    if x >= 2*w:
        return True
    
def ogr2(y, z):
    if 3 + y <= z:
        return True

def ogr3(x, y, z, w):
    if x - 11*w + y + 11*z <= 100:
        return True

problem.addConstraint(ogr1, 'XW')
problem.addConstraint(ogr2, 'YZ')
problem.addConstraint(ogr3, 'XYZW')

resenje = problem.getSolutions()

for r in resenje:
    print("----------------------")
    print("X = {}, Y = {}, Z = {}, W = {}".format(r['X'], r['Y'], r['Z'], r['W']))