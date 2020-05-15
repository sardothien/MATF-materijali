/* Napisati program koji za uneti četvorocifreni broj ispisuje njegovu najveću cifru. */

#include <stdio.h>
#include <stdlib.h>

int main(){

  int x, c1, c10, c100, c1000, max;
  
  printf("Uneti cetvorocifreni broj: ");
  scanf("%d", &x);
  
  x=abs(x);
  
  if(x<1000 || x>9999){
     printf("Greska: Niste uneli cetvorocifren broj!\n");
     return -1;
  }
  
  c1=x%10;
  c10=(x/10)%10;
  c100=(x/100)%10;
  c1000=x/1000;
  
  if(c1>=c10 && c1>=c100 && c1>=c1000){
    max = c1;
  }
  if(c10>=c1 && c10>=c100 && c10>=c1000){
    max = c10;
  }
  if(c100>=c1 && c100>=c10 && c100>=c1000){
    max = c100;
  }
  if(c1000>=c1 && c1000>=c10 && c1000>=c100){
    max = c1000;
  }
  
  printf("Najveca cifra je: %d\n", max);
    
  return 0;
}
