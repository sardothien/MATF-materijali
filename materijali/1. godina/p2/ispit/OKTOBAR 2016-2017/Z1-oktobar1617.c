#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
 if(argc == 1)
  greska();
 
 int jednaki = 1;
 int rastuce = 1;
 int opadajuce = 1;
 int suma = atoi(argv[1]);
 int proizvod = atoi(argv[1]);
 
 int i;
 for(i=2; i<argc; i++){
  if(atoi(argv[i]) != atoi(argv[i-1]))
   jednaki = 0;
  if(atoi(argv[i]) > atoi(argv[i-1]))
   opadajuce = 0;
  if(atoi(argv[i]) < atoi(argv[i-1]))
   rastuce = 0;
  if(atoi(argv[i]) == atoi(argv[i-1])){
   rastuce = 0;
   opadajuce = 0;
  }
  suma += atoi(argv[i]);
  proizvod *= atoi(argv[i]);
 }
 
 if(rastuce)
  printf("%d\n", suma);
 else if(opadajuce)
  printf("%d\n", proizvod);
 else if(jednaki)
  printf("0\n");
 else
  printf("-\n"); 
 
 return 0;
}
