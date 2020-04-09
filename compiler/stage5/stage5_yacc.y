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

%type <root> NUM END E Program ID Slist Stmt InputStmt OutputStmt AssgStmt Ifstmt Whilestmt BreakStmt ContinueStmt
%type <root> IF then Else ENDIF WHILE DO ENDWHILE '+' '-' '*' '/' '%' ',' '[' ']' '(' ')' '{' '}' LT GT LE GE EQ NE BREAK CONT
// %type <root> Declarations DeclList Decl VarList
%type <root> Type DECL ENDDECL INTEGER STRING STRING_LITERAL
%type <root> GdeclBlock GdeclList GDecl GidList Gid FDefBlock FDef ParamList LDeclBlock Body Param LDecList LDecl IdList ArgList RETURN MainBlock MAIN


%token NUM END _BEGIN READ WRITE ID IF then Else ENDIF WHILE DO ENDWHILE RETURN LT GT LE GE EQ NE BREAK CONT DECL ENDDECL INTEGER STRING STRING_LITERAL MAIN


%left NE
%left EQ
%left GE
%left GT
%left LE
%left LT
%left '+' '-'
%left '*' '/' '%'

                        //node createTree(int val, int type, char* varname, int nodetype, node left, node right)

%start Program

%%

    Program     :      GdeclBlock FDefBlock MainBlock        {}
                       | GdeclBlock MainBlock                {}
                       | MainBlock                           {}

    // Program:        Declarations _BEGIN Slist END ';'     {
    //                                         printGsymbolTable();
    //                                         // callPrefixPrint($1);
    //                                         // callPostfixPrint($1);
    //                                         // printf("%d\n", evaluate($1));
                                           
    //                                         printf(">>Parsed<<!!!\n");
                                            
    //                                         codeGen($3);
    //                                         $$ = $3;

    //                                         //some more things to check O/P
    //                                     }
    //                 |Declarations _BEGIN END ';' {
    //                                     // callPrefixPrint($1);
    //                                     // callPostfixPrint($1);
    //                                     // printf("%d\n", evaluate($1));
                                        
    //                                     //codeGen(NULL);
        
    //                                     $$ = NULL;
    //                                     //some more things to check O/P
    //                                 }
    //                 ;



    

    GdeclBlock  :   DECL GdeclList ENDDECL          {
                                                        installFunc("main", INTEGER, NULL);
                                                        printGsymbolTable();
                                                    }
                    | DECL ENDDECL                  {
                                                        installFunc("main", INTEGER, NULL);
                                                        printGsymbolTable();
                                                    }
                    ;

    GdeclList    :   GdeclList GDecl               {}
                    |GDecl                         {}
                    ;

    GDecl        :   Type GidList ';'              {
                                                        popType();
                                                   }
                    ;

    // Type        :   INTEGER                     {TYPE = INTEGER;}   //REMOVE FROM here and bear FDefBlock Later
    //                 |STRING                     {TYPE = STRING;}
    //                 ;

    GidList     :   GidList ',' Gid              {}
                    | Gid                        {}
                    ;

    Gid         :   ID                          {installGId($1->varname, getType(), 1);}
                    | ID'['NUM']'               {installGId($1->varname, getType(), $3->val);}
                    | ID '(' ParamList ')'      {
                                                    installFunc($1->varname, getType(), paramHeadPtr);
                                                    paramHeadPtr = NULL;
                                                }
                    ;




    MainBlock   :   INTEGER MAIN '(' ')' '{' LDeclBlock Body '}'           {}
                    // | INTEGER MAIN '(' ')' '{' Body '}'                 {}   //LDeclBlock mandatory
                    ;





    FDefBlock   :   FDefBlock FDef              {}
                    | FDef                      {}
                    ;

    FDef        :   Type ID '(' ParamList ')' '{' LDeclBlock Body '}'   {   

                                                                            checkEquivalenceParamDeclDef($2->varname, paramHeadPtr, getType(), $8);     //NAME_TYPE_CHK of decl and def of fn
                                                                            setupLSTBinding($2->varname);

                                                                            paramHeadPtr = NULL;
                                                                            //might also need to free LST and and AST of func here
                                                                            Lsymbol_head = NULL;

                                                                            popType();
                                                                        }      //Note that body is necessary as we need to have a return statement atleast as void returntype is not allowed
                    
                    |Type ID '('  ')' '{' LDeclBlock Body '}'           {
                                                                            checkEquivalenceParamDeclDef($2->varname, paramHeadPtr, getType());
                                                                            setupLSTBinding(char* funcName);

                                                                            //might also need to free LST and and AST of func here
                                                                            Lsymbol_head = NULL;
                                                                            paramHeadPtr = NULL;

                                                                            popType();
                                                                        }
                    // |Type ID '(' ParamList ')' '{' Body '}'             {}   //LDeclBlock mandatory in Fdef
                    // |Type ID '('  ')' '{' Body '}'                      {}
                    ;

    ParamList   :   ParamList ',' Param         {}
                    | Param                     {}
                    ;

    Param       :   Type ID                     {
                                                    paramHeadPtr = addToParamList(getType(), $2->varname);
                                                    popType();
                                                }
                    ;

    Type        :   INTEGER                     {
                                                    // TYPE = INTEGER;
                                                    pushType(INTEGER);
                                                }
                    |STRING                     {
                                                    // TYPE = STRING;
                                                    pushType(STRING);
                                                }
                    ;







    LDeclBlock  :   DECL LDecList ENDDECL       {
                                                    addParamToLST(paramHeadPtr);
                                                    printLsymbolTable();
                                                }

                    | DECL ENDDECL              {
                                                    printLsymbolTable();
                                                }   //will print nothing as empty GST
                    ;

    LDecList    :   LDecList LDecl               {}
                    |   LDecl                    {}
                    ;

    LDecl       :   Type IdList ';'            {
                                                    popType();
                                               }
                    ;

    IdList      :   IdList ',' ID              {installLId($3->varname, getType())}
                    | ID                       {installLId($1->varname, getType())}
                    ;











    // Declarations:   DECL DeclList ENDDECL       {printGsymbolTable();}
    //                 | DECL ENDDECL              {printGsymbolTable();}   //will print nothing as empty GST
    //                 ;

    // DeclList    :   DeclList Decl               {}
    //                 |   Decl                    {}
    //                 ;

    // Decl        :   Type VarList ';'            {}
    //                 ;

    // Type        :   INTEGER                     {TYPE = INTEGER;}
    //                 |STRING                     {TYPE = STRING;}
    //                 ;

    // VarList     :   VarList ',' ID              {install($3->varname, TYPE, 1);}
    //                 | VarList ',' ID'['NUM']'   {install($3->varname, TYPE, $5->val);}
    //                 | ID                        {install($1->varname, TYPE, 1);}
    //                 | ID'['NUM']'               {install($1->varname, TYPE, $3->val);}
    //                 ;







    Body    :       _BEGIN Slist RETURN E ';' END           {
                                                                $$ = createTree(-1, CONNECTOR, NULL, CONNECTOR, $2, createTree(-1, RETURN, NULL, RETURN, $4, NULL, NULL), NULL);
                                                            }

                    | _BEGIN RETURN E ';' END               {
                                                                $$ = createTree(-1, RETURN, NULL, RETURN, $4, NULL, NULL);
                                                            }
                    ;

    Slist   :       Slist Stmt      {$$ = createTree(-1, CONNECTOR, NULL, CONNECTOR, $1, $2, NULL);}
                    | Stmt          {$$ = $1;}
                    ;

    Stmt    :       InputStmt       {$$=$1;}
                    | OutputStmt    {$$=$1;}
                    | AssgStmt      {$$=$1;}
                    | Ifstmt        {$$=$1;}
                    |Whilestmt      {$$=$1;}
                    |BreakStmt      {$$=$1;}
                    |ContinueStmt   {$$=$1;}
                    ;

    InputStmt:      READ '(' ID ')' ';'         {
                                                    // $3->STptr = lookUp($3->varname);   //finding and setting STptr

                                                    // $3->type = ($3->STptr)->type;      //setting type from STptr

                                                    // $$ = createTree(-1, READ, NULL, READ, $3, NULL, NULL);
                                                    
                                                }


                    |READ '(' ID '[' E ']' ')' ';'         {
                                                    // $3->STptr = lookUp($3->varname);   //finding and setting STptr

                                                    // $3->type = ($3->STptr)->type;      //setting type from STptr
                                                    // $3->left = $5;
                                                    // if ($3->left->type != INTEGER)     //TYPE_CHK
                                                    // {
                                                    //     printf("TYPE_ERR..!!! array_index INTEGER expected something else....!!!\n");
                                                    //     exit(0);
                                                    // }

                                                    // $$ = createTree(-1, READ, NULL, READ, $3, NULL, NULL);
                                                    
                                                }
                    ;

    OutputStmt:     WRITE '(' E ')' ';'         {$$ = createTree(-1, WRITE, NULL, WRITE, $3, NULL, NULL);}
                    ;

    AssgStmt    :   ID '=' E ';'                {
                                                    // $1->STptr = lookUp($1->varname);   //finding and setting STptr

                                                    // $1->type = ($1->STptr)->type;      //setting type from STptr
                                                    
                                                    // $$ = createTree('=', '=', NULL, ASSGNOP, $1, $3, NULL);
                                                }
                    | ID'[' E ']' '=' E ';'     {
                                                    // $1->STptr = lookUp($1->varname);   //finding and setting STptr

                                                    // $1->type = ($1->STptr)->type;      //setting type from STptr
                                                    // // $1->val = $3->val;

                                                    // $1->left = $3;
                                                    // if ($1->left->type != INTEGER)     //TYPE_CHK
                                                    // {
                                                    //     printf("TYPE_ERR..!!! array_index INTEGER expected something else....!!!\n");
                                                    //     exit(0);
                                                    // }

                                                    // $$ = createTree('=', '=', NULL, ASSGNOP, $1, $6, NULL);
                                                }
                    ;

    Ifstmt      :   IF '(' E ')' then Slist Else Slist ENDIF ';'    {$$ = createTree(-1, IF, NULL, IF, $3, createTree(-1, IFBODY, NULL, IFBODY, $6, $8, NULL), NULL);}
                |   IF '(' E ')' then Slist ENDIF ';'               {$$ = createTree(-1, IF, NULL, IF, $3, createTree(-1, IFBODY, NULL, IFBODY, $6, NULL, NULL), NULL);}
                ;

    Whilestmt   :   WHILE '(' E ')' DO Slist ENDWHILE ';'           {$$ = createTree(-1, WHILE, NULL, WHILE, $3, $6, NULL);}
                ;

    BreakStmt   :   BREAK ';'                   {$$ = createTree(-1, BREAK, NULL, BREAK, NULL, NULL, NULL);}

    ContinueStmt:   CONT ';'                    {$$ = createTree(-1, CONT, NULL, CONT, NULL, NULL, NULL);}


    E       :         E '+' E         {$$ = createTree('+', INTEGER, NULL, ARITHOP, $1, $3, NULL);}
                    | E '-' E         {$$ = createTree('-', INTEGER, NULL, ARITHOP, $1, $3, NULL);}
                    | E '*' E         {$$ = createTree('*', INTEGER, NULL, ARITHOP, $1, $3, NULL);}
                    | E '/' E         {$$ = createTree('/', INTEGER, NULL, ARITHOP, $1, $3, NULL);}
                    | E '%' E         {$$ = createTree('%', INTEGER, NULL, ARITHOP, $1, $3, NULL);}
                    | '(' E ')'       {$$ = $2;}
                    | NUM             {$$ = $1;}
                    | STRING_LITERAL  {$$ = $1;}        //printf("str found...\n");
                    | ID              {
                                        // printf("LALA..!!!! in ID reduc....\n");
                                        // $1->STptr = lookUp($1->varname);   //finding and setting STptr
                                        // // if($1->STptr == NULL)
                                        // // {
                                        // //     printf("%%$##@@@#$#\n");
                                        // //     exit(1);
                                        // // }
                                        // $1->type = ($1->STptr)->type;      //setting type from STptr
                                        // $$ = $1;
                                        // printf("LALA..!!!! varname is %s\n", $$->STptr->name);
                                        // printf("LALA..!!!! type is %d\n", $$->type);
                                        // printf("val of STptr is %p\n", $$->STptr);
                                      }
                    | ID'['E']'     {
                                        // printf("LALALOLO..!!!! in ID[E] reduc....\n");
                                        // $1->STptr = lookUp($1->varname);   //finding and setting STptr
                                        // // if($1->STptr == NULL)
                                        // // {
                                        // //     printf("%%$##@@@#$#\n");
                                        // //     exit(1);
                                        // // }
                                        // $1->type = ($1->STptr)->type;      //setting type from STptr
                                        // // $1->val = $3->val;
                                        // $1->left = $3;
                                        // if ($1->left->type != INTEGER)     //TYPE_CHK
                                        // {
                                        //     printf("TYPE_ERR..!!! array_index INTEGER expected something else....!!!\n");
                                        //     exit(0);
                                        // }
                                        // $$ = $1;
                                        // printf("LALA..!!!! varname is %s\n", $$->STptr->name);
                                        // printf("LALA..!!!! type is %d\n", $$->type);
                                        // printf("val of STptr is %p\n", $$->STptr);
                                      }
                        

                    | E LT E          {$$ = createTree(LT, BOOLEAN, NULL, RELOP, $1, $3, NULL);}
                    | E GT E          {$$ = createTree(GT, BOOLEAN, NULL, RELOP, $1, $3, NULL);}
                    | E LE E          {$$ = createTree(LE, BOOLEAN, NULL, RELOP, $1, $3, NULL);}
                    | E GE E          {$$ = createTree(GE, BOOLEAN, NULL, RELOP, $1, $3, NULL);}
                    | E EQ E          {$$ = createTree(EQ, BOOLEAN, NULL, RELOP, $1, $3, NULL);}
                    | E NE E          {$$ = createTree(NE, BOOLEAN, NULL, RELOP, $1, $3, NULL);}
                    
                    | ID '(' ArgList ')'    {
                                                $1->STptr = lookUp($1->varname, 1);
                                                $1->type = ($1->STptr)->type;      //setting type from STptr

                                                $$ = createTree(-1, $1->type, $1->varname, FUNCCALL, $1, $3, NULL);
                                            }

                    | ID '(' ')'            {
                                                $1->STptr = lookUp($1->varname, 1);
                                                $1->type = ($1->STptr)->type;      //setting type from STptr

                                                $$ = createTree(-1, $1->type, $1->varname, FUNCCALL, $1, NULL, NULL);
                                            }
                    ;


    ArgList :       ArgList ',' E           {

                                                $$ = createTree(-1, $3->type, NULL, ARGLIST, $3, $1, NULL);
                                            }
                    
                    | E                     {$$ = createTree(-1, $1->type, NULL, ARGLIST, $1, NULL, NULL);}
                    ;
%%


void yyerror(const char *s){
    printf("line %d: yyerror %s", line,s);
}



int main(int argc, char* argv[]){
    line = 1;
    yyin = fopen(argv[1], "r");

    // installFunc("main", INTEGER, NULL);

    yyparse();
    return 0;
}

