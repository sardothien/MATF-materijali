prog: lex.yy.o parser.tab.o vektor.o
	g++ -Wall -std=c++11 -o prog lex.yy.o parser.tab.o vektor.o -lm
	
vektor.o: vektor.cpp vektor.hpp
	g++ -Wall -std=c++11 -c vektor.cpp
	
lex.yy.o: lex.yy.c
	g++ -Wall -std=c++11 -c lex.yy.c
	
lex.yy.c: lexer.lex parser.tab.hpp
	flex lexer.lex
	
parser.tab.o: parser.tab.cpp parser.tab.hpp
	g++ -std=c++11 -Wall -c parser.tab.cpp
	
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -v -d parser.ypp
