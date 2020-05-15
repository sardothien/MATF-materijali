/* Napisati program koji sa standardnog ulaza
ucitava ceo broj n, 1≤n≤50, cele brojeve k i l, 
0≤k, l<n a zatim kvadratnu matricu dimenzija nxn
ciji su elementi celi brojevi. Na standardni izlaz
ispisati sumu elemenata koji se nalaze na ivicama
podmatrice unete matrice ciji gornji levi ugao ima
koordinate (k,k) a donji desni (l,l). U slucaju
neispravnog ulaza, na standardni izlaz ispisati -1 */

#include <stdio.h>
#define MAX 50

int main(){
 int n, k, l, suma;
 int i, j;
 int mat[MAX][MAX];
 
 scanf("%d", &n);
 scanf("%d%d", &k, &l);
 if(n<1 || n>50 || k<0 || l>=n){
  printf("-1\n");
  return -1;
 }
 
 for(i=0; i<n; i++){
  for(j=0; j<n; j++){
   scanf("%d", &mat[i][j]);
  }
 }
 
 for(i=k; i<=l; i++)
  for(j=k; j<=l; j++){
   if(j==l || j==k || i==l || i==k)   
    suma=suma+mat[i][j];
  }
  
 printf("%d\n", suma); 
 
 return 0; 
}
