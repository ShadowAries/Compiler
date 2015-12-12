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
#line 1 "parser.y" /* yacc.c:339  */

    #include <stdio.h>
    #include <stdlib.h>
    #include <iostream>

    #include "ast.hpp"
    #define YYMAXDEPTH      500
    #define YYDEBUG 1
     #define YYINITDEPTH 500
    int yylex(void);
    void yyerror(const char *);
    
    extern ASTNode* astRoot;

#line 81 "parser.cpp" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
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
    T_ARROW = 258,
    T_PLUS = 259,
    T_MINUS = 260,
    T_MULT = 261,
    T_DIVIDE = 262,
    T_AND = 263,
    T_OR = 264,
    T_NOT = 265,
    T_OPAREN = 266,
    T_CPAREN = 267,
    T_OBRACET = 268,
    T_CBRACET = 269,
    T_SEMICOLON = 270,
    T_COMMA = 271,
    T_DOT = 272,
    T_ASSIGNMENT = 273,
    T_LESSEQ = 274,
    T_LESS = 275,
    T_EQUALS = 276,
    T_IFSTMNT = 277,
    T_ELSESTMNT = 278,
    T_WHILESTMNT = 279,
    T_REPEATSTMNT = 280,
    T_UNTILSTMNT = 281,
    T_PRINTSTMNT = 282,
    T_LITERAL = 283,
    T_TRUE = 284,
    T_FALSE = 285,
    T_BOOLEAN = 286,
    T_INTEGER = 287,
    T_NONE = 288,
    T_NEW = 289,
    T_EXTENDS = 290,
    T_EOF = 291,
    T_COLON = 292,
    T_RETURN = 293,
    T_CLASS = 294,
    T_IDENTIFIER = 295,
    NOT = 296,
    UNARYMINUS = 297
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 170 "parser.cpp" /* yacc.c:358  */

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   303

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   112,   112,   113,   114,   117,   122,   123,   125,   126,
     127,   128,   130,   131,   132,   136,   137,   138,   140,   141,
     143,   144,   145,   146,   148,   149,   151,   152,   154,   156,
     157,   158,   159,   162,   163,   165,   167,   168,   171,   172,
     175,   176,   178,   179,   180,   181,   182,   183,   185,   186,
     188,   190,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   212,   213,   215,   216,   217,   218,   220,   221,   222,
     225,   227,   229,   230,   232
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_ARROW", "T_PLUS", "T_MINUS", "T_MULT",
  "T_DIVIDE", "T_AND", "T_OR", "T_NOT", "T_OPAREN", "T_CPAREN",
  "T_OBRACET", "T_CBRACET", "T_SEMICOLON", "T_COMMA", "T_DOT",
  "T_ASSIGNMENT", "T_LESSEQ", "T_LESS", "T_EQUALS", "T_IFSTMNT",
  "T_ELSESTMNT", "T_WHILESTMNT", "T_REPEATSTMNT", "T_UNTILSTMNT",
  "T_PRINTSTMNT", "T_LITERAL", "T_TRUE", "T_FALSE", "T_BOOLEAN",
  "T_INTEGER", "T_NONE", "T_NEW", "T_EXTENDS", "T_EOF", "T_COLON",
  "T_RETURN", "T_CLASS", "T_IDENTIFIER", "NOT", "UNARYMINUS", "$accept",
  "START", "CLASSES", "CLASS", "INHERITS", "CLASS_BLOCK", "MEMBERS",
  "MEMBER", "MEMBER_TYPES", "METHODS", "RETURN_MEMBER_TYPES", "METHOD",
  "PARAMETERS", "PARM", "BODY", "DECLRATION_STATEMENTS", "X",
  "DECLARATION", "RETURN_CONTROL", "STATEMENTS", "STATEMENT", "ASSIGNING",
  "WHILELOOP", "MEMBER_ACCESS", "EXPRESSION", "ARGUMENTS", "METHODCALL",
  "CLASS_NAME", "REPEAT_UNTIL", "IF_ELSE", "ELSE_BLOCK", "PRINT", YY_NULLPTR
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
     295,   296,   297
};
# endif

