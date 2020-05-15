#include <stdio.h>
#include <stdlib.h>
#include "stabla.h"

int svi_parni(Cvor *koren){
 if(koren == NULL)
  return 1;
 return koren->vrednost % 2 == 0 
     && svi_parni(koren->levo)
     && svi_parni(koren->desno); 
}

int parni(Cvor *koren){
 if(koren == NULL)
  return 0;
 
 if(svi_parni(koren))
  return 1 + parni(koren->levo) + parni(koren->desno);
 else
  return parni(koren->levo) + parni(koren->desno);
}

int main(){
 Cvor *koren = NULL;
 ucitaj_stablo(&koren, stdin);
 
 printf("%d\n", parni(koren));
 
 oslobodi_stablo(koren);
 
 return 0;
}
