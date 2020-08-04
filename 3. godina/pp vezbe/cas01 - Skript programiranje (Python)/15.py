# Napisati program koji imitira rad bafera. Maksimalan broj elemenata
# u baferu je 5. Korisnik sa standardnog ulaza unosi podatke do unosa 
# reci quit. Program ih smesta u bafer, posto se bafer napuni unosi se
# ispisuju na standardni izlaz i bafer se prazni.

buffer = []

i = 0
while True:
    unos = input()

    if unos == 'quit':
        break

    buffer.append(unos)
    
    i += 1
    if i == 5:
        for unos in buffer:
            print(unos)
        buffer = []
        i = 0