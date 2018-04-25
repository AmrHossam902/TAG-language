%{
#include <stdlib.h>
#include "p_test.tab.h"
//void yyerror(char *);
%}

%%
	/* matching integers */
[-+]?[0-9]+         { printf("%s\n", "integer value");  yylval.i = atoi(yytext);  return INT_VAL; }
	
	/* matching doubles */
[-+]?(([0-9]*.[0-9]+)|([0-9]+.[0-9]*))([eE][-+]?[0-9]+)?   { yylval.d = atof(yytext);  printf("%s\n", "double value"); return DOUBLE_VAL;}
	
	/* matching booleans */
TRUE|FALSE    { yylval.b = yytext; printf("%s %s\n", "boolean value", yylval.s);  return BOOL_VAL;}
	
	/* keywords */
int |               
double |		
bool				{ yylval.str = yytext; printf("%s \n", yylval.str);  return ID_TYPE; }
const				{ printf("%s\n", "const keyword"); return CONST_TYPE; }
if                  { return IF; printf("%s\n", "if" ); }
else				{ return ELSE; printf("%s\n", "else" ); }
for                 { return FOR;  printf("%s\n", "for");}
while				{ return WHILE;  printf("%s\n", "while");}
repeat				{ return REPEAT; }
untill 				{ return UNTILL; }
switch				{ return SWITCH; }
case 				{ return CASE; }
default				{ return DEFAULT; }
break				{ return BREAK; }
&&					{ return AND; }
|| 					{ return OR; }
\^					{ return XOR; }
==					{ return EE; }
>=					{ return GE; }
<=					{ return LE; }
!=					{ return NE; }

	/* matching identifiers*/


[_a-zA-Z][_a-zA-Z0-9]*   { printf("%s\n","identifier" ); return ID; }

[-*\(\)+/;\n]   { printf("%s\n", yytext); return *yytext; }





%%


int yywrap(void)
{
	return 1;
}
