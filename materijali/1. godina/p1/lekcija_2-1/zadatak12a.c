/* Program učitava pet karaktera. Ispisati koliko puta su se pojavile cifre. */

#include <stdio.h>
#include <ctype.h>

int main(){
 
 char c1, c2, c3, c4, c5;
 int br=0;
 
 printf("Unesite pet karaktera: ");
 scanf("%c%c%c%c%c", &c1, &c2, &c3, &c4, &c5);
 
 if(isdigit(c1)){
   br++;
 }
 if(isdigit(c2)){
   br++;
 }
 if(isdigit(c3)){
   br++;
 }
 if(isdigit(c4)){
   br++;
 }
 if(isdigit(c5)){
   br++;
 }
  
 printf("%d\n", br);
 
  return 0;
}
