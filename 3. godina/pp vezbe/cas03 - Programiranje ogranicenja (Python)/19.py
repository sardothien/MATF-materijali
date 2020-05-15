# Napisati program koji ucitava ceo broj n i ispisuje magicnu 
# sekvencu S brojeva od 0 do n-1. S = (x_0, x_1,..., x_n-1) 
# je magicna sekvenca ako postoji x_i pojavljivanja broja i
# za i = 0, 1,..., n-1.

import constraint

def magicna(s):
    n = len(s)
    for i in range(n):
        if s.count(i) != s[i]:
            return False
    return True

problem = constraint.Problem()

n = int(input("Unesite duzinu magicne sekvence: "))

for i in range(n):
    problem.addVariable('X'+str(i), range(n))

resenje = problem.getSolutions()

id = 0
for r in resenje:
	s = []
	for kljuc in r:
		s.append(r[kljuc])
	if magicna(s):
		id = 1
		print(s)

if id==0:
	print("Ne postoji magicna sekvenca duzine " + str(n))