/* Napisati program koji za uneti redni broj dana u nedelji ispisuje ime odgovarajućeg dana. U slučaju pogrešnog unosa ispisati odgovarajuću poruku. */

#include <stdio.h>

int main(){
  
  int x;
  
  printf("Unesite broj: ");
  scanf("%d", &x); 
  
  if(x==1){
    printf("U pitanju je: ponedeljak\n");
  }
  if(x==2){
    printf("U pitanju je: utorak\n");
  }
  if(x==3){
    printf("U pitanju je: sreda\n");
  }
  if(x==4){
    printf("U pitanju je: cetvrtak\n");
  }
  if(x==5){
    printf("U pitanju je: petak\n");
  }
  if(x==6){
    printf("U pitanju je: subota\n");
  }
  if(x==7){
    printf("U pitanju je: nedelja\n");
  }
  if(x<1 || x>7){
    printf("Greska! Nedozvoljen unos!\n");
    return -1;
  }
  
  return 0;
}
