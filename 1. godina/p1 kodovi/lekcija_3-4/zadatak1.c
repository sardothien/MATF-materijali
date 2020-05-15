/* Napisati program koji učitava i zatim ispisuje vrednosti učitane
matrice. Pretpostaviti da je maksimalna dimenzija matrice 50 × 50,
a da se sa ulaza najpre učitavaju dva cela broja m i n, a potom i
elementi matrice celih brojeva dimenzije m × n. U slučaju greške
ispisati odgovarajuću poruku. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int main(){
 int mat[MAX][MAX];
 int m, n;
 int i, j;
 scanf("%d%d", &m, &n);

 if(n<=0 || n>MAX || m<=0 || m>MAX){
  printf("-1\n");
  exit(EXIT_FAILURE);
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
   printf("\n");
 }		

 return 0;
}
