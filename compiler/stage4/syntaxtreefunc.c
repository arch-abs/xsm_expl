#include <string.h>
// MIGHT NEED TO INCLUDE exprtreedecl.h here
// #include "syntaxtreedecl.h"
#include "y.tab.h"

int regCount = 0; //might need to change this to array based in future
int lblCount = -1;

int loop_stack_count = -1;

int TYPE;

int binding = 4095;

Gsymbol_entry Gsymbol_head = NULL;

void pushLoop()
{
    loop_stack_count++;
}

void popLoop()
{
    if (loop_stack_count <= -1)
        printf("ERR...!!! Loop stack count trying to over pop...\n");
    else
        loop_stack_count--;
}

int loop_stack[2][1000]; //0 is for entry point lbl & 1 is for exit pt label

Gsymbol_entry lookUp(char *name)
{
    if (Gsymbol_head == NULL)
    {
        printf("ERR...!!! Trying to LookUp in EMPTY GSymbol Table...!!!\n");
        return NULL;
    }
    Gsymbol_entry tmp = Gsymbol_head;
    while (tmp != NULL)
    {
        if (strcmp(tmp->name, name) == 0)
            return tmp;
        tmp = tmp->next;
    }

    printf("ERR...!!! Entry not found in GSymbol Table...!!!\n");
    return NULL;
}

void install(char *name, int type, int size)
{
    Gsymbol_entry new = (Gsymbol_entry)malloc(sizeof(struct Gsymbol));
    Gsymbol_entry tmp = Gsymbol_head;
    new->name = name;
    new->type = type;
    new->size = size;
    new->next = NULL;

    if (tmp == NULL)
    {
        binding++;
        new->binding = binding;
        Gsymbol_head = new;
    }
    else
    {
        while (tmp->next != NULL)
        {
            if (strcmp(tmp->name, name) == 0)
            {
                printf("ERR..!!! Variable redeclared... (printing from install())\n");
                exit(0);
            }
            tmp = tmp->next;
            binding = binding + tmp->size;
        }
        binding++;
        new->binding = binding;
        tmp->next = new;
    }
}



void printGsymbolTable()        //for DEBUGGING PURPOSES
{
    Gsymbol_entry tmp = Gsymbol_head;
    int count = 0;
    while (tmp != NULL)
    {
        count++;
        printf("----------------GST_Entry_%d---------------\n", count);
        printf("varname: %s\n", tmp->name);
        printf("type: %d\n", tmp->type);
        printf("size: %d\n", tmp->size);
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

node createTree(int val, int type, char *varname, int nodetype, node left, node right, Gsymbol_entry GSTptr)       //varname arg will refer to str_val arg in case of STR_LITERAL
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
        tmp->GSTptr = NULL;
        break;

    case STRING_LITERAL:        //varname arg in case of STRING literal contains actual String
        tmp->val = -1;
        tmp->type = type;       //STRING
        tmp->varname = NULL;
        tmp->nodetype = nodetype;   //STRING_LITERAL
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->str_val = substr(varname, 2, strlen(varname)-2);       //memory is also allocated inside substr so is safe
        tmp->GSTptr = NULL;
        break;

    case ID:
        tmp->val = 0;      //>>>>>>IMP<<<<<LET IT BE 0          // val stores index of value to dereference in ID node_type
        (tmp->type) = type;          //<<<<<<<<<>>>>>>>>>>!!!!!!!!!! MAY NEED TO CHANGE LATER !!!!!!!!!!<<<<<<<<>>>>>>>>>
        tmp->varname = strdup(varname); //try removing dereferencing and see what happens
        tmp->nodetype = ID;
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->str_val = NULL;
        tmp->GSTptr = NULL;
        break;

    case ARITHOP:
        tmp->val = val;
        tmp->type = INTEGER; //INTEGER upto now
        tmp->varname = NULL;
        tmp->nodetype = ARITHOP;
        tmp->left = left;
        tmp->right = right;
        tmp->str_val = NULL;
        tmp->GSTptr = NULL;

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
        tmp->GSTptr = NULL;
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
        tmp->GSTptr = NULL;

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
        tmp->GSTptr = NULL;
        break;

    case WRITE:
        tmp->val = -1;
        tmp->type = WRITE;
        tmp->varname = NULL;
        tmp->nodetype = WRITE;
        tmp->left = left;
        tmp->right = NULL;
        tmp->str_val = NULL;
        tmp->GSTptr = NULL;
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
        tmp->GSTptr = NULL;

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
        tmp->GSTptr = NULL;
        break;

    case CONT:
        tmp->val = -1;
        tmp->type = CONT;
        tmp->varname = NULL;
        tmp->nodetype = CONT;
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->str_val = NULL;
        tmp->GSTptr = NULL;
        break;

    case IF:
        tmp->val = -1;
        tmp->type = IF;
        tmp->varname = NULL;
        tmp->nodetype = IF;
        tmp->left = left;
        tmp->right = right;
        tmp->str_val = NULL;
        tmp->GSTptr = NULL;
        
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
        tmp->GSTptr = NULL;
        break;
        
    case CONNECTOR:
        tmp->val = -1;
        tmp->type = CONNECTOR;
        tmp->varname = NULL;
        tmp->nodetype = CONNECTOR;
        tmp->left = left;
        tmp->right = right;
        tmp->str_val = NULL;
        tmp->GSTptr = NULL;
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
        fprintf(fw, "MOV R%d, %d\n", reg, (root->GSTptr)->binding);

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