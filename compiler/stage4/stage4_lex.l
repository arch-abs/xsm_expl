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
            yylval.root = createTree(number, INTEGER, NULL, NUM, NULL, NULL, NULL);
            return NUM;
        }

([\"](.)*[\"])    {
            yylval.root = createTree(number, STRING, yytext, STRING_LITERAL, NULL, NULL, NULL);
            return STRING_LITERAL;
        }

[ \+ | \- | \* | \/ | \( | \) | \= | \; |\, |\[ |\] ]  {
                    return *yytext;
                    //yylval = NULL;
                }


"decl" {
            return DECL;
        }

"enddecl"   {
            return ENDDECL;
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

                                                                   
"if"    {
            return IF;
        }

"then"    {
            return then;
        }

"else"  {
            return Else;
    }

"endif"   {
            return ENDIF;    
}

"while"    {
            return WHILE;
}

"do"        {
            return DO;
}

"endwhile"  {
            return ENDWHILE;
}

"break"  {
            return BREAK;
}

"continue"  {
            return CONT;
}

"int"       {
            return INTEGER;
}

"str"       {
            return STRING;
}


"<"     {
            return LT;
        }

">"     {
            return GT;         
        }

"<="     {
            return LE;    
        }

">="     {
            return GE;      
        }

"=="     {
            return EQ;      
        }

"!="     {
            return NE;
        }        


[a-zA-Z][a-zA-Z0-9]*   {
            yylval.root = createTree(-1, ID, yytext, ID, NULL, NULL, NULL);  //NOW not defining type, will be done later when ID found in program and type will be Added from symbol table
            return ID;
        }

%%