#define YYPACT_NINF -127

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-127)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -38,   -12,    40,   -38,  -127,    10,    47,  -127,  -127,  -127,
      23,  -127,  -127,    59,    74,    23,    58,    61,    78,  -127,
      -7,  -127,    83,    78,  -127,  -127,    59,  -127,    96,    90,
      68,  -127,  -127,    11,    25,   113,    91,  -127,  -127,  -127,
    -127,   123,  -127,  -127,    11,  -127,   147,   124,    -2,    -2,
     126,    -2,    -2,    76,    93,   132,   147,   133,  -127,   164,
    -127,   134,  -127,   135,   138,  -127,   139,   147,    -2,    -2,
      -2,  -127,  -127,  -127,   112,    -5,  -127,   192,  -127,   210,
     168,   273,   228,    19,   117,    -2,  -127,   142,  -127,   152,
    -127,   164,  -127,    76,  -127,  -127,  -127,  -127,  -127,  -127,
     156,  -127,  -127,   246,   162,  -127,   136,    -2,    -2,    -2,
      -2,    -2,    -2,   168,    -2,    -2,    -2,   168,   116,  -127,
    -127,   273,    73,    50,   273,   140,  -127,  -127,  -127,  -127,
      92,   171,   103,   103,  -127,  -127,   282,   220,   120,   255,
     255,   255,   137,   149,  -127,    -2,    95,    -2,  -127,  -127,
      79,   160,  -127,   173,   273,  -127,    99,   273,  -127,   181,
    -127,    -2,  -127,   168,   264,   141,  -127,  -127
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,     0,     2,     4,     0,     0,     1,     3,     6,
      11,    15,    16,    17,     0,     9,     0,     0,    10,    19,
       0,     5,     0,     8,    13,    14,     0,    18,     0,     0,
       0,    27,    12,     0,     0,     0,     0,    20,    21,    23,
      22,     0,    17,    28,     0,    26,    39,     0,     0,     0,
       0,     0,     0,    17,     0,     0,    39,     0,    32,    39,
      41,     0,    44,     0,     0,    47,     0,    39,     0,     0,
       0,    64,    68,    69,     0,    66,    65,     0,    67,     0,
       0,    84,     0,     0,     0,     0,    37,    35,    25,     0,
      30,    39,    34,     0,    31,    40,    43,    42,    45,    46,
       0,    62,    63,     0,    77,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      74,    72,     0,     0,    49,     0,    33,    29,    24,    52,
       0,    51,    57,    59,    60,    61,    53,    54,     0,    55,
      56,    58,     0,     0,    73,     0,     0,     0,    36,    79,
       0,    83,    50,     0,    71,    76,     0,    48,    78,     0,
      81,     0,    75,     0,     0,     0,    80,    82
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,  -127,   200,  -127,  -127,  -127,   191,     7,   194,
     163,    46,  -127,   174,   153,  -127,   165,  -127,   -45,   -55,
     -52,  -127,  -127,  -127,   -33,  -126,   -46,  -127,  -127,  -127,
    -127,  -127
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     6,    14,    15,    16,    54,    18,
      41,    19,    30,    31,    55,    56,    57,    87,    58,    59,
      60,    61,    62,    76,   121,   122,    78,   105,    64,    65,
     160,    66
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      63,    91,     1,    68,   150,    28,    83,    95,    69,    70,
      63,    90,   106,    63,    94,    77,    79,    17,    81,    82,
     156,    63,    17,     5,    68,   118,    71,    72,    73,    69,
      70,   120,    74,    29,    63,   101,   102,   103,    75,    95,
       7,    43,    37,    38,    39,    63,   127,    71,    72,    73,
       9,    40,   124,    74,    11,    12,    11,    12,   138,    75,
      10,   146,   142,    13,    27,    42,    95,    63,   147,    27,
      20,    63,    63,    24,   132,   133,   134,   135,   136,   137,
      35,   139,   140,   141,    36,   144,    95,    83,    21,   145,
      95,   158,    63,    84,    85,   145,    63,    68,    32,    33,
      68,    25,    69,    70,   149,    69,    70,   155,   165,   109,
     110,   162,   154,    95,   157,   145,    44,    63,    26,    63,
      71,    72,    73,    71,    72,    73,    74,    34,   164,    74,
     143,    29,    75,    86,   151,    75,    46,    67,    48,    80,
      49,    50,    48,    51,    49,    50,    88,    51,    92,    96,
      97,   152,   104,    98,    99,   167,    93,   123,   125,    48,
      93,    49,    50,    48,    51,    49,    50,   126,    51,    48,
     128,    49,    50,   130,    51,   153,   131,    93,    11,    12,
     148,    93,   146,   159,   161,    52,    48,    53,    49,    50,
      48,    51,    49,    50,   163,    51,   107,   108,   109,   110,
     111,   112,    52,     8,    93,   113,    22,    47,    93,    23,
      45,   114,   115,   116,   107,   108,   109,   110,   111,   112,
     100,    89,     0,   117,   107,   108,   109,   110,   111,   114,
     115,   116,   107,   108,   109,   110,   111,   112,     0,   114,
     115,   116,     0,   119,     0,     0,     0,   114,   115,   116,
     107,   108,   109,   110,   111,   112,     0,     0,   129,   107,
     108,   109,   110,     0,     0,   114,   115,   116,   107,   108,
     109,   110,   111,   112,     0,     0,   166,   107,   108,   109,
     110,   111,   112,   114,   115,   116,   107,   108,   109,   110,
       0,     0,   114,   115,   116,     0,     0,     0,     0,     0,
       0,   114,   115,   116
};

