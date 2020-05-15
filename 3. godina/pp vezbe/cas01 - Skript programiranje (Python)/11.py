# Definisati funkciju printf, koja na standardni izlaz stampa svoje argumente.
# Modifikovati definisanu funkciju tako da kao argumente prima proizvoljan
# broj imenovanih argumenata. Definisati funkciju koja racuna aritmeticku
# sredinu svojih argumenata.

def printf(*x): # nepoznat broj argumenata
    print(x)

printf()
printf(12)
printf([1, 2, 3])
printf(1, 2, "translate", "printf")

def printf(**x): # proizvoljan broj imenovanih argumenata
    print(x)

printf()
printf(de = "German", en = "English", rs = "Serbian")

# -----------------------------------------------------------

def aritm_sredina(pocetak, *kraj):
    suma = pocetak
    for i in kraj:
        suma += i
    return suma

print(aritm_sredina(1, 2, 3, 4, 5, 6))

# -----------------------------------------------------------

def prosek(a, b, c):
    def zbir(a, b, c):
        return a + b + c
    return zbir(a, b, c) / 3

print(prosek(1, 2, 3))