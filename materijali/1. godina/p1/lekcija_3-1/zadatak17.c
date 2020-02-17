/* Napisati program koji učitava dimenziju i elemente niza i
štampa niz u kojem su najveći i najmanji element niza razmenili
mesta. Ukoliko se najmanji ili najveći element više puta
pojavljuju u nizu, uzeti u obzir njihova prva pojavljivanja.
Pretpostaviti da je dimenzija niza broj koji nije veći od 100.*/

#include <stdio.h>

#define MAX 100

void ucitaj(int a[], int n){
 int i;
 for(i=0; i<n; i++){
  scanf("%d", &a[i]);
 }
}

void ispisi(int a[], int n){
 int i;
 for(i=0; i<n; i++){
  printf("%d ", a[i]);
 }
 printf("\n");
}

int main(){

 int a[MAX];
 int n, i, pom, min, max;
 
 scanf("%d", &n); 
 if(n<=0 || n>100){
  printf("-1\n");
  return -1;
 }
 
 ucitaj(a, n);
 pom=a[0];
 for(i=0; i<n; i++){
  if(a[i]<pom){
   pom=a[i];
   min=i;
  }
 }
 pom=a[0];
 for(i=0; i<n; i++){
  if(a[i]>pom){
   pom=a[i];
   max=i;
  }
 }

 pom=a[min];
 a[min]=a[max];
 a[max]=pom;
 
 ispisi(a, n);
 
 return 0;
}
