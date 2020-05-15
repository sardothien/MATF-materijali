/* Napisati funkciju float zbir_reciprocnih(int n) koja
za dato n vraća zbir recipročnih vrednosti brojeva od 1 do n. Napisati program
koji učitava ceo broj i ispisuje rezultat rada funkcje zaokružen na dve decimale. */

#include <stdio.h>

float zbir_reciprocnih(int n){
 
  float s=0;
  int i;
  
  for(i=1; i<=n; i++){
   s+=1.0/i;
  }
 
 return s;
}

int main(){
 
 int n;
 scanf("%d", &n);
  
 printf("%.2f\n", zbir_reciprocnih(n));

 return 0;
}
