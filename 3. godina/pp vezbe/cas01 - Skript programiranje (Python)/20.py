# Sa standardnog ulaza se unose reci do reci quit. Napisati
# program koji ispisuje unete reci eliminisuci duplikate.

lista = []

while True:
    unos = input()
    if unos == 'quit':
        break
    lista.append(unos)

skup = set(lista)
print(skup)