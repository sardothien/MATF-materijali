/* Sa standardnog ulaza se učitava ceo broj n (manji od 100) i
elementi dvaju nizova a i b dimenzije n. Napisati program
koji formira i ispisuje niz c čiju prvu polovinu čine
elementi niza b, a drugu polovinu elementi niza a. */

#include <stdio.h>

#define MAX 100 

int main(){
 int n, i, k;
 int a[MAX], b[MAX], c[2*MAX];
 
 scanf("%d", &n);
 if(n<0 || n>MAX){
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
  c[i]=b[i];
  c[n+i]=a[i];
 }
 
 for(i=0; i<2*n; i++){
  printf("%d ", c[i]);
 }
 
 printf("\n");
 
 return 0;
}
