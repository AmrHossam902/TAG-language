/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "p_test.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
int yylex(void);
void yyerror(char *);
extern FILE* yyin;


#line 76 "p_test.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "p_test.tab.h".  */
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
    CONST = 263,
    IF = 264,
    ELSE = 265,
    WHILE = 266,
    FOR = 267,
    REPEAT = 268,
    UNTILL = 269,
    SWITCH = 270,
    CASE = 271,
    DEFAULT = 272,
    BREAK = 273,
    AND = 274,
    OR = 275,
    XOR = 276,
    CMP = 277,
    UM = 278,
    STMNT1 = 279,
    ASSI_LIST = 280,
    DECL_LIST = 281,
    SWBODY = 282,
    LIST = 283,
    NOT = 284,
    CMP2 = 285,
    CMP1 = 286,
    UMINUS = 287
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 11 "p_test.y" /* yacc.c:355  */

	int i;
	double d;
	char * s;
	TreeNode * node;

#line 156 "p_test.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_P_TEST_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 173 "p_test.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  32
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   220

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  40
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  107

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,     2,     2,     2,     2,     2,
      39,    40,    35,    32,    48,    33,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    42,
       2,    41,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    68,    68,    69,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      91,    94,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   112,   113,   114,   117,   121,   122,   123,
     126
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_VAL", "DOUBLE_VAL", "BOOL_VAL",
  "ID", "ID_TYPE", "CONST", "IF", "ELSE", "WHILE", "FOR", "REPEAT",
  "UNTILL", "SWITCH", "CASE", "DEFAULT", "BREAK", "AND", "OR", "XOR",
  "CMP", "UM", "STMNT1", "ASSI_LIST", "DECL_LIST", "SWBODY", "LIST", "NOT",
  "CMP2", "CMP1", "'+'", "'-'", "'/'", "'*'", "'!'", "UMINUS", "\"=\"",
  "'('", "')'", "'='", "';'", "':'", "'{'", "'}'", "'['", "']'", "','",
  "$accept", "list", "expr", "assi_stmnt", "decl_stmnt", "statement",
  "assi_list", "decl_list", "switch_body", "case_block", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,    43,    45,    47,    42,    33,   287,   288,    40,
      41,    61,    59,    58,   123,   125,    91,    93,    44
};
# endif

#define YYPACT_NINF -41

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-41)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     202,   -40,    -1,     5,    20,    20,    21,    19,    15,    23,
      62,    24,    25,   202,    20,   -38,   -41,    64,    26,   -41,
     -41,   -41,   -41,    20,    20,    20,    90,    96,    68,   202,
      20,   -41,   -41,   -41,   -41,   -41,   157,   -41,   -41,   -41,
     -41,   140,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    27,    29,     0,    34,    33,    66,   -41,   172,   162,
     -25,    -2,    17,   -20,   -20,   -41,   -41,   202,   202,     0,
       0,   -41,    20,    65,    38,    49,    63,   -41,   -41,   121,
      20,    18,    73,   -41,     0,   115,    86,   202,    67,    18,
      70,    78,   -41,    20,   -41,   -41,   -41,   202,    93,    72,
      98,   202,   202,   -41,    99,   -41,   -41
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,     0,     0,    21,     0,     0,    17,
      18,    16,    19,     0,     0,     0,     0,     0,     0,     3,
       0,    32,     1,    22,    23,     2,    20,    25,    24,     9,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,     0,     0,     0,     4,    10,    11,
      12,    14,    13,     5,     6,     7,     8,     3,     3,    35,
      35,    36,     0,     0,     0,     0,     0,    34,    33,     0,
       0,    39,    26,    28,    35,     0,     0,     3,     0,    39,
       0,     0,    29,     0,    38,    31,    37,     3,     0,     0,
       0,     3,     3,    27,     0,    40,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -41,   -13,    -3,    11,   135,   -41,   -12,   -41,    75,   -41
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    10,    26,    11,    12,    13,    71,    54,    88,    89
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      35,    14,    27,    14,    37,    15,     1,    47,    48,    49,
      50,    36,    17,    16,    49,    50,    55,    42,    43,    44,
      39,    40,    41,    19,    20,    21,    22,    56,    16,    46,
      47,    48,    49,    50,    86,    87,    42,    43,    44,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    69,    47,
      48,    49,    50,    23,    75,    76,    24,    77,    78,    25,
      28,    30,    32,    29,    70,    31,    33,    34,    38,    79,
       1,    67,    91,    68,    94,    53,    72,    85,    73,    80,
      70,    70,    81,    90,   100,    42,    43,    44,   104,   105,
      99,    42,    43,    44,    82,    70,    45,    46,    47,    48,
      49,    50,    45,    46,    47,    48,    49,    50,    83,    42,
      43,    44,    95,    74,    97,    42,    43,    44,    98,   102,
      45,    46,    47,    48,    49,    50,    45,    46,    47,    48,
      49,    50,    93,    51,    42,    43,    44,   101,    18,    52,
      42,    43,    44,   103,   106,    45,    46,    47,    48,    49,
      50,    45,    46,    47,    48,    49,    50,     0,    92,    42,
      43,    44,     0,    84,    96,     0,     0,     0,     0,     0,
      45,    46,    47,    48,    49,    50,    42,    43,    44,     0,
      57,    42,     0,    44,     0,     0,     0,    45,    46,    47,
      48,    49,    50,    44,    47,    48,    49,    50,     0,     0,
       0,     0,     0,     0,    47,    48,    49,    50,     1,     2,
       3,     4,     0,     5,     6,     7,     0,     8,     0,     0,
       9
};

