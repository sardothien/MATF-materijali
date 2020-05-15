/* Na standardni ulaz se zadaje pozitivan ceo broj
n, a zatim informacije o n artikala u magacinu. Za
svaki artikal se zna naziv (dužine najviše 50
karaktera) i koločina. Na standardni izlaz ispisati
ukupnu količinu svakog artikla. Ispis raditi u
redosledu unosa (svaki artikal treba da se javi
tačno jednom). U slučaju greške, na standardni
izlaz za greške ispisati -1. Ne postoji pretpostavka
o maksimalnoj vrednosti broja n. Zadaci rešeni bez
korišćenja dinamičke alokacije će biti ocenjeni sa 0
poena. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

typedef struct {
 char naziv[51];
 int kolicina;
 int obradjen;
}ARTIKAL;

int main(){
 int n;
 scanf("%d", &n);

 ARTIKAL *a;
 a=malloc(n*sizeof(ARTIKAL));
 if(a==NULL)
  greska();
 
 int i;
 for(i=0; i<n; i++){
  scanf("%s%d", a[i].naziv, &a[i].kolicina);
  if(a[i].kolicina<=0)
   greska();
  a[i].obradjen=0;
 }
 
 int j;
 int suma;
 for(i=0; i<n; i++){
  if(a[i].obradjen)
   continue;
  suma=a[i].kolicina;
  for(j=i+1; j<n; j++){
   if(a[j].obradjen==0){
    if(strcmp(a[i].naziv, a[j].naziv)==0){
     suma+=a[j].kolicina;
     a[j].obradjen=1;
    }
   }
  }
  printf("%s %d\n", a[i].naziv, suma);
 }
 
 free(a);
 
 return 0;
}
