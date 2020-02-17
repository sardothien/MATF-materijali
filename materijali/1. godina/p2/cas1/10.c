/* Napisati program koji poredi dva fajla i ispisuje redni broj
linija u kojima se fajlovi razlikuju. Imena fajlova se zadaju kao
argumenti komandne linije. Pretpostaviti da je maksimalna duzina
reda u datoteci 200 karaktera. Linije brojati pocevsi od 1. U
slucaju greske na standardni izlaz za greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
 if(argc!=3){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 FILE *dat1=fopen(argv[1], "r");
 FILE *dat2=fopen(argv[2], "r");
 if(dat1==NULL || dat2==NULL){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);  
 }
 
 char bafer1[201];
 char bafer2[201];
 int i=1;
 
 while(fgets(bafer1, 200, dat1)!=NULL){
  if(fgets(bafer2, 200, dat2)!=NULL){
   if(strcmp(bafer1, bafer2)!=0){
    printf("%d ", i);
   }
  }
  else{
   printf("%d ", i);
  }
  i++;
 }
 
 while(fgets(bafer2, 200, dat2)!=NULL){
  printf("%d ", i);
  i++;
 }
 
 fclose(dat1);
 fclose(dat2);
  
 return 0;
}
