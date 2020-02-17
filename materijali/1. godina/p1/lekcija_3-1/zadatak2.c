/* Napisati program koji za učitani niz ispisuje:
(a) elemente niza koji se nalaze na parnim pozicijama.
(b) parne elemente niza.
Pretpostaviti da je dimenzija niza broj koji nije veći od 100. */

#include <stdio.h>

#define MAX 100

int main(){

 int a[MAX];
 int n, i;
 scanf("%d", &n);
 
 if(n<=0 || n>100){
  printf("-1\n");
  return -1;
 }
 
 for(i=0; i<n; i++){
  scanf("%d", &a[i]);
 }
 /* Pod a) */
 for(i=0; i<n; i=i+2){
  if(i%2==0){
    printf("%d ", a[i]);
  }
 }

 printf("\n");
 /* Pod b) */
 for(i=0; i<n; i++){
  if(a[i]%2==0){
    printf("%d ", a[i]);
  }
 }

 printf("\n");

 return 0;
}
