# Direktorijum cije se ime navodi kao prvi argument 
# komandne linije programa sadrzi poddirektorijume 
# nazvane po indeksima studenta I smera. Direktorijumi
# sadrze zadatke koje su studenti tokom leta radili u 
# datotekama oblika broj.ext gde ext ukazuje na programski 
# jezik u kome je zadatak radjen (C, C++, JAVA, Pascal). 
# Napisati skript koji tabelarno prikazuje zadatke koje 
# je svaki student radio. 

import sys, re, os

# izdvajamo indekse iz datoteke 'indeksi'
homedir = 'seminarski'
studenti = {}
indeksi = open(homedir + '/indeksi', 'r')

for linija in indeksi.readlines():
    if linija[-1] == '\n': # izbacujemo karakter \n
        linija = linija[0:-1]
        info = re.split(r",\s*", linija) # rezultat je lista
        studenti[info[0]] = info[1] # radi kao recnik
    
re_dir = re.compile(r"m[mnvlir]\d{5}")
re_file = re.compile(r"(\d+)\.(java|pas|c|cpp)")

max_br_zad = 0
zadaci = {}
predali = []

# listamo direktorijum sa studentskim direktorijumima
for f in os.listdir(homedir):
    stud_dir = os.path.join(homedir, f)
    m = re_dir.match(f)
    # ako je direktorijum i naziv odgovara studentskom 
    # indeksu i u pitanju je student koji je sa spiska
    if os.path.isdir(stud_dir) and m is not None and m.group() in studenti:
        stud_indeks = m.group()
        predali.append(stud_indeks)
        # izdvajamo zadatke koje je student uradio
        for sf in os.listdir(stud_dir):
            zadatak_path = os.path.join(stud_dir, sf)
            # ako je datoteka ekstenzije .c ili .cpp ili .pas ili .java
            m = re_file.match(sf)
            if os.path.isfile(zadatak_path) and m is not None:
                zadatak = int(m.group(1))
                if zadatak > max_br_zad:
                    max_br_zad = zadatak
                kljuc = stud_indeks + " " + m.group(1)
                zadaci[kljuc] = m.group(2)
                
# prikazujemo tabelu oblika
# Pera Peric - pas - c
# Ivan Ivanovic c pas - java
for indeks, ime in studenti.iteritems():
    print "\n" + ime + " "
    for i in range(1, max_br_zad+1):
        kljuc = indeks + " " + str(i)
        if kljuc not in zadaci:
            print "\t"
        else:
            print "\t" + zadaci[kljuc]
