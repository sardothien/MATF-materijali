#include <stdio.h>
#include <stdlib.h>
#include "stabla.h"

// proizvod parnih nivoa
int proizvod(Cvor *koren, int nivo){
 if(koren == NULL)
  return 1;
 
 if(nivo % 2 == 0)
  return koren->vrednost 
       * proizvod(koren->levo, nivo+1)
       * proizvod(koren->desno, nivo+1);
 else
  return proizvod(koren->levo, nivo+1)
       * proizvod(koren->desno, nivo+1) ;
}

int main(){
 FILE *in = fopen("stablo.txt", "r");
 if(in == NULL)
  greska();
 
 Cvor *koren = NULL;
 
 ucitaj_stablo(&koren, in);
 
 if(koren == NULL)
  printf("0\n");
 else
  printf("%d\n", proizvod(koren, 0));
 
 oslobodi_stablo(koren);
 fclose(in);
 
 return 0;
}
