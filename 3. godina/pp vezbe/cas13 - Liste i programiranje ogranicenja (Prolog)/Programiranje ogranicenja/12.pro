/* Napisati program koji rasporedjuje n dama na sahovsku tablu
   dimenzije nxn tako da se nikoje dve dame ne napadaju. */

kraljice(N) :- length(Qs, N),% Qs  je  niz  , tj . lista od  n promenljivih
               Qs :: 1..N,
               % I je  implicitno razlicito od J -> razlicite kolone
               % Qs[I] treba da bude razlicito od Qs[J] -> razlicite vrste
               foreach(I in 1..N-1, J in I+1..N,
                       (Qs[I] #\= Qs[J], abs(Qs[I]-Qs[J]) #\= J-I)),
               labeling(Qs),
               writeln(Qs), fail.