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
#define max_syn_errors_count 20

int error_count = 0;   //syntax error count
int tmp_counter = 1;    //counter for the temp variables
int loop_counter = 1;    //counter for the loop variables
int sem_error_count = 0;
extern int yylineno;

Sym_table table;
TreeNode * program = NULL;

FILE * sem_errors_file;
FILE * syn_errors_file;
FILE * interm_lang_file;
FILE * analysis_file;
%}

%union{
	int i;
	double d;
	char s[100];
	TreeNode * node;
}

	/*token set*/

%token <i> INT_VAL
%token <d> DOUBLE_VAL
%token <i> BOOL_VAL
%token <s> ID
%token <s> ID_TYPE
%token <s> STRING_VAL
%token UNKNOWN

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

%type <node> list statement expr assi_stmnt decl_stmnt assi_list decl_list switch_body case_block susp

	/*operators precedence & associativity*/
%right "="
%left OR   
%left AND
%left XOR
%left EE NE       // == , !=  
%left LT GT LE GE       // < , > , <= , >=
%left '+' '-'
%left '/' '*'
%nonassoc '!' UMINUS  /*unary minus*/

%start list

%%

list : statement list 					{ if($1==NULL) { $$ = $2; yyerror(""); } else { fprintf(analysis_file, "list matched"); $$ = newLIST($1, $2); program =$$;} }
	 |									{ fprintf(analysis_file, "empty list matched\n");$$ = NULL; }
	 | susp 							
	 ;


expr : '(' expr ')'	 					{ $$ = $2; }
	 | expr '+' expr					{ $$ = newEXP('+', $1, $3, yylineno); }
	 | expr '-' expr					{ $$ = newEXP('-', $1, $3, yylineno); }
	 | expr '/' expr					{ $$ = newEXP('/', $1, $3, yylineno); }
	 | expr '*' expr					{ $$ = newEXP('*', $1, $3, yylineno); }
 	 |'-' expr	 %prec UMINUS 			{ $$ = newEXP(UMINUS, $2, NULL, yylineno); }
	 | expr AND expr					{ $$ = newEXP(AND,$1, $3, yylineno); }
 	 | expr OR expr						{ $$ = newEXP(OR, $1, $3, yylineno); }
	 | expr XOR expr					{ $$ = newEXP(XOR, $1, $3, yylineno); }
	 | expr EE expr						{ $$ = newEXP(EE, $1, $3, yylineno); }
	 | expr NE expr						{ $$ = newEXP(NE, $1, $3, yylineno); }
	 | expr LT expr						{ $$ = newEXP(LT, $1, $3, yylineno); }
	 | expr GT expr						{ $$ = newEXP(GT, $1, $3, yylineno); }
	 | expr LE expr						{ $$ = newEXP(LE, $1, $3, yylineno); }
	 | expr GE expr						{ $$ = newEXP(GE, $1, $3, yylineno); }
	 | '!' expr	 %prec UMINUS           { $$ = newEXP(NOT, $2, NULL, yylineno); }
 	 | BOOL_VAL							{ $$ = newBOOL($1, yylineno); }
 	 | INT_VAL							{ $$ = newINT($1, yylineno); }
 	 | DOUBLE_VAL						{ $$ = newDOUBLE($1, yylineno); }
 	 | STRING_VAL						{ $$ = newSTRING($1, yylineno); }
 	 | ID 								{ $$ = newID($1, yylineno);  id_semantics($$); }
 	 

 	 | '(' expr error 					{ $$ = NULL; fprintf(syn_errors_file, "E1: right parenthesis is missing at %d : %d\n", @2.last_line, @2.last_column);}
 	 | expr '+' error 					{ $$ = NULL; fprintf(syn_errors_file, "E2: RHS of \'+\' is not a valid expression %d\n", @2.last_line); }
 	 | expr '-' error 					{ $$ = NULL; fprintf(syn_errors_file, "E3: RHS of \'-\' is not a valid expression %d\n", @2.last_line); }
 	 | expr '/' error 					{ $$ = NULL; fprintf(syn_errors_file, "E4: RHS of \'/\' is not a valid expression %d\n", @2.last_line); }
 	 | expr '*' error 					{ $$ = NULL; fprintf(syn_errors_file, "E5: RHS of \'*\' is not a valid expression %d\n", @2.last_line); }
 	 | '-' error 						{ $$ = NULL; fprintf(syn_errors_file, "E6: RHS of unary \'-\' is not a valid expression %d\n", @1.last_line); }
 	 | expr AND error 					{ $$ = NULL; fprintf(syn_errors_file, "E7: RHS of \"&&\" is not a valid expression %d\n", @2.last_line); }
 	 | expr OR error 					{ $$ = NULL; fprintf(syn_errors_file, "E8: RHS of \"||\" is not a valid expression %d\n", @2.last_line); }
 	 | expr XOR error 					{ $$ = NULL; fprintf(syn_errors_file, "E9: RHS of \"^\" is not a valid expression %d\n", @2.last_line); }
 	 | expr EE error 					{ $$ = NULL; fprintf(syn_errors_file, "E10: RHS of \"==\" is not a valid expression %d\n", @2.last_line); }
 	 | expr NE error    				{ $$ = NULL; fprintf(syn_errors_file, "E11: RHS of \"!=\" is not a valid expression %d\n", @2.last_line); }
 	 | expr LT error 					{ $$ = NULL; fprintf(syn_errors_file, "E12: RHS of \"<\" is not a valid expression %d\n", @2.last_line); }
 	 | expr GT error   					{ $$ = NULL; fprintf(syn_errors_file, "E13: RHS of \">\" is not a valid expression %d\n", @2.last_line); }
 	 | expr LE error 					{ $$ = NULL; fprintf(syn_errors_file, "E14: RHS of \"<=\" is not a valid expression %d\n", @2.last_line); }
 	 | expr GE error   					{ $$ = NULL; fprintf(syn_errors_file, "E15: RHS of \">=\" is not a valid expression %d\n", @2.last_line); }
 	 | '!' error  						{ $$ = NULL; fprintf(syn_errors_file, "E16: RHS of \'!\' is not a valid expression %d\n", @1.last_line); }
 	 ; 

