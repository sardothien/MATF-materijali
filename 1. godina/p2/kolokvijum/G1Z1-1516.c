/* Kao argumenti komandne linije prosledjena su dva
cela broja k i l (2≤k≤l≤10000). Ispisati na standarni
izlaz sve proste brojeve p takve da vazi k≤p≤l. U
slucaju greske ispisati −1 na standardni izlaz. */

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
 
 if(k<2 || l<k || l>10000)
  greska();
  
 int i;
 for(i=k; i<=l; i++){
  int br=2, d;
  for(d=2; d<=i/2; d++){
   if(i%d==0){
    br++;
   }
  }
  if(br==2)
   printf("%d ", i);
  else
   continue;
 }
 
 printf("\n"); 
 
 return 0;
}
