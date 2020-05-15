/* U datoteci studenti.txt se nalaze podaci o studentima
(ime, prezime, smer, prosecna ocena), sortirane prema
prezimenu rastuce. Sa standardnog ulaza se zadaje prezime.
Na standardni izlaz ispisati sve podatke o svim pronadjenim
studentima sa zadatim prezimenom. Koristiti funkciju
bsearch. Maksimalna duzina imena, kao i prezimena studenta
je 20 karaktera. Smer je jedan karakter i moze biti I, R,
M, N, V ili L. Prosecna ocena je realan broj izmedju 5 i
10. U slucaju greske na standardni izlaz za greske ispisati
-1.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 21

typedef struct{
 char ime[MAX];
 char prezime[MAX];
 char smer;
 float prosek;
}STUDENT;

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

STUDENT *s;

int poredi(const void *a, const void *b){
 int k=strcmp((char *)a, ((STUDENT*)b)->prezime);
 if(k==0 && b!=s){
  STUDENT *preth=((STUDENT*)b) - 1;
  if(strcmp((char *)a, preth->prezime)==0){
   return -1;
  }
  return 0;
 }
  
 return k;
}

int main(){
 FILE *in=fopen("studenti.txt", "r");
 if(in==NULL)
  greska();
  
 int n, i;
 fscanf(in, "%d", &n);
 s=malloc(n*sizeof(STUDENT));
 if(s==NULL)
  greska();
  
 for(i=0; i<n; i++)
  fscanf(in, "%s %s %c%f", s[i].ime, s[i].prezime,
                          &s[i].smer, &s[i].prosek);
  
 fclose(in);
  
 char prezime[MAX];
 scanf("%s", prezime);
  
 STUDENT *prvi;
 int k=n;
 prvi=bsearch(prezime, s, k, sizeof(STUDENT), poredi);
 k=prvi-s;
  
 if(prvi==NULL)
  printf("Student sa zadatim prezimenom ne postoji.\n");
 else
  for(; k<n && strcmp(prvi->prezime, prezime)==0; prvi+=1, k++)
   printf("%s %s %c %.1f\n", prvi->ime, prvi->prezime,
                             prvi->smer, prvi->prosek);
                            
  free(s);  
  
  return 0;
}
