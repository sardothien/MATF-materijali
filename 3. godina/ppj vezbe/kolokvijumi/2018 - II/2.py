import sys

stanje = 0
zavrsna = [1, 2]
prelazi = {
    0: {'a':0, 'b':1, 'c':0},
    1: {'b':1, 'c':2},
    2: {'c':2}
}

while True:
    try:
        c = input()
        if c != 'a' and c != 'b' and c != 'c':
            raise ValueError('Nekorektan karakter na ulazu')
        if c not in prelazi[stanje].keys():
            print 'Automat ne prihvata unetu rec'
            exit(1)
        else:
            stanje = prelazi[stanje][c]
            rec += c
    except EOFError:
        break
    except ValueError as e:
        exit(e)
        
if stanje in zavrsna:
    print 'Rec je prihvacena'
else:
    print 'Rec nije prihvacena'
