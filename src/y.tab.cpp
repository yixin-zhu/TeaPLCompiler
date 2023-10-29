/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     OP_PLUS = 258,
     OP_MINUS = 259,
     OP_MULTIPLY = 260,
     OP_DIVTION = 261,
     OP_LESS = 262,
     OP_LE = 263,
     OP_GREAT = 264,
     OP_GE = 265,
     OP_EQ = 266,
     OP_NEQ = 267,
     OP_OR = 268,
     OP_AND = 269,
     LET = 270,
     RET = 271,
     FN = 272,
     TOKEN_ID = 273,
     TOKEN_NUM = 274,
     POS = 275,
     CONTINUE = 276,
     BREAK = 277,
     NULL = 278,
     IF = 279,
     ELSE = 280,
     WHILE = 281,
     NATIVETYPE = 282,
     UMINUS = 283
   };
#endif
/* Tokens.  */
#define OP_PLUS 258
#define OP_MINUS 259
#define OP_MULTIPLY 260
#define OP_DIVTION 261
#define OP_LESS 262
#define OP_LE 263
#define OP_GREAT 264
#define OP_GE 265
#define OP_EQ 266
#define OP_NEQ 267
#define OP_OR 268
#define OP_AND 269
#define LET 270
#define RET 271
#define FN 272
#define TOKEN_ID 273
#define TOKEN_NUM 274
#define POS 275
#define CONTINUE 276
#define BREAK 277
#define NULL 278
#define IF 279
#define ELSE 280
#define WHILE 281
#define NATIVETYPE 282
#define UMINUS 283




/* Copy the first part of user declarations.  */
#line 1 "parser.yacc"

#include <stdio.h>
#include "TeaplAst.h"

extern A_pos pos;
extern A_program root;

