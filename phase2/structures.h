
typedef struct TreeNode {
	int NodeType;        
}TreeNode;


typedef struct Double {
	int NodeType;
	int linenum;     
	double d;
}Double;

typedef struct Int
{
	int NodeType;
	int linenum;
	int i;
}Int;


typedef struct Bool {
	int NodeType;
	int linenum;     
	int b;
}Bool;


typedef struct String
{
	int NodeType;
	int linenum;
	char s[50];
}String;

/*
typedef struct Char 
{
	int NodeType;
	int linenum;
	char c;
}Char;
*/

typedef	struct Id {
	int NodeType;
	char name[50];
	int linenum;
}Id;


typedef struct List {
	int NodeType;
	TreeNode * statement;   // statement 
	TreeNode * list;    // list of next statements
}List;


typedef struct Flow {   // while, if , repeat
	int NodeType;
	TreeNode * cond;
	TreeNode * if_brnch;    // used in case of if , while, repeat
	TreeNode * els_brnch;    // used in else branch only
}Flow;


typedef struct For {
	int NodeType;
	TreeNode * decl_list;     // declaration list
	TreeNode * cond;   		  // stop condition
	TreeNode * assi_list;     // assinment list
	TreeNode * body;
}For;


typedef	struct Switch {
	int NodeType;
	TreeNode * exp;
	TreeNode * body;
}Switch;


typedef struct Exp {   // use l only for unary operators and use left & right for binary operators
	int NodeType;
	int linenum;
	TreeNode * lhs;
	TreeNode * rhs;
}Exp;


typedef struct Stmnt {   // for first 4 types of statements only
	int NodeType;
	char type[10];
	int con;    //constant or not
	TreeNode * Id;
	TreeNode * rhs; 
}Stmnt;


typedef struct Assi_list
{
	int NodeType;
	TreeNode * astmnt;   // assingment statement 
	TreeNode * alist;	 // assignment list
}Assi_list;

typedef struct Decl_list
{
	int NodeType;
	TreeNode * alist;
}Decl_list;


typedef struct Swbody
{
	int NodeType;
	TreeNode * case_block;
	TreeNode * sbody;   // continue switch body
}Swbody;


typedef struct Case
{
	int NodeType;
	TreeNode * case_exp;
	TreeNode * case_list;
}Case;


typedef struct Symbol
{
	char name[50];
	int def_line;    //line where variable is defined
	int init_line;    //line where variable is initialized
	char type[10];
	int con;     // constant or not
}Symbol;

typedef struct Sym_table Sym_table;

struct Sym_table
{
	Symbol symbols[100];  		//array of symbols
	int count;
};



//-------------------------------Tree functions------------------------------------------
TreeNode * newNODE(int type);
TreeNode * newINT(int value, int linenum);
TreeNode * newDOUBLE(double value, int linenum);
TreeNode * newBOOL(int value, int linenum);
TreeNode * newSTRING(char * value, int linenum);
//TreeNode * newCHAR(char value, int linenum);
TreeNode * newID(char * name, int linenum);
TreeNode * newEXP(int type, TreeNode * left, TreeNode * right, int linenum);
//TreeNode * newASTMNT(char * type, char * id, TreeNode * rhs);
//TreeNode * newDSTMNT(char * type, TreeNode * astmnt);
TreeNode * newSTMNT(int num,...);
TreeNode * newFLOW(int type, TreeNode* cond, TreeNode* if_brnch, TreeNode* el_brnch);
TreeNode * newFOR(TreeNode * decl_list, TreeNode * cond, TreeNode * assi_list, TreeNode * body);
TreeNode * newSWITCH(TreeNode * exp, TreeNode * sw_body);
TreeNode * newCASE(int type, TreeNode * c_exp, TreeNode * c_list);
TreeNode * newSBODY( TreeNode * case_block, TreeNode * sw_body);
TreeNode * newALIST(TreeNode * astmnt, TreeNode * alist);
TreeNode * newDLIST(char* type, TreeNode * alist);
TreeNode * newLIST(TreeNode * st, TreeNode * l);


void assi_stmnt_semantics(TreeNode * stmnt);
void decl_assi_stmnt_semantics(TreeNode * stmnt);
void decl_stmnt_semantics(TreeNode * stmnt);
void const_decl_stmnt_semantics(TreeNode * stmnt);
void id_semantics(TreeNode * id);
void print_symbol(Symbol s);
int exp_semantics(TreeNode* exp);
int convert_chart_to_intt(char* buff);
void flow_semantics(TreeNode * flow);
void for_semantics(TreeNode * for_obj);
void decl_list_semantics(TreeNode * assi_list);
void switch_semantics(TreeNode * switch_obj);

//-----------------------------Handling symbol table--------------------------------------

//void extend_table();
void add_symbol(Symbol S);
int update_symbol(Symbol s);
Symbol get_symbol(char * name);
void generate_symbols_file();

//------------------------------Generating code--------------------------------------------
void analyzeList (TreeNode * root, char * c);
void analyzeStmnt(TreeNode * stmnt, char * c);
void analyzeAssignStmnt( TreeNode * stmnt);
void analyzeExp(TreeNode * stmnt, char * rhs);
void analyzeFlow(TreeNode * stmnt);
void analyzeFor(TreeNode * stmnt);
void analyzeDecList(TreeNode * stmnt);
void analyzeAssignList(TreeNode * stmnt);
void analyzeBreak(char * c);
void analyzeSwitch(TreeNode * stmnt);
void analyzeSBody(TreeNode * stmnt, char * ID, char * c);
void analyzeCase(TreeNode * stmnt, char * ID, char * c1);