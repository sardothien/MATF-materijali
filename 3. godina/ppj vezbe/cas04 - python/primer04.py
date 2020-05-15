import sys, re

if (len(sys.argv) != 1):
    print 'Greska!'
    sys.exit()
    
try:
    with open('ulaz.txt', 'r') as f:
        data = f.read()
        quotes = data.split(";;")
        print 'Podaci su ucitani :)'
except IOError:
    print 'Neuspesno otvaranje datoteke'
    
try:
    with open('izlaz.xml', 'w') as f:
        f.write("<tesla-quotes>\n")
        for q in quotes:
            f.write("\t<item>{}</item>\n".format(q))
        f.write("</tesla-quotes>")
except IOError:
    print 'Neuspesno otvaranje datoteke za pisanje'
    
print 'Generisana je datoteka {}'.format('izlaz.xml')
