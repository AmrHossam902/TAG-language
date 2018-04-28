
typedef struct TreeNode {
	int NodeType;        
}TreeNode;


typedef struct Double {
	int NodeType;     
	double d;
}Double;

typedef struct Int
{
	int NodeType;
	int i;
}Int;


typedef struct Bool {
	int NodeType;      
	int b;
}Bool;


typedef	struct Id {
	int NodeType;
	char * name;
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
	TreeNode * lhs;
	TreeNode * rhs;
}Exp;


typedef struct Stmnt1 {   // for first 4 types of statements only
	int NodeType;
	TreeNode * Id;
	TreeNode * rhs; 
}Stmnt1;


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




TreeNode * newNODE(int type);
TreeNode * newINT(int value);
TreeNode * newDOUBLE(double value);
TreeNode * newBOOL(int value);
TreeNode * newID(char * name);
TreeNode * newEXP(int type, TreeNode * left, TreeNode * right);
TreeNode * newSTMNT1(char * id, TreeNode * rhs);
TreeNode * newFLOW(int type, TreeNode* cond, TreeNode* if_brnch, TreeNode* el_brnch);
TreeNode * newFOR(TreeNode * decl_list, TreeNode * cond, TreeNode * assi_list, TreeNode * body);
TreeNode * newSWITCH(TreeNode * exp, TreeNode * sw_body);
TreeNode * newCASE(int type, TreeNode * c_exp, TreeNode * c_list);
TreeNode * newSBODY( TreeNode * case_block, TreeNode * sw_body);
TreeNode * newALIST(TreeNode * astmnt, TreeNode * alist);
TreeNode * newDLIST(TreeNode * alist);
TreeNode * newLIST(TreeNode * st, TreeNode * l);