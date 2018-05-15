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
#include <stdarg.h>
#include<string.h>
#include "structures.h"
int yylex(void);
void yyerror(char *);
extern FILE* yyin;

//----------------------------------Variables-----------------------------------------
#define bucket_size 20
#define not_defined -10
#define not_initialized -10
#define max_syn_errors_count 20

int error_count = 0;
Sym_table table;
extern int yylineno;
FILE * sem_errors_file;
FILE * syn_errors_file;


#line 90 "p_test.tab.c" /* yacc.c:339  */

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
#line 25 "p_test.y" /* yacc.c:355  */

	int i;
	double d;
	char s[100];
	TreeNode * node;

#line 178 "p_test.tab.c" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 209 "p_test.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   808

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  251

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,     2,     2,     2,     2,     2,
      47,    48,    43,    40,    56,    41,     2,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,    50,
       2,    49,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    88,    88,    89,    90,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   135,   139,   142,   143,   144,   145,   146,   148,
     151,   154,   157,   160,   163,   165,   166,   168,   169,   170,
     171,   174,   175,   176,   177,   178,   179,   180,   181,   185,
     186,   187,   190,   191,   192,   193,   196,   197,   198,   199,
     200,   201,   204,   205,   206,   207,   213,   215,   216,   219,
     224,   225,   228,   229,   230,   231,   236,   237,   238,   239
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_VAL", "DOUBLE_VAL", "BOOL_VAL",
  "ID", "ID_TYPE", "STRING_VAL", "UNKNOWN", "CONST", "IF", "ELSE", "WHILE",
  "FOR", "REPEAT", "UNTILL", "SWITCH", "CASE", "DEFAULT", "BREAK", "AND",
  "OR", "XOR", "DECL_STMNT", "ASSI_STMNT", "DECL_ASSI_STMNT",
  "CONST_DECL_STMNT", "EMPTY_STMNT", "ASSI_LIST", "DECL_LIST", "SWBODY",
  "LIST", "NOT", "EE", "NE", "LT", "GT", "LE", "GE", "'+'", "'-'", "'/'",
  "'*'", "'!'", "UMINUS", "\"=\"", "'('", "')'", "'='", "';'", "':'",
  "'{'", "'}'", "'['", "']'", "','", "$accept", "list", "expr",
  "assi_stmnt", "decl_stmnt", "statement", "assi_list", "decl_list",
  "switch_body", "case_block", "susp", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      43,    45,    47,    42,    33,   295,   296,    40,    41,    61,
      59,    58,   123,   125,    91,    93,    44
};
# endif

