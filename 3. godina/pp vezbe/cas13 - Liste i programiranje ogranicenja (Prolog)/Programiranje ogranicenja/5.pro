/* Napisati program koji dodeljuje razlicite vrednosti razlicitim
   karakterima tako da suma bude zadovoljena:  
    TWO
   +TWO
   -------
   FOUR */

jednakost(Vars) :- Vars = [T, W, O, F, U, R],
                   Vars :: 0..9,
                   T #\= 0,
                   F #\= 0,
                   alldifferent(Vars),
                   2*(100*T + 10*W + O) #= 1000*F + 100*O + 10*U + R,
                   labeling(Vars),
                   write(' '), write(T), write(W), write(O), nl,
                   write('+'), write(T), write(W), write(O), nl,
                   write('-----'), nl,
                   write(F), write(O), write(U), write(R), nl, nl, fail.
% dodavanjem fail na kraju ispisuju se sva resenja