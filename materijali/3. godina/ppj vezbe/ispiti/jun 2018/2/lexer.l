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
"["     return UO;
"]"     return UZ;
","     return ZAR;
"="     return DOD;
disp    return DISP;
[0-9]+  return BROJ;
[a-zA-Z]  return ID;
\n      return EOI;
[ \t]   {}
.       {
            fprintf(stderr, "Leksicka greska!\n");
            exit(EXIT_FAILURE);
        }
%%
