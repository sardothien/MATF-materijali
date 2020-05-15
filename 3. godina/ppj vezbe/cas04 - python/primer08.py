# Napisati python-skript koji stampa na standardni izraz autora 
# (-a), cenu (-c), izdavaca (-i) ili godinu izdanja (-g) knjige
# koja se navodi kao argument komande linije, u zavisnosti od
# prisutne opcije komandne linije (u slucaju da nema opcija, 
# ispisati sve podatke o trazenoj knjizi). Informacije o knjigama 
# se nalaze u fajlu knjige.xml.

import sys, re

if len(sys.argv) < 2:
    print 'Greska'
    sys.exit()

try: 
    f = open("knjige.xml", "r")
except IOError:
    print 'Neuspesno otvaranje datoteke za citanje'
    
sadrzaj = f.read()
f.close()

trazim_autora = False
trazim_izdavaca = False
trazim_godinu_izdanja = False
trazim_cenu = False
trazim_sve = False
ime_knjige = ''

for arg in sys.argv[1:]:
    if arg == "-a":
        trazim_autora = True
    elif arg == "-c":
        trazim_cenu = True
    elif arg == "-g":
        trazim_godinu_izdanja = True
    elif arg == "-i":
        trazim_izdavaca = True
    else:
        ime_knjige = arg         
            
if ime_knjige == '':
    print 'Nije unet naziv knjige'
    sys.exit()
    
if not trazim_autora and not trazim_cenu and not trazim_godinu_izdanja and not trazim_izdavaca:
    trazim_sve = True
    
pattern1 = re.compile(r'<knjiga\s+rbr\s*=\s*"(\d+)"\s*>\s*', re.I) # naziv knjige
pattern2 = re.compile(r'<(naslov|autor|godina_izdanja|izdavac)>\s*([^<]+)\s*</\1>\s*', re.I) # vrsta taga
pattern3 = re.compile(r'<cena\s+valuta\s*=\s*"((rsd)|(eur))"\s*>\s*([^<]+)\s*</cena>\s*', re.I) # tag za cenu

mapa = {}
for m in pattern1.finditer(sadrzaj):
    m_next = pattern1.search(sadrzaj, m.end())
    if m_next is None:
        tmp = len(sadrzaj)
    else:
        tmp = m_next.start()
    for i in pattern2.finditer(sadrzaj, m.end(), tmp):
        if i is not None:
            if i.group(1) == "naslov":
                naslov = i.group(2).strip()
            elif i.group(1) == "autor":
                autor = i.group(2).strip()
            elif i.group(1) == "izdavac":
                izdavac = i.group(2).strip()
            elif i.group(1) == "godina_izdanja":
                godina_izdanja = i.group(2).strip()
        else:
            print 'Nema informacije o knjizi'
            sys.exit()
        
    i = pattern3.search(sadrzaj, m.end(), tmp)
    if i is None:
        print 'Nema cene'
        sys.exit()
    else:
        cena = i.group(4) + i.group(1)
            
    mapa[naslov] = (autor, izdavac, godina_izdanja, cena)
        
for k, v in mapa.iteritems():
    if k == ime_knjige:
        if trazim_sve:
            print k, v
        if trazim_autora:
            print v[0]
        if trazim_izdavaca:
            print v[1]
        if trazim_godinu_izdanja:
            print v[2]
        if trazim_cenu:
            print v[3]
