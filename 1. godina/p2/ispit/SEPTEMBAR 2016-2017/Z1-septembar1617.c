#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int niveneov(int x){
 int suma = 0;
 int c = x;
 while(c){
  suma += c%10;  
  c /= 10; 
 }
 if(x % suma == 0)
  return 1;
 else
  return 0;
}

int main(int argc, char *argv[]){
 if(argc!=2)
  greska();
  
 int n = atoi(argv[1]);
 if(n <= 0)
  greska();
 
 int x;
 int br = 0;
 double suma = 0;
 while(n){
  scanf("%d", &x);
  if(x <= 0)
   greska();
  if(niveneov(x)){
   suma += x;
   br++;
  }  
  n--;
 }
 
 if(br == 0)
  printf("0.00\n");
 else
  printf("%.2f\n", suma/br);
 
 return 0;
}
