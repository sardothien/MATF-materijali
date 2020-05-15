#include <stdio.h>
#include "2.h"

int main(){
 int x;
 cvor *lista = NULL;

 while(1){
  scanf("%d", &x);
  if(x == 0)
   break;
  dodaj_na_kraj(&lista, x);
 }
  
 scanf("%d", &x);
  
 obrisi_cvor(&lista, x);
 ispis(lista); 
 oslobodi_listu(lista);
 
 return 0;
}
