/* NE RADI - Napisati program koji sa standardnog ulaza učitava 10
celih brojeva i razdvaja ih na parne i neparne tako što parne
brojeve upisuje na početak niza, a neparne brojeve na kraj
niza. Ispisati niz dobijen na ovaj način. Napomena: Nije
dozvoljeno koristiti pomoćne nizove. */

#include <stdio.h>

#define MAX 10

int main(){
 int i, bn=0, bp=0;
 int a[MAX];
 
 for(i=0; i<MAX; i++){
  scanf("%d", &a[i]);
 }
 
/* for(i=0; i<MAX; i++){
  if(a[i]%2==0){
   bp++;
  }
  else{
   bn++;
  }
 } */
 
 for(i=0; i<MAX; i++){
  if(a[i]%2==0){
   printf("%d ", a[i]);
  }
 }


 
 printf("\n");
 
 return 0;
}
