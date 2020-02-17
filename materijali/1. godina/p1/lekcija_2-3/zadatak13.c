/* Napisati funkciju int sadrzi(int x, int c) koja ispituje 
da li se cifra c nalazi u zapisu celog broja x. Funkcija treba 
da vrati 1 ako se cifra nalazi u broju, a 0 inače. 
Napisati program koji učitava dva cela broja i ispisuje rezultat poziva funkcije. */

#include <stdio.h>
#include <stdlib.h>

int sadrzi(int x, int c){
 
 if(c<0 || c>9){
  printf("-1\n");
  exit(EXIT_FAILURE);
 }
 
 x=abs(x);
 while(x>0){
  if(x%10==c){
   return 1;
  }
  x=x/10;
 }
 
 return 0; 
}

int main(){
 
 int x, c;
 scanf("%d%d", &x, &c);
  
 printf("%d\n", sadrzi(x, c));

 return 0;
}
