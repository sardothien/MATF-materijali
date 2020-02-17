#include <stdio.h>

int savrsen(int);

int main(){
 int n;
 scanf("%d", &n);
 
 if(savrsen(n))
  printf("Jeste\n");
 else
  printf("Nije\n");
 
 return 0;
}
