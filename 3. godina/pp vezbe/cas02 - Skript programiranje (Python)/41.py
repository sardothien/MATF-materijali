# Napisati program koji imitira rad komande ls. Program na 
# standardni izlaz ispisuje sadrzaj tekuceg direktorijuma.

import os

# ispisivanje liste imena svih fajlova u datom direktorijumu
print(os.listdir(os.curdir))

for (trendir, poddir, datoteke) in os.walk(os.curdir):
    print(trendir)
    for dat in datoteke:
        print(os.path.join(trendir, dat))