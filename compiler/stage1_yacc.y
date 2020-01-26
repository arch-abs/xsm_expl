%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "exprtreedecl.h"
    #include "exprtreefunc.c"

    //#define YYSTYPE node
    
    int yylex(void);
%}

%union{
     struct tnode* root;
}

%type <root> NUM END E program '+'


%token NUM END
%left '+'



%%

    program:        E END           {
                                        callPrefixPrint($1);
                                        callPostfixPrint($1);
                                        printf("%d\n", evaluate($1));
                                        codeGen($1);
        
                                        $$ = $1;
                                        //some more things to check O/P
                                    }
                    ;


    E       :       E '+' E         {$$ = makeOperatorNode('+', $1, $3);}
                    | '(' E ')'     {$$ = $2;}
                    | NUM           {$$ = $1;}
                    ;
%%


void yyerror(const char *s){
    printf("yyerror %s", s);
}

int main(void){
    
    yyparse();
    return 0;
}
