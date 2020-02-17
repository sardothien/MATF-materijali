%option noyywrap
%option noinput
%option nounput

%{
    #include<stdio.h>
    #include<stdlib.h>
    #include"tokeni.h"
%}

%%
print   return PRINT;
":="    return DOD;
","     return ZAR;
";"     return TZ;
"("     return OZ;
")"     return ZZ;
"<"     return UO;
">"     return UZ;
"+"     return PLUS;
"-"     return MINUS;
"*"     return PUTA;
[+-]?[0-9]+(\.[0-9]+)? return BROJ;
[a-z]+  return ID;
[ \n\t]     {}
.           {
                fprintf(stderr, "Leksicka greska!\n");
                exit(EXIT_FAILURE);
            }
%%
