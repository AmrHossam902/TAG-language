/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_P_TEST_TAB_H_INCLUDED
# define YY_YY_P_TEST_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT_VAL = 258,
    DOUBLE_VAL = 259,
    BOOL_VAL = 260,
    ID = 261,
    ID_TYPE = 262,
    STRING_VAL = 263,
    UNKNOWN = 264,
    CONST = 265,
    IF = 266,
    ELSE = 267,
    WHILE = 268,
    FOR = 269,
    REPEAT = 270,
    UNTILL = 271,
    SWITCH = 272,
    CASE = 273,
    DEFAULT = 274,
    BREAK = 275,
    AND = 276,
    OR = 277,
    XOR = 278,
    DECL_STMNT = 279,
    ASSI_STMNT = 280,
    DECL_ASSI_STMNT = 281,
    CONST_DECL_STMNT = 282,
    EMPTY_STMNT = 283,
    ASSI_LIST = 284,
    DECL_LIST = 285,
    SWBODY = 286,
    LIST = 287,
    NOT = 288,
    EE = 289,
    NE = 290,
    LT = 291,
    GT = 292,
    LE = 293,
    GE = 294,
    UMINUS = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "p_test.y" /* yacc.c:1909  */

	int i;
	double d;
	char s[100];
	TreeNode * node;

#line 102 "p_test.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_P_TEST_TAB_H_INCLUDED  */
