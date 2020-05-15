# Dati su novcici od 1, 2, 5, 10, 20 dinara. Napisati program koji
# pronalazi sve moguce kombinacije tako da zbir svih novcica bude 50. 
# Sve rezultate ispisati na standardni izlaz koristeci datu komandu ispisa.

import constraint

problem = constraint.Problem()

problem.addVariable("1 din", range(0, 51))
problem.addVariable("2 din", range(0, 26))
problem.addVariable("5 din", range(0, 11))
problem.addVariable("10 din", range(0, 6))
problem.addVariable("20 din", range(0, 3))

problem.addConstraint(constraint.ExactSumConstraint(50, [1, 2, 5, 10, 20]), ["1 din", "2 din", "5 din", "10 din", "20 din"])

resenje = problem.getSolutions()

for r in resenje:
    print("-----------------")
    print("""1 din: {0:d}\n2 din: {1:d}\n5 din: {2:d}\n10 din: {3:d}\n20 din: {4:d}""".format(r["1 din"], r["2 din"], r["5 din"], r["10 din"], r["20 din"]))