# Napisati program koji definise praznu (bez tela) funkciju tri argumenta,
# kvadratnu funkciju, kao i funkciju translacije, koja prosledjeni argument
# umanjuje za jedan. Ilustrovati kompoziciju kvadratne funkcije i translacije.
# Funkciju kvadriranja definisati kao anonimnu funkciju.

def prazna(x, y, z):
    pass

def kvadrat(x):
    "Funkcija vraca kvadrat broj"
    return x**2

def translacija(x):
    "Funkcija vraca dati broj umanjen za 1"
    x = x-1
    return x

print(prazna(1, 2, 3))

print(kvadrat(6))
print(help(kvadrat))

print(translacija(4))
print(help(translacija))

# Anonimna f-ja
suma = lambda x, y: x+y
print(suma(1, 3))
# print(suma)