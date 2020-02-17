#include <stdio.h>
#include <stdlib.h>
#include "6.h"
 
int main(){
 FILE *in = fopen("izraz.txt", "r");
 if(in == NULL)
  greska();
  		
 Cvor* stablo = ucitaj(in);
 ispisi(stablo);
 printf("\n");
	
 printf("Vrednost izraza: %.2f\n", vrednost(stablo));
	
 fclose(in);
 oslobodi(stablo);
 
 return 0;
}
