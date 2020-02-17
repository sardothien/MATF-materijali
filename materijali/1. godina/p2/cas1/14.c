/* Sastaviti program koji sa standardnog ulaza
prima ime datoteke koju treba otvoriti. Ispisati 
(na standardnom izlazu) koja cifra (medju svim
ciframa koje se pojavljuju u datoteci) ima najveci
broj pojavljivanja. Ukoliko nema cifara u datoteci
na standardni izlaz ispisati -1. Maksimalna duzina
naziva datoteka je 20 karaktera. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 21

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int main(){
 
 char naziv[MAX];
 scanf("%s", naziv);
 
 FILE *in=fopen(naziv, "r");
 if(in==NULL)
  greska();
 
 char c;
 int a[10], i, ind=0;
 
 for(i=0; i<10; i++){
  a[i]=0;
 }
 
 while((c=fgetc(in))!=EOF){
  if(c>='0' && c<='9'){
   ind=1;
   a[c-'0']++;
  }
 }
 
 fclose(in);
 
 if(ind==0)
  greska();
 
 int max=0, br;
 for(i=0; i<10; i++){
  if(a[i]>max){
   max=a[i];
   br=i;
  }
 }
 
 printf("%d\n", br);
 
 return 0;
}
