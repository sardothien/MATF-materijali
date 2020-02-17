#include <stdio.h>
#include <stdlib.h>

typedef struct Cvor{
 int br;
 struct Cvor *next;
 struct Cvor *prev;
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
 novi->prev = NULL;
 return novi;
}

void dodaj_na_kraj(cvor **pocetak, int x){
 cvor *novi=napravi_novi(x);
 if(*pocetak==NULL){
  *pocetak = novi;
  novi->next = novi;
  novi->prev = novi;
  return;
 }
 
 cvor *kraj = (*pocetak)->prev;
 kraj->next = novi;
 novi->prev = kraj;
 novi->next = *pocetak;
 (*pocetak)->prev = novi;
}

// Pravi se lista od prazne liste
void napravi_listu(cvor **adresa_liste, int n){
 int i;
 for(i=0; i<n; i++)
  dodaj_na_kraj(adresa_liste, i+1); 
}

void ispis(cvor *pocetak){
 if(pocetak==NULL){
  printf("[]\n");
  return;
 }
 cvor *prvi = pocetak;
 printf("%d ", pocetak->br);
 pocetak = pocetak->next;
 
 while(prvi != pocetak){
  printf("%d ", pocetak->br);
  pocetak = pocetak->next;
 }
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
 return;
}

void izbaci(cvor **adresa_liste, int k){
 if(*adresa_liste == NULL)
  return;
  
 cvor *tekuci = *adresa_liste;
 int smer = 1; // 1 - desno, -1 - levo  
 while(1){
  if((*adresa_liste)->next == (*adresa_liste)){
   printf("%d ", (*adresa_liste)->br);
   free(*adresa_liste);
   *adresa_liste=NULL;
   break;
  }
  int i;
  if(smer == 1){
   for(i=0; i<k-1; i++){
    tekuci = tekuci->next;
   }
  }
  else{
   for(i=0; i<k-1; i++){
    tekuci = tekuci->prev;
   }
  } 
 printf("%d ", tekuci->br);
 // tekuci treba da se brise
 (tekuci->prev)->next = tekuci->next;
 (tekuci->next)->prev = tekuci->prev;
 cvor *tmp = tekuci;
 if(smer==1)
  tekuci = tekuci->prev;
 else
  tekuci = tekuci->next;
 if(tmp == *adresa_liste)
  *adresa_liste = tekuci;  
 free(tmp);
 smer *= -1;
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
// oslobodi(lista);
 
 return 0;
}
