#include <iostream>
#include <cstdlib>
#include "liste.hpp"

void ispisi(int, int);
void yyerror(char*);

cvor_l* novi_cvor(int br){
  cvor_l* novi_c = (cvor_l*)malloc(sizeof(cvor_l));
  
  novi_c->vr = br;
  novi_c->sled = NULL;
  
  return novi_c;
}

lista* nova_lista(int br){
  lista* nova_l = (lista*)malloc(sizeof(lista));
  cvor_l* novi_c = novi_cvor(br);
  nova_l->glava = nova_l->rep = novi_c;
  
  return nova_l;
}

lista* dodaj(lista* l, int br){
  if (l->rep) {
    cvor_l* n = novi_cvor(br);
    l->rep->sled = n;
    l->rep = n;
    return l;
  }
  else 
    return nova_lista(br);
}

static lista* dupliraj(lista* l){
  lista* nova = nova_lista(l->glava->vr);
  cvor_l* pom = l->glava->sled;
  
  while(pom){
    nova = dodaj(nova, pom->vr);
    pom = pom->sled;
  }
  
  return nova;  
}

lista* nadovezi(lista* prva, lista* druga){
  if (prva != NULL) {
    if (prva == druga)
      druga = dupliraj(druga);
    if (druga == NULL)
      return prva;
    prva->rep->sled = ( druga != NULL ) ? druga->glava : NULL;
    prva->rep = druga->rep;
    return prva;
  }
  else
    return druga;
}

void ispisi_listu(lista* l){
  putchar('[');
  if (!l)
    puts("]");
  else {
    cvor_l *pom = l->glava;
    while(pom && pom != l->rep){
      ispisi(pom->vr, '\0');
      printf(", ");
      pom = pom->sled;
    }
    if (pom) {
      ispisi(pom->vr, '\0');
      printf("]\n");
    }
    else
      puts("]");
  }
  fflush(stdout);
}

int nadji_u_listi(lista* l, int i){
  cvor_l* pom = l->glava;
  
  while(pom && i){
    pom = pom->sled;
    i--;
  }
  if (pom)
    return pom->vr;
  else
    return 1;
}
lista* dodaj_na_poc(lista* l, int br){
  if(l){
    cvor_l* pom = novi_cvor(br);
    pom->sled = l->glava;
    l->glava = pom;
    return l;
  }
  else
    return nova_lista(br);
}
int    duzina_liste(lista* l){
  int duzina = 0;
  if (l == NULL)
    return 0;
  cvor_l* pom = l->glava;
  while(pom){
    duzina++;
    pom = pom->sled;
  }
  
  return duzina;
}

int poredi(const void* a, const void* b){
  int prvi = *(int*)a;
  int drugi = *(int*)b;
  
  if (prvi>drugi)
    return 1;
  else if (prvi<drugi)
    return -1;
  else
    return 0;
}

lista* sortiraj(lista* l){
  int duzina = duzina_liste(l);
  int *pom_niz = (int*)malloc(sizeof(int)*duzina);
  
  cvor_l* pom = l->glava;
  
  int i=0;
  while(pom){
    pom_niz[i++] = pom->vr;
    pom = pom->sled;
  }
  
  qsort(pom_niz, duzina, sizeof(int), poredi);
  
  pom = l->glava;
  for(i=0; pom; i++, pom = pom->sled)
    pom->vr = pom_niz[i];
  
  free(pom_niz);
  return l;
}
