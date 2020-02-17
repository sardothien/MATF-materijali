/* U prodavnici se nalaze artikala čije cene su realni pozitivni brojevi. 
Program unosi cene artikala sve do unosa broja nula 0. Napisati program koji 
izračunava i ispisuje prosečnu vrednost cena u radnji. */

#include <stdio.h>

int main(){

 int br;
 float cena, pv=0; 
 
 while(1){
  scanf("%f", &cena);
  if(cena==0){
   break;
  }
  if(cena<0){
   printf("-1\n");
   return -1;
  }
  pv=pv+cena;
  br++;
 }
 
 if(br>0){
  printf("Prosecna cena: %.4f\n", pv/br);
 }
 else if(br==0){
  printf("Nisu unete cene.\n");
 } 
   
 return 0;
}