assi_stmnt : ID '=' expr				{ if($3 != NULL){ fprintf(analysis_file, "assignment expression matched\n");  $$ = newSTMNT(3, ASSI_STMNT, $1, $3); } 
		    							  else { $$=NULL; fprintf(syn_errors_file, "E17: RHS of \'=\' is not a valid expression %d\n", @1.last_line);}  }
		   ;

decl_stmnt : ID_TYPE assi_stmnt			{ if($2 != NULL) $$ = newSTMNT(3, DECL_ASSI_STMNT, $1, $2); else { $$=NULL; fprintf(syn_errors_file, "Invalid declaration statement at line %d\n", @1.first_line);} }
		   ;

statement : ';'														  { fprintf(analysis_file, "Empty statement\n"); $$ = newSTMNT(1, EMPTY_STMNT);}
		  | assi_stmnt ';'											  { if ($1 != NULL) {$$ = $1; fprintf(analysis_file, "assignment statement matched\n"); assi_stmnt_semantics($$);} else $$ = NULL;  }
		  | decl_stmnt ';'											  { if ($1 != NULL) {$$ = $1; fprintf(analysis_file, "declaration with assignment matched\n"); decl_assi_stmnt_semantics($$);} else $$=NULL; }
		  | CONST decl_stmnt';'										  { if ($2 != NULL) {$$ = newSTMNT(3, CONST_DECL_STMNT, 1, $2); fprintf(analysis_file, "constant declaration statement matched\n"); const_decl_stmnt_semantics($$);} else $$=NULL; }
		  | ID_TYPE ID ';' 					 						  { $$ = newSTMNT(3, DECL_STMNT, $1, $2); fprintf(analysis_file, "declaration statement matched\n"); decl_stmnt_semantics($$); }
		  
		  | IF expr ':' '{' list '}'								  { if($2 !=NULL) {$$ = newFLOW(IF, $2, $5, NULL); fprintf(analysis_file, "IF without else\n"); flow_semantics($$);}
		  																else { $$=NULL; fprintf(syn_errors_file, "E18: Invalid IF statement at  line %d\n", @1.last_line);} }
		  
		  | IF expr ':' '{' list '}' ELSE '{' list '}'		          { if($2 !=NULL) {$$ = newFLOW(IF, $2, $5, $9); fprintf(analysis_file, "IF with else\n"); flow_semantics($$);}
		  																else { $$=NULL; fprintf(syn_errors_file, "E19: Invalid IF statement at  line %d\n", @1.last_line);} }
		  
		  | WHILE expr ':' '{' list '}'								  { if($2 != NULL) {$$ = newFLOW(WHILE, $2, $5, NULL); fprintf(analysis_file, "while loop\n"); flow_semantics($$);}
		  																else { $$=NULL; fprintf(syn_errors_file, "E20: Invalid while statement at  line %d\n", @1.last_line);} }
		  
		  | REPEAT '{' list '}' UNTILL expr ':'						  { if($6 !=NULL) {$$ = newFLOW(REPEAT, $6, $3, NULL); fprintf(analysis_file, "repeat loop\n"); flow_semantics($$);}
		  																else { $$=NULL; fprintf(syn_errors_file, "E21: Invalid repeat statement at  line %d\n", @1.last_line);} }
		  
		  | FOR '(' decl_list ';' expr ';' assi_list ')' '{' list '}' { if($3 != NULL && $5 != NULL && $7 !=NULL) {$$ = newFOR($3, $5, $7, $10); fprintf(analysis_file, "for loop\n"); for_semantics($$);}
		  																else{ $$=NULL;  fprintf(syn_errors_file, "E22: Invalid for statement at  line %d\n", @1.last_line); } }
		 
		  | SWITCH '[' expr ']' '{' switch_body '}'					  { if($3 != NULL && $6 !=NULL) { $$ = newSWITCH($3, $6); fprintf(analysis_file, "switch statement\n"); switch_semantics($$);}
		  																else { $$=NULL; fprintf(syn_errors_file, "E23: Invalid switch statement at  line %d\n", @1.last_line); } }
		  | BREAK ';' 												  { $$ = newNODE(BREAK);}
		  | BREAK error 											  { $$=NULL; fprintf(syn_errors_file, "E24: semicolon missing at line %d\n", @1.last_line); }

		  | assi_stmnt error 										  { $$=NULL; fprintf(syn_errors_file, "E25: semicolon missing at line %d\n", yylineno); }
		  | decl_stmnt error 										  { $$=NULL; fprintf(syn_errors_file, "E26: semicolon missing at line %d\n", yylineno); }
		  | ID_TYPE ID error 										  { $$=NULL; fprintf(syn_errors_file, "E27: semicolon missing at line %d\n", yylineno); }
		  | ID_TYPE error ';'										  { $$=NULL; fprintf(syn_errors_file, "E28: Identifier name is missing at line %d\n", yylineno); }
		  

		  | IF expr ':' '{' list error 								  { $$=NULL; fprintf(syn_errors_file, "E29: right brace expected at end of IF body at line %d\n", yylineno); }
		  | IF expr ':' error list '}'								  { $$=NULL; fprintf(syn_errors_file, "E30: IF branch left brace is missing at line %d\n", ((Exp*)$2)->linenum); }
		  | IF expr error '{' list '}'								  { $$=NULL; fprintf(syn_errors_file, "E31: Colon expected after IF cond. at line %d\n", ((Exp*)$2)->linenum); }	  
		  | IF expr ':' '{' list '}' ELSE '{' list error 		      { $$=NULL; fprintf(syn_errors_file, "E32: else branch right brace is missing at line %d", yylineno); }
		  | IF expr	':' '{' list '}' ELSE error list '}'			  { $$=NULL; fprintf(syn_errors_file, "E33: else branch left brace is missing at line %d", @7.first_line); }
		  | IF expr	':' '{' list error ELSE '{' list '}'			  { $$=NULL; fprintf(syn_errors_file, "E34: IF branch right brace missing at line %d\n", @7.first_line);}
		  | IF expr ':' error list '}' ELSE '{' list '}'			  { $$=NULL; fprintf(syn_errors_file, "E35: IF branch left brace is missing at line %d\n", @3.first_line);}
		  | IF expr error '{' list '}' ELSE '{' list '}'			  { $$=NULL; fprintf(syn_errors_file, "E36: Colon expected after IF cond. at line %d\n", ((Exp*)$2)->linenum);}
		  //| IF expr ':' '{' list '}' error '{' list '}' 			  { $$=NULL; yyerror("EEEE13\n"); fprintf(syn_errors_file, "else keyword is missing at  %d\n", @6.last_line, @6.first_column);}


		  | WHILE expr ':' '{' list error 							{ $$=NULL; fprintf(syn_errors_file, "E37: right brace of while loop body is missing at line%d\n", yylineno); }
		  | WHILE expr ':' error list '}'							{ $$=NULL; fprintf(syn_errors_file, "E38: left brace of while loop body is missing at line%d\n", @3.first_line); }
		  | WHILE expr error '{' list '}' 							{ $$=NULL; fprintf(syn_errors_file, "E39: Colon expected after while cond. at line %d\n", ((Exp*)$2)->linenum); }			
		  

		  | REPEAT '{' list '}' UNTILL expr error 					{ $$=NULL; fprintf(syn_errors_file, "E40: Colon expected after repeat cond at line %d\n", ((Exp*)$6)->linenum);}
		  | REPEAT '{' list '}' error expr ':'						{ $$=NULL; fprintf(syn_errors_file, "E41: Untill keyword is missing after repeat body at line %d\n", @4.first_line);}
		  | REPEAT '{' list error UNTILL expr ':'					{ $$=NULL; fprintf(syn_errors_file, "E42: right brace of repeat loop body is missing at line%d\n", @5.first_line);}
		  | REPEAT error list '}' UNTILL expr ':'					{ $$=NULL; fprintf(syn_errors_file, "E43: right brace of repeat loop body is missing at line%d\n", @1.first_line);}


		  | FOR '(' decl_list ';' expr ';' assi_list ')' '{' list error    { $$=NULL; fprintf(syn_errors_file, "E44: right brace of for loop body is missing at line %d\n", @10.first_line);}
		  | FOR '(' decl_list ';' expr ';' assi_list ')' error list '}'	   { $$=NULL; fprintf(syn_errors_file, "E45: left brace of for loop body is missing at line %d\n", @8.first_line);}
		  | FOR '(' decl_list ';' expr ';' assi_list error '{' list '}'	   { $$=NULL; fprintf(syn_errors_file, "E46: right parenthesis of for loop header is missing at line %d\n", @7.first_line);}
		  | FOR '(' decl_list ';' expr error assi_list ')' '{' list '}'	   { $$=NULL; fprintf(syn_errors_file, "E47: semicolon is missing after for loop stop condition at %d : %d\n", @5.last_line, @5.last_column);}
		  | FOR '(' decl_list error expr ';' assi_list ')' '{' list '}'	   { $$=NULL; fprintf(syn_errors_file, "E48: semicolon is missing after for loop declaration list at %d : %d\n", @3.last_line, @3.last_column);}
		  | FOR error decl_list ';' expr ';' assi_list ')' '{' list '}'    { $$=NULL; fprintf(syn_errors_file, "E49: left parenthesis of for loop header is missing at %d : %d\n", @1.last_line, @1.last_column);}
		  

		  | SWITCH '[' expr ']' '{' switch_body error 					  { $$=NULL; fprintf(syn_errors_file, "E50: right brace of switch body is missing at line %d \n", @6.last_line);} 
		  | SWITCH '[' expr ']' error switch_body '}'					  { $$=NULL; fprintf(syn_errors_file, "E51: left brace of switch body is missing at line %d \n", @4.last_line);} 
		  | SWITCH '[' expr error '{' switch_body '}'					  { $$=NULL; fprintf(syn_errors_file, "E52: right bracket of switch expression is missing at line %d \n", @3.last_line);} 
		  | SWITCH error expr ']' '{' switch_body '}'					  { $$=NULL; fprintf(syn_errors_file, "E53: left bracket of switch expression is missing at line %d \n", @1.last_line);} 

		  ;


		 
