TARGET = 3
CXX = g++
CFLAGS=-Wall -std=c++11


	
$(TARGET): 03_parser.tab.o lex.yy.o
	$(CXX) $(CFLAGS) -o $@ $^

lex.yy.o: lex.yy.c 03_parser.tab.hpp
	$(CXX) $(CFLAGS) -c -o $@ $<
	
lex.yy.c: 03_lexer.lex 03_parser.tab.hpp
	flex $<

03_parser.tab.o: 03_parser.tab.cpp 03_parser.tab.hpp
	$(CXX) $(CFLAGS) -c -o $@ $<

03_parser.tab.cpp 03_parser.tab.hpp: 03_parser.ypp
	bison -d -v $<


.PHONY: clean

clean:
	rm $(TARGET) lex.yy.* *.tab.* *.output *~ 
