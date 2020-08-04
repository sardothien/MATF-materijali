% Ako su date činjenice oblika:
% • proizvodi(Firma,Sok) - firma proizvodi dati sok
% • procenatVoca(Firma,ProcenatVoca) - firma u svoje sokove stavlja ProcenatVoca
%   procenata voća
% • pakuje(Firma,BrojLitara) - firma u jedan paket stavlja BrojLitara litara soka
proizvodi(bravo,narandza).
proizvodi(next,narandza).
proizvodi(nectar,narandza).
proizvodi(fructal,narandza).
proizvodi(bravo,jabuka).
proizvodi(fructal,jabuka).
proizvodi(next,multivitamin).
proizvodi(nectar,multivitamin).
proizvodi(fructal,jagoda).
proizvodi(fructal,malina).
proizvodi(bravo,breskva).

procenatVoca(bravo,65).
procenatVoca(next,99).
procenatVoca(fructal,86).
procenatVoca(nectar,95).

pakuje(bravo,10).
pakuje(next,8).
pakuje(fructal,12).
pakuje(nectar,15).

% Napisati predikate:
% (a) bolji(F1,F2,S) - proverava da li je firma F1 bolji proizvodjač soka S od firme F2
%     (firma je bolji proizvođač ukoliko stavlja veći procenat voća u sok)
bolji(F1, F2, S) :- proizvodi(F1, S), proizvodi(F2, S), procenatVoca(F1, X), procenatVoca(F2, Y), X > Y.

% (b) najbolji(S,F) - pronalazi firmu F koja je najbolji proizvođač soka, odnosno firmu
%     od koje ne postoji bolji proizvođač
najbolji(F, S) :- proizvodi(F, S), not(bolji(_, F, S)), !.

% (c) brojPaketa(BrojLitara,F,P) - računa broj paketa P koji je potreban da bi firma F
%     spakovala BrojLitara litara soka (broj paketa se dobija kao zaokružena vrednost 
%     količnika ukupnog broja litara soka BrojLitara i broja litara soka po jednom paketu)
brojPaketa(BrojLitara, F, P) :- pakuje(F, BP), P is ceiling(BrojLitara / BP).

% (d) kolicinaSoka(S,BrojKilogramaVoca,BrojLitara) - računa koliko litara BrojLitara soka S
%     je moguće dobiti ukoliko firma koja je najbolji proizvođač dobije BrojKilogramaVoca 
%     kilograma voća
kolicinaSoka(S, BrojKilogramaVoca, BrojLitara) :- najbolji(F, S), procenatVoca(F, PR), 
                                                  P1 is (100.0 - PR), 
                                                  BrojLitara is BrojKilogramaVoca + (BrojKilogramaVoca / PR)*P1.