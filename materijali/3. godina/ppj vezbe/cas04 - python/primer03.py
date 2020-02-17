# Napisati skript koji rezultate sa ispita iz datoteke 
# rezultati_ispita.html ispisuje na standardni izlaz,
# sortirano po ukupnom broju poena neopadajuce.
# Poeni sa pismenog se skaliraju sa intervala
# [0, 100] na interval [0, 60], a poeni sa usmenog sa
# intervala [0, 100] na interval [0, 40]. Njihov zbir 
# daje ukupan broj poena.

import sys, re

if (len(sys.argv) == 1) or (re.match(r".*\.html", sys.argv[1]) is None):
    print 'Neispravno!'
    sys.exit()
#else:
    #print 'Uspeh!'
    
try:
    ulaz = open(sys.argv[1], "r")
    data = ulaz.read()
    #print data
except IOError:
    print 'Neuspesno otvaranje datoteke'
    
pattern = r"<tr>\s*"
pattern += r"<td>\s*(?P<ime>[a-zA-Z]+\s+[a-zA-Z]+)\s*</td>\s*" 
pattern += r"<td>\s*(?P<pismeni>\d+)\s*</td>\s*" 
pattern += r"<td>\s*(?P<usmeni>\d+)\s*</td>\s*" 
pattern += r"</tr>" 

re_comp = re.compile(pattern, re.VERBOSE)

studenti = []

for x in re_comp.finditer(data):
    pismeni = float(x.group('pismeni'))
    pismeni = pismeni/100 * 60.0
    usmeni = float(x.group('usmeni'))
    usmeni = usmeni/100 * 40.0
    studenti.append({
            'ime': x.group('ime'),
            'pismeni': pismeni,
            'usmeni': usmeni,
            'ukupno': pismeni+usmeni
    })
    
# for student in studenti:
        # print(student['ime'], student['pismeni'], student['usmeni'], student['ukupno'])
        
def poredjenje(student):
        return student['ukupno']
    
studenti.sort(key = poredjenje, reverse=False)

for i, student in enumerate(studenti):
    print(i+1, student['ime'], student['ukupno'])
    
ulaz.close()
