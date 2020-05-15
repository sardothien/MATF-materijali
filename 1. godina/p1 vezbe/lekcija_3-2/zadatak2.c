/* Napisati funkciju koja za boju datu u rgb formatu računa
cmy format po formulama:
c = 1 − (r/255)
m = 1 − (g/255)
y = 1 − (b/255)
Napisati program koji učitava tri cela broja broja (rgb format)
i ispisuje rezultat poziva funkcije (cmy format). Napomena:
Vrednosti boja u rgb formatu su u opsegu [0, 255]. */

#include <stdio.h>
#include <math.h>

void cmy_format(float* a, float* b, float* c){
 *a=1-(*a)/255;
 *b=1-(*b)/255;
 *c=1-(*c)/255;
}

int rgb_korektno(float a){
 if(a<0 || a>255)
   return 0;
   
 return 1;
}

int main(){
 float a, b, c;
 
 scanf("%f%f%f", &a, &b, &c);
 
 if(rgb_korektno(a) && rgb_korektno(b) && rgb_korektno(c))
   cmy_format(&a, &b, &c);
 else{
  printf("-1\n");
  return -1;
 }

 printf("c=%.2f, m=%.2f, y=%.2f\n", a, b, c);
 
 return 0;
}
