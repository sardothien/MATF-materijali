/* Napisati program koji za učitanu matricu
celih brojeva ispisuje indekse onih elemenata
matrice koji su jednaki zbiru svih svojih
susednih elemenata. Pretpostaviti da je
maksimalna dimenzija matrice 50 × 50. U slučaju
greške ispisati odovarajuću poruku. */

#include <stdio.h>
#define MAX 50

int main(){
 int mat[MAX][MAX];
 int m, n, s;
 int i, j, k, t;
 
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
 
 for(i=0; i<m; i++)
  for(j=0; j<n; j++){
   s=0;
   for(k=-1;k <=1; k++)
    for(t=-1; t <=1; t++)
     if (i+k>=0 && i+k<n && j+t>=0 && j+t<n)
      s += mat[i+k][j+t];
    if (s-mat[i][j]==mat[i][j])
      printf("%d %d\n", i, j);
  }
  
 return 0; 
}
