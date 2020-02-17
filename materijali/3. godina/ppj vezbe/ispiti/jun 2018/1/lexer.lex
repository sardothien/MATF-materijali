%option noyywrap
%option noinput
%option nounput

%{
    #include<iostream>
    #include<cstdlib>
    #include"matrice.hpp"
    #include"parser.tab.hpp"
    using namespace std;
%}

%%
disp    return DISP;
size    return SIZE;
".*"    return TPUTA;
".+"    return TPLUS;
[\[\](),;=*\']  return *yytext;
[0-9]+  {   
            yylval.vr = atoi(yytext);
            return BROJ;
        }
[a-zA-Z]    {
                yylval.id = *yytext;
                return ID;
            }
\n  return *yytext;
[ \t]   {}
.       {
            cerr << "Leksicka greska!" << endl;
            exit(EXIT_FAILURE);
        }
%%
