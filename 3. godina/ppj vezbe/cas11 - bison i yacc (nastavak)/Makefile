parser: 05_y.tab.c lex.yy.c
	gcc -o izvrsni 05_y.tab.c lex.yy.c -g
	
lex.yy.c: 05_lexer.l
	flex 05_lexer.l
	
05_y.tab.c: 05_parser.y
	yacc -d -v 05_parser.y
