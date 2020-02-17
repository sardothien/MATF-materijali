#include <stdio.h>
#include "liste.h"

Cvor *izmena(Cvor *lista){
 if(lista == NULL) 
  return NULL;
 if(lista->sledeci == NULL)
  return lista;
  
 if(lista->vrednost + lista->sledeci->vrednost == 0){
  Cvor *novi = lista;
  lista = izmena(lista->sledeci);
  free(novi);
 }
 else
  lista->sledeci = izmena(lista->sledeci);
 return lista;
}

int main(){
 FILE *in = fopen("lista.txt", "r");
 if(in == NULL)
  greska();
  
 Cvor *lista = NULL;
 ucitaj_listu(&lista, in);
 
 lista = izmena(lista);
 
 ispisi_listu(lista);
 oslobodi_listu(lista); 
 
 fclose(in);
 
 return 0;
}
