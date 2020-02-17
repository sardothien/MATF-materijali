#include <stdio.h>
#include <stdlib.h>
#include "1.h"

int main(){ 
 cvor *koren=NULL;
 ucitaj_stablo(&koren, stdin);
 ispis_infiksno(koren);
 printf("\n");
  
 cvor *najmanji = najmanji_broj(koren);
 if(najmanji != NULL)
 printf("%d\n", najmanji->br);
  
 cvor *najveci = najveci_broj(koren);
 if(najveci != NULL)
  printf("%d\n", najveci->br);
 
 int x;
 scanf("%d", &x);
 if(pretrazi_stablo(koren, x) != NULL){
  printf("Nalazi se u stablu.\n");
  obrisi_cvor(&koren, x);
 }
 else
  printf("Ne nalazi se u stablu.\n"); 
  
 ispis_infiksno(koren);
 printf("\n"); 
 
 oslobodi(koren);
 
 return 0;
}
