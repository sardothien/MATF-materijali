% Napisati program koji resava sledecu zagonetku. Cetiri para je 
% doslo na maskenbal:
% • Markova zena se maskirala kao macka
% • dva para su stigla pre Marka i njegove zene, a jedan muskarac je 
%   bio maskiran u medveda
% • prvi koji je stigao nije bio Vasa, ali je stigao pre onoga koji je
%   bio maskiran u princa
% • zena maskirana u vesticu (nije Bojana) je udata za Peru, koji se 
%   maskirao kao Paja patak
% • Marija je dosla posle Laze, a oboje su stigli pre Bojane
% • zena maskirana u Ciganku je stigla pre Ane, pri cemu nijedna od 
%   njih nije udata za muskarca maskiranog u Betmena
% • zena maskirana u Snezanu je stigla posle Ivane 
% Odrediti kako je bio obucen koji par.

% (muskarac, zena, muska maska, zenska maska, vreme dolaska)

sadrzi(X, [X|_]).
sadrzi(X, [G|R]) :- G \== X, sadrzi(X, R).

maskenbal(L) :- L = [c(_, _, _, _, 1),
                     c(_, _, _, _, 2),
                     c(_, _, _, _, 3),
                     c(_, _, _, _, 4)],
                sadrzi(c(marko, _, _, _, _), L),
                sadrzi(c(vasa, _, _, _, StigaoVasa), L),
                sadrzi(c(pera, _, _, _, _), L),
                sadrzi(c(laza, _, _, _, StigaoLaza), L),
                sadrzi(c(_, ana, _, _, StiglaAna), L),
                sadrzi(c(_, marija, _, _, StiglaMarija), L),
                sadrzi(c(_, ivana, _, _, StiglaIvana), L),
                sadrzi(c(_, bojana, _, _, StiglaBojana), L),
                sadrzi(c(_, _, medved, _, StigaoMedved), L),
                sadrzi(c(_, _, princ, _, StigaoPrinc), L),
                sadrzi(c(_, _, betmen, _, _), L),
                sadrzi(c(_, _, pajaPatak, _, _), L),
                sadrzi(c(_, _, _, ciganka, StiglaCiganka), L),
                sadrzi(c(_, _, _, snezana, StiglaSnezana), L),
                sadrzi(c(_, _, _, vestica, _), L),
                sadrzi(c(_, _, _, macka, _), L),
                sadrzi(c(marko, _, _, macka, 3), L),
                \+(sadrzi(c(_, bojana, _, vestica, _), L)),
                \+(sadrzi(c(pera, bojana, _, _, _), L)),
                sadrzi(c(pera, _, pajaPatak, vestica, _), L),
                \+(sadrzi(c(_, _, betmen, ciganka, _), L)),
                \+(sadrzi(c(_, ana, betmen, _, _), L)),
                StigaoMedved =< 2,
                StigaoVasa > 1,
                StigaoVasa < StigaoPrinc,
                StigaoLaza < StiglaMarija,
                StiglaBojana > StiglaMarija,
                StiglaBojana > StigaoLaza,
                StiglaCiganka < StiglaAna,
                StiglaSnezana > StiglaIvana.             