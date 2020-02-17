/* Program koji cisti Pascal datoteku od komentara */
%option noyywrap
%option nounput
%option noinput

%%

"{"[^}]*"}" { /* komentari u pascal-u: { }
                 stavljamo praznu akciju*/
            }
"(*"([^*]|"*"+[^*)])*\*+")" { /* komentari mogu biti i u
                                 obliku (* ... *) */
                            }
%%

int main(){

    yylex();
    
    return 0;
}
