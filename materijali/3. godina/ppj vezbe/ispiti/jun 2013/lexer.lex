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
(?i:kthxbye[ \n\t]*) return KRAJ;
(?i:iz)              return IZ;
rofl                 return ROFL;
orly"?"              return ORLY;
uber                 return UBER;
nope\ uber           return NUBER;
liek                 return LIEK;
nope\ liek           return NLIEK;
(?i:lo{1,48}l)       {
                        yylval.broj = strlen(yytext)-2;
                        return ID;
                     }
[0-9]{1,3}           {  
                        yylval.broj = atoi(yytext);
                        if(yylval.broj > 255){
                            cerr << "Nekorektan broj!" << endl;
                            exit(EXIT_FAILURE);
                        }
                        return BROJ;
                     }
"++"      return UVECANJE;
"--"      return SMANJENJE;
[+*/()-]  return *yytext;
\n        return *yytext;
[ \t]     {}
. {
    cerr << "Leksicka greska!" << endl;
  }
%%
