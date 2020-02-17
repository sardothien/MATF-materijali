%option noyywrap
%option noinput
%option nounput

%{
    #include<stdio.h>
    #include<stdlib.h>
    #include"tokeni.h"
%}

%%
"True"  return TRUE_ID;
"False" return FALSE_ID;
"/\\"   return KONJ;
"\\/"   return DISJ;
"!"     return NEG;
"("     return OZ;
")"     return ZZ;
[a-z][a-z0-9]*  return ID;
\n      return EOI;
[ \t] {}
. {
    fprintf(stderr, "Leksicka greska!\n");
    exit(EXIT_FAILURE);
  }
%%
