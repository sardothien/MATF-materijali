prog: lex.yy.c parser.c
	gcc -Wall -o prog lex.yy.c parser.c
	
lex.yy.c: lexer.l
	flex lexer.l
