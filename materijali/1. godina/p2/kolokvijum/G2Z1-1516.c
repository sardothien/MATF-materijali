/* Kao argumenti komandne linije prosledjena su dva
cela broja k i l (0 ≤ k ≤ l ≤ 10000). Ispisati na
standardni izlaz sumu cifara svih brojeva x, takvih
da je k ≤ x ≤ l. U slucaju greske ispisati −1 na
standardni izlaz. */

#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
 if(argc!=3)
  greska();
 
 int k, l;
 k=atoi(argv[1]);
 l=atoi(argv[2]);
 if(k<0 || k>l || l>10000)
  greska();
 
 int i, j;
 int suma=0;
 for(i=k; i<=l; i++){
   suma+=i%10+(i/10)%10;
 }
 
 printf("%d\n", suma);
 
 
 
 return 0;
}
