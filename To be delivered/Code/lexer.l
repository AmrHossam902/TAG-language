%{
#include "structures.h"
#include "parser.tab.h"
#include <string.h>
%}

%%
	/* matching integers */
[0-9]+         { fprintf(yyout, "%s\n", "integer value");  yylval.i = atoi(yytext);  return INT_VAL; }
	
	/* matching doubles */
(([0-9]*\.[0-9]+)|([0-9]+\.[0-9]*))([eE][-+]?[0-9]+)?   { yylval.d = atof(yytext);  fprintf(yyout, "%s\n", "double value"); return DOUBLE_VAL;}
	
	/* matching booleans */
TRUE|FALSE    { if(strcmp(yytext, "TRUE") == 0 ) yylval.i = 1; else yylval.i =0; fprintf(yyout, "%s\n", "boolean value");  return BOOL_VAL;}


	/* matching strings */
"\""[^\n\"]*"\"" 		{fprintf(yyout, "%s\n", "string value"); return STRING_VAL;} 

	/* keywords */
int |				             
double |
string |		
bool 				{ fprintf(yyout, "%s\n", yytext); return ID_TYPE; }
const				{ fprintf(yyout, "%s\n", "const keyword"); return CONST;}
if                  { fprintf(yyout, "%s\n", "if" ); return IF; }
else				{ fprintf(yyout, "%s\n", "else" ); return ELSE;  }
for                 { fprintf(yyout, "%s\n", "for"); return FOR;  }
while				{ fprintf(yyout, "%s\n", "while");return WHILE;  }
repeat				{ fprintf(yyout, "%s\n", "repeat");return REPEAT; }
untill 				{ fprintf(yyout, "%s\n", "untill");return UNTILL; }
switch				{ fprintf(yyout, "%s\n", "switch");return SWITCH; }
case 				{ fprintf(yyout, "%s\n", "case");return CASE; }
default				{ fprintf(yyout, "%s\n", "default");return DEFAULT;  }
break				{ fprintf(yyout, "%s\n", "break");return BREAK; }
&&					{ fprintf(yyout, "%s\n", "AND");return AND; }
\|\| 				{ fprintf(yyout, "%s\n", "OR");return OR; }
\^					{ fprintf(yyout, "%s\n", "XOR");return XOR; }
"="					{ fprintf(yyout, "%s\n", "="); return '='; }
">=" |
">" |
"<=" |
"<" 				{ fprintf(yyout, "%s\n", yytext ); yylval.s = yytext; return CMP1; }
!= | 
==				{ fprintf(yyout, "%s\n", yytext ); yylval.s = yytext; return CMP2; }
	/* matching identifiers*/
[_a-zA-Z][_a-zA-Z0-9]*   { fprintf(yyout, "%s\n","identifier" ); return ID; }

[-*\(\)+/;:{}\[\],]   { fprintf(yyout, "%s\n", yytext); return *yytext; }

.					 ;

%%


int yywrap(void)
{
	return 1;
}
