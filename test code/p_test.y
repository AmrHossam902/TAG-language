%{
#include <stdio.h>
int yylex(void);
void yyerror(char *);
extern FILE* yyin;

typedef struct TreeNode {
	int NodeType;
	TreeNode * tn;
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

typedef struct List {
	int NodeType;
	Stmnt * st;
	List * l;
}List;

typedef struct Flow {   // while, if , repeat
	int NodeType;
	exp * cond;
	List * if_brnch;    // used in case of if , while, repeat
	List * el_brnch;    // used in else branch only
}Flow;

typedef struct exp {
	int NodeType;
	exp * l;
	exp * r;
}exp;

typedef struct 


%}

%union{
	int i;
	double d;
	bool b;
	char * s;
	tree * node;
}

	/*token set*/

%token <i> INT_VAL
%token <d> DOUBLE_VAL
%token <b> BOOL_VAL
%token ID
%token ID_TYPE
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

list : 
	 | statement list
	 ;


expr : '(' expr ')'	 
	 | expr '+' expr			
	 | expr '-' expr			
	 | expr '/' expr			
	 | expr '*' expr
 	 |'-' expr	 %prec UMINUS
	 | expr AND expr			
 	 | expr OR expr			
	 | expr XOR expr			
	 | expr CMP1 expr
	 | expr CMP2 expr		
	 | '!' expr	 %prec UMINUS
 	 | BOOL_VAL
 	 | INT_VAL
 	 | DOUBLE_VAL
 	 | ID
 	 ;

assi_stmnt : ID '=' expr
		   ;
decl_stmnt : ID_TYPE assi_stmnt
		   ;
statement : assi_stmnt ';'
		  | decl_stmnt ';'
		  | CONST decl_stmnt';'
		  | ID_TYPE ID ';' 
		  | IF expr ':' '{' list '}'
		  | IF expr ':' '{' list '}' ELSE '{' list '}'
		  | WHILE expr ':' '{' list '}'
		  | REPEAT '{' list '}' UNTILL expr ':'
		  | FOR '(' decl_list ';' expr ';' assi_list ')' '{' list '}'
		  | SWITCH expr ':' '{' switch_body '}'
		  ;


		 
assi_list : assi_stmnt assi_list
		  | ',' assi_list
		  |
		  ;

decl_list : ID_TYPE assi_list
		  ;




switch_body : DEFAULT ':' '\n' list
			| case_stmnt list BREAK switch_body
			;

case_stmnt : CASE INT_VAL ':' '\n' list BREAK
		   | CASE DOUBLE_VAL ':' '\n' list BREAK
		   | CASE BOOL_VAL ':' '\n' list BREAK
		   ;





%%s
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