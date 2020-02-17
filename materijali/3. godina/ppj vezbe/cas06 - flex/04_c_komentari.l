/* Program koji cisti C program od komentara i broji redove fajla */

%option noyywrap

/* definisemo ekskluzivno stanje comment */
%x comment

%{
    int num_lines = 0;
%}

%%

"/*" { /* kada se naidje na /*, prelazimo u stanje comment */
        BEGIN(comment);
     }
<comment>[^*\n]* {
                    /* gutamo sve osim \n i *, akcija je prazna */
                 }
<comment>"*"* {
                /* u komentarima gutamo * iza kojih nije / i \n */
              }
<comment>\n {
                num_lines++;
            }
<comment>\*+"/" {   /* kraj komentara */
                    BEGIN(INITIAL);
                }
\n {  /* novi red van komentara */
        ++num_lines;
        ECHO;
   }
. {
    /* ostale podatke prepisujemo na izlaz
       ovaj deo moze i da se izostavi */
  }

%%

int main(){
    
    yylex();
    
    printf("%d\n", num_lines);
    
    return 0;

}
