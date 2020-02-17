/* Napisati funkciju int cifre(char s[], int n) koja izračunava
broj cifara u nizu karaktera a dužine n. Napisati program koji za
karaktere koji se unose u zasebnim redovima ispisuje broj unetih
cifara. Pretpostaviti da dužina niza neće biti veća od 100.*/

#include <stdio.h>
#include <ctype.h>

#define MAX 100

int cifre(char s[], int n){
 int i, br=0;
 for(i=0; i<n; i++){
  if(isdigit(s[i])){
   br++;
  }
 }
 return br;
}

int main(){

 char s[MAX];
 int n, i;
 
 scanf("%d", &n); 
 if(n<=0 || n>100){
  printf("-1\n");
  return -1;
 }
 
 for(i=0; i<n; i++){
  getchar();
  scanf("%c",&s[i]);
 }
 
 printf("%d\n", cifre(s,n));
 
 return 0;
}