static const yytype_int16 yycheck[] =
{
      46,    56,    40,     5,   130,    12,    11,    59,    10,    11,
      56,    56,    17,    59,    59,    48,    49,    10,    51,    52,
     146,    67,    15,    35,     5,    80,    28,    29,    30,    10,
      11,    12,    34,    40,    80,    68,    69,    70,    40,    91,
       0,    34,    31,    32,    33,    91,    91,    28,    29,    30,
      40,    40,    85,    34,    31,    32,    31,    32,   113,    40,
      13,    11,   117,    40,    18,    40,   118,   113,    18,    23,
      11,   117,   118,    15,   107,   108,   109,   110,   111,   112,
      12,   114,   115,   116,    16,    12,   138,    11,    14,    16,
     142,    12,   138,    17,    18,    16,   142,     5,    15,     3,
       5,    40,    10,    11,    12,    10,    11,    12,   163,     6,
       7,    12,   145,   165,   147,    16,     3,   163,    40,   165,
      28,    29,    30,    28,    29,    30,    34,    37,   161,    34,
      14,    40,    40,    40,    14,    40,    13,    13,    22,    13,
      24,    25,    22,    27,    24,    25,    14,    27,    15,    15,
      15,    14,    40,    15,    15,    14,    40,    40,    16,    22,
      40,    24,    25,    22,    27,    24,    25,    15,    27,    22,
      14,    24,    25,    11,    27,    26,    40,    40,    31,    32,
      40,    40,    11,    23,    11,    38,    22,    40,    24,    25,
      22,    27,    24,    25,    13,    27,     4,     5,     6,     7,
       8,     9,    38,     3,    40,    13,    15,    44,    40,    15,
      36,    19,    20,    21,     4,     5,     6,     7,     8,     9,
      67,    56,    -1,    13,     4,     5,     6,     7,     8,    19,
      20,    21,     4,     5,     6,     7,     8,     9,    -1,    19,
      20,    21,    -1,    15,    -1,    -1,    -1,    19,    20,    21,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,     4,
       5,     6,     7,    -1,    -1,    19,    20,    21,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,     4,     5,     6,
       7,     8,     9,    19,    20,    21,     4,     5,     6,     7,
      -1,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    44,    45,    46,    35,    47,     0,    46,    40,
      13,    31,    32,    40,    48,    49,    50,    51,    52,    54,
      11,    14,    50,    52,    15,    40,    40,    54,    12,    40,
      55,    56,    15,     3,    37,    12,    16,    31,    32,    33,
      40,    53,    40,    51,     3,    56,    13,    53,    22,    24,
      25,    27,    38,    40,    51,    57,    58,    59,    61,    62,
      63,    64,    65,    69,    71,    72,    74,    13,     5,    10,
      11,    28,    29,    30,    34,    40,    66,    67,    69,    67,
      13,    67,    67,    11,    17,    18,    40,    60,    14,    59,
      61,    62,    15,    40,    61,    63,    15,    15,    15,    15,
      57,    67,    67,    67,    40,    70,    17,     4,     5,     6,
       7,     8,     9,    13,    19,    20,    21,    13,    62,    15,
      12,    67,    68,    40,    67,    16,    15,    61,    14,    12,
      11,    40,    67,    67,    67,    67,    67,    67,    62,    67,
      67,    67,    62,    14,    12,    16,    11,    18,    40,    12,
      68,    14,    14,    26,    67,    12,    68,    67,    12,    23,
      73,    11,    12,    13,    67,    62,    12,    14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    47,    47,    48,    48,
      48,    48,    49,    49,    50,    51,    51,    51,    52,    52,
      53,    53,    53,    53,    54,    54,    55,    55,    56,    57,
      57,    57,    57,    58,    58,    59,    60,    60,    61,    61,
      62,    62,    63,    63,    63,    63,    63,    63,    64,    64,
      65,    66,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    68,    68,    69,    69,    69,    69,    70,    70,    70,
      71,    72,    73,    73,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     5,     2,     0,     2,     1,
       1,     0,     3,     2,     2,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     9,     8,     3,     1,     3,     3,
       2,     2,     1,     3,     2,     2,     3,     1,     3,     0,
       2,     1,     2,     2,     1,     2,     2,     1,     5,     3,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     1,     1,     1,     1,     1,     1,
       2,     3,     1,     4,     3,     6,     5,     1,     4,     3,
       8,     6,     4,     0,     2
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
#line 112 "parser.y" /* yacc.c:1661  */
    {(yyval.program_ptr)= new ProgramNode((yyvsp[0].class_list_ptr)); astRoot=(yyval.program_ptr);}
#line 1393 "parser.cpp" /* yacc.c:1661  */
    break;

  case 3:
#line 113 "parser.y" /* yacc.c:1661  */
    {(yyval.class_list_ptr)= (yyvsp[-1].class_list_ptr); (yyval.class_list_ptr)->push_back((yyvsp[0].class_ptr));}
#line 1399 "parser.cpp" /* yacc.c:1661  */
    break;

  case 4:
#line 114 "parser.y" /* yacc.c:1661  */
    {(yyval.class_list_ptr)= new std::list<ClassNode*>(); (yyval.class_list_ptr)->push_back((yyvsp[0].class_ptr));}
#line 1405 "parser.cpp" /* yacc.c:1661  */
    break;

  case 5:
#line 117 "parser.y" /* yacc.c:1661  */
    {(yyvsp[-1].class_ptr)->identifier_1= (yyvsp[-4].identifier_ptr);
                                                               (yyvsp[-1].class_ptr)->identifier_2= (yyvsp[-3].identifier_ptr);
                                                               (yyval.class_ptr)=(yyvsp[-1].class_ptr); }
#line 1413 "parser.cpp" /* yacc.c:1661  */
    break;

  case 6:
#line 122 "parser.y" /* yacc.c:1661  */
    {(yyval.identifier_ptr)= (yyvsp[0].identifier_ptr);}
#line 1419 "parser.cpp" /* yacc.c:1661  */
    break;

  case 7:
#line 123 "parser.y" /* yacc.c:1661  */
    {(yyval.identifier_ptr)= NULL;}
#line 1425 "parser.cpp" /* yacc.c:1661  */
    break;

  case 8:
#line 125 "parser.y" /* yacc.c:1661  */
    {(yyval.class_ptr)= new ClassNode(NULL, NULL, (yyvsp[-1].declaration_list_ptr), (yyvsp[0].method_list_ptr)    ); }
#line 1431 "parser.cpp" /* yacc.c:1661  */
    break;

  case 9:
#line 126 "parser.y" /* yacc.c:1661  */
    {(yyval.class_ptr)= new ClassNode(NULL, NULL, (yyvsp[0].declaration_list_ptr), NULL  ); }
#line 1437 "parser.cpp" /* yacc.c:1661  */
    break;

  case 10:
#line 127 "parser.y" /* yacc.c:1661  */
    {(yyval.class_ptr)= new ClassNode(NULL, NULL, NULL, (yyvsp[0].method_list_ptr)  ); }
#line 1443 "parser.cpp" /* yacc.c:1661  */
    break;

  case 11:
#line 128 "parser.y" /* yacc.c:1661  */
    {(yyval.class_ptr)= new ClassNode(NULL, NULL, NULL, NULL); }
#line 1449 "parser.cpp" /* yacc.c:1661  */
    break;

  case 12:
#line 130 "parser.y" /* yacc.c:1661  */
    {(yyval.declaration_list_ptr)= (yyvsp[-2].declaration_list_ptr); (yyval.declaration_list_ptr)->push_back((yyvsp[-1].declaration_ptr));}
#line 1455 "parser.cpp" /* yacc.c:1661  */
    break;

  case 13:
#line 131 "parser.y" /* yacc.c:1661  */
    {(yyval.declaration_list_ptr)= new std::list<DeclarationNode*>(); (yyval.declaration_list_ptr)->push_back((yyvsp[-1].declaration_ptr));}
#line 1461 "parser.cpp" /* yacc.c:1661  */
    break;

  case 14:
#line 132 "parser.y" /* yacc.c:1661  */
    {std::list<IdentifierNode*> *s = new std::list<IdentifierNode*>();
                                       s->push_back((yyvsp[0].identifier_ptr));
                                       (yyval.declaration_ptr)= new DeclarationNode((yyvsp[-1].type_ptr),s); (yyval.declaration_ptr)->objectClassName= (yyvsp[-1].type_ptr)->objectClassName; (yyval.declaration_ptr)->basetype= (yyvsp[-1].type_ptr)->basetype;  }
#line 1469 "parser.cpp" /* yacc.c:1661  */
    break;

  case 15:
#line 136 "parser.y" /* yacc.c:1661  */
    {(yyval.type_ptr)= new BooleanTypeNode(); (yyval.type_ptr)->objectClassName= "Boolean"; (yyval.type_ptr)->basetype= bt_boolean;}
#line 1475 "parser.cpp" /* yacc.c:1661  */
    break;

  case 16:
#line 137 "parser.y" /* yacc.c:1661  */
    {(yyval.type_ptr)= new IntegerTypeNode(); (yyval.type_ptr)->objectClassName= "Integer"; (yyval.type_ptr)->basetype= bt_integer;}
#line 1481 "parser.cpp" /* yacc.c:1661  */
    break;

  case 17:
#line 138 "parser.y" /* yacc.c:1661  */
    {(yyval.type_ptr)= new ObjectTypeNode((yyvsp[0].identifier_ptr)); (yyval.type_ptr)->objectClassName= (yyvsp[0].identifier_ptr)->name; (yyval.type_ptr)->basetype= bt_object; }
#line 1487 "parser.cpp" /* yacc.c:1661  */
    break;

  case 18:
#line 140 "parser.y" /* yacc.c:1661  */
    {(yyval.method_list_ptr)= (yyvsp[-1].method_list_ptr); (yyval.method_list_ptr)->push_back((yyvsp[0].method_ptr));}
#line 1493 "parser.cpp" /* yacc.c:1661  */
    break;

  case 19:
#line 141 "parser.y" /* yacc.c:1661  */
    {(yyval.method_list_ptr)= new std::list<MethodNode*>(); (yyval.method_list_ptr)->push_back((yyvsp[0].method_ptr));}
#line 1499 "parser.cpp" /* yacc.c:1661  */
    break;

  case 20:
#line 143 "parser.y" /* yacc.c:1661  */
    {(yyval.type_ptr)= new BooleanTypeNode(); (yyval.type_ptr)->objectClassName= "Boolean"; (yyval.type_ptr)->basetype= bt_boolean;}
#line 1505 "parser.cpp" /* yacc.c:1661  */
    break;

  case 21:
#line 144 "parser.y" /* yacc.c:1661  */
    {(yyval.type_ptr)= new IntegerTypeNode(); (yyval.type_ptr)->objectClassName= "Integer"; (yyval.type_ptr)->basetype= bt_integer;}
#line 1511 "parser.cpp" /* yacc.c:1661  */
    break;

  case 22:
#line 145 "parser.y" /* yacc.c:1661  */
    {(yyval.type_ptr)= new ObjectTypeNode((yyvsp[0].identifier_ptr)); (yyval.type_ptr)->objectClassName= (yyvsp[0].identifier_ptr)->name; (yyval.type_ptr)->basetype= bt_object;}
#line 1517 "parser.cpp" /* yacc.c:1661  */
    break;

  case 23:
#line 146 "parser.y" /* yacc.c:1661  */
    {(yyval.type_ptr)= new NoneNode(); (yyval.type_ptr)->objectClassName="None"; (yyval.type_ptr)->basetype= bt_none;}
#line 1523 "parser.cpp" /* yacc.c:1661  */
    break;

  case 24:
#line 148 "parser.y" /* yacc.c:1661  */
    {(yyval.method_ptr)= new MethodNode( (yyvsp[-8].identifier_ptr), (yyvsp[-6].parameter_list_ptr),(yyvsp[-3].type_ptr), (yyvsp[-1].methodbody_ptr) ); (yyval.method_ptr)->objectClassName= (yyvsp[-3].type_ptr)->objectClassName; (yyval.method_ptr)->basetype= (yyvsp[-3].type_ptr)->basetype;}
#line 1529 "parser.cpp" /* yacc.c:1661  */
    break;

  case 25:
#line 149 "parser.y" /* yacc.c:1661  */
    {(yyval.method_ptr)= new MethodNode( (yyvsp[-7].identifier_ptr), NULL,(yyvsp[-3].type_ptr), (yyvsp[-1].methodbody_ptr) );}
#line 1535 "parser.cpp" /* yacc.c:1661  */
    break;

  case 26:
#line 151 "parser.y" /* yacc.c:1661  */
    {(yyval.parameter_list_ptr)= (yyvsp[-2].parameter_list_ptr); (yyval.parameter_list_ptr)->push_back((yyvsp[0].parameter_ptr));}
#line 1541 "parser.cpp" /* yacc.c:1661  */
    break;

  case 27:
#line 152 "parser.y" /* yacc.c:1661  */
    {(yyval.parameter_list_ptr)= new std::list<ParameterNode*>(); (yyval.parameter_list_ptr)->push_back((yyvsp[0].parameter_ptr));}
#line 1547 "parser.cpp" /* yacc.c:1661  */
    break;

  case 28:
#line 154 "parser.y" /* yacc.c:1661  */
    {(yyval.parameter_ptr)= new ParameterNode((yyvsp[0].type_ptr), (yyvsp[-2].identifier_ptr)); (yyval.parameter_ptr)->objectClassName= (yyvsp[0].type_ptr)->objectClassName; (yyval.parameter_ptr)->basetype= (yyvsp[0].type_ptr)->basetype;}
#line 1553 "parser.cpp" /* yacc.c:1661  */
    break;

  case 29:
#line 156 "parser.y" /* yacc.c:1661  */
    {(yyval.methodbody_ptr)= new MethodBodyNode((yyvsp[-2].declaration_list_ptr),(yyvsp[-1].statement_list_ptr),(yyvsp[0].returnstatement_ptr));}
#line 1559 "parser.cpp" /* yacc.c:1661  */
    break;

  case 30:
#line 157 "parser.y" /* yacc.c:1661  */
    {(yyval.methodbody_ptr)= new MethodBodyNode((yyvsp[-1].declaration_list_ptr),NULL,(yyvsp[0].returnstatement_ptr));}
#line 1565 "parser.cpp" /* yacc.c:1661  */
    break;

  case 31:
#line 158 "parser.y" /* yacc.c:1661  */
    {(yyval.methodbody_ptr)= new MethodBodyNode(NULL,(yyvsp[-1].statement_list_ptr),(yyvsp[0].returnstatement_ptr));}
#line 1571 "parser.cpp" /* yacc.c:1661  */
    break;

  case 32:
#line 159 "parser.y" /* yacc.c:1661  */
    {(yyval.methodbody_ptr)= new MethodBodyNode(NULL, NULL, (yyvsp[0].returnstatement_ptr));}
#line 1577 "parser.cpp" /* yacc.c:1661  */
    break;

  case 33:
#line 162 "parser.y" /* yacc.c:1661  */
    {(yyval.declaration_list_ptr)= (yyvsp[-2].declaration_list_ptr); (yyval.declaration_list_ptr)->push_back((yyvsp[-1].declaration_ptr));}
#line 1583 "parser.cpp" /* yacc.c:1661  */
    break;

  case 34:
#line 163 "parser.y" /* yacc.c:1661  */
    {(yyval.declaration_list_ptr)= new std::list<DeclarationNode*>(); (yyval.declaration_list_ptr)->push_back((yyvsp[-1].declaration_ptr));}
#line 1589 "parser.cpp" /* yacc.c:1661  */
    break;

  case 35:
#line 165 "parser.y" /* yacc.c:1661  */
    {(yyval.declaration_ptr)= new DeclarationNode((yyvsp[-1].type_ptr),(yyvsp[0].identifier_list_ptr)); (yyval.declaration_ptr)->basetype= (yyvsp[-1].type_ptr)->basetype; (yyval.declaration_ptr)->objectClassName= (yyvsp[-1].type_ptr)->objectClassName;}
#line 1595 "parser.cpp" /* yacc.c:1661  */
    break;

  case 36:
#line 167 "parser.y" /* yacc.c:1661  */
    {(yyval.identifier_list_ptr)=(yyvsp[-2].identifier_list_ptr); (yyval.identifier_list_ptr)->push_back((yyvsp[0].identifier_ptr));    }
#line 1601 "parser.cpp" /* yacc.c:1661  */
    break;

  case 37:
#line 168 "parser.y" /* yacc.c:1661  */
    {(yyval.identifier_list_ptr)= new std::list<IdentifierNode*>(); (yyval.identifier_list_ptr)->push_back((yyvsp[0].identifier_ptr));  }
#line 1607 "parser.cpp" /* yacc.c:1661  */
    break;

  case 38:
#line 171 "parser.y" /* yacc.c:1661  */
    {(yyval.returnstatement_ptr)= new ReturnStatementNode((yyvsp[-1].expression_ptr)); (yyval.returnstatement_ptr)->basetype=(yyvsp[-1].expression_ptr)->basetype; (yyval.returnstatement_ptr)->objectClassName= (yyvsp[-1].expression_ptr)->objectClassName; }
#line 1613 "parser.cpp" /* yacc.c:1661  */
    break;

  case 39:
#line 172 "parser.y" /* yacc.c:1661  */
    {(yyval.returnstatement_ptr)= NULL;}
#line 1619 "parser.cpp" /* yacc.c:1661  */
    break;

  case 40:
#line 175 "parser.y" /* yacc.c:1661  */
    {(yyval.statement_list_ptr)=(yyvsp[-1].statement_list_ptr); (yyval.statement_list_ptr)->push_back((yyvsp[0].statement_ptr));}
#line 1625 "parser.cpp" /* yacc.c:1661  */
    break;

  case 41:
#line 176 "parser.y" /* yacc.c:1661  */
    {(yyval.statement_list_ptr)= new std::list<StatementNode*>(); (yyval.statement_list_ptr)->push_back((yyvsp[0].statement_ptr));    }
#line 1631 "parser.cpp" /* yacc.c:1661  */
    break;

  case 42:
#line 178 "parser.y" /* yacc.c:1661  */
    {(yyval.statement_ptr)= new CallNode((yyvsp[-1].methodcall_ptr));}
#line 1637 "parser.cpp" /* yacc.c:1661  */
    break;

  case 43:
#line 179 "parser.y" /* yacc.c:1661  */
    {(yyval.statement_ptr)=(yyvsp[-1].assignment_ptr);}
#line 1643 "parser.cpp" /* yacc.c:1661  */
    break;

  case 44:
#line 180 "parser.y" /* yacc.c:1661  */
    {(yyval.statement_ptr)=(yyvsp[0].while_ptr);}
#line 1649 "parser.cpp" /* yacc.c:1661  */
    break;

  case 45:
#line 181 "parser.y" /* yacc.c:1661  */
    {(yyval.statement_ptr)=(yyvsp[-1].repeat_ptr);}
#line 1655 "parser.cpp" /* yacc.c:1661  */
    break;

  case 46:
#line 182 "parser.y" /* yacc.c:1661  */
    {(yyval.statement_ptr)=(yyvsp[-1].print_ptr);}
#line 1661 "parser.cpp" /* yacc.c:1661  */
    break;

  case 47:
#line 183 "parser.y" /* yacc.c:1661  */
    {(yyval.statement_ptr)=(yyvsp[0].ifelse_ptr);}
#line 1667 "parser.cpp" /* yacc.c:1661  */
    break;

  case 48:
#line 185 "parser.y" /* yacc.c:1661  */
    {(yyval.assignment_ptr)= new AssignmentNode((yyvsp[-4].identifier_ptr),(yyvsp[-2].identifier_ptr),(yyvsp[0].expression_ptr));}
#line 1673 "parser.cpp" /* yacc.c:1661  */
    break;

  case 49:
#line 186 "parser.y" /* yacc.c:1661  */
    {(yyval.assignment_ptr)= new AssignmentNode((yyvsp[-2].identifier_ptr),NULL,(yyvsp[0].expression_ptr));}
#line 1679 "parser.cpp" /* yacc.c:1661  */
    break;

  case 50:
#line 188 "parser.y" /* yacc.c:1661  */
    {(yyval.while_ptr)= new WhileNode((yyvsp[-3].expression_ptr),(yyvsp[-1].statement_list_ptr));}
#line 1685 "parser.cpp" /* yacc.c:1661  */
    break;

  case 51:
#line 190 "parser.y" /* yacc.c:1661  */
    {(yyval.memberaccess_ptr)= new MemberAccessNode((yyvsp[-2].identifier_ptr),(yyvsp[0].identifier_ptr));}
#line 1691 "parser.cpp" /* yacc.c:1661  */
    break;

  case 52:
#line 192 "parser.y" /* yacc.c:1661  */
    {(yyval.expression_ptr)= (yyvsp[-1].expression_ptr);}
#line 1697 "parser.cpp" /* yacc.c:1661  */
    break;

  case 53:
#line 193 "parser.y" /* yacc.c:1661  */
    {(yyval.expression_ptr)= new AndNode((yyvsp[-2].expression_ptr), (yyvsp[0].expression_ptr));		  (yyval.expression_ptr)->objectClassName= (yyvsp[-2].expression_ptr)->objectClassName; (yyval.expression_ptr)->basetype= (yyvsp[-2].expression_ptr)->basetype;}
#line 1703 "parser.cpp" /* yacc.c:1661  */
    break;

  case 54:
#line 194 "parser.y" /* yacc.c:1661  */
    {(yyval.expression_ptr)= new OrNode((yyvsp[-2].expression_ptr), (yyvsp[0].expression_ptr));		  (yyval.expression_ptr)->objectClassName= (yyvsp[-2].expression_ptr)->objectClassName; (yyval.expression_ptr)->basetype= (yyvsp[-2].expression_ptr)->basetype;}
#line 1709 "parser.cpp" /* yacc.c:1661  */
    break;

  case 55:
#line 195 "parser.y" /* yacc.c:1661  */
    {(yyval.expression_ptr)= new LessEqualNode((yyvsp[-2].expression_ptr), (yyvsp[0].expression_ptr)); (yyval.expression_ptr)->objectClassName= "Boolean"; (yyval.expression_ptr)->basetype= bt_boolean;}
#line 1715 "parser.cpp" /* yacc.c:1661  */
    break;

  case 56:
#line 196 "parser.y" /* yacc.c:1661  */
    {(yyval.expression_ptr)= new LessNode((yyvsp[-2].expression_ptr), (yyvsp[0].expression_ptr)) ;	  (yyval.expression_ptr)->objectClassName= "Boolean"; (yyval.expression_ptr)->basetype= bt_boolean;}
#line 1721 "parser.cpp" /* yacc.c:1661  */
    break;

  case 57:
#line 197 "parser.y" /* yacc.c:1661  */
    {(yyval.expression_ptr)= new PlusNode((yyvsp[-2].expression_ptr), (yyvsp[0].expression_ptr)) ;	  (yyval.expression_ptr)->objectClassName= (yyvsp[-2].expression_ptr)->objectClassName; (yyval.expression_ptr)->basetype= (yyvsp[-2].expression_ptr)->basetype;}
#line 1727 "parser.cpp" /* yacc.c:1661  */
    break;

  case 58:
#line 198 "parser.y" /* yacc.c:1661  */
    {(yyval.expression_ptr)= new EqualNode((yyvsp[-2].expression_ptr), (yyvsp[0].expression_ptr));	  (yyval.expression_ptr)->objectClassName= "Boolean"; (yyval.expression_ptr)->basetype= bt_boolean;}
#line 1733 "parser.cpp" /* yacc.c:1661  */
    break;

  case 59:
#line 199 "parser.y" /* yacc.c:1661  */
    {(yyval.expression_ptr)= new MinusNode((yyvsp[-2].expression_ptr), (yyvsp[0].expression_ptr));	  (yyval.expression_ptr)->objectClassName= (yyvsp[-2].expression_ptr)->objectClassName; (yyval.expression_ptr)->basetype= (yyvsp[-2].expression_ptr)->basetype;}
#line 1739 "parser.cpp" /* yacc.c:1661  */
    break;

  case 60:
#line 200 "parser.y" /* yacc.c:1661  */
    {(yyval.expression_ptr)= new TimesNode((yyvsp[-2].expression_ptr), (yyvsp[0].expression_ptr));	  (yyval.expression_ptr)->objectClassName= (yyvsp[-2].expression_ptr)->objectClassName; (yyval.expression_ptr)->basetype= (yyvsp[-2].expression_ptr)->basetype;}
#line 1745 "parser.cpp" /* yacc.c:1661  */
    break;

  case 61:
#line 201 "parser.y" /* yacc.c:1661  */
    {(yyval.expression_ptr)= new DivideNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr));	  (yyval.expression_ptr)->objectClassName= (yyvsp[-2].expression_ptr)->objectClassName; (yyval.expression_ptr)->basetype= (yyvsp[-2].expression_ptr)->basetype;}
#line 1751 "parser.cpp" /* yacc.c:1661  */
    break;

  case 62:
#line 202 "parser.y" /* yacc.c:1661  */
    {(yyval.expression_ptr)= new NegationNode((yyvsp[0].expression_ptr));	  (yyval.expression_ptr)->objectClassName= (yyvsp[0].expression_ptr)->objectClassName; (yyval.expression_ptr)->basetype= (yyvsp[0].expression_ptr)->basetype;}
#line 1757 "parser.cpp" /* yacc.c:1661  */
    break;

  case 63:
#line 203 "parser.y" /* yacc.c:1661  */
    {(yyval.expression_ptr)= new NotNode((yyvsp[0].expression_ptr));	 		  (yyval.expression_ptr)->objectClassName= (yyvsp[0].expression_ptr)->objectClassName; (yyval.expression_ptr)->basetype= (yyvsp[0].expression_ptr)->basetype;}
#line 1763 "parser.cpp" /* yacc.c:1661  */
    break;

  case 64:
#line 204 "parser.y" /* yacc.c:1661  */
    {(yyval.expression_ptr)= new IntegerLiteralNode((yyvsp[0].integer_ptr));(yyval.expression_ptr)->objectClassName= "Integer"; (yyval.expression_ptr)->basetype= bt_integer;}
#line 1769 "parser.cpp" /* yacc.c:1661  */
    break;

  case 65:
#line 205 "parser.y" /* yacc.c:1661  */
    {(yyval.expression_ptr)= (yyvsp[0].memberaccess_ptr);}
#line 1775 "parser.cpp" /* yacc.c:1661  */
    break;

  case 66:
#line 206 "parser.y" /* yacc.c:1661  */
    {(yyval.expression_ptr)= new VariableNode((yyvsp[0].identifier_ptr));}
#line 1781 "parser.cpp" /* yacc.c:1661  */
    break;

  case 67:
#line 207 "parser.y" /* yacc.c:1661  */
    {(yyval.expression_ptr)=(yyvsp[0].methodcall_ptr);}
#line 1787 "parser.cpp" /* yacc.c:1661  */
    break;

  case 68:
#line 208 "parser.y" /* yacc.c:1661  */
    {(yyval.expression_ptr)= new BooleanLiteralNode((yyvsp[0].integer_ptr));(yyval.expression_ptr)->objectClassName= "Boolean"; (yyval.expression_ptr)->basetype=bt_boolean;}
#line 1793 "parser.cpp" /* yacc.c:1661  */
    break;

  case 69:
#line 209 "parser.y" /* yacc.c:1661  */
    {(yyval.expression_ptr)= new BooleanLiteralNode((yyvsp[0].integer_ptr));(yyval.expression_ptr)->objectClassName= "Boolean"; (yyval.expression_ptr)->basetype=bt_boolean;}
