#include <stdio.h>
#include <stdlib.h>
#include "velikibroj.h"

int main(){
 VB r=unos("1");
 VB i;
 VB sto=unos("100");
 VB jedan=unos("1");
 for(i=unos("1"); cmpvb(i,sto)<=0; i=zbir(i, jedan)){
  r=mnozi(r, i);
 }
 
 ispis(r);
 VB a=unos("543");
 VB b=unos("42");
 ispis(mnozi(a, b));

 return 0;
}
