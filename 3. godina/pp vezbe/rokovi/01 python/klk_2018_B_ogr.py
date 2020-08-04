import constraint

problem = constraint.Problem()

# ukupna energija = [2500, 3500] kcal
# min 60g proteina
# [500mg, 1000mg] kalcijuma

# ovseni obrok
problem.addVariable("O", range(1, 35))
# piletina
problem.addVariable("P", range(1, 15)) 
# jaje
problem.addVariable("J", range(1, 25))
# mleko
problem.addVariable("M", range(1, 25))
# tiramisu
problem.addVariable("T", range(1, 10))

def ogr(o, p, j, m, t):
    if (o*110 + p*205 + j*160 + m*160 + t*420 >= 2500) and (o*110 + p*205 + j*160 + m*160 + t*420 <= 3500):
        if (o*4 + p*32 + j*13 + m*8 + t*4 >= 60) and (o*2 + p*12 + j*285 + m*22 + t*22 >= 500 and o*2 + p*12 + j*285 + m*22 + t*22 <= 1000):
            if (o < 5 and p < 2 and j < 11 and m < 9 and t < 3):
                return True

    return False

problem.addConstraint(ogr, "OPJMT")

resenje = problem.getSolutions()

def cena(r):
    return r['O']*80 + r['P']*200 + r['J']*20 + r['M']*90 + r['T']*190

min = float('inf')
for r in resenje:
    if cena(r) < min:
        min = cena(r)

print(min)