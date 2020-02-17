# Izvlacimo podatke iz html datoteke. Sabira poene studenta.

import re, sys

if(len(sys.argv) == 1) or (re.match(r".*\.html", sys.argv[1]) is None):
    print 'Neispravno'
    sys.exit()
    
#print 'Uspeh!'

try:
    ulaz = open(sys.argv[1], "r")
    data = ulaz.read()
    #print(data)
except IOError:
    print 'Neuspesno otvaranje datoteke'
    
pattern = r"\s*<tr[^>]*>\s*" # 0
pattern += r"<td[^>]*>\s*(\w+)\s*</td>\s*" # 1 Ime
pattern += r"<td[^>]*>\s*(\w+)\s*</td>\s*" # 2 Prezime
pattern += r"<td[^>]*>\s*(\w+)\s*</td>\s*" # 3 Indeks
pattern += r"<td[^>]*>\s*(\d+)\s*</td>\s*" # 4 Prvi kolokvijum
pattern += r"<td[^>]*>\s*(\d+)\s*</td>\s*" # 5 Drugi kolokvijum
pattern += r"<td[^>]*>\s*(\d+)\s*</td>\s*" # 6 Treci kolokvijum
pattern += r"<td[^>]*>\s*(\d+)\s*</td>\s*" # 7 Cetvrti kolokvijum
pattern += r"</tr>" # 8

for x in re.finditer(pattern, data):
    zbir = 0
    for i in range(4, 8): # sabiramo poene
        zbir += int(x.group(i))
    print zbir
    
ulaz.close()
