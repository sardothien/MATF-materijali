# Napisati program koji ilustruje osnovne sistemske funkcije i module
# programskog jezika Python tako sto koristi funkcije faktorijel, logaritam, 
# generise pseudoslucajne brojeve, ispisuje argumente komandne linije na izlaz,
# poziva sistemski poziv listanja tekuceg direktorijuma, ispisuje broj sekundi
# od 1.1.1970. godine, finalno unosi string sa ulaza za koji proverava da li 
# predstavlja zapis celog broja.

import math
print(math.factorial(5))
print(math.log(5, 4))

import random
print(random.random())
print(random.randint(0, 10))

import sys
print(sys.argv)

import os
os.system("ls -l")

import time as t
print(t.time())

from re import search as re_src
print(re_src(r'[0-9]+', input("Unesite string za match: ")))