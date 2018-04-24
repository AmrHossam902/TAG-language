%{
#include <stdlib.h>
#include "token_test_parser.tab.h"
//void yyerror(char *);
%}

%%
	/* matching integers */
[-+]?[0-9]+         { printf("%s\n", "integer value");  yylval.i = atoi(yytext);  return INT_VAL; }
	
	/* matching doubles */
[-+]?(([0-9]*"."[0-9]+)|([0-9]+"."[0-9]*))([eE][-+]?[0-9]+)?   { yylval.d = atof(yytext);  printf("%s\n", "double value"); return DOUBLE_VAL;}
	
	/* matching booleans */
"TRUE"|"FALSE"    { yylval.str = yytext; printf("%s %s\n", "boolean value", yylval.str );  return BOOL_VAL;}
	
	/* matching types */
"int" |               
"double" |		
"bool"				{ yylval.str = yytext; printf("%s \n", yylval.str);  return ID_TYPE; }
"const"				{ printf("%s\n", "const keyword"); return CONST_TYPE; }
	
	/* matching identifiers*/
[_a-zA-Z][_a-zA-Z0-9]*   { printf("%s\n","identifier" ); return ID; }




%%


int yywrap(void)
{
	return 1;
}
