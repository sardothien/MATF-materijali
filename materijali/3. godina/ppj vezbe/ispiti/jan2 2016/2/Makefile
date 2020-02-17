prog: lex.yy.c parser.c tokeni.h
	gcc -Wall -Wextra -o prog lex.yy.c parser.c tokeni.h
	
lex.yy.c: lexer.l
	flex lexer.l
