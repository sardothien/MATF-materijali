/* Napisati program koji učitava prirodan broj n, a potom
iscrtava odgovarajuću sliku. Pretpostaviti da je unos korektan.
Slika sadrži pravougli trougao sastavljen od zvezdica. Kateta trougla je
dužine n, a prav ugao se nalazi u gornjem desnom uglu slike. */

#include <stdio.h>

int main(){

 int n, i, j;
 scanf("%d", &n);
 
 for(i=0; i<n; i++){
  for(j=0; j<n; j++){
   if(j>=i){
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
