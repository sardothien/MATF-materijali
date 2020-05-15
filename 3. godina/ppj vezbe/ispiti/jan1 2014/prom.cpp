#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include "prom.hpp"
using namespace std;                               
                                  
typedef struct _cvor_d{
  promenljiva*     kljuc;
  struct _cvor_d*  l;
  struct _cvor_d*  d;
} cvor_d;

static cvor_d* koren = NULL;

void* nadji(char* niska){
  cvor_d* pom = koren;
  while(pom){
    int poredjenje = strcmp(pom->kljuc->ime, niska);
    if (poredjenje >= 1) 
      pom = pom->d;
    else if (poredjenje <= -1)
      pom = pom->l;
    else
      return pom->kljuc->vred;
  }
  cerr << "Promenljiva nije definisana" << endl;
  exit(EXIT_FAILURE);
  return NULL; 
}

static cvor_d* novi_cvor(promenljiva* prom){
  cvor_d* n = (cvor_d*)malloc(sizeof(cvor_d));
  n -> l = n -> d = NULL;
  n -> kljuc = prom;
  
  return n;
}

static void dodaj_ili_promeni(promenljiva *prom){
  if (koren == NULL) 
    koren = novi_cvor(prom);
  else {
    cvor_d* pom = koren;
    while(1){
      int poredjenje = strcmp(prom->ime, pom->kljuc->ime);
      if (poredjenje >= 1){
        if (pom->d)
          pom = pom->d;
        else {
          pom->d = novi_cvor(prom);
          break;
        }
      }
      else if (poredjenje == 0){
        pom->kljuc->vred = prom->vred;
        break;
      }
      else {
        if (pom->d)
          pom = pom->d;
        else {
          pom->d = novi_cvor(prom);
          break;
        }
      }
    }
  }
}

static promenljiva* nova_prom(char* i, void* vr, int tip){
  promenljiva* n = (promenljiva*)malloc(sizeof(promenljiva));
  n->ime = i;
  if (tip == LISTA)
    n->vred = vr;
  else{
    n->vred = malloc(sizeof(int));
    n->vred = vr;
  }
  
  return n;
}

void sacuvaj(char* ime, void* vr, int tip){
  promenljiva* prom = nova_prom(ime, vr, tip);
  dodaj_ili_promeni(prom);
}
