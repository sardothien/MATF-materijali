/* Napisati program koji za unetu cenu proizvoda ispisuje najmanji broj novčanica koje je potrebno izdvojiti prilikom plaćanja proizvoda. Na raspolaganju su novčanice od 5000, 2000, 1000, 500, 200, 100, 50, 20, 10 i 1 dinar. */

#include <stdio.h>

int main()
{
   unsigned x;
   printf("Unesi cenu: ");
   scanf("%u", &x);
   
   printf("%u=%u*5000 + ", x,x/5000); 
   x=x%5000;
   
   printf("%u*2000 + ", x/2000);
   x=x%2000;

   printf("%u*1000 + ", x/1000);
   x=x%1000;

   printf("%u*500 + ", x/500);
   x=x%500;

   printf("%u*200 + ", x/200);
   x=x%200;

   printf("%u*100 + ", x/100);
   x=x%100;

   printf("%u*50 + ",x/50);
   x=x%50;

   printf("%u*20 + ", x/20);
   x=x%20;

   printf("%u*10 + ", x/10);
   x=x%10;

   printf("%u*1\n", x);

   return 0;
}
