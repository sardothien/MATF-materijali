/* Napisati rekurzivnu funkciju int izmeni(int n)
koja svaku parnu cifru c u broju n zamenjuje sa
c/2. Napisati glavni program koji kao argument
komandne linije dobija broj n, a na standardni izlaz
ispisuje novi broj. U slucaju greske na standardni
izlaz za greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int izmeni(int n){
 if(n/10==0)
  if(n%2==0)
   return n/2;
  else 
   return n;
 
 if((n%10)%2==0)
  return izmeni(n/10)*10+(n%10)/2;
 else
  return izmeni(n/10)*10+(n%10);
}

int main(int argc, char *argv[]){
 if(argc!=2)
  greska();
 
 int n=atoi(argv[1]);
 int k=abs(n);
 
 printf("%d\n", n>0 ? izmeni(n):-1*izmeni(k));
 
 return 0;
}
