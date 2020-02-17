# Napisati python-skript koji kao prvi argument komandne 
# linije prihvata ime fajla koji je dobijen sistemom UNITEX
# kao rezultat prepoznavanja imenovanih entiteta. Na osnovu 
# tog fajla treba napraviti .xml fajl koji je dobijen zamenom
# semantickih markera odgovarajucim tagom (+org se menja tagom)

import sys, re

if (len(sys.argv) != 2):
    print 'Greska!'
    sys.exit()
 
with open(sys.argv[1], 'r') as f:
    data = f.read()
    
print 'Prepoznati tokeni:'
pattern = r"{(.*?)[.]NE\+([a-zA-Z]+):\d+[a-z]+}"

ri = re.compile(pattern, re.DOTALL)
for i in ri.finditer(data):
    print(i)
    
# vrsimo zamenu u tekstu
new = re.sub(ri, r"<\2>\1<\2>", data)

with open('izlaz07.xml', 'w') as f:
    f.write('<xml>\n')
    f.write(new)
    f.write('</xml>')
    print 'Rezultat je upisan u datoteku izlaz07.xml'
