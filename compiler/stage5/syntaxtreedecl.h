
//NUM END _BEGIN READ WRITE ID alreafy have unique integer identifiers as declared as TOKENS in YACC

//#define INTEGER 0         //defined as token in stage 4
#define ARITHOP 1
#define PLUS (int)'+'
#define MINUS (int)'-'
#define DIV (int)'/'
#define MUL (int)'*'
#define ASSGNOP (int)'='
#define CONNECTOR 2

#define RELOP 3        //for nodetype
#define BOOLEAN 4      //for type

#define IFBODY 5
// #define LT 4        //type for <
// #define GT 5        //type for >
// #define LE 6        //type for <=
// #define GE 7        //type for >=
// #define EQ 8        //type for ==
// #define NE 9        //type for !=





int line;



struct paramListNode
{
    int type;
    char* name;
    struct paramListNode* next;
};
typedef struct paramListNode* paramList;


struct Gsymbol{

    // * Identify Array as size >= 1  AND  param == NULL
    // * Identify simple VAR as size == 1  AND  param == NULL
    // * Identify FUNC as size = -1


    char* name;                 // name of the variable
    int type;                   // type of the variable
    int size;                   // <<USED ONLY FOR VARs>> size of the type of the variable
    int binding;                // stores the STATIC memory address allocated to the VAR  or LABEL binding num for FUNC...in form of <F NUM  
    paramList param;            // <<USED_ONLY_FOR_FUNC>> parameter list associated with function
    struct Gsymbol* next;       // pointer to next entry in the symbol table
};
typedef struct Gsymbol* Gsymbol_entry;


struct tnode{
    int val;    // val stores index of value to dereference in ID node_type
    int type;   //type of variable
    //char* op;
    char* varname;
    char* str_val;
    int nodetype;
    struct tnode* left;
    struct tnode* right;

    Gsymbol_entry GSTptr;
    
};
typedef struct tnode* node;


// node makeLeafNode(int n);
// node makeOperatorNode(char c, node l, node r);
// int evaluate(node root);
// void callPrefixPrint(node root);
// void callPostfixPrint(node root);

char *substr(char *string, int position, int length);  //substr function

int codeGenAuxillary(node root, FILE* fw);
int codeGen(node root);

node createTree(int val, int type, char* varname, int nodetype, node left, node right, Gsymbol_entry GSTptr);       //varname arg will refer to str_val arg in case of STR_LITERAL