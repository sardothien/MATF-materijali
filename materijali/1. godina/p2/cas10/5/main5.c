#include <stdio.h>
#include <stdlib.h>
#include "5.h"

int main(){
 cvor *lista = NULL;
 int x;
 while(1){
  scanf("%d", &x);
  if(x==0)
   break;
  dodaj_na_kraj(&lista, x);
 }
 
 obrisi_manje(lista);
 ispis(lista);
 oslobodi_listu(lista); 
 
 return 0;
}
