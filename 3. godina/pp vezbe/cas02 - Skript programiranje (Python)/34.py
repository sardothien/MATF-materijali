# Napisati program koji ispisuje sadrzaj datoteke dat.txt na
# standardni izlaz liniju po liniju.

try:
    with open('dat.txt', 'r') as datoteka:
        for linija in datoteka:
            print(linija)
except FileNotFoundError:
    print("Datoteka ne postoji!")
    exit(1)