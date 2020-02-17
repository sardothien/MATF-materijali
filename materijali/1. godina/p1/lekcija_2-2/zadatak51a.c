/* Napisati program koji za unet prirodan broj n zvezdicama
iscrtava odgovarajuću sliku. Pretpostaviti da je unos korektan. Slika sadrži kvadrat stranice n sastavljen od zvezdica. */

#include <stdio.h>

int main(){

 int n, i, j;
 scanf("%d", &n);
 
 for(i=1; i<=n; i++){
  for(j=1; j<=n; j++){
    printf("*");
  }
  printf("\n");
 }

 return 0;
}
