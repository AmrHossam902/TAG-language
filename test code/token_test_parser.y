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


%token INT_VAL
%token <d>DOUBLE_VAL
%token <str> BOOL_VAL
%token <str> ID
%token <str> ID_TYPE
%token <str> CONST_TYPE


%%

prog: prog INT_VAL
	| prog DOUBLE_VAL
	| prog BOOL_VAL
	| prog ID
	| prog ID_TYPE
	| prog CONST_TYPE
	|   
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