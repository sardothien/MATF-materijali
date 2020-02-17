/* Napisati program koji učitava pozitivan ceo broj n, a zatim učitava n celih brojeva i ispisuje sumu pozitivnih i sumu negativnih unetih brojeva. */

#include <stdio.h>

int main() {

 int n, m, sp=0, sn=0;
 
 scanf("%d", &n);
 
 if(n<=0){
  printf("-1\n");
  return -1;
 }
 
 while(n>0){
  scanf("%d", &m);
  if(m>0){
   sp=sp+m;
  } 
  else{
   sn=sn+m;
  }
  n--;
 }
 
 printf("Suma pozitivnih: %d\n", sp);
 printf("Suma negativnih: %d\n", sn);

 return 0;
}
