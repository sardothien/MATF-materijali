% Napisati predikat drugari(L) koji rešava sledeću zagonetku i listu L
% unifikuje sa njenim rešenjem. Maja, Ana, Jovan i Lazar su drugari koji
% vole da slušaju različitu vrstu muzike jazz, techno, pop i rock i imaju
% različit broj godina 24,25,26,27. Na osnovu sledećih činjenica odrediti
% imena, broj godina i vrstu muzike koju drugari slušaju:
% • Lazar je najmlađi u društvu
% • Osoba koja ima 27 godina sluša jazz.
% • Ana ima manje od 27 godina.
% • Jovan ima jednu godinu manje od osobe koja voli pop.
% • Techno muziku voli osoba starija od 23 godine.
% • Maja ne voli techno muziku.
% Uputstvo: Rešenje zagoneteke je lista strukutura koje jednoznačno 
% određuju svakog drugara (imeDrugara, vrstaMuzike, brojGodina).

sadrzi(X, [X|_]).
sadrzi(X, [G|R]) :- G \== X, sadrzi(X, R).

drugari(L) :- L = [c(maja, _, MG),
                   c(ana, _, AG), 
                   c(jovan, _, JG), 
                   c(lazar, _, LG)], %najmladji
              sadrzi(c(_, jazz, _), L),
              sadrzi(c(_, pop, PG), L),
              sadrzi(c(_, techno, _), L),
              sadrzi(c(_, rock, _), L),
              sadrzi(c(_, _, 24), L),
              sadrzi(c(_, _, 25), L),
              sadrzi(c(_, _, 26), L),
              sadrzi(c(_, _, 27), L),
              sadrzi(c(_, jazz, 27), L),
              \+(sadrzi(c(maja, techno, _), L)),
              AG #< 27,
              JG #= PG-1,
              LG #< AG,
              LG #< MG,
              LG #< JG.            