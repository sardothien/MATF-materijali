# Napisati funkciju min_torka(torka) koja vraca najmanji
# element u torci torka. Napisati program koji testira funkciju.

def min_torka(torka):
    minimum = torka[0]
    for l in torka:
        if l < minimum:
            minimum = l
    return minimum

torka = ((1, 2, 'a'), (1, 2, 'b'), (1, 3, 'z'), (2, 2, '5'))
print(min_torka(torka))