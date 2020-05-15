/* Napisati program koji učitava tri cela broja i ispisuje zbir pozitivnih. */

#include <stdio.h>

int main(){

  int x, y, z, s=0;
  
  printf("Uneti tri cela broja: ");
  scanf("%d%d%d", &x, &y, &z);
  
  if(x > 0){
    s=s+x;
  }
  if(y > 0){
    s=s+y;
  }
  if(z > 0){
    s=s+z;
  }
  
  printf("Suma unetih pozitivnih brojeva: %d\n", s);
    
  return 0;
}
