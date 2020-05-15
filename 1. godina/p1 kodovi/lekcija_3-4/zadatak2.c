/* Napisati program koji za učitanu celobrojnu matricu dimenzije
m×n izračunava njenu Ekulidsku normu. Pretpostaviti da je maksimalna
dimenzija matrice 50 × 50. U slučaju greške ispisati odovarajuću
poruku. Uputstvo: Euklidska norma matrice je kvadratni koren sume
kvadrata svih elemenata matrice. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 50

int main(){
 int mat[MAX][MAX];
 int m, n;
 int suma = 0;
 int i, j;
 scanf("%d%d", &m, &n);

 if(n<=0 || n>MAX || m<=0 || m>MAX){
  printf("-1\n");
  exit(EXIT_FAILURE);
 }

 for(i=0; i<m; i++)
  for(j=0; j<n; j++)
   scanf("%d", &mat[i][j]);

 for(i=0; i<m; i++)
  for(j=0; j<n; j++)
   suma += mat[i][j] * mat[i][j];

 printf("Euklidska norma je %.3lf.\n", sqrt(suma));

 return 0;
}
