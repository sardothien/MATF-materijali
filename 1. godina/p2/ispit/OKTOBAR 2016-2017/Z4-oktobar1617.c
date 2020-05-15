#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

Cvor *brisanje(Cvor *lista){
 if(lista == NULL)
  return NULL;
 if(lista->sledeci == NULL || lista->sledeci->sledeci == NULL)
  return lista;
 
 int bris = 0;
 
 if(lista->vrednost + lista->sledeci->sledeci->vrednost 
  > lista->sledeci->vrednost)
   bris = 1;
 lista->sledeci = brisanje(lista->sledeci);
 
 if(bris){
  Cvor *tmp = lista->sledeci;
  lista->sledeci = lista->sledeci->sledeci;
  free(tmp);
 }
 return lista;
}

int main(){
 Cvor *lista = NULL;
 ucitaj_listu(&lista, stdin);
 
 lista = brisanje(lista);
 ispisi_listu(lista);
 
 oslobodi_listu(lista);
 return 0;
}
