%option noyywrap

%{
    #include "tokeni.h"
%}

%%
while 	return WHILE_TOKEN;
if 		return IF_TOKEN;
begin 	return BEGIN_TOKEN;
end 	return END_TOKEN;
do 		return DO_TOKEN;
then 	return THEN_TOKEN;

"(" 	return LZ;
")" 	return DZ;
":=" 	return DTJ;
[<>] 	return ROP;
[a-z]+ 	return ID;
[0-9]+ 	return BROJ;
; 		return TZ;

[\n\t ] {}
. 		{ 
            fprintf(stderr, "Nepoznata leksema %s.\n",yytext);
			exit(EXIT_FAILURE);
        }
%%
