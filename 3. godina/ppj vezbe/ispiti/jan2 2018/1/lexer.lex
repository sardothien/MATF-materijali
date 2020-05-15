%option noyywrap
%option noinput
%option nounput

%{
    #include<iostream>
    #include<cstdlib>
    #include"formula.hpp"
    #include"parser.tab.hpp"
    using namespace std;
%}

%%
"/\\"   return KONJ;
"\\/"   return DISJ;
"<=>"   return EKV;
"=>"    return IMPL;
"!"     return NEG;
":="    return DOD;
tail    return TAIL;
head    return HEAD;
True    return TRUE_T;
False   return FALSE_T;
Undef   return UNDEF_T;
[()\[\],]    return *yytext;
[0-9]+  {
            yylval.vr = atoi(yytext);
            return BROJ;
        }
[A-Z][a-z0-9]*  {
                    yylval.id = new string(yytext);
                    return ID_L;
                }
[a-z][a-z0-9]*  {
                    yylval.id = new string(yytext);
                    return ID;
                }
\n      return *yytext;
[ \t]   {}
.       {
            cerr << "Leksicka greska!" << endl;
            exit(EXIT_FAILURE);
        }
%%
