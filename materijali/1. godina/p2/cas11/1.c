#include <stdio.h>
#include <stdlib.h>

typedef struct Cvor{
 int br;
 struct Cvor *next;
} cvor;

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

cvor *napravi_novi(int x){
 cvor *novi=malloc(sizeof(cvor));
 if(novi==NULL)
  greska();
 
 novi->br = x;
 novi->next = NULL;
 return novi;
}
void dodaj_na_kraj(cvor **pocetak, cvor **kraj, int x){
 cvor *novi=napravi_novi(x);
 if(*pocetak==NULL){
  *pocetak = novi;
  *kraj = novi;
  (*kraj)->next = *pocetak;
  return;
 }
 
 (*kraj)->next = novi;
 novi->next = *pocetak;
 *kraj = novi;
}

// Pravi se lista od prazne liste
void napravi_listu(cvor **adresa_liste, int n){
 cvor *kraj = *adresa_liste;
 int i;
 for(i=0; i<n; i++)
  dodaj_na_kraj(adresa_liste, &kraj, i); 
}

void ispis(cvor *pocetak){
 if(pocetak==NULL){
  printf("[]\n");
  return;
 }
 cvor *prvi = pocetak;
 printf("%d", pocetak->br);
 pocetak = pocetak->next;
 
 while(prvi != pocetak){
  printf(" %d", pocetak->br);
  pocetak = pocetak->next;
 }
 printf("\n");
}

void oslobodi(cvor *lista){
 if(lista==NULL)
  return;
 
 cvor *prvi=lista;
 lista = lista->next;
 free(prvi);
 while(lista != prvi){
  cvor *tekuci = lista;
  lista = lista->next;
  free(tekuci);
 }
}

void izbaci(cvor **adresa_liste, int k){
 if(*adresa_liste == NULL)
  return;
  
 while(1){
  if((*adresa_liste)->next == (*adresa_liste)){
   printf("%d\n", (*adresa_liste)->br);
   free(*adresa_liste);
   *adresa_liste=NULL;
   break;
  }
  cvor *prethodni = *adresa_liste;
  int i;
  for(i=0; i<k-1; i++)
   prethodni = prethodni->next;
 
  printf("%d ", (prethodni->next)->br); 
  if(prethodni->next == *adresa_liste){
   cvor *tekuci = prethodni->next;
   prethodni->next = tekuci->next;
   free(tekuci);
   *adresa_liste = prethodni->next;
  }
  else{
   cvor *tekuci = prethodni->next;
   prethodni->next = tekuci->next;
   free(tekuci);
  }
 }
}

int main(){
 int n;
 scanf("%d", &n);
 
 cvor *lista=NULL;
 napravi_listu(&lista, n);
 ispis(lista);
 
 int k;
 scanf("%d", &k);
 izbaci(&lista, k);
 ispis(lista);
 //oslobodi(lista);
 
 return 0;
}
