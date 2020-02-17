/* Napraviti funkciju koja generise slucajan realan broj od 0 i
1. Na standardni izlaz ispisati rezultat izvrsavanja napisane
funkcije. */

#include <stdio.h>
#include <stdlib.h>

int main(){
 
 printf("%.2f\n", (float)rand()/RAND_MAX);
 
 return 0;
}
