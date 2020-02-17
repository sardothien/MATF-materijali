/* Napisati program koji za uneti ceo broj x ispisuje njegov znak, tj da li je broj jednak nuli, manji od nule ili veći od nule. */

#include <stdio.h>

int main(){
 
  int x;
  
  printf("Unesite jedan ceo broj: ");
  scanf("%d", &x);
  
  if(x<0){
   printf("Broj je manji od nule.\n");
  }
  if(x>0){
   printf("Broj je veci od nule.\n");
  }
  if(x==0){
   printf("Broj je jednak nuli.\n");
  }
 
 return 0;
}
