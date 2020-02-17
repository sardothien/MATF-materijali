#include"liste.h"
#include<stdio.h>
#include<stdlib.h>

void greska()
{
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

Cvor* napravi_cvor(int broj)
{
  Cvor* novi = malloc(sizeof(Cvor));
  if(novi == NULL)
    greska();
  
  novi->vrednost = broj;
  novi->sledeci = NULL;
 
  return novi;
}

void dodaj_na_pocetak(Cvor** lista, int broj)
{
    Cvor* novi = napravi_cvor(broj);    
    novi->sledeci = *lista;
    *lista = novi;
}

void ispisi_listu(Cvor* lista)
{
  printf("[");
  while(lista != NULL)
  {
    printf("%d", lista->vrednost);
    if(lista->sledeci)
      printf(", ");
    lista = lista->sledeci;
  }
  printf("]\n");
}

void dodaj_na_kraj(Cvor** lista, int broj)
{
  if(*lista == NULL)
  {
    Cvor* novi = napravi_cvor(broj);
    *lista = novi;
    return;
  }
  
  dodaj_na_kraj(&(*lista)->sledeci, broj);
}

void ucitaj_listu(Cvor** lista, FILE* f)
{
    if(f == NULL)
        greska();
    
    int x;
    while(fscanf(f, "%d", &x) != EOF)
    {
        dodaj_na_kraj(lista, x);
    }
}

void oslobodi_listu(Cvor* lista)
{
  if(lista)
  {
    oslobodi_listu(lista->sledeci);
    free(lista);
  }
}
