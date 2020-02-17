/* Program predstavlja primer on-demand analizatora. Pronalazi
   celobrojne i razlomljene konstante u tekstu i vraca razlicite 
   tokene. Ilustracija citanja i pisanja iz datoteke. */

%option noyywrap

%{
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

int main(int argc, char** argv){
    
    if(argc > 1 && (yyin = fopen(argv[1], "r")) != NULL);
    else
        yyin = stdin;
    
    if(argc > 2 && (yyout = fopen(argv[2], "w")) != NULL);
    else
        yyout = stdout;
        
    int token;
    
    while(token = yylex()){
        switch(token){
            case I_CONST: fprintf(yyout, "Pronadjena je celobrojna konstanta: %s\n", yytext);
                          break;
            case F_CONST: fprintf(yyout, "Pronadjena je realna konstanta: %s\n", yytext);
                          break;
        }
    }
    
    return 0;
}
