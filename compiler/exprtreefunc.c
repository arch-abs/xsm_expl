// MIGHT NEED TO INCLUDE exprtreedecl.h here
//#include "exprtreedecl.h"

int regCount = 0;               //might need to change this to array based in future

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
}