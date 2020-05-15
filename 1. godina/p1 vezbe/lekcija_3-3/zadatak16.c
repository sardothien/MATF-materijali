/* Napisati program koji učitava ceo broj i pretvara ga u
nisku.*/

#include <stdio.h>
#include <string.h>
#define MAX 10

int formiraj_niz_cifara(int n, char b[]){
 int i=0, neg = 0;
 char cifra;
 if(n<0){
  neg = 1;
  n = -n;
 }
 
 do{
  cifra = n%10;
  b[i]=cifra+'0';
  n/=10;
  i++;
 }while(n);
   
 if(neg){
  b[i]='-';
  i++;
 }   
  
 b[i]='\0';   
}

void obrni(char s[]){          
 char t;  
 int i,j;
 for(i=0,j=strlen(s)-1;i<j;i++, j--){ 
  t = s[i];
  s[i] = s[j];
  s[j] = t;   
 }
}

void broj_u_niz_cifara(int n, char broj[]){
  formiraj_niz_cifara(n, broj);
  obrni(broj);
}

int main(){
 int n;
 char broj[MAX];

 scanf("%d", &n);	
 
 broj_u_niz_cifara(n,broj);                    
   
 printf("%s\n", broj);

 return 0;	       
}
