%{
#include <stdio.h>
int yylex(void);
void yyerror(char *);
extern FILE* yyin;
%}

	/* types of yylval */
%union{
	char* str;
	double d;
	int  i;
}

	/*token set*/

%token INT_VAL
%token <d> DOUBLE_VAL
%token <str> BOOL_VAL
%token <str> ID
%token <str> ID_TYPE
%token <str> CONST_TYPE

	/*operators precedence & associativity*/
%left "+" "-"
%left "/" "*"
%nonassoc "|" UMINUS    /*unary minus*/
%right "="


%%

prog: prog statement
	|
	;

statement : ";"
		  | expr ";"
		  | ID "=" expr ";"
		  | ID_TYPE ID "=" expr ";"
		  | CONST_TYPE ID_TYPE ID "=" expr ";"
		  ;

expr : "(" expr ")"
	 | bool_expr
	 | int_expr
	 | double_expr
	 ;

int_expr : term "+" term
		 | term "-" term


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