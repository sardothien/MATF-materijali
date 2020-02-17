import sys, re, os

recenica = "Danas je lep dan sunce sija dan je divan"

m = re.match(r"d([a-z])+", recenica)
#m = re.match(r"(?i)(\w+\s*)", recenica)
m = re.search(r"d[a-z]+", recenica)

#if m is None:
    #print 'Nema'
#else:
    #print(m.group())
    #print(recenica[m.start():m.end()])
    #recenica = recenica[m.end():]
    #m = re.search(r"d[a-z]+", recenica)
    #if m is None:
        #print 'Nema'
    #else:
        #print(m.group())

m = re.findall(r"d[a-z]+", recenica)
for x in m:
    print(x)
