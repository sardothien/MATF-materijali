prog: lex.yy.o parser.tab.o matrice.o
	g++ -std=c++11 -Wall -o prog lex.yy.o parser.tab.o matrice.o
	
matrice.o: matrice.cpp matrice.hpp
	g++ -std=c++11 -Wall -c matrice.cpp
	
lex.yy.o: lex.yy.c
	g++ -std=c++11 -Wall -c lex.yy.c
	
lex.yy.c: lexer.lex parser.tab.hpp
	flex lexer.lex
	
parser.tab.o: parser.tab.cpp parser.tab.hpp
	g++ -std=c++11 -Wall -c parser.tab.cpp
	
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v parser.ypp
