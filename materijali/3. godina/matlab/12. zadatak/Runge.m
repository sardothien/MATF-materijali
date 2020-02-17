% Napisati M-fajl Runge.m sa funkcijom Runge(S1, S2)
% koja vraca vrednost Rungeove ocene greske uopstene 
% Simpsonove kvadraturne formule, ako su S1 i S2 njene
% vrednosti od kojih je jedna izracunata sa dvostruko 
% manjim korakom u odnosu na drugu.
function vr = Runge(S1, S2)

vr = abs(S1 - S2) / 15;