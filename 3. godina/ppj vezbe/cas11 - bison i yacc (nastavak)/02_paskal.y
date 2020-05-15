/* Pseudo Paskal */

%{
    #include<stdio.h>
    #include<stdlib.h>
    #define YYDEBUG 1
    
    extern int yylex();
    void yyerror(char* s);
    int promenljive[26];
%}

%union {
    char niska[50];
    char ime;
    int vr;
}

%left '+'
%left MOD
%left '*'

%token POCETAK ISPISI KRAJ DOD
%token <niska> NISKA
%token <vr> BROJ
%token <ime> ID
%type <vr> e

%%
program : blok '.' {}
        ;
blok : POCETAK niznaredbi KRAJ {}
       ;
niznaredbi : niznaredbi ';' naredba {}
             | naredba {}
             ;
naredba : ISPISI '(' NISKA ')' { printf("%s\n", $3); }
        | ISPISI '(' e ')'    { printf("%d\n", $3); }
        | ID DOD e            { promenljive[$1-'a'] = $3; }
        ;
e : e '+' e      { $$ = $1 + $3; }
  | e '*' e      { $$ = $1 * $3; }
  | e MOD e      { $$ = $1 % $3; }
  | '(' e ')'    { $$ = $2; }
  | BROJ         { $$ = $1; }
  | ID           { $$ = promenljive[$1-'a']; }
  ;
%%

void yyerror(char* s){
    fprintf(stderr, "%s\n", s);
    exit(EXIT_FAILURE);
}

int main(){
    
    yydebug = 0;
    yyparse();
    
    return 0;
}
