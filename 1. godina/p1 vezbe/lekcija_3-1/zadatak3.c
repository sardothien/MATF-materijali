/* Napisati program koji za učitani ceo broj, ispisuje broj
pojavljivanja svake od cifara u zapisu tog broja. Uputstvo: Za evidenciju broja pojavljivanja svake cifre pojedinačno, koristiti niz. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main(){

 int a[MAX];
 int x, i;
 scanf("%d", &x);
 x=abs(x);
  
 for(i=0; i<MAX; i++){
  a[i]=0;
 }
 
 while(x>0){
  int c=x%10;
  a[c]++;
  x=x/10;
 }
 
 for(i=0; i<MAX; i++){
  if(a[i]>0){
    printf("%d: %d\n", i, a[i]);
  }
 }

 return 0;
}
