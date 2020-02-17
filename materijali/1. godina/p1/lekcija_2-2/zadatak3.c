/* Napisati program koji učitava pozitivan ceo broj n a potom ispisuje sve cele brojeve od 0 do n. */

#include <stdio.h>

int main(){
 
 int n, i;
 
 scanf("%d", &n);

 if(n<=0){
  printf("-1\n");
  return -1;
 }

 i=0;
 while(i<=n){
  printf("%d ", i);
  i++;
 }

 return 0;
}
