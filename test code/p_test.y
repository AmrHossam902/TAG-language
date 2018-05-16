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

list : statement list 					{ if($1==NULL) $$ = $2; else { printf("%s\n", "list matched"); $$ = newLIST($1, $2); program =$$;} }
	 |									{ printf("%s\n", "empty list matched");$$ = NULL; }
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
 	 

 	 | '(' expr error 					{ $$ = NULL; yyerror("EEEE106\n"); fprintf(syn_errors_file, "right parenthesis is missing at %d : %d\n", @2.last_line, @2.last_column);}
 	 | expr '+' error 					{ $$ = NULL; yyerror("EEEE90\n"); fprintf(syn_errors_file, "RHS of \'+\' is not a valid expression %d\n", @2.last_line); }
 	 | expr '-' error 					{ $$ = NULL; yyerror("EEEE91\n"); fprintf(syn_errors_file, "RHS of \'-\' is not a valid expression %d\n", @2.last_line); }
 	 | expr '/' error 					{ $$ = NULL; yyerror("EEEE92\n"); fprintf(syn_errors_file, "RHS of \'/\' is not a valid expression %d\n", @2.last_line); }
 	 | expr '*' error 					{ $$ = NULL; yyerror("EEEE94\n"); fprintf(syn_errors_file, "RHS of \'*\' is not a valid expression %d\n", @2.last_line); }
 	 | '-' error 						{ $$ = NULL; yyerror("EEEE95\n"); fprintf(syn_errors_file, "RHS of unary \'-\' is not a valid expression %d\n", @1.last_line); }
 	 | expr AND error 					{ $$ = NULL; yyerror("EEEE96\n"); fprintf(syn_errors_file, "RHS of \"&&\" is not a valid expression %d\n", @2.last_line); }
 	 | expr OR error 					{ $$ = NULL; yyerror("EEEE97\n"); fprintf(syn_errors_file, "RHS of \"||\" is not a valid expression %d\n", @2.last_line); }
 	 | expr XOR error 					{ $$ = NULL; yyerror("EEEE98\n"); fprintf(syn_errors_file, "RHS of \"^\" is not a valid expression %d\n", @2.last_line); }
 	 | expr EE error 					{ $$ = NULL; yyerror("EEEE99\n"); fprintf(syn_errors_file, "RHS of \"==\" is not a valid expression %d\n", @2.last_line); }
 	 | expr NE error    				{ $$ = NULL; yyerror("EEEE100\n"); fprintf(syn_errors_file, "RHS of \"!=\" is not a valid expression %d\n", @2.last_line); }
 	 | expr LT error 					{ $$ = NULL; yyerror("EEEE101\n"); fprintf(syn_errors_file, "RHS of \"<\" is not a valid expression %d\n", @2.last_line); }
 	 | expr GT error   					{ $$ = NULL; yyerror("EEEE102\n"); fprintf(syn_errors_file, "RHS of \">\" is not a valid expression %d\n", @2.last_line); }
 	 | expr LE error 					{ $$ = NULL; yyerror("EEEE103\n"); fprintf(syn_errors_file, "RHS of \"<=\" is not a valid expression %d\n", @2.last_line); }
 	 | expr GE error   					{ $$ = NULL; yyerror("EEEE104\n"); fprintf(syn_errors_file, "RHS of \">=\" is not a valid expression %d\n", @2.last_line); }
 	 | '!' error  						{ $$ = NULL; yyerror("EEEE105\n"); fprintf(syn_errors_file, "RHS of \'!\' is not a valid expression %d\n", @1.last_line); }
 	 ; 

assi_stmnt : ID '=' expr				{ if($3 != NULL){ printf("%s ID = %s\n", "assi_stmnt matched", $1);  $$ = newSTMNT(3, ASSI_STMNT, $1, $3); } 
		    							  else { $$=NULL; yyerror("EEEE107\n"); fprintf(syn_errors_file, "RHS of \'=\' is not a valid expression %d\n", @1.last_line);}  }
		   ;

decl_stmnt : ID_TYPE assi_stmnt			{ if($2 != NULL) $$ = newSTMNT(3, DECL_ASSI_STMNT, $1, $2); else { $$=NULL; fprintf(syn_errors_file, "Invalid declaration statement at line %d\n", @1.first_line);} }
		   ;

