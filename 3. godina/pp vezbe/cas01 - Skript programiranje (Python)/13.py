# Napisati program kojim se ilustruje upotreba struktura podataka:
# stek, skup, mapa, torke.

# Skup
imena = set()
for ime in ['Milan', 'Jovan', 'Marko', 'Milos', 'Lazar', 'Marko']:
    imena.add(ime)

print(imena)
print(set(['Milan', 'Jovan', 'Marko', 'Milos', 'Lazar', 'Marko']))

# Stek
stek = []
stek.append(1)
stek.append(2)
stek.append(3)
print("Stek: ", stek)

print("Elementi pop(): ")
print(stek.pop())
print(stek.pop())
print(stek.pop())

# Mape
prosek = {'Milan' : 9.45, 'Ana' : 9.87, 'Nikola' : 8.42}
print(prosek, type(prosek))
print(prosek.keys())
print(prosek.values())
print('Milan' in prosek)
print('Milos' in prosek)

# Torke
voce = ('apple', 'orange', 'banana', 'pear', 'kiwi')
print(voce)
print(voce[2:4])

try: 
    voce[0] = 5
except TypeError:
    print("Tuple objekti su imutabilni!")