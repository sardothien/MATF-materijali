#include <stdio.h>
#include <stdlib.h>
#include "6.h"

int main(){
 int x;
 cvor *lista = NULL;
 
 while(1){
  scanf("%d", &x);
  if(x==0)
   break;
  dodaj_na_kraj(&lista, x);
 }
 
 int k;
 scanf("%d", &k);
 
 dodaj_1(lista, k);
 ispis(lista);
 oslobodi_listu(lista);
 
 return 0;
}