statement : ';'														  { printf("%s\n", "Empty statement"); $$ = newSTMNT(1, EMPTY_STMNT);}
		  | assi_stmnt ';'											  { if ($1 != NULL) {$$ = $1; printf("assi_stmnt"); assi_stmnt_semantics($$);} else $$ = NULL;  }
		  | decl_stmnt ';'											  { if ($1 != NULL) {$$ = $1; printf("%s\n", "decl_stmnt"); decl_assi_stmnt_semantics($$);} else $$=NULL; }
		  | CONST decl_stmnt';'										  { if ($2 != NULL) {$$ = newSTMNT(3, CONST_DECL_STMNT, 1, $2); printf("%s\n", "decl_stmnt with const"); const_decl_stmnt_semantics($$);} else $$=NULL; }
		  | ID_TYPE ID ';' 					 						  { $$ = newSTMNT(3, DECL_STMNT, $1, $2); printf("decl without initialization"); decl_stmnt_semantics($$); }
		  
		  | IF expr ':' '{' list '}'								  { if($2 !=NULL) {$$ = newFLOW(IF, $2, $5, NULL); printf("%s\n", "IF without else"); flow_semantics($$);}
		  																else { $$=NULL; yyerror("EEEE108\n"); fprintf(syn_errors_file, "Invalid IF statement at  line %d\n", @1.last_line);} }
		  
		  | IF expr ':' '{' list '}' ELSE '{' list '}'		          { if($2 !=NULL) {$$ = newFLOW(IF, $2, $5, $9); printf("%s\n", "IF with else"); flow_semantics($$);}
		  																else { $$=NULL; yyerror("EEEE108\n"); fprintf(syn_errors_file, "Invalid IF statement at  line %d\n", @1.last_line);} }
		  
		  | WHILE expr ':' '{' list '}'								  { if($2 != NULL) {$$ = newFLOW(WHILE, $2, $5, NULL); printf("%s\n", "while loop"); flow_semantics($$);}
		  																else { $$=NULL; yyerror("EEEE109\n"); fprintf(syn_errors_file, "Invalid while statement at  line %d\n", @1.last_line);} }
		  
		  | REPEAT '{' list '}' UNTILL expr ':'						  { if($6 !=NULL) {$$ = newFLOW(REPEAT, $6, $3, NULL); printf("%s\n", "repeat loop"); flow_semantics($$);}
		  																else { $$=NULL; yyerror("EEEE110\n"); fprintf(syn_errors_file, "Invalid repeat statement at  line %d\n", @1.last_line);} }
		  
		  | FOR '(' decl_list ';' expr ';' assi_list ')' '{' list '}' { if($3 != NULL && $5 != NULL && $7 !=NULL) {$$ = newFOR($3, $5, $7, $10); printf("%s\n", "for loop"); for_semantics($$);}
		  																else{ $$=NULL;  yyerror("EEEE111\n"); fprintf(syn_errors_file, "Invalid for statement at  line %d\n", @1.last_line); } }
		 
		  | SWITCH '[' expr ']' '{' switch_body '}'					  { if($3 != NULL && $6 !=NULL) { $$ = newSWITCH($3, $6); printf("%s\n", "switch statement"); switch_semantics($$);}
		  																else { $$=NULL; yyerror("EEEE112\n"); fprintf(syn_errors_file, "Invalid switch statement at  line %d\n", @1.last_line); } }
		  | BREAK ';' 												  { $$ = newNODE(BREAK); }
		  | BREAK error 											  { $$=NULL; yyerror("EEEE1\n"); fprintf(syn_errors_file, "semicolon missing at line %d\n", @1.last_line); }

		  | assi_stmnt error 										  { $$=NULL; yyerror("EEEE1\n"); fprintf(syn_errors_file, "semicolon missing at line %d\n", yylineno); }
		  | decl_stmnt error 										  { $$=NULL; yyerror("EEEE2\n"); fprintf(syn_errors_file, "semicolon missing at line %d\n", yylineno); }
		  | ID_TYPE ID error 										  { $$=NULL; yyerror("EEEE3\n"); fprintf(syn_errors_file, "semicolon missing at line %d\n", yylineno); }
		  | ID_TYPE error ';'										  { $$=NULL; yyerror("EEEE4\n"); fprintf(syn_errors_file, "Identifier name is missing at line %d\n", yylineno); }
		  

		  | IF expr ':' '{' list error 								  { $$=NULL; yyerror("EEEE5\n"); fprintf(syn_errors_file, "right brace expected at end of IF body at line %d\n", yylineno); }
		  | IF expr ':' error list '}'								  { $$=NULL; yyerror("EEEE6\n"); fprintf(syn_errors_file, "IF branch left brace is missing at line %d\n", ((Exp*)$2)->linenum); }
		  | IF expr error '{' list '}'								  { $$=NULL; yyerror("EEEE7\n"); fprintf(syn_errors_file, "Colon expected after IF cond. at line %d\n", ((Exp*)$2)->linenum); }	  
		  | IF expr ':' '{' list '}' ELSE '{' list error 		      { $$=NULL; yyerror("EEEE8\n"); fprintf(syn_errors_file, "else branch right brace is missing at line %d", yylineno); }
		  | IF expr	':' '{' list '}' ELSE error list '}'			  { $$=NULL; yyerror("EEEE10\n"); fprintf(syn_errors_file, "else branch left brace is missing at line %d", @7.first_line); }
		  | IF expr	':' '{' list error ELSE '{' list '}'			  { $$=NULL; yyerror("EEEE11\n"); fprintf(syn_errors_file, "IF branch right brace missing at line %d\n", @7.first_line);}
		  | IF expr ':' error list '}' ELSE '{' list '}'			  { $$=NULL; yyerror("EEEE12\n"); fprintf(syn_errors_file, "IF branch left brace is missing at line %d\n", @3.first_line);}
		  | IF expr error '{' list '}' ELSE '{' list '}'			  { $$=NULL; yyerror("EEEE13\n"); fprintf(syn_errors_file, "Colon expected after IF cond. at line %d\n", ((Exp*)$2)->linenum);}
		  //| IF expr ':' '{' list '}' error '{' list '}' 			  { $$=NULL; yyerror("EEEE13\n"); fprintf(syn_errors_file, "else keyword is missing at  %d\n", @6.last_line, @6.first_column);}


		  | WHILE expr ':' '{' list error 							{ $$=NULL; yyerror("EEEE14\n"); fprintf(syn_errors_file, "right brace of while loop body is missing at line%d\n", yylineno); }
		  | WHILE expr ':' error list '}'							{ $$=NULL; yyerror("EEEE15\n"); fprintf(syn_errors_file, "left brace of while loop body is missing at line%d\n", @3.first_line); }
		  | WHILE expr error '{' list '}' 							{ $$=NULL; yyerror("EEEE16\n"); fprintf(syn_errors_file, "Colon expected after while cond. at line %d\n", ((Exp*)$2)->linenum); }			
		  

		  | REPEAT '{' list '}' UNTILL expr error 					{ $$=NULL; yyerror("EEEE17\n"); fprintf(syn_errors_file, "Colon expected after repeat cond at line %d\n", ((Exp*)$6)->linenum);}
		  | REPEAT '{' list '}' error expr ':'						{ $$=NULL; yyerror("EEEE18\n"); fprintf(syn_errors_file, "Untill keyword is missing after repeat body at line %d\n", @4.first_line);}
		  | REPEAT '{' list error UNTILL expr ':'					{ $$=NULL; yyerror("EEEE19\n"); fprintf(syn_errors_file, "right brace of repeat loop body is missing at line%d\n", @5.first_line);}
		  | REPEAT error list '}' UNTILL expr ':'					{ $$=NULL; yyerror("EEEE20\n"); fprintf(syn_errors_file, "right brace of repeat loop body is missing at line%d\n", @1.first_line);}


		  | FOR '(' decl_list ';' expr ';' assi_list ')' '{' list error    { $$=NULL; yyerror("EEEE21\n"); fprintf(syn_errors_file, "right brace of for loop body is missing at line %d\n", @10.first_line);}
		  | FOR '(' decl_list ';' expr ';' assi_list ')' error list '}'	   { $$=NULL; yyerror("EEEE22\n"); fprintf(syn_errors_file, "left brace of for loop body is missing at line %d\n", @8.first_line);}
		  | FOR '(' decl_list ';' expr ';' assi_list error '{' list '}'	   { $$=NULL; yyerror("EEEE23\n"); fprintf(syn_errors_file, "right parenthesis of for loop header is missing at line %d\n", @7.first_line);}
		  | FOR '(' decl_list ';' expr error assi_list ')' '{' list '}'	   { $$=NULL; yyerror("EEEE24\n"); fprintf(syn_errors_file, "semicolon is missing after for loop stop condition at %d : %d\n", @5.last_line, @5.last_column);}
		  | FOR '(' decl_list error expr ';' assi_list ')' '{' list '}'	   { $$=NULL; yyerror("EEEE25\n"); fprintf(syn_errors_file, "semicolon is missing after for loop declaration list at %d : %d\n", @3.last_line, @3.last_column);}
		  | FOR error decl_list ';' expr ';' assi_list ')' '{' list '}'    { $$=NULL; yyerror("EEEE26\n"); fprintf(syn_errors_file, "left parenthesis of for loop header is missing at %d : %d\n", @1.last_line, @1.last_column);}
		  

		  | SWITCH '[' expr ']' '{' switch_body error 					  { $$=NULL; yyerror("EEEE27\n"); fprintf(syn_errors_file, "right brace of switch body is missing at line %d \n", @6.last_line);} 
		  | SWITCH '[' expr ']' error switch_body '}'					  { $$=NULL; yyerror("EEEE28\n"); fprintf(syn_errors_file, "left brace of switch body is missing at line %d \n", @4.last_line);} 
		  | SWITCH '[' expr error '{' switch_body '}'					  { $$=NULL; yyerror("EEEE29\n"); fprintf(syn_errors_file, "right bracket of switch expression is missing at line %d \n", @3.last_line);} 
		  | SWITCH error expr ']' '{' switch_body '}'					  { $$=NULL; yyerror("EEEE30\n"); fprintf(syn_errors_file, "left bracket of switch expression is missing at line %d \n", @1.last_line);} 

		  ;


		 
