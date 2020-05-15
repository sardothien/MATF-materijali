/* Prvi red datoteke matrica.txt sadrzi 2 cela broja manja od 50
koji predstavljaju redom broj vrsta i broj kolona realne matrice
A. Svaki sledeci red sadrzi po jednu vrstu matrice. Napisati
program koji pronalazi sve elemente matrice A koji su jednaki
zbiru svih svojih susednih elemenata i stampa ih u obliku
(broj vrste, broj kolone, vrednost elementa). U slucaju greske na
standardni izlaz za greske ispisati -1. Pretpostaviti da je
sadrzaj datoteke ispravan. */

#include <stdio.h>
#include <stdlib.h>

int main(){
 FILE *in;
 int m, n, i, j;
 float mat[50][50];
 
 if((in=fopen("matrica.txt", "r"))==NULL){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 fscanf(in, "%d%d", &m, &n);
 
 for(i=0; i<m; i++){
  for(j=0; j<n; j++){
   fscanf(in, "%f", &mat[i][j]);
  }
 }
 
 fclose(in);
 
 for(i=0; i<m; i++){
  for(j=0; j<n; j++){
   float s=0;
   s=(i>0 && j>0 ? mat[i-1][j-1]:0)
    +(i>0 ? mat[i-1][j]:0)
    +(i>0 && j<n-1 ? mat[i-1][j+1]:0)
    +(j>0 ? mat[i][j-1]:0)
    +(j<n-1 ? mat[i][j+1]:0)
    +(i<m-1 && j>0 ? mat[i+1][j-1]:0)
    +(i<m-1 ? mat[i+1][j]:0)
    +(i<m-1 && j<n-1 ? mat[i+1][j+1]:0);
    
   if(s==mat[i][j]){
    fprintf(stdout, "(%d %d %d)\n", i, j, (int)mat[i][j]);
   }
  }
 } 
 
 return 0;
}
