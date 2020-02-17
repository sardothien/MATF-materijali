/* Program učitava ceo pozitivan broj n, a zatim i n celih brojeva. Napisati program koji ispisuje broj sa najvećim brojem cifara. Ukoliko ima više takvih, ispisati prvi. */

#include <stdio.h>
#include <stdlib.h>

int main() {

 int n, m, max, maxm;
 scanf("%d", &n);
 
 if(n<0){
  printf("-1\n");
  return -1;
 }
 
 max=0;
 while(n>0){
  scanf("%d", &m);
  if(m>max){
   max=m;
   maxm=m;
  }
  n--;
 }
 
 printf("%d\n", maxm);
   
 return 0;
}
