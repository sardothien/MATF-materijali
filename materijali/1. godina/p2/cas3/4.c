/* Napisati program koji u datoteci cije se ime
zadaje kao argument komandne linije, pronalazi i na
standardni izlaz ispisuje sve linije u kojima se
zadata rec pojavljuje n puta. Trazena rec i broj
pojavljivanja n se zadaju sa standardnog ulaza.
Maksimalna duzina reci je 20 karaktera. U slucaju
greske, na standardni izlaz za greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 21
#define MAX_L 100

int main(int argc, char *argv[]){
 if(argc!=2){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 FILE *in=fopen(argv[1], "r");
 if(in==NULL){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 char rec[MAX], lrec[MAX];
 char *linija;
 int n, d;
 size_t duzina=0;
 linija=malloc((MAX_L+1)*sizeof(char));
 
 scanf("%d%s", &n, rec);
 while((d=getline(&linija, &duzina, in))!=-1){
  int ucitano=0, br=0;
  while(1){
   int k;
   if(sscanf(linija+ucitano, "%s%n", lrec, &k)<1){
    break;
   }
   ucitano+=k;
   if(strcmp(lrec, rec)==0){
    br++;
   }
  }
  if(br==n){
   printf("%s", linija);
  }
 }
 
 fclose(in);
 free(linija);
 
 return 0;
}
