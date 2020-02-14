%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "syntaxtreedecl.h"
    #include "syntaxtreefunc.c"

    //#define YYSTYPE node
    
    int yylex(void);
%}

%union{
     struct tnode* root;
}

%type <root> OutputStmt E  '+'


%token NUM END _BEGIN READ WRITE ID 
%left '+' '-'
%left '*' '/'


                        //node createTree(int val, int type, char* varname, int nodetype, node left, node right)



%%




    OutputStmt:     WRITE '(' E ')' ';'         {$$ = createTree(-1, WRITE, NULL, WRITE, $3, NULL);}
                    ;


    E       :         '(' E ')'       {$$ = $2;}
            | NUM

                    ;
%%


void yyerror(const char *s){
    printf("yyerror %s", s);
}

main(int argc, char* argv[]){
	if(argc > 1){
		FILE *fr = fopen(argv[1], "r");
		if(fr)
			yyin = fr;
	}
    
    yyparse();
    return 0;
}