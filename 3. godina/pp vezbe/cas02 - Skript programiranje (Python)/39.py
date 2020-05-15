# Napisati program koji na standardni izlaz ispisuje 
# argumente komandne linije.

import sys

if len(sys.argv) == 1:
    print("Nema argumenata komandne linije!")
    exit(1)

for item in sys.argv:
    print(item)