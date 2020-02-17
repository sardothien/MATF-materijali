#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
 if(argc!=3)
  greska();
 
 int n = atoi(argv[1]);
 if(n <= 0)
  greska();
 
 FILE *out = fopen("podniske.txt", "w");
 if(out == NULL)
  greska();
 
 int l = strlen(argv[2]);
 
 int i, j;
 for(i=0; i<=l-n; i++){
  for(j=0; j<n; j++){
   fprintf(out, "%c", argv[2][i+j]);
  }
  fprintf(out, " ");
 }
 
 fclose(out);
 
 return 0;
}
