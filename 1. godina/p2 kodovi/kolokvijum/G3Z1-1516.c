/* Preko argumenata komandne linije prosledjen je niz
celih brojeva. Neka su a, b, c redom minimum,
maksimum i prosecna vrednost niza. Ispisati brojeve
niza strogo vece od (a + b + c)/3. U slucaju
greske ispisati −1 na standardni izlaz. */

#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
 if(argc==1)
  greska();
  
 int i;
 int x, max=0, suma=0;
 int min=atoi(argv[1]);
 for(i=1; i<argc; i++){
  x=atoi(argv[i]);
  if(x>max)
   max=x;
  if(x<min)
   min=x;
  suma+=x;
 }
 
 float prosek, f;
 prosek=(float)suma/(argc-1);
 f=(min+max+prosek)/3;
 
 for(i=1; i<argc; i++){
  if(atoi(argv[i]) > f){
   printf("%d ", atoi(argv[i]));
  }
 }
 printf("\n");
 
 return 0;
}
