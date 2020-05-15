/* Napisati funkciju:
void razmeni(int mat[][max], int m, int n, int k, int t)
u kojoj se razmenjuju elemeti k–te i t–te vrste matrice
mat dimezije m × n. Napisati program koji za učitanu
matricu celih brojeva, i dva cela broja k i t ispisuje
matricu dobijenu razmenjivanjem k–te i t–te vrste
ulazne matrice. Pretpostaviti da je maksimalna dimenzija
matrice 50 × 50. U slučaju greške ispisati odovarajuću
poruku. */

#include <stdio.h>
#define MAX 50

void razmeni(int mat[][MAX], int m, int n, int k, int t){
 int j, pom;
 
 for(j=0; j<n; j++){
  pom=mat[k][j];
  mat[k][j]=mat[t][j];
  mat[t][j]=pom;
 }
}

void ispis(int mat[][MAX], int m, int n){
 int i, j;
 for(i=0; i<m; i++){
  for(j=0; j<n; j++){
   printf("%3d ", mat[i][j]);
  }
  printf("\n");
 } 
}


int main(){
 int mat[MAX][MAX];
 int m, n, k, t;
 int i, j;
 
 scanf("%d%d", &m, &n);
 if(m<=0 || m>MAX || n<=0 || n>MAX){
  printf("-1\n");
  return -1;
 }
 
 for(i=0; i<m; i++){
  for(j=0; j<n; j++){
   scanf("%d", &mat[i][j]);
  }
 }
 
 scanf("%d%d", &k, &t);
 if(k<0 || k>=m || t<0 || t>=m){
  printf("-1\n");
  return -1;
 }
 
 printf("\n");
 razmeni(mat, m, n, k, t);
 ispis(mat, m, n);
 
 return 0;
}
