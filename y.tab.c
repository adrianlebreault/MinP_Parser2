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
#line 1 "parse.y" /* yacc.c:339  */

#include <bits/stdc++.h>

using namespace std;

enum TipoEnum{
	Integer,
	Real,
	String,
	Procedure
};

struct registro{

	TipoEnum tipo;
	int nivel;
};

extern int yylineno;
int yylex();
int yyerror(char *s);
int error(char *s);
short setType(short xtype, short ytype);
int nivel;
bool declaration = false;


stringstream ss;
multimap<string,registro> SymTab, BUSymTab;
multimap<string,registro>::iterator oit;
map<string,registro> ProcTab;
// vector<string> declares, uses, declerrors, typerrors;





#line 104 "y.tab.c" /* yacc.c:339  */

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
    ID = 258,
    ICONST = 259,
    RCONST = 260,
    ECONST = 261,
    LITERAL = 262,
    LBRACK = 263,
    RBRACK = 264,
    LPAREN = 265,
    RPAREN = 266,
    SEMI = 267,
    COLON = 268,
    COMMA = 269,
    ASSIGN = 270,
    PLUS = 271,
    MINUS = 272,
    MULT = 273,
    DIVIDE = 274,
    EQL = 275,
    LESS = 276,
    GTR = 277,
    LEQ = 278,
    GEQ = 279,
    NEQ = 280,
    PROGRAM = 281,
    ENDVARS = 282,
    ENDPROCS = 283,
    VARS = 284,
    NOVARS = 285,
    INTEGER = 286,
    REAL = 287,
    STRING = 288,
    PROCS = 289,
    NOPROCS = 290,
    PROC = 291,
    _BEGIN = 292,
    END = 293,
    FOR = 294,
    TO = 295,
    DO = 296,
    IF = 297,
    THEN = 298,
    ELSE = 299,
    READ = 300,
    WRITE = 301,
    ERROR = 302
  };
#endif
/* Tokens.  */
#define ID 258
#define ICONST 259
#define RCONST 260
#define ECONST 261
#define LITERAL 262
#define LBRACK 263
#define RBRACK 264
#define LPAREN 265
#define RPAREN 266
#define SEMI 267
#define COLON 268
#define COMMA 269
#define ASSIGN 270
#define PLUS 271
#define MINUS 272
#define MULT 273
#define DIVIDE 274
#define EQL 275
#define LESS 276
#define GTR 277
#define LEQ 278
#define GEQ 279
#define NEQ 280
#define PROGRAM 281
#define ENDVARS 282
#define ENDPROCS 283
#define VARS 284
#define NOVARS 285
#define INTEGER 286
#define REAL 287
#define STRING 288
#define PROCS 289
#define NOPROCS 290
#define PROC 291
#define _BEGIN 292
#define END 293
#define FOR 294
#define TO 295
#define DO 296
#define IF 297
#define THEN 298
#define ELSE 299
#define READ 300
#define WRITE 301
#define ERROR 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 89 "parse.y" /* yacc.c:355  */


	short tipo;
	char *sval;
	

#line 245 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 262 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   112

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  126

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   101,   101,   105,   109,   109,   121,   121,   123,   127,
     129,   133,   150,   165,   180,   197,   201,   203,   207,   209,
     213,   215,   219,   223,   223,   238,   254,   256,   260,   262,
     266,   268,   270,   272,   274,   276,   280,   284,   286,   288,
     292,   294,   296,   300,   302,   306,   308,   321,   323,   327,
     340,   355,   357,   361,   374,   379,   383,   385,   387,   389,
     391,   393,   397,   401,   413,   423
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "ICONST", "RCONST", "ECONST",
  "LITERAL", "LBRACK", "RBRACK", "LPAREN", "RPAREN", "SEMI", "COLON",
  "COMMA", "ASSIGN", "PLUS", "MINUS", "MULT", "DIVIDE", "EQL", "LESS",
  "GTR", "LEQ", "GEQ", "NEQ", "PROGRAM", "ENDVARS", "ENDPROCS", "VARS",
  "NOVARS", "INTEGER", "REAL", "STRING", "PROCS", "NOPROCS", "PROC",
  "_BEGIN", "END", "FOR", "TO", "DO", "IF", "THEN", "ELSE", "READ",
  "WRITE", "ERROR", "$accept", "program", "title", "block", "$@1", "vars",
  "$@2", "varlist", "vardef", "bnl", "nlist", "procs", "proclist",
  "procdef", "ptittle", "$@3", "code", "para", "stmt", "assign", "expr",
  "term", "fac", "val", "ids", "vallist", "it", "cond", "bop", "loop",
  "input", "output", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

#define YYPACT_NINF -75

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-75)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -19,    24,    55,    17,   -75,   -75,    31,   -75,   -75,   -75,
     -75,    60,    52,    65,    68,   -75,    30,   -17,    60,    45,
     -75,    57,    75,   -75,   -75,   -75,    83,    77,   -75,    78,
      -3,    87,   -75,    82,    45,    31,   -75,     7,   -75,   -75,
      19,    84,   -75,   -75,    85,    91,    38,    86,    88,   -75,
      -8,   -75,   -75,    89,   -75,   -75,   -75,   -75,   -75,    93,
     -75,    60,    63,    61,    29,   -75,   -75,    38,     1,    50,
     -75,   -75,   -75,    96,    51,     7,   -75,    38,   -75,    59,
     -75,   -75,    26,   -75,    38,    63,    40,    38,    38,   -75,
     -75,   -75,   -75,   -75,   -75,    38,    38,    38,    92,    94,
      95,   -75,    56,   -75,    60,   -75,    63,    -5,    48,   -75,
      50,    50,   -11,   -75,   -75,   -75,   -75,   -75,   -75,     7,
     -75,     7,   -75,    58,     7,   -75
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     3,     1,     0,     6,     8,     2,
       4,     0,     0,     0,     0,    10,     0,     0,     7,     0,
      19,     0,    11,    12,    14,     9,     0,    18,    21,     0,
       0,     0,    13,     0,     0,     0,    27,     0,     5,    17,
       0,    23,    20,    22,    49,     0,     0,     0,     0,    35,
       0,    29,    30,     0,    31,    32,    33,    34,    15,     0,
      25,     0,     0,     0,    49,    48,    47,     0,     0,    39,
      42,    43,    45,     0,     0,     0,    26,     0,    16,     0,
      53,    54,     0,    52,     0,     0,     0,     0,     0,    56,
      57,    58,    59,    60,    61,     0,     0,     0,     0,     0,
       0,    28,    36,    24,     0,    50,     0,     0,     0,    44,
      37,    38,     0,    40,    41,    63,    64,    65,    51,     0,
      46,     0,    62,     0,     0,    55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -75,   -75,   -75,    72,   -75,   -75,   -75,    39,   -16,   -75,
     -75,   -75,   -75,    74,   -75,   -75,    79,   -75,   -74,    66,
     -64,   -13,   -20,   -75,   -37,    25,     6,   -75,   -75,   -75,
     -75,   -75
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     9,    12,    10,    11,    14,    15,    32,
      40,    21,    27,    28,    29,    61,    49,    50,    51,    52,
      68,    69,    70,    71,    72,    82,    83,    54,    95,    55,
      56,    57
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      53,   101,    25,    86,    75,    87,    88,     1,    53,    36,
      44,    87,    88,   102,    22,    23,    24,    87,    88,    36,
     107,    89,    90,    91,    92,    93,    94,     4,    58,     6,
      76,   112,   121,    59,    37,   105,   119,    62,    53,    85,
     106,    64,    65,    66,    37,   122,    45,   123,    67,    46,
     125,   109,    47,    48,    99,     5,    87,    88,   100,   120,
       7,     8,   106,    13,    19,    20,    80,    81,    96,    97,
     103,   104,    87,    88,   110,   111,   113,   114,    17,    16,
      18,    26,    53,    31,    53,    30,    33,    53,    25,    34,
      35,    39,    41,    62,    44,    60,    73,    78,    74,    98,
      79,    84,   124,   115,    77,   116,   117,    43,    42,    38,
     108,    63,   118
};

