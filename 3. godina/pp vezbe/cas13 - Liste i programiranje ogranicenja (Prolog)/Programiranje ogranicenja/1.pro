/* Constraint - nad konacnim domenom
    1. generisanje promenljivih i njihovim domenima
    2. generisanje ogranicenja
    3. generisanje resenja -> instanciranje promenljivih
    
   Definisanje domena promenljivih:
    * X in D <=> X :: D
    * Vars in D <=> Vars :: D
   
   Domen: [pocetak..korak..kraj]

   Predikati za ogranicenja: 
    * Opsta: alldifferent(Vars), alldistinct(Vars),
             atmost(N, L, V), atleast(N, L, V), exactly(N, L, V),
    * Aritmeticka: E1 R E2 (E1, E2 -> aritm. izrazi; R -> #=, #\=, #>=, #=<, #>, #<)
                   min(L), max(L), max(E1, E2), min(E1, E2),
                   sum(L)

   Instanciranje promenljivih (labeliranje):
    * labeling(Options, Vars)
 */

 primer1(Vars) :- Vars = [X, Y, Z],
                 X :: 1..3,
                 Y :: 2..2..10,
                 Z :: 5..8,
                 Z #>= Y,
                 labeling(Vars).

% Potpuni kvadrati do 100
primer2(Vars) :- Vars = [X],
                 X :: 1..100,
                 X #= Y*Y,
                 labeling(Vars).