#define YYPACT_NINF -33

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-33)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     268,   -33,   -33,   -33,   -32,    33,   -33,    12,   213,   213,
     107,    15,     5,   124,   288,   296,   213,   213,   -33,   109,
     573,   125,   133,   268,   -33,   213,    70,    65,   -33,   115,
      73,   -33,   121,   172,   117,   117,   268,   268,   213,   213,
     -33,   -33,   -33,   -33,   -33,   -33,   285,   665,   -33,   341,
     349,   357,   365,   373,   418,   426,   434,   442,   450,   495,
     503,   511,    79,   -33,   -33,   -33,   -33,   -33,   734,   -33,
     -33,   -33,   -32,   -33,    80,    36,    83,    37,   115,    86,
     140,   -20,     2,   538,    35,   -33,   -33,   -33,   -33,   -19,
     -33,   522,   -33,   146,   -33,   742,   -33,   742,   -33,   765,
     -33,   765,   -33,   765,   -33,   765,   -33,   -17,   -33,   -17,
     -33,   -33,   -33,   -33,   268,   268,   268,   268,   268,   268,
     268,    77,   -33,   213,   213,   213,   130,   131,     4,    97,
      98,    59,   100,   112,   113,    11,   114,   123,    26,   115,
     -33,   688,   711,   227,   213,   213,   213,   213,    22,    22,
      22,    22,   139,   179,   180,   208,   210,   -33,   -33,   -33,
     -33,   -33,   115,   115,   115,   115,   596,   619,   642,   204,
      14,   268,   171,    22,   176,   177,    27,   181,   182,   183,
     184,    60,   189,   203,   205,    62,   -33,   -33,   -33,   -33,
     -33,   213,   213,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     268,   268,   268,   268,   268,   268,   200,   206,   207,   228,
      61,   548,    64,   178,   231,   234,   237,   242,    28,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   245,   250,   252,   257,   258,
      29,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    22,    23,    21,    25,     0,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    44,     0,
       0,     0,     0,     3,     4,     0,     0,     0,    43,     0,
       0,    25,     0,     0,     0,     0,     3,     3,     0,     0,
      56,    55,    31,    10,    41,    20,     0,    96,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,    45,    58,    46,     2,    42,    60,
      59,    48,     0,    47,     0,     0,     0,     0,    88,     0,
       0,     0,     0,     0,     0,    26,     5,    97,    32,    11,
      33,    12,    34,    13,    35,    14,    36,    15,    37,    16,
      38,    17,    39,    18,    40,    19,    27,     6,    28,     7,
      29,     8,    30,     9,     3,     3,     3,     3,     3,     3,
       3,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      87,     0,     0,     0,     0,     0,     0,     0,    91,    91,
      91,    91,    98,    63,    62,    61,    49,    71,    70,    69,
      51,    86,    88,    88,    88,    88,     0,     0,     0,     0,
       0,     3,     0,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    75,    74,    73,    72,
      52,     0,     0,    93,    85,    90,    84,    83,    82,    54,
       3,     3,     3,     3,     3,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     3,
       3,     3,     3,     3,     3,     3,     3,     3,    99,    68,
      67,    66,    65,    64,    50,     0,     0,     0,     0,     0,
       0,    95,    94,    92,    81,    80,    79,    78,    77,    76,
      53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -33,   -23,    -7,     6,   225,   -33,   363,   221,   -21,   -33,
     -33
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    20,    21,    22,    23,   122,    79,   172,   173,
      24
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      67,    32,    33,   127,    51,   146,    38,    43,    45,    46,
      47,    28,   155,    81,    82,   191,    36,    25,    68,    29,
     147,    58,    59,    60,    61,    60,    61,   159,   198,   233,
     249,    83,    84,   126,    26,    28,   130,   116,   119,    27,
     170,   171,    89,    91,    93,    95,    97,    99,   101,   103,
     105,   107,   109,   111,   113,   128,    49,    50,    51,    39,
     150,   204,   223,   209,   156,   226,    70,    37,   192,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,   160,
     199,   234,   250,    72,   121,    49,    50,    51,   117,   120,
     131,   132,   133,   134,   135,   136,   137,   138,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    34,    48,
     210,   151,   205,   224,    25,    71,   141,   142,   143,   227,
      69,    72,    74,    73,    78,    40,    63,   121,   174,   175,
     176,   114,   115,   139,    65,   118,   123,   166,   167,   168,
     169,   124,    49,    50,    51,   121,   144,   145,   193,   148,
     149,   177,   195,   152,    35,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,   153,   154,   157,   121,   121,
     121,   121,    75,    76,    41,    64,   158,   213,   214,   215,
     216,   217,   218,    66,   211,   212,    58,    59,    60,    61,
     125,   178,   179,    49,    50,    51,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   189,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,     1,     2,     3,    31,
     180,     6,   181,    77,   194,    49,    50,    51,   164,   196,
     197,   228,    30,   200,   201,   202,   203,   206,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    49,    50,
      51,   207,   219,   208,    14,   190,    80,    15,   220,   221,
      16,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,     1,     2,     3,     4,     5,     6,   165,     7,     8,
     222,     9,    10,    11,   229,    12,    85,   230,    13,    42,
     231,     1,     2,     3,    31,   232,     6,    44,   244,     1,
       2,     3,    31,   245,     6,   246,    49,    50,    51,    14,
     247,   248,    15,     0,     0,    16,     0,    17,    18,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    14,
       0,     0,    15,    86,     0,    16,     0,    14,     0,     0,
      15,     0,    88,    16,     1,     2,     3,    31,     0,     6,
      90,     0,     1,     2,     3,    31,     0,     6,    92,     0,
       1,     2,     3,    31,     0,     6,    94,     0,     1,     2,
       3,    31,     0,     6,    96,     0,     1,     2,     3,    31,
       0,     6,    14,     0,     0,    15,     0,     0,    16,     0,
      14,     0,     0,    15,     0,     0,    16,     0,    14,     0,
       0,    15,     0,     0,    16,     0,    14,     0,     0,    15,
       0,     0,    16,     0,    14,     0,     0,    15,     0,    98,
      16,     1,     2,     3,    31,     0,     6,   100,     0,     1,
       2,     3,    31,     0,     6,   102,     0,     1,     2,     3,
      31,     0,     6,   104,     0,     1,     2,     3,    31,     0,
       6,   106,     0,     1,     2,     3,    31,     0,     6,    14,
       0,     0,    15,     0,     0,    16,     0,    14,     0,     0,
      15,     0,     0,    16,     0,    14,     0,     0,    15,     0,
       0,    16,     0,    14,   140,     0,    15,     0,     0,    16,
       0,    14,     0,     0,    15,     0,   108,    16,     1,     2,
       3,    31,   161,     6,   110,     0,     1,     2,     3,    31,
       0,     6,   112,     0,     1,     2,     3,    31,     0,     6,
       0,     0,     0,     0,     0,   182,   183,   184,   185,     0,
       0,     0,     0,     0,     0,     0,    14,     0,     0,    15,
       0,     0,    16,    49,    14,    51,     0,    15,     0,     0,
      16,     0,    14,     0,     0,    15,     0,     0,    16,    49,
      50,    51,    58,    59,    60,    61,     0,     0,     0,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,     0,   129,    49,    50,    51,     0,     0,     0,
       0,     0,     0,   225,     0,     0,     0,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    49,    50,    51,
       0,     0,     0,     0,    62,     0,     0,     0,     0,     0,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      49,    50,    51,     0,     0,     0,     0,   186,     0,     0,
       0,     0,     0,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    49,    50,    51,     0,     0,     0,     0,
     187,     0,     0,     0,     0,     0,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    49,    50,    51,     0,
       0,     0,     0,   188,     0,     0,     0,     0,     0,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    49,
      50,    51,     0,     0,     0,    87,     0,     0,     0,     0,
       0,     0,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    49,    50,    51,     0,     0,     0,   162,     0,
       0,     0,     0,     0,     0,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    49,    50,    51,     0,     0,
       0,   163,     0,    49,    50,    51,     0,     0,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    54,    55,
      56,    57,    58,    59,    60,    61,    49,    50,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    58,    59,    60,    61
};

static const yytype_int16 yycheck[] =
{
      23,     8,     9,     1,    23,     1,     1,    14,    15,    16,
      17,     5,     1,    36,    37,     1,     1,    49,    25,     7,
      16,    40,    41,    42,    43,    42,    43,     1,     1,     1,
       1,    38,    39,    53,     1,    29,     1,     1,     1,     6,
      18,    19,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    53,    21,    22,    23,    54,
       1,     1,     1,     1,    53,     1,     1,    52,    54,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    53,
      53,    53,    53,     6,    78,    21,    22,    23,    52,    52,
      55,   114,   115,   116,   117,   118,   119,   120,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     1,     0,
      48,    52,    52,    52,    49,    50,   123,   124,   125,    55,
      50,     6,     1,    50,     7,     1,     1,   121,   149,   150,
     151,    52,    52,    56,     1,    52,    50,   144,   145,   146,
     147,     1,    21,    22,    23,   139,    16,    16,   171,    52,
      52,    12,   173,    53,    47,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    53,    53,    53,   162,   163,
     164,   165,    51,     1,    50,    50,    53,   200,   201,   202,
     203,   204,   205,    50,   191,   192,    40,    41,    42,    43,
      50,    12,    12,    21,    22,    23,   219,   220,   221,   222,
     223,   224,   225,   226,   227,     1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     3,     4,     5,     6,
      12,     8,    12,    51,    53,    21,    22,    23,     1,    53,
      53,    53,     7,    52,    52,    52,    52,    48,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    21,    22,
      23,    48,    52,    48,    41,    51,    35,    44,    52,    52,
      47,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     3,     4,     5,     6,     7,     8,    50,    10,    11,
      52,    13,    14,    15,    53,    17,     1,    53,    20,     1,
      53,     3,     4,     5,     6,    53,     8,     1,    53,     3,
       4,     5,     6,    53,     8,    53,    21,    22,    23,    41,
      53,    53,    44,    -1,    -1,    47,    -1,    49,    50,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    41,
      -1,    -1,    44,    48,    -1,    47,    -1,    41,    -1,    -1,
      44,    -1,     1,    47,     3,     4,     5,     6,    -1,     8,
       1,    -1,     3,     4,     5,     6,    -1,     8,     1,    -1,
       3,     4,     5,     6,    -1,     8,     1,    -1,     3,     4,
       5,     6,    -1,     8,     1,    -1,     3,     4,     5,     6,
      -1,     8,    41,    -1,    -1,    44,    -1,    -1,    47,    -1,
      41,    -1,    -1,    44,    -1,    -1,    47,    -1,    41,    -1,
      -1,    44,    -1,    -1,    47,    -1,    41,    -1,    -1,    44,
      -1,    -1,    47,    -1,    41,    -1,    -1,    44,    -1,     1,
      47,     3,     4,     5,     6,    -1,     8,     1,    -1,     3,
       4,     5,     6,    -1,     8,     1,    -1,     3,     4,     5,
       6,    -1,     8,     1,    -1,     3,     4,     5,     6,    -1,
       8,     1,    -1,     3,     4,     5,     6,    -1,     8,    41,
      -1,    -1,    44,    -1,    -1,    47,    -1,    41,    -1,    -1,
      44,    -1,    -1,    47,    -1,    41,    -1,    -1,    44,    -1,
      -1,    47,    -1,    41,   121,    -1,    44,    -1,    -1,    47,
      -1,    41,    -1,    -1,    44,    -1,     1,    47,     3,     4,
       5,     6,   139,     8,     1,    -1,     3,     4,     5,     6,
      -1,     8,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    44,
      -1,    -1,    47,    21,    41,    23,    -1,    44,    -1,    -1,
      47,    -1,    41,    -1,    -1,    44,    -1,    -1,    47,    21,
      22,    23,    40,    41,    42,    43,    -1,    -1,    -1,    21,
      22,    23,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    55,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    21,    22,    23,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      21,    22,    23,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    21,    22,    23,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    21,    22,    23,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    21,
      22,    23,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    21,    22,    23,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    21,    22,    23,    -1,    -1,
      -1,    50,    -1,    21,    22,    23,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    36,    37,
      38,    39,    40,    41,    42,    43,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    10,    11,    13,
      14,    15,    17,    20,    41,    44,    47,    49,    50,    58,
      59,    60,    61,    62,    67,    49,     1,     6,    60,     7,
      61,     6,    59,    59,     1,    47,     1,    52,     1,    54,
       1,    50,     1,    59,     1,    59,    59,    59,     0,    21,
      22,    23,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    51,     1,    50,     1,    50,    58,    59,    50,
       1,    50,     6,    50,     1,    51,     1,    51,     7,    64,
      64,    58,    58,    59,    59,     1,    48,    50,     1,    59,
       1,    59,     1,    59,     1,    59,     1,    59,     1,    59,
       1,    59,     1,    59,     1,    59,     1,    59,     1,    59,
       1,    59,     1,    59,    52,    52,     1,    52,    52,     1,
      52,    60,    63,    50,     1,    50,    53,     1,    53,    55,
       1,    55,    58,    58,    58,    58,    58,    58,    58,    56,
      63,    59,    59,    59,    16,    16,     1,    16,    52,    52,
       1,    52,    53,    53,    53,     1,    53,    53,    53,     1,
      53,    63,    50,    50,     1,    50,    59,    59,    59,    59,
      18,    19,    65,    66,    65,    65,    65,    12,    12,    12,
      12,    12,    63,    63,    63,    63,    51,    51,    51,     1,
      51,     1,    54,    58,    53,    65,    53,    53,     1,    53,
      52,    52,    52,    52,     1,    52,    48,    48,    48,     1,
      48,    59,    59,    58,    58,    58,    58,    58,    58,    52,
      52,    52,    52,     1,    52,    55,     1,    55,    53,    53,
      53,    53,    53,     1,    53,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    53,    53,    53,    53,    53,     1,
      53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    60,    61,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    63,    63,    63,    64,
      65,    65,    66,    66,    66,    66,    67,    67,    67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     2,     1,     2,     2,     3,     3,     6,
      10,     6,     7,    11,     7,     2,     2,     2,     2,     3,
       3,     6,     6,     6,    10,    10,    10,    10,    10,     6,
       6,     6,     7,     7,     7,     7,    11,    11,    11,    11,
      11,    11,     7,     7,     7,     7,     3,     2,     0,     2,
       2,     0,     5,     2,     5,     5,     2,     3,     5,     9
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 88 "p_test.y" /* yacc.c:1646  */
    { if((yyvsp[-1].node)==NULL) (yyval.node) = (yyvsp[0].node); else { printf("%s\n", "list matched"); (yyval.node) = newLIST((yyvsp[-1].node), (yyvsp[0].node));} }
#line 1650 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 89 "p_test.y" /* yacc.c:1646  */
    { printf("%s\n", "empty list matched");(yyval.node) = NULL; }
#line 1656 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 94 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1662 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 95 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP('+', (yyvsp[-2].node), (yyvsp[0].node), yylineno); }
#line 1668 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 96 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP('-', (yyvsp[-2].node), (yyvsp[0].node), yylineno); }
#line 1674 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 97 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP('/', (yyvsp[-2].node), (yyvsp[0].node), yylineno); }
#line 1680 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 98 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP('*', (yyvsp[-2].node), (yyvsp[0].node), yylineno); }
#line 1686 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 99 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP(UMINUS, (yyvsp[0].node), NULL, yylineno); }
#line 1692 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 100 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP(AND,(yyvsp[-2].node), (yyvsp[0].node), yylineno); }
#line 1698 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 101 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP(OR, (yyvsp[-2].node), (yyvsp[0].node), yylineno); }
#line 1704 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 102 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP(XOR, (yyvsp[-2].node), (yyvsp[0].node), yylineno); }
#line 1710 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 103 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP(EE, (yyvsp[-2].node), (yyvsp[0].node), yylineno); }
#line 1716 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 104 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP(NE, (yyvsp[-2].node), (yyvsp[0].node), yylineno); }
#line 1722 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 105 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP(LT, (yyvsp[-2].node), (yyvsp[0].node), yylineno); }
#line 1728 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 106 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP(GT, (yyvsp[-2].node), (yyvsp[0].node), yylineno); }
#line 1734 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 107 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP(LE, (yyvsp[-2].node), (yyvsp[0].node), yylineno); }
#line 1740 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 108 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP(GE, (yyvsp[-2].node), (yyvsp[0].node), yylineno); }
#line 1746 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 109 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newEXP(NOT, (yyvsp[0].node), NULL, yylineno); }
#line 1752 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 110 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newBOOL((yyvsp[0].i), yylineno); }
#line 1758 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 111 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newINT((yyvsp[0].i), yylineno); }
#line 1764 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 112 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newDOUBLE((yyvsp[0].d), yylineno); }
#line 1770 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 113 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newSTRING((yyvsp[0].s), yylineno); }
#line 1776 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 114 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newID((yyvsp[0].s), yylineno);  id_semantics((yyval.node)); }
#line 1782 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 117 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; yyerror("EEEE106\n"); fprintf(syn_errors_file, "right parenthesis is missing at %d : %d\n", (yylsp[-1]).last_line, (yylsp[-1]).last_column);}
#line 1788 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 118 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; yyerror("EEEE90\n"); fprintf(syn_errors_file, "RHS of \'+\' is not a valid expression %d\n", (yylsp[-1]).last_line); }
#line 1794 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 119 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; yyerror("EEEE91\n"); fprintf(syn_errors_file, "RHS of \'-\' is not a valid expression %d\n", (yylsp[-1]).last_line); }
#line 1800 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 120 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; yyerror("EEEE92\n"); fprintf(syn_errors_file, "RHS of \'/\' is not a valid expression %d\n", (yylsp[-1]).last_line); }
#line 1806 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 121 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; yyerror("EEEE94\n"); fprintf(syn_errors_file, "RHS of \'*\' is not a valid expression %d\n", (yylsp[-1]).last_line); }
#line 1812 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 122 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; yyerror("EEEE95\n"); fprintf(syn_errors_file, "RHS of unary \'-\' is not a valid expression %d\n", (yylsp[-1]).last_line); }
#line 1818 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 123 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; yyerror("EEEE96\n"); fprintf(syn_errors_file, "RHS of \"&&\" is not a valid expression %d\n", (yylsp[-1]).last_line); }
#line 1824 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 124 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; yyerror("EEEE97\n"); fprintf(syn_errors_file, "RHS of \"||\" is not a valid expression %d\n", (yylsp[-1]).last_line); }
#line 1830 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 125 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; yyerror("EEEE98\n"); fprintf(syn_errors_file, "RHS of \"^\" is not a valid expression %d\n", (yylsp[-1]).last_line); }
#line 1836 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 126 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; yyerror("EEEE99\n"); fprintf(syn_errors_file, "RHS of \"==\" is not a valid expression %d\n", (yylsp[-1]).last_line); }
#line 1842 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 127 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; yyerror("EEEE100\n"); fprintf(syn_errors_file, "RHS of \"!=\" is not a valid expression %d\n", (yylsp[-1]).last_line); }
#line 1848 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 128 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; yyerror("EEEE101\n"); fprintf(syn_errors_file, "RHS of \"<\" is not a valid expression %d\n", (yylsp[-1]).last_line); }
#line 1854 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 129 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; yyerror("EEEE102\n"); fprintf(syn_errors_file, "RHS of \">\" is not a valid expression %d\n", (yylsp[-1]).last_line); }
#line 1860 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 130 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; yyerror("EEEE103\n"); fprintf(syn_errors_file, "RHS of \"<=\" is not a valid expression %d\n", (yylsp[-1]).last_line); }
#line 1866 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 131 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; yyerror("EEEE104\n"); fprintf(syn_errors_file, "RHS of \">=\" is not a valid expression %d\n", (yylsp[-1]).last_line); }
#line 1872 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 132 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; yyerror("EEEE105\n"); fprintf(syn_errors_file, "RHS of \'!\' is not a valid expression %d\n", (yylsp[-1]).last_line); }
#line 1878 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 135 "p_test.y" /* yacc.c:1646  */
    { if((yyvsp[0].node) != NULL){ printf("%s ID = %s\n", "assi_stmnt matched", (yyvsp[-2].s));  (yyval.node) = newSTMNT(3, ASSI_STMNT, (yyvsp[-2].s), (yyvsp[0].node)); } 
		    							  else { (yyval.node)=NULL; yyerror("EEEE107\n"); fprintf(syn_errors_file, "RHS of \'=\' is not a valid expression %d\n", (yylsp[-2]).last_line);}  }
#line 1885 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 139 "p_test.y" /* yacc.c:1646  */
    { if((yyvsp[0].node) != NULL) (yyval.node) = newSTMNT(3, DECL_ASSI_STMNT, (yyvsp[-1].s), (yyvsp[0].node)); else { (yyval.node)=NULL; fprintf(syn_errors_file, "Invalid declaration statement at line %d\n", (yylsp[-1]).first_line);} }
#line 1891 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 142 "p_test.y" /* yacc.c:1646  */
    { printf("%s\n", "Empty statement"); (yyval.node) = newSTMNT(1, EMPTY_STMNT);}
#line 1897 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 143 "p_test.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].node) != NULL) {(yyval.node) = (yyvsp[-1].node); printf("assi_stmnt"); assi_stmnt_semantics((yyval.node));} else (yyval.node) = NULL;  }
#line 1903 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 144 "p_test.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].node) != NULL) {(yyval.node) = (yyvsp[-1].node); printf("%s\n", "decl_stmnt"); decl_assi_stmnt_semantics((yyval.node));} else (yyval.node)=NULL; }
#line 1909 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 145 "p_test.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].node) != NULL) {(yyval.node) = newSTMNT(3, CONST_DECL_STMNT, 1, (yyvsp[-1].node)); printf("%s\n", "decl_stmnt with const"); const_decl_stmnt_semantics((yyval.node));} else (yyval.node)=NULL; }
#line 1915 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 146 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newSTMNT(3, DECL_STMNT, (yyvsp[-2].s), (yyvsp[-1].s)); printf("decl without initialization"); decl_stmnt_semantics((yyval.node)); }
#line 1921 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 148 "p_test.y" /* yacc.c:1646  */
    { if((yyvsp[-4].node) !=NULL) {(yyval.node) = newFLOW(IF, (yyvsp[-4].node), (yyvsp[-1].node), NULL); printf("%s\n", "IF without else"); flow_semantics((yyval.node));}
		  																else { (yyval.node)=NULL; yyerror("EEEE108\n"); fprintf(syn_errors_file, "Invalid IF statement at  line %d\n", (yylsp[-5]).last_line);} }
#line 1928 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 151 "p_test.y" /* yacc.c:1646  */
    { if((yyvsp[-8].node) !=NULL) {(yyval.node) = newFLOW(IF, (yyvsp[-8].node), (yyvsp[-5].node), (yyvsp[-1].node)); printf("%s\n", "IF with else"); flow_semantics((yyval.node));}
		  																else { (yyval.node)=NULL; yyerror("EEEE108\n"); fprintf(syn_errors_file, "Invalid IF statement at  line %d\n", (yylsp[-9]).last_line);} }
#line 1935 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 154 "p_test.y" /* yacc.c:1646  */
    { if((yyvsp[-4].node) != NULL) {(yyval.node) = newFLOW(WHILE, (yyvsp[-4].node), (yyvsp[-1].node), NULL); printf("%s\n", "while loop"); flow_semantics((yyval.node));}
		  																else { (yyval.node)=NULL; yyerror("EEEE109\n"); fprintf(syn_errors_file, "Invalid while statement at  line %d\n", (yylsp[-5]).last_line);} }
#line 1942 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 157 "p_test.y" /* yacc.c:1646  */
    { if((yyvsp[-1].node) !=NULL) {(yyval.node) = newFLOW(REPEAT, (yyvsp[-1].node), (yyvsp[-4].node), NULL); printf("%s\n", "repeat loop"); flow_semantics((yyval.node));}
		  																else { (yyval.node)=NULL; yyerror("EEEE110\n"); fprintf(syn_errors_file, "Invalid repeat statement at  line %d\n", (yylsp[-6]).last_line);} }
#line 1949 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 160 "p_test.y" /* yacc.c:1646  */
    { if((yyvsp[-8].node) != NULL && (yyvsp[-6].node) != NULL && (yyvsp[-4].node) !=NULL) {(yyval.node) = newFOR((yyvsp[-8].node), (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-1].node)); printf("%s\n", "for loop"); for_semantics((yyval.node));}
		  																else{ (yyval.node)=NULL;  yyerror("EEEE111\n"); fprintf(syn_errors_file, "Invalid for statement at  line %d\n", (yylsp[-10]).last_line); } }
#line 1956 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 163 "p_test.y" /* yacc.c:1646  */
    { if((yyvsp[-4].node) != NULL && (yyvsp[-1].node) !=NULL) { (yyval.node) = newSWITCH((yyvsp[-4].node), (yyvsp[-1].node)); printf("%s\n", "switch statement"); switch_semantics((yyval.node));}
		  																else { (yyval.node)=NULL; yyerror("EEEE112\n"); fprintf(syn_errors_file, "Invalid switch statement at  line %d\n", (yylsp[-6]).last_line); } }
#line 1963 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 165 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newNODE(BREAK); }
#line 1969 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 166 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE1\n"); fprintf(syn_errors_file, "semicolon missing at line %d\n", (yylsp[-1]).last_line); }
#line 1975 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 168 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE1\n"); fprintf(syn_errors_file, "semicolon missing at line %d\n", yylineno); }
#line 1981 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 169 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE2\n"); fprintf(syn_errors_file, "semicolon missing at line %d\n", yylineno); }
#line 1987 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 170 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE3\n"); fprintf(syn_errors_file, "semicolon missing at line %d\n", yylineno); }
#line 1993 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 171 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE4\n"); fprintf(syn_errors_file, "Identifier name is missing at line %d\n", yylineno); }
#line 1999 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 174 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE5\n"); fprintf(syn_errors_file, "right brace expected at end of IF body at line %d\n", yylineno); }
#line 2005 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 175 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE6\n"); fprintf(syn_errors_file, "IF branch left brace is missing at line %d\n", ((Exp*)(yyvsp[-4].node))->linenum); }
#line 2011 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 176 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE7\n"); fprintf(syn_errors_file, "Colon expected after IF cond. at line %d\n", ((Exp*)(yyvsp[-4].node))->linenum); }
#line 2017 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 177 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE8\n"); fprintf(syn_errors_file, "else branch right brace is missing at line %d", yylineno); }
#line 2023 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 178 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE10\n"); fprintf(syn_errors_file, "else branch left brace is missing at line %d", (yylsp[-3]).first_line); }
#line 2029 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 179 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE11\n"); fprintf(syn_errors_file, "IF branch right brace missing at line %d\n", (yylsp[-3]).first_line);}
#line 2035 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 180 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE12\n"); fprintf(syn_errors_file, "IF branch left brace is missing at line %d\n", (yylsp[-7]).first_line);}
#line 2041 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 181 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE13\n"); fprintf(syn_errors_file, "Colon expected after IF cond. at line %d\n", ((Exp*)(yyvsp[-8].node))->linenum);}
#line 2047 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 185 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE14\n"); fprintf(syn_errors_file, "right brace of while loop body is missing at line%d\n", yylineno); }
#line 2053 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 186 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE15\n"); fprintf(syn_errors_file, "left brace of while loop body is missing at line%d\n", (yylsp[-3]).first_line); }
#line 2059 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 187 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE16\n"); fprintf(syn_errors_file, "Colon expected after while cond. at line %d\n", ((Exp*)(yyvsp[-4].node))->linenum); }
#line 2065 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 190 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE17\n"); fprintf(syn_errors_file, "Colon expected after repeat cond at line %d\n", ((Exp*)(yyvsp[-1].node))->linenum);}
#line 2071 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 191 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE18\n"); fprintf(syn_errors_file, "Untill keyword is missing after repeat body at line %d\n", (yylsp[-3]).first_line);}
#line 2077 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 192 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE19\n"); fprintf(syn_errors_file, "right brace of repeat loop body is missing at line%d\n", (yylsp[-2]).first_line);}
#line 2083 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 193 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE20\n"); fprintf(syn_errors_file, "right brace of repeat loop body is missing at line%d\n", (yylsp[-6]).first_line);}
#line 2089 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 196 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE21\n"); fprintf(syn_errors_file, "right brace of for loop body is missing at line %d\n", (yylsp[-1]).first_line);}
#line 2095 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 197 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE22\n"); fprintf(syn_errors_file, "left brace of for loop body is missing at line %d\n", (yylsp[-3]).first_line);}
#line 2101 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 198 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE23\n"); fprintf(syn_errors_file, "right parenthesis of for loop header is missing at line %d\n", (yylsp[-4]).first_line);}
#line 2107 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 199 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE24\n"); fprintf(syn_errors_file, "semicolon is missing after for loop stop condition at %d : %d\n", (yylsp[-6]).last_line, (yylsp[-6]).last_column);}
#line 2113 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 200 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE25\n"); fprintf(syn_errors_file, "semicolon is missing after for loop declaration list at %d : %d\n", (yylsp[-8]).last_line, (yylsp[-8]).last_column);}
#line 2119 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 201 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE26\n"); fprintf(syn_errors_file, "left parenthesis of for loop header is missing at %d : %d\n", (yylsp[-10]).last_line, (yylsp[-10]).last_column);}
#line 2125 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 204 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE27\n"); fprintf(syn_errors_file, "right brace of switch body is missing at line %d \n", (yylsp[-1]).last_line);}
#line 2131 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 205 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE28\n"); fprintf(syn_errors_file, "left brace of switch body is missing at line %d \n", (yylsp[-3]).last_line);}
#line 2137 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 206 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE29\n"); fprintf(syn_errors_file, "right bracket of switch expression is missing at line %d \n", (yylsp[-4]).last_line);}
#line 2143 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 207 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE30\n"); fprintf(syn_errors_file, "left bracket of switch expression is missing at line %d \n", (yylsp[-6]).last_line);}
#line 2149 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 213 "p_test.y" /* yacc.c:1646  */
    { if((yyvsp[-2].node) !=NULL) {printf("assi_list matched\n");(yyval.node) = newALIST((yyvsp[-2].node), (yyvsp[0].node));}
													  else (yyval.node)=NULL; }