#line 1799 "parser.cpp" /* yacc.c:1661  */
    break;

  case 70:
#line 210 "parser.y" /* yacc.c:1661  */
    {(yyval.expression_ptr)=(yyvsp[0].new_ptr);}
#line 1805 "parser.cpp" /* yacc.c:1661  */
    break;

  case 71:
#line 212 "parser.y" /* yacc.c:1661  */
    {(yyval.expression_list_ptr)=(yyvsp[-2].expression_list_ptr); (yyval.expression_list_ptr)->push_back((yyvsp[0].expression_ptr));  }
#line 1811 "parser.cpp" /* yacc.c:1661  */
    break;

  case 72:
#line 213 "parser.y" /* yacc.c:1661  */
    {(yyval.expression_list_ptr)= new std::list<ExpressionNode*>(); (yyval.expression_list_ptr)->push_back((yyvsp[0].expression_ptr));}
#line 1817 "parser.cpp" /* yacc.c:1661  */
    break;

  case 73:
#line 215 "parser.y" /* yacc.c:1661  */
    {(yyval.methodcall_ptr)= new MethodCallNode((yyvsp[-3].identifier_ptr), NULL, (yyvsp[-1].expression_list_ptr)); }
#line 1823 "parser.cpp" /* yacc.c:1661  */
    break;

  case 74:
