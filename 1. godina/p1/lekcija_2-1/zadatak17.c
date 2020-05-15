/* Napisati program koji ispituje da li se tačke A(x 1 , y 1 ) i B(x 2 , y 2 ) nalaze u istom kvadrantu i ispisuje odgovor DA ili NE. */

#include <stdio.h>

int main(){
 
  float x1, y1, x2, y2;
  
  printf("Unesite koordinate temena A: ");
  scanf("%f%f", &x1, &y1);
  
  printf("Unesite koordinate temena B: ");
  scanf("%f%f", &x2, &y2);
 
  
  /* Isti kvadrant */
  if(x1>0 && y1>0 && x2>0 && y2>0){
    printf("DA.\n");
  }
  if(x1>0 && y1<0 && x2>0 && y2<0){
    printf("DA.\n");
  }
  if(x1<0 && y1>0 && x2<0 && y2>0){
    printf("DA.\n");
  }
  if(x1<0 && y1<0 && x2<0 && y2<0){
    printf("DA.\n");
  }
  
  /* Razliciti kvadrant */
  if(x1>0 && y1>0 && x2<0 && y2>0){
    printf("NE.\n");
  }
  if(x1>0 && y1>0 && x2>0 && y2<0){
    printf("NE.\n");
  }
  if(x1>0 && y1>0 && x2<0 && y2<0){
    printf("NE.\n");
  }
  if(x1<0 && y1>0 && x2>0 && y2>0){
    printf("NE.\n");
  }
  if(x1>0 && y1<0 && x2>0 && y2>0){
    printf("NE.\n");
  }
  if(x1<0 && y1<0 && x2>0 && y2>0){
    printf("NE.\n");
  } 

  return 0;
}
