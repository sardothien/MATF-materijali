#include <stdio.h>
#include <stdlib.h>
#include "4.h"

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

cvor *napravi_novi(int x){
 cvor *novi = malloc(sizeof(cvor));
 if(novi == NULL)
  greska();
 
 novi->br = x;
 novi->levo = NULL;
 novi->desno = NULL;
 return novi;
}

void dodaj_u_stablo(cvor **adresa_stabla, int x){
 if(*adresa_stabla == NULL){
  cvor *novi = napravi_novi(x);
  *adresa_stabla = novi;
  return;
 }
 
 if((*adresa_stabla)->br > x) 
  dodaj_u_stablo(&((*adresa_stabla)->levo), x);
 else 
  dodaj_u_stablo(&((*adresa_stabla)->desno), x);
}

void ucitaj_stablo(cvor **adresa_stabla, FILE *f){
 int x;
 while(fscanf(f, "%d", &x) != EOF){
  dodaj_u_stablo(adresa_stabla, x);
 }
}




void oslobodi(cvor *stablo){
 if(stablo == NULL)
  return;
 
 oslobodi(stablo->levo);
 oslobodi(stablo->desno);
 free(stablo);
}

////////
CvorReda* napravi_cvor_reda(cvor* cvor_stabla, int nivo){
 CvorReda* novi = malloc(sizeof(CvorReda));
 if(novi == NULL)
  greska();
 
 novi->cvor_stabla = cvor_stabla;
 novi->nivo = nivo;
 novi->sledeci = NULL;
	
 return novi;
}

void dodaj_na_kraj_reda(CvorReda **pocetak, CvorReda** kraj, cvor* cvor_stabla, int nivo){
 CvorReda *novi = napravi_cvor_reda(cvor_stabla, nivo);
	
 if(*pocetak == NULL){ //red je prazan --> oba pokazivaca postavljamo na novi cvor
  *pocetak = novi;
  *kraj = novi;
 }
 else{ //dodajemo na kraj i pomeramo pokazivac kraja
  (*kraj)->sledeci = novi;
  *kraj = novi;
 }
}

/* Funkcija koja brise element koji se nalazi na pocetku reda */
int skini_sa_pocetka(CvorReda** pocetak, CvorReda** kraj){
 if(*pocetak == NULL)
  return 0;
 
 if(*pocetak == *kraj){ //red ima samo jedan element
  free(*pocetak);
  *pocetak = NULL;
  *kraj = NULL;
 }
 else{
  CvorReda* tmp = *pocetak;
  *pocetak = (*pocetak)->sledeci;
  free(tmp);
 }
	
 return 1;
}

 
/* Funkcija koja ispisuje stablo po nivoima, 
   a kao pomocnu strukturu podataka koristi red.

 Princip: 
   1. Dodaj koren u red 
   2. Dok god je red neprazan:
      Uzmi prvi clan u redu i:
	 2.1 Dodaj u red njegovu decu (ako ih ima)
	 2.2 Ispisi vrednost tekuceg clana
	 2.3 Obrisi tekuci clan iz reda */

void ispisi_po_nivoima(cvor* stablo){
 if(stablo == NULL)
  return;
  	
 CvorReda* prvi = NULL;
 CvorReda* poslednji = NULL;
 dodaj_na_kraj_reda(&prvi, &poslednji, stablo, 0);
 int trenutni_nivo = -1;

 while(prvi != NULL){ //dok god je red neprazan
  /*Ako je doslo do promene nivoa, ispisujemo na kom smo trenutno nivou*/
  if(prvi->nivo != trenutni_nivo){
   trenutni_nivo = prvi->nivo;
   printf("\n%d.nivo: ", trenutni_nivo);
  }
  if(prvi->cvor_stabla->levo)
   dodaj_na_kraj_reda(&prvi, &poslednji, prvi->cvor_stabla->levo, prvi->nivo + 1);
  if(prvi->cvor_stabla->desno)
   dodaj_na_kraj_reda(&prvi, &poslednji, prvi->cvor_stabla->desno, prvi->nivo + 1);
	
  printf("%d ", prvi->cvor_stabla->br);
		
  if(!skini_sa_pocetka(&prvi, &poslednji))
   greska();
 }
	
 printf("\n");
}
