/* Program učitava pet karaktera. Ispisati koliko puta su se pojavile cifre. */

#include <stdio.h>
#include <ctype.h>

int main(){
 
 int br=0;
 
 printf("Unesite pet karaktera: ");
 
 if(isdigit(getchar())){
   br++;
 }
 if(isdigit(getchar())){
   br++;
 }

 if(isdigit(getchar())){
   br++;
 }

 if(isdigit(getchar())){
   br++;
 }

 if(isdigit(getchar())){
   br++;
 }
  
 printf("%d\n", br);
 
  return 0;
}
