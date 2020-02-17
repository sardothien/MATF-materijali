prog: lex.yy.o parser.tab.o liste.o
	g++ -Wall -std=c++11 -o prog lex.yy.o parser.tab.o liste.o
	
liste.o: liste.cpp liste.hpp
	g++ -Wall -std=c++11 -c liste.cpp
	
lex.yy.o: lex.yy.c 
	g++ -Wall -std=c++11 -c lex.yy.c
	
lex.yy.c: lexer.lex parser.tab.hpp
	flex lexer.lex
	
parser.tab.o: parser.tab.cpp parser.tab.hpp
	g++ -Wall -std=c++11 -c parser.tab.cpp 
	
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -v -d parser.ypp
