/* Napisati program koji učitava četvorocifreni broj i ispisuje broj koji se dobija kada se unetom broju razmene najmanja i najveća cifra. */

#include <stdio.h>
#include <math.h>

int main(){
 
  int x, absx, min, max, min_p, max_p, rez;
  int c1, c10, c100, c1000;
  
  scanf("%d", &x);
  
  absx=abs(x);
  
  if(absx<1000 || absx>9999){
     printf("-1\n");
     return -1;
  } 

  c1=absx%10;
  c10=(absx/10)%10;
  c100=(absx/100)%10;
  c1000=absx/1000;
  
  min = c1000;
  min_p = 1000;
  
  if(c100<min){
    min = c100;
    min_p = 100;
  }
  if(c10<min){
    min = c10;
    min_p = 10;
  }
  if(c1<min){
    min = c1;
    min_p = 1;
  }
    
   max = c1000;
  max_p = 1000;
  
  if(c100>max){
    max = c100;
    max_p = 100;
  }
  if(c10>max){
    max = c10;
    max_p = 10;
  }
  if(c1>max){
    max = c1;
    max_p = 1;
  }
  
  rez = absx + min*max_p + max*min_p - min*min_p - max*max_p;
  
  if(x<0){
   rez *= -1;
  }
  
  printf("%d\n", rez);

  return 0;
}
