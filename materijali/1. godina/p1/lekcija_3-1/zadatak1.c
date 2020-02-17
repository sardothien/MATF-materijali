/* Ako su a=(a1,...,an) i b=(b1,...,bn) vektori dimenzije n, njihov skalarni proizvod je a·b=a1·b1+...+an·bn. Napisati program koji računa skalarni proizvod dva vektora. Vektori se zadaju kao celobrojni nizovi sa najviše 100 elemenata. Program učitava dimenziju i elemente nizova, a na izlaz ispisuje vrednost skalarnog proizvoda. */

#include <stdio.h>

#define MAX 100

int main(){

 int a[MAX], b[MAX];
 int n, i, s=0;
 scanf("%d", &n);
 
 if(n<=0 || n>100){
  printf("-1\n");
  return -1;
 }
 
 for(i=0; i<n; i++){
  scanf("%d", &a[i]);
 }
 for(i=0; i<n; i++){
  scanf("%d", &b[i]);
 }
 
 for(i=0; i<n; i++){
  s=s+a[i]*b[i];
 }

 printf("%d\n", s);

 return 0;
}
