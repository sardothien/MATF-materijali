/* Napisati program koji za uneto n ispisuje tablicu brojeva tako da su u prvoj
vrsti svi brojevi od 1 do n, a svaka naredna vrsta dobija se rotiranjem
prethodne vrste za jedno mesto u levo. */

#include <stdio.h>

int main(){

 int n, i, j;
 scanf("%d", &n);
 
 for(i=1; i<=n; i++){
  for(j=i; j<=n; j++){
   printf("%3d ", j);
  }
  for(j=1; j<i; j++){
   printf("%3d ", j);
  }
  printf("\n");
 }
 
 return 0;
}
