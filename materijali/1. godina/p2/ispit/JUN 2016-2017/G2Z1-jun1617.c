#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int savrsen(int br){
 int suma = 0;
 int i;
 for(i=1; i<br; i++){
  if(br % i == 0)
   suma += i;
  else
   continue;
 }
 if(suma == br)
  return br;
 return 0;
}

int main(int argc, char *argv[]){
 if(argc != 3)
  greska();
 
 int a = atoi(argv[1]);
 int b = atoi(argv[2]);
 if(a<0 || b<0 || a>b)
  greska();
   
 int i;
 for(i=a; i<b; i++)
  if(savrsen(i))
   printf("%d ", savrsen(i));
 
 printf("\n");
 
 return 0;
}
