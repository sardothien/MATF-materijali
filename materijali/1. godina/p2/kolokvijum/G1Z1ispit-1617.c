/* Napisati program koji kao argumente komandne linije
dobija dva pozitivna cela broja a i b i ispisuje sve
Armstrongove brojeve u intervalu [a,b], n-tocifreni
broj je Armstrongov ako je jednak zbitu n-tih stepena 
svojih cifara. U slucaju greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int armstr(int br){
 int i=1;
 int pom=br;
 while(br){
  br=br/10;
  if(br)
   i++;
 }
 
 int n=i;
 br=pom;
 int suma=0;
 
 while(br){
  suma+=pow(br%10, n);
  br/=10;
 }
 if(pom==suma)
  return 1;
 
 return 0;
}

int main(int argc, char *argv[]){
 if(argc!=3)
  greska();
 
 int a=atoi(argv[1]);
 int b=atoi(argv[2]);
 if(a<=0 || b<=0 || a>b)
  greska();
 
 int i;
 for(i=a; i<=b; i++){
  if(armstr(i))
   printf("%d ", i);  
 }
 
 printf("\n");
 
 return 0;
}
