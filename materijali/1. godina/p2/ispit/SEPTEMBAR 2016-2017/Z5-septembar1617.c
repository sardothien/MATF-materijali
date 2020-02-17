#include <stdio.h>
#include <stdlib.h>
#include "stabla.h"

int visina_stabla(Cvor *koren){
 if(koren == NULL)
  return 0;
 
 int l = visina_stabla(koren->levo);
 int d = visina_stabla(koren->desno);
 if(d <= l)
  return l+1;
 else
  return d+1;
}

// suma poslednjeg nivoa
int suma(Cvor *koren, int nivo, int l){
 if(koren == NULL)
  return 0;
 
 if(l == nivo)
  return koren->vrednost;
 else
  return suma(koren->levo, nivo, l+1)
       + suma(koren->desno, nivo, l+1);
}

int main(){
 FILE *in = fopen("stablo.txt", "r");
 if(in == NULL)
  greska();

 Cvor *koren = NULL;
 ucitaj_stablo(&koren, in);
 
 printf("%d\n", suma(koren, visina_stabla(koren), 1));
 
 oslobodi_stablo(koren);
 fclose(in);
 
 return 0;
}
