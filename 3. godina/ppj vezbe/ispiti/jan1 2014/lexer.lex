%option noyywrap
%option noinput
%option nounput

%{
    #include<iostream>
    #include<cstdlib>
    #include"prom.hpp"
    #include"liste.hpp"
    #include"parser.tab.hpp"
    using namespace std;
    
    int hex();
%}

%%
OR      return OR_OP;
AND     return AND_OP;
NOT     return NOT_OP;
XOR     return XOR_OP;
SHL     return SHL_OP;
SHR     return SHR_OP;
SET     return SET_OP;
TO      return TO_OP;
HEAD    return HEAD_OP;
TAIL    return TAIL_OP;
SORT    return SORT_OP;
LENGTH  return LENGTH_OP;
\n      return *yytext;
[#=(),\[\]\.+*/-]  return *yytext;
[a-z]+  {   
            yylval.id = strdup(yytext);
            return ID;
        }
[A-Z]+  {   
            yylval.id = strdup(yytext);
            return ID_L;
        }
[0-9]+    { 
                yylval.vr = atoi(yytext);
                return BROJ;
          }
0x[0-9A-F]{1,8}  {
                    yylval.vr = hex();
                    return BROJ;
                 }
[ \t] {}
. {
    cerr << "Leksicka greska!" << endl;
    exit(EXIT_FAILURE);
  }
%%

int maska(char c){
    if(c >= '0' && c <= '9')
        return c - '0';
    else
        return c - 'A' + 10;
}

int hex(){
    int br = 0;
    for(int i = yyleng-1, j = 0; yytext[i] != 'x'; i--, j++)
        br = br | (maska(yytext[i]) << 4*j);
    return br;
}
