%option noyywrap
%option noinput
%option nounput

%{
 /* Bison vodi racuna o tokenima i njihove definicije 
    smesta u datoteku parser.tab.hpp. Posto su nam 
    potrebni za komunikaciju izmedju sintasnog i leksickog
    analizatora ukljucujemo zaglavlje parser.tab.hpp u kom
    su tokeni definisani. */
    #include <iostream>
    #include <cstdlib>
    #include "01_aritmeticki_izraz.tab.hpp"
    using namespace std;
%}

%%
[0-9]+ return BROJ;
[+*()] return yytext[0];
[\n \t] {}
. {
    cerr << "Leksicka greska: nepoznat karakter" << endl;
    exit(EXIT_FAILURE);
  }
%%
