
//NUM END _BEGIN READ WRITE ID alreafy have unique integer identifiers as declared as TOKENS in YACC

#define INTEGER 0
#define ARITHOP 1
#define PLUS (int)'+'
#define MINUS (int)'-'
#define DIV (int)'/'
#define MUL (int)'*'
#define ASSGNOP (int)'='
#define CONNECTOR 2









struct tnode{
    int val;
    int type;   //type of variable
    //char* op;
    char* varname;
    int nodetype;
    struct tnode* left;
    struct tnode* right;
};

typedef struct tnode* node;


// node makeLeafNode(int n);
// node makeOperatorNode(char c, node l, node r);
// int evaluate(node root);
// void callPrefixPrint(node root);
// void callPostfixPrint(node root);
int codeGenAuxillary(node root, FILE* fw);
int codeGen(node root);

int codeEvaluator(node root);

node createTree(int val, int type, char* varname, int nodetype, node left, node right);