/* Napisati program koji za uneti realan broj ispisuje njegovu apsolutnu vrednost zaokruženu na dve decimale. */

#include <stdio.h>

int main(){

  float x, absx;

  printf("Uneti jedan realan broj: ");
  scanf("%f", &x);

  if(x < 0){
      absx = -x;
  }
   else{
      absx = x; 
   }
 
  printf("Njegova apsolutna vrednost je: %.2f\n", absx);

  return 0;
}
