/* Napisati funkciju int zbir_delilaca(int n) koja izračunava zbir
delilaca broja n. Napisati program koji učitava ceo broj k i ispisuje
zbir delilaca svakog broja od 1 do k. */

#include <stdio.h>

int zbir_delilaca(int n){
 int i=0;
 int s=0;
 
 for(i=1; i<=n; i++){
  if(n%i==0){
   s=s+i;
  }
 }
 return s;
}

int main(){
 
 int k, i;
 scanf("%d", &k);
 
 if(k<=0){
  printf("-1\n");
 }
 else{
  for(i=1; i<=k; i++){
   printf("%d ", zbir_delilaca(i));
  }
 }
 
 return 0;
}
