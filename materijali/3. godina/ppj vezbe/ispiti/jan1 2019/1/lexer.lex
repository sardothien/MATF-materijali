%option noyywrap
%option noinput
%option nounput

%{
    #include<iostream>
    #include<cstdlib>
    #include"parser.tab.hpp"
    using namespace std;
%}

%%
int     return INT_T;
print   return PRINT;
list    return LIST;
"<<"    return SHL;
">>"    return SHR;
"=="    return JEDN;
"!="    return RAZL;
0x[0-9A-F]+ {
                yylval.vr = strtol(yytext, NULL, 16);
                return BROJ;
            }
0[0-7]+     {
                yylval.vr = strtol(yytext, NULL, 8);
                return BROJ;
            }
[0-9]+  {
            yylval.vr = strtol(yytext, NULL, 10);
            return BROJ;
        }
[(),;=&"|"^~+*%/\-\[\]]  return *yytext;
_[a-z][a-z0-9]* {
                    yylval.id = new std::string(yytext);
                    return ID;
                }
[a-z]+      {
                yylval.id = new std::string(yytext);
                return ID_L;
            }
[ \n\t] {}
.   {
        cerr << "Leksicka greska!" << endl;
        exit(EXIT_FAILURE);
    }
%%
