/* Napisati funkciju koja za dve prave date svojim koeficijentima
pravca i slobodnim članovima određuje njihovu tačku preseka. Funkcija
treba da vrati 1 ako se prave seku i 0 ako nemaju tačku preseka (ako
su paralelne). Napisati program koji učitava podatke o pravama,
poziva napisanu funkciju i ispisuje odgovarajuću poruku. */

#include<stdio.h>

int presek(float k1, float n1, float k2, float n2, float *x, float *y){
 if(k1==k2){
  return 0;
 }
   
 *x = -(n1-n2)/(k1-k2);
 *y = k1*(*x)+n1;
 return 1;
}

int main(){
 float k1,k2,n1,n2;
 float x,y;
  
 scanf("%f%f",&k1,&n1);
 scanf("%f%f",&k2,&n2);
   
 if(presek(k1,n1,k2,n2,&x,&y)){
  printf("Prave se seku u tacki (%.2f, %.2f)\n", x,y);
 }
 else{
  printf("Prave su paralelne\n");
 }
      
 return 0;
}
