%{
#include <stdio.h>
#include "structures.h"
int yylex(void);
void yyerror(char *);
extern FILE* yyin;

%}

%union{
	int i;
	double d;
	bool b;
	char * s;
	TreeNode * node;
}

	/*token set*/

%token <i> INT_VAL
%token <d> DOUBLE_VAL
%token <b> BOOL_VAL
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

%token UM    // unary minus
%token STMNT1
%token ASSI_LIST
%token DECL_LIST

%type <node> list statement expr assi_stmnt decl_stmnt assi_list decl_list switch_body case

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

list : statement list 					{ $$ = newLIST($1, $2); }
	 |									{ $$ = NULL; }
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
 	 | INT_VAL							{ $$ = newNUM($1); }
 	 | DOUBLE_VAL						{ $$ = newNUM($1); }
 	 | ID 								{ $$ = newID($1); }
 	 ;

assi_stmnt : ID '=' expr				{ $$ = newSTMNT1($1, $3); }
		   ;

decl_stmnt : ID_TYPE assi_stmnt			{ $$ = $2; }
		   ;

statement : assi_stmnt ';'											  { $$ = $1; }
		  | decl_stmnt ';'											  { $$ = $1; }
		  | CONST decl_stmnt';'										  { $$ = $2; }
		  | ID_TYPE ID ';' 					 						  { $$ = newSTMNT1($1,NULL); }
		  | IF expr ':' '{' list '}'								  { $$ = newFLOW(IF, $2, $5, NULL); }
		  | IF expr ':' '{' list '}' ELSE '{' list '}'		          { $$ = newFLOW(IF, $2, $5, $9); }
		  | WHILE expr ':' '{' list '}'								  { $$ = newFLOW(WHILE, $2, $5, NULL); }
		  | REPEAT '{' list '}' UNTILL expr ':'						  { $$ = newFLOW(REPEAT, $6, $3, NULL); }
		  | FOR '(' decl_list ';' expr ';' assi_list ')' '{' list '}' { $$ = newFOR($3, $5, $7, $10); }
		  | SWITCH '[' expr ']' '{' switch_body '}'					  { $$ = newSWITCH($3, $6); }
		  | BREAK ';'  												  { $$ = newNODE(BREAK); }
		  ;


		 
assi_list : assi_stmnt assi_list      				{ $$ = newALIST($1, $2); }
		  | ',' assi_list 							{ $$ = $2; }
		  |											{ $$ = NULL; }
		  ;

decl_list : ID_TYPE assi_list 						{ $$ = $2; }
		  ;


switch_body : case switch_body 						{ $$ = newSBODY($1, $2); }
			| DEFAULT '\n' list 					{ $$ = newCASE(DEFAULT, NULL, $3); }
			|										{ $$ = NULL; }
			;

case : CASE '[' expr ']' '\n' list 					{ $$ = newCASE(CASE, $3, $6); }
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