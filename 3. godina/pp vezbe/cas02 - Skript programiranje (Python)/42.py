# Napisati program koji na standardni izlaz ispisuje sve
# apsolutne putanje regularnih fajlova koji se nalaze u
# tekucem direktorijumu.

import os

for ime in os.listdir(os.curdir):
    if os.path.isfile(os.path.join(os.curdir, ime)):
        print(os.path.abspath(os.path.join(os.curdir, ime)))