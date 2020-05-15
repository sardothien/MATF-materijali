# Napisati program koji dodaje u datoteku dat.txt nisku
# water a potom ispisuje njen sadrzaj na standardni izlaz.

try:
    with open('dat.txt', 'a+') as datoteka:
        datoteka.write("water\n")
        datoteka.seek(0, 0)
        print(datoteka.readlines())
except FileNotFoundError:
    print("Datoteka ne postoji!")
    exit(1)