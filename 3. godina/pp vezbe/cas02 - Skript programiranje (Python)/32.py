# Korisnik na standardni ulaz unosi dve niske. Napisati program
# koji prvo pojavljivanje druge niske u prvoj zamenjuje karakterom
# $. U slucaju da nema pojavljivanja druge niske u prvoj i da je 
# druga niska kraca ispisuje nadovezane niske sa separatorom -.
# Ako je druga niska duza od prve program treba da ispise drugu
# i njenu duzinu.

niska1 = input("Unesite prvu nisku: ")
niska2 = input("Unesite drugu nisku: ")

if len(niska1) >= len(niska2):
    n = niska1.count(niska2) # koliko puta se niska2 javlja u niska1
    if n > 0:
        i = niska1.find(niska2) # pozicija prvog pojavljivanja
        niska1 = niska1[0:i] + '$' + niska1[i+len(niska2):]
        print(niska1)
    else:
        print('-'.join([niska1, niska2])) # spaja niske separatorom '-'
else:
    print("Duzina niske {} je {}".format(niska2, len(niska2)))