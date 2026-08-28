%{
#include "calc.tab.h"   /* Inclui as definições criadas pelo bison -d */
#include <stdlib.h>
%}

%%

[ \t\n]+              /* ignora espaços, tabs e quebras de linha */
[0-9]+  {
    yylval.intValue = atoi(yytext);
    return NUM;
}
"+"     { return PLUS; }
"-"     { return MINUS; }
"*"     { return TIMES; }
"/"     { return DIV; }
"("     { return LPAREN; }
")"     { return RPAREN; }
.       { /* tudo mais é ignorado */ }

%%

int yywrap() { return 1; }