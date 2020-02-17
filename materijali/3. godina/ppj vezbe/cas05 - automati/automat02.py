# Program implementira automat koji odgovara
# regularnom izrazu (ab?)+(b?a+b)*

# U mapi se cuva matrica prelaza, pri cemu se za kljuc mape uzima 
# stanje, a vrednost je ponovo mapa oblika slovo->novo_stanje.
# Nakon primene algoritma Gluskova da dobijemo automat, potom postupka
# determinizacije i minimizacije dobija se MDKA sa tablicom 'prelaz'.
#import sys

prelaz = {'A': {'a':'BC'},
          'BC': {'a':'BC', 'b':'DE'},
          'DE': {'a':'BC', 'b':'F'},
          'F': {'a':'G'},
          'G': {'a':'G', 'b':'H'},
          'H': {'a': 'G', 'b':'F'}}

pocetno = 'A'
zavrsna = ('BC', 'DE', 'H')

stanje = pocetno

rec = input('Unesite celu rec: ')
for c in rec:
    try:
        if c != 'a' and c != 'b':
            raise ValueError
        
        if c in prelaz[stanje]:
            stanje = prelaz[stanje][c]
        else:
            exit('Rec ne moze biti prihvacena automatom')
            
        print('\tStanje: ', stanje)
        
    except EOFError:
        break
    except ValueError:
        exit('Podrzana slova su a i b.')
        
if stanje in zavrsna:
    print 'Automat prihvata rec'
else:
    print 'Automat ne prohvata rec'
