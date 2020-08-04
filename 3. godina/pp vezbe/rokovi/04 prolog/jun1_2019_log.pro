clan(X, [X|_]).
clan(X, [G|R]) :- G \== X, clan(X, R).

% (ime, prezime, vrsta, boja obuce)

drugarice(X) :- X = [c(_, _, _, _),
                     c(_, _, _, _),
                     c(_, _, _, _),
                     c(_, _, _, _)],
                clan(c(anja, _, _, _), X),
                clan(c(jelena, _, _, _), X),
                clan(c(_, cugurovic, _, _), X),
                clan(c(_, bogdanovic, _, _), X),

                clan(c(kaca, andonov, _, _), X),
                clan(c(_, ranisavljevic, _, zelena), X),
                clan(c(_, _, cizme, braon), X),
                clan(c(milica, _, sandale, _), X),
                \+(clan(c(_, cugurovic, cizme, _), X)),
                \+(clan(c(milica, ranisavljevic, _, _), X)),
                \+(clan(c(milica, _, _, crna), X)),
                \+(clan(c(kaca, _, cizme, _), X)),
                \+(clan(c(_, _, cipele, pink), X)),
                \+(clan(c(anja, bogdanovic, _, _), X)),
                \+(clan(c(jelena, _, patike, _), X)).