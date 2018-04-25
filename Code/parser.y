%{
#include <stdio.h>
int yylex(void);
void yyerror(char *);
extern FILE* yyin;
%}

%union{
	int i;
	double d;
	bool b;
	char * s;
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
%token EE
%token GE
%token LE
%token NE

	/*operators precedence & associativity*/
%left EE LE GE NE
%left OR XOR
%left AND
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
	 | expr EE expr
	 | expr GE expr
	 | expr LE expr
	 | expr NE expr		
	 | '!' expr	 %prec UMINUS
 	 | BOOL_VAL
 	 | INT_VAL
 	 | DOUBLE_VAL
 	 | ID
 	 ;


statement : decl_stmnt ';'
		  | assi_stmnt ';'
		  | CONST ID_TYPE ID '=' expr ';'
		  | ID_TYPE ID ';' 
		  | IF expr ':' '{' list '}'
		  | IF expr ':' '{' list '}' ELSE '{' list '}'
		  | WHILE expr ':' '{' list '}'
		  | REPEAT '{' list '}' UNTILL expr ':'
		  | FOR '(' decl_list ';' expr ';' assi_list ')' '{' list '}'
		  | SWITCH expr ':' '{' switch_body '}'
		  ;

switch_body : DEFAULT ':' '\n' list
			| case_stmnt list BREAK switch_body
			;

case_stmnt : CASE INT_VAL ':' '\n' list BREAK
		   | CASE DOUBLE_VAL ':' '\n' list BREAK
		   | CASE BOOL_VAL ':' '\n' list BREAK
		   ;

decl_list : decl_stmnt decl_list
		  | ',' decl_list
		  |
		  ;

decl_stmnt : ID_TYPE ID '=' expr
		  ;

assi_list : assi_stmnt assi_list
		  | ',' assi_list
		  |
		  ;

assi_stmnt : ID '=' expr
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