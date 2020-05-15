#include <stdio.h>
#include <stdlib.h>
#include "7.h"

int main(){
 cvor *lista = NULL;
 int x;
 
 while(1){
  scanf("%d", &x);
  if(x==0)
   break;
  dodaj_na_kraj(&lista, x); 
 }
 
 int k;
 scanf("%d", &k);
 
 obrisiZ(&lista, k);
 ispis(lista);
 oslobodi_listu(lista);
 
 return 0;
}
