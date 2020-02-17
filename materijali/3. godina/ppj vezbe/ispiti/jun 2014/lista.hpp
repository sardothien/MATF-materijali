#ifndef _LISTA_H
#define _LISTA_H

typedef struct cvor_{
  int vred;
  struct cvor_ *sled;
} cvor;

typedef struct {
  cvor* glava;
  cvor* rep;
} lista;

lista* nova_lista(int);
lista* nadovezi(lista*, lista*);
lista* ostatak(lista*);
lista* dodaj_na_pocetak(lista*, int);
lista* dodaj_na_kraj(lista*, int);
void   ispisi_listu(lista*);

#endif
