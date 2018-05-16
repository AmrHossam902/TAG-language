%{
#include "structures.h"
#include "p_test.tab.h"
#include <string.h>

extern FILE * analysis_file;

/* handle locations */
int yycolumn = 1;
#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno; \
yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1; \
yycolumn += yyleng;


%}

%%
	/* matching integers */
[0-9]+         { fprintf(analysis_file, "integer value\n");  yylval.i = atoi(yytext);  return INT_VAL; }
	
	/* matching doubles */
(([0-9]*\.[0-9]+)|([0-9]+\.[0-9]*))([eE][-+]?[0-9]+)?   { yylval.d = atof(yytext);  fprintf(analysis_file, "double value\n"); return DOUBLE_VAL;}
	
	/* matching booleans */
TRUE|FALSE    { if(strcmp(yytext, "TRUE") == 0 ) yylval.i = 1; else yylval.i =0; fprintf(analysis_file, "boolean value\n");  return BOOL_VAL;}


	/* matching strings */
"\""[^\n\"]*"\"" 	{ fprintf(analysis_file, "string value\n"); strcpy(yylval.s,yytext); return STRING_VAL;} 

	/* keywords */
int |				             
double |
string |		
bool 				{ fprintf(analysis_file, "%s\n", yytext); strcpy(yylval.s, yytext); return ID_TYPE; }
const				{ fprintf(analysis_file, "const keyword\n"); return CONST;}
if                  { fprintf(analysis_file, "if\n"); return IF; }
else				{ fprintf(analysis_file, "else\n"); return ELSE;  }
for                 { fprintf(analysis_file, "for\n"); return FOR;  }
while				{ fprintf(analysis_file, "while\n");return WHILE;  }
repeat				{ fprintf(analysis_file, "repeat\n");return REPEAT; }
untill 				{ fprintf(analysis_file, "untill\n");return UNTILL; }
switch				{ fprintf(analysis_file, "switch\n");return SWITCH; }
case 				{ fprintf(analysis_file, "case\n");return CASE; }
default				{ fprintf(analysis_file, "default\n");return DEFAULT;  }
break				{ fprintf(analysis_file, "break\n");return BREAK; }
&&					{ fprintf(analysis_file, "AND\n");return AND; }
\|\| 				{ fprintf(analysis_file, "OR\n");return OR; }
\^					{ fprintf(analysis_file, "XOR\n");return XOR; }
"="					{ fprintf(analysis_file, "=\n"); return '='; }
">=" 				{ fprintf(analysis_file, ">=\n"); return GE; }
">" 				{ fprintf(analysis_file, ">\n"); return GT; }
"<=" 				{ fprintf(analysis_file, "<=\n"); return LE; }
"<" 				{ fprintf(analysis_file, "<\n"); return LT; }
!=  				{ fprintf(analysis_file, "!=\n"); return NE; }
==					{ fprintf(analysis_file, "%s\n",yytext ); strcpy(yylval.s, yytext); return EE; }
	/* matching identifiers*/
[_a-zA-Z][_a-zA-Z0-9]*   { fprintf(analysis_file, "%s\n","identifier" ); strcpy(yylval.s, yytext); return ID; }

[-*\(\)+/;:{}\[\],]   { fprintf(analysis_file, "%s\n", yytext); return *yytext; }

\n 					{yylineno++;}

.						;  // any other characters neglect them


%%


int yywrap(void)
{
	return 1;
}
