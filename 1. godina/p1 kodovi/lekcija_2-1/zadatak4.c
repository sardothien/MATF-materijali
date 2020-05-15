/* Napisati program koji za uneti ceo broj ispisuje njegovu recipročnu vrednost zaokruženu na četiri decimale. */

#include <stdio.h>

int main(){

  int x;
  float rx;
  
  printf("Unesite jedan ceo broj: ");
  scanf("%d", &x);
  
  if(x == 0){
     printf("Nedozvoljeno deljenje nulom!\n");
     return -1;
  }
  rx = 1.0/x;
  printf("Reciprocna vrednost unetog broja: %.4f\n", rx); 

  return 0;
}
