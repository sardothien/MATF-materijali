/* Napisati funkciju float razlomljeni_deo(float x) koja
izračunava razlomljeni deo broja x. Napisati program koji učitava jedan realan
broj i ispisuje rezultat poziva funkcije. */

#include <stdio.h>

float razlomljeni_deo(float x){

 int x1;
 float k;
 x1=x;
 
 k=x-x1;
 if(k<0){
  k=-1*k;
 }
 
 return k;
}

int main(){
 float x;
 scanf("%f", &x);
 
 printf("%f\n", razlomljeni_deo(x));
 
 return 0;
}
