%option noyywrap
%option noinput
%option nounput

%{
    #include<iostream>
    #include<cstdlib>
    #include<string>
    #include"formula.hpp"
    using namespace std;
    #include"parser.tab.hpp"
%}

%%
"/\\"   return III;
"\\/"   return ILI;
"<=>"   return EKV;
"=>"    return IMPL;
"True"  return TRUE_ID;
"False" return FALSE_ID;
[a-z][a-z0-9]*   {
                    yylval.str_type = new std::string(yytext);
                    return ID;
                 }
":="    return DOD;
[!\n()]   return *yytext;
[ \t] {}
. {
    cerr << "Leksicka greska!" << endl;
    exit(EXIT_FAILURE);
  }
%%
