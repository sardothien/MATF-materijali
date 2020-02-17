%option noyywrap
%option noinput
%option nounput

%{
    #include<iostream>
    #include<cstdlib>
    #include<string>
    #include"formula.hpp"
    #include"parser.tab.hpp"
    using namespace std;
%}

%%
"True"  return TRUE_ID;
"False" return FALSE_ID;
"<=>"   return EKV;
"=>"    return IMPL;
"/\\"   return KONJ;
"\\/"   return DISJ;
":="    return DOD;
[a-z][a-z0-9]*   {
                    yylval.prom = new std::string(yytext);
                    return ID;
                 }
[\n()!]    return *yytext;
[ \t] {}
. {
    cerr << "Leksicka greska!" << endl;
    exit(EXIT_FAILURE);
  }
%%
