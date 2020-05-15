# Napisati funkciju max_list(lista) koja vraca najveci element
# u listi. Napisati program koji testira ovu funkciju.

def max_list(lista):
    maximum = lista[-1]
    for elem in lista:
        if elem > maximum:
            maximum = elem
    return maximum

lista = [1, 4, -6, 7, 9, 0, 1]
print(max_list(lista))