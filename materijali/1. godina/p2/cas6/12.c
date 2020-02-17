/* Napisati program koji preko argumenta komandne linije
dobija ime datoteke koja sadrži sortirani spisak
studenta po broju indeksa rastuće. Za svakog studenta u
jednom redu stoje informacije o indeksu, imenu i
prezimenu. Program učitava spisak studenata u niz i
traži od korisnika indeks ili prezime studenta čije
informacije se potom prikazuju na standardni izlaz. U
slučaju više studenata sa istim prezimenom prikazati
informacije o prvom takvom. Odabir kriterijuma pretrage
se vrši kroz poslednji argument komandne linije, koji
može biti -indeks ili -prezime. U slučaju neuspešnih
pretragi, štampati odgovarajuću poruku. Pretrage
implementirati u vidu iterativnih funkcija što manje
složenosti. Pretpostaviti da u datoteci neće biti više
od 128 studenata i da su imena i prezimena svih kraća od
16 slova.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 17
#define MAXS 128

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

typedef struct {
 long indeks;
 char ime[MAX];
 char prezime[MAX];
}STUDENT;

int bin_pretraga(STUDENT a[], int n, long x){
 int l=0;
 int d=n-1;
 int sr;
 while(l<=d){
  sr=(l+d)/2;
  if(x<a[sr].indeks)
   d=sr-1;
  else if(x>a[sr].indeks)
   l=sr+1;
  else 
   return sr;
 }
 return -1;
}

int lin_pretraga(STUDENT a[], int n, char x[]){
 int i;
 for(i=0; i<n; i++)
  if(strcmp(a[i].prezime, x)==0)
   return i;
 
 return -1;
}

int main(int argc, char *argv[]){
 if(argc!=3)
  greska();
  
 int binpr; 
 if(strcmp(argv[2], "-indeks")==0)
  binpr=1;
 else if(strcmp(argv[2], "-prezime")==0)
  binpr=0;
 else
  greska();
  
 FILE *in=fopen(argv[1], "r");
 if(in==NULL)
  greska();
  
 STUDENT s[MAXS];
 int i;
 for(i=0; i<MAXS; i++){
  if(fscanf(in, "%ld %s %s", &s[i].indeks, s[i].ime, 
                             s[i].prezime)!=3)
   break;
 }
 
 int br=0;
 br=i;
 fclose(in);
 
 long trazeni_indeks=0;
 char trazeno_prezime[MAX];
 
 if(binpr){
  scanf("%ld", &trazeni_indeks);
  i=bin_pretraga(s, br, trazeni_indeks);
  if(i==-1)
   greska();
  else
   printf("%ld %s %s\n", s[i].indeks, s[i].ime, s[i].prezime);
 }
 else{
  scanf("%s", trazeno_prezime);
  i=lin_pretraga(s, br, trazeno_prezime);
  if(i==-1)
   greska();
  else
   printf("%ld %s %s\n", s[i].indeks, s[i].ime, s[i].prezime);
 }
  
 return 0;
}
