/* Napisati funkciju int veci_od_proseka() koja ucitava
cele brojeve sa standarnog ulaza sve dok se ne ucita 0.
Broj brojeva nije unapred poznat. Funkcija vraca broj
brojeva vecih od proseka. Ako nema unetih brojeva
funkcija treba da vrati 0. Testirati napisanu funkciju
pozivom iz glavnog programa i na standardni izlaz
ispisati rezultat izvrsavanja funkcije. U slucaju
greske, na standardni izlaz za greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int veci_od_proseka(){
 int *niz;
 int i=0, abr=0, k=5;
 int suma=0;
 niz=malloc(k*sizeof(int));
 if(niz==NULL)
  greska();

 while(1){
  scanf("%d", &niz[i]);
  if(niz[i]==0)
   break;
  suma+=niz[i];
  i++;
  abr++;  
  if(i==abr){
   niz=realloc(niz, k*sizeof(int));
   abr=0;
  }
 }
 
 if(i==0)
  return 0;
 
 float prosek=suma/i;
 int br=0;
 for(k=0; k<i; k++)
  if(niz[k]>prosek) 
   br++;
   
 return br;  
}

int main(){
 int *niz;
 
 printf("%d\n", veci_od_proseka());
 
 free(niz);
 return 0;
}
