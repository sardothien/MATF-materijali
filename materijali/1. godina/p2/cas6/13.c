/* U datoteci koja se zadaje kao prvi argument
komandne linije, nalaze se koordinate tačaka. U
zavisnosti od prisustva opcija komandne linije
(-x ili -y), pronaći onu koja je najbliža x, ili y
osi, ili koordinatnom početku, ako nije prisutna
nijedna opcija. Pretpostaviti da je broj tačaka u
datoteci veći od 0 i ne veći od 1024. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1024

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

typedef struct {
 float x;
 float y;
}TACKA;

float rastojanje(TACKA a){
 return sqrt(a.x*a.x + a.y*a.y);
}

TACKA najbliza_koordin_pocetku(TACKA t[], int n){
 TACKA najbliza;
 int i;
 najbliza=t[0];
 for(i=1; i<n; i++){
  if(rastojanje(t[i])<rastojanje(najbliza))
   najbliza=t[i];
 }
 return najbliza;
}

TACKA najbliza_xosi(TACKA t[], int n){
 int i;
 TACKA najbliza=t[0];
 for(i=1; i<n; i++){
  if(fabs(t[i].x)<fabs(najbliza.x))
   najbliza=t[i];
 }
 return najbliza;
}

TACKA najbliza_yosi(TACKA t[], int n){
 TACKA najbliza=t[0];
 int i;
 for(i=1; i<n; i++){
  if(fabs(t[i].y)<fabs(najbliza.y))
   najbliza = t[i];
 }
return najbliza;
}

int main(int argc, char *argv[]){
 if(argc!=3 && argc!=2)
  greska();
 
 FILE *in=fopen(argv[1], "r");
 if(in==NULL)
  greska();
 
 int i=0;
 TACKA tacke[MAX];
 while(fscanf(in, "%f%f", &tacke[i].x, &tacke[i].y)==2){
  i++;
 }
 
 fclose(in);
 
 int n=i;
 TACKA najbliza;
 if(argc==2) 
  najbliza=najbliza_koordin_pocetku(tacke, n);
 else if(strcmp(argv[2], "-x")==0)
  najbliza=najbliza_xosi(tacke, n);
 else if(strcmp(argv[2], "-y")==0)
  najbliza=najbliza_yosi(tacke, n); 
 else
  greska();
 
 printf("%g %g\n", najbliza.x, najbliza.y);
 
 return 0;
}
