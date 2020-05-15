/* Kalkulator */

%option noyywrap
%option noinput
%option nounput

%{
    #include<iostream>
    #include<cstdlib>
    #include"01_parser.tab.hpp"
    using namespace std;
%}

%%
[0-9]+(\.[0-9]+)? {
                    yylval.vrednost = atof(yytext);
                    return BROJ;
                  }
print {
            return PRINT;
      }
[a-zA-Z_][a-zA-Z0-9]* {
                            yylval.id = new string(yytext);
                            return ID;
                      }
[\n=+*()/-] return *yytext;
[ \t] {}
. {
        cerr << "Leksicka greska! Karakter nije prepoznat." << endl;
        exit(EXIT_FAILURE);
  }
%%
