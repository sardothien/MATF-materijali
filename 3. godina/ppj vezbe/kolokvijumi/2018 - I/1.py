import sys, re

if (len(sys.argv) < 2):
    exit('Nedovoljan broj argumenata')
    
sortiranje = False
trazim_verziju = False
trazim_veb = False
trazim_repozitorijum = False
trazim_opis = False
ime = ""

try:
    with open("paketi.xml", 'r') as f:
        data = f.read()
except IOError:
    exit('Neuspesno otvaranje datoteke')
    
for arg in sys.argv[1:]:
    if arg == "-a":
        sortiranje = True
    elif arg == "-v":
        trazim_verziju = True
    elif arg == "-w":
        trazim_veb = True
    elif arg == "-r":
        trazim_repozitorijum = True
    elif arg == "-o":
        trazim_opis = True
    else:
        ime = arg
        
if (ime == '' and sortiranje == False):
    print 'Neispravan poziv'
    exit(1)
    
pattern = re.compile(r'<paket\s+id\s*=\s*"(\d+)"\s*>')
pattern1 = re.compile(r'<naziv>\s*(\w+)\s*</naziv>\s*') # 1. Naziv paketa
pattern2 = re.compile(r'<verzija>\s*(\d+)\.(\d+)\.(\d+)\s*</verzija>') # 2. Verzija
pattern3 = re.compile(r'<opis>\s*([^<]+)\s*</opis>') # 3. Opis
pattern4 = re.compile(r'<repo>\s*((github)|(gitlab)|(bitbucket))\s*</repo>') # 4. Repozitorijum
pattern5 = re.compile(r'<veb>\s*((www\.)?(\w+\.)+((org)|(com)))\s*</veb>') # 5. Veb strana

mapa = {}
for m in pattern.finditer(data):
    m_next = pattern.search(data, m.end())
    if m_next is None:
        tmp = len(data)
    else:
        tmp = m_next.start()
        
    i = pattern1.search(data, m.end(), tmp)
    if i is not None:
        naziv = i.group(1)
    else:
        naziv = "neispravan"
        
    i = pattern2.search(data, m.end(), tmp)
    if i is not None:
        verzija = i.group(1) + "." + i.group(2) + "." + i.group(3)
    else:
        naziv = "neispravan"
        
    i = pattern3.search(data, m.end(), tmp)
    if i is not None:
        opis = i.group(1)
    else:
        naziv = "neispravan"
        
    i = pattern4.search(data, m.end(), tmp)
    if i is not None:
        repozitorijum = i.group(1)
    else:
        naziv = "neispravan"
        
    i = pattern5.search(data, m.end(), tmp)
    if i is not None:
        veb = i.group(1)
    else:
        naziv = "neispravan"
    
    mapa[naziv] = (verzija, opis, repozitorijum, veb)
    
#print mapa
del mapa["neispravan"]
#print mapa

if sortiranje:
    keys = mapa.keys()
    keys.sort()
    for k in keys:
        print '[{}] v{} {}\n{}\n{}\n'.format(k, mapa[k][0],mapa[k][2],mapa[k][3],mapa[k][1])
else:
    if trazim_opis:
        print "Opis: " + mapa[ime][1]
    if trazim_repozitorijum:
        print "Repozitorijum: " + mapa[ime][2]
    if trazim_veb:
        print "Veb: " + mapa[ime][3]
    if trazim_verziju:
        print "Verzija: " + mapa[ime][0]
