/* Napisati program koji za uneti prirodan broj n zvezdicama iscrtava slovo X dimenzije n. Pretpostaviti da je unos korektan. */

#include <stdio.h>

int main(){

 int n, i, j;
 scanf("%d", &n);
 
 for(i=0; i<n; i++){
  for(j=0; j<n; j++){
   if(i==j || i+j==n+1){
     printf("*");
   }
   else{
    printf(" ");
   }
  }
  printf("\n");
 }
 
 return 0;
}
