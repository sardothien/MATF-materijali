prog: lex.yy.o parser.tab.o
	g++ -std=c++11 -Wall -o prog lex.yy.o parser.tab.o 
	
lex.yy.o: lex.yy.c
	g++ -std=c++11 -Wall -c lex.yy.c
	
lex.yy.c: lexer.lex parser.tab.hpp
	flex lexer.lex
	
parser.tab.o: parser.tab.cpp parser.tab.hpp
	g++ -std=c++11 -Wall -c parser.tab.cpp
	
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -v -d parser.ypp
