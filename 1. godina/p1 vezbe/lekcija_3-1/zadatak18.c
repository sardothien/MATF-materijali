/* Napisati funkciju int min_max(int a[], int n) koja
pronalazi indekse najmanjeg i najvećeg elementa u nizu a
dimenzije n koristeći samo jedan prolaz kroz niz. Funkcija
kao povratnu vrednost vraća manji od ta dva indeksa. 
Napisati program koji testira ovu funkciju za učitane nizove
celih brojeva maksimalne dužine 100 elemenata. */

#include <stdio.h>
#define MAX 100

int min_max(int a[], int n){
 int i, max, min, maxpoz, minpoz;
 min=a[0];
 max=a[0];
 for(i=0; i<n; i++){
  if(a[i]<min){
   min=a[i];
   minpoz=i;
  }
  if(a[i]>max){
   max=a[i];
   maxpoz=i;
  }  
 }
 
 if(maxpoz<minpoz){
  return maxpoz;
 }
 else{
  return minpoz;
 }
}

int main(){
 int n, i;
 int a[MAX];
 
 scanf("%d", &n);
 for(i=0; i<n; i++){
  scanf("%d", &a[i]);
 }
 
 printf("%d\n", min_max(a, n));
 
 return 0;
}