assi_list : assi_stmnt ',' assi_list      			{ if($1 !=NULL) { fprintf(analysis_file, "assignment list matched\n");$$ = newALIST($1, $3);}
													  else $$=NULL; } 
		  | assi_stmnt assi_list 					{ $$=NULL; fprintf(syn_errors_file, "E54: comma is missing at line %d \n", @1.first_line); }
		  |											{ $$ = NULL;}
		  ;

decl_list : ID_TYPE assi_list 						{ if($2 != NULL) {$$ = newDLIST($1, $2); decl_list_semantics($2);}
													  else $$=NULL; }
		  ;


switch_body : case_block switch_body 				{ $$ = newSBODY($1, $2); }
			|										{ $$ = NULL; }
			;

case_block : CASE '[' expr ']' list 				{ $$ = newCASE(CASE, $3, $5); }
	 	   | DEFAULT list 							{ $$ = newCASE(DEFAULT, NULL, $2); }
	 	   | CASE '[' expr error list 				{ $$=NULL; fprintf(syn_errors_file, "E55: right bracket of case expression is missing at line %d \n", @3.last_line); }
	 	   | CASE error expr ']' list 				{ $$=NULL; fprintf(syn_errors_file, "E56: left bracket of case expression is missing at line %d \n", @3.last_line);}
	 	   ;

 

