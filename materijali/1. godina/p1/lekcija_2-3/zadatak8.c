/* Napisati funkciju int faktorijel(int n) koja računa
faktorijel broja n. Napisati i program koji učitava dva
cela broja x i y iz intervala [0, 12] i ispisuje vrednost 
zbira x! + y!. */

#include <stdio.h>

int faktorijel(int n){

 int f=1, i;
 
 for(i=1; i<=n; i++){
  f*=i;
 }
 
 return f;
}

int main(){
 
 int x, y;
 scanf("%d%d", &x, &y);
 
 if(x<0 || x>12 || y<0 || y>12){
  printf("-1\n");
  return -1;
 }
 
 printf("%d\n", faktorijel(x) + faktorijel(y));

 return 0;
}
