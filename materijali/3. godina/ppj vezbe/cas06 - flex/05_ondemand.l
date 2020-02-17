/* Program predstavlja primer on-demand analizatora. Pronalazi
   celobrojne i razlomljene konstante u tekstu i vraca razlicite 
   tokene. */
   
%option noyywrap

%{
    /* vrednost 0 je rezervisana za EOF */
    #define F_CONST 1
    #define I_CONST 2    
%}

DIGIT [0-9]

%%

[+\-]?{DIGIT}+ {  /* celobrojna konstanta */
                    return I_CONST;
               }
[+\-]?{DIGIT}+\.{DIGIT}*([Ee][+\-]?{DIGIT}+)? { /* realna konstanta */
                                                   return F_CONST;
                                              }
. {}
\n {}

%%

int main(){
    int token;
    
    while((token = yylex())){
        switch(token){
            case I_CONST: printf("Pronadjena je celobrojna konstanta: %s\n", yytext);
                          break;
            case F_CONST: printf("Pronadjena je realna konstanta: %s\n", yytext);
                          break;
        }
    }
    
    return 0;
}
