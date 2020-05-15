/* Ako su celi brojevi a i b argumenti komandne linije na
standardni izlaz ispisati sve brojeve koji pripadaju intervalu
[a, b]. U slucaju greske na standardni izlaz ispisati -1. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
 if(argc!=3){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 if(atoi(argv[1])>atoi(argv[2])){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 int i;
 for(i=atoi(argv[1]); i<=atoi(argv[2]); i++){
  printf("%d ", i);
 }
 
 printf("\n"); 
 
 return 0;
}
