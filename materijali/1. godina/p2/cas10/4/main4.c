#include <stdio.h>
#include <stdlib.h>
#include "4.h"

int main(int argc, char *argv[]){
 if(argc!=2)
  greska();
 
 FILE *in=fopen(argv[1], "r");
 if(in==NULL)
  greska();
 
 cvor *lista = NULL;
 ucitaj_listu(&lista, in);
 
 int x;
 scanf("%d", &x);
 
 printf("%d\n", veci_od(lista, x));
 
 oslobodi_listu(lista);
 
 return 0;
}
