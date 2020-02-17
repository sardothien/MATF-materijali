# Program implementira automat za prepoznavanje 
# ulaza sa parnim brojem 0. Prelasci se odredjuju
# naredbama granjanja.
import sys

stanje = 'P'
zavrsno = 'P'
prelazi = {
    'P':{'0':'N', '1':'P'},
    'N':{'0':'P', '1':'N'}
}

while True:
    try:
        c = input('Unesite 0 ili 1:')
        if(c != '0' and c != '1'):
            raise ValueError('Nije uneta ni 0 ni 1')
    except EOFError:
        break
    except ValueError as e:
        print(e)
        exit()
        
    stanje = prelazi[stanje][c]
    
if stanje == zavrsno:
    print('Ima paran broj 0.')
else:
    print('Ima neparan broj 0.')
