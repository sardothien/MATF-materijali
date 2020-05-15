%option noyywrap
%option noinput
%option nounput

%{
    #include<iostream>
    #include<cstdlib>
    #include"datum.hpp"
    #include"parser.tab.hpp"
    using namespace std;
%}

%%
date        return DATE_T;
print       return PRINT;
USA         return USA;
EUR         return EUR;
ISO         return ISO;
"=="        return JEDNAKO;
"!="        return RAZLICITO;
[/\-+=()<>;,\.\']    return *yytext;
[0-9]+          {
                    yylval.vr = atoi(yytext);
                    return BROJ;
                }
[a-z][a-z0-9]*  {
                    yylval.niska = new string(yytext);
                    return ID;
                }
[ \n\t] {}
.   {
        cerr << "Leksicka greska! "  << *yytext << endl;
        exit(EXIT_FAILURE);
    }
%%
