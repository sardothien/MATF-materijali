%option noyywrap
%option noinput
%option nounput

%{
    #include<stdio.h>
    #include<stdlib.h>
    #include"tokeni.h"
%}

%%
"("     return OZ;
")"     return ZZ;
";"     return TZ;
"|"     return ILI;
"&"     return III;
"~"     return NEG;
"="     return DOD;
int     return INT;
print   return PRINT;
[+-]?[0-9]+  return BROJ;
_[a-z][a-z0-9]* return ID;
\n      return EOI;
[ \t] {}
.   {
        fprintf(stderr, "Leksicka greska!\n");
        exit(EXIT_FAILURE);
    }
%%
