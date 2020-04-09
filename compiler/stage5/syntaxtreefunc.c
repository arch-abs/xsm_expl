    #include <string.h>
    // MIGHT NEED TO INCLUDE exprtreedecl.h here
    #include "syntaxtreedecl.h"
    #include "y.tab.h"

    int regCount = 0; //might need to change this to array based in future
    int lblCount = -1;
    int funcLblCount = -1;

    int loop_stack_count = -1;
    int type_stack_count = -1;

    // int TYPE;

    paramList paramHeadPtr = NULL;      //used in making paramList

    int binding = 4095;

    int loop_stack[2][10000]; //0 is for entry point lbl & 1 is for exit pt label

    int type_stack[10000];

    SymbolTableEntry Gsymbol_head = NULL;

    SymbolTableEntry Lsymbol_head = NULL;      //ptr for LST of Func being CURRENTLY PROCESSED




    int getFreeReg()
    {
        if (regCount >= 20)
        {
            printf("Error!!!! NO REGS FREE\n");
            exit(0);
            return -1;
        }
        regCount++;
        return (regCount - 1);
    }

    void freeReg()
    {
        // printf("In freeReg()...\n");
        if (regCount > 0){
            // printf("Decrementing reg count...\n");
            regCount--;
        }
        else
        {
            printf("Error!!!! NO REGS to REALEASE\n");
            exit(0);
        }
    }


    int getLabel()
    {
        lblCount++;
        return lblCount;
    }

    int getFuncLabel()
    {
        funcLblCount++;
        return funcLblCount;
    }


    void pushType(int type){
        if(type_stack_count >= 10000){
            printf(">>>ERROR<<<!!!...TYPE_STACK OVERFLOW.... exiting...\n");
            exit(0);
        }
        else{
            type_stack_count++;
            type_stack[type_stack_count] = type;    
        }
    }

    void popType()
    {
        if (type_stack_count <= -1)
            printf("ERR...!!! TYPE STACK count trying to over pop...\n");
        else
            type_stack_count--;
    }

    int getType(){
        return type_stack[type_stack_count];
    }




    void pushLoop()
    {   if(loop_stack_count >= 10000){
            printf(">>>ERROR<<<!!!...LOPP_STACK OVERFLOW.... exiting...\n");
            exit(0);
        }
        else
            loop_stack_count++;
    }

    void popLoop()
    {
        if (loop_stack_count <= -1)
            printf("ERR...!!! Loop stack count trying to over pop...\n");
        else
            loop_stack_count--;
    }



    paramList addToParamList(int type, char* name){
        // printf("LOLA>..!!! IN addtoParamList()\n");
        paramList new = (paramList)malloc(sizeof(struct paramListNode));
        new->type = type;
        new->name = strdup(name);
        new->next = NULL;

        if(paramHeadPtr == NULL)
            paramHeadPtr = new;
        else{
            paramList tmp = paramHeadPtr;
            if (strcmp(tmp->name, name) == 0)
            {
                printf("ERR..!!! Parameter name redeclared... (printing from addToParamList())...EXITing\n");
                exit(0);
            }
            while(tmp->next != NULL){
                if (strcmp(tmp->name, name) == 0)
                {
                    printf("ERR..!!! Parameter name redeclared... (printing from addToParamList())...EXITing\n");
                    exit(0);
                }
                tmp = tmp->next;
            }
            tmp->next = new;
        }

        return paramHeadPtr;

    }



    SymbolTableEntry lookUp(char *name, int FlagGSTLookup)     //bool GSTLookup is to state if direclty search in GST(int case of arrays and functions)
    {
        //part to lookup in LST
        if(FlagGSTLookup == 0){
            if (Lsymbol_head == NULL)
            {
                printf("ERR...!!! Trying to LookUp in EMPTY GSymbol Table...!!!\n");
                // return NULL;
            }
            SymbolTableEntry tmp = Lsymbol_head;
            while (tmp != NULL)
            {
                if (strcmp(tmp->name, name) == 0)
                    return tmp;
                tmp = tmp->next;
            }
        }


        //part to lookUp in GST
        if (Gsymbol_head == NULL)
        {
            printf("ERR...!!! Trying to LookUp in EMPTY GSymbol Table...!!!...EXITing\n");
            return NULL;
        }
        SymbolTableEntry tmp = Gsymbol_head;
        while (tmp != NULL)
        {
            if (strcmp(tmp->name, name) == 0)
                return tmp;
            tmp = tmp->next;
        }

        printf("ERR...!!! Entry not found in GSymbol Table...!!!\n");
        return NULL;
    }


    SymbolTableEntry createSymbolTableNode(char* name, int type, int size, paramList param){
        SymbolTableEntry new = (SymbolTableEntry)malloc(sizeof(struct SymbolTable));
        new->name = name;
        new->type = type;
        new->size = size;
        new->param = param;
        new->next = NULL;

        return new;
    }


    void installGId(char *name, int type, int size)
    {
        // SymbolTableEntry new = (SymbolTableEntry)malloc(sizeof(struct SymbolTable));
        // new->name = name;
        // new->type = type;
        // new->size = size;
        // new->param = NULL;
        // new->next = NULL;

        SymbolTableEntry new = createSymbolTableNode(name, type, size, NULL);

        SymbolTableEntry tmp = Gsymbol_head;
        if (tmp == NULL)
        {
            binding++;
            new->binding = binding;
            Gsymbol_head = new;
        }
        else
        {make
            long size_sum;
            size_sum = 0;
            while (tmp->next != NULL)
            {
                if (strcmp(tmp->name, name) == 0)
                {
                    printf("ERR..!!! Variable redeclared... (printing from install())\n");
                    exit(0);
                }
                if(tmp->size != -1)
                    size_sum = size_sum + tmp->size;
                tmp = tmp->next;
            }

            if (strcmp(tmp->name, name) == 0)
            {
                printf("ERR..!!! Variable redeclared... (printing from installGId())\n");
                exit(0);
            }
            if(tmp->size != -1)
                size_sum = size_sum + tmp->size;


            binding = 4095 + size_sum;
            binding++;
            new->binding = binding;
            tmp->next = new;
        }
    }


    void installFunc(char *name, int type, paramList param)
    {
        // SymbolTableEntry new = (SymbolTableEntry)malloc(sizeof(struct SymbolTable));
        // new->name = name;
        // new->type = type;
        // new->size = -1;
        // new->binding = getFuncLabel();
        // new->param = param;
        // new->next = NULL;


        SymbolTableEntry new = createSymbolTableNode(name, type, -1, param);
        new->binding = getFuncLabel();


        SymbolTableEntry tmp = Gsymbol_head;

        if (tmp == NULL)
        {
            // binding++;
            // new->binding = binding;
            Gsymbol_head = new;
        }
        else
        {
            while (tmp->next != NULL)
            {
                if (strcmp(tmp->name, name) == 0)
                {
                    printf("ERR..!!! Func with name %s already decalred... (printing from installGId())\n", name);
                    exit(0);
                }
                tmp = tmp->next;
                // binding = binding + tmp->size;
            }
            // binding++;
            // new->binding = binding;
            tmp->next = new;
        }
    }



    void installLId(char *name, int type)
    {
        // SymbolTableEntry new = (SymbolTableEntry)malloc(sizeof(struct SymbolTable));
        // new->name = name;
        // new->type = type;
        // new->size = 1;      //no need in LId but still assigning 1 to differetiate from func entires
        // new->next = NULL;

        SymbolTableEntry new = createSymbolTableNode(name, type, 1, NULL);

        SymbolTableEntry tmp = Lsymbol_head;
        if (tmp == NULL)
        {
            // binding++;
            // new->binding = binding;
            Lsymbol_head = new;
        }
        else
        {
            // long size_sum;
            // size_sum = 0;
            while (tmp->next != NULL)
            {
                if (strcmp(tmp->name, name) == 0)
                {
                    printf("ERR..!!! Variable redeclared... (printing from installLId())\n");
                    exit(0);
                }
                // if(tmp->size != -1)
                //     size_sum = size_sum + tmp->size;
                tmp = tmp->next;
            }

            if (strcmp(tmp->name, name) == 0)
            {
                printf("ERR..!!! Variable redeclared... (printing from installLId())\n");
                exit(0);
            }
            // if(tmp->size != -1)
            //     size_sum = size_sum + tmp->size;


            // binding = 4095 + size_sum;
            // binding++;
            // new->binding = binding;
            tmp->next = new;
        }
    }

    SymbolTableEntry addParamToLST(paramList param){
        paramList tmp = param;
        SymbolTableEntry head, ptr;
        head = NULL;
        ptr = NULL;

        while (tmp != NULL){
            SymbolTableEntry new  = createSymbolTableNode(tmp->name, tmp->type, 1, NULL);
            if(head == NULL  ||  ptr == NULL){
                head = new;
                ptr = new;
            }else{
                ptr->next = new;
                ptr = ptr->next;
            }

            tmp = tmp->next;
        }

        if(ptr!=NULL  &&  head!=NULL){
            ptr->next = Lsymbol_head;
            Lsymbol_head = head;
        }

        return Lsymbol_head;
    }


    void setupLSTBinding(char* funcName){
        SymbolTableEntry ste = lookUp(funcName, 1);     //note that decl of function has been already been checked by checkEquivalenceParamDeclDef
        if(ste != NULL){
            int i;
            paramList tmp = ste->param;
            SymbolTableEntry ptr = Lsymbol_head;
            
            i = 1;
            while(tmp != NULL){
                ptr->binding = -(i + 2);
                i++;
                tmp = tmp->next;
                ptr = ptr->next;  
            }

            i=1;
            while(ptr != NULL){
                ptr->binding = i;
                i++;
                ptr = ptr->next;
            }
        }else{
            printf("funcTion lookUP failed in GST....NOT_FOUND...!!!...EXITing...\n");
            exit(0);
        }
    }


    int checkEquivalenceParamDeclDef(char* funcName, paramList lst1, int defRetType, node body){
        SymbolTableEntry ste = lookUp(funcName, 1);
        
        int i = 1;

        if(ste!=NULL){
            paramList lst2 = ste->param;
            paramList tmp1 = lst1;
            paramList tmp2 = lst2;

            if(ste->type  !=  defRetType){
                printf("Function RET_TYPE in def and dec of func %s different...!!! EXITing...\n", funcName);
                exit(0);
                return 0;
            }

            if(body->nodetype == CONNECTOR){
                if(defRetType != ((body->right)->left)->type){
                    printf("Type of RET_EXPR diff from decl and def in function %s ...!!! EXITing...\n", funcName);
                    exit(0);
                    return 0;
                }
            }
            else{           // if not CONNECTOR then must be RETURN
                if(defRetType != (body->left)->type){
                    printf("Type of RET_EXPR diff from decl and def in function %s ...!!! EXITing...\n", funcName);
                    exit(0);
                    return 0;
                }
            }

            while(tmp1!=NULL && tmp2!=NULL){
                if(tmp1->type != tmp2->type){
                    i = 0;
                    break;
                }
                if(strcmp(tmp1->name, tmp2->name)!=0){
                    i = 0;
                    break;
                }
            }

            if((tmp1 == NULL && tmp2!=NULL)  || (tmp1 != NULL && tmp2==NULL))
                i = 0;


            if(i == 0){
                printf("Either type or num of params diff in decl and defn of func '%s'...!!! ...exiting....\n", funcName);
                exit(0);
                return 0;
            }

            return i;

        }else{
            printf("Function '%s' not declared but defined...!!! ...exiting....\n", funcName);
            exit(0);
            return -1;
        }
    }





    int checkEquivalenceParamArg(char* funcName, SymbolTableEntry argList){
        paramList tmp1;
        node tmp2;
        
        int ParamListSize = 0;
        
        tmp1 = paramHeadPtr;
        while(tmp1 != NULL)
            ParamListSize++;

        tmp2 = argList;
        for(; ParamListSize > 0; ParamListSize--){
            tmp1 = paramHeadPtr;
            for(int j=1; j<ParamListSize; j++)
                tmp1 = tmp1->next;
            if(tmp2 == NULL /*and implicitly tmp1!=NULL*/){        //NOTE: inside tmp1 will not be NULL (as we have aleady clculated oits sie and going in reverse order)
                printf("Mismatch in number of args and params in func %s ...!!! EXITING...\n", funcName);
                exit(0);
                return 0;
            }else if(tmp1->type != tmp2->type){
                printf("Mismatch in type of arg(s) and param(s) in func %s...!!! EXITING...\n", funcName);
                exit(0);
                return 0;
            }
            tmp2 = tmp2->right;
        }

        if(tmp2 != NULL){   //means still something left in arg while param has exhausted
            printf("Mismatch in number of args and params in func %s ...!!! EXITING...\n", funcName);
            exit(0);
            return 0;
        }

        return 1;
    }


    int isPresentInLST(char* varname){
        SymbolTableEntry tmp = Lsymbol_head;
        int i=0;

        while(tmp != NULL){
            if(strcmp(tmp->name, varname) == 0){
                i=1;
                break;
            }
            tmp = tmp->next;
        }

        return i;
    }


    void printParamList(paramList head){
        paramList tmp = head;

        if(tmp == NULL)
            printf(">>PARAM_LST EMPTY<<\n");
        else{
            int count;
            printf(">>Printing PARAM_LST<<\n");
            count = 0;
            while(tmp!=NULL){
                count++;
                printf("\tPARAM_NUM: %d -> paramName: %s    paramType: %d\n", count, tmp->name, tmp->type);
                tmp = tmp->next;
            }
        }
    }

    void printGsymbolTable()        //for DEBUGGING PURPOSES
    {
        SymbolTableEntry tmp = Gsymbol_head;
        int count = 0;
        while (tmp != NULL)
        {
            count++;
            printf("----------------GST_Entry_%d---------------\n", count);
            printf("varname: %s\n", tmp->name);
            printf("type: %d\n", tmp->type);
            if(tmp->size == -1)
            {
                printf("FUNCTION\n");
                printParamList(tmp->param);
            }
            else
                printf("VARIABLE\nsize: %d\n", tmp->size);
            printf("binding: %d\n", tmp->binding);
            printf("\n\n");

            tmp = tmp->next;
        }
    }


    void printLsymbolTable()        //for DEBUGGING PURPOSES
    {
        SymbolTableEntry tmp = Lsymbol_head;
        int count = 0;
        while (tmp != NULL)
        {
            count++;
            printf("----------------LST_Entry_%d---------------\n", count);
            printf("varname: %s\n", tmp->name);
            printf("type: %d\n", tmp->type);
            printf("binding: %d\n", tmp->binding);
            printf("\n\n");

            tmp = tmp->next;
        }
    }




    /*
    node makeLeafNode(int n){
        node tmp = (node)malloc(sizeof(struct tnode));
        tmp->val = n;
        tmp->op = NULL;
        tmp->left = NULL;
        tmp->right = NULL;
        return tmp;
    }

    node makeOperatorNode(char c, node l, node r){
        node tmp= (node)malloc(sizeof(struct tnode));
        tmp->op = (char*)malloc(sizeof(char));
        *(tmp->op) = c;
        tmp->left = l;
        tmp->right = r;
        return tmp; 
    }
    */

    node createTree(int val, int type, char *varname, int nodetype, node left, node right, SymbolTableEntry STptr)       //varname arg will refer to str_val arg in case of STR_LITERAL
    {
        node tmp = (node)malloc(sizeof(struct tnode));
        //tmp->varname = (char*)malloc(sizeof(char));

        switch (nodetype)
        {
        case NUM:
            tmp->val = val;
            tmp->type = type;
            tmp->varname = NULL;
            tmp->nodetype = nodetype;
            tmp->left = NULL;
            tmp->right = NULL;
            tmp->str_val = NULL;
            tmp->STptr = NULL;
            break;

        case STRING_LITERAL:        //varname arg in case of STRING literal contains actual String
            tmp->val = -1;
            tmp->type = type;       //STRING
            tmp->varname = NULL;
            tmp->nodetype = nodetype;   //STRING_LITERAL
            tmp->left = NULL;
            tmp->right = NULL;
            tmp->str_val = substr(varname, 2, strlen(varname)-2);       //memory is also allocated inside substr so is safe
            tmp->STptr = NULL;
            break;

        case ID:
            tmp->val = 0;      //>>>>>>IMP<<<<<LET IT BE 0          // val stores index of value to dereference in ID node_type
            (tmp->type) = type;          //<<<<<<<<<>>>>>>>>>>!!!!!!!!!! MAY NEED TO CHANGE LATER !!!!!!!!!!<<<<<<<<>>>>>>>>>
            tmp->varname = strdup(varname); //try removing dereferencing and see what happens
            tmp->nodetype = ID;
            tmp->left = NULL;
            tmp->right = NULL;
            tmp->str_val = NULL;
            tmp->STptr = NULL;
            break;

        case ARITHOP:
            tmp->val = val;
            tmp->type = INTEGER; //INTEGER upto now
            tmp->varname = NULL;
            tmp->nodetype =     ARITHOP;
            tmp->left = left;
            tmp->right = right;
            tmp->str_val = NULL;
            tmp->STptr = NULL;

            if (tmp->left->type != INTEGER || tmp->right->type != INTEGER)
            { //TYPE_CHK
                printf("TYPE_ERR..!!! ARITHOP expects type INTEGER on LHS and type INTEGER on RHS...\n");
                exit(0);
            }
            break;

        case RELOP:
            tmp->val = val;
            tmp->type = BOOLEAN; //BOOLEAN
            tmp->varname = NULL;
            tmp->nodetype = RELOP;
            tmp->left = left;
            tmp->right = right;
            tmp->str_val = NULL;
            tmp->STptr = NULL;
            if ((tmp->left->type != INTEGER || tmp->right->type != INTEGER)  && (tmp->left->type != STRING || tmp->right->type != STRING))
            { //TYPE_CHK
                printf("TYPE_ERR..!!! RELOP expects type INTEGER  or STRING on both LHS and RHS... found something else \n");
                exit(0);
            }
            break;

        case ASSGNOP:
            tmp->val = val;
            tmp->type = (int)'=';
            tmp->varname = NULL;
            tmp->nodetype = ASSGNOP;
            tmp->left = left;
            tmp->right = right;
            tmp->str_val = NULL;
            tmp->STptr = NULL;

            if (tmp->left->type != tmp->right->type)
            { //TYPE_CHK
                printf("TYPE_ERR..!!! '=' expects ID of same type ads RHS...found different\n");
                exit(0);
            }
            break;

        case READ:
            tmp->val = -1;
            tmp->type = READ;
            tmp->varname = NULL;
            tmp->nodetype = READ;
            tmp->left = left;
            tmp->right = NULL;
            tmp->str_val = NULL;
            tmp->STptr = NULL;
            break;

        case WRITE:
            tmp->val = -1;
            tmp->type = WRITE;
            tmp->varname = NULL;
            tmp->nodetype = WRITE;
            tmp->left = left;
            tmp->right = NULL;
            tmp->str_val = NULL;
            tmp->STptr = NULL;
            if (tmp->left->type != INTEGER  &&  tmp->left->type != STRING)
            { //TYPE_CHK
                printf("TYPE_ERR..!!! write expects INTEGER or STRING... found something else....!!!\n");
                exit(0);
            }
            break;

        case WHILE:
            tmp->val = -1;
            tmp->type = WHILE;
            tmp->varname = NULL;
            tmp->nodetype = WHILE;
            tmp->left = left; //>>>>>>>!!!!!might need to put TYPE_CHK here<<<<<<<<!!!!!!!
            tmp->right = right;
            tmp->str_val = NULL;
            tmp->STptr = NULL;

            if (tmp->left->type != BOOLEAN)
            { //TYPE_CHK
                printf("TYPE_ERR..!!! while expects BOOLEAN found something else....!!!\n");
                exit(0);
            }
            break;

        case BREAK:
            tmp->val = -1;
            tmp->type = BREAK;
            tmp->varname = NULL;
            tmp->nodetype = BREAK;
            tmp->left = NULL;
            tmp->right = NULL;
            tmp->str_val = NULL;
            tmp->STptr = NULL;
            break;

        case CONT:
            tmp->val = -1;
            tmp->type = CONT;
            tmp->varname = NULL;
            tmp->nodetype = CONT;
            tmp->left = NULL;
            tmp->right = NULL;
            tmp->str_val = NULL;
            tmp->STptr = NULL;
            break;

        case IF:
            tmp->val = -1;
            tmp->type = IF;
            tmp->varname = NULL;
            tmp->nodetype = IF;
            tmp->left = left;
            tmp->right = right;
            tmp->str_val = NULL;
            tmp->STptr = NULL;
            
            if (tmp->left->type != BOOLEAN)
            { //TYPE_CHK
                printf("TYPE_ERR..!!! if expects BOOLEAN found something else....!!!\n");
                exit(0);
            }
            break;

        case IFBODY:
            tmp->val = -1;
            tmp->type = IFBODY;
            tmp->varname = NULL;
            tmp->nodetype = IFBODY;
            tmp->left = left;
            tmp->right = right;
            tmp->str_val = NULL;
            tmp->STptr = NULL;
            break;
            
        case ARGLIST:               //takes left as the expr node and right as next arglist node
            tmp->val = -1;
            tmp->type = left->type;
            tmp->varname = NULL;
            tmp->nodetype = ARGLIST;
            tmp->left = left;
            tmp->right = right;
            tmp->STptr = NULL;
            break;

        case FUNCCALL:               //takes left as the expr node and right as next arglist node
            
            checkEquivalenceParamArg(left->varname, right);     //NAME_TYPE_CHK of args and param while calling
            
            tmp->val = -1;
            tmp->type = left->type;     //assuming type of left(ID) has already beeen setup (in yacc)
            tmp->varname = left->varname;       //putting same varname as funcname from left child
            tmp->nodetype = FUNCCALL;
            tmp->left = left;
            tmp->right = right;
            tmp->STptr = left->STptr;     //assuming STptr of left(ID) has already beeen setup (in yacc)
            break;

        case RETURN:                      //left child will be a expression node
            tmp->val = -1;
            tmp->type = left->type;
            tmp->varname = NULL;
            tmp->nodetype = RETURN;
            tmp->left = left;
            tmp->right = NULL;
            tmp->str_val = NULL;
            tmp->STptr = NULL;
            break;

        
        case CONNECTOR:
            tmp->val = -1;
            tmp->type = CONNECTOR;
            tmp->varname = NULL;
            tmp->nodetype = CONNECTOR;
            tmp->left = left;
            tmp->right = right;
            tmp->str_val = NULL;
            tmp->STptr = NULL;
            break;

        default:
            printf("ERROR!!! in creteTree() SWITCH_CASE\n");
            break;
        }

        return tmp;
    }

    /*
    int evaluate(node root){
        if(root->op == NULL)
            return root->val;

        switch(*(root->op)){
            
            case '+'    :   return evaluate(root->left) + evaluate(root->right);
                            break;
            case '-'    :   return evaluate(root->left) - evaluate(root->right);
                            break;
            case '*'    :   return evaluate(root->left) * evaluate(root->right);
                            break;
            case '/'    :   return evaluate(root->left) / evaluate(root->right);
                            break;
            default     :   printf("ERROR in evaluate expr switchcase\n");
                            break;
        }
    }


    void prefixPrint(node root){
        if(root != NULL){
            if(root->op != NULL)
                printf("%c", *(root->op));
            else
                printf("%d", root->val);
            prefixPrint(root->left);
            prefixPrint(root->right);
        }
    }

    void callPrefixPrint(node root){
        prefixPrint(root);
        printf("\n");
    }



    void postfixPrint(node root){
        if(root != NULL){
            postfixPrint(root->left);
            postfixPrint(root->right);
            if(root->op != NULL)
                printf("%c", *(root->op));
            else
                printf("%d", root->val);
        }
    }

    void callPostfixPrint(node root){
        postfixPrint(root);
        printf("\n");
    }
    */





    /*
    int codeGen(node root){
        int reg;
        
        FILE* fw = fopen("a.xsm", "w");
        
        //generating header of XEXE file
        for(int i=1; i<=8; i++)
            if(i==2)
                fprintf(fw, "2056\n");
            else
                fprintf(fw, "0\n");

        fprintf(fw, "MOV SP, 4096\n");    //code to initialize stack from 4096 not 4095 cause one location used for storing result of calculation
        fprintf(fw, "BRKP\n");


        int ret = codeGenAuxillary(root, fw);
        fprintf(fw, "MOV [4096], R%d\n", ret);       //moving result to mem location 4096
        freeReg();                                   //to free the ret reg


        //after this we expet result in R0
        //Wirting code to call PRINT func from library
        reg = getFreeReg();
        fprintf(fw, "MOV R%d, \"Write\"\n", reg);
        fprintf(fw, "PUSH R%d\n", reg);
        fprintf(fw, "MOV R%d, -2\n", reg);
        fprintf(fw, "PUSH R%d\n", reg);
        fprintf(fw, "MOV R%d, [4096]\n", reg);
        fprintf(fw, "PUSH R%d\n", reg);
        fprintf(fw, "PUSH R%d\n", reg);
        fprintf(fw, "PUSH R%d\n", reg);
        fprintf(fw, "CALL 0\n");
        fprintf(fw, "POP R%d\n", reg);
        fprintf(fw, "POP R%d\n", reg);
        fprintf(fw, "POP R%d\n", reg);
        fprintf(fw, "POP R%d\n", reg);
        fprintf(fw, "POP R%d\n", reg);
        freeReg();

        //Wirting code to call EXIT func from library
        reg = getFreeReg();
        fprintf(fw, "MOV R%d, \"Exit\"\n", reg);
        fprintf(fw, "PUSH R%d\n", reg);
        fprintf(fw, "PUSH R%d\n", reg);
        fprintf(fw, "PUSH R%d\n", reg);
        fprintf(fw, "PUSH R%d\n", reg);
        fprintf(fw, "PUSH R%d\n", reg);
        fprintf(fw, "CALL 0\n");
        fprintf(fw, "POP R%d\n", reg);
        fprintf(fw, "POP R%d\n", reg);
        fprintf(fw, "POP R%d\n", reg);
        fprintf(fw, "POP R%d\n", reg);
        fprintf(fw, "POP R%d\n", reg);
        freeReg();

        fclose(fw);
    }



    int codeGenAuxillary(node root, FILE* fw){                     //written in pre-order form so, l will bw lower and r will be greater REG
        int l, r, reg;
        char c;
        if(root->op != NULL){
            l = codeGenAuxillary(root->left, fw);
            r = codeGenAuxillary(root->right, fw);
            c = *(root->op);
            switch (c)
            {
            case '+':
                fprintf(fw, "ADD R%d, R%d\n", l, r);
                break;
            case '-':
                fprintf(fw, "SUB R%d, R%d\n", l, r);
                break;
            case '*':
                fprintf(fw, "MUL R%d, R%d\n", l, r);
                break;
            case '/':
                fprintf(fw, "DIV R%d, R%d\n", l, r);
                break;
            default:
                printf("Error!!!! in codeGen op switch case\n");
                fclose(fw);
                //close the file pointer;
                exit(0);
                break;
            }
            freeReg();
            return l;
        }else{
            reg = getFreeReg();
            fprintf(fw, "MOV R%d, %d\n", reg, root->val);
            return reg;
        }
    }*/

    int codeGen(node root)
    {
        int reg;

        FILE *fw = fopen("a.xsm", "w");

        //generating header of XEXE file
        for (int i = 1; i <= 8; i++)
            if (i == 2)
                fprintf(fw, "2056\n");
            else
                fprintf(fw, "0\n");

        // fprintf(fw, "MOV SP, 4121\n"); //code to initialize stack from 4096 not 4095 cause one location used for storing result of calculation
        fprintf(fw, "MOV SP, %d\n", binding); //code to initialize stack
        fprintf(fw, "BRKP\n");

        int ret = codeGenAuxillary(root, fw);
        //freeReg();                                   //to free the ret reg

        //Wirting code to call EXIT func from library
        reg = getFreeReg();
        fprintf(fw, "MOV R%d, \"Exit\"\n", reg);
        fprintf(fw, "PUSH R%d\n", in Dis reg);
        fprintf(fw, "PUSH R%d\n", reg);
        fprintf(fw, "PUSH R%d\n", reg);
        fprintf(fw, "PUSH R%d\n", reg);
        fprintf(fw, "PUSH R%d\n", reg);
        fprintf(fw, "CALL 0\n");
        fprintf(fw, "POP R%d\n", reg);
        fprintf(fw, "POP R%d\n", reg);
        fprintf(fw, "POP R%d\n", reg);
        fprintf(fw, "POP R%d\n", reg);
        fprintf(fw, "POP R%d\n", reg);
        freeReg();

        fclose(fw);
    }

    //4121
    int codeGenAuxillary(node root, FILE *fw)
    { //written in pre-order form so, l will bw lower and r will be greater REG
        int l, r, reg, lbl1, lbl2;
        char c;

        

        switch (root->nodetype)
        {
        case NUM:
            reg = getFreeReg();
            fprintf(fw, "MOV R%d, %d\n", reg, root->val);
            return reg;
            break;

        case STRING_LITERAL:
            reg = getFreeReg();
            fprintf(fw, "MOV R%d, \"%s\"\n", reg, root->str_val);
            return reg;
            break;

        case ID:

            reg = getFreeReg();
            fprintf(fw, "MOV R%d, %d\n", reg, (root->STptr)->binding);

            if(isPresentInLST(root->varname)==1  &&  root->left == NULL){      //to check is ID is a LOCAL var and not of type array(to deal with case when both local and global with same name but global is array)
                fprintf(fw, "ADD R%d, BP\n", reg);
            }
            else{
                if(root->left != NULL)      //condition when ID is of array type
                {
                    l = codeGenAuxillary(root->left, fw);
                    if (root->left->nodetype == ID)
                    {
                        //reg = getFreeReg();
                        fprintf(fw, "MOV R%d, [R%d]\n", l, l);
                        //l = reg;
                    }
                    fprintf(fw, "ADD R%d, R%d\n", reg, l);
                    freeReg();
                }
            }

            return reg;
            break;

        case ARITHOP:
            l = codeGenAuxillary(root->left, fw);
            if (root->left->nodetype == ID)
            {
                //reg = getFreeReg();
                fprintf(fw, "MOV R%d, [R%d]\n", l, l);
                //l = reg;
            }

            r = codeGenAuxillary(root->right, fw);
            if (root->right->nodetype == ID)
            {
                //reg = getFreeReg();
                fprintf(fw, "MOV R%d, [R%d]\n", r, r);
                //r = reg;
            }
            c = (root->val);
            switch (c)
            {
            case '+':
                //printf("lala...here_3\n");
                fprintf(fw, "ADD R%d, R%d\n", l, r);
                break;
            case '-':
                fprintf(fw, "SUB R%d, R%d\n", l, r);
                break;
            case '*':
                fprintf(fw, "MUL R%d, R%d\n", l, r);
                break;
            case '/':
                fprintf(fw, "DIV R%d, R%d\n", l, r);
                break;
            case '%':
                fprintf(fw, "MOD R%d, R%d\n", l, r);
                break;
            default:
                printf("Error!!!! in codeGenARITHOP op switch case\n");
                fclose(fw);
                //close the file pointer;
                exit(0);
                break;
            }
            freeReg();
            return l;
            break;

        case RELOP:
            l = codeGenAuxillary(root->left, fw);
            if (root->left->nodetype == ID)
            {
                //reg = getFreeReg();
                fprintf(fw, "MOV R%d, [R%d]\n", l, l);
                //l = reg;
            }

            r = codeGenAuxillary(root->right, fw);
            if (root->right->nodetype == ID)
            {
                //reg = getFreeReg();
                fprintf(fw, "MOV R%d, [R%d]\n", r, r);
                //l = reg;
            }
            switch (root->val)
            {
            case LT:
                fprintf(fw, "LT R%d, R%d\n", l, r);
                break;
            case GT:
                fprintf(fw, "GT R%d, R%d\n", l, r);
                break;
            case LE:
                fprintf(fw, "LE R%d, R%d\n", l, r);
                break;
            case GE:
                fprintf(fw, "GE R%d, R%d\n", l, r);
                break;
            case EQ:
                //printf("lala...here\n");
                fprintf(fw, "EQ R%d, R%d\n", l, r);
                break;
            case NE:
                fprintf(fw, "NE R%d, R%d\n", l, r);
                break;
            default:
                printf("Error!!!! in codeGenRELOP op switch case\n");
                fclose(fw);
                //close the file pointer;
                exit(0);
                break;
            }
            freeReg();
            return l;
            break;

        case ASSGNOP:
            l = codeGenAuxillary(root->left, fw);
            r = codeGenAuxillary(root->right, fw);

            if (root->right->nodetype == ID)
            {
                //reg = getFreeReg();
                fprintf(fw, "MOV R%d, [R%d]\n", r, r);
                //l = reg;
            }

            fprintf(fw, "MOV [R%d], R%d\n", l, r);

            freeReg();
            freeReg();          //-------------->>>>>>>>>!!!MIGHT NEED TO REMOVE!!!<<<<<<<<<<<<-----------
            return l; //returning l arbirarily as no use of it
            break;

        case READ:
            l = codeGenAuxillary(root->left, fw);

            reg = getFreeReg();
            fprintf(fw, "MOV R%d, \"Read\"\n", reg);
            fprintf(fw, "PUSH R%d\n", reg);
            fprintf(fw, "MOV R%d, -1\n", reg);
            fprintf(fw, "PUSH R%d\n", reg);
            //fprintf(fw, "MOV R%d, %d\n", reg, (l - 'a' + 4096));
            fprintf(fw, "PUSH R%d\n", l);
            fprintf(fw, "PUSH R%d\n", reg);
            fprintf(fw, "PUSH R%d\n", reg);
            fprintf(fw, "CALL 0\n");
            fprintf(fw, "POP R%d\n", reg);
            fprintf(fw, "POP R%d\n", reg);
            fprintf(fw, "POP R%d\n", reg);
            fprintf(fw, "POP R%d\n", reg);
            fprintf(fw, "POP R%d\n", reg);

            freeReg();
            freeReg();      //-------------->>>>>>>>>!!!MIGHT NEED TO REMOVE!!!<<<<<<<<<<<<-----------

            return l;       //returning l arbirarily as no use of it
            break;

        case WRITE:
            l = codeGenAuxillary(root->left, fw);

            if (root->left->nodetype == ID)
            {
                //reg = getFreeReg();
                fprintf(fw, "MOV R%d, [R%d]\n", l, l);
                //l = reg;
            }

            reg = getFreeReg();
            fprintf(fw, "MOV R%d, \"Write\"\n", reg);
            fprintf(fw, "PUSH R%d\n", reg);
            fprintf(fw, "MOV R%d, -2\n", reg);
            fprintf(fw, "PUSH R%d\n", reg);
            // fprintf(fw, "MOV R%d, R%d", reg, (l-'a'+4096));
            fprintf(fw, "PUSH R%d\n", l);
            fprintf(fw, "PUSH R%d\n", reg);
            fprintf(fw, "PUSH R%d\n", reg);
            fprintf(fw, "CALL 0\n");
            fprintf(fw, "POP R%d\n", reg);
            fprintf(fw, "POP R%d\n", reg);
            fprintf(fw, "POP R%d\n", reg);
            fprintf(fw, "POP R%d\n", reg);
            fprintf(fw, "POP R%d\n", reg);

            freeReg();
            freeReg();
            return l; //returning l arbirarily as no use of it
            break;

        case IF:
            lbl1 = getLabel();
            lbl2 = getLabel();
            l = codeGenAuxillary(root->left, fw);
            fprintf(fw, "JZ R%d, L%d\n", l, lbl1);
            r = codeGenAuxillary((root->right)->left, fw);
            fprintf(fw, "JMP L%d\n", lbl2);
            fprintf(fw, "L%d:\n", lbl1);
            if ((root->right)->right != NULL)
                r = codeGenAuxillary((root->right)->right, fw);
            fprintf(fw, "L%d:\n", lbl2);

            freeReg();
            // freeReg();      //.....>>> MIGHT NEED TO REMOVE <<<<-------------------
            break;

        case WHILE:
            lbl1 = getLabel();
            lbl2 = getLabel();
            pushLoop();
            loop_stack[0][loop_stack_count] = lbl1;
            loop_stack[1][loop_stack_count] = lbl2;
            fprintf(fw, "L%d:\n", lbl1);
            l = codeGenAuxillary(root->left, fw);
            fprintf(fw, "JZ R%d, L%d\n", l, lbl2);
            r = codeGenAuxillary(root->right, fw);
            fprintf(fw, "JMP L%d\n", lbl1);
            fprintf(fw, "L%d:\n", lbl2);

            popLoop();
            freeReg();
            break;

        case BREAK:
            if (loop_stack_count >= 0)
                fprintf(fw, "JMP L%d\n", loop_stack[1][loop_stack_count]);
            break;

        case CONT:
            if (loop_stack_count >= 0)
                fprintf(fw, "JMP L%d\n", loop_stack[0][loop_stack_count]);
            break;


        case ARGLIST:

            if(root != NULL){
                l = codeGenAuxillary(root->left, fw);
                if (root->left->nodetype == ID)
                {
                    //reg = getFreeReg();
                    fprintf(fw, "MOV R%d, [R%d]\n", l, l);
                    //l = reg;
                }

                fprintf(fw, "PUSH R%d\n", l);

                freeReg();          //----!!! might have to change order with codeGenAux

                codeGenAuxillary(root->right, fw);
            }
            break;



        case FUNCCALL:
            int i, regCountBackup;
            for(i=0; i<regCount; i++)           //-----BACKUP REGS in use in current function-----
                fprintf(fw, "PUSH R%d\n", i);


            regCountBackup = regCount;          //since all regs used already pushed we can start from R0 to evaluate args
            regCount = 0;

            r = codeGenAuxillary(root->right, fw);      //this will push Evaluate and push ARGS 
            
            regCount = regCountBackup;

            fprintf(fw, "PUSH R0\n");           //pushing empty space for RET
            fprintf(fw, "CALL F%d\n", root->STptr->binding);
            r = getFreeReg();

            fprintf(fw, "POP R%d\n", r);        //poping the RET_VAL

            paramList tmp = root->STptr->param;
            while(tmp != NULL){
                fprintf(fw, "POP R0\n");        //popping the pushed args
                tmp = tmp->next;
            }

            //NOTE we have got an extra REG now and we dont wanna pop that
            for(i=regCount-2; i>=0; i--)           //-----RESTORE REGS in use in current function-----
                fprintf(fw, "POP R%d\n", i);

            break;



        case RETURN:
            l = codeGenAuxillary(root->left, fw);
            if (root->left->nodetype == ID)
            {
                //reg = getFreeReg();
                fprintf(fw, "MOV R%d, [R%d]\n", l, l);
                //l = reg;
            }
            fprintf(fw, "MOV [BP-2], R%d\n", l);

            freeReg();
            break;


        case CONNECTOR:
            l = codeGenAuxillary(root->left, fw);
            r = codeGenAuxillary(root->right, fw);
            return l; //returning l arbirarily as no use of it
            break;

        default:
            printf("ERROR....!!! In codeGenAuxillary() switch case...\n");
            break;
        }
    }






    char *substr(char *string, int position, int length)        //substr func
    {
    char *pointer;
    int c;
    
    pointer = malloc(length+1);
    
    if (pointer == NULL)
    {
        printf("Unable to allocate memory.\n");
        exit(0);
    }
    
    for (c = 0 ; c < position -1 ; c++) 
        string++; 
    
    for (c = 0 ; c < length ; c++)
    {
        *(pointer+c) = *string;      
        string++;   
    }
    
    *(pointer+c) = '\0';
    
    return pointer;

    }