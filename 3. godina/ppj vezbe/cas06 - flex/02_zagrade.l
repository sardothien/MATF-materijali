/* Program proverava da li su zagrade ispravno uparene */

%option noyywrap

%{
    int num_open = 0;
%}

%%
 
"{" {   /* ECHO je isto kao i printf */
        ECHO; 
        num_open++;
    }
"}" {
        ECHO;
        if(num_open == 0){
            fprintf(stderr, "Zagrade nisu uparene!\n");
            /* return se odnosi na yylex() */
            return -1;
        }
        else
            num_open--;
    }
. {ECHO;}
\n {ECHO;}

%%

int main(){
    
    if(yylex() == -1)
        exit(EXIT_FAILURE);
        
    if(num_open == 0)
        printf("Zagrade su uparene\n");
    else
        printf("Zagrade nisu lepo uparene\n");
    
    return 0;
}
