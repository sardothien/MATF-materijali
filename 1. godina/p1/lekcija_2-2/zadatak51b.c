/* Napisati program koji za unet prirodan broj n zvezdicama
iscrtava odgovarajuću sliku. Pretpostaviti da je unos korektan. Slika sadrži rub kvadrata dimenzije n. */

#include <stdio.h>

int main(){

 int n, i, j;
 scanf("%d", &n);
 
 for(i=1; i<=n; i++){
  for(j=1; j<=n; j++){
   if(i>1 && i<n && j>1 && j<n){
    printf(" ");
   }
   else{
    printf("*");
   }
  }
  printf("\n");
 }

 return 0;
}
