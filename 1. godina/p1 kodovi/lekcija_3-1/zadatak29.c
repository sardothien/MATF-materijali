/* Napisati funkciju float zbir_pozitivnih(float a[],
int n, int k) koja izračunava zbir prvih k pozitivnih elemenata
realnog niza a dužine n. Napisati i program koji testira rad
funkcije. Pretpostaviti da dužina niza neće biti veća od 100.*/

#include <stdio.h>

#define MAX 100

float zbir_pozitivnih(float a[], int n, int k){
 int i;
 float zbir=0;
 for(i=0; i<n && k>0; i++){
  if(a[i] >= 0){
    zbir+=a[i];
    k--;
  }
 }
 return zbir;
} 

int main(){

 int n, i, k;
 float a[MAX];
  
 scanf("%d", &n);
 if(n<=0 || n>MAX){
  printf("-1\n");
  return 0;
 }
  
 for(i=0; i<n; i++){
  scanf("%f", &a[i]);
 }
  
 scanf("%d", &k);
 if(k<0 || k>n){
  printf("-1\n");
  return 0;
 }

 printf("%.2f\n", zbir_pozitivnih(a,n,k));
  
  return 0;
}
