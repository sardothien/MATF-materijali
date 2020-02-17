/* Napisati program koji za uneti prirodan broj ispisuje da li je on deljiv sumom svojih cifara. */

#include <stdio.h>

int main() {

 int n, c, s=0, pom;
 
 scanf("%d", &n);
 
 if(n<=0){
  printf("-1\n");
  return -1;
 }
 
 pom=n;
 
 while(n>0){
  c=n%10;
  s=s+c;
  n=n/10;
 }
 
 if(pom%s==0){
  printf("Deljiv je.\n");
 }
 else{
  printf("Nije deljiv.\n");
 }

 return 0;
}
