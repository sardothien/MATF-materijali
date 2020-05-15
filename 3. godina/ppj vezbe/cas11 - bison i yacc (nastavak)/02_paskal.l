/* Pseudo Paskal */

%option noyywrap

%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<ctype.h>
    #include"y.tab.h"
%}

%%
ispisi return ISPISI;
pocetak return POCETAK;
kraj return KRAJ;
mod return MOD;
":=" return DOD;
["][A-Za-z\t !\-?.;,:0-9]+["] {
                                  strncpy(yylval.niska, yytext+1, strlen(yytext)-2);
                                  return NISKA;
                              }
[0-9]+|0[xX][a-fA-F0-9]+ {
                            yylval.vr = atoi(yytext);
                            return BROJ;
                         }
[a-zA-Z] {
            yylval.ime = tolower(*yytext);
            return ID;
         }
[.+*;()] return *yytext;
[\t \n] {}
. {
      fprintf(stderr, "Leksicka greska!\n");
      exit(EXIT_FAILURE);
  }
%%

/*
int main(){
	int token; 
	while(token = yylex())
		printf("%d\n", token);
	return 0;
}
*/
