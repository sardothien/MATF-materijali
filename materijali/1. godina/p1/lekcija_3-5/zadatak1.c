/* Definisati strukturu kojom se predstavlja kompleksan broj.
Napisati funkcije koje izračunavaju zbir, razliku, proizvod i količnik
dva kompleksna broja. Napisati program koji za učitana dva kompleksna
broja ispisuje vrednost zbira, razlike, proizvoda i količnika. */

#include <stdio.h>

typedef struct Complex{
  float re;
  float im;
} KOMP;  


KOMP saberi(KOMP *a, KOMP *b){
  KOMP c;
  c.re = a->re + b->re;
  c.im = a->im + b->im;
  return c;
}

KOMP oduzmi(KOMP *a, KOMP *b) {
  KOMP c;
  c.re = a->re - b->re;
  c.im = a->im - b->im;
  return c;
}

KOMP pomnozi(KOMP *a, KOMP *b) {
  KOMP c;
  c.re = a->re * b->re - a->im * b->im;
  c.im = b->re * a->im + a->re * b->im;
  return c;
}

KOMP podeli(KOMP *a, KOMP *b) {
  KOMP c;
  c.re = (a->re * b->re + a->im * b->im) / (b->re*b->re + b->im*b->im);
  c.im = (b->re * a->im - a->re * b->im) / (b->re*b->re + b->im*b->im);
  return c;
}

int main() {
  KOMP a, b;
  KOMP c;
  
  scanf("%f%f", &a.re, &a.im);
  scanf("%f%f", &b.re, &b.im);
  
  c = saberi(&a, &b);
  printf("Zbir: %.2f%c%.2f*i\n", c.re, c.im > 0 ? '+' : ' ', c.im);  
  c = oduzmi(&a, &b);
  printf("Razlika: %.2f%c%.2f*i\n", c.re, c.im > 0 ? '+' : ' ', c.im);  
  c = pomnozi(&a, &b);
  printf("Proizvod: %.2f%c%.2f*i\n", c.re, c.im > 0 ? '+' : ' ', c.im);
  
  if(b.re != 0 || b.im != 0) {
    c = podeli(&a, &b);
    printf("Kolicnik: %.2f%c%.2f*i\n", c.re, c.im > 0 ? '+' : ' ', c.im);
  }
  else
    printf("Kolicnik ne postoji.\n"); 			

  return 0;
}
