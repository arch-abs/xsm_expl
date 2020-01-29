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

%type <root> NUM END E Program ID Slist Stmt InputStmt OutputStmt AssgStmt Ifstmt Whilestmt
%type <root> IF then Else ENDIF WHILE DO ENDWHILE '+' '-' '*' '/' LT GT LE GE EQ NE


%token NUM END _BEGIN READ WRITE ID IF then Else ENDIF WHILE DO ENDWHILE LT GT LE GE EQ NE


%left NE
%left EQ
%left GE
%left GT
%left LE
%left LT
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
                    | Ifstmt
                    |Whilestmt
                    ;

    InputStmt:      READ '(' ID ')' ';'         {$$ = createTree(-1, READ, NULL, READ, $3, NULL);}
                    ;

    OutputStmt:     WRITE '(' E ')' ';'         {$$ = createTree(-1, WRITE, NULL, WRITE, $3, NULL);}
                    ;

    AssgStmt    :   ID '=' E ';'                {$$ = createTree('=', '=', NULL, ASSGNOP, $1, $3);}
                    ;

    Ifstmt      :   IF '(' E ')' then Slist Else Slist ENDIF ';'    {$$ = createTree(-1, IF, NULL, IF, $3, createTree(-1, IFBODY, NULL, IFBODY, $6, $8));}
                |   IF '(' E ')' then Slist ENDIF ';'               {$$ = createTree(-1, IF, NULL, IF, $3, createTree(-1, IFBODY, NULL, IFBODY, $6, NULL));}
                ;

    Whilestmt   :   WHILE '(' E ')' DO Slist ENDWHILE ';'           {$$ = createTree(-1, WHILE, NULL, WHILE, $3, $6);}
                ;


    E       :         E '+' E         {$$ = createTree('+', INTEGER, NULL, ARITHOP, $1, $3);}
                    | E '-' E         {$$ = createTree('-', INTEGER, NULL, ARITHOP, $1, $3);}
                    | E '*' E         {$$ = createTree('*', INTEGER, NULL, ARITHOP, $1, $3);}
                    | E '/' E         {$$ = createTree('/', INTEGER, NULL, ARITHOP, $1, $3);}
                    | '(' E ')'       {$$ = $2;}
                    | NUM             {$$ = $1;}
                    | ID              {$$ = $1;}

                    | E LT E          {$$ = createTree(LT, BOOLEAN, NULL, RELOP, $1, $3);}
                    | E GT E          {$$ = createTree(GT, BOOLEAN, NULL, RELOP, $1, $3);}
                    | E LE E          {$$ = createTree(LE, BOOLEAN, NULL, RELOP, $1, $3);}
                    | E GE E          {$$ = createTree(GE, BOOLEAN, NULL, RELOP, $1, $3);}
                    | E EQ E          {$$ = createTree(EQ, BOOLEAN, NULL, RELOP, $1, $3);}
                    | E NE E          {$$ = createTree(NE, BOOLEAN, NULL, RELOP, $1, $3);}
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

