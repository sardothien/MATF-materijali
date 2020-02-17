#include<iostream>
#include<cstdlib>
#include"razlomak.hpp"

static int izracunaj_nzd(int a, int b){
  int pom;
  while(b){
    pom = b;
    b = a % b;
    a = pom;
  }
  
  return a;
}

static Razlomak* skrati(Razlomak* r){
  int nzd = izracunaj_nzd(r->br, r->im);
  r->im /= nzd;
  r->br /= nzd;
  
  return r;
}

int jednaki(Razlomak* r1, Razlomak* r2){
  skrati(r1);
  skrati(r2);
  
  return r1->im == r2->im && r1->br == r2->br;
}

Razlomak* novi_razl(int br, int im){
  if(im == 0) {
    cerr << "Greska!" << endl;
    return NULL;
  }
  Razlomak* r = malloc(sizeof(Razlomak));
  if(r == NULL){
        cerr << "Greksa!" << endl;
        exit(EXIT_FAILURE);
  }
  
  r->im = im;
  r->br = br;
  
  return skrati(r);
}

Razlomak* saberi(Razlomak* r1, Razlomak* r2){
  if(r1 == NULL)
    return r2;
  if(r2 == NULL)
    return r1;
  
  return skrati(novi_razl(r1->br*r2->im + r2->br*r1->im,
                          r1->im*r2->im));
}

Razlomak* oduzmi(Razlomak* r1, Razlomak* r2){
  if(r1 == NULL)
    return r2;
  if(r2 == NULL)
    return r1;
  
  return skrati(novi_razl(r1->br*r2->im - r2->br*r1->im,
                          r1->im*r2->im));
}

Razlomak* pomnozi(Razlomak* r1, Razlomak* r2){
  if(r1 == NULL)
    return r2;
  if(r2 == NULL)
    return r1;
  
  return skrati(novi_razl(r1->br * r2->br,
                          r1->im * r2->im));
}

Razlomak* podeli(Razlomak* r1, Razlomak* r2){
  if(r1 == NULL)
    return r2;
  if(r2 == NULL)
    return r1;
  
  return skrati(novi_razl(r1->br * r2->br,
                          r1->im / r2->im));
}

void ispisi(Razlomak* r){
  if(r == NULL)
    cerr << "Neispravna vrednost izraza." << endl;
  else
    cout << "[" << r->br << ", " << r->im << "]" << endl;
}
