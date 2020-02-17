/* Napisati funkciju int prebrojavanje(int a[], int n)
koja izračunava broj elemenata celobrojnog niza a dužine n koji
su manji od poslednjeg elementa niza. Napisati i program koji
testira rad funkcije. Pretpostaviti da dužina niza neće biti veća
od 100.*/

#include <stdio.h>

#define MAX 100

int prebrojavanje(int a[], int n){
  int i, bm=0;
  for(i=0; i<n-1; i++){
   if(a[i]<a[n-1]){
      bm++;
   }
  }  
  return bm;
}

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
   
  printf("%d\n", prebrojavanje(a,n));
  
  return 0;
}
