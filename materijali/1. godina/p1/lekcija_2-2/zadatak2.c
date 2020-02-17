/* Napisati program koji učitava ceo broj n i ispisuje n puta tekst Mi volimo da programiramo. */

#include <stdio.h>

int main(){
 
 int n, i;
 
 scanf("%d", &n);
 i=0;
 while(i<n){
  printf("Mi volimo da programiramo.\n");
  i++;
 }

 return 0;
}
