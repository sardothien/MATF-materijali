%option noyywrap
%option noinput
%option nounput

%{
    #include <iostream>
    #include <cstdlib>
    #include "02_vrednost_izraza.tab.hpp"
    using namespace std;
%}

%%
[0-9]+ {
            yylval.vrednost = atoi(yytext);
            return BROJ;
       }
[+*()] return *yytext;
[\n \t] {}
. {
    cerr << "Leksicka greska: neocekivani simbol" << endl;
    exit(EXIT_FAILURE);
  }
%%
