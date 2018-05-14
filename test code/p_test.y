%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include<string.h>
#include "structures.h"
int yylex(void);
void yyerror(char *);
extern FILE* yyin;

//----------------------------------Variables-----------------------------------------
#define bucket_size 20
#define not_defined -10
#define not_initialized -10


int error_count = 0;
Sym_table table;
extern int yylineno;
FILE * sem_errors_file;
FILE * syn_errors_file;

%}

%union{
	int i;
	double d;
	char s[100];
	TreeNode * node;
	char c;
}

	/*token set*/

%token <i> INT_VAL
%token <d> DOUBLE_VAL
%token <i> BOOL_VAL
%token <s> ID
%token <s> ID_TYPE
%token <s> STRING_VAL
%token <c> CHAR_VAL

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

 // dummy tokens
%token DECL_STMNT
%token ASSI_STMNT
%token DECL_ASSI_STMNT
%token CONST_DECL_STMNT
%token EMPTY_STMNT

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
 	 | STRING_VAL						{ printf("%s\n", $1);   $$ = newSTRING($1); }
 	 | CHAR_VAL							{ printf("%c\n", $1);  $$ = newCHAR($1); }
 	 | ID 								{ $$ = newID($1);  id_semantics($$); }
 	 ;

assi_stmnt : ID '=' expr				{ printf("%s ID = %s\n", "assi_stmnt matched", $1);  $$ = newSTMNT(3, ASSI_STMNT, $1, $3);}
		   ;

decl_stmnt : ID_TYPE assi_stmnt			{ $$ = newSTMNT(3, DECL_ASSI_STMNT, $1, $2); }
		   ;

statement : ';'														  { printf("%s\n", "Empty statement"); $$ = newSTMNT(1, EMPTY_STMNT);}
		  | assi_stmnt ';'											  { $$ = $1; printf("%s\n", "assi_stmnt"); assi_stmnt_semantics($$);}
		  | decl_stmnt ';'											  { $$ = $1; printf("%s\n", "decl_stmnt"); decl_assi_stmnt_semantics($$);}
		  | CONST decl_stmnt';'										  { $$ = newSTMNT(3, CONST_DECL_STMNT, 1, $2); printf("%s\n", "decl_stmnt with const"); const_decl_stmnt_semantics($$);}
		  | ID_TYPE ID ';' 					 						  { $$ = newSTMNT(3, DECL_STMNT, $1, $2); printf("decl without initialization"); decl_stmnt_semantics($$); }
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
			|										{ $$ = NULL; }
			;

case_block : CASE '[' expr ']' list 					{ $$ = newCASE(CASE, $3, $5); }
	 	   | DEFAULT list 							{ $$ = newCASE(DEFAULT, NULL, $2); }
	 	   ;

%%
void yyerror(char *s) {
	fprintf(stderr, "%s \n", s);
}

int main(int argc, char **argv) {
	
	if(argc > 1) {
		if(!(yyin = fopen(argv[1], "r"))) {
			perror(argv[1]);
			return (1);
		}
	}
	sem_errors_file = fopen("semantic errors.txt", "w");
	yyparse();
	fclose(sem_errors_file);
	generate_symbols_file(table);
	return 0;
}


#include "create.c"
