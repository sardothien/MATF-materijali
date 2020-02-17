% Napisati M-fajl smena.m sa funkcijom [c,d]=smena(a,b)
% koja vraca koeficijente linearne smene x = ct + d 
% kojom se interval tc[-1,1] preslikava na xc[a, b].
function [c, d] = smena(a, b)

d = (a+b)/2;
c = (b-a)/2;