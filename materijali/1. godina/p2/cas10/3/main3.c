#include <stdio.h>
#include "3.h"

int main(int argc, char *argv[]){
 if(argc!=3)
  greska();
 
 FILE *in1=fopen(argv[1], "r");
 if(in1==NULL)
  greska();
 FILE *in2=fopen(argv[2], "r");
 if(in2==NULL)
  greska();
 
 cvor *lista1 = NULL;
 cvor *lista2 = NULL;
 
 ucitaj_listu(&lista1, in1);
 ucitaj_listu(&lista2, in2);
 
 cvor *rez;
 merge(lista1, lista2, &rez);
 ispis(rez);
 oslobodi_listu(rez);
  
 return 0;
}
