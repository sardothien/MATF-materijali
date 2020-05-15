# Napisati program koji ispisuje sadrzaj datoteke dat.txt
# na standardni izlaz karakter po karakter.

try:
    with open("dat.txt", 'r') as datoteka:
        for linija in datoteka:
            for karakter in linija:
                print(karakter, end = '')
except FileNotFoundError:
    print("Datoteka ne postoji!")
    exit(1)