%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    
    #define YYDEBUG 1
    #define KORAK 3
    
    extern int yylex();
    void yyerror(char* s){
        fprintf(stderr, "%s\n", s);
        exit(EXIT_FAILURE);
    }
    
    typedef struct {
        char* naslov;
        char* reziser;
        int godina;
        double ocena;
    } film;
    
    film* spisak = NULL;
    int br_filmova = 0;
    int alocirano = 0;
    
    int poredjenjeGodina(const void *a, const void *b){
        film prvi = *(film*)a;
        film drugi = *(film*)b;
        return prvi.godina - drugi.godina;
    }
    
    int poredjenjeNaslova(const void* a, const void *b){
        film prvi = *(film*)a;
        film drugi = *(film*)b;
        return strcmp(prvi.naslov, drugi.naslov);
    }
    
    int poredjenjeOcena(const void *a, const void *b){
        film prvi = *(film*)a;
        film drugi = *(film*)b;
        return -prvi.ocena + drugi.ocena;
    }
%}

%union {
    int godina;
    double ocena;
    char buffer[1000];
}

%token XMLO XMLZ MOVIEO MOVIEZ TITLEO TITLEZ YEARO YEARZ DIRECTORO DIRECTORZ RATINGO RATINGZ
%token<buffer> NASLOV IME
%token<ocena> OCENA
%token<godina> GODINA

%%
filmovi : XMLO lista XMLZ
          ;
          
lista : lista film
      | film    {}
      ;
      
film : MOVIEO naslov premijera podaci MOVIEZ { br_filmova++; }
       ;
       
naslov : TITLEO NASLOV TITLEZ   {
                                    if(br_filmova == alocirano){
                                        alocirano += KORAK;
                                        spisak = (film*) realloc(spisak ,alocirano*sizeof(film));
                                        if(spisak == NULL)
                                        yyerror("Realloc za spisak");
                                    }
                                    spisak[br_filmova].naslov = (char*)malloc(strlen($2)*sizeof(char));
                                    if(spisak[br_filmova].naslov == NULL)
                                    yyerror("Malloc za naslov");
                                    strcpy(spisak[br_filmova].naslov,$2);
                                    spisak[br_filmova].reziser = NULL;
                                }
         ;
         
premijera : YEARO GODINA YEARZ { spisak[br_filmova].godina = $2; }
            ;
            
podaci : podaci podatak
         |
         ;
         
podatak : DIRECTORO IME DIRECTORZ   {
                                        spisak[br_filmova].reziser = (char* )malloc(sizeof(char)*strlen($2));
                                        if(spisak[br_filmova].reziser == NULL)
                                            yyerror("MAlloc() error za rezisera\n");
                                        strcpy(spisak[br_filmova].reziser , $2);
                                    }
        | RATINGO OCENA RATINGZ
        ;
%%

int main(int argc, char** argv){
	
	int (*poredjenje)(const void*,const void * );
	int ispravno =0;
	
	for(argc-- ; argc >0 ; argc-- )
		if(argv[argc][0] == '-' )
			if(argv[argc][1] == 'g'){
                ispravno = 1;
				poredjenje = poredjenjegodina;
			}
			else
				if(argv[argc][1] == 'n'){
                    ispravno = 1;
					poredjenje = poredjenjenaslova;
				}
				else 
					if(argv[argc][1] == 'o'){
                        ispravno = 1;
						poredjenje = poredjenjeocena;
					}
					
    if( !ispravno ){
        fprintf(stderr,"Upotreba programa: \n\t%s -[gno]\n\n",argv[0]);
        exit(EXIT_SUCCESS);
    }
		
	yydebug = 0 ;
  
    yyparse();
  
    int i;
	
	qsort(spisak, br_filmova, sizeof(film), poredjenje );
	
	for(i=0; i<br_filmova; i++){
		printf("\n\n%s\n",spisak[i].naslov);
		printf("\t%d\n",spisak[i].godina);
		printf("\t%.2f\n",spisak[i].ocena);
		if(spisak[i].reziser != NULL )
			printf("\t%s\n",spisak[i].reziser);
	}
	
	for(i=0;i<br_filmova; i++){
		free(spisak[i].naslov);
		free(spisak[i].reziser);
	}
	
	free(spisak);
	
	return 0;
}
