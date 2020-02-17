/* Program učitava pet karaktera. Ispisati koliko puta su se pojavile cifre. */

#include <stdio.h>

int main(){

 char c1, c2, c3, c4, c5;
 int br=0;
 
 printf("Unesite pet karaktera: ");
 scanf("%c%c%c%c%c", &c1, &c2, &c3, &c4, &c5);
 
 if(c1>='0' && c1<='9'){
   br++;
 }
 if(c2>='0' && c2<='9'){
   br++;
 }
 if(c3>='0' && c3<='9'){
   br++;
 }
 if(c4>='0' && c4<='9'){
   br++;
 }
 if(c5>='0' && c5<='9'){
   br++;
 }
 
 printf("%d\n", br);
 
  return 0;
}
