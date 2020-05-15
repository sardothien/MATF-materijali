/* Parametri komandne linije su n, a, b (a < b). Na standardni
izlaz ispisati n slucajnih brojeva koji su izmedju a i b. U
slucaju greske na standardni izlaz za greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){
 if(argc!=4){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 int n, a, b;
 n=atoi(argv[1]);
 a=atoi(argv[2]);
 b=atoi(argv[3]);
 
 if(n>200 || a>=b){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 srand(time(NULL));
 
 int i;
 for(i=0; i<n; i++){
  printf("%d ", (int)(a+(b-a)*((float)rand()/RAND_MAX)));
 }
 
 return 0;
}
