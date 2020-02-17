#include <stdio.h>

int deljiv_16(int);

int main(){
 int x;
 scanf("%d", &x);
 
 if(deljiv_16(x))
  printf("Jeste\n");
 else
  printf("Nije\n");
   
 return 0;
}
