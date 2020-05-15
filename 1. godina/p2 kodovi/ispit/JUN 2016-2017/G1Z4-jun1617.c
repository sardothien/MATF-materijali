#include <stdio.h>
#include "liste.h"

Cvor *dopuna(Cvor *lista){
 if(lista == NULL)
  return NULL;
 if(lista->sledeci == NULL)
  return lista;
  
 if(lista->vrednost % 2 == 0 && lista->sledeci->vrednost % 2 == 0){
  Cvor *novi = napravi_cvor(lista->vrednost 
                          + lista->sledeci->vrednost);
  novi->sledeci = lista;
  lista->sledeci = dopuna(lista->sledeci);
  return novi;
 }
 else{
  lista->sledeci = dopuna(lista->sledeci);
  return lista;
 }
}

int main(){
 FILE *in = fopen("lista.txt", "r");
 if(in == NULL)
  greska();
 
 Cvor *lista = NULL;
 ucitaj_listu(&lista, in);
 lista = dopuna(lista);
 ispisi_listu(lista);
 
 oslobodi_listu(lista);
 fclose(in); 
 
 return 0;
}
