// Ispis Armstrongovih brojeva

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int duzina(int br){
 int i=0;
 while(br){
  br /= 10;
  i++;
 }
 return i;
}

int main(int argc, char *argv[]){
 if(argc!=3)
  greska();
 
 int a = atoi(argv[1]);
 int b = atoi(argv[2]);
 if(a<0 || b<0 || a>b)
  greska();
 
 int i;
 for(i=a; i<=b; i++){
  int d = duzina(i);
  int suma = 0;
  int br = i;
  while(br){
   int p = br%10;
   suma += pow(p, d);
   br /= 10;
  }
  if(suma == i)
   printf("%d ", i);
 }
 
 printf("\n");
 
 return 0;
}
