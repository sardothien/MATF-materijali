/* Sa standardnog ulaza se unosi broj elemenata niza a i
njegovi elementi. Napisati program koji od datog niza formira
niz b u koji ulaze elementi niza a koji se pojavljuju tačno 
tri puta. Pretpostaviti da će uneti niz imati najviše 100
elemenata. Pretpostaviti da je dimenzija niza broj koji nije
veći od 100. */

#include <stdio.h>
#define MAX 100

int broj_pojavljivanja(int a[], int n, int x){
 int i;
 int br=0;

 for(i=0; i<n; i++){
  if(a[i] == x){
    br++;
  }
 }
 return br;
}

int main(){
 int n, i, j, x, z;
 int a[MAX], b[MAX];
 
 scanf("%d", &n);
 for(i=0; i<n; i++){
  scanf("%d", &a[i]);
 }
 
 j=0;
 for(i=0; i<n; i++){
  if(broj_pojavljivanja(a, n, a[i])==3 && broj_pojavljivanja (b, j, a[i]) ==0){
   b[j]=a[i];
   j++;
  }
 }
 
 z=j;
 for(i=0; i<z; i++){
  printf("%d ", b[i]);
 }
 printf("\n");
 return 0;
}