susp : '=' expr 							{ $$=NULL; fprintf(syn_errors_file, "E57: Identifier missing at the begining of assign. statement at %d : %d\n",@1.first_line, @1.first_column ); }
	 | '=' expr ';' 						{ $$=NULL; fprintf(syn_errors_file, "E58: Identifier missing at the begining of assign. statement at %d : %d\n",@1.first_line, @1.first_column ); }
	 | expr ':' '{' list '}'				{ $$=NULL; fprintf(syn_errors_file, "E59: IF or While keyword is missing at the begining of assign. statement at %d : %d\n",@1.first_line, @1.first_column ); }
	 | expr ':''{'list'}'ELSE '{' list '}'  { $$=NULL; fprintf(syn_errors_file, "E60: IF keyword is missing at the begining of assign. statement at %d : %d\n",@1.first_line, @1.first_column ); }  
	;
 // syntax error checking





%%
void yyerror(char *s) {

	if( strcmp(s, "syntax error") == 0)  // don't print ugly syntax error
		return;

	error_count++;
	if(error_count >20)
	{
		fclose(sem_errors_file);
		fclose(syn_errors_file);
		printf("your program Exceeded max number of syntax errors, solve them and try again\n");
		printf("program aborted\n");
		exit(0);
	}
}

int main(int argc, char **argv) {
	
	if(argc > 1) {
		if(!(yyin = fopen(argv[1], "r"))) {
			perror(argv[1]);
			return (1);
		}
	}
	
	sem_errors_file = fopen("semantic errors.txt", "w");
	syn_errors_file = fopen("syntax errors.txt", "w");
	analysis_file = fopen("analysis.txt", "w");
	
	yyparse();
	
	fclose(sem_errors_file);
	fclose(syn_errors_file);
	fclose(analysis_file);

	generate_symbols_file(table);

	// if error free generate program
	if(error_count == 0 && sem_error_count == 0)
	{
		interm_lang_file = fopen("intermediate.txt", "w");
		analyzeList(program, NULL);
		fclose(interm_lang_file);
	}
	else
		printf("No code generated, solve errors first\n");
	
	return 0;
}


#include "create.c"
