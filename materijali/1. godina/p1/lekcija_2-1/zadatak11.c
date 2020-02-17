/* Program učitava pet karaktera. Napisati koliko se puta pojavilo veliko ili malo slovo a. */

#include <stdio.h>

int main(){

 char c1, c2, c3, c4, c5;
 int br=0;
 
 printf("Unesite pet karaktera: ");
 scanf("%c%c%c%c%c", &c1, &c2, &c3, &c4, &c5);
 
 if(c1=='a' || c1=='A'){
   br++;
 }
 if(c2=='a' || c2=='A'){
   br++;
 }
 if(c3=='a' || c3=='A'){
   br++;
 }
 if(c4=='a' || c4=='A'){
   br++;
 }
 if(c5=='a' || c5=='A'){
   br++;
 }
 
 printf("%d\n", br);
 
  return 0;
}
