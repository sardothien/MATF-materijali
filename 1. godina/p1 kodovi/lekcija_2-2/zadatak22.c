/* Program učitava ceo pozitivan broj n, a zatim i n celih brojeva. Napisati program koji ispisuje broj sa najvećom cifrom desetica. Ukoliko ima više takvih, ispisati prvi. */

#include <stdio.h>
#include <stdlib.h>

int main() {

 int n, max, x, c10, maxx;
 scanf("%d", &n);
 
 if(n<0){
  printf("-1\n");
  return -1;
 }
 
 max=0;
 while(n>0){
  scanf("%d", &x);
  c10=(abs(x)/10)%10;
  if(c10>max){
   max=c10;
   maxx=x;
  }
  n--;
 }
 
 printf("%d\n", maxx);
   
 return 0;
}
