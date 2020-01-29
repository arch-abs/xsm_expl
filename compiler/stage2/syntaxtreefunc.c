// MIGHT NEED TO INCLUDE exprtreedecl.h here
//#include "syntaxtreedecl.h"
#include "y.tab.h"

int regCount = 0;               //might need to change this to array based in future

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
            (tmp->type) = ID;
            *(tmp->varname) = *(varname);       //try removing dereferencing and see what happens
            tmp->nodetype = ID;
            tmp->left = NULL;
            tmp->right = NULL;
            break;

        case ARITHOP:
            tmp->val = val;
            tmp->type = type;       //INTEGER upto now
            tmp->varname = NULL;
            tmp->nodetype = ARITHOP;
            tmp->left = left;
            tmp->right = right;
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

        case ASSGNOP:
            tmp->val = val;
            tmp->type = (int)'=';
            tmp->varname = NULL;
            tmp->nodetype = ASSGNOP;
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
    int l, r, reg;
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
            r = codeGenAuxillary(root->right, fw);
            if(root->left->nodetype == ID){
                reg = getFreeReg();
                fprintf(fw, "MOV R%d, [%d]\n", reg, (l -'a' + 4096));
                l = reg;
            }
            if(root->right->nodetype == ID){
                reg = getFreeReg();
                fprintf(fw, "MOV R%d, [%d]\n", reg, (r -'a' + 4096));
                r = reg;
            }
            c = (root->val);
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
            return l;       //returning l arbirarily as no use of it
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