# Skript obradjuje html datoteke dostupne iz
# polazne html datoteke (preko linkova) i 
# racuna popularnost svake od datoteka, na osnovu
# broja linkova.
import re

def obradi_datoteku(ime):
    if(ime in obradjene_datoteke):
        return
    
    obradjene_datoteke.append(ime)
    
    try:
        with open(ime, 'r') as f:
            data = f.read()
    except IOError:
        exit(1)
        
    ri = re.compile(r'<a\s+href\s*=\s*"([^"]+)">(.*?)</a>', re.I | re.S)
    for m in ri.finditer(data):
        tekst = m.group(2)
        url = m.group(1)
        
        if url not in popularnost:
            popularnost[url] = 1
        else:
            popularnost[url] += 1
            
        obradi_datoteku(url)
        
obradjene_datoteke = []
popularnost = {}
obradi_datoteku("prva.html")

popd = list(popularnost.items())
popd.sort(reverse = True, key = lambda t : t[1])

for no, url in popd:
    print(url, "\t", no)
