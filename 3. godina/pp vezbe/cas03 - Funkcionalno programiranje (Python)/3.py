# Marko, Petar i Pavle su polagali ispit iz predmeta
# Programske Paradigme. Napisati program koji sa 
# standardnog ulaza ucitava ocene koji su dobili,
# a potom ispisuje listu parova (student, ocena) na
# standardni izlaz.

imena = ['Marko', 'Petar', 'Pavle']
ocene = [int(input("Ocena za " + ime + ": ")) for ime in imena]

print(zip(imena, ocene)) # adresa 

for par in zip(imena, ocene):
    print(par)