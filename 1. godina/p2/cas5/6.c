/* Napisati rekurzivnu funkciju void heksa zapis
(int x) koja odredjuje heksadekadni zapis datog
celog broja. */

#include <stdio.h>

void heksa_zapis(int x){
 if(x<16){
  if(x<10){
   printf("%d", x);
   return;
  }
  else{
   printf("%c", 'A'+x-10);
   return;
  }
 }
    
  heksa_zapis(x/16);
  int a=x%16;
  if(a<16)
   printf("%d", a);
  else
   printf("%c", 'A'+a-10);
}

int main(){
 int n;
 scanf("%d", &n);
 
 heksa_zapis(n);
 printf("\n");
 
 return 0;
}
