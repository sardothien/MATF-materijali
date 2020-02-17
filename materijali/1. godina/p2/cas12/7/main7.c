#include <stdio.h>
#include <stdlib.h>
#include "7.h"

int main(){
 FILE *in = fopen("karakteri.txt", "r");
 if(in == NULL) 
  greska();
 
 cvor* stablo = napravi_stablo_iz_fajla(in);
 cvor* maks = maks_ponavljanja(stablo);
 printf("'%c': %d\n", maks->slovo, maks->br);
 
 fclose(in);
 oslobodi(stablo);
	
 return 0;
}
