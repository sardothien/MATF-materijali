#ifndef _LISTA_H
#define _LISTA_H

typedef struct _cvor_l{
  int vr;
  struct _cvor_l* sled;
} cvor_l;

typedef struct{
  cvor_l* glava;
  cvor_l* rep;
} lista;

cvor_l* novi_cvor(int br);
lista* nova_lista(int br);
lista* dodaj(lista* l, int br);
lista* nadovezi(lista* prva, lista* druga);
void   ispisi_listu(lista* l);
int    nadji_u_listi(lista* l, int i);
lista* dodaj_na_poc(lista* l, int br);
int    duzina_liste(lista* l);
lista* sortiraj(lista*);

#endif
