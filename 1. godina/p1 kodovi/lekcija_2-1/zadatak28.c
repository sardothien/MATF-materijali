/* Napisatiti program koji učitava dva cela broja i jedan od karaktera +, -, *, / ili % i ispisuje vrednost izraza dobijenog primenom date operacije na date argumente. U slučaju pogrešnog unosa ispisati odgovarajuću poruku. */

#include <stdio.h>
#include <ctype.h>

int main(){
	
   char c;
   int x, y, rez;
   
   scanf("%c%d%d", &c, &x, &y);
   	
   switch(c){
	case '+': rez = x+y;
	          break;
	case '-': rez = x-y;
	          break;
	case '*': rez = x*y;
	          break;
	case '/': if(y==0){
	            printf("-1\n");
	            return -1;
	          }
	           else 
	            rez = x/y;
	          break;
	case '%': if(y==0){
	            printf("-1\n");
	            return -1;
	          }
	           else 
	            rez = x%y;
                  break;         
	default: printf("-1\n");
	         return -1; 
	}

   printf("%d\n", rez);

  return 0;
}
