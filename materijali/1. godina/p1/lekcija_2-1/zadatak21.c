/* Napisati program koji za unete koeficijente kvadratne jednačine ispisuje koliko realnih rešenja jednačina ima i ako ih ima, ispisuje ih zaokružene na dve decimale. */

#include <stdio.h>
#include <math.h>

int main(){
 
  float a,b,c, D;
  
  printf("Unesite koeficijente A, B i C: ");
  scanf("%f%f%f", &a, &b, &c);
  
  D=b*b-4*a*c;
  
  if(D<0){
   printf("Jednacina nema resenja.\n");
  }
  if(D>0){
   printf("Jednacina ima dva razlicita realna resenja:\n %.2f i %.2f\n", (-b+sqrt(D))/2*a, (-b-sqrt(D))/2*a);
  }
  if(D==0){
   printf("Jednacina ima jedno dvostruko resenje:\n %.2f\n", -b/2*a);
  } 

  return 0;
}
