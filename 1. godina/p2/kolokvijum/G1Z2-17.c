/* Na standarni ulaz se zadaje ceo broj n, a zatim
informacije o n studenata. U svakom redu se nalazi
indeks studenta i zatim jedna njegova ocena (ceo broj
u intervalu [6,10]). Na standardni izlaz ispisati
indeks i prosečnu ocenu svakog studenta o kom postoje
date informacije. Prosek ispisati na dve decimale.
Ispis raditi u redosledu unosa (svaki indeks treba da
se javi tačno jednom). U slučaju greške, na standardni
izlaz za greške ispisati -1. Ne postoji pretpostavka o
maksimalnoj vrednosti broja n. Zadatak uradjen bez
korišćenja dinamičke alokacije se boduje sa 0 poena. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

typedef struct {
 char indeks[11];
 int ocena;
 int obradjen;
}STUDENT;

int main(){
 int n;
 scanf("%d", &n);
 if(n<=0)
  greska();
 
 STUDENT *s;
 s=(STUDENT*)malloc(n*sizeof(STUDENT));
 if(s==NULL)
  greska();
 
 int i;
 for(i=0; i<n; i++){
  scanf("%s%d", s[i].indeks, &s[i].ocena);
  if(s[i].ocena<6 || s[i].ocena>10)
   greska();
  s[i].obradjen=0;
 }
 
 int j;
 float prosek;
 int br;
 for(i=0; i<n; i++){
  if(s[i].obradjen)
   continue;
  prosek=s[i].ocena;
  br=1;
  for(j=i+1; j<n; j++){
   if(s[j].obradjen==0){
    if(strcmp(s[j].indeks, s[i].indeks)==0){
     br++;
     prosek+=s[j].ocena;
     s[j].obradjen=1;
    }
   }
  }
  printf("%s %.2f\n", s[i].indeks, prosek/br);
 }
  
 free(s);
 
 return 0;
}
