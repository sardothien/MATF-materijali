/* FEBRUAR - 2017 zadatak 2
Napisati program koji sa standardnog ulaza uitava nisku s i ceo broj
n, 1 ≤ n ≤ 100, a zatim n niski i na standardni izlaz ispisuje sve
niske za koje vazi da im je s prefiks ili sufiks. Maksimalna duina 
svih niski koje se ucitavaju je 100 karaktera. U slucaju neispravnog
ulaza na standardni izlaz ispisati -1. */

#include <stdio.h>
#include <string.h>
#define MAX 101

int main(){
 char s[MAX];
 char x[MAX];
 int n;
    
 scanf("%s", s);
 scanf("%d", &n);
 if(n<1 || n>100){
  printf("-1");
  return -1;
 }

 int i;
 int pref, suf;
 int l1=strlen(s);
    
 for(i=0; i<n; i++){
  pref=1;
  suf=1;
  scanf("%s", x);
  int j;
  int l2=strlen(x);
  if(l1>l2)
   continue;
  for(j=0; j<l1; j++){
   if(x[j] != s[j]){
    pref=0;
    break;
   }
  }
  for(j=0; j<l1; j++){
   if(x[l2-l1+j] != s[j]){
    suf=0;
    break;
   }
  }
  if(pref || suf)
   printf("%s\n", x);
 }
    
 return 0;
}