static const yytype_int8 yycheck[] =
{
      13,    41,     5,    41,    42,     6,     6,    32,    33,    34,
      35,    14,     7,     2,    34,    35,    29,    19,    20,    21,
      23,    24,    25,     3,     4,     5,     6,    30,    17,    31,
      32,    33,    34,    35,    16,    17,    19,    20,    21,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    48,    32,
      33,    34,    35,    33,    67,    68,    36,    69,    70,    39,
      39,    46,     0,    44,    53,    42,    42,    42,    42,    72,
       6,    44,    84,    44,    87,     7,    42,    80,    45,    14,
      69,    70,    44,    10,    97,    19,    20,    21,   101,   102,
      93,    19,    20,    21,    45,    84,    30,    31,    32,    33,
      34,    35,    30,    31,    32,    33,    34,    35,    45,    19,
      20,    21,    45,    47,    44,    19,    20,    21,    40,    47,
      30,    31,    32,    33,    34,    35,    30,    31,    32,    33,
      34,    35,    46,    43,    19,    20,    21,    44,     3,    43,
      19,    20,    21,    45,    45,    30,    31,    32,    33,    34,
      35,    30,    31,    32,    33,    34,    35,    -1,    43,    19,
      20,    21,    -1,    42,    89,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    19,    20,    21,    -1,
      40,    19,    -1,    21,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    21,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,     6,     7,
       8,     9,    -1,    11,    12,    13,    -1,    15,    -1,    -1,
      18
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,     9,    11,    12,    13,    15,    18,
      50,    52,    53,    54,    41,     6,    52,     7,    53,     3,
       4,     5,     6,    33,    36,    39,    51,    51,    39,    44,
      46,    42,     0,    42,    42,    50,    51,    42,    42,    51,
      51,    51,    19,    20,    21,    30,    31,    32,    33,    34,
      35,    43,    43,     7,    56,    50,    51,    40,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    44,    44,    48,
      52,    55,    42,    45,    47,    50,    50,    55,    55,    51,
      14,    44,    45,    45,    42,    51,    16,    17,    57,    58,
      10,    55,    43,    46,    50,    45,    57,    44,    40,    51,
      50,    44,    47,    45,    50,    50,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      52,    53,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    55,    55,    55,    56,    57,    57,    57,
      58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     2,     1,     1,     1,     1,
       3,     2,     2,     2,     3,     3,     6,    10,     6,     7,
      11,     7,     2,     2,     2,     0,     2,     2,     2,     0,
       5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 68 "p_test.y" /* yacc.c:1646  */
    { printf("%s\n", "list matched"); (yyval.node) = newLIST((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1337 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 69 "p_test.y" /* yacc.c:1646  */
    { printf("%s\n", "empty list matched");(yyval.node) = NULL; }
#line 1343 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 73 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1349 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 74 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP('+', (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1355 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 75 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP('-', (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1361 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 76 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP('/', (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1367 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 77 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP('*', (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1373 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 78 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP(UMINUS, (yyvsp[0].node), NULL); }
#line 1379 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 79 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP(AND,(yyvsp[-2].node), (yyvsp[0].node)); }
#line 1385 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 80 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP(OR, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1391 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 81 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP(XOR, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1397 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 82 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP(CMP1, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1403 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 83 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP(CMP2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1409 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 84 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP(NOT, (yyvsp[0].node), NULL); }
#line 1415 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 85 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newBOOL((yyvsp[0].i)); }
#line 1421 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 86 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newINT((yyvsp[0].i)); }
#line 1427 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 87 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newDOUBLE((yyvsp[0].d)); }
#line 1433 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 88 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newID((yyvsp[0].s)); }
#line 1439 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 91 "p_test.y" /* yacc.c:1646  */
    { printf("%s\n", "assi_stmnt matched");  (yyval.node) = newSTMNT1((yyvsp[-2].s), (yyvsp[0].node)); }
#line 1445 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 94 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1451 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 97 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); printf("%s\n", "assi_stmnt");}
#line 1457 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 98 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); printf("%s\n", "decl_stmnt");}
#line 1463 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 99 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); printf("%s\n", "decl_stmnt with const");}
#line 1469 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 100 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newSTMNT1((yyvsp[-1].s),NULL); printf("%s\n", "decl without initialization"); }
#line 1475 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 101 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newFLOW(IF, (yyvsp[-4].node), (yyvsp[-1].node), NULL); printf("%s\n", "IF without else"); }
#line 1481 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 102 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newFLOW(IF, (yyvsp[-8].node), (yyvsp[-5].node), (yyvsp[-1].node)); printf("%s\n", "IF with else");}
#line 1487 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 103 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newFLOW(WHILE, (yyvsp[-4].node), (yyvsp[-1].node), NULL); printf("%s\n", "while loop");}
#line 1493 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 104 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newFLOW(REPEAT, (yyvsp[-1].node), (yyvsp[-4].node), NULL); printf("%s\n", "repeat loop");}
#line 1499 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 105 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newFOR((yyvsp[-8].node), (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-1].node)); printf("%s\n", "for loop");}
#line 1505 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 106 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newSWITCH((yyvsp[-4].node), (yyvsp[-1].node)); printf("%s\n", "switch statement");}
#line 1511 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 107 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newNODE(BREAK); }
#line 1517 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 112 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newALIST((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1523 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 113 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1529 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 114 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1535 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 117 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newDLIST((yyvsp[0].node)); }
#line 1541 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 121 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newSBODY((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1547 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 122 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newCASE(DEFAULT, NULL, (yyvsp[0].node)); }
#line 1553 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 123 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1559 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 126 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newCASE(CASE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1565 "p_test.tab.c" /* yacc.c:1646  */
    break;


#line 1569 "p_test.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 129 "p_test.y" /* yacc.c:1906  */

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


TreeNode * newNODE(int type)
{
	TreeNode * T = malloc(sizeof(TreeNode));
	T->NodeType = type;
	return T;
}


TreeNode * newINT(int value)
{
	Int * I = malloc(sizeof(Int));
	I->NodeType = INT_VAL;
	I->i = value;
	return (TreeNode *) I;
}


TreeNode * newDOUBLE(double value)
{
	Double * D = malloc(sizeof(Double));
	D->NodeType = DOUBLE_VAL;
	D->d = value;
	return (TreeNode *) D;
}


TreeNode * newBOOL(int value)
{
	Bool * B = malloc(sizeof(Bool));
	B->NodeType = BOOL_VAL;
	B->b = value;
	return (TreeNode *) B;
}


TreeNode * newID(char * name)
{
	Id * I = malloc(sizeof(Id));
	I->NodeType = ID;
	I->name = name;
	return (TreeNode *) I;
}


TreeNode * newEXP(int type, TreeNode * left, TreeNode * right)
{
	Exp * E = malloc(sizeof(Exp));
	E->NodeType = type;
	E->rhs = right;
	E->lhs = left;
	return (TreeNode *) E;
}


TreeNode * newSTMNT1(char * id, TreeNode * rhs)
{
	
	Id * I = malloc(sizeof(Id));
	I->name = id;
	I->NodeType = ID;

	Stmnt1 * S = malloc(sizeof(Stmnt1));
	S->NodeType = STMNT1;
	S->Id = (TreeNode *) I;
	S->rhs = rhs;

	return (TreeNode *) S;
}


TreeNode * newFLOW(int type, TreeNode* cond, TreeNode* if_brnch, TreeNode* el_brnch)
{
	Flow * F = malloc(sizeof(Flow));
	F->NodeType = type;
	F->cond = cond;
	F->if_brnch = if_brnch;
	F->els_brnch = el_brnch;

	return (TreeNode *) F;
}


TreeNode * newFOR(TreeNode * decl_list, TreeNode * cond, TreeNode * assi_list, TreeNode * body)
{
	For * F = malloc(sizeof(For));
	F->NodeType = FOR;
	F->decl_list = decl_list;
	F->cond = cond;
	F->assi_list = assi_list;
	F->body = body;

	return (TreeNode *) F;
}


TreeNode * newSWITCH(TreeNode * exp, TreeNode * sw_body)
{
	Switch * S = malloc(sizeof(Switch));
	S->NodeType = SWITCH;
	S->exp = exp;
	S->body = sw_body;

	return (TreeNode *) S;
}


TreeNode * newCASE(int type, TreeNode * c_exp, TreeNode * c_list)
{
	Case * C = malloc(sizeof(Case));
	C->NodeType = type;
	C->case_exp = c_exp;
	C->case_list = c_list;

	return (TreeNode *) C;
}


TreeNode * newSBODY( TreeNode * case_block, TreeNode * sw_body)
{
	Swbody * S = malloc(sizeof(Swbody));
	S->NodeType = SWBODY;
	S->case_block = case_block;
	S->sbody = sw_body;

	return (TreeNode *) S;
}


TreeNode * newALIST(TreeNode * astmnt, TreeNode * alist)
{
	Assi_list * A = malloc(sizeof(Assi_list));
	A->NodeType = ASSI_LIST;
	A->astmnt = astmnt;   
	A->alist = alist;

	return (TreeNode *) A;
}


TreeNode * newDLIST(TreeNode * alist)
{
	Decl_list * D = malloc(sizeof(Decl_list));
	D->NodeType = DECL_LIST;
	D->alist = alist;

	return (TreeNode *) D;
}


TreeNode * newLIST(TreeNode * st, TreeNode * l)
{
	List * L = malloc(sizeof(List));
	L->NodeType = LIST;
	L->statement = st;
	L->list = l;

	return (TreeNode *) L;
}
