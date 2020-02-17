CXXFLAGS = -Wall -std=c++11 -g

izvrsni: parser.tab.o lex.yy.o skup.o
	g++ -o $@ $(CXXFLAGS) $^
	
skup.o: skup.cpp
	g++ -c $(CXXFLAGS) $<
	
lex.yy.o: lex.yy.c
	g++ -c $(CXXFLAGS) $<
	
lex.yy.c: lexer.l parser.tab.hpp
	flex lexer.l

parser.tab.o: parser.tab.cpp
	g++ -c $(CXXFLAGS) $<
	
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v parser.ypp
