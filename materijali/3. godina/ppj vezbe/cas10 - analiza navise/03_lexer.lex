%option noyywrap
%option noinput
%option nounput

%{
    #include <iostream>
    #include <cstdlib>
    #include "03_parser.tab.hpp"
    using namespace std;
%}

%%
[0-9]+(\.[0-9]+)? {
                        yylval.vrednost = atof(yytext);
                        return BROJ;
                  }
[+*()/-] return *yytext;
[\n \t] {}
. {
    cerr << "Leksicka greska!" << endl;
    exit(EXIT_FAILURE);
  }
%%
