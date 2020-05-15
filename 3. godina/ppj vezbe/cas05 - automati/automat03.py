# azbuka: a, b
# stanja: 0, 1, 2
# pocetno: 0
# zavrsna: 1, 2
import re

try:
    f = open("ka.txt", 'r')
except IOError:
    print "Neuspesno otvaranje fajla"
    exit(1)
    
linije = f.readlines()

def nije_komentar(l):
    return l[0] != '#' and l != '\n'

def strip(s):
    return s.strip()

linije = filter(nije_komentar, linije)
# print linije

azbuka = re.split(",\s*", linije[0])
#print azbuka

azbuka = map(strip, azbuka)
#print azbuka

stanja = re.split(",\s*", linije[1])
stanja = map(strip, stanja)
stanja = map(int, stanja)
#print stanja

pocetno_stanje = int(linije[2].strip())
#print pocetno_stanje
if (pocetno_stanje not in stanja):
    print "Neispravno pocetno_stanje"
    exit(1)
#else:
    #print "Pocetno stanje je dobro"
    
zavrsna_stanja = re.split(",\s*", linije[3])
zavrsna_stanja = map(strip, zavrsna_stanja)
zavrsna_stanja = map(int, zavrsna_stanja)
#print zavrsna_stanja
for zs in zavrsna_stanja:
    if zs not in stanja:
        exit(1)
    #else:
        #print "Zavrsno stanje je dobro"
        
prelazi = {}
linije = map(strip, linije)

for i in range(4, len(linije)):
    stanje1, slovo, stanje2 = re.split("\s+", linije[i])
    stanje1 = int(stanje1)
    stanje2 = int(stanje2)
    #print stanje1, slovo, stanje2
    
    if stanje1 not in stanja:
        exit(1)
    if stanje2 not in stanja:
        exit(1)
    if slovo not in azbuka:
        exit(1)
        
    if (stanje1, slovo) in prelazi:
        print "Automat nije DKA"
    else:
        prelazi[(stanje1, slovo)] = stanje2
        
print prelazi
