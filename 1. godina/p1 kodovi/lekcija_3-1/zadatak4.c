/* Napisati program koji za dva cela broja x i y koja se
učitavaju sa standardnog ulaza proverava da li se zapisuju
pomoću istih cifara. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main(){
 int x, y, i, c, br=1;
 int a[MAX], b[MAX];
 
 scanf("%d%d", &x, &y);
 x=abs(x);
 y=abs(y);
 
 for(i=0; i<MAX; i++){
  a[i]=0;
  b[i]=0;
 }
 
 while(x>0){
  c=x%10;
  a[c]++;
  x=x/10;
 }
 while(y>0){
  c=y%10;
  b[c]++;
  y=y/10;
 }
 
 for(i=0; i<MAX; i++){
  if(a[i]!=b[i]){
   br=0;
   break;
  }
 }
 
 if(br){
  printf("Iste cifre.\n");
 }
 else{
  printf("Razlicite cifre.\n");
 }
 
 return 0;
}
