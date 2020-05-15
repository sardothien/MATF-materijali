/* Napisati program koji na standarni izlaz ispisuje broj
linija u tekstualnom fajlu sa imenom knjiga.txt. U slucaju
greske na standardni izlaz za greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>

int main(){
 FILE *in;
 char linija[81];
 int br=0;
 
 in=fopen("knjiga.txt", "r");
 if(in==NULL){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 while(fgets(linija, 80, in)!=NULL){
  br++;
 }
 
 printf("%d\n", br);
 fclose(in);
 
 return 0;
}
