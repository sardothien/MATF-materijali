%option noyywrap
%option noinput
%option nounput

%{
    #include<iostream>
    #include<string>
    #include"03_polinom.hpp"
    #include"03_polinomi.tab.hpp"
    using namespace std;
%}

%%
-?[0-9]+(\.[0-9]+)? {
                        yylval.vr = atof(yytext);
                        return BROJ;
                    }
[a-zA-Z][a-zA-Z0-9]+ {
                        yylval.id = new string(yytext);
                        return ID;
                     }
[<>,\n+*()!$|'\[\]-] return *yytext;
:=  return DODELA;
!=  return NEQ;
==  return EQ;
[ \t] {}
. {
    cerr << "Leksicka greska!" << endl;
    exit(EXIT_FAILURE);
  }
%%
