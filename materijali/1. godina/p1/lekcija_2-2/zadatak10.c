/* Napisati program koji učitava ceo broj i ispisuje njegove cifre u obrnutom poretku. */

#include <stdio.h>
#include <stdlib.h>

int main() {

 int n, i;
 
 scanf("%d", &n);
 
 n=abs(n);
 
 for(i=0; n; i++){
  printf("%d ", n%10);
  n=n/10;
 }

 return 0;
}
