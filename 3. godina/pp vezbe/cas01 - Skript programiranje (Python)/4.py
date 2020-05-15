# Napisati program koji sa standardnog ulaza ucitava ceo broj, a zatim
# na standardni izlaz ispisuje poruku o ostatku koji taj broj daje kada se 
# podeli sa pet. Nakon toga, koristeci for i while petlju ispisati prvih
# deset prirodnih brojeva.

x = int(input("Uneti ceo broj: "))
if x % 5 == 0:
    print("Ostatak je 0")
elif x % 5 == 1:
    print("Ostatak je 1")
elif x % 5 == 2:
    print("Ostatak je 2")
elif x % 5 == 3:   
    print("Ostatak je 3")
else: 
    print("Ostatak je 4")

for i in range(10):
    print(i, end = ' ')
print()

i = 0
while i < 10:
    print(i, end = ' ')
    i += 1