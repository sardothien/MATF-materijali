# Napisati funkciju parovi(a, b, c, d) koja generise listu 
# parova celih brojeva (x,y), za koje x pripada segmentu [a,b]
# a y pripada segmentu [c,d]. Testirati rad funkcije pozivom
# u programu.

a = int(input("a: "))
b = int(input("b: "))
c = int(input("c: "))
d = int(input("d: "))

lista = [(x, y) for x in range(a, b+1) for y in range(c, d+1)]
print(lista)