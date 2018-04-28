%{
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
int yylex(void);
void yyerror(char *);
extern FILE* yyin;

%}

%union{
	int i;
	double d;
	char * s;
	TreeNode * node;
}

	/*token set*/

%token <i> INT_VAL
%token <d> DOUBLE_VAL
%token <i> BOOL_VAL
%token <s> ID
%token <s> ID_TYPE
%token CONST
%token IF
%token ELSE
%token WHILE
%token FOR
%token REPEAT
%token UNTILL
%token SWITCH
%token CASE
%token DEFAULT
%token BREAK
%token AND
%token OR
%token XOR
%token CMP

 // dummy tokens
%token UM    // unary minus
%token STMNT1
%token ASSI_LIST
%token DECL_LIST
%token SWBODY    //switch body
%token LIST  
%token NOT

%type <node> list statement expr assi_stmnt decl_stmnt assi_list decl_list switch_body case_block

	/*operators precedence & associativity*/
%left CMP2       // == , !=
%left CMP1       // < , > , <= , >=
%left OR   
%left AND
%left XOR
%left '+' '-'
%left '/' '*'
%nonassoc '!' UMINUS  /*unary minus*/
%right "="


%start list

%%

list : statement list 					{ printf("%s\n", "list matched"); $$ = newLIST($1, $2); }
	 |									{ printf("%s\n", "empty list matched");$$ = NULL; }
	 ;


expr : '(' expr ')'	 					{ $$ = $2; }
	 | expr '+' expr					{ $$ = newEXP('+', $1, $3); }
	 | expr '-' expr					{ $$ = newEXP('-', $1, $3); }
	 | expr '/' expr					{ $$ = newEXP('/', $1, $3); }
	 | expr '*' expr					{ $$ = newEXP('*', $1, $3); }
 	 |'-' expr	 %prec UMINUS 			{ $$ = newEXP(UMINUS, $2, NULL); }
	 | expr AND expr					{ $$ = newEXP(AND,$1, $3); }
 	 | expr OR expr						{ $$ = newEXP(OR, $1, $3); }
	 | expr XOR expr					{ $$ = newEXP(XOR, $1, $3); }
	 | expr CMP1 expr					{ $$ = newEXP(CMP1, $1, $3); }
	 | expr CMP2 expr					{ $$ = newEXP(CMP2, $1, $3); }
	 | '!' expr	 %prec UMINUS           { $$ = newEXP(NOT, $2, NULL); }
 	 | BOOL_VAL							{ $$ = newBOOL($1); }
 	 | INT_VAL							{ $$ = newINT($1); }
 	 | DOUBLE_VAL						{ $$ = newDOUBLE($1); }
 	 | ID 								{ $$ = newID($1); }
 	 ;

assi_stmnt : ID '=' expr				{ printf("%s\n", "assi_stmnt matched");  $$ = newSTMNT1($1, $3); }
		   ;

decl_stmnt : ID_TYPE assi_stmnt			{ $$ = $2; }
		   ;

statement : assi_stmnt ';'											  { $$ = $1; printf("%s\n", "assi_stmnt");}
		  | decl_stmnt ';'											  { $$ = $1; printf("%s\n", "decl_stmnt");}
		  | CONST decl_stmnt';'										  { $$ = $2; printf("%s\n", "decl_stmnt with const");}
		  | ID_TYPE ID ';' 					 						  { $$ = newSTMNT1($2,NULL); printf("%s\n", "decl without initialization"); }
		  | IF expr ':' '{' list '}'								  { $$ = newFLOW(IF, $2, $5, NULL); printf("%s\n", "IF without else"); }
		  | IF expr ':' '{' list '}' ELSE '{' list '}'		          { $$ = newFLOW(IF, $2, $5, $9); printf("%s\n", "IF with else");}
		  | WHILE expr ':' '{' list '}'								  { $$ = newFLOW(WHILE, $2, $5, NULL); printf("%s\n", "while loop");}
		  | REPEAT '{' list '}' UNTILL expr ':'						  { $$ = newFLOW(REPEAT, $6, $3, NULL); printf("%s\n", "repeat loop");}
		  | FOR '(' decl_list ';' expr ';' assi_list ')' '{' list '}' { $$ = newFOR($3, $5, $7, $10); printf("%s\n", "for loop");}
		  | SWITCH '[' expr ']' '{' switch_body '}'					  { $$ = newSWITCH($3, $6); printf("%s\n", "switch statement");}
		  | BREAK ';'  												  { $$ = newNODE(BREAK); }
		  ;


		 
assi_list : assi_stmnt assi_list      				{ $$ = newALIST($1, $2); }
		  | ',' assi_list 							{ $$ = $2; }
		  |											{ $$ = NULL; }
		  ;

decl_list : ID_TYPE assi_list 						{ $$ = newDLIST($2); }
		  ;


switch_body : case_block switch_body 				{ $$ = newSBODY($1, $2); }
			| DEFAULT list 							{ $$ = newCASE(DEFAULT, NULL, $2); }
			|										{ $$ = NULL; }
			;

case_block : CASE '[' expr ']' list 					{ $$ = newCASE(CASE, $3, $5); }
	 ;

%%
void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}

int main(int argc, char **argv) {
	
	if(argc > 1) {
		if(!(yyin = fopen(argv[1], "r"))) {
			perror(argv[1]);
			return (1);
		}
	}	

	yyparse();
	return 0;
}


TreeNode * newNODE(int type)
{
	TreeNode * T = malloc(sizeof(TreeNode));
	T->NodeType = type;
	return T;
}


TreeNode * newINT(int value)
{
	Int * I = malloc(sizeof(Int));
	I->NodeType = INT_VAL;
	I->i = value;
	return (TreeNode *) I;
}


TreeNode * newDOUBLE(double value)
{
	Double * D = malloc(sizeof(Double));
	D->NodeType = DOUBLE_VAL;
	D->d = value;
	return (TreeNode *) D;
}


TreeNode * newBOOL(int value)
{
	Bool * B = malloc(sizeof(Bool));
	B->NodeType = BOOL_VAL;
	B->b = value;
	return (TreeNode *) B;
}


TreeNode * newID(char * name)
{
	Id * I = malloc(sizeof(Id));
	I->NodeType = ID;
	I->name = name;
	return (TreeNode *) I;
}


TreeNode * newEXP(int type, TreeNode * left, TreeNode * right)
{
	Exp * E = malloc(sizeof(Exp));
	E->NodeType = type;
	E->rhs = right;
	E->lhs = left;
	return (TreeNode *) E;
}


TreeNode * newSTMNT1(char * id, TreeNode * rhs)
{
	
	Id * I = malloc(sizeof(Id));
	I->name = id;
	I->NodeType = ID;

	Stmnt1 * S = malloc(sizeof(Stmnt1));
	S->NodeType = STMNT1;
	S->Id = (TreeNode *) I;
	S->rhs = rhs;

	return (TreeNode *) S;
}


TreeNode * newFLOW(int type, TreeNode* cond, TreeNode* if_brnch, TreeNode* el_brnch)
{
	Flow * F = malloc(sizeof(Flow));
	F->NodeType = type;
	F->cond = cond;
	F->if_brnch = if_brnch;
	F->els_brnch = el_brnch;

	return (TreeNode *) F;
}


TreeNode * newFOR(TreeNode * decl_list, TreeNode * cond, TreeNode * assi_list, TreeNode * body)
{
	For * F = malloc(sizeof(For));
	F->NodeType = FOR;
	F->decl_list = decl_list;
	F->cond = cond;
	F->assi_list = assi_list;
	F->body = body;

	return (TreeNode *) F;
}


TreeNode * newSWITCH(TreeNode * exp, TreeNode * sw_body)
{
	Switch * S = malloc(sizeof(Switch));
	S->NodeType = SWITCH;
	S->exp = exp;
	S->body = sw_body;

	return (TreeNode *) S;
}


TreeNode * newCASE(int type, TreeNode * c_exp, TreeNode * c_list)
{
	Case * C = malloc(sizeof(Case));
	C->NodeType = type;
	C->case_exp = c_exp;
	C->case_list = c_list;

	return (TreeNode *) C;
}


TreeNode * newSBODY( TreeNode * case_block, TreeNode * sw_body)
{
	Swbody * S = malloc(sizeof(Swbody));
	S->NodeType = SWBODY;
	S->case_block = case_block;
	S->sbody = sw_body;

	return (TreeNode *) S;
}


TreeNode * newALIST(TreeNode * astmnt, TreeNode * alist)
{
	Assi_list * A = malloc(sizeof(Assi_list));
	A->NodeType = ASSI_LIST;
	A->astmnt = astmnt;   
	A->alist = alist;

	return (TreeNode *) A;
}


TreeNode * newDLIST(TreeNode * alist)
{
	Decl_list * D = malloc(sizeof(Decl_list));
	D->NodeType = DECL_LIST;
	D->alist = alist;

	return (TreeNode *) D;
}


TreeNode * newLIST(TreeNode * st, TreeNode * l)
{
	List * L = malloc(sizeof(List));
	L->NodeType = LIST;
	L->statement = st;
	L->list = l;

	return (TreeNode *) L;
}