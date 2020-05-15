# Napisati program koji sa standardnog ulaza ucitava nisku,
# a na standardni izlaz ispisuje nisku u kojoj su sva mala 
# slova pretvorena u velika.

niska = input("Uneti nisku: ")

print(map(lambda c: c.upper(), niska)) # adresa

print(list(map(lambda c: c.upper(), niska))) # lista karaktera

print(''.join(list(map(lambda c: c.upper(), niska)))) # resenje