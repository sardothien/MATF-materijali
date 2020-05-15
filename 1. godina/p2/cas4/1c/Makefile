main: 1.o polinom.o
	gcc -Wall -o main 1.o polinom.o

1.o: 1.c
	gcc -c -Wall -o 1.o 1.c

polinom.o: polinom.c
	gcc -c -Wall -o polinom.o polinom.c

.PHONY: brisanje

brisanje:
	rm *.o *~
