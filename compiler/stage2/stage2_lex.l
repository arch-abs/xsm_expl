%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
    #include "syntaxtreedecl.h"
    //#include "syntaxtreefunc.c"       //might need to remove

    //#define YYSTYPE node

    // yyin  = (FILE*)fopen(argv[1], "r");

    int number;

    //MIGHT NEED TO REMOVE NOYYWRAP
%}


%option noyywrap


%%

[ |\t|\n]*  /*Eat up white space*/                          

[0-9]+  {
            number = atoi(yytext);
            yylval.root = createTree(number, INTEGER, NULL, NUM, NULL, NULL);
            return NUM;
        }

[\+ | \- | \* | \/ | \( | \) | \= | \;]  {
                    return *yytext;
                    //yylval = NULL;
                }

[a-z]   {
            yylval.root = createTree(-1, ID, yytext, ID, NULL, NULL);
            return ID;
        }

"begin" {
            return _BEGIN;
        }

"end"   {
            return END;
        }

"read"   {
            return READ;
        }
"write"   {
            return WRITE;
        }

%%
