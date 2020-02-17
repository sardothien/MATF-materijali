%option noyywrap
%option noinput
%option nounput

%{
    #include "tokeni.h"
%}

%%
while 	return WHILE_TOKEN;
if 	    return IF_TOKEN;
begin 	return BEGIN_TOKEN;
end 	return END_TOKEN;
then 	return THEN;
do 	    return DO;

[a-z]+[A-Za-z0-9_]*  return ID;
:= 		             return DOD;
[<>=]=?		         return ROP;
"(" 		         return LZ;
")" 		         return DZ;
;		             return TZ;
[0-9]+(\.[0-9]+)?    return BROJ;
[ \t\n] {}
.   {
      fprintf(stderr,"Leksicka greska: Nepoznata leksema %s\n", yytext);
      exit(EXIT_FAILURE);
    }
%%

/*
int main(){
  int token ;

  while((token = yylex() )!=EOI)
    ;

  return 0;
}*/
