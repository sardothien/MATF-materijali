/* LEKSER */
%option noyywrap
%option noinput
%option nounput

%{
	#include "tokeni.h"
	extern int yyval;
%}

%%
"+" return PLUS;
"-" return MINUS;
"*" return PUTA;
"("  return LZ;
")" return DZ;
"/" return PODELJENO;
[0-9]+ { 
            yyval = atoi(yytext);
            return BROJ;	
       }
"\n" return EOI;
. {
    fprintf(stderr,"Leksicka greska: Nepoznata leksema %s!\n", yytext);
	exit(EXIT_FAILURE);	
  }
%%

/*
int main() {
  int token;
  
  while(token = yylex());
  
  return 0;
}*/
