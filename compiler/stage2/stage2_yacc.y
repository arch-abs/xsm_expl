%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "syntaxtreedecl.h"
    #include "syntaxtreefunc.c"

    //#define YYSTYPE node
    
    FILE* yyin;
    int yylex(void);
%}

%union{
     struct tnode* root;
}

%type <root> NUM END E Program ID Slist Stmt InputStmt OutputStmt AssgStmt '+' '-' '*' '/'


%token NUM END _BEGIN READ WRITE ID 
%left '+' '-'
%left '*' '/'


                        //node createTree(int val, int type, char* varname, int nodetype, node left, node right)



%%

    Program:        _BEGIN Slist END ';'     {
                                            // callPrefixPrint($1);
                                            // callPostfixPrint($1);
                                            // printf("%d\n", evaluate($1));
                                           
                                            printf(">>Parsed<<!!!\n");
                                            
                                            codeGen($2);
                                            $$ = $2;

                                            //some more things to check O/P
                                        }
                    | _BEGIN END ';' {
                                        // callPrefixPrint($1);
                                        // callPostfixPrint($1);
                                        // printf("%d\n", evaluate($1));
                                        
                                        //codeGen(NULL);
        
                                        $$ = NULL;
                                        //some more things to check O/P
                                    }
                    ;

    Slist   :       Slist Stmt      {$$ = createTree(-1, CONNECTOR, NULL, CONNECTOR, $1, $2);}
                    | Stmt          {$$ = $1;}
                    ;

    Stmt    :       InputStmt       {$$=$1;}
                    | OutputStmt    {$$=$1;}
                    | AssgStmt      {$$=$1;}
                    ;

    InputStmt:      READ '(' ID ')' ';'         {$$ = createTree(-1, READ, NULL, READ, $3, NULL);}
                    ;

    OutputStmt:     WRITE '(' E ')' ';'         {$$ = createTree(-1, WRITE, NULL, WRITE, $3, NULL);}
                    ;

    AssgStmt    :   ID '=' E ';'                {$$ = createTree('=', '=', NULL, ASSGNOP, $1, $3);}
                    ;


    E       :         E '+' E         {$$ = createTree('+', '+', INTEGER, ARITHOP, $1, $3);}
                    | E '-' E         {$$ = createTree('-', '-', INTEGER, ARITHOP, $1, $3);}
                    | E '*' E         {$$ = createTree('*', '*', INTEGER, ARITHOP, $1, $3);}
                    | E '/' E         {$$ = createTree('/', '/', INTEGER, ARITHOP, $1, $3);}
                    | '(' E ')'       {$$ = $2;}
                    | NUM             {$$ = $1;}
                    | ID              {$$ = $1;}
                    ;
%%


void yyerror(const char *s){
    printf("yyerror %s", s);
}

int main(int argc, char* argv[]){
    
    yyin = fopen(argv[1], "r");

    yyparse();
    return 0;
}