/* Sa standardnog ulaza se ucitava rec pretrage,
dimenzija niza, a zatim i niz reci. Pretpostavljati
da je maksimalna duzina reci 20 karaktera (prostor za
rec alocirati dinamicki). Na standardni izlaz ispisati
indeks prvog i poslednjeg pojavljivanja trazene reci u 
okviru unetog niza reci. U slucaju da se rec ne pojavljuje
u nizu, ispisati -1 za obe pozicije. U slucaju greske na
standardni izlaz za greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
 int m, n=21, i, j;
 char **niz_niski, *rec;
 
 rec=(char *)malloc(21*sizeof(char)); 
 scanf("%s", rec);
 getchar();
 scanf("%d", &m);
 
 niz_niski=(char**)malloc(m*sizeof(char*));
 if(niz_niski==NULL){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 for(i=0; i<m; i++){
  niz_niski[i]=(char*)malloc(n*sizeof(char));
  if(niz_niski[i]==NULL){
   for(j=0; j<i; j++){
    free(niz_niski[j]);
   }
   free(niz_niski);
   fprintf(stderr, "-1\n");
   exit(EXIT_FAILURE);
  }  
 }
 
 for(i=0; i<m; i++){
  scanf("%s", niz_niski[i]);
  getchar();
 }
 
 int t, d;
 for(i=0; i<m; i++){
  if(strcmp(niz_niski[i], rec)==0){
   printf("%d ", i);
   t=i;
   break;
  }  
 }
 
 if(t!=i){
  printf("-1 ");
 }
 
 for(i=m-1; i>=0; i--){
  if(strcmp(niz_niski[i], rec)==0){
   if(t!=i){
    printf("%d\n", i);
    d=i;
    break;
   }
   break;
  }
 }
 
 if(t!=i && d!=i){
  printf("-1\n");
 }
   
 for(i=0; i<m; i++){
  free(niz_niski[i]);
 }
 
 free(niz_niski);
 
 return 0;
}
