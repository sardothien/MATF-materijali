%option noyywrap
%option noinput
%option nounput

%{
    #include<iostream>
    #include<cstdlib>
    #include"razlomak.hpp"
    using namespace std;
    #include"parser.tab.hpp"
%}

%%
[+*/(),=-] return *yytext;
[+-]?(0|[1-9][0-9]*)   {
                            yylval.br = atoi(yytext);
                            return BROJ;
                       }
\[|\]   return *yytext;
fraction    return FRAC;
print       return PRINT;
numerator   return NUMER;
denominator return DENOM;
check       return CHECK;
double      return DOUBLE;
(?i:[a-z_][a-z0-9_]*) {
                        yylval.id = strdup(yytext);
                        return ID;
                      }
[ \t\n] {}
. {
        cerr << "Leksicka greska!" << endl;
        exit(EXIT_FAILURE);
  }
%%
