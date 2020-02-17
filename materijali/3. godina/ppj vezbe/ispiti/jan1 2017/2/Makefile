prog: lex.yy.c 2.c tokeni.h
	gcc -Wall -Wextra -o prog lex.yy.c 2.c tokeni.h
	
lex.yy.c: lexer.l
	flex lexer.l
