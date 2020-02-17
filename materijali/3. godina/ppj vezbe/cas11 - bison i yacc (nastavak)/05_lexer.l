%option noyywrap

%{
    #include"05_y.tab.c"
%}

%x naslov
%x ime

%%
"<xml>"     return XMLO;
"</xml>"    return XMLZ;
"<movie>"   return MOVIEO;
"</movie>"  return MOVIEZ;
"<title>"   {
                BEGIN(naslov);
                return TITLEO;
            }
<naslov>"</title>"  {
                        BEGIN(INITIAL);
                        return TITLEZ;
                    }
<naslov>[^<]+       {
                        strcpy(yylval.buffer, yytext);
                        return NASLOV;
                    }
"<year>"        return YEARO;
"</year>"       return YEARZ;
"<director>"    {
                    BEGIN(ime);
                    return DIRECTORO;
                }
<ime>[A-Z][a-z]+(" "[A-Za-z]+)* {
                                    strcpy(yylval.buffer, yytext);
                                    return IME;
                                }
<ime>"</director>"  {
                        BEGIN(INITIAL);
                        return DIRECTORZ;
                    }
"<rating>"  return RATINGO;
"</rating>" return RATINGZ;
189[5-9]|19[0-9]{2}|200[0-9]|201[0-3]   {
                                            yylval.godina = atoi(yytext);
                                            return GODINA;
                                        }
10|[1-9]\.[0-9]{1,2}    {
                            yylval.ocena = atof(yytext);
                            return OCENA;
                        }
[ \t\n] {}
. {
        fprintf(stderr, "Leksicka greska!\n");
        exit(EXIT_FAILURE);
  }
%%
