prog: lex.yy.o parser.tab.o lista.o
	g++ -Wall -std=c++11 -o prog lex.yy.o parser.tab.o lista.o
	
lista.o: lista.cpp lista.hpp
	g++ -std=c++11 -c lista.cpp -o lista.o
	
parser.tab.o: parser.tab.cpp parser.tab.hpp
	g++ -Wall -std=c++11 -c -o parser.tab.o parser.tab.cpp
	
lex.yy.o: lex.yy.c parser.tab.hpp
	g++ -Wall -std=c++11 -c -o lex.yy.o lex.yy.c
	
lex.yy.c: lexer.lex parser.tab.hpp
	flex lexer.lex
	
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -v -d parser.ypp
