/* U datoteci studenti.txt se nalaze podaci o
studentima (ime, prezime, smer, prosecna ocena),
sortirane prema prezimenu rastuce. Sa standardnog
ulaza se zadaje prezime. Na standardni izlaz ispisati
sve podatke o prvom pronadjenom studentu sa zadatim
prezimenom. Koristiti funkciju bsearch. Maksimalna
duzina imena, kao i prezimena studenta je 20
karaktera. Smer je jedan karakter i moze biti I, R, M,
N, V ili L. Prosecna ocena je realan broj izmedju 5 i
10. U slucaju greske na standardni izlaz za greske
ispisati -1. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 21

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

typedef struct {
 char ime[MAX];
 char prezime[MAX];
 char smer;
 float prosek;
}STUDENT;

int poredi(const void *a, const void *b){
 return strcmp((char*)a, ((STUDENT*)b)->prezime);
}

int main(){
 FILE *in=fopen("studenti.txt", "r");
 if(in==NULL)
  greska();
 
 int n;
 fscanf(in, "%d", &n);
 if(n<=0)
  greska();
 
 STUDENT *s;
 s=malloc(n*sizeof(STUDENT));
 if(s==NULL)
  greska();
 
 int i;
 for(i=0; i<n; i++){
  fscanf(in, "%s %s %c%f", s[i].ime, s[i].prezime,
                           &s[i].smer, &s[i].prosek);
  if(s[i].smer!='I' && s[i].smer!='R' &&
     s[i].smer!='M' && s[i].smer!='N' &&
     s[i].smer!='V' && s[i].smer!='L')
   greska();
  if(s[i].prosek<5 || s[i].prosek>10)
   greska();
 }
 
 fclose(in);
 
 char prezime[MAX];
 scanf("%s", prezime);
 STUDENT *pronadjen, *prvi;
 int k=n;
 while(1){
  pronadjen=bsearch(prezime, s, k, sizeof(STUDENT), poredi);
  if(pronadjen==NULL)
   break;
  prvi=pronadjen;
  k=prvi-s;
 }
 
 if(prvi==NULL)
  printf("Ne postoji student sa datim prezimenom.\n");
 else
  for(; k<n && strcmp(prvi->prezime, prezime)==0; prvi+=1, k++)
   printf("%s %s %c %.1f\n", prvi->ime, prvi->prezime, prvi->smer, prvi->prosek);
   
 free(s);
 
 return 0;
}
