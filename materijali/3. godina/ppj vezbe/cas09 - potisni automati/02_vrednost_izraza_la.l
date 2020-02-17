%option noyywrap
%option noinput
%option nounput

%{
    #include "tokeni.h"
    extern int yyval;
%}

%%
[0-9]+ {
            yyval = atoi(yytext);
            return BROJ;
       }
"+" return PLUS;
"*" return PUTA;
"(" return LZ;
")" return DZ;
\n  return EOI;
[ \t] {}
. {
        fprintf(stderr, "Leksicka greska! Neocekivan token: %s\n", yytext);
        exit(EXIT_FAILURE);
  }
%%

/*
int main(){
  int token;
  
  while((token =yylex()) != EOI);
  
  return 0;
} */
