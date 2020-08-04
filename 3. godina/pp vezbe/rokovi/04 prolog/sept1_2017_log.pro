% Napisati predikat braca koji rešava sledeću zagonetku. Četiri brata Stefan, Vanja, 
% Miloš i Petar su otišla u prodavnicu da kupe knjige i doneli su tati račune od 600,
% 1200, 1500 i 3200 dinara. Kupili su 3,4,5 i 8 knjiga. Pomozimo tati da otkrije broj 
% knjiga i količinu novca koju je svako od njih potrošio:
% • Stefan je kupio tri knjige.
% • Miloš je potrošio 1200 dinara.
% • Brat koji je kupio 5 knjiga svaku je platio 300 dinara.
% • Vanja je kupio jednu knjigu više od Miloša.
% • 600 dinara nisu potrošili ni Stefan ni Vanja
% • Petar nije kupio četiri knjige.
% Uputstvo: Predikat treba da generiše listu koja sadrži trojke 
% (imeBrata, brojKnjiga, kolicinaNovca).\

sadrzi(X, [X|_]).
sadrzi(X, [G|R]) :- G \== X, sadrzi(X, R).

braca(L) :- L = [c(stefan, 3, _),
                 c(milos, M, 1200),
                 c(vanja, V, _),
                 c(petar, _, _)],
            sadrzi(c(_, _, 600), L),  
            sadrzi(c(_, _, 3200), L),  
            sadrzi(c(_, 4, _), L),  
            sadrzi(c(_, 8, _), L),  
            sadrzi(c(_, 5, 1500), L),
            \+(sadrzi(c(stefan, _, 600), L)),
            \+(sadrzi(c(vanja, _, 600), L)),
            \+(sadrzi(c(petar, 4, _), L)),
            V =:= M+1.