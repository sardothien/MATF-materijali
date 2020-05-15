/* Napisati program koji transformiše uneti niz tako što
kvadrira sve negativne elemente niza. Pretpostaviti da je
dimenzija niza broj koji nije veći od 100. */

#include <stdio.h>
#define MAX 100

int main(){
 int n, i;
 float a[MAX];
 
 scanf("%d", &n);
 for(i=0; i<n; i++){
  scanf("%f", &a[i]);
 }
 
 for(i=0; i<n; i++){
  if(a[i]<0){
   a[i]*=a[i];
  }
  printf("%.2f ", a[i]);
 }
 printf("\n");

 return 0;
}
