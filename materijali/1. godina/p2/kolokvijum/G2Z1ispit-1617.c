/* Napisati program koji kao argumente komandne
linije dobija dva pozitivna cela broja a i b i
stampa sve savrsene brojeve izmedju njih. */

#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int savrsen(int br){
 int suma=0;
 int i;
 for(i=1; i<=br/2; i++){
  if(br%i==0)
   suma+=i;
 }
 return br==suma;
}

int main(int argc, char *argv[]){
 if(argc!=3)
  greska();
 
 int a=atoi(argv[1]);
 int b=atoi(argv[2]);
 if(a>b || a<0 || b<0)
  greska();
 
 int i;
 for(i=a; i<=b; i++){
  if(savrsen(i))
   printf("%d ", i);
 }
 
 printf("\n");
 
 return 0;
}
