%option noyywrap
%option noinput
%option nounput

%{
    #include<stdio.h>
    #include<stdlib.h>
    #include"tokeni.h"
%}

%%
"/\\"   return KONJ;
"\\/"   return DISJ;
"!"     return NEG;
":="    return DOD;
True    return TRUE;
False   return FALSE;
Undef   return UNDEF;
[a-z][a-z0-9]*  return ID;
[ \t]   {}
.       {
            fprintf(stderr, "Leksicka greska!\n");
            exit(EXIT_FAILURE);
        }
%%
