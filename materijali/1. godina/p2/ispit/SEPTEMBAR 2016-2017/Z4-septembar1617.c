#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

Cvor *brisanje(Cvor *lista){
 Cvor *glava = lista;
 int preth = 1;
 int tekuci = 1;
 Cvor *prethodni = NULL;
 
 int i = 1;
 while(lista != NULL){
  if(i == tekuci){
   if(prethodni == NULL){
    Cvor *pom = lista;
    lista = lista->sledeci;
    glava = lista;
    free(pom);
    i++;
    int t = tekuci + preth;
    preth = tekuci;
    tekuci = t;
   }
   else{
    Cvor *pom = lista;
    prethodni->sledeci = lista->sledeci;
    lista = lista->sledeci;
    free(pom);
    i++;
    int t = tekuci + preth;
    preth = tekuci;
    tekuci = t;
   }
  }
  else{
   i++;
   prethodni = lista;
   lista = lista->sledeci;
  }
 }
 return glava;
}

int main(){
 Cvor *lista = NULL;
 ucitaj_listu(&lista, stdin);
 
 lista = brisanje(lista);
 ispisi_listu(lista);
 oslobodi_listu(lista); 
 
 return 0;
}
