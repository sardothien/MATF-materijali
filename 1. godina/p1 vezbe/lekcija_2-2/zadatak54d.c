/* Napisati program koji učitava prirodan broj n, a potom
iscrtava odgovarajuću sliku. Pretpostaviti da je unos korektan.
Slika sadrži pravougli trougao sastavljen od zvezdica. Kateta
trougla je dužine n, a prav ugao se nalazi u donjem desnom uglu
slike. */

#include <stdio.h>

int main(){

 int n, i, j;
 scanf("%d", &n);
 
 if(n<0){
  printf("-1\n");
  return -1;
 }
 
 for(i=1; i<=n; i++){
  for(j=1; j<=n; j++){
   if(i+j>n){
    printf("*");
   }
   else{
    printf(" ");
   }
  }
  printf("\n");
 }

 return 0;
}
