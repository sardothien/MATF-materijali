/* Napisati funkciju koja na osnovu neoznacenog broja x
formira nisku s koji sadrzi heksadekadni zapis broja x,
koristeci algoritam za brzo prevodjenje binarnog u
heksadekadni zapis (svake 4 binarne cifre se zamenjuju jednom
odgovarajucom heksadekadnom cifrom). */

#include <stdio.h>

int main(){
 int x, s;
 unsigned int mask = 1 << (sizeof(int)*8-1);
 scanf("%d", &x);
 
 while(mask!=0){
  s=0;
  if(x&mask)
    s=1;
  mask = mask >> 1; 
  s=s*2;
  if(x&mask)
    s=s+1;
  mask = mask >> 1; 
  s=s*2;
  if(x&mask)
    s=s+1;
  mask = mask >> 1; 
  s=s*2;
  if(x&mask)
    s=s+1;
  mask = mask >> 1;
  if(s<10)
    printf("%d", s);
  else 
    printf("%c", s+'A'-10);
 }
 
 printf("\n");
 
 return 0;
}
