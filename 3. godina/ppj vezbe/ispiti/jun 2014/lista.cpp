#include<iostream>
#include<cstdlib>
#include "lista.hpp"
using namespace std;

static cvor* novi_cvor(int br){
  cvor* n = (cvor*)malloc(sizeof(cvor));
  
  n->vred = br;
  n->sled = NULL;
  
  return n;
}

lista* nova_lista(int br){
  lista* n = (lista*)malloc(sizeof(lista));
  
  n->glava = n->rep = novi_cvor(br);
  
  return n;
}

lista* nadovezi(lista* l1, lista* l2){
  if (l2 == nullptr)
    return l1;
  if (l1 == nullptr)
    return l2;
  
  l1->rep->sled = l2->glava;
  l1->rep = l2->rep;
  
  return l1; 
  
}

lista* ostatak(lista* l){
  lista* nova = (lista*)malloc(sizeof(lista));
  if (l == nullptr || l->glava == l->rep)
    nova->glava = nova->rep = NULL;
  else {
    nova->glava = l->glava->sled;
    nova->rep = l->rep;
  }
  if (l){
    free(l->glava);
    free(l); 
  }
  return nova;
}

lista* dodaj_na_pocetak(lista* l, int br){
  if (l){
    cvor* novi_c = novi_cvor(br);
    novi_c->sled = l->glava;
    l->glava = novi_c;
    return l;
  }
  else
    return nova_lista(br);
}

lista* dodaj_na_kraj(lista* l, int br){
  if (l){
    cvor* novi_c = novi_cvor(br);
    l->rep->sled = novi_c;
    l->rep = novi_c;
  }
  else 
    l = nova_lista(br);
 
  return l;
}

void ispisi_listu(lista* l){
  printf("(");
  if(l){
    cvor* pom = l->glava;
    while(pom){
      printf(pom == l->glava ?  "%d" : " %d", pom->vred);
      pom = pom->sled;
    }
  }
  printf(")\n");
}
