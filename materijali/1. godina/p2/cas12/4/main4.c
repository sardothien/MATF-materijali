#include <stdio.h>
#include "4.h"

int main(){
 cvor* stablo = NULL;
 ucitaj_stablo(&stablo, stdin);
 ispisi_po_nivoima(stablo);
 
 oslobodi(stablo);
 return 0;
}
