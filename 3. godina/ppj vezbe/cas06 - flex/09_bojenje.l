/* Zadatak prihvata program na C-u, i na osnovu njega pravi
   HTML stanicu ciji je sadrzaj samo C-kod, ali lepo obojen */
   
%option noyywrap
%option noinput
%option nounput

%{
    void print_char(char c);
    void print_string(char *s);
%}

DIGIT  [0-9]
ID  [a-zA-Z_][a-zA-Z0-9_]*
WHITE  [ \t\n]

%%

{DIGIT}+ { /* Ako prepozna celobrojnu konstantu, boji je u plavo */
             fprintf(yyout, "<span style=\"color:blue;\">%s</span>", yytext);
         }
{DIGIT}+\.{DIGIT}* { /* Ako prepozna realnu konstantu, boji je u plavo */
                        fprintf(yyout, "<span style=\"color:blue;\">%s</span>", yytext);
                   }
if|else|switch|case|while|for|do|break|continue|int|char|double|float|short|unsigned|long|void|struct|union|static|extern|typedef|return|register  {
      /* Kljucne reci se isticu masnim slovima */
                                    fprintf(yyout, "<B>%s</B>", yytext);        
                                }
^{WHITE}*#(.|\\\n)*\n {
      /* Predprocesorske direktive u zeleno */
                        fprintf(yyout, "<span style=\"color:green;\">");        
                        print_string(yytext);
                        fprintf(yyout, "</span>");        
                      }
{ID} { /* Identifikatore u crno */
         fprintf(yyout, "<span style=\"color:black;\">%s</span>", yytext);
     }
"/*"([^*]|"*"*[^/*])*"*"*"/"  {
                                /* Komentare u sivo */
                                fprintf(yyout, "<span style=\"color:grey;\">");
                                print_string(yytext);
                                fprintf(yyout, "</span>\n");
                              }
\"([^\\\"]|\\.)*\"  {
                        /* Stringove u crveno  */
                        fprintf(yyout, "<span style=\"color:red;\">");
                        print_string(yytext);
                        fprintf(yyout, "</span>");
                    }
'([^\\']|\\.)' { 
                    /* Karaktere u ljubicasto */
                    fprintf(yyout , "<span style=\"color:violet;\"> "); 
                    print_string(yytext); 
                    fprintf(yyout, "</span>");
               }    
.|\n  {
      /* Sve ostalo se prepisuje kakvo jeste na yyout */
      ECHO;
    }

%%

/* specijalne karaktere treba prilagoditi, radi 
   ispravnog prikaza u okviru HTML datoteke */
void print_char(char c){
  if (c == '<')
    fprintf(yyout, "&lt;");
  else if (c == '>')
    fprintf(yyout,"&gt;");
  else if (c == '&')
    fprintf(yyout, "&amp;");
  else
    fprintf(yyout, "%c", c);
}

void print_string(char *s){
  int i;
  for(i = 0; s[i] != '\0'; i++)
    print_char(s[i]);
}

int main(int argc, char* argv[]){

  if (argc > 1) {
    if ((yyin = fopen(argv[1],"r")) == NULL) {
      fprintf(stderr, "Neuspesno otvaranje datoteke %s.\n", argv[1]);
      exit(EXIT_FAILURE);
    }
  }
  else
    yyin = stdin;
    
  if (argc > 2) {
    if ((yyout = fopen(argv[2],"w")) == NULL) {
      fprintf(stderr, "Neuspesno otvaranje datoteke %s.\n", argv[2]);
      exit(EXIT_FAILURE);
    }
  }
  else
    yyout = stdout;

  /* Stampa se zaglavlje html dokumenta */
  fprintf(yyout, "<html>\n");
  if (argc > 1)
    fprintf(yyout, "<head><title>%s</title></head>\n", argv[1]);
  fprintf(yyout, "<body>\n<pre>\n");

  /* Boji se tekst */
  yylex();

  /* Zavrsava se html dokument */
  fprintf(yyout,"</pre>\n</body>\n</html>\n");

  fclose(yyin);
  fclose(yyout);

  return 0;
}
