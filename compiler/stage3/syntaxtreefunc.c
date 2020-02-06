// MIGHT NEED TO INCLUDE exprtreedecl.h here
// #include "syntaxtreedecl.h"
#include "y.tab.h"

int regCount = 0;               //might need to change this to array based in future
int lblCount = -1;

int loop_stack_count = -1;

void pushLoop(){
    loop_stack_count++;
}

void popLoop(){
    if(loop_stack_count <= -1)
        printf("ERR...!!! Loop stack count trying to over pop...\n");
    else
        loop_stack_count--;
}

int loop_stack[2][1000];        //0 is for entry point lbl & 1 is for exit pt label

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




node createTree(int val, int type, char* varname, int nodetype, node left, node right){
    node tmp = (node)malloc(sizeof(struct tnode));
    tmp->varname = (char*)malloc(sizeof(char));

    switch(nodetype){
        case NUM:
            tmp->val = val;
            tmp->type = INTEGER;
            tmp->varname = NULL;
            tmp->nodetype = nodetype;
            tmp->left = NULL;
            tmp->right = NULL;
            break;

        case ID:
            tmp->val = -1;
            (tmp->type) = INTEGER;              //<<<<<<<<<>>>>>>>>>>!!!!!!!!!! MAY NEED TO CHANGE LATER !!!!!!!!!!<<<<<<<<>>>>>>>>>
            *(tmp->varname) = *(varname);       //try removing dereferencing and see what happens
            tmp->nodetype = ID;
            tmp->left = NULL;
            tmp->right = NULL;
            break;

        case ARITHOP:
            tmp->val = val;
            tmp->type = INTEGER;       //INTEGER upto now
            tmp->varname = NULL;
            tmp->nodetype = ARITHOP;
            tmp->left = left;
            tmp->right = right;

            if(tmp->left->type != INTEGER  || tmp->right->type != INTEGER){          //TYPE_CHK
                printf("TYPE_ERR..!!! ARITHOP expects type INTEGER on LHS and type INTEGER on RHS...\n");
                exit(0);
            }
            break;

        case RELOP:
            tmp->val = val;
            tmp->type = BOOLEAN;       //BOOLEAN
            tmp->varname = NULL;
            tmp->nodetype = RELOP;
            tmp->left = left;
            tmp->right = right;

            if(tmp->left->type != INTEGER  || tmp->right->type != INTEGER){          //TYPE_CHK
                printf("TYPE_ERR..!!! RELOP expects type INTEGER on LHS and type INTEGER on RHS...\n");
                exit(0);
            }
            break;
            break;

        case ASSGNOP:
            tmp->val = val;
            tmp->type = (int)'=';
            tmp->varname = NULL;
            tmp->nodetype = ASSGNOP;
            tmp->left = left;
            tmp->right = right;

            if(tmp->left->type != INTEGER  || tmp->right->type != INTEGER){         //TYPE_CHK
                printf("TYPE_ERR..!!! '=' expects ID of type INTEGER on LHS and INTEGER TYPE on RHS...\n");
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
            break;

        case WRITE:
            tmp->val = -1;
            tmp->type = WRITE;
            tmp->varname = NULL;
            tmp->nodetype = WRITE;
            tmp->left = left;
            tmp->right = NULL;
            break;

        case WHILE:
            tmp->val = -1;
            tmp->type = WHILE;
            tmp->varname = NULL;
            tmp->nodetype = WHILE;
            tmp->left = left;           //>>>>>>>!!!!!might need to put TYPE_CHK here<<<<<<<<!!!!!!!
            tmp->right = right;

            if(tmp->left->type != BOOLEAN){      //TYPE_CHK
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
            break;

        case CONT:
            tmp->val = -1;
            tmp->type = CONT;
            tmp->varname = NULL;
            tmp->nodetype = CONT;
            tmp->left = NULL;
            tmp->right = NULL;
            break;

        case IF:
            tmp->val = -1;
            tmp->type = IF;
            tmp->varname = NULL;
            tmp->nodetype = IF;
            tmp->left = left;
            tmp->right = right;

            if(tmp->left->type != BOOLEAN){      //TYPE_CHK
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
            break;

        case CONNECTOR:
            tmp->val = -1;
            tmp->type = CONNECTOR;
            tmp->varname = NULL;
            tmp->nodetype = CONNECTOR;
            tmp->left = left;
            tmp->right = right;
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



int getFreeReg(){
    if(regCount >= 20){
        printf("Error!!!! NO REGS FREE\n");
        exit(0);
        return -1;
    }
    regCount++;
    return (regCount-1);
}




void freeReg(){
    if(regCount > 0)
        regCount--;
    else
    {
        printf("Error!!!! NO REGS to REALEASE\n");
        exit(0);
    }
    
}


int getLabel(){
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





int codeGen(node root){
    int reg;
    
    FILE* fw = fopen("a.xsm", "w");
    
    //generating header of XEXE file
    for(int i=1; i<=8; i++)
        if(i==2)
            fprintf(fw, "2056\n");
        else
            fprintf(fw, "0\n");

    fprintf(fw, "MOV SP, 4121\n");    //code to initialize stack from 4096 not 4095 cause one location used for storing result of calculation
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
int codeGenAuxillary(node root, FILE* fw){                     //written in pre-order form so, l will bw lower and r will be greater REG
    int l, r, reg, lbl1, lbl2;
    char c;

    switch(root->nodetype){
        case NUM:
            reg = getFreeReg();
            fprintf(fw, "MOV R%d, %d\n", reg, root->val);
            return reg;
            break;
        
        case ID:
            // reg = getFreeReg();
            // fprintf(fw, "MOV R%d, %d\n", reg, ((*(root->varname)) - 'a' + 4096) );
            return *(root->varname);
            break;

        case ARITHOP:
            l = codeGenAuxillary(root->left, fw);
            if(root->left->nodetype == ID){
                reg = getFreeReg();
                fprintf(fw, "MOV R%d, [%d]\n", reg, (l -'a' + 4096));
                l = reg;
            }

            r = codeGenAuxillary(root->right, fw);
            if(root->right->nodetype == ID){
                reg = getFreeReg();
                fprintf(fw, "MOV R%d, [%d]\n", reg, (r -'a' + 4096));
                r = reg;
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
            if(root->left->nodetype == ID){
                reg = getFreeReg();
                //printf("lala...here_1\n");
                fprintf(fw, "MOV R%d, [%d]\n", reg, (l -'a' + 4096));
                l = reg;
            }

            r = codeGenAuxillary(root->right, fw);
            if(root->right->nodetype == ID){
                reg = getFreeReg();
                //printf("lala...here_2\n");
                fprintf(fw, "MOV R%d, [%d]\n", reg, (r -'a' + 4096));
                r = reg;
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

            if(root->right->nodetype == ID){
                reg = getFreeReg();
                fprintf(fw, "MOV R%d, [%d]\n", reg, (r -'a' + 4096));
                r = reg;
            }

            fprintf(fw, "MOV [%d], R%d\n", (l-'a'+4096), r);

            freeReg();
            // freeReg();
            return l;       //returning l arbirarily as no use of it
            break;
        
        case READ:
            l = codeGenAuxillary(root->left, fw);

            reg = getFreeReg();
            fprintf(fw, "MOV R%d, \"Read\"\n", reg);
            fprintf(fw, "PUSH R%d\n", reg);
            fprintf(fw, "MOV R%d, -1\n", reg);
            fprintf(fw, "PUSH R%d\n", reg);
            fprintf(fw, "MOV R%d, %d\n", reg, (l-'a'+4096));
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

            return l;       //returning l arbirarily as no use of it
            break;

        case WRITE:
            l = codeGenAuxillary(root->left, fw);

            if(root->left->nodetype == ID){
                reg = getFreeReg();
                fprintf(fw, "MOV R%d, [%d]\n", reg, (l -'a' + 4096));
                l = reg;
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
            return l;       //returning l arbirarily as no use of it
            break;


        case IF:
            lbl1 = getLabel();
            lbl2 = getLabel();
            l = codeGenAuxillary(root->left, fw);
            fprintf(fw, "JZ R%d, L%d\n", l, lbl1);
            r = codeGenAuxillary((root->right)->left, fw);
            fprintf(fw, "JMP L%d\n", lbl2);
            fprintf(fw, "L%d:\n", lbl1);
            if((root->right)->right != NULL)
                r = codeGenAuxillary((root->right)->right, fw);
            fprintf(fw, "L%d:\n", lbl2);

            freeReg();
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
            if(loop_stack_count >= 0)
                fprintf(fw, "JMP L%d\n", loop_stack[1][loop_stack_count]);
            break;

        case CONT:
            if(loop_stack_count >= 0)
                fprintf(fw, "JMP L%d\n", loop_stack[0][loop_stack_count]);
            break;


        case CONNECTOR:
            l = codeGenAuxillary(root->left, fw);
            r = codeGenAuxillary(root->right, fw);
            return l;       //returning l arbirarily as no use of it
            break;

        default:
            printf("ERROR....!!! In codeGenAuxillary() switch case...\n");
            break;

    }

}