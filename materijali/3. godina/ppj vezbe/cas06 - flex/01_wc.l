/* Program koji broji linije i karaktere sa standardnog ulaza */

/* kako bi se pri EOF-u zaustavilo dalje citanje */
%option noyywrap 

%{  /* ukljucivanje zaglavlja i globalne promenljive */
    int num_lines = 0;
    int num_chars = 0;
%}

/* regularne definicije za regularne izraze */

/* glavni deo datoteke u kome se definisu regularni izrazi.
   ne smemo da imamo C-ovske komentare na pocetku linije, dok 
   u akcijama smemo.*/
%%

\n {
        num_lines++;
        num_chars++;
   }
.  {
        num_chars++;
   }

%%

int main(){
    yylex();
    
    printf("%d %d\n", num_chars, num_lines);
    
    return 0;
}
