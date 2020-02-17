/* Napisati program koji za unetih pet karaktera ispisuje koliko je među njima malih slova. */

#include <stdio.h>

int main(){

 char c1, c2, c3, c4, c5;
 int br=0;
 
 printf("Unesite pet karaktera: ");
 scanf("%c %c %c %c %c", &c1, &c2, &c3, &c4, &c5);
 
 if(c1>='a' && c1<='z'){
   br++;
 }
 if(c2>='a' && c2<='z'){
   br++;
 }
 if(c3>='a' && c3<='z'){
   br++;
 }
 if(c4>='a' && c4<='z'){
   br++;
 }
 if(c5>='a' && c5<='z'){
   br++;
 }
 
 printf("Broj malih slova: %d\n", br);
 
  return 0;
}
