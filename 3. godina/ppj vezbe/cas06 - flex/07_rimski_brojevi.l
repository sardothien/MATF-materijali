/* Program prepisuje datoteku na ekran, a sve sto moze
   da prepozna kao zapis rimskog broja prepisuje na ekran. */
   
%option noyywrap
%option nounput
%option noinput

%{
    int value = 0;
    char number[1000];
%}

thousand M+
hundred C+|CD|DC*|CM
ten X+|XL|LX*|XC
one I+|IV|VI*|IX

%%
{thousand} {
                value += 1000*yyleng;
                strcat(number, yytext);
           }
           
{hundred} {
            if(strcmp(yytext, "CM") == 0){
                value += 900;
            }
            else if(strcmp(yytext, "CD") == 0){
                value += 400;
            }
            else{
                if(yytext[0] == 'D'){
                    value += 500;
                    if(yyleng <= 4){ // DCCC
                        value += 100*(yyleng-1);
                    }
                    else{
                        fprintf(stderr, "\nNeispravan rimski broj %s\n",yytext);
                        exit(EXIT_FAILURE);
                    }
                }
                else{
                    if(yyleng <= 3){
                        value += 100*yyleng;
                    }
                    else{
                        fprintf(stderr, "\nNeispravan rimski broj %s\n",yytext);
                        exit(EXIT_FAILURE);
                    }
                }
                strcat(number, yytext);
            }
          }
          
{ten} {
            if(strcmp(yytext, "XC") == 0)
                value += 90;
            else if(strcmp(yytext, "XL") == 0)
                value += 40;
            else{
                if(yytext[0] == 'L'){
                    value += 50;
                    if(yyleng <= 4){
                        value += 10*(yyleng-1);
                    }
                    else{ // LXXXX
                        fprintf(stderr, "\nNeispravan rimski broj %s\n",yytext);
                        exit(EXIT_FAILURE);
                    }
                }
                else{
                    if(yyleng <= 3){
                        value += 10*yyleng;
                    }
                    else{
                        fprintf(stderr, "\nNeispravan rimski broj %s\n",yytext);
                        exit(EXIT_FAILURE);
                    }
                }
                strcat(number, yytext);
            }
      }
      
{one} {
            if(strcmp(yytext, "IX") == 0)
                value += 9;
            else if(strcmp(yytext, "IV") == 0)
                value += 4;
            else if(yytext[0] == 'V'){
                value += 5;
                if(yyleng <= 4)
                    value += (yyleng-1);
                else{
                    fprintf(stderr, "\nNeispravan rimski broj %s\n",yytext);
                    exit(EXIT_FAILURE);
                }
            }
            else{
                if(yyleng <= 3)
                    value += yyleng;
                else{
                    fprintf(stderr, "\nNeispravan rimski broj %s\n",yytext);
                    exit(EXIT_FAILURE);
                }
            }
            strcat(number, yytext);
      }
      
[\n\t.!?;"':] { 
                if(value > 0){
                    printf("%d", value);
                    value = 0;		
                    number[0]='\0';
                }					
                ECHO;
              }
              
. {
    if(value > 0){
        value = 0;
        printf("%s", number);
        number[0]='\0';
    }
    ECHO; 
  }
%%

int main(){
    yylex();
    
    return 0;
}
