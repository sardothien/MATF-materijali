/* Napisati program koji za dva učitana niza a i b dimenzije
n formira i na izlaz ispisuje niz c koji se dobija naizmeničnim
raspoređivanjem elemenata nizova a i b, tj.
c=[a0,b0,a1,b1,...,an-1,bn−1]. Pretpostaviti da dimenzija
učitanih nizova nije veća od 100. */

#include <stdio.h>

#define MAX 100

int main(){

 int a[MAX], b[MAX], c[2*MAX];
 int n, i;
 scanf("%d", &n);
 
 if(n<=0 || n>100){
  printf("-1\n");
  return -1;
 }
 
 for(i=0; i<n; i++){
  scanf("%d", &a[i]);
 }
 for(i=0; i<n; i++){
  scanf("%d", &b[i]);
 }
 
 for(i=0; i<n; i++){
  c[2*i]=a[i];
  c[2*i+1]=b[i];
 }
 
 for(i=0; i<2*n; i++){
  printf("%d ", c[i]);
 }
 
 printf("\n");
 
 return 0;
}
