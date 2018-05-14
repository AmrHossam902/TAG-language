%{
#include "structures.h"
#include "p_test.tab.h"
#include <string.h>
%}

%%
	/* matching integers */
[0-9]+         { printf("%s %d\n", "integer value", yylineno);  yylval.i = atoi(yytext);  return INT_VAL; }
	
	/* matching doubles */
(([0-9]*\.[0-9]+)|([0-9]+\.[0-9]*))([eE][-+]?[0-9]+)?   { yylval.d = atof(yytext);  printf("%s %d\n", "double value", yylineno); return DOUBLE_VAL;}
	
	/* matching booleans */
TRUE|FALSE    { if(strcmp(yytext, "TRUE") == 0 ) yylval.i = 1; else yylval.i =0; printf("%s %8d\n", "boolean value", yylval.i);  return BOOL_VAL;}

	/* matching characters */
"\'"[^\n]"\'"		{printf("%s\n","character value" ); yylval.c = yytext[1]; return CHAR_VAL;}

	/* matching strings */
"\""[^\n\"]*"\"" 	{printf("%s\n", "string value"); strcpy(yylval.s,yytext); return STRING_VAL;} 

	/* keywords */
int |				             
double |
string |
char   |		
bool 				{ printf("%s\n", yytext); strcpy(yylval.s, yytext); return ID_TYPE; }
const				{ printf("%s\n", "const keyword"); return CONST;}
if                  { printf("%s\n", "if" ); return IF; }
else				{ printf("%s\n", "else" ); return ELSE;  }
for                 { printf("%s\n", "for"); return FOR;  }
while				{ printf("%s\n", "while");return WHILE;  }
repeat				{ printf("%s\n", "repeat");return REPEAT; }
untill 				{ printf("%s\n", "untill");return UNTILL; }
switch				{ printf("%s\n", "switch");return SWITCH; }
case 				{ printf("%s\n", "case");return CASE; }
default				{ printf("%s\n", "default");return DEFAULT;  }
break				{ printf("%s\n", "break");return BREAK; }
&&					{ printf("%s\n", "AND");return AND; }
\|\| 				{ printf("%s\n", "OR");return OR; }
\^					{ printf("%s\n", "XOR");return XOR; }
"="					{ printf("%s\n", "="); return '='; }
">=" |
">" |
"<=" |
"<" 				{ printf("%s\n", yytext ); strcpy(yylval.s, yytext); return CMP1; }
!= | 
==				{ printf("%s\n", yytext ); strcpy(yylval.s, yytext); return CMP2; }
	/* matching identifiers*/
[_a-zA-Z][_a-zA-Z0-9]*   { printf("%s\n","identifier" ); strcpy(yylval.s, yytext); return ID; }

[-*\(\)+/;:{}\[\]]   { printf("%s\n", yytext); return *yytext; }

\n 					{yylineno++;}

.						;  // any other characters neglect them


%%


int yywrap(void)
{
	return 1;
}
