/* Definisati strukturu STUDENT koja sadrzi:
•puno_ime (u polju se cuva ime i prezime studenta,
maksimalna duzina polja je 100 karaktera)
•ocene (sadrzi najvise 10 ocena studenta)
•broj_ocena (ukupan broj ocena za studenata)
•prosek (prosecna ocena)
U datoteci ciji se naziv zadaje kao argument komandne
linije se nalaze podaci o studentima (prvo broj studenata,
a zatim i informacije o svakom studentu). Za svakog studenta
unosi se ime i prezime razdvojeno razmakom, a potom ocene
koje se zavrsavaju sa 0. Napisati funkciju int najveci prosek
(STUDENT* niz, int n) koja pronalazi studenta sa najvecim
prosekom i vraca poziciju u nizu na kojoj se taj student
nalazi. Napisati funkciju void ispisi(const STUDENT* s)
koja ispisuje podatke o studentu u formatu: ime prezime,
prosek na dve decimale. Testirati obe funkcije pozivom u
glavnom programu, tako sto prvo treba naci studenta sa 
najvecim prosekom, a zatim ispisati informacije o tom
studentu. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
 char puno_ime[101];
 unsigned ocene[10];
 int br_ocena;
 float prosek;
}STUDENT;


int najveci_prosek(STUDENT *niz, int n){
 int i, pozicija=0;
 float p=niz[0].prosek;
 for(i=1; i<n; i++){
  if(niz[i].prosek > p){
   pozicija=i;
   p=niz[i].prosek;
  }
 }
 return pozicija;
}

void ispisi(const STUDENT *s){
 printf("%s %.2f\n", s->puno_ime, s->prosek);
}

int main(int argc, char *argv[]){
 if(argc!=2){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 FILE *in=fopen(argv[1], "r");
 if(in==NULL){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 int n;
 fscanf(in, "%d", &n);
 
 STUDENT *niz;
 niz=malloc(n*sizeof(STUDENT));
 if(niz==NULL){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 int i, ocena, j, suma;
 char tmp_prezime[101];
 for(i=0; i<n; i++){
  fscanf(in, "%s %s", niz[i].puno_ime, tmp_prezime);
  strcat(niz[i].puno_ime, " ");
  strcat(niz[i].puno_ime, tmp_prezime);  
  j=0; 
  suma=0;
  niz[i].br_ocena=0;
  while(1){
   fscanf(in, "%d", &ocena);
   if(ocena==0){
    break;
   }
   niz[i].ocene[j++]==ocena;
   suma=suma+ocena;
   niz[i].br_ocena++;
  }
  niz[i].prosek=(float)suma/niz[i].br_ocena;
 }
 
 int p=najveci_prosek(niz, n);
 ispisi(&niz[p]);
 
 free(niz);
 fclose(in); 
 
 return 0;
}
