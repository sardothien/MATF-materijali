/* Napisati program koji za uneto vreme (broj sati iz intervala [0, 24) i broj minuta iz intervala [0, 60)) ispisuje koliko je sati i minuta ostalo do ponoći. */

#include <stdio.h>

int main(){

  int s,m, sp, mp;
  
  printf("Uneti vreme: ");
  scanf("%d%d", &s, &m);
  
  sp=23-s;
  mp=60-m;
  
  if(mp==60){
   mp=0;
   sp++;
  }
  
  if(s==24){
    printf("Neispravan unos!\n");
    return -1;
  }
  
  printf("Do ponoci je ostalo %d sati i %d minuta.\n", sp, mp);  
    
  return 0;
}
