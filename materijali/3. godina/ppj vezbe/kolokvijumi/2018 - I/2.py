import sys

user_input = ""

print('Unesite cifru po cifru: ')

stanje = 1
zavrsna = [4,5]
prelaz = {
    (1,0): 2,
    (1,1): 3,
    (2,0): 4,
    (2,1): 3,
    (3,0): 2,
    (3,1): 5,
    (4,0): 4,
    (4,1): 3,
    (5,0): 2,
    (5,1): 5
}

while True:
    try:
        c = input()
        user_input += c
        c = int(c)
        if c != 0 and c != 1:
            raise ValueError('Nekorektan unos')
    except EOFError:
        break
    except ValueError as e:
        print(e)
        sys.exit(1)
        
    stanje = prelaz[(stanje, c)]
    print("Trenutno stanje: {}".format(stanje))
    
print ("Korisnicki unos: ", user_input)
if stanje in zavrsna:
    print 'Ulaz je dobar'
else:
    print 'Greska pri ulazu'