#line 216 "parser.y" /* yacc.c:1661  */
    {(yyval.methodcall_ptr)= new MethodCallNode((yyvsp[-2].identifier_ptr), NULL, NULL);}
#line 1829 "parser.cpp" /* yacc.c:1661  */
    break;

  case 75:
#line 217 "parser.y" /* yacc.c:1661  */
    {(yyval.methodcall_ptr)= new MethodCallNode((yyvsp[-5].identifier_ptr), (yyvsp[-3].identifier_ptr), (yyvsp[-1].expression_list_ptr));}
#line 1835 "parser.cpp" /* yacc.c:1661  */
    break;

  case 76:
#line 218 "parser.y" /* yacc.c:1661  */
    {(yyval.methodcall_ptr)= new MethodCallNode((yyvsp[-4].identifier_ptr), (yyvsp[-2].identifier_ptr), NULL);}
#line 1841 "parser.cpp" /* yacc.c:1661  */
    break;

  case 77:
#line 220 "parser.y" /* yacc.c:1661  */
    {(yyval.new_ptr)= new NewNode((yyvsp[0].identifier_ptr),NULL); (yyval.new_ptr)->basetype= bt_object; (yyval.new_ptr)->objectClassName= (yyvsp[0].identifier_ptr)->name;}
#line 1847 "parser.cpp" /* yacc.c:1661  */
    break;

  case 78:
