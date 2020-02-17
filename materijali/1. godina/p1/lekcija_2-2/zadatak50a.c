/* Napisati program koji za unetu pozitivnu celobrojnu vrednost n ispisuje
tablicu množenja. */

#include <stdio.h>

int main(){

 int n, i, j;
 scanf("%d", &n);
 
 if(n<0){
  printf("-1\n");
  return -1;
 }
 
 for(i=1; i<=n; i++){
  for(j=1; j<=n; j++){
   printf("%3d ", i*j);
  }
  printf("\n");
 }
 
 return 0;
}
