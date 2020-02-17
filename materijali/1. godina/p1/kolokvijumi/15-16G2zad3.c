/* 2015/2016 - Kolokvijum GRUPA 2, zadatak 3 */
/* Drzavna lutrija dosla je na ideju o novoj igri na srecu. Ova igra na srecu igra se tako sto se izvuce jedan broj od 1000 do 9999. Nagrada koja se dobija ako ste pogodili izvucen broj je proizvod njegovih parnih cifara i samog broja. Vas zadatak je da na osnovu izucenog broja izracunate nagradu koja se dobija. Kao ulaz sigurno cete dobiti ispravan broj. Ako broj nema parnih cifara, nagrada je sam taj broj. Na standardni izlaz ispisite nagradu. */

#include <stdio.h>

int main(){
  int br, x1, x10, x100, x1000;
  scanf("%d", &br);

  x1 = br%10;
  x10 = (br/10)%10;
  x100 = (br/100)%10;
  x1000 = br/1000;
 
 if(x1%2==0){
   br= br*x1;
 }
 if(x10%2==0){
   br= br*x10;
 }
 if(x100%2==0){
   br= br*x100;
 }
 if(x1000%2==0){
   br= br*x1000;
 } 

 printf("%d\n", br);

 return 0;
}
