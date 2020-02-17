#include <stdio.h>
#include "stabla.h"

int prebroj(Cvor *koren){
 if(koren == NULL)
  return 0;
 if(koren->vrednost < 0)
  greska();
  
 if(koren->vrednost % 2 == 0){
  int br = 0;
  if(koren->levo != NULL)
   br = 1 + prebroj(koren->levo); 
  if(koren->desno != NULL)
   br = br + 1 + prebroj(koren->desno); 
  return br;
 }
 else
  return prebroj(koren->levo) + prebroj(koren->desno);
}

int main(){
 FILE *in = fopen("stablo.txt", "r");
 if(in == NULL)
  greska();
 
 Cvor *koren = NULL;
 ucitaj_stablo(&koren, in);
 
 printf("%d\n", prebroj(koren)); 
 
 oslobodi_stablo(koren);
 fclose(in);
 
 return 0;
}
