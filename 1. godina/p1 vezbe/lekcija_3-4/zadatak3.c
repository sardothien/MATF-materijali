/* Napisati funkcije za rad sa celobrojnim matricama:
(a) void ucitavanje(int mat[][MAX], int* n, int* m)
kojom se prvo učitava dimenzija matrice (brojevi m i
n), a potom i vrednosti matrice celih brojeva mat,
(b) void ispis(int mat[][MAX], int n, int m) kojom se
ispisuju vrednosti matrice mat dimenzije m × n.
Napisati program koji najpre učitava, a zatim i
ispisuje vrednosti učitane matrice. Pretpostaviti da
je maksimalna dimenzija matrice 50 × 50. U slučaju
greške ispisati odovarajuću poruku. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void ucitavanje(int mat[][MAX], int* n, int* m){
 int i, j;
 scanf("%d%d", m, n);
 if(*m<=0 || *m>MAX || *n<=0 || *n>MAX){
  printf("-1\n");
  exit(EXIT_FAILURE);
 }
 
 for(i=0; i<*m; i++){
  for(j=0; j<*n; j++){
   scanf("%d", &mat[i][j]);
  }
 }
}

void ispis(int mat[][MAX], int n, int m){
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
 int m, n;
 
 ucitavanje(mat, &n, &m);
 ispis(mat, n, m);
 
 return 0;
}
