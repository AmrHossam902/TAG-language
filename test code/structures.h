
typedef struct TreeNode {
	int NodeType;        
}TreeNode;


typedef struct Number {
	int NodeType;     
	int i;
	double d;
}Number;


typedef struct Boolean {
	int NodeType;      
	bool b;
}Boolean;


typedef	struct Id {
	int NodeType;
	char * name = "";
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
	TreeNode * next;
	TreeNode * astmnt;   // assingment statement 
	TreeNode * alist;	 // assignment list
}Assi_list;




typedef struct Swbody
{
	int NodeType;
	TreeNode * case_list;
	TreeNode * list;    // body of each case
	TreeNode * sbody;   // continue switch body
}Swbody;


typedef struct Case
{
	int NodeType;
	TreeNode * case_exp;
	TreeNode * case_list;
};