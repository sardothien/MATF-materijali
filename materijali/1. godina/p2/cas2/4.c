/* Napisati program koji sa standardnog ulaza ucitava
matricu celih brojeva. Prvo se ucitaju broj vrsta i 
kolona matrice, a zatim i elementi matrice. Na standardni
izlaz ispisati ucitanu matricu. Zatim napisati funkciju:
int sum max(int **A, int n, int m) koja racuna zbir najvecih
elemenata u svakoj vrsti. Ispisati rezultat izvrsavanja
funkcije na standardni izlaz. U slucaju greske na standardni
izlaz za greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>

int max(int *niz, int n){
 int max=niz[0];
 int i;
 for(i=0; i<n; i++){
  if(niz[i]>max){
   max=niz[i];
  }
 }
 
 return max;
}

int sum_max(int **mat, int m, int n){
 int suma=0;
 int i;
 for(i=0; i<m; i++){
  suma=suma+max(mat[i], n);
 }
 
 return suma;
}


int main(){
 int m, n;
 
 scanf("%d%d", &m, &n);
 
 int **mat;
 mat=(int **)malloc(m*sizeof(int *));
 if(mat==NULL){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 int i, j;
 for(i=0; i<m; i++){
  mat[i]=(int *)malloc(n*sizeof(int));
  if(mat[i]==NULL){
   for(j=0; j<i; j++){
    free(mat[j]);
   }
   free(mat);
   fprintf(stderr, "-1\n");
   exit(EXIT_FAILURE);
  }
 }
 
 for(i=0; i<m; i++){
  for(j=0; j<n; j++){
   scanf("%d", &mat[i][j]);
  }
 }
 
 for(i=0; i<m; i++){
  for(j=0; j<n; j++){
   printf("%d ", mat[i][j]);
  }
 }
 
 printf("\n");
 printf("%d \n", sum_max(mat, m, n));
 
 for(i=0; i<n; i++){
  free(mat[i]);
 }
 
 free(mat);
 
 return 0;
}
