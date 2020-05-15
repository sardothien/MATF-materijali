/* Napisati program koji učitava dva cela broja n i m ispisuje sve cele brojeve iz intervala [n, m].
(a) Koristiti while petlju.
(b) Koristiti for petlju.
(c) Koristiti do-while petlju. */

#include <stdio.h>

int main(){
 
 int n, m, i;
 
 scanf("%d %d", &n, &m);
 
 if(n>m){
  printf("-1\n");
  return -1;
 }
/* WHILE petlja
 i=n;
 while(i<=m){
  printf("%d ", i);
  i++;
 } */
 
 /* FOR petlja
 for(i=n; i<=m; i++){
   printf("%d ", i);
 } */
 
 /* DO WHILE petlja */
 i=n;
 do{
  printf("%d ", i);
  i++;
 } while(i<=m);

 return 0;
}
