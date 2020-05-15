/* Napisati rekurzivnu funkciju void trougao(int n, int trenutna linija)
koja za dato n iscrtava trougao dimenzije n */

#include <stdio.h>

void trougao(int n, int trenutna_linija){
 if(n<=trenutna_linija)
  return;  
 int i;
 for(i=0; i<n-trenutna_linija-1; i++){
  printf(" ");
 }
 for(; i<n; i++){
  printf("+");
 }
 printf("\n");
 trougao(n, trenutna_linija+1);
}

int main(){

 trougao(8, 0);
 
 return 0;
}
