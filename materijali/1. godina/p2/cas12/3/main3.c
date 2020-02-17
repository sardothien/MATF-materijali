#include <stdio.h>
#include <stdlib.h>
#include "3.h"

int main(){ 
 cvor *koren=NULL;
 ucitaj_stablo(&koren, stdin);
  
 printf("Broj cvorova: %d\n", broj_cvorova(koren)); 
 printf("Broj listova: %d\n", broj_listova(koren));
 
 printf("Pozitivni listovi: ");
 ispis_poz_listova(koren);
 printf("\n");

 printf("Zbir cvorova: %d\n", zbir_cvorova(koren));
 
 cvor *najveci = najveci_broj(koren);
 if(najveci != NULL)
  printf("Najveci element: %d\n", najveci->br);
 
 printf("Dubina stabla: %d\n", dubina(koren));
 
 int i;
 scanf("%d", &i);
 printf("Broj cvorova na %d. nivou: %d\n", i, br_i_nivo(koren, i));
 ispis_i_nivo(koren, i);
 printf("\n");
 cvor *max = max_i_nivo(koren, i);
 printf("Najveci na %d. nivou: %d\n", i, max->br);
 printf("Zbir na %d. nivou: %d\n", i, zbir_i_nivo(koren, i));
  
 int x;
 scanf("%d", &x);
 printf("Zbir <= od %d: %d\n", x, zbir_manjih_od_x(koren, x));
 
 oslobodi(koren);
 
 return 0;
}
