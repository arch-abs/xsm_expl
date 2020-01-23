%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
    #include "exprtreedecl.h"
    //#include "exprtreefunc.c"       //might need to remove

    //#define YYSTYPE node

    int number;

    //MIGHT NEED TO REMOVE NOYYWRAP
%}


%option noyywrap

%%

[ |\t]*        //eat up whitespace... (new line not include) 

[0-9]+   {
            number = atoi(yytext);
            yylval.root = makeLeafNode(number);
            return NUM;
        }

[\+ | \( | \)]  {
                    return *yytext;
                    //yylval = NULL;
                }

[\n]    {
            return END;
        }

%%