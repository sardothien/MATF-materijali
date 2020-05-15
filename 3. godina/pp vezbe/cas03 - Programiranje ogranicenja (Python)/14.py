# Napisati program koji ucitava tablu za Sudoku iz datoteke
# cije ime se zadaje sa standardnog ulaza i koriscenjem
# ogranicenja resava Sudoku zagonetka.

import constraint, json

problem = constraint.Problem()

# Dodajemo promenljive za svaki red
for i in range(1,10):
    problem.addVariables(range(i*10+1, i*10+10), range(1,10))

# Dodajemo ogranicenja za vrste
for i in range(1,10):
    problem.addConstraint(constraint.AllDifferentConstraint(), range(i*10+1, i*10+10))

# Dodajemo ogranicenja za kolone
for i in range(1,10):
    problem.addConstraint(constraint.AllDifferentConstraint(), range(10+i, 100+i, 10))

# Dodajemo ogranicenja za kvadrate
for i in [1,4,7]:
    for j in [1,4,7]:
        poz = [10*i+j, 10*i+j+1, 10*i+j+2, 10*(i+1)+j, 10*(i+1)+j+1, 10*(i+1)+j+2, 10*(i+2)+j, 10*(i+2)+j+1, 10*(i+2)+j+2]
        problem.addConstraint(constraint.AllDifferentConstraint(), poz)

ulaz = input('Unesite ime datoteke: ')
f = open(ulaz, "r")
tabla = json.load(f)
f.close()

# Dodajemo ogranicenja za svaki broj u tabli
for i in range(9):
    for j in range(9):
        if tabla[i][j] != 0:
            def ogr(vr_prom, vr_na_tabli = tabla[i][j]):
                if vr_na_tabli == vr_prom:
                    return True

            problem.addConstraint(ogr, [((i+1)*10 + (j+1))])

resenje = problem.getSolutions()

for r in resenje: 
    print(" ================== ") 
    for i in range(1 ,10): 
        print("|", end='') 
        for j in range(1 ,10): 
            if j%3 == 0: 
                print(str(r[i*10+j])+" | ", end='') 
            else: 
                print(str(r[i*10+j]), end='') 
        print("") 
        if i%3 == 0 and i != 9: 
            print(" ------------------") 
    print(" ================== ")