struct tnode{
    int val;
    char* op;
    struct tnode* left;
    struct tnode* right;
};

typedef struct tnode* node;


node makeLeafNode(int n);
node makeOperatorNode(char c, node l, node r);
int evaluate(node root);
void callPrefixPrint(node root);
void callPostfixPrint(node root);
int codeGenAuxillary(node root, FILE* fw);
int codeGen(node root);