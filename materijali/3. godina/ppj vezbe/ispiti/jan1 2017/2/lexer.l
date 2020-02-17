%option noyywrap
%option noinput
%option nounput

%{
    #include"tokeni.h"
    extern int yylval;
%}

%%
date        return DATE;
";"         return TZ;
","         return ZAR;
"="         return DOD;
"/"         return KOSA;
"."         return TACKA;
"-"         return CRTA;
"'"         return APOS;
[0-9]+      return BROJ;
[a-z][a-z0-9]*  return ID;
\n              return EOI;
[ \t] {}
.   {
        fprintf(stderr, "Leksicka greska!\n");
        exit(EXIT_FAILURE);
    }
%%
