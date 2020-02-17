%option noyywrap
%option noinput
%option nounput

%{
    #include<iostream>
    #include<cstdlib>
    #include<string>
    #include"razlomak.hpp"
    #include"parser.tab.hpp"
    using namespace std;
%}

%%
print           return PRINT;
nom             return NOM;
den             return DEN;
double          return DOUBLE;
equals          return EQUALS;
[+-]?[0-9]+     {
                    yylval.vr = atoi(yytext);
                    return BROJ;
                }
[a-zA-Z][a-zA-Z0-9]* {
                        yylval.id = new std::string(yytext);
                        return ID;
                    }
[()\[\]=,+*/\-]     return *yytext;
\n                 return *yytext;
[ \t]   {}
.       {
            cerr << "Leksicka greska!" << endl;
            exit(EXIT_FAILURE);
        }
%%
