/* Napisati predikat dupliraj(L, NL) koji od date liste L formira 
   novu listu NL tako sto svaki negativan element duplira, tj. dva
   puta upisuje u novu listu. */
dupliraj([], []).
dupliraj([G|R], [G, G|R1]) :- G<0, dupliraj(R, R1), !.
dupliraj([G|R], [G|R1]) :- G>=0, dupliraj(R, R1).