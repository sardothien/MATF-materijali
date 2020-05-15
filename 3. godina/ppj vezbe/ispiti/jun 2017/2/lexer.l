%option noyywrap
%option noinput
%option nounput

%{
    #include<stdio.h>
    #include<stdlib.h>
    #include"tokeni.h"
    extern int yylval;
%}

%%
"["         return OZ;
"]"         return ZZ;
"."         return TACKA;
";"         return TZ;
","         return ZAR;
print       return PRINT;
[+-]?[0-9]+ return BROJ;
\n          return EOI;
[ \t]     {}
.           {
                fprintf(stderr, "Leksicka greska!");
                exit(EXIT_FAILURE);
            }
%%
