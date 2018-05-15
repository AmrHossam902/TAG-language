%{
#include "structures.h"
#include "p_test.tab.h"
#include <string.h>


/* handle locations */
int yycolumn = 1;
#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno; \
yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1; \
yycolumn += yyleng;


%}

%%
	/* matching integers */
[0-9]+         { printf("%s %d\n", "integer value", yylineno);  yylval.i = atoi(yytext);  return INT_VAL; }
	
	/* matching doubles */
(([0-9]*\.[0-9]+)|([0-9]+\.[0-9]*))([eE][-+]?[0-9]+)?   { yylval.d = atof(yytext);  printf("%s %d\n", "double value", yylineno); return DOUBLE_VAL;}
	
	/* matching booleans */
TRUE|FALSE    { if(strcmp(yytext, "TRUE") == 0 ) yylval.i = 1; else yylval.i =0; printf("%s %8d\n", "boolean value", yylval.i);  return BOOL_VAL;}


	/* matching strings */
"\""[^\n\"]*"\"" 	{printf("%s\n", "string value"); strcpy(yylval.s,yytext); return STRING_VAL;} 

	/* keywords */
int |				             
double |
string |		
bool 				{ printf("%s\n", yytext); strcpy(yylval.s, yytext); return ID_TYPE; }
const				{ printf("const keyword"); return CONST;}
if                  { printf("if" ); return IF; }
else				{ printf("else" ); return ELSE;  }
for                 { printf("for"); return FOR;  }
while				{ printf("while");return WHILE;  }
repeat				{ printf("repeat");return REPEAT; }
untill 				{ printf("untill");return UNTILL; }
switch				{ printf("switch");return SWITCH; }
case 				{ printf("case");return CASE; }
default				{ printf("default");return DEFAULT;  }
break				{ printf("break");return BREAK; }
&&					{ printf("AND");return AND; }
\|\| 				{ printf("OR");return OR; }
\^					{ printf("XOR");return XOR; }
"="					{ printf("="); return '='; }
">=" 				{ printf(">="); return GE; }
">" 				{ printf(">"); return GT; }
"<=" 				{ printf("<="); return LE; }
"<" 				{ printf("<"); return LT; }
!=  				{ printf("!="); return NE; }
==					{ printf("%s\n",yytext ); strcpy(yylval.s, yytext); return EE; }
	/* matching identifiers*/
[_a-zA-Z][_a-zA-Z0-9]*   { printf("%s\n","identifier" ); strcpy(yylval.s, yytext); return ID; }

[-*\(\)+/;:{}\[\],]   { printf("%s\n", yytext); return *yytext; }

\n 					{yylineno++;}

.						;  // any other characters neglect them


%%


int yywrap(void)
{
	return 1;
}
