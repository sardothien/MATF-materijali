/* Napisati funkciju void transponovana(int a[][max], int m, int n,
int b[][max]) koja određuje matricu b koja je dobijena 
transponovanjem matrice a. Napisati program koji za učitanu matricu
celih brojeva 1 ispisuje odgvarajuću transponovanu matricu.
Pretpostaviti da je maksimalna dimenzija matrice 50 × 50. U slučaju
greške ispisati odovarajuću poruku. */

#include <stdio.h>
#define MAX 50

void transponovana(int a[][MAX], int m, int n, int b[][MAX]){
 int k, l;
 for(k=0; k<n; k++){
  for(l=0; l<m; l++){
   b[k][l]=a[l][k];
   printf("%3d ", b[k][l]);
  }
  printf("\n");
 }
}


int main(){
 int a[MAX][MAX], b[MAX][MAX];
 int m, n;
 int i, j;
 
 scanf("%d%d", &m, &n);
 if(m<=0 || m>MAX || n<=0 || n>MAX){
  printf("-1\n");
  return -1;
 }
 
 for(i=0; i<m; i++){
  for(j=0; j<n; j++){
   scanf("%d", &a[i][j]);
  }
 }
 printf("\n");
 transponovana(a, m, n, b);
 
 return 0;
}
