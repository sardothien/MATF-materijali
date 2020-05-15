# Ako je prvi dan u mesecu ponedeljak, napisati funkciju radni_dan(dan)
# koja kao argument dobija dan u mesecu i vraca Tacno ako je dan radni.
# Napisati program koji testira ovu funkciju. Korisnik sa standardnog
# ulaza u petlji unosi deset dana i dobija poruku o tome da li su uneti 
# dani radni ili ne.

def radni_dan(broj):
    if broj % 7 == 1 or broj % 7 == 2 or broj % 7 == 3 or broj % 7 == 4 or broj % 7 == 5:
        return True
    else:
        return False

for i in range(10):
    try:
        dan = int(input("Uneti dan: "))
    except ValueError:
        print("Nije unet broj!")
        exit(1)

    if radni_dan(dan):
        print("Jeste radni dan!")
    else:
        print("Nije radni dan!")    