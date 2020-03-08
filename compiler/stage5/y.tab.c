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
#line 1 "stage5_yacc.y" /* yacc.c:339  */

    #include <stdio.h>
    #include <stdlib.h>
    #include "syntaxtreedecl.h"
    #include "syntaxtreefunc.c"

    //#define YYSTYPE node
    
    FILE* yyin;
    int yylex(void);

#line 78 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    NUM = 258,
    END = 259,
    _BEGIN = 260,
    READ = 261,
    WRITE = 262,
    ID = 263,
    IF = 264,
    then = 265,
    Else = 266,
    ENDIF = 267,
    WHILE = 268,
    DO = 269,
    ENDWHILE = 270,
    RETURN = 271,
    LT = 272,
    GT = 273,
    LE = 274,
    GE = 275,
    EQ = 276,
    NE = 277,
    BREAK = 278,
    CONT = 279,
    DECL = 280,
    ENDDECL = 281,
    INTEGER = 282,
    STRING = 283,
    STRING_LITERAL = 284,
    MAIN = 285
  };
#endif
/* Tokens.  */
#define NUM 258
#define END 259
#define _BEGIN 260
#define READ 261
#define WRITE 262
#define ID 263
#define IF 264
#define then 265
#define Else 266
#define ENDIF 267
#define WHILE 268
#define DO 269
#define ENDWHILE 270
#define RETURN 271
#define LT 272
#define GT 273
#define LE 274
#define GE 275
#define EQ 276
#define NE 277
#define BREAK 278
#define CONT 279
#define DECL 280
#define ENDDECL 281
#define INTEGER 282
#define STRING 283
#define STRING_LITERAL 284
#define MAIN 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "stage5_yacc.y" /* yacc.c:355  */

     struct tnode* root;

#line 182 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 199 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   395

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  177

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     7,     2,     2,
      11,    12,     5,     3,     8,     4,     2,     6,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
       2,    44,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     9,     2,    10,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    13,     2,    14,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    42,    42,    43,    44,    75,    76,    79,    80,    83,
      92,    93,    96,    97,    98,   107,   115,   116,   119,   122,
     129,   130,   133,   139,   143,   155,   156,   159,   160,   163,
     168,   169,   209,   210,   213,   214,   217,   218,   219,   220,
     221,   222,   223,   226,   236,   252,   255,   262,   279,   280,
     283,   286,   288,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   313,   336,   337,   338,   339,   340,   341,   343,
     344,   348,   349
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'+'", "'-'", "'*'", "'/'", "'%'", "','",
  "'['", "']'", "'('", "')'", "'{'", "'}'", "NUM", "END", "_BEGIN", "READ",
  "WRITE", "ID", "IF", "then", "Else", "ENDIF", "WHILE", "DO", "ENDWHILE",
  "RETURN", "LT", "GT", "LE", "GE", "EQ", "NE", "BREAK", "CONT", "DECL",
  "ENDDECL", "INTEGER", "STRING", "STRING_LITERAL", "MAIN", "';'", "'='",
  "$accept", "Program", "GdeclBlock", "GdeclList", "GDecl", "GidList",
  "Gid", "MainBlock", "FDefBlock", "FDef", "ParamList", "Param", "Type",
  "LDeclBlock", "LDecList", "LDecl", "IdList", "Body", "Slist", "Stmt",
  "InputStmt", "OutputStmt", "AssgStmt", "Ifstmt", "Whilestmt",
  "BreakStmt", "ContinueStmt", "E", "ArgList", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    43,    45,    42,    47,    37,    44,    91,
      93,    40,    41,   123,   125,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,    59,    61
};
# endif

#define YYPACT_NINF -148

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-148)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     112,   108,   -31,    40,    14,  -148,  -148,  -148,  -148,   120,
    -148,    28,    59,  -148,   -31,  -148,    14,  -148,    51,  -148,
    -148,   262,    15,  -148,    87,  -148,  -148,    97,   146,    92,
      28,  -148,   168,    26,   183,    43,  -148,   188,  -148,   184,
     215,    60,  -148,    92,  -148,  -148,   140,   222,   184,   216,
    -148,  -148,   227,   167,  -148,   314,   226,   222,   184,  -148,
      31,  -148,  -148,   237,   244,     5,   245,   264,   259,   242,
     243,   326,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,   273,   222,   268,  -148,   274,   259,   259,   259,   259,
     259,   259,  -148,   267,  -148,    13,  -148,  -148,   259,  -148,
    -148,   281,  -148,   105,   106,   123,    57,   138,   170,   180,
     259,   257,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   280,    73,  -148,   259,   254,   256,   265,
    -148,   288,   285,  -148,   212,  -148,   228,   107,   231,   231,
    -148,  -148,  -148,    78,   298,   191,   277,   159,   260,  -148,
     296,   220,  -148,  -148,   259,   359,   359,  -148,   259,  -148,
    -148,   305,    91,   295,   338,   228,   278,  -148,   359,   279,
     282,  -148,   351,  -148,  -148,   283,  -148
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     6,    23,    24,     0,
       8,     0,     0,     1,    23,     3,     0,    17,     0,     5,
       7,    12,     0,    11,     0,     2,    16,     0,     0,     0,
       0,     9,     0,     0,     0,     0,    21,     0,    10,     0,
       0,     0,    13,     0,    14,    22,     0,     0,     0,     0,
      20,    26,     0,     0,    28,     0,     0,     0,     0,    31,
       0,    25,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      15,     0,     0,     0,    29,     0,     0,     0,     0,     0,
       0,     0,    59,    61,    60,     0,    51,    52,     0,    34,
      19,     0,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     0,
      46,     0,     0,    58,     0,    70,    72,     0,    53,    54,
      55,    56,    57,    63,    64,    65,    66,    67,    68,    33,
       0,     0,    43,    45,     0,     0,     0,    62,     0,    69,
      32,     0,     0,     0,     0,    71,     0,    47,     0,     0,
       0,    44,     0,    49,    50,     0,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -148,  -148,  -148,  -148,   315,  -148,   293,     8,  -148,   312,
     303,   294,     6,     9,  -148,   287,  -148,    -7,  -147,   -71,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,   -85,  -148
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     9,    10,    22,    23,     5,    16,    17,
      35,    36,    37,    47,    53,    54,    60,    56,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    95,   137
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      99,   104,   105,   106,   107,   108,   109,    11,   163,   164,
      18,    12,    15,   124,    87,    11,   112,   113,   114,   115,
     116,   172,    18,    30,    25,   134,   136,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    40,    83,
      13,   151,   117,   118,   119,   120,   121,   122,    21,    88,
      81,    43,    52,    14,     8,    44,   123,    57,    31,    52,
     112,   113,   114,   115,   116,     7,     8,    82,    43,   162,
      24,    27,    49,   165,    84,   101,   112,   113,   114,   115,
     116,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,    99,    99,   112,   113,   114,   115,   116,    32,
     130,    99,   117,   118,   119,   120,   121,   122,    33,   112,
     113,   114,   115,   116,   126,   158,   150,   127,   128,   159,
     117,   118,   119,   120,   121,   122,   112,   113,   114,   115,
     116,     7,     8,   129,   167,   117,   118,   119,   120,   121,
     122,   112,   113,   114,   115,   116,     6,     7,     8,     1,
     131,     2,   117,   118,   119,   120,   121,   122,    19,     7,
       8,    34,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   112,   113,   114,   115,   116,    51,     7,
       8,    39,   132,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   133,    42,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    61,     7,     8,    45,   117,
     118,   119,   120,   121,   122,   112,   113,   114,   115,   116,
     117,    46,   157,   112,   113,   114,   115,   116,    48,    58,
     161,   112,   113,   114,   115,   116,   114,   115,   116,    55,
      80,   117,   118,   119,   120,   121,   122,    59,    85,   117,
     118,   119,   120,   121,   122,    86,    89,   117,   118,   119,
     120,   121,   122,   112,   113,   114,   115,   116,    91,   135,
      91,    28,    92,    29,    92,    90,   110,    93,   111,    93,
     112,   113,   114,   115,   116,    96,    97,   100,   102,   117,
     118,   119,   120,   121,   103,   125,   149,   152,    94,   153,
      94,   112,   113,   114,   115,   116,   117,   118,   119,   154,
     155,   156,   160,    63,    64,    65,    66,   166,   168,   169,
      67,   171,   173,    38,    20,   174,   176,   117,    26,   119,
      69,    70,    63,    64,    65,    66,    41,    50,     0,    67,
      62,     0,    68,     0,    63,    64,    65,    66,     0,    69,
      70,    67,     0,     0,    98,     0,    63,    64,    65,    66,
       0,    69,    70,    67,     0,   170,     0,     0,     0,    63,
      64,    65,    66,    69,    70,   175,    67,    63,    64,    65,
      66,     0,     0,     0,    67,     0,    69,    70,     0,     0,
       0,     0,     0,     0,    69,    70
};

static const yytype_int16 yycheck[] =
{
      71,    86,    87,    88,    89,    90,    91,     1,   155,   156,
       4,    42,     4,    98,     9,     9,     3,     4,     5,     6,
       7,   168,    16,     8,    16,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    12,     8,
       0,   126,    29,    30,    31,    32,    33,    34,    20,    44,
      57,     8,    46,    39,    40,    12,    43,    48,    43,    53,
       3,     4,     5,     6,     7,    39,    40,    58,     8,   154,
      11,    20,    12,   158,    43,    82,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,    29,    30,    31,    32,
      33,    34,   163,   164,     3,     4,     5,     6,     7,    12,
      43,   172,    29,    30,    31,    32,    33,    34,    11,     3,
       4,     5,     6,     7,     9,     8,    43,    12,    12,    12,
      29,    30,    31,    32,    33,    34,     3,     4,     5,     6,
       7,    39,    40,    10,    43,    29,    30,    31,    32,    33,
      34,     3,     4,     5,     6,     7,    38,    39,    40,    37,
      12,    39,    29,    30,    31,    32,    33,    34,    38,    39,
      40,    15,     3,     4,     5,     6,     7,    29,    30,    31,
      32,    33,    34,     3,     4,     5,     6,     7,    38,    39,
      40,    13,    12,     3,     4,     5,     6,     7,    29,    30,
      31,    32,    12,    10,     3,     4,     5,     6,     7,    29,
      30,    31,    32,    33,    34,    38,    39,    40,    20,    29,
      30,    31,    32,    33,    34,     3,     4,     5,     6,     7,
      29,    37,    10,     3,     4,     5,     6,     7,    13,    13,
      10,     3,     4,     5,     6,     7,     5,     6,     7,    17,
      14,    29,    30,    31,    32,    33,    34,    20,    11,    29,
      30,    31,    32,    33,    34,    11,    11,    29,    30,    31,
      32,    33,    34,     3,     4,     5,     6,     7,    11,    12,
      11,     9,    15,    11,    15,    11,     9,    20,    11,    20,
       3,     4,     5,     6,     7,    43,    43,    14,    20,    29,
      30,    31,    32,    33,    20,    14,    16,    43,    41,    43,
      41,     3,     4,     5,     6,     7,    29,    30,    31,    44,
      22,    26,    16,    18,    19,    20,    21,    12,    23,    24,
      25,    43,    43,    30,     9,    43,    43,    29,    16,    31,
      35,    36,    18,    19,    20,    21,    33,    43,    -1,    25,
      53,    -1,    28,    -1,    18,    19,    20,    21,    -1,    35,
      36,    25,    -1,    -1,    28,    -1,    18,    19,    20,    21,
      -1,    35,    36,    25,    -1,    27,    -1,    -1,    -1,    18,
      19,    20,    21,    35,    36,    24,    25,    18,    19,    20,
      21,    -1,    -1,    -1,    25,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    39,    46,    47,    52,    38,    39,    40,    48,
      49,    57,    42,     0,    39,    52,    53,    54,    57,    38,
      49,    20,    50,    51,    11,    52,    54,    20,     9,    11,
       8,    43,    12,    11,    15,    55,    56,    57,    51,    13,
      12,    55,    10,     8,    12,    20,    37,    58,    13,    12,
      56,    38,    57,    59,    60,    17,    62,    58,    13,    20,
      61,    38,    60,    18,    19,    20,    21,    25,    28,    35,
      36,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      14,    62,    58,     8,    43,    11,    11,     9,    44,    11,
      11,    11,    15,    20,    41,    72,    43,    43,    28,    64,
      14,    62,    20,    20,    72,    72,    72,    72,    72,    72,
       9,    11,     3,     4,     5,     6,     7,    29,    30,    31,
      32,    33,    34,    43,    72,    14,     9,    12,    12,    10,
      43,    12,    12,    12,    72,    12,    72,    73,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    16,
      43,    72,    43,    43,    44,    22,    26,    10,     8,    12,
      16,    10,    72,    63,    63,    72,    12,    43,    23,    24,
      27,    43,    63,    43,    43,    24,    43
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    46,    46,    47,    47,    48,    48,    49,
      50,    50,    51,    51,    51,    52,    53,    53,    54,    54,
      55,    55,    56,    57,    57,    58,    58,    59,    59,    60,
      61,    61,    62,    62,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    66,    67,    67,    68,    68,
      69,    70,    71,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       3,     1,     1,     4,     4,     8,     2,     1,     9,     8,
       3,     1,     2,     1,     1,     3,     2,     2,     1,     3,
       3,     1,     6,     5,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     8,     5,     4,     7,    10,     8,
       8,     2,     2,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     4,     3,     3,     3,     3,     3,     3,     4,
       3,     3,     1
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
#line 42 "stage5_yacc.y" /* yacc.c:1646  */
    {}
#line 1433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 43 "stage5_yacc.y" /* yacc.c:1646  */
    {}
#line 1439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 44 "stage5_yacc.y" /* yacc.c:1646  */
    {}
#line 1445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 75 "stage5_yacc.y" /* yacc.c:1646  */
    {printGsymbolTable();}
#line 1451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 76 "stage5_yacc.y" /* yacc.c:1646  */
    {printGsymbolTable();}
#line 1457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 79 "stage5_yacc.y" /* yacc.c:1646  */
    {}
#line 1463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 80 "stage5_yacc.y" /* yacc.c:1646  */
    {}
#line 1469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 83 "stage5_yacc.y" /* yacc.c:1646  */
    {
                                                        popType();
                                                   }
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 92 "stage5_yacc.y" /* yacc.c:1646  */
    {}
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 93 "stage5_yacc.y" /* yacc.c:1646  */
    {}
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 96 "stage5_yacc.y" /* yacc.c:1646  */
    {installGId((yyvsp[0].root)->varname, getType(), 1);}
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 97 "stage5_yacc.y" /* yacc.c:1646  */
    {installGId((yyvsp[-3].root)->varname, getType(), (yyvsp[-1].root)->val);}
#line 1501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 98 "stage5_yacc.y" /* yacc.c:1646  */
    {
                                                    installFunc((yyvsp[-3].root)->varname, getType(), paramHeadPtr);
                                                    paramHeadPtr = NULL;
                                                }
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 107 "stage5_yacc.y" /* yacc.c:1646  */
    {}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 115 "stage5_yacc.y" /* yacc.c:1646  */
    {}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 116 "stage5_yacc.y" /* yacc.c:1646  */
    {}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 119 "stage5_yacc.y" /* yacc.c:1646  */
    {
                                                                            paramHeadPtr = NULL;
                                                                        }
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 122 "stage5_yacc.y" /* yacc.c:1646  */
    {
                                                                            paramHeadPtr = NULL;
                                                                        }
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 129 "stage5_yacc.y" /* yacc.c:1646  */
    {}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 130 "stage5_yacc.y" /* yacc.c:1646  */
    {}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 133 "stage5_yacc.y" /* yacc.c:1646  */
    {
                                                    paramHeadPtr = addToParamList(getType(), (yyvsp[0].root)->varname);
                                                    popType();
                                                }
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 139 "stage5_yacc.y" /* yacc.c:1646  */
    {
                                                    // TYPE = INTEGER;
                                                    pushType(INTEGER);
                                                }
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 143 "stage5_yacc.y" /* yacc.c:1646  */
    {
                                                    // TYPE = STRING;
                                                    pushType(STRING);
                                                }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 155 "stage5_yacc.y" /* yacc.c:1646  */
    {}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 156 "stage5_yacc.y" /* yacc.c:1646  */
    {}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 159 "stage5_yacc.y" /* yacc.c:1646  */
    {}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 160 "stage5_yacc.y" /* yacc.c:1646  */
    {}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 163 "stage5_yacc.y" /* yacc.c:1646  */
    {
                                                    popType();
                                               }
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 168 "stage5_yacc.y" /* yacc.c:1646  */
    {}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 169 "stage5_yacc.y" /* yacc.c:1646  */
    {}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 209 "stage5_yacc.y" /* yacc.c:1646  */
    {}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 210 "stage5_yacc.y" /* yacc.c:1646  */
    {}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 213 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root) = createTree(-1, CONNECTOR, NULL, CONNECTOR, (yyvsp[-1].root), (yyvsp[0].root), NULL);}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 214 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root) = (yyvsp[0].root);}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 217 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root)=(yyvsp[0].root);}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 218 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root)=(yyvsp[0].root);}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 219 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root)=(yyvsp[0].root);}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 220 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root)=(yyvsp[0].root);}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 221 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root)=(yyvsp[0].root);}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 222 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root)=(yyvsp[0].root);}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 223 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root)=(yyvsp[0].root);}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 226 "stage5_yacc.y" /* yacc.c:1646  */
    {
                                                    // $3->GSTptr = lookUp($3->varname);   //finding and setting GSTptr

                                                    // $3->type = ($3->GSTptr)->type;      //setting type from GSTptr

                                                    // $$ = createTree(-1, READ, NULL, READ, $3, NULL, NULL);
                                                    
                                                }
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 236 "stage5_yacc.y" /* yacc.c:1646  */
    {
                                                    // $3->GSTptr = lookUp($3->varname);   //finding and setting GSTptr

                                                    // $3->type = ($3->GSTptr)->type;      //setting type from GSTptr
                                                    // $3->left = $5;
                                                    // if ($3->left->type != INTEGER)     //TYPE_CHK
                                                    // {
                                                    //     printf("TYPE_ERR..!!! array_index INTEGER expected something else....!!!\n");
                                                    //     exit(0);
                                                    // }

                                                    // $$ = createTree(-1, READ, NULL, READ, $3, NULL, NULL);
                                                    
                                                }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 252 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root) = createTree(-1, WRITE, NULL, WRITE, (yyvsp[-2].root), NULL, NULL);}
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 255 "stage5_yacc.y" /* yacc.c:1646  */
    {
                                                    // $1->GSTptr = lookUp($1->varname);   //finding and setting GSTptr

                                                    // $1->type = ($1->GSTptr)->type;      //setting type from GSTptr
                                                    
                                                    // $$ = createTree('=', '=', NULL, ASSGNOP, $1, $3, NULL);
                                                }
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 262 "stage5_yacc.y" /* yacc.c:1646  */
    {
                                                    // $1->GSTptr = lookUp($1->varname);   //finding and setting GSTptr

                                                    // $1->type = ($1->GSTptr)->type;      //setting type from GSTptr
                                                    // // $1->val = $3->val;

                                                    // $1->left = $3;
                                                    // if ($1->left->type != INTEGER)     //TYPE_CHK
                                                    // {
                                                    //     printf("TYPE_ERR..!!! array_index INTEGER expected something else....!!!\n");
                                                    //     exit(0);
                                                    // }

                                                    // $$ = createTree('=', '=', NULL, ASSGNOP, $1, $6, NULL);
                                                }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 279 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root) = createTree(-1, IF, NULL, IF, (yyvsp[-7].root), createTree(-1, IFBODY, NULL, IFBODY, (yyvsp[-4].root), (yyvsp[-2].root), NULL), NULL);}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 280 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root) = createTree(-1, IF, NULL, IF, (yyvsp[-5].root), createTree(-1, IFBODY, NULL, IFBODY, (yyvsp[-2].root), NULL, NULL), NULL);}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 283 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root) = createTree(-1, WHILE, NULL, WHILE, (yyvsp[-5].root), (yyvsp[-2].root), NULL);}
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 286 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root) = createTree(-1, BREAK, NULL, BREAK, NULL, NULL, NULL);}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 288 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root) = createTree(-1, CONT, NULL, CONT, NULL, NULL, NULL);}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 291 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root) = createTree('+', INTEGER, NULL, ARITHOP, (yyvsp[-2].root), (yyvsp[0].root), NULL);}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 292 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root) = createTree('-', INTEGER, NULL, ARITHOP, (yyvsp[-2].root), (yyvsp[0].root), NULL);}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 293 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root) = createTree('*', INTEGER, NULL, ARITHOP, (yyvsp[-2].root), (yyvsp[0].root), NULL);}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 294 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root) = createTree('/', INTEGER, NULL, ARITHOP, (yyvsp[-2].root), (yyvsp[0].root), NULL);}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 295 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root) = createTree('%', INTEGER, NULL, ARITHOP, (yyvsp[-2].root), (yyvsp[0].root), NULL);}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 296 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root) = (yyvsp[-1].root);}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 297 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root) = (yyvsp[0].root);}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 298 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root) = (yyvsp[0].root);}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 299 "stage5_yacc.y" /* yacc.c:1646  */
    {
                                        // printf("LALA..!!!! in ID reduc....\n");
                                        // $1->GSTptr = lookUp($1->varname);   //finding and setting GSTptr
                                        // // if($1->GSTptr == NULL)
                                        // // {
                                        // //     printf("%%$##@@@#$#\n");
                                        // //     exit(1);
                                        // // }
                                        // $1->type = ($1->GSTptr)->type;      //setting type from GSTptr
                                        // $$ = $1;
                                        // printf("LALA..!!!! varname is %s\n", $$->GSTptr->name);
                                        // printf("LALA..!!!! type is %d\n", $$->type);
                                        // printf("val of GSTptr is %p\n", $$->GSTptr);
                                      }
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 313 "stage5_yacc.y" /* yacc.c:1646  */
    {
                                        // printf("LALALOLO..!!!! in ID[E] reduc....\n");
                                        // $1->GSTptr = lookUp($1->varname);   //finding and setting GSTptr
                                        // // if($1->GSTptr == NULL)
                                        // // {
                                        // //     printf("%%$##@@@#$#\n");
                                        // //     exit(1);
                                        // // }
                                        // $1->type = ($1->GSTptr)->type;      //setting type from GSTptr
                                        // // $1->val = $3->val;
                                        // $1->left = $3;
                                        // if ($1->left->type != INTEGER)     //TYPE_CHK
                                        // {
                                        //     printf("TYPE_ERR..!!! array_index INTEGER expected something else....!!!\n");
                                        //     exit(0);
                                        // }
                                        // $$ = $1;
                                        // printf("LALA..!!!! varname is %s\n", $$->GSTptr->name);
                                        // printf("LALA..!!!! type is %d\n", $$->type);
                                        // printf("val of GSTptr is %p\n", $$->GSTptr);
                                      }
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 336 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root) = createTree(LT, BOOLEAN, NULL, RELOP, (yyvsp[-2].root), (yyvsp[0].root), NULL);}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 337 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root) = createTree(GT, BOOLEAN, NULL, RELOP, (yyvsp[-2].root), (yyvsp[0].root), NULL);}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 338 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root) = createTree(LE, BOOLEAN, NULL, RELOP, (yyvsp[-2].root), (yyvsp[0].root), NULL);}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 339 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root) = createTree(GE, BOOLEAN, NULL, RELOP, (yyvsp[-2].root), (yyvsp[0].root), NULL);}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 340 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root) = createTree(EQ, BOOLEAN, NULL, RELOP, (yyvsp[-2].root), (yyvsp[0].root), NULL);}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 341 "stage5_yacc.y" /* yacc.c:1646  */
    {(yyval.root) = createTree(NE, BOOLEAN, NULL, RELOP, (yyvsp[-2].root), (yyvsp[0].root), NULL);}
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 343 "stage5_yacc.y" /* yacc.c:1646  */
    {}
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 344 "stage5_yacc.y" /* yacc.c:1646  */
    {}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 348 "stage5_yacc.y" /* yacc.c:1646  */
    {}
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 349 "stage5_yacc.y" /* yacc.c:1646  */
    {}
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1950 "y.tab.c" /* yacc.c:1646  */
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
#line 351 "stage5_yacc.y" /* yacc.c:1906  */



void yyerror(const char *s){
    printf("line %d: yyerror %s", line,s);
}



int main(int argc, char* argv[]){
    line = 1;
    yyin = fopen(argv[1], "r");

    yyparse();
    return 0;
}
