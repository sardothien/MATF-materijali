/* Kompanija Start ima 250 zaposlenih radnika.  Rukovodstvo kompanije je odlucilo 
   da svojim radnicima obezbedi dodatnu edukaciju. Da bi se radnik obucio programskom
   jeziku Elixir potrebno je platiti 100 evra po osobi za kurs, ali bi njegovo 
   produktivno znanje ovog programskog jezika donelo 150 projekat/sati mesecno, sto 
   bi za kompaniju znacilo dobit od 5 evra po projekat/satu. Da bi se radnik obucio
   programskom jeziku Dart potrebno je platiti 105 evra po osobi za kurs, ali bi 
   njegovo produktivno znanje ovog programskog jezika donelo 170 projekat/sati mesecno,
   koji bi za kompaniju znacili dobit od 6 evra po satu. Ukoliko Start ima na raspolaganju
   26000 evra za obuku i maksimalan broj 51200 mogucih projekat/sati mesecno, odrediti 
   na koji nacin kompanija treba da obuci svoje zaposlene kako bi ostvarila maksimalnu dobit. */

kompanija(Vars) :- Vars= [E,D],
                   Vars :: 0..250,
                   E+D #= 250,
                   150*E + 170*D #=< 51200,
                   100*E + 105*D #=< 26000,
                   labeling([maximize(150*5*E+170*6*D-(100*E+ 105*D))], Vars),
                   Zarada is (150*5*E+ 170*6*D- (100*E+ 105*D)),
                   write('Maksimalna zarada je:  '), write(Zarada),
                   write(', broj radnika koje treba poslati na kurs Elixir je:  '), write(E),
                   write(', a broj radnika koje treba poslati na kurs Dart je:  '), write(D), nl.