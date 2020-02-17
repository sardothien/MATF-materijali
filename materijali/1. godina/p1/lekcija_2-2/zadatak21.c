/* U prodavnici se nalazi n artikala čije cene su realni brojevi. Napisati program koji učitava n, a potom i cenu svakog od n artikala i određuje i ispisuje najmanju cenu */

#include <stdio.h>

int main() {

 int n;
 float c, min;
 scanf("%d", &n);
 
 if(n<0){
  printf("-1\n");
  return -1;
 }
 
 min=0;
 while(n>0){
  scanf("%f", &c);
  if(c<=0){
   printf("-1\n");
   return -1;
  }
  if(min==0){
   min=c;
  }
  if(c<min){
   min=c;
  }
  n--;
 }
 
 printf("%f\n", min);
   
 return 0;
}
