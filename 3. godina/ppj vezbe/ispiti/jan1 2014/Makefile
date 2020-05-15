prog: lex.yy.o parser.tab.o liste.o prom.o
	g++ -std=c++11 -Wall -o prog lex.yy.o parser.tab.o liste.o prom.o
	
liste.o: liste.cpp liste.hpp
	g++ -std=c++11 -Wall -c liste.cpp liste.hpp
	
prom.o: prom.cpp prom.hpp
	g++ -std=c++11 -Wall -c prom.cpp prom.hpp

parser.tab.o: parser.tab.cpp parser.tab.hpp
	g++ -std=c++11 -Wall -c -o parser.tab.o parser.tab.cpp
	
lex.yy.o: lex.yy.c parser.tab.hpp
	g++ -std=c++11 -Wall -c lex.yy.c
	
lex.yy.c: lexer.lex
	flex lexer.lex
	
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v parser.ypp
