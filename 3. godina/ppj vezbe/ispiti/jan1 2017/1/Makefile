prog: lex.yy.o parser.tab.o datum.o
	g++ -std=c++11 -Wall -o prog lex.yy.o parser.tab.o datum.o
	
datum.o: datum.cpp datum.hpp
	g++ -std=c++11 -Wall -c datum.cpp
	
lex.yy.o: lex.yy.c parser.tab.hpp
	g++ -std=c++11 -Wall -c lex.yy.c
	
lex.yy.c: lexer.lex
	flex lexer.lex
	
parser.tab.o: parser.tab.cpp parser.tab.hpp
	g++ -std=c++11 -Wall -c parser.tab.cpp
	
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v parser.ypp
