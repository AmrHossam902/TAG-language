%{
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
int yylex(void);
void yyerror(char *);
extern FILE* yyin;
extern FILE* yyout;
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
%token <s> STRING_VAL

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
 	 | INT_VAL							{ $$ = newINT($1); }
 	 | DOUBLE_VAL						{ $$ = newDOUBLE($1); }
 	 | STRING_VAL						{ $$ = newSTRING($1); }
 	 | ID 								{ $$ = newID($1); }
 	 ;

assi_stmnt : ID '=' expr				{ $$ = newSTMNT1($1, $3); }
		   ;

decl_stmnt : ID_TYPE assi_stmnt			{ $$ = $2; }
		   ;

statement : ';'														  { fprintf(yyout, "%s\n\n", "---------Empty statement---------"); $$ = newSTMNT1(NULL, NULL); }
		  | assi_stmnt ';'											  { $$ = $1; fprintf(yyout, "%s\n\n", "-----------assignment statement----------"); }
		  | decl_stmnt ';'											  { $$ = $1; fprintf(yyout, "%s\n\n", "---------declaration and assignment statement--------"); }
		  | CONST decl_stmnt';'										  { $$ = $2; fprintf(yyout, "%s\n\n", "----------Constant declaration statement--------"); }
		  | ID_TYPE ID ';' 					 						  { $$ = newSTMNT1($2,NULL); fprintf(yyout, "%s\n\n", "--------declaration without initialization--------"); }
		  | IF expr ':' '{' list '}'								  { $$ = newFLOW(IF, $2, $5, NULL); fprintf(yyout, "%s\n\n", "--------IF without else---------"); }
		  | IF expr ':' '{' list '}' ELSE '{' list '}'		          { $$ = newFLOW(IF, $2, $5, $9); fprintf(yyout, "%s\n\n", "---------IF with else--------");}
		  | WHILE expr ':' '{' list '}'								  { $$ = newFLOW(WHILE, $2, $5, NULL); fprintf(yyout, "%s\n\n", "---------while loop-------");}
		  | REPEAT '{' list '}' UNTILL expr ':'						  { $$ = newFLOW(REPEAT, $6, $3, NULL); fprintf(yyout, "%s\n\n", "----------repeat loop---------");}
		  | FOR '(' decl_list ';' expr ';' assi_list ')' '{' list '}' { $$ = newFOR($3, $5, $7, $10); fprintf(yyout, "%s\n\n", "----------for loop--------");}
		  | SWITCH '[' expr ']' '{' switch_body '}'					  { $$ = newSWITCH($3, $6); fprintf(yyout, "%s\n\n", "----------switch statement----------");}
		  | BREAK ';'  												  { $$ = newNODE(BREAK); fprintf(yyout, "%s\n\n", "------------break statement-----------"); }
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

case_block : CASE '[' expr ']' list 				{ $$ = newCASE(CASE, $3, $5); }
	 	   | DEFAULT list 							{ $$ = newCASE(DEFAULT, NULL, $2); }
	 	   ;

%%
void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}

int main(int argc, char **argv) {
	
	if(argc > 1) {
		if(!(yyin = fopen(argv[1], "r"))) {
			perror(argv[1]);
			return 1;
		}
		if(!(yyout = fopen("analysis.txt", "w")))
		{
			perror("analysis.txt");
			return 1;
		}
	}	

	yyparse();
	fclose(yyin);
	fclose(yyout);
	return 0;
}


#include "functions.c"