assi_list : assi_stmnt ',' assi_list      			{ if($1 !=NULL) {printf("assi_list matched\n");$$ = newALIST($1, $3);}
													  else $$=NULL; } 
		  | assi_stmnt assi_list 					{ $$=NULL; yyerror("EEEE31\n"); fprintf(syn_errors_file, "comma is missing at line %d \n", @1.first_line); }
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
	 	   | CASE '[' expr error list 				{ $$=NULL; yyerror("EEEE29\n"); fprintf(syn_errors_file, "right bracket of case expression is missing at line %d \n", @3.last_line); }
	 	   | CASE error expr ']' list 				{ $$=NULL; yyerror("EEEE29\n"); fprintf(syn_errors_file, "left bracket of case expression is missing at line %d \n", @3.last_line);}
	 	   ;

 

susp : '=' expr 							{ $$=NULL; yyerror("EEEE677"); fprintf(syn_errors_file, "Identifier missing at the begining of assign. statement at %d : %d\n",@1.first_line, @1.first_column ); }
	 | '=' expr ';' 						{ $$=NULL; yyerror("EEEE677"); fprintf(syn_errors_file, "Identifier missing at the begining of assign. statement at %d : %d\n",@1.first_line, @1.first_column ); }
	 | expr ':' '{' list '}'				{ $$=NULL; yyerror("EEEE677"); fprintf(syn_errors_file, "IF or While keyword is missing at the begining of assign. statement at %d : %d\n",@1.first_line, @1.first_column ); }
	 | expr ':''{'list'}'ELSE '{' list '}'  { $$=NULL; yyerror("EEEE677"); fprintf(syn_errors_file, "IF keyword is missing at the begining of assign. statement at %d : %d\n",@1.first_line, @1.first_column ); }  
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

	fprintf(stderr,"%s", s);
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
	analysis_file = fopen("analysis.txt");
	
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
	
	return 0;
}


#include "create.c"
