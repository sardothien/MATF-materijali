/* Napisati program koji učitane karaktere (najviše njih 100,
učitavaju se sve do pojave karaktera *) ispisuje u redosledu
suprotnom od redosleda čitanja. */

#include <stdio.h>
#include <ctype.h>
#define MAX 100

int main(){
 int i, br;
 char a[MAX], c;
 
 for(i=0; i<MAX; i++){
  scanf("%c", &c);
  getchar();
  if(c=='*'){
   break;
  }
  a[i]=c;
 }
 
 br=i-1;
 for(i=br; i>=0; i--){
  printf("%c ", a[i]);
 }
 printf("\n");
 return 0;
}