#line 221 "parser.y" /* yacc.c:1661  */
    {(yyval.new_ptr)= new NewNode((yyvsp[-3].identifier_ptr),(yyvsp[-1].expression_list_ptr))  ; (yyval.new_ptr)->basetype= bt_object; (yyval.new_ptr)->objectClassName= (yyvsp[-3].identifier_ptr)->name;}
#line 1853 "parser.cpp" /* yacc.c:1661  */
    break;

  case 79:
#line 222 "parser.y" /* yacc.c:1661  */
    {(yyval.new_ptr)= new NewNode((yyvsp[-2].identifier_ptr),NULL); (yyval.new_ptr)->basetype= bt_object; (yyval.new_ptr)->objectClassName= (yyvsp[-2].identifier_ptr)->name;}
#line 1859 "parser.cpp" /* yacc.c:1661  */
    break;

  case 80:
#line 225 "parser.y" /* yacc.c:1661  */
    {(yyval.repeat_ptr)= new RepeatNode((yyvsp[-5].statement_list_ptr),(yyvsp[-1].expression_ptr));}
#line 1865 "parser.cpp" /* yacc.c:1661  */
    break;

  case 81:
#line 227 "parser.y" /* yacc.c:1661  */
    {(yyval.ifelse_ptr)= new IfElseNode((yyvsp[-4].expression_ptr),(yyvsp[-2].statement_list_ptr),(yyvsp[0].statement_list_ptr));}
#line 1871 "parser.cpp" /* yacc.c:1661  */
    break;

  case 82:
#line 229 "parser.y" /* yacc.c:1661  */
    {(yyval.statement_list_ptr)= (yyvsp[-1].statement_list_ptr);}
#line 1877 "parser.cpp" /* yacc.c:1661  */
    break;

  case 83:
#line 230 "parser.y" /* yacc.c:1661  */
    {(yyval.statement_list_ptr)= NULL;}
#line 1883 "parser.cpp" /* yacc.c:1661  */
    break;

  case 84:
#line 232 "parser.y" /* yacc.c:1661  */
    {(yyval.print_ptr)= new PrintNode((yyvsp[0].expression_ptr));}
#line 1889 "parser.cpp" /* yacc.c:1661  */
    break;


#line 1893 "parser.cpp" /* yacc.c:1661  */
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
#line 237 "parser.y" /* yacc.c:1906  */


extern int yylineno;

void yyerror(const char *s) {
  fprintf(stderr, "%s at line %d\n", s, yylineno);
  exit(0);
}
