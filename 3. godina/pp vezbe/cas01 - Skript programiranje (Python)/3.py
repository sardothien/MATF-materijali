# Napisati program koji sa standardnog ulaza ucitava jedan string
# i jedan ceo broj, a zatim ispisuje (dinamicki odredjene) tipove
# ucitanih promenljivih. Nakon toga, na standardni izlaz ispisati
# poruku ispisivanje vise stringova koriscenjem separatora =, <->
# i novog reda, redom.

x = input("Uneti string: ")
print(x, type(x))

x = int(input("Uneti ceo broj: "))
print(x, type(x))

print("Neke niske u Python-u")
print("Neke", "niske", "u", "Python-u")
print("Neke", "niske", sep = '=')
print("Neke", "niske", sep = '<->')
print("Neke", "niske", sep = '\n')
