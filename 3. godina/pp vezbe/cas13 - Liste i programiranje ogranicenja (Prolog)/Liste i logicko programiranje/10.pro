/* Napisati predikat spoji(L1, L2, L) koji spaja dve rastuce 
   sortirane liste L1 i L2 u trecu tako da i ona bude sortirana
   rastuce. */
spoji([], L, L) :- !.
spoji(L, [], L) :- !.
spoji([G1|R1], [G2|R2], [G1|R]) :- G1<G2, spoji(R1, [G2|R2], R), !.
spoji([G1|R1], [G2|R2], [G2|R]) :- G1>=G2, spoji([G1|R1], R2, R).