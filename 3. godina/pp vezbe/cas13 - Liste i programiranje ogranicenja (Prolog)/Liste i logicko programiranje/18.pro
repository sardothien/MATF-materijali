% Marko i tri njegova prijatelja su proveli subotu popodne
% u lokalnoj igraonici. Pokazalo se da je svako od njih odlican
% u nekoj od igri koje su dostupne u igraonici. Za svakog od
% ucesnika potrebno je otkriti njegovo ime, prezime, u kojoj igri
% je najbolji i sta je grickao. U igraonici su bile dostupne
% gricklalice pica, nacos, kokice i sladoled.
% * Marko nije pobedio u igri stoni fudbal.
% * Marko je jeo nacos.
% * Markovic je jeo kokice.
% * Milicino prezime nije Milic.
% * Pobednik u bilijaru je jeo picu.
% * U bilijaru nije pobedila Milica.
% * Ivanino prezime je Stefanovic.
% * Nemanjino prezime nije Radosavljevic.
% * Nemanja je pobedio u igri mini golf.
% * Pobednik u kuglanju se ne preziva Radosavljevic.

sadrzi(X, [X|_]).
sadrzi(X, [G|R]) :- G \== X, sadrzi(X, R).

% (ime, prezime, igra, grickalica)

prijatelji(X) :- X = [c(_, _, _, _),
                      c(_, _, _, _),
                      c(_, _, _, _),
                      c(_, _, _, _)],
                sadrzi(c(milica, _, _, _), L),
                sadrzi(c(_, radosavljevic, _, _), L),
                sadrzi(c(_, milic, _, _), L),
                sadrzi(c(_, _, kuglanje, _), L),
                sadrzi(c(_, _, stoniFudbal, _), L),
                sadrzi(c(_, _, _, sladoled), L),
                \+(sadrzi(c(marko, _, stoniFudbal, _), L)),
                sadrzi(c(marko, _, _, nacos), L),
                sadrzi(c(_, markovic, _, kokice), L),
                \+(sadrzi(c(milica, milic, _, _), L)),
                sadrzi(c(_, _, bilijar, pica), L),
                \+(sadrzi(c(milica, _, bilijar, _), L)),
                sadrzi(c(ivana, stefanovic, _, _), L),
                \+(sadrzi(c(nemanja, radosavljevic, _, _), L)),
                sadrzi(c(nemanja, _, miniGolf, _), L),
                \+(sadrzi(c(_, radosavljevic, kuglanje, _), L)).