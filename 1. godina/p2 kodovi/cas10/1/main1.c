#include <stdio.h>
#include "1.h"

int main() {
 int n; 
 scanf("%d", &n);
 if(n<=0)
  greska();
 
 cvor *lista=NULL;
 int x;
 
 int i; 
 for(i=0; i<n; i++){
  scanf("%d", &x);
  dodaj_na_pocetak(&lista, x);
 // dodaj_na_kraj(&lista, x);
 }
 
 ispis(lista);
 oslobodi_listu(lista);
 
 return 0;
}
