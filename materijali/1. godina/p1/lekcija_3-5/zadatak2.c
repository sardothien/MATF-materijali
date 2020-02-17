/* Definisati strukturu kojom se predstavlja razlomak.
Napisati funkcije koje izračunavaju zbir i proizvod dva
razlomka. Napisati program koji za uneti broj n i unetih n
razlomaka ispisuje njihov zbir i proizvod */ 

#include <stdio.h>

typedef struct razlomak{
 int im;
 int br;
}R;

int nzd(int a, int b){
 int pom;
 if(a<b){
  pom=a;
  a=b;
  b=pom;
 }
 while(b!=0){
  pom=a%b;
  a=b;
  b=pom;
 }
 return a;
}

R zbir(R a, R b){
 R c;
 int nzd_razlomka;
 
 c.br = a.br*b.im + b.br*a.im;
 c.im = a.im*b.im;
 
 nzd_razlomka=nzd(c.br, c.im);
 c.br=c.br/nzd_razlomka;
 c.im=c.im/nzd_razlomka; 
 return c;
}

R proizvod(R a, R b){
 R c;
 int nzd_razlomka;
 
 c.br = a.br*b.br;
 c.im = a.im*b.im;
 
 nzd_razlomka=nzd(c.br, c.im);
 c.br=c.br/nzd_razlomka;
 c.im=c.im/nzd_razlomka;
 return c;
}

int main(){
 int n, i; 
 R broj, s, pr;
 scanf("%d", &n);
 
 s.br=0;
 s.im=1;
 pr.br=1;
 pr.im=1;
 
 for(i=0; i<n; i++){
  scanf("%d", &broj.br);
  scanf("%d", &broj.im);
  s=zbir(s, broj);
  pr=proizvod(pr, broj);
 }
 
 printf("Suma: %d/%d\n", s.br, s.im);
 printf("Proizvod: %d/%d\n", pr.br, pr.im);
 
 return 0;
}
