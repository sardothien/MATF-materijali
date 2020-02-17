/* Napisati program koji za unetu godinu ispisuje da li je prestupna. */

#include <stdio.h>

int main(){
 
  int g;
  
  printf("Unesite godinu: ");
  scanf("%d", &g);
  
  if(g<0){
    printf("Nekorektan unos!\n");
    return -1;
  }
 
 if((g%4==0 && g%100!=0) || g%400==0){
    printf("Godina je prestupna.\n");   
 }
  else{
   printf("Godina nije prestupna.\n");   
  }
 
  return 0;
}
