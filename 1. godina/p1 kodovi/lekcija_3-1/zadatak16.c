/* Sa standardnog ulaza se učitava dimenzija niza, elementi
niza i jedan ceo broj k. Napisati program koji štampa indekse
elemenata koji su deljivi sa k. Pretpostaviti da je dimenzija
niza broj koji nije veći od 100. */

#include <stdio.h>
#define MAX 100

int main(){
 int n, k, i, br=0;
 int a[MAX];
 
 scanf("%d", &n);
 for(i=0; i<n; i++){
  scanf("%d", &a[i]);
 }
 scanf("%d", &k);
 
 for(i=0; i<n; i++){
  if(a[i]%k==0){
   printf("%d ", i);
   br++;
  }
 }
 
 if(br==0){
  printf("Nisu deljivi brojem k.");
 }
 printf("\n");
 return 0;
}
