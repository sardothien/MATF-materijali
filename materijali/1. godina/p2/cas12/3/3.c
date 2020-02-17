#include <stdio.h>
#include <stdlib.h>
#include "3.h"

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

// POD a)
int broj_cvorova(cvor *koren){
 if(koren == NULL)
  return 0;
 
 return 1 + broj_cvorova(koren->levo) 
          + broj_cvorova(koren->desno);
}

// POD b)
int broj_listova(cvor *koren){
 if(koren == NULL)
  return 0;
  
 if(koren->levo == NULL && koren->desno == NULL)
  return 1;
 
 return broj_listova(koren->levo) + broj_listova(koren->desno); 
}

// POD C)
void ispis_poz_listova(cvor *koren){
 if(koren == NULL)
  return;
 
 if(koren->levo == NULL && koren->desno == NULL){
  if(koren->br > 0)
   printf("%d ", koren->br);
  return;   
 }
 ispis_poz_listova(koren->levo);
 ispis_poz_listova(koren->desno);
}

// POD d)
int zbir_cvorova(cvor *koren){
 if(koren == NULL)
  return 0;
 
 return koren->br + zbir_cvorova(koren->levo) 
                  + zbir_cvorova(koren->desno);
}

// POD e)
cvor *najveci_broj(cvor *koren){
 if(koren == NULL)
  return NULL;
 
 if(koren->desno == NULL)
  return koren;
 else
  return najveci_broj(koren->desno);
}

// POD f)
int dubina(cvor *koren){
 if(koren == NULL)
  return 0;
 
 int levo = dubina(koren->levo);
 int desno = dubina(koren->desno);
 
 return levo > desno ? levo+1 : desno+1;
}

// POD g)
// koren je na 0-tom nivou
int br_i_nivo(cvor *koren, int i){
 if(koren == NULL)
  return 0;
 
 if(i == 0)
  return 1;
 
 return br_i_nivo(koren->levo, i-1) 
      + br_i_nivo(koren->desno, i-1);
} 

// POD h)
void ispis_i_nivo(cvor *koren, int i){
 if(koren == NULL)
  return;
 
 if(i == 0){
  printf("%d ", koren->br);
  return;
 }
 
 ispis_i_nivo(koren->levo, i-1);
 ispis_i_nivo(koren->desno, i-1);
} 

// POD i)
cvor *max_i_nivo(cvor *koren, int i){
 if(koren == NULL)
  return NULL;
 
 if(i == 0)
  return koren;
 
 cvor *levo = max_i_nivo(koren->levo, i-1);
 cvor *desno = max_i_nivo(koren->desno, i-1);
 
 if(levo == NULL)
  return desno;
 if(desno == NULL)
  return levo;
 
 if(levo->br > desno->br)
  return levo;
 else
  return desno;
} 

// POD j)
int zbir_i_nivo(cvor *koren, int i){
if(koren == NULL)
  return 0;
 
 if(i == 0)
  return koren->br;
 
 return zbir_i_nivo(koren->levo, i-1)
      + zbir_i_nivo(koren->desno, i-1);
}

// POD k)
int zbir_manjih_od_x(cvor* koren, int x){
 if(koren == NULL)
  return 0;
 
 if(koren->br <= x)
  return zbir_manjih_od_x(koren->levo, x) 
       + zbir_manjih_od_x(koren->desno, x) 
       + koren->br;
 else
  return zbir_manjih_od_x(koren->levo, x);
}
