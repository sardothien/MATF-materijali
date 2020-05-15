/* Napisati program koji učitava karaktere sve do kraja ulaza, a potom ispisuje broj velikih slova, broj malih slova, broj cifara, broj belina i zbir unetih cifara. */

#include <stdio.h>
#include <ctype.h>

int main(){

 char c;
 int bv=0, bm=0, sc=0, bc=0, bb=0;

 while((c=getchar()) != EOF){
  if(isupper(c)){
   bv++;
  }
  else if(islower(c)){
   bm++;
  }
  else if(isdigit(c)){
   bc++;
   sc=sc+c-'0';
  }
  else if(c=='\n' || c=='\t' || c==' '){
   bb++;
  }
 }
 
 
 printf("%d %d %d %d %d\n", bv, bm, bc, bb, sc);
 return 0;
}
