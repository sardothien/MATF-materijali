%option noyywrap

%{
    #include <string>
    #include "skup.hpp"
    #include "parser.tab.hpp"
    using namespace std;
%}

%%
UniversalSet    return UNIVERSE;
check           return CHECK;
card            return CARD;
print           return PRINT;
[A-Z][a-zA-Z0-9]* { 
                    yylval.ime = new string(yytext);
                    return ID;
                  }
[={,}:;<~]      return *yytext;
".."            return TT;
"\\/"           return U;
"/\\"           return P;
"\\"            return R;
-?[0-9]+        {
                    yylval.i_val = atoi(yytext);
                    return BROJ;
                }
[ \n\t]         {}
. {
        fprintf(stderr, "Leksicka greska!");
        exit(EXIT_FAILURE);
  }
%%
