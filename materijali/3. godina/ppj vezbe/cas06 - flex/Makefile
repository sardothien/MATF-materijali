PROGRAM = 01_wc.l

lexer: lex.yy.c
	gcc -o lexer -Wall lex.yy.c
	
lex.yy.c: $(PROGRAM)
	flex  $(PROGRAM)
