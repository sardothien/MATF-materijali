#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int zbir(Cvor *lista){
 int suma = 0;
 while(lista){
  suma += lista->vrednost;
  lista = lista->sledeci;
 }
 return suma;
}

Cvor *brisanje(Cvor *lista){
 if(lista == NULL)
  return NULL;
 if(lista->sledeci != NULL 
 && lista->vrednost > zbir(lista->sledeci)){
  Cvor *tmp = lista->sledeci;
  free(lista);
  return brisanje(tmp);
 }
 else{
  lista->sledeci = brisanje(lista->sledeci);
  return lista;
 }
}

int main(){
 Cvor *lista = NULL;
 
 ucitaj_listu(&lista, stdin); 
 lista = brisanje(lista);
 ispisi_listu(lista);
 oslobodi_listu(lista); 
 
 return 0;
}
