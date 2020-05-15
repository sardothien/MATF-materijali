#include <stdio.h>
#include <stdlib.h>
#include "2.h"

int main(){
 cvor *koren1=NULL;
 cvor *koren2=NULL;
 
 ucitaj_stablo(&koren1, stdin);
 ucitaj_stablo(&koren2, stdin);
 
 if(jednaki(koren1,koren2))
  printf("Ne\n");
 else
  printf("Da\n");
  
 oslobodi(koren1);
 oslobodi(koren2);
 
 return 0;
}
