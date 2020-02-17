#include <stdio.h>
#include "stabla.h"

int prebrojavanje(Cvor *koren){
 if(koren == NULL)
  return 0;
 if(koren->vrednost < 0)
  greska();
 
 if(koren->levo != NULL && koren->desno != NULL){
  if(koren->levo->vrednost % 2 == 1 && koren->desno->vrednost % 2 == 0)
   return 1 + prebrojavanje(koren->levo) + prebrojavanje(koren->desno);  
  else if(koren->levo->vrednost % 2 == 0 && koren->desno->vrednost % 2 == 1)
   return 1 + prebrojavanje(koren->levo) + prebrojavanje(koren->desno);
  else 
   return prebrojavanje(koren->levo) + prebrojavanje(koren->desno);
 } 
 else if(koren->levo == NULL && koren->desno != NULL){
  if(koren->desno->vrednost % 2 == 1)
   return 1 + prebrojavanje(koren->desno);
  else
   return prebrojavanje(koren->desno);
 }
 else if(koren->levo != NULL && koren->desno == NULL){
  if(koren->levo->vrednost % 2 == 1)
   return 1 + prebrojavanje(koren->levo);
  else
   return prebrojavanje(koren->levo);
 }
 else 
  return 0;
}

int main(){
 FILE *in = fopen("stablo.txt", "r");
 if(in == NULL)
  greska();
 
 Cvor *koren = NULL;
 ucitaj_stablo(&koren, in);
 
 printf("%d\n", prebrojavanje(koren));
 
 oslobodi_stablo(koren); 
 fclose(in);
 
 return 0;
}
