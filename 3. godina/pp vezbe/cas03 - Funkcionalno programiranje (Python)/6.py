# Napisati program koji na standarndi izlaz ispisuje
# sumu, koristeci funkciju reduce prvih n prirodnih
# brojeva gde se n unosi sa standardnog ulaza.

from functools import reduce

n = int(input("Unesite broj: "))

brojevi = range(0, n+1)
print("Suma: {}".format(reduce(lambda x,y: x+y, brojevi)))