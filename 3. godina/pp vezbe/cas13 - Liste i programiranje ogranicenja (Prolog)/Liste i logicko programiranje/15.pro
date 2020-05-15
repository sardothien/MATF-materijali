/* Napisati program koji resava sledecu zagonetku. Postoji pet kuca, 
   svaka razlicite boje u kojoj zive ljudi razlicitih nacionalnosti 
   koji piju razlicita pica, jedu razlicita jela i imaju razlicite
   kucne ljubimce. Vazi sledece:
   • Englez zivi u crvenoj kuci
   • Spanac ima psa
   • kafa se pije u zelenoj kuci
   • Ukrajinac pije caj
   • zelena kuca je odmah desno uz belu
   • onaj koji jede spagete ima puza
   • pica se jede u zutoj kuci
   • mleko se pije u srednjoj kuci
   • Norvezanin zivi u prvoj kuci s leva
   • onaj koji jede piletinu zivi pored onoga koji ima lisicu
   • pica se jede u kuci koja je pored kuce u kojoj je konj
   • onaj koji jede brokoli pije sok od narandze
   • Japanac jede susi
   • Norvezanin zivi pored plave kuce 
  Cija je zebra, a ko pije vodu? */ 

clan(X, [X|_]).
clan(X, [_|R]) :- clan(X, R).

% k(boja, nacionalnost, jelo, pice, kucniLjubimac)
kuce(L) :- L = [k(_, norvezanin, _, _, _), 
                k(plava, _, _, _, _),
                k(_, _, mleko, _, _),
                k(_, _, _, _, _),
                k(_, _, _, _, _)],
            clan(k(crvena, englez, _, _, _), L),
            clan(k(_, spanac, _, _, pas), L),
            clan(k(zelena, _, _, kafa, _), L),
            clan(k(_, ukrajinac, _, caj, _), L),
            desno(k(zelena, _, _, kafa, _), k(bela, _, _, _, _), L),
            clan(k(_, _, spagete, _, puz), L),
            clan(k(zuta, _, pica, _, _), L),
            pored(k(_, _, piletina, _, _), k(_, _, _, _, lisica), L),
            pored(k(_, _, pica, _, _), k(_, _, _, _, konj), L),
            clan(k(_, _, brokoli, narandza, _), L),
            clan(k(_, japanac, susi, _, _), L),
            clan(k(_, _, _, _, zebra), L),
            clan(k(_, _, _, voda, _), L).

pored(X, Y, [X,Y|_]).
pored(X, Y, [Y,X|_]).
pored(X, Y, [_|R]) :- pored(X, Y, R).

desno(X, Y, [Y,X|_]).
desno(X, Y, [_|R]) :- desno(X, Y, R).

zagonetka(X, Y) :- kuce(L), clan(k(_, X, _, _, zebra), L), clan(k(_, Y, _, voda, _), L).