%option noyywrap
%option noinput
%option nounput

%{
    #include<iostream>
    #include<cstdlib>
    #include"liste.hpp"
    #include"parser.tab.hpp"
    using namespace std;
%}

%%
print       return PRINT;
head        return HEAD;
tail        return TAIL;
number      return NUMBER;
sort        return SORT;
scalar      return SCALAR;
[\[\];,=\.]  return *yytext;
"=="        return POREDI;
[+-]?[0-9]+         {
                        yylval.vr = atoi(yytext);
                        return BROJ;
                    }
[a-z][a-z0-9]{0,7}  {
                        yylval.id = new string(yytext);
                        return ID;
                    }
\n      return *yytext;
[ \t]     {}
.           {
                cerr << "Leksicka greska!" << endl;
                exit(EXIT_FAILURE);
            }
%%
