/* LEKSER */
%option noyywrap

%{
    #include<stdio.h>
    #include<stdlib.h>
    #include"tokeni.h"
    extern int yyval;
%}

%%
"+" { return PLUS; }
"*" { return PUTA; }
"(" { return LZ; }
")" { return DZ; }
[0-9]+ { 
            yyval = atoi(yytext);
            return BROJ; 
       }
\n { return EOI; }
. { 
        fprintf(stderr, "Leksicka greska\n");
        exit(EXIT_FAILURE);
  }
%%
