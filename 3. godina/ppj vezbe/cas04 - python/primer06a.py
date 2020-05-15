# Skript prati linkove navedene u HTML datoteci 
# i vodi evidenciju o datotekama koje su posecene.
import sys, re

def obradi_datoteku(ime):
    if (ime in obradjene_datoteke):
        return
    
    obradjene_datoteke.append(ime)
    
    try:
        with open(ime, 'r') as f:
            datoteka = f.read()
    except IOError:
        exit(1)
        
    ri = re.compile(r'<a\s+href\s*=\s*"(.*?)">.*?</a>', re.I | re.S)
    
    for m in ri.finditer(datoteka):
       obradi_datoteku(m.group(1))
       
if len(sys.argv) > 1:
    pocetna = sys.argv[1]
else:
    pocetna = "index.html"
    
obradjene_datoteke = []
obradi_datoteku(pocetna)

for datoteka in obradjene_datoteke:
    print datoteka
