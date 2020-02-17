import sys, re

if len(sys.argv) < 2:
    exit('Neispravan broj argumenata')
    
trazim_sve = False
trazim_info = False
trazim_i = False
trazim_p = False
ime = ""
rec = ""

for a in sys.argv[1:]:
    if a == "-sve":
        trazim_sve = True
    elif a == "-i":
        trazim_i = True
    elif a == "-p":
        trazim_p = True
    elif a == "-info":
        trazim_info = True
    else:
        if trazim_info == True:
            rec = a
        else:
            ime = a
            
try:
    with open("igre.xml", 'r') as f:
        data = f.read()
except IOError:
    exit('Neuspesno otvaranje datoteke')
    
pattern = re.compile(r'<igra\s+id\s*=\s*"(\d+)"\s*>')
pattern1 = re.compile(r"<naziv>\s*(([a-zA-Z0-9,.:'()]+ ?)+)\s*</naziv>") # 1. Naziv
pattern2 = re.compile(r'<godina>\s*((19[5-9][0-9])|(20[0-1][0-9]))\s*</godina>') # 2. Godina
pattern3 = re.compile(r'<izdavac>\s*(([0-9A-Z][a-zA-Z0-9]* ?)+)\s*</izdavac>') # 3. Izdavac
pattern4 = re.compile(r'<platforme>\s*((PlayStation|Xbox|PC|Nintendo)(,\s*(PlayStation|Xbox|PC|Nintendo))*)\s*</platforme>') # 4. Platforme
pattern5 = re.compile(r'<ocena>\s*((10\.0)|([1-9]\.[0-9]))\s*</ocena>') # 5. Ocena

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
        godina = i.group(1)
    else:
        naziv = "neispravan"
        
    i = pattern3.search(data, m.end(), tmp)
    if i is not None:
        izdavac = i.group(1)
    else:
        naziv = "neispravan"
        
    i = pattern4.search(data, m.end(), tmp)
    if i is not None:
        platforme = i.group(1)
    else:
        naziv = "neispravan"
    
    i = pattern5.search(data, m.end(), tmp)
    if i is not None:
        ocena = i.group(1)
    else:
        naziv = "neispravan"
        
    mapa[naziv] = (godina, izdavac, platforme, ocena)
    
#del mapa["neispravan"]
#print mapa

if trazim_sve:
    keys = mapa.keys()
    keys.sort()
    for k in keys:
        print(k)
else:
    if trazim_info:
        for k in mapa.keys():
            if re.search(r''+rec, k, re.I) is not None:
                print k + " (" + mapa[k][3] + "/10)"
    if trazim_i:
        for k in mapa.keys():
            if mapa[k][1] == ime:
                print k + " (" + mapa[k][0] + ")"
    if trazim_p:
        for k in mapa.keys():
            if ime in mapa[k][2]:
                print k