static const yytype_uint8 yycheck[] =
{
      37,    75,    18,    67,    12,    16,    17,    26,    45,    12,
       3,    16,    17,    77,    31,    32,    33,    16,    17,    12,
      84,    20,    21,    22,    23,    24,    25,     3,     9,    12,
      38,    95,    43,    14,    37,     9,    41,     8,    75,    10,
      14,     3,     4,     5,    37,   119,    39,   121,    10,    42,
     124,    11,    45,    46,     3,     0,    16,    17,     7,    11,
      29,    30,    14,     3,    34,    35,     3,     4,    18,    19,
      11,    12,    16,    17,    87,    88,    96,    97,    13,    27,
      12,    36,   119,     8,   121,    28,     3,   124,   104,    12,
      12,     4,    10,     8,     3,    11,    10,     4,    10,     3,
      61,    40,    44,    11,    15,    11,    11,    35,    34,    30,
      85,    45,   106
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    26,    49,    50,     3,     0,    12,    29,    30,    51,
      53,    54,    52,     3,    55,    56,    27,    13,    12,    34,
      35,    59,    31,    32,    33,    56,    36,    60,    61,    62,
      28,     8,    57,     3,    12,    12,    12,    37,    64,     4,
      58,    10,    61,    51,     3,    39,    42,    45,    46,    64,
      65,    66,    67,    72,    75,    77,    78,    79,     9,    14,
      11,    63,     8,    67,     3,     4,     5,    10,    68,    69,
      70,    71,    72,    10,    10,    12,    38,    15,     4,    55,
       3,     4,    73,    74,    40,    10,    68,    16,    17,    20,
      21,    22,    23,    24,    25,    76,    18,    19,     3,     3,
       7,    66,    68,    11,    12,     9,    14,    68,    73,    11,
      69,    69,    68,    70,    70,    11,    11,    11,    74,    41,
      11,    43,    66,    66,    44,    66
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    52,    51,    54,    53,    53,    55,
      55,    56,    56,    56,    56,    57,    58,    58,    59,    59,
      60,    60,    61,    63,    62,    62,    64,    64,    65,    65,
      66,    66,    66,    66,    66,    66,    67,    68,    68,    68,
      69,    69,    69,    70,    70,    71,    71,    71,    71,    72,
      72,    73,    73,    74,    74,    75,    76,    76,    76,    76,
      76,    76,    77,    78,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     0,     6,     0,     4,     1,     3,
       1,     3,     3,     4,     3,     3,     3,     1,     2,     1,
       3,     1,     3,     0,     6,     4,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     1,
       3,     3,     1,     1,     3,     1,     4,     1,     1,     1,
       4,     3,     1,     1,     1,     8,     1,     1,     1,     1,
       1,     1,     6,     4,     4,     4
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
        case 3:
#line 105 "parse.y" /* yacc.c:1646  */
    { nivel = 0; }
#line 1427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 109 "parse.y" /* yacc.c:1646  */
    { nivel++; }
#line 1433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 109 "parse.y" /* yacc.c:1646  */
    {  oit = SymTab.begin();
														while(oit != SymTab.end())
														{
															if(oit->second.nivel == nivel) SymTab.erase(oit);

															oit++;
														}
														nivel--; 
													 }
#line 1447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 121 "parse.y" /* yacc.c:1646  */
    {  declaration = true; }
#line 1453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 133 "parse.y" /* yacc.c:1646  */
    {  
								if(declaration){
									registro newreg;
									newreg.tipo = Integer;
									newreg.nivel = nivel;
									SymTab.insert(pair<string,registro>(yyval.sval,newreg));
									// oit = SymTab.upper_bound(yyval.sval);
									// oit--;
									auto ouit = SymTab.find(yyval.sval);
							
									ss <<  "En linea: " << yylineno << " se declaro Key: "<< ouit->first << " tipo: " << ouit->second.tipo << " nivel: "<< ouit->second.nivel<<endl;
									//declares.push_back(ss.str());
									cout << ss.str();
									ss.str(string());
								}
							}
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 150 "parse.y" /* yacc.c:1646  */
    {
								if(declaration){
									registro newreg;
									newreg.tipo = Real;
									newreg.nivel = nivel;
									SymTab.insert(pair<string,registro>(yyval.sval,newreg));
									// oit = SymTab.upper_bound(yyval.sval);
									// oit--;
									auto ouit = SymTab.find(yyval.sval);
									ss <<  "En linea: " << yylineno << " se declaro Key: "<< ouit->first << " tipo: " << ouit->second.tipo << " nivel: "<< ouit->second.nivel<<endl;
									// declares.push_back(ss.str());
									cout << ss.str();
									ss.str(string());}
							}
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 165 "parse.y" /* yacc.c:1646  */
    {   
								if(declaration){
									registro newreg;
									newreg.tipo = Integer;
									newreg.nivel = nivel;
									SymTab.insert(pair<string,registro>(yyval.sval,newreg));
									// oit = SymTab.upper_bound(yyval.sval);
									// oit--;
									auto ouit = SymTab.find(yyval.sval);
									ss <<  "En linea: " << yylineno << " se declaro Key: "<< ouit->first << " tipo: " << ouit->second.tipo << " nivel: "<< ouit->second.nivel<<endl;
									// declares.push_back(ss.str());
									cout << ss.str();
									ss.str(string());}
							}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 180 "parse.y" /* yacc.c:1646  */
    {  
								if(declaration){
									registro newreg;
									newreg.tipo = String;
									newreg.nivel = nivel;
									SymTab.insert(pair<string,registro>(yyval.sval,newreg));
									// oit = SymTab.upper_bound(yyval.sval);
									// oit--;
									auto ouit = SymTab.find(yyval.sval);
									ss <<  "En linea: " << yylineno << " se declaro Key: "<< ouit->first << " tipo: " << ouit->second.tipo << " nivel: "<< ouit->second.nivel<<endl;
									// declares.push_back(ss.str());
									cout << ss.str();
									ss.str(string());}
							}
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 223 "parse.y" /* yacc.c:1646  */
    { declaration = true; }
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 224 "parse.y" /* yacc.c:1646  */
    {
						registro newreg;
						newreg.tipo = Procedure;
						newreg.nivel = nivel;
						ProcTab.insert(pair<string,registro>((yyvsp[-4].sval),newreg));
						// oit = ProcTab.upper_bound($2);
						// oit--;
						auto ouit = ProcTab.find((yyvsp[-4].sval));
						ss <<  "En linea: " << yylineno << " se declaro Key: "<< ouit->first << " tipo: " << ouit->second.tipo << " nivel: "<< ouit->second.nivel<<endl;
						// declares.push_back(ss.str());
						cout << ss.str();
						ss.str(string());
					}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 238 "parse.y" /* yacc.c:1646  */
    {
								registro newreg;
								newreg.tipo = Procedure;
								newreg.nivel = nivel;
								ProcTab.insert(pair<string,registro>((yyvsp[-2].sval),newreg));
								// oit = ProcTab.upper_bound($2);
								// oit--;
								auto ouit = ProcTab.find((yyvsp[-2].sval));
								ss <<  "En linea: " << yylineno << " se declaro Key: "<< ouit->first << " tipo: " << ouit->second.tipo << " nivel: "<< ouit->second.nivel<<endl;
								// declares.push_back(ss.str());
								cout << ss.str();
								ss.str(string());
							}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 284 "parse.y" /* yacc.c:1646  */
    {	(yyval.tipo) = setType((yyvsp[-2].tipo), (yyvsp[0].tipo)); }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 286 "parse.y" /* yacc.c:1646  */
    {	(yyval.tipo) = setType((yyvsp[-2].tipo), (yyvsp[0].tipo)); }
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 288 "parse.y" /* yacc.c:1646  */
    { (yyval.tipo) = (yyvsp[0].tipo);}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 292 "parse.y" /* yacc.c:1646  */
    {	(yyval.tipo) = setType((yyvsp[-2].tipo), (yyvsp[0].tipo)); }
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 294 "parse.y" /* yacc.c:1646  */
    {	(yyval.tipo) = setType((yyvsp[-2].tipo), (yyvsp[0].tipo)); }
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 296 "parse.y" /* yacc.c:1646  */
    { (yyval.tipo) = (yyvsp[0].tipo);}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 300 "parse.y" /* yacc.c:1646  */
    { (yyval.tipo) = (yyvsp[0].tipo); }
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 302 "parse.y" /* yacc.c:1646  */
    { (yyval.tipo) = (yyvsp[-1].tipo); }
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 306 "parse.y" /* yacc.c:1646  */
    { (yyval.tipo) = (yyvsp[0].tipo); }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 308 "parse.y" /* yacc.c:1646  */
    {	//Se busca en la tabla de simbolo para encontrar el uso de la variable cuyo lexema de identificador proviene de ID
									// oit = SymTab.upper_bound(yyval.sval);
									// oit--;
									auto ouit = SymTab.find(yyval.sval);
									if(ouit->first != yyval.sval) { error(yyval.sval); }
									else { 	(yyval.tipo) = ouit->second.tipo;
											ss <<  "En linea:" << yylineno << " se uso Key: "<< ouit->first << " tipo: " << ouit->second.tipo << " nivel: "<< ouit->second.nivel<<endl;
											// uses.push_back(ss.str());
											cout << ss.str();
											ss.str(string());
										 }
								}
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 321 "parse.y" /* yacc.c:1646  */
    { 	(yyval.tipo) = (yyvsp[0].tipo);	}
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 323 "parse.y" /* yacc.c:1646  */
    { 	(yyval.tipo) = (yyvsp[0].tipo);	}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 327 "parse.y" /* yacc.c:1646  */
    {	//Se busca en la tabla de simbolo para encontrar el uso de la variable cuyo lexema de identificador proviene de ID
				// oit = SymTab.upper_bound(yyval.sval);
				// oit--;
				auto ouit = SymTab.find(yyval.sval);
				if(ouit->first != yyval.sval) { error(yyval.sval); }
				else { 	(yyval.tipo) = ouit->second.tipo;
						ss <<  "En linea:" << yylineno << " se uso Key: "<< ouit->first << " tipo: " << ouit->second.tipo << " nivel: "<< ouit->second.nivel<<endl;
					 	// uses.push_back(ss.str());
						cout << ss.str();
						ss.str(string());
					 }
			}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 340 "parse.y" /* yacc.c:1646  */
    {	//Se busca en la tabla de simbolo para encontrar el uso de la variable cuyo lexema de identificador proviene de ID
									// oit = SymTab.upper_bound(yyval.sval);
									// oit--;
									auto ouit = SymTab.find(yyval.sval);
									if(ouit->first != yyval.sval) { error(yyval.sval); }
									else { 	(yyval.tipo) = ouit->second.tipo;
											ss <<  "En linea:" << yylineno << " se uso Key: "<< ouit->first << " tipo: " << ouit->second.tipo << " nivel: "<< ouit->second.nivel<<endl;
											// uses.push_back(ss.str());
											cout << ss.str();
											ss.str(string());
										 }
								}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 361 "parse.y" /* yacc.c:1646  */
    {	//Se busca en la tabla de simbolo para encontrar el uso de la variable cuyo lexema de identificador proviene de ID
									// oit = SymTab.upper_bound(yyval.sval);
									// oit--;
									auto ouit = SymTab.find(yyval.sval);
									if(ouit->first != yyval.sval) { error(yyval.sval); }
									else { 	(yyval.tipo) = ouit->second.tipo;
											ss <<  "En linea:" << yylineno << " se uso Key: "<< ouit->first << " tipo: " << ouit->second.tipo << " nivel: "<< ouit->second.nivel<<endl;
											// uses.push_back(ss.str());
											cout << ss.str();
											ss.str(string());
										 }
								}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 374 "parse.y" /* yacc.c:1646  */
    { 	(yyval.tipo) = (yyvsp[0].tipo);
								}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 401 "parse.y" /* yacc.c:1646  */
    {
								oit = SymTab.find((yyvsp[-1].sval));
								if(oit->first != (yyvsp[-1].sval)) { error((yyvsp[-1].sval)); }
								else {	cout <<  "En linea:" << yylineno << " se uso Key: "<< oit->first << " tipo: " << oit->second.tipo << " nivel: "<< oit->second.nivel<<endl; 
										// uses.push_back(ss.str());
										cout << ss.str();
										ss.str(string());
									 }
							}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 413 "parse.y" /* yacc.c:1646  */
    {
								oit = SymTab.find((yyvsp[-1].sval));
								if(oit->first != (yyvsp[-1].sval)) { error((yyvsp[-1].sval)); }
								else {	ss <<  "En linea:" << yylineno << " se uso Key: "<< oit->first << " tipo: " << oit->second.tipo << " nivel: "<< oit->second.nivel<<endl; 
										// uses.push_back(ss.str());
										cout << ss.str();
										ss.str(string());	
									 }
							}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1746 "y.tab.c" /* yacc.c:1646  */
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
#line 426 "parse.y" /* yacc.c:1906  */


int yyerror(char *s)
{
	cout << "Syntax Error on line " << yylineno << endl;
	
	return 0;
}

int error(char *s)
{

	ss << "Error semantico, variable " << s << " no declarada en la linea " << yylineno << endl;
	// declerrors.push_back(ss.str());
	cout << ss.str();
	ss.str(string());
	
	return 0;
}

string getType(short x)
{
	switch(x)
	{
		case Integer: 
				return strdup("Integer");
				break;
		case Real: 
				return strdup("Real");
				break;
		case String: 
				return strdup("String");
				break;
		case Procedure: 
				return strdup("Procedure");
				break;
		default: return strdup("Undefined");
					break;

	}
}

void typeError(short xtype, short ytype){

	string tipo1 = getType(xtype);
	string tipo2 = getType(ytype);

	ss << "Type error line " << yylineno << " type " << tipo1 << " missmatch " << tipo2 << endl;
	// typerrors.push_back(ss.str());
	cout << ss.str();
	ss.str(string());

}

short setType(short xtype, short ytype)
{
	if(xtype <= 2) 
	switch(xtype)
	{
		case Integer:	if(ytype == 0) return 0;
				else if(ytype == 1) return 1;
				else typeError(xtype, ytype);
				break;

		case Real:	if(ytype == 0) return 1;
				else if(ytype == 1) return 1;
				else typeError(xtype, ytype);
				break;
		case String:	if(ytype == 2) return 2;
				else typeError(xtype, ytype);
				break;
	}

	else{typeError(xtype, ytype);}
}