extern int yylex(void);
extern "C"{
extern void yyerror(char *s); 
extern int  yywrap();
}



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "parser.yacc"
{
    int num;
    char* token;
    char* key;
    char* id;
    A_pos pos;
    A_varDecl       varDecl;
    A_varDef        varDef;
    A_rightVal      rightVal;
    A_arithExpr     arithExpr;
    A_boolExpr      boolExpr;
    A_arithBiOpExpr arithBiOpExpr;
    A_arithUExpr    arithUExpr;
    A_exprUnit      exprUnit;
    A_fnCall        fnCall;
    A_indexExpr     indexExpr;
    A_arrayExpr     arrayExpr;
    A_memberExpr    memberExpr;
    A_boolUnit      boolUnit;
    A_boolBiOpExpr  boolBiOpExpr;
    A_boolUOpExpr   boolUOpExpr;
    A_comExpr       comExpr;
    A_leftVal       leftVal;
    A_assignStmt    assignStmt;
    A_rightValList  rightValList;
    A_varDefScalar  varDefScalar;
    A_varDefArray   varDefArray;
    A_varDeclScalar varDeclScalar;
    A_varDeclArray  varDeclArray;
    A_varDeclStmt   varDeclStmt;
    A_varDeclList   varDeclList;
    A_structDef     structDef;
    A_paramDecl     paramDecl;
    A_fnDecl        fnDecl;
    A_fnDef         fnDef;
    A_codeBlockStmt codeBlockStmt;
    A_ifStmt        ifStmt;
    A_whileStmt     whileStmt;
    A_fnDeclStmt    fnDeclStmt;
    A_callStmt      callStmt;
    A_returnStmt    returnStmt;
    A_programElement        programElement;
    A_codeBlockStmtList     codeBlockStmtList;
    A_programElementList    programElementList;
    A_program       program;
    A_tokenId       tokenId;
    A_tokenNum      tokenNum;
    A_type          type;
    A_arithBiOp     arithBiOp;
    A_arithUOp      arithUOp;
    A_nativeType    ntype;
    A_boolBiOp      boolBiOp;
    A_comOp         comOp;
    A_boolUOp       boolUOp;
}
/* Line 193 of yacc.c.  */
#line 223 "y.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 236 "y.tab.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   155

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNRULES -- Number of states.  */
#define YYNSTATES  174

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,     2,     2,     2,     2,     2,     2,
      14,    16,     2,     2,    18,    42,    22,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    19,
       2,    17,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    23,     2,    24,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    41,     2,     2,     2,     2,
       2,     2,     2,    20,     2,    21,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    15,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    15,    18,    21,
      24,    25,    29,    33,    35,    37,    41,    48,    50,    52,
      58,    60,    62,    64,    66,    70,    72,    74,    76,    78,
      80,    82,    86,    88,    90,    92,    94,    97,   102,   104,
     106,   110,   112,   117,   121,   123,   129,   133,   135,   146,
     148,   150,   152,   154,   158,   160,   162,   164,   166,   168,
     172,   174,   176,   178,   180,   182,   184,   187,   189,   192,
     198,   207,   209,   212,   215,   217,   222,   226,   230,   234,
     238,   242,   246,   251,   256,   260,   265,   267,   269,   271,
     274,   282,   288
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    46,    -1,    47,    46,    -1,    -1,    48,
      47,    -1,    66,    47,    -1,    78,    47,    -1,    81,    47,
      -1,    19,    47,    -1,    -1,    26,    49,    19,    -1,    26,
      52,    19,    -1,    50,    -1,    51,    -1,    29,    40,    69,
      -1,    29,    23,    30,    24,    40,    69,    -1,    53,    -1,
      68,    -1,    29,    40,    69,    17,    54,    -1,    55,    -1,
      70,    -1,    56,    -1,    58,    -1,    55,    57,    55,    -1,
       3,    -1,     4,    -1,     5,    -1,     6,    -1,    30,    -1,
      29,    -1,    14,    55,    16,    -1,    64,    -1,    60,    -1,
      62,    -1,    59,    -1,    63,    58,    -1,    29,    23,    61,
      24,    -1,    29,    -1,    30,    -1,    29,    22,    29,    -1,
       4,    -1,    29,    14,    65,    16,    -1,    54,    18,    65,
      -1,    54,    -1,    41,    29,    20,    67,    21,    -1,    49,
      18,    67,    -1,    49,    -1,    29,    23,    30,    24,    40,
      69,    17,    20,    65,    21,    -1,    29,    -1,    38,    -1,
      71,    -1,    73,    -1,    70,    72,    73,    -1,    15,    -1,
      13,    -1,    74,    -1,    70,    -1,    76,    -1,    58,    75,
      58,    -1,    11,    -1,    12,    -1,     8,    -1,     7,    -1,
       9,    -1,    10,    -1,    77,    73,    -1,    25,    -1,    79,
      19,    -1,    28,    29,    14,    80,    16,    -1,    28,    29,
      14,    80,    16,    42,    43,    69,    -1,    67,    -1,    79,
      82,    -1,    83,    82,    -1,    83,    -1,    20,    34,    19,
      21,    -1,    20,    48,    21,    -1,    20,    85,    21,    -1,
      20,    87,    21,    -1,    20,    88,    21,    -1,    20,    89,
      21,    -1,    20,    84,    21,    -1,    20,    32,    19,    21,
      -1,    20,    33,    19,    21,    -1,    27,    54,    19,    -1,
      86,    17,    54,    19,    -1,    29,    -1,    60,    -1,    62,
      -1,    64,    19,    -1,    35,    14,    70,    16,    83,    36,
      83,    -1,    35,    14,    70,    16,    83,    -1,    37,    14,
      70,    16,    83,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   146,   146,   152,   157,   161,   165,   169,   173,   177,
     182,   186,   190,   195,   199,   204,   209,   214,   218,   223,
     227,   231,   235,   239,   245,   251,   255,   259,   263,   269,
     273,   277,   281,   285,   289,   293,   298,   304,   309,   313,
     318,   324,   329,   335,   339,   344,   349,   353,   358,   363,
     367,   372,   376,   381,   386,   390,   395,   399,   403,   408,
     413,   417,   421,   425,   429,   433,   438,   443,   448,   453,
     457,   462,   467,   472,   476,   482,   486,   490,   494,   498,
     502,   506,   510,   514,   519,   524,   529,   533,   537,   542,
     547,   551,   556
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OP_PLUS", "OP_MINUS", "OP_MULTIPLY",
  "OP_DIVTION", "OP_LESS", "OP_LE", "OP_GREAT", "OP_GE", "OP_EQ", "OP_NEQ",
  "OP_OR", "'('", "OP_AND", "')'", "'='", "','", "';'", "'{'", "'}'",
  "'.'", "'['", "']'", "'!'", "LET", "RET", "FN", "TOKEN_ID", "TOKEN_NUM",
  "POS", "CONTINUE", "BREAK", "NULL", "IF", "ELSE", "WHILE", "NATIVETYPE",
  "UMINUS", "':'", "'struct'", "'-'", "'>'", "$accept", "PROGRAM",
  "PROGRAMELEMENTLIST", "PROGRAMELEMENT", "VARDECLSTMT", "VARDECL",
  "VARDECLSCALAR", "VARDECLARRAY", "VARDEF", "VARDEFSCALAR", "RIGHTVAL",
  "ARITHEXPR", "ARITHBIOPEXPR", "AIRTHBIOP", "EXPRUNIT", "ARITHUEXPR",
  "ARRAYEXPR", "INDEXEXPR", "MEMBEREXPR", "ARITHUOP", "FN_CALL",
  "RIGHTVALLIST", "STRUCTDEF", "VARDECLLIST", "VARDEFARRAY", "TYPE",
  "BOOLEXPR", "BOOLBIOPEXPR", "BOOLBIOP", "BOOLUNIT", "COMPEXPR", "COMOP",
  "BOOLUOPEXPR", "BOOLUOP", "FNDECLSTMT", "FNDECL", "PARAMDECL", "FNDEF",
  "CODEBLOCKSTMTLIST", "CODEBLOCKSTMT", "RETURNSTMT", "ASSIGNSTMT",
  "LEFTVAL", "CALLSTMT", "IFSTMT", "WHILESTMT", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,    40,   269,    41,    61,    44,    59,
     123,   125,    46,    91,    93,    33,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
      58,   115,    45,    62
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    47,    47,
      47,    48,    48,    49,    49,    50,    51,    52,    52,    53,
      54,    54,    55,    55,    56,    57,    57,    57,    57,    58,
      58,    58,    58,    58,    58,    58,    59,    60,    61,    61,
      62,    63,    64,    65,    65,    66,    67,    67,    68,    69,
      69,    70,    70,    71,    72,    72,    73,    73,    73,    74,
      75,    75,    75,    75,    75,    75,    76,    77,    78,    79,
      79,    80,    81,    82,    82,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    84,    85,    86,    86,    86,    87,
      88,    88,    89
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     2,     2,     2,     2,
       0,     3,     3,     1,     1,     3,     6,     1,     1,     5,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     2,     4,     1,     1,
       3,     1,     4,     3,     1,     5,     3,     1,    10,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     5,
       8,     1,     2,     2,     1,     4,     3,     3,     3,     3,
       3,     3,     4,     4,     3,     4,     1,     1,     1,     2,
       7,     5,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    10,     0,     0,     0,     0,     2,     4,    10,    10,
      10,     0,    10,     9,     0,     0,    13,    14,     0,    17,
      18,     0,     0,     1,     3,     5,     6,     7,    68,     0,
      72,    74,     8,     0,     0,    11,    12,     0,     0,     0,
      86,     0,     0,     0,     0,     0,     0,    87,    88,     0,
       0,     0,     0,     0,     0,     0,    73,     0,    49,    50,
      15,     0,    47,    71,     0,     0,    41,     0,    67,    30,
      29,     0,    20,    22,    23,    35,    33,    34,     0,    32,
      21,    51,    52,    56,    58,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    76,    89,    81,    77,     0,    78,
      79,    80,     0,     0,     0,     0,     0,    69,    45,     0,
      23,    84,    25,    26,    27,    28,     0,    63,    62,    64,
      65,    60,    61,     0,    36,    55,    54,     0,     0,    57,
      52,    44,     0,    40,    38,    39,     0,    82,    83,    75,
       0,     0,     0,     0,    19,     0,    15,    46,     0,    31,
      24,    59,    52,     0,    42,    37,     0,     0,    85,    16,
       0,     0,    43,    91,    92,     0,     0,    70,     0,     0,
      16,    90,     0,    48
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    62,    16,    17,    18,    19,
     131,    72,    73,   116,    74,    75,    76,   136,    77,    78,
      79,   132,     9,    63,    20,    60,    80,    81,   127,    82,
      83,   123,    84,    85,    10,    11,    64,    12,    30,    31,
      50,    51,    52,    53,    54,    55
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -134
static const yytype_int16 yypact[] =
{
      -4,    -4,   -18,   -11,    -6,    16,  -134,    -4,    -4,    -4,
      -4,    26,    -4,  -134,   -15,     7,  -134,  -134,    19,  -134,
    -134,    44,    30,  -134,  -134,  -134,  -134,  -134,  -134,    43,
    -134,    40,  -134,    41,     2,  -134,  -134,    55,    55,     5,
      65,    54,    67,    81,    93,    94,    83,  -134,  -134,    91,
      88,    95,    96,    97,    98,    99,  -134,    87,  -134,  -134,
     100,   -13,   103,  -134,   106,   102,  -134,     3,  -134,    65,
    -134,   105,    92,  -134,    82,  -134,  -134,  -134,     3,  -134,
      36,  -134,  -134,  -134,  -134,     5,     5,    85,    35,   104,
     107,   108,     5,     5,  -134,  -134,  -134,  -134,     5,  -134,
    -134,  -134,    72,     5,   101,     2,    55,    84,  -134,    38,
    -134,  -134,  -134,  -134,  -134,  -134,     3,  -134,  -134,  -134,
    -134,  -134,  -134,     3,  -134,  -134,  -134,     5,    82,    36,
    -134,   109,   114,  -134,  -134,  -134,   110,  -134,  -134,  -134,
      86,    90,   113,     2,  -134,   111,  -134,  -134,   112,  -134,
      92,  -134,  -134,     5,  -134,  -134,    40,    40,  -134,   116,
      75,     2,  -134,   115,  -134,   117,     2,  -134,    40,     5,
    -134,  -134,   118,  -134
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -134,  -134,   129,    73,   119,   136,  -134,  -134,  -134,  -134,
     -37,   -63,  -134,  -134,   -64,  -134,   120,  -134,   121,  -134,
     123,  -133,  -134,   -38,  -134,  -104,   -80,  -134,  -134,   -79,
    -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,   122,  -101,
    -134,  -134,  -134,  -134,  -134,  -134
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      65,   146,    71,   110,   109,   129,   130,    66,    33,    66,
     104,    14,   140,   141,   124,     1,    23,    67,    21,    67,
     162,   128,     2,    22,     3,    34,    35,   105,   128,   128,
      68,    58,    69,    70,    69,    70,   172,     4,    36,   159,
      59,   112,   113,   114,   115,    28,    29,   129,   152,   125,
      38,   126,   110,   150,   149,   163,   164,   167,    37,   151,
      29,   142,   170,   128,   134,   135,   144,   171,   147,     2,
      39,    57,    40,    89,    13,    41,    42,    43,    44,    86,
      45,    25,    26,    27,    61,    32,    90,    87,    88,   117,
     118,   119,   120,   121,   122,   112,   113,   114,   115,   125,
      91,   126,   156,   125,    94,   126,   157,    92,    93,    96,
      95,   102,   143,    98,   133,   166,    97,   103,    99,   100,
     101,   106,   107,   108,   111,   137,   148,   153,   138,   139,
     154,   145,   158,   165,   155,   160,    24,   169,    15,   173,
       0,     0,     0,     0,     0,     0,     0,     0,    46,    47,
      48,   168,    49,    56,     0,   161
};

static const yytype_int16 yycheck[] =
{
      38,   105,    39,    67,    67,    85,    85,     4,    23,     4,
      23,    29,    92,    93,    78,    19,     0,    14,    29,    14,
     153,    85,    26,    29,    28,    40,    19,    40,    92,    93,
      25,    29,    29,    30,    29,    30,   169,    41,    19,   143,
      38,     3,     4,     5,     6,    19,    20,   127,   127,    13,
      20,    15,   116,   116,    16,   156,   157,   161,    14,   123,
      20,    98,   166,   127,    29,    30,   103,   168,   106,    26,
      27,    30,    29,    19,     1,    32,    33,    34,    35,    14,
      37,     8,     9,    10,    29,    12,    19,    22,    23,     7,
       8,     9,    10,    11,    12,     3,     4,     5,     6,    13,
      19,    15,    16,    13,    21,    15,    16,    14,    14,    21,
      19,    24,    40,    17,    29,    40,    21,    17,    21,    21,
      21,    18,    16,    21,    19,    21,    42,    18,    21,    21,
      16,    30,    19,    17,    24,    24,     7,    20,     2,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    29,
      29,    36,    29,    31,    -1,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,    26,    28,    41,    45,    46,    47,    48,    66,
      78,    79,    81,    47,    29,    49,    50,    51,    52,    53,
      68,    29,    29,     0,    46,    47,    47,    47,    19,    20,
      82,    83,    47,    23,    40,    19,    19,    14,    20,    27,
      29,    32,    33,    34,    35,    37,    48,    60,    62,    64,
      84,    85,    86,    87,    88,    89,    82,    30,    29,    38,
      69,    29,    49,    67,    80,    67,     4,    14,    25,    29,
      30,    54,    55,    56,    58,    59,    60,    62,    63,    64,
      70,    71,    73,    74,    76,    77,    14,    22,    23,    19,
      19,    19,    14,    14,    21,    19,    21,    21,    17,    21,
      21,    21,    24,    17,    23,    40,    18,    16,    21,    55,
      58,    19,     3,     4,     5,     6,    57,     7,     8,     9,
      10,    11,    12,    75,    58,    13,    15,    72,    58,    70,
      73,    54,    65,    29,    29,    30,    61,    21,    21,    21,
      70,    70,    54,    40,    54,    30,    69,    67,    42,    16,
      55,    58,    73,    18,    16,    24,    16,    16,    19,    69,
      24,    43,    65,    83,    83,    17,    40,    69,    36,    20,
      69,    83,    65,    21
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 147 "parser.yacc"
    {
        root=A_program((yyvsp[(1) - (1)].programElementList));
        (yyval.program)=root;
    }
    break;

  case 3:
#line 153 "parser.yacc"
    {
        (yyval.programElementList)=A_programElementList((yyvsp[(1) - (2)].programElement),(yyvsp[(2) - (2)].programElementList));
    }
    break;

  case 4:
#line 157 "parser.yacc"
    {
        (yyval.programElementList)=NULL;
    }
    break;

  case 5:
#line 162 "parser.yacc"
    {
        (yyval.programElement)=A_ProgramVarDeclStmt((yyvsp[(1) - (2)].varDeclStmt)->pos, (yyvsp[(1) - (2)].varDeclStmt));
    }
    break;

  case 6:
#line 166 "parser.yacc"
    {
        (yyval.programElement)=A_ProgramStructDef((yyvsp[(1) - (2)].structDef)->pos, (yyvsp[(1) - (2)].structDef));
    }
    break;

  case 7:
#line 170 "parser.yacc"
    {
        (yyval.programElement)=A_ProgramFnDeclStmt((yyvsp[(1) - (2)].fnDeclStmt)->pos, (yyvsp[(1) - (2)].fnDeclStmt));
    }
    break;

  case 8:
#line 174 "parser.yacc"
    {
        (yyval.programElement)=A_ProgramFnDef((yyvsp[(1) - (2)].fnDef)->pos, (yyvsp[(1) - (2)].fnDef));
    }
    break;

  case 9:
#line 178 "parser.yacc"
    {
        (yyval.programElement)=A_ProgramNullStmt((yyvsp[(1) - (2)].token)->pos);
    }
    break;

  case 10:
#line 182 "parser.yacc"
    {
        (yyval.programElement)=NULL;
    }
    break;

  case 11:
#line 187 "parser.yacc"
    {
        (yyval.varDeclStmt)=A_VarDeclStmt((yyvsp[(2) - (3)].varDecl)->pos, (yyvsp[(2) - (3)].varDecl));
    }
    break;

  case 12:
#line 191 "parser.yacc"
    {
        (yyval.varDeclStmt)=A_VarDefStmt((yyvsp[(2) - (3)].varDef)->pos, (yyvsp[(2) - (3)].varDef));
    }
    break;

  case 13:
#line 196 "parser.yacc"
    {
        (yyval.varDecl)=A_VarDeclScalar((yyvsp[(1) - (1)].varDeclScalar)->pos, (yyvsp[(1) - (1)].varDeclScalar));
    }
    break;

  case 14:
#line 200 "parser.yacc"
    {
        (yyval.varDecl)=A_VarDeclArray((yyvsp[(1) - (1)].varDeclArray)->pos, (yyvsp[(1) - (1)].varDeclArray));
    }
    break;

  case 15:
#line 205 "parser.yacc"
    {
        (yyval.varDeclScalar)=A_VarDeclScalar((yyvsp[(1) - (3)].tokenId)->pos, (yyvsp[(1) - (3)].tokenId)->id, (yyvsp[(3) - (3)].type));
    }
    break;

  case 16:
#line 210 "parser.yacc"
    {
        (yyval.varDeclArray)=A_VarDeclArray((yyvsp[(1) - (6)].tokenId)->pos, (yyvsp[(1) - (6)].tokenId)->id, (yyvsp[(3) - (6)].tokenNum)->num, (yyvsp[(6) - (6)].type));
    }
    break;

  case 17:
#line 215 "parser.yacc"
    {
        (yyval.varDef)=A_VarDef_Scalar((yyvsp[(1) - (1)].varDefScalar)->pos, (yyvsp[(1) - (1)].varDefScalar));
    }
    break;

  case 18:
#line 219 "parser.yacc"
    {
        (yyval.varDef)=A_VarDef_Array((yyvsp[(1) - (1)].varDefArray)->pos, (yyvsp[(1) - (1)].varDefArray));
    }
    break;

  case 19:
#line 224 "parser.yacc"
    {
        (yyval.varDefScalar)=A_VarDefScalar((yyvsp[(3) - (5)].type)->pos, (yyvsp[(1) - (5)].tokenId)->id, (yyvsp[(3) - (5)].type), (yyvsp[(5) - (5)].rightVal));
    }
    break;

  case 20:
#line 228 "parser.yacc"
    {
        (yyval.rightVal)=A_ArithExprRVal((yyvsp[(1) - (1)].arithExpr)->pos, (yyvsp[(1) - (1)].arithExpr));
    }
    break;

  case 21:
#line 232 "parser.yacc"
    {
        (yyval.rightVal)=A_BoolExprRVal((yyvsp[(1) - (1)].boolExpr)->pos, (yyvsp[(1) - (1)].boolExpr));
    }
    break;

  case 22:
#line 236 "parser.yacc"
    {
        (yyval.arithExpr)=A_ArithBiOp_Expr((yyvsp[(1) - (1)].arithBiOpExpr)->pos, (yyvsp[(1) - (1)].arithBiOpExpr));
    }
    break;

  case 23:
#line 240 "parser.yacc"
    {
        (yyval.arithExpr)=A_ExprUnit((yyvsp[(1) - (1)].exprUnit)->pos, (yyvsp[(1) - (1)].exprUnit));
    }
    break;

  case 24:
#line 246 "parser.yacc"
    {
        (yyval.arithBiOpExpr)=A_ArithBiOpExpr((yyvsp[(2) - (3)].arithBiOp)->pos, (yyvsp[(2) - (3)].arithBiOp), (yyvsp[(1) - (3)].arithExpr), (yyvsp[(3) - (3)].arithExpr));
    }
    break;

  case 25:
#line 252 "parser.yacc"
    {
        (yyval.arithBiOp)= A_add;
    }
    break;

  case 26:
#line 256 "parser.yacc"
    {
        (yyval.arithBiOp)= A_sub
    }
    break;

  case 27:
#line 260 "parser.yacc"
    {
        (yyval.arithBiOp)= A_mul
    }
    break;

  case 28:
#line 264 "parser.yacc"
    {
        (yyval.arithBiOp)= A_div
    }
    break;

  case 29:
#line 270 "parser.yacc"
    {
        (yyval.exprUnit)=A_NumExprUnit((yyvsp[(1) - (1)].tokenNum)->pos, (yyvsp[(1) - (1)].tokenNum)->num);
    }
    break;

  case 30:
#line 274 "parser.yacc"
    {
        (yyval.exprUnit)=A_IdExprUnit((yyvsp[(1) - (1)].tokenId)->pos, (yyvsp[(1) - (1)].tokenId)->id);
    }
    break;

  case 31:
#line 278 "parser.yacc"
    {
        (yyval.exprUnit)=A_ArithUExprUnit((yyvsp[(2) - (3)].arithExpr)->pos, (yyvsp[(2) - (3)].arithExpr));
    }
    break;

  case 32:
#line 282 "parser.yacc"
    {
        (yyval.exprUnit)=A_CallExprUnit((yyvsp[(1) - (1)].fnCall)->pos, (yyvsp[(1) - (1)].fnCall));
    }
    break;

  case 33:
#line 286 "parser.yacc"
    {
        (yyval.exprUnit)=A_ArrayExprUnit((yyvsp[(1) - (1)].arrayExpr)->pos, (yyvsp[(1) - (1)].arrayExpr));
    }
    break;

  case 34:
#line 290 "parser.yacc"
    {
        (yyval.exprUnit)=A_MemberExprUnit((yyvsp[(1) - (1)].memberExpr)->pos, (yyvsp[(1) - (1)].memberExpr));
    }
    break;

  case 35:
#line 294 "parser.yacc"
    {
        (yyval.exprUnit)=A_ArithUExprUnit((yyvsp[(1) - (1)].arithUExpr)->pos, (yyvsp[(1) - (1)].arithUExpr));
    }
    break;

  case 36:
#line 299 "parser.yacc"
    {
        (yyval.arithUExpr)=A_ArithUExprUnit((yyvsp[(1) - (2)].arithUOp)->pos, (yyvsp[(1) - (2)].arithUOp), (yyvsp[(2) - (2)].exprUnit));
    }
    break;

  case 37:
#line 305 "parser.yacc"
    {
        (yyval.arrayExpr)=A_ArrayExpr((yyvsp[(1) - (4)].tokenId)->pos, (yyvsp[(1) - (4)].tokenId)->id, (yyvsp[(3) - (4)].indexExpr));
    }
    break;

  case 38:
#line 310 "parser.yacc"
    {
        (yyval.indexExpr)=A_IdIndexExpr((yyvsp[(1) - (1)].tokenId)->pos, (yyvsp[(1) - (1)].tokenId)->id);
    }
    break;

  case 39:
#line 314 "parser.yacc"
    {
        (yyval.indexExpr)=A_NumIndexExpr((yyvsp[(1) - (1)].tokenNum)->pos, (yyvsp[(1) - (1)].tokenNum)->num);
    }
    break;

  case 40:
#line 319 "parser.yacc"
    {
        (yyval.memberExpr)=A_MemberExpr((yyvsp[(1) - (3)].tokenId)->pos, (yyvsp[(1) - (3)].tokenId)->id, (yyvsp[(3) - (3)].tokenId)->id);
    }
    break;

  case 41:
#line 325 "parser.yacc"
    {
        (yyval.arithUOp)=A_neg;
    }
    break;

  case 42:
#line 330 "parser.yacc"
    {
        (yyval.fnCall)=A_FnCall((yyvsp[(1) - (4)].tokenId)->pos, (yyvsp[(1) - (4)].tokenId)->id, (yyvsp[(3) - (4)].rightValList));
    }
    break;

  case 43:
#line 336 "parser.yacc"
    {
        (yyval.rightValList)=A_RightValList((yyvsp[(1) - (3)].rightVal)->pos, (yyvsp[(1) - (3)].rightVal), (yyvsp[(3) - (3)].rightValList));
    }
    break;

  case 44:
#line 340 "parser.yacc"
    {
        (yyval.rightValList)=A_RightValList((yyvsp[(1) - (1)].rightVal)->pos, (yyvsp[(1) - (1)].rightVal), NULL);
    }
    break;

  case 45:
#line 345 "parser.yacc"
    {
        (yyval.structDef)=A_StructDef((yyvsp[(2) - (5)].tokenId)->pos, (yyvsp[(2) - (5)].tokenId)->id, (yyvsp[(4) - (5)].varDeclList));
    }
    break;

  case 46:
#line 350 "parser.yacc"
    {
        (yyval.varDeclList)=A_VarDeclList((yyvsp[(1) - (3)].varDecl)->pos, (yyvsp[(1) - (3)].varDecl), (yyvsp[(3) - (3)].varDeclList));
    }
    break;

  case 47:
#line 354 "parser.yacc"
    {
        (yyval.varDeclList)=A_VarDeclList((yyvsp[(1) - (1)].varDecl)->pos, (yyvsp[(1) - (1)].varDecl), NULL);
    }
    break;

  case 48:
#line 359 "parser.yacc"
    {
        (yyval.varDefArray)=A_VarDefArray((yyvsp[(1) - (10)].tokenId)->pos, (yyvsp[(1) - (10)].tokenId)->id, (yyvsp[(3) - (10)].tokenNum)->num, (yyvsp[(6) - (10)].type), (yyvsp[(9) - (10)].rightValList));
    }
    break;

  case 49:
#line 364 "parser.yacc"
    {
        (yyval.type)=A_StructType((yyvsp[(1) - (1)].tokenId)->pos, (yyvsp[(1) - (1)].tokenId)->id);
    }
    break;

  case 50:
#line 368 "parser.yacc"
    {
        (yyval.type)=A_NativeType((yyvsp[(1) - (1)].ntype)->pos, (yyvsp[(1) - (1)].ntype)->ntype);
    }
    break;

  case 51:
#line 373 "parser.yacc"
    {
        (yyval.boolExpr)=A_BoolBiOp_Expr((yyvsp[(1) - (1)].boolBiOpExpr)->pos, (yyvsp[(1) - (1)].boolBiOpExpr));
    }
    break;

  case 52:
#line 377 "parser.yacc"
    {
        (yyval.boolExpr)=A_BoolExpr((yyvsp[(1) - (1)].boolUnit)->pos, (yyvsp[(1) - (1)].boolUnit));
    }
    break;

  case 53:
#line 382 "parser.yacc"
    {
        (yyval.boolBiOpExpr)=A_BoolBiOpExpr((yyvsp[(2) - (3)].boolBiOp)->pos, (yyvsp[(2) - (3)].boolBiOp), (yyvsp[(1) - (3)].boolExpr), (yyvsp[(3) - (3)].boolUnit));
    }
    break;

  case 54:
#line 387 "parser.yacc"
    {
        (yyval.boolBiOp)=A_and;
    }
    break;

  case 55:
#line 391 "parser.yacc"
    {
        (yyval.boolBiOp)=A_or;
    }
    break;

  case 56:
#line 396 "parser.yacc"
    {
        (yyval.boolUnit)=A_ComExpr((yyvsp[(1) - (1)].comExpr)->pos, (yyvsp[(1) - (1)].comExpr));
    }
    break;

  case 57:
#line 400 "parser.yacc"
    {
        (yyval.boolUnit)=A_BoolExprUnit((yyvsp[(1) - (1)].boolExpr)->pos, (yyvsp[(1) - (1)].boolExpr));
    }
    break;

  case 58:
#line 404 "parser.yacc"
    {
        (yyval.boolUnit)=A_BoolUOpExpr((yyvsp[(1) - (1)].boolUOpExpr)->pos, (yyvsp[(1) - (1)].boolUOpExpr));
    }
    break;

  case 59:
#line 409 "parser.yacc"
    {
        (yyval.comExpr)=A_ComExpr((yyvsp[(2) - (3)].comOp)->pos, (yyvsp[(2) - (3)].comOp), (yyvsp[(1) - (3)].exprUnit), (yyvsp[(3) - (3)].exprUnit));
    }
    break;

  case 60:
#line 414 "parser.yacc"
    {
        (yyval.comOp)=A_eq;
    }
    break;

  case 61:
#line 418 "parser.yacc"
    {
        (yyval.comOp)=A_ne;
    }
    break;

  case 62:
#line 422 "parser.yacc"
    {
        (yyval.comOp)=A_le;
    }
    break;

  case 63:
#line 426 "parser.yacc"
    {
        (yyval.comOp)=A_lt;
    }
    break;

  case 64:
#line 430 "parser.yacc"
    {
        (yyval.comOp)=A_gt;
    }
    break;

  case 65:
#line 434 "parser.yacc"
    {
        (yyval.comOp)=A_ge;
    }
    break;

  case 66:
#line 439 "parser.yacc"
    {
        (yyval.boolUOpExpr)=A_BoolUOpExpr((yyvsp[(2) - (2)].boolUnit)->pos, (yyvsp[(1) - (2)].boolUOp), (yyvsp[(2) - (2)].boolUnit));
    }
    break;

  case 67:
#line 444 "parser.yacc"
    {
        (yyval.boolUOp)=A_not;
    }
    break;

  case 68:
#line 449 "parser.yacc"
    {
        (yyval.fnDeclStmt)=A_FnDecl((yyvsp[(1) - (2)].fnDecl)->pos, (yyvsp[(1) - (2)].fnDecl));
    }
    break;

  case 69:
#line 454 "parser.yacc"
    {
        (yyval.fnDecl)=A_FnDecl((yyvsp[(1) - (5)].key)->pos, (yyvsp[(2) - (5)].tokenId)->id, (yyvsp[(4) - (5)].paramDecl), NULL);
    }
    break;

  case 70:
#line 458 "parser.yacc"
    {
        (yyval.fnDecl)=A_FnDecl((yyvsp[(1) - (8)].key)->pos, (yyvsp[(2) - (8)].tokenId)->id, (yyvsp[(4) - (8)].paramDecl), (yyvsp[(8) - (8)].type));
    }
    break;

  case 71:
#line 463 "parser.yacc"
    {
        (yyval.paramDecl)=A_ParamDecl((yyvsp[(1) - (1)].varDeclList)->pos, (yyvsp[(1) - (1)].varDeclList));
    }
    break;

  case 72:
#line 468 "parser.yacc"
    {
        (yyval.fnDef)=A_FnDef((yyvsp[(1) - (2)].fnDecl)->pos, (yyvsp[(1) - (2)].fnDecl), (yyvsp[(2) - (2)].codeBlockStmtList));
    }
    break;

  case 73:
#line 473 "parser.yacc"
    {
        (yyval.codeBlockStmtList)=A_CodeBlockStmtList((yyvsp[(1) - (2)].codeBlockStmt)->pos, (yyvsp[(1) - (2)].codeBlockStmt), (yyvsp[(2) - (2)].codeBlockStmtList));
    }
    break;

  case 74:
#line 477 "parser.yacc"
    {
        (yyval.codeBlockStmtList)=A_CodeBlockStmtList((yyvsp[(1) - (1)].codeBlockStmt)->pos, (yyvsp[(1) - (1)].codeBlockStmt), NULL);
    }
    break;

  case 75:
#line 483 "parser.yacc"
    {
        (yyval.codeBlockStmt)=A_BlockNullStmt((yyvsp[(2) - (4)].pos)->pos);
    }
    break;

  case 76:
#line 487 "parser.yacc"
    {
        (yyval.codeBlockStmt)=A_BlockVarDeclStmt((yyvsp[(2) - (3)].varDeclStmt)->pos, (yyvsp[(2) - (3)].varDeclStmt));
    }
    break;

  case 77:
#line 491 "parser.yacc"
    {
        (yyval.codeBlockStmt)=A_BlockAssignStmt((yyvsp[(2) - (3)].assignStmt)->pos, (yyvsp[(2) - (3)].assignStmt));
    }
    break;

  case 78:
#line 495 "parser.yacc"
    {
        (yyval.codeBlockStmt)=A_BlockCallStmt((yyvsp[(2) - (3)].callStmt)->pos, (yyvsp[(2) - (3)].callStmt));
    }
    break;

  case 79:
#line 499 "parser.yacc"
    {
        (yyval.codeBlockStmt)=A_BlockIfStmt((yyvsp[(2) - (3)].ifStmt)->pos, (yyvsp[(2) - (3)].ifStmt));
    }
    break;

  case 80:
#line 503 "parser.yacc"
    {
        (yyval.codeBlockStmt)=A_BlockWhileStmt((yyvsp[(2) - (3)].whileStmt)->pos, (yyvsp[(2) - (3)].whileStmt));
    }
    break;

  case 81:
#line 507 "parser.yacc"
    {
        (yyval.codeBlockStmt)=A_BlockReturnStmt((yyvsp[(2) - (3)].returnStmt)->pos, (yyvsp[(2) - (3)].returnStmt));
    }
    break;

  case 82:
#line 511 "parser.yacc"
    {
        (yyval.codeBlockStmt)=A_BlockContinueStmt((yyvsp[(2) - (4)].pos)->pos);
    }
    break;

  case 83:
#line 515 "parser.yacc"
    {
        (yyval.codeBlockStmt)=A_BlockBreakStmt((yyvsp[(2) - (4)].pos)->pos, (yyvsp[(2) - (4)].pos));
    }
    break;

  case 84:
#line 520 "parser.yacc"
    {
        (yyval.returnStmt)=A_ReturnStmt((yyvsp[(1) - (3)].key)->pos, (yyvsp[(2) - (3)].rightVal));
    }
    break;

  case 85:
#line 525 "parser.yacc"
    {
        (yyval.assignStmt)=A_AssignStmt((yyvsp[(1) - (4)].leftVal)->pos, (yyvsp[(1) - (4)].leftVal), (yyvsp[(3) - (4)].rightVal));
    }
    break;

  case 86:
#line 530 "parser.yacc"
    {
        (yyval.leftVal)=A_IdLeftVal((yyvsp[(1) - (1)].tokenId)->pos, (yyvsp[(1) - (1)].tokenId)->id);
    }
    break;

  case 87:
#line 534 "parser.yacc"
    {
        (yyval.leftVal)=A_ArrayLeftVal((yyvsp[(1) - (1)].arrayExpr)->pos, (yyvsp[(1) - (1)].arrayExpr));
    }
    break;

  case 88:
#line 538 "parser.yacc"
    {
        (yyval.leftVal)=A_MemberLeftVal((yyvsp[(1) - (1)].memberExpr)->pos, (yyvsp[(1) - (1)].memberExpr));
    }
    break;

  case 89:
#line 543 "parser.yacc"
    {
        (yyval.callStmt)=A_CallStmt((yyvsp[(1) - (2)].fnCall)->pos, (yyvsp[(1) - (2)].fnCall));
    }
    break;

  case 90:
#line 548 "parser.yacc"
    {
        (yyval.ifStmt)=A_IfStmt((yyvsp[(1) - (7)].pos)->pos, (yyvsp[(3) - (7)].boolExpr), (yyvsp[(5) - (7)].codeBlockStmt), (yyvsp[(7) - (7)].codeBlockStmt));
    }
    break;

  case 91:
#line 552 "parser.yacc"
    {
        (yyval.ifStmt)=A_IfStmt((yyvsp[(1) - (5)].pos)->pos, (yyvsp[(3) - (5)].boolExpr), (yyvsp[(5) - (5)].codeBlockStmt), NULL);
    }
    break;

  case 92:
#line 557 "parser.yacc"
    {
        (yyval.whileStmt)=A_WhileStmt((yyvsp[(1) - (5)].pos)->pos, (yyvsp[(3) - (5)].boolExpr), (yyvsp[(5) - (5)].codeBlockStmt));
    }
    break;


/* Line 1267 of yacc.c.  */
#line 2227 "y.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 560 "parser.yacc"
 


extern "C"{
void yyerror(char * s)
{
  fprintf(stderr, "%s\n",s);
}
int yywrap()
{
  return(1);
}
}



