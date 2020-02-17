/* Napisati program koji sa standardnog ulaza
ucitava niz razlomaka. Prvo se ucita broj razlomaka,
a zatim i razlomci u obliku brojilac imenilac. Na 
standardni izlaz ispisati sve razlomke cija je vrednost
veca od prosecne vrednosti svih ucitanih razlomaka, u obliku
brojilac/imenilac. Ne praviti nikakve pretpostavke o
maksimalnoj dimenziji niza. U slucaju greske na standardni 
izlaz za greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>

int main(){
 int n;
 float s=0;
 int *niz;
 
 scanf("%d", &n);
 
 niz=(int *)malloc(2*n*sizeof(int));
 if(niz==NULL){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 int i;
 for(i=0; i<2*n; i+=2){
  scanf("%d %d", &niz[i], &niz[i+1]);
  s=s+(float)niz[i]/niz[i+1];
 }
 
 s=s/n;
 
 for(i=0; i<2*n; i+=2){
  if((float)niz[i]/niz[i+1] > s){
   printf("%d/%d\n", niz[i], niz[i+1]);
  }
 }
 
 free(niz);
 
 return 0;
}
