# Napisati program koji sa standardnog ulaza ucitava nisku, 
# a na standardni izlaz ispisuje sve karaktere koji nisu slova.

niska = input("Uneti nisku: ")

print(list(filter(lambda c: not c.isalpha(), niska)))