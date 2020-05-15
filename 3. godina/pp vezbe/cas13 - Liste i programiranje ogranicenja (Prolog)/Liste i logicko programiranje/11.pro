/* Ako su date cinjenice oblika:
    * stan(Porodica, KvadraturaStana)
    * clan(Porodica, BrojClanova)
   Napisati predikat poClanu(Porodica, Prosek) koji odredjuje
   prosecan broj kvadrata stana po clanu porodice koja zivi u njemu. */
stan(petrovic, 76).
stan(ciric, 93).
stan(aleksic, 55).
stan(lisic, 123).
stan(peric, 67).

clan(ciric, 3).
clan(peric, 5).
clan(aleksic, 2).
clan(lisic, 3).
clan(petrovic, 4).

poClanu(Porodica, Prosek) :- stan(Porodica, X), clan(Porodica, Y), Prosek is X/Y.