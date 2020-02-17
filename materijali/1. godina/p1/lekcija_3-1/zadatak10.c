/* Napisati program koji učitava dimenziju n celobrojnog niza
a i njegove elemente, i iz niza a izbacuje sve elemente koji nisu
deljivi svojom poslednjom cifrom. Izuzetak su elementi čija je
poslednja cifra 0 koje treba zadržati. Program treba da ispiše
izmenjeni niz na standardni izlaz. Niz a sadrži najviše 100
elemenata. */

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
  
 for(i=0; i<n; i++){
  int c=a[i]%10;
  if(c==0){
   printf("%d ", a[i]);
   continue;
  }
  if(a[i]%c==0){
   printf("%d ", a[i]);
  }
 }
  
 printf("\n");
 
 return 0;
}
