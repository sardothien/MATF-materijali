# Napisati program koji pronalazi vrednosti 
# A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S koje su 
# poredjane u heksagon na sledeci nacin:
#   A B C
#  D E F G
# H I J K L
#  M N O P
#   Q R S
# tako da zbir vrednosti duz svake horizontalne i
# dijagonalne linije bude 38.

import constraint

problem = constraint.Problem()

problem.addVariables('ABCDEFGHIJKLMNOPQRS', range(1,38))

def ogr1(a, b, c):
    if a + b + c == 38:
        return True

def ogr2(a, b, c, d):
    if a + b + c + d == 38:
        return True

def ogr3(a, b, c, d, e):
    if a + b + c + d + e == 38:
        return True

problem.addConstraint(constraint.AllDifferentConstraint())

# Ogranicenja za horizontalne linije:
problem.addConstraint(ogr1, 'ABC')
problem.addConstraint(ogr1, 'QRS')
problem.addConstraint(ogr2, 'DEFG')
problem.addConstraint(ogr2, 'MNOP')
problem.addConstraint(ogr3, 'HIJKL')

# Ogranicenja za dijagonale:
problem.addConstraint(ogr1, 'HMQ')
problem.addConstraint(ogr1, 'ADH')
problem.addConstraint(ogr1, 'CGL')
problem.addConstraint(ogr1, 'LPS')
problem.addConstraint(ogr2, 'DINR')
problem.addConstraint(ogr2, 'BFKP')
problem.addConstraint(ogr2, 'BEIM')
problem.addConstraint(ogr2, 'GKOR')
problem.addConstraint(ogr3, 'AEJOS')
problem.addConstraint(ogr3, 'CFJNQ')

resenje = problem.getSolutions()

for r in resenje:
    print("-----------------") 
    print(" {0:d} ,{1:d} ,{2:d}".format(r['A'],r['B'],r['C'])) 
    print(" {0:d} ,{1:d} ,{2:d} ,{3:d}".format(r['D'],r['E'],r['F'],r['G'])) 
    print("{0:d} ,{1:d} ,{2:d} ,{3:d} ,{4:d}".format(r['H'],r['I'],r['J'],r['K'],r['L'])) 
    print(" {0:d} ,{1:d} ,{2:d} ,{3:d}".format(r['M'],r['N'],r['O'],r['P'])) 
    print(" {0:d} ,{1:d} ,{2:d}".format(r['Q'],r['R'],r['S'])) 
    print(" -----------------")