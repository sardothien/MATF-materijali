/* Programu se kroz argumente komandne linije zadaje
proizvoljan broj razlomaka u formatu a/b. Na standardni
izlaz ispisati vrednosti ovih razlomaka zapisane na dve
decimale. U slucaju greske na standardni izlaz za
greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void provera(char *s){
 int i, br=0;
 if(!isdigit(s[0])){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 } 
 for(i=0; s[i]; i++){
  if(s[i]=='/'){
   br++;
   continue;
  }
  if(!isdigit(s[i])){
   fprintf(stderr, "-1\n");
   exit(EXIT_FAILURE);
  }
 } 
 if(br!=1 || !isdigit(s[i-1])){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 } 
}

int main(int argc, char *argv[]){
 int i, br, im;
 
 for(i=1; i<argc; i++){
  provera(argv[i]);
 }
 
 for(i=1; i<argc; i++){
  sscanf(argv[i], "%d/%d", &br, &im);
  printf("%.2f\n", (float)br/im);
 }
  
 return 0;
}
