%option noyywrap
%option noinput
%option nounput

%{
    #include<iostream>
    #include<cstdlib>
    #include"lista.hpp"
    #include"parser.tab.hpp"
    using namespace std;
%}

%%
car     return CAR;
cdr     return CDR;
cons    return CONS;
append  return APPEND;
if      return IF_T;
eql     return EQL;
null    return NULL_T;
[0-9]+  {   
            yylval.vr = atoi(yytext);
            return BROJ;
        }
[()+*'] return *yytext;
\n  return *yytext;
[ \t] {}
. {
    cerr << "Leksicka greska!" << endl;
    exit(EXIT_FAILURE);
  }
%%
