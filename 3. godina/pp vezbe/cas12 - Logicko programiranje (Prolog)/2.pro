% Prolog sintaksa

/* Termovi - osnovna struktura podataka u Prolog-u
     -> atoms, numbers, variables, compounds

    * Atoms: strings (lowerCase, upperCase, digits, underscore)
             pocinju malim slovom
             recenica moze biti atom ('This is atom.')
    * Numbers: integer type (kod nekih ima i float)
    * Variables: strings (lowerCase, upperCase, digits, underscore)
                 pocinju velikim slovom ili underscore-om
                 _ - anonimna promenljiva
    * Compound terms: functor (atom)
                      arguments (termovi)
*/

/*  Klauze - cinjenice i pravila 
        -> na osnovu njih definisemo predikate
        -> cinjenica predstavlja predikat pracen tackom
        -> pravilo se sastoji od glave (predikat) i (:-) 
           tela (sekvenca predikata odvojeni zarezima)

    Prolog programi - sekvenca klauza

    Ugradjeni predikati: 
        Equality: = (X=Y)
        Guaranteed success and failure: true, fail
        Output: write('...'), nl (new line)
        Checking: atom(nesto) -> vraca yes/no
*/

mortal(X) :- man(X).
man(socrates).

% query: mortal(socrates)