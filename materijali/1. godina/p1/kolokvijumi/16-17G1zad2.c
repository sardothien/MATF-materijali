/* 2016/2017 - Predlog kolokvijuma GRUPA 1, zadatak 2 */
/* Napisati program koji za uneti karakter (< ili >) i dva cela pozitivna trocifrena broja, poredi brojeve
prema datom karakteru i ako je uslov ispunjen zamenjuje najvecu cifru prvog broja sa najmanjom
cifrom drugog broja, a ako uslov nije ispunjen zamenjuje najmanju cifru prvog broja sa najvecom
cifrom drugog broja. Ukoliko ima viˇse najmanjih/najvecih cifara u okviru nekog broja, uzeti onu sa
najmanjom tezinom. Na standardni izlaz ispisati brojeve nakon zamene cifara. U slucaju greke, na
standardni izlaz ispisati -1. */

#include <stdio.h>

int main(){

  char c;
  int x, y, maxx, maxy, minx, miny, minx_p, miny_p, maxx_p, maxy_p, rez1, rez2;
  int x1, x10, x100, y1, y10, y100;
  
  scanf("%c%d%d", &c, &x, &y);
  
  if(c!='<' && c!='>'){
     printf("-1\n");
     return -1;
  }
  if((x<100 || x>999) || (y<100 || y>999)){
     printf("-1\n");
     return -1;
  }
  
  x1 = x%10;
  x10 = (x/10)%10;
  x100 = (x/100)%10;
  
  minx = x1;
  minx_p = 1;
  
  if(x10 < minx){
    minx = x10;
    minx_p = 10;
  }
  if(x100 < minx){
    minx = x100;
    minx_p = 100;
  }
  
  maxx = x1;
  maxx_p = 1;
  
  if(x10 > maxx){
    maxx = x10;
    maxx_p = 10;
  }
  if(x100>maxx){
    maxx = x100;
    maxx_p = 100;
  }

 
  y1 = y%10;
  y10 = (y/10)%10;
  y100 = (y/100)%10;
  
  miny = y1;
  miny_p = 1;
  
  if(y10 < miny){
    miny = y10;
    miny_p = 10;
  }
  if(y100 < miny){
    miny = y100;
    miny_p = 100;
  }
  
  maxy = y1;
  maxy_p = 1;
  
  if(y10 > maxy){
    maxy = y10;
    maxy_p = 10;
  }
  if(y100>maxy){
    maxy = y100;
    maxy_p = 100;
  }
  
  if(c=='<'){
    rez1 = x < y;
    if(rez1==1){
      printf("%d %d\n", x - maxx*maxx_p + miny*maxx_p , y - miny*miny_p + maxx*miny_p);
    }
    else 
      printf("%d %d\n", x - minx*minx_p + maxy*minx_p , y - maxy*maxy_p + minx*maxy_p);
  }
  
  if(c=='>'){
    rez2 = x > y;
    if(rez2==1){
      printf("%d %d\n", x - maxx*maxx_p + miny*maxx_p , y - miny*miny_p + maxx*miny_p);
    }
    else 
      printf("%d %d\n", x - minx*minx_p + maxy*minx_p , y - maxy*maxy_p + minx*maxy_p);
  }
  
  return 0;
}