#line 2156 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 215 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE31\n"); fprintf(syn_errors_file, "comma is missing at %d : %d\n", (yylsp[-1]).last_line, (yylsp[-1]).last_column); }
#line 2162 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 216 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;}
#line 2168 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 219 "p_test.y" /* yacc.c:1646  */
    { if((yyvsp[0].node) != NULL) {(yyval.node) = newDLIST((yyvsp[-1].s), (yyvsp[0].node)); decl_list_semantics((yyvsp[0].node));}
													  else (yyval.node)=NULL; }
#line 2175 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 224 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newSBODY((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2181 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 225 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 2187 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 228 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newCASE(CASE, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2193 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 229 "p_test.y" /* yacc.c:1646  */
    { (yyval.node) = newCASE(DEFAULT, NULL, (yyvsp[0].node)); }
#line 2199 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 230 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE29\n"); fprintf(syn_errors_file, "right bracket of case expression is missing at line %d \n", (yylsp[-2]).last_line); }
#line 2205 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 231 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE29\n"); fprintf(syn_errors_file, "left bracket of case expression is missing at line %d \n", (yylsp[-2]).last_line);}
#line 2211 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 236 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE677"); fprintf(syn_errors_file, "Identifier missing at the begining of assign. statement at %d : %d\n",(yylsp[-1]).first_line, (yylsp[-1]).first_column ); }
#line 2217 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 237 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE677"); fprintf(syn_errors_file, "Identifier missing at the begining of assign. statement at %d : %d\n",(yylsp[-2]).first_line, (yylsp[-2]).first_column ); }
#line 2223 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 238 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE677"); fprintf(syn_errors_file, "IF or While keyword is missing at the begining of assign. statement at %d : %d\n",(yylsp[-4]).first_line, (yylsp[-4]).first_column ); }
#line 2229 "p_test.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 239 "p_test.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; yyerror("EEEE677"); fprintf(syn_errors_file, "IF keyword is missing at the begining of assign. statement at %d : %d\n",(yylsp[-8]).first_line, (yylsp[-8]).first_column ); }
#line 2235 "p_test.tab.c" /* yacc.c:1646  */
    break;


#line 2239 "p_test.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 247 "p_test.y" /* yacc.c:1906  */

void yyerror(char *s) {

	error_count++;
	if(error_count >20)
	{
		fclose(sem_errors_file);
		fclose(syn_errors_file);
		printf("your program Exceeded max number of syntax errors, solve them and try again\n");
		printf("program aborted\n");
		exit(0);
	}

	fprintf(stderr,"%s", s);
}

int main(int argc, char **argv) {
	
	if(argc > 1) {
		if(!(yyin = fopen(argv[1], "r"))) {
			perror(argv[1]);
			return (1);
		}
	}
	sem_errors_file = fopen("semantic errors.txt", "w");
	syn_errors_file = fopen("syntax errors.txt", "w");
	
	yyparse();
	
	fclose(sem_errors_file);
	fclose(syn_errors_file);
	
	generate_symbols_file(table);
	
	return 0;
}


#include "create.c"
