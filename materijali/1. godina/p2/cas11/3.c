#include <stdio.h>
#include <stdlib.h>

typedef struct Cvor{
 int br;
 struct Cvor *levo;
 struct Cvor *desno;
} cvor;

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
// Veci idu desno od korena, a manji levo
void dodaj_u_stablo(cvor **adresa_stabla, int x){
 if(*adresa_stabla == NULL){
  cvor *novi = napravi_novi(x);
  *adresa_stabla = novi;
  return;
 }
 
 if((*adresa_stabla)->br > x) // dodajemo levo
  dodaj_u_stablo(&((*adresa_stabla)->levo), x);
 else // inace, dodajemo desno od korena stabla
  dodaj_u_stablo(&((*adresa_stabla)->desno), x);
}

void ucitaj_stablo(cvor **adresa_stabla, FILE *f){
 int x;
 while(fscanf(f, "%d", &x) != EOF){
  dodaj_u_stablo(adresa_stabla, x);
 }
}

// infiksno - prvo se rekurzivno obradi levo, pa se obradi koren (printf)
//            i zatim rekurzivno obradi desno 
// prefiksno - koren -> levo -> desno
// postfiksno - levo -> desno -> koren
// vazi i kada je desno -> levo

void ispis_infiksno(cvor *koren){
 if(koren == NULL)
  return;
 
 ispis_infiksno(koren->levo);
 printf("%d ", koren->br);
 ispis_infiksno(koren->desno);
}
// pomocu ovoga moze da se sortira niz

void ispis_prefiksno(cvor *koren){
 if(koren == NULL)
  return;
 
 printf("%d ", koren->br);
 ispis_prefiksno(koren->levo);
 ispis_prefiksno(koren->desno);
}

void ispis_postfiksno(cvor *koren){
 if(koren == NULL)
  return;
  
 ispis_postfiksno(koren->levo);
 ispis_postfiksno(koren->desno);
 printf("%d ", koren->br);
}

void oslobodi(cvor *stablo){
 if(stablo == NULL)
  return;
 
 oslobodi(stablo->levo);
 oslobodi(stablo->desno);
 free(stablo);
}

int main(){
 cvor *stablo=NULL;
 ucitaj_stablo(&stablo, stdin);

 printf("Infiksno: ");
 ispis_infiksno(stablo);
 printf("\n");
 printf("Postfiksno: ");
 ispis_postfiksno(stablo);
 printf("\n");
 printf("Prefiksno: ");
 ispis_prefiksno(stablo);
 printf("\n");
 
 oslobodi(stablo);
 
 return 0;
}