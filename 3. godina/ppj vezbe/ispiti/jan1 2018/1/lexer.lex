%option noyywrap
%option noinput
%option nounput

%{
    #include<iostream>
    #include<cstdlib>
    #include<string>
    #include"vektor.hpp"
    #include"parser.tab.hpp"
    using namespace std;
%}

%%
print         return PRINT;
ugao          return UGAO;
eqv           return EKV;
":="          return DODELA;
[<>\|(),;+*\-\.]        return *yytext;
[+-]?[0-9]+(\.[0-9]+)? {
                            yylval.vr = atof(yytext);
                            return BROJ;
                       }
[a-z]+      {
                yylval.id = strdup(yytext);
                return ID;
            }
[ \n\t]     {}
.           {
                cerr << "Leksicka greska!" << endl;
                exit(EXIT_FAILURE);
            }
%%
