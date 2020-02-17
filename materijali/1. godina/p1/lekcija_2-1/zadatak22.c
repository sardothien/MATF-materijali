/* Napisati program koji za uneti četvorocifreni broj proverava da li su njegove cifre uređene rastuće, opadajuće ili nisu uređene i štampa odgovarajuću poruku. */

#include <stdio.h>
#include <stdlib.h>

int main() {
  int x;
  char c1, c10, c100, c1000;
  
  printf("Unesi jedan cetvorocifreni broj:");
  scanf("%d", &x);
  
  x=abs(x); 
  
  if(x<1000 || x>9999){
     printf("Uneti broj nije cetvorocifren!\n");
     return -1;
  }
  
  c1=x%10;
  c10=(x/10)%10;  
  c100=(x/100)%10;  
  c1000=x/1000;
     
  if(c1000<=c100 && c100<=c10 && c10<=c1){
     printf("Cifre su uredjene neopadajuce.\n");
  }
  else if(c1000>=c100 && c100>=c10 && c10>=c1){
     printf("Cifre su uredjene nerastuce.\n");
  }
    else{
       printf("Cifre nisu uredjene.\n");
     }
     
  return 0;
}
