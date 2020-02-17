/* Sa standardog ulaza se zadaje ime tekstualne
datoteke koja sadrzi podatke o artiklima prodavnice.
Jedna linija datoteke je u formatu: bar kod, ime
artikla, proizvodjac, cena. Datoteka je sortirana prema
bar kodu. Bar kod moze imati najvise 20 cifara. Ime
artikla i proizvodjac su niske i mogu imati navise 50
karaktera. Cena je realan broj. Pretpostaviti da su
podaci u datoteci ispravni (ne treba proveravati
ispravnost bilo kog od navedena 4 podatka). Nije
unapred poznat broj artikala u datoteci. Sa
standardnog ulaza unose bar kodovi artikla sve dok se
ne unese 0. Izracunati ukupnu cenu unetih proizvoda.
(koristiti ugradjenu f-ju bsearch za trazenje artikla
sa datim bar kodom). U slucaju greske, na standardni
izlaz za greske ispisati -1. U slucaju da korisnik
unese bar kod koji se ne nalazi u datoteci, ispisati
mu poruku ”Nepostojeci bar kod” i omoguciti mu da
nastavi unosenje. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

typedef struct {
 long int bar_kod;
 char ime_artikla[MAX];
 char proizvodjac[MAX];
 float cena;
}ARTIKAL;

int poredi(const void *a, const void *b){
 return (long int*)a - ((ARTIKAL*)b)->bar_kod;
}

int main(){
 char ime[MAX];
 scanf("%s", ime);
 
 FILE *in=fopen(ime, "r");
 if(in==NULL)
  greska();
 
 ARTIKAL *a;
 int n=10;
 a=malloc(10*sizeof(ARTIKAL));
 if(a==NULL)
  greska();
  
 int i=0, j=0;
 while((fscanf(in, "%ld%s%s%f", &a[i].bar_kod, 
        a[i].ime_artikla, a[i].proizvodjac, 
        &a[i].cena))==4){
  i++;
  j++;
  if(j==n){
   n+=10;
   j=0;
   a=realloc(a, n*sizeof(ARTIKAL));
   if(a==NULL)
    greska();
  }
 }
 
 long int bar_kodovi;
 int *p;
 float suma=0;
 while(1){
  scanf("%ld", &bar_kodovi);
  if(bar_kodovi==0)
   break;
  p=bsearch(&bar_kodovi, a, i, sizeof(ARTIKAL), poredi);
  if(p!=0)
   suma+= a->cena;
  else
   printf("”Nepostojeci bar kod”\n");
 }
 
 printf("%.2f\n", suma);
 free(a);
 
 return 0;
}
