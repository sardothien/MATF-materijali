#include<stdio.h>
#include "5.h"

int main(){
 cvor* stablo = NULL;
 ucitaj_stablo(&stablo, stdin);
 
 printf("Jednaki broju suseda: %d\n", broj_jednakih_zbiru_suseda(stablo, NULL));

 oslobodi(stablo);
 
 return 0;
}
