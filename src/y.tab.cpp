/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
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


#line 85 "y.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    OP_ARROW = 270,
    LET = 271,
    RET = 272,
    FN = 273,
    STRUCT = 274,
    CONTINUE = 275,
    BREAK = 276,
    IF = 277,
    ELSE = 278,
    WHILE = 279,
    INT = 280,
    TOKEN_ID = 281,
    TOKEN_NUM = 282
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
#define OP_ARROW 270
#define LET 271
#define RET 272
#define FN 273
#define STRUCT 274
#define CONTINUE 275
#define BREAK 276
#define IF 277
#define ELSE 278
#define WHILE 279
#define INT 280
#define TOKEN_ID 281
#define TOKEN_NUM 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "parser.yacc"


    A_pos           token;
    A_pos           key;
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
    A_program       program;
    A_tokenId       tokenId;
    A_tokenNum      tokenNum;
    A_type          type;
    A_nativeType    ntype;
    A_programElement        programElement;
    A_codeBlockStmtList     codeBlockStmtList;
    A_programElementList    programElementList;

#line 240 "y.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   204

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

#define YYUNDEFTOK  2
#define YYMAXUTOK   282


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,     2,     2,     2,     2,     2,     2,
      15,    16,     2,     2,    18,     2,    22,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    39,    19,
       2,    17,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    23,     2,    24,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   121,   121,   128,   133,   138,   142,   146,   150,   154,
     160,   164,   170,   174,   178,   184,   188,   194,   201,   205,
     210,   214,   220,   226,   230,   235,   240,   244,   250,   254,
     260,   264,   270,   274,   279,   284,   288,   294,   300,   307,
     313,   318,   322,   328,   332,   336,   340,   344,   348,   352,
     356,   360,   365,   370,   374,   379,   385,   390,   394,   399,
     404,   408,   415,   419,   425,   430,   436,   441,   445,   449,
     455,   459,   463,   467,   471,   475,   480,   484,   488,   492,
     496,   502,   506,   511,   515,   519,   523,   527,   533,   539,
     543,   549,   555,   560,   564,   570
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OP_PLUS", "OP_MINUS", "OP_MULTIPLY",
  "OP_DIVTION", "OP_LESS", "OP_LE", "OP_GREAT", "OP_GE", "OP_EQ", "OP_NEQ",
  "OP_OR", "OP_AND", "'('", "')'", "'='", "','", "';'", "'{'", "'}'",
  "'.'", "'['", "']'", "'!'", "OP_ARROW", "LET", "RET", "FN", "STRUCT",
  "CONTINUE", "BREAK", "IF", "ELSE", "WHILE", "INT", "TOKEN_ID",
  "TOKEN_NUM", "':'", "$accept", "PROGRAM", "PROGRAMELEMENTLIST",
  "PROGRAMELEMENT", "RIGHTVAL", "LEFTVAL", "RIGHTVALLIST", "FNDECLSTMT",
  "FNDECL", "TYPE", "PARAMDECL", "VARDECLLIST", "VARDECL", "VARDECLSCALAR",
  "VARDECLARRAY", "VARDEF", "VARDEFARRAY", "VARDEFSCALAR", "FNDEF",
  "CODEBLOCK", "CODEBLOCKSTMTLIST", "CODEBLOCKSTMT", "RETURNSTMT",
  "ASSIGNSTMT", "CALLSTMT", "IFSTMT", "WHILESTMT", "VARDECLSTMT",
  "BOOLEXPR", "BOOLBIOPEXPR", "BOOLUNIT", "COMEXPR", "ARITHEXPR",
  "EXPRUNIT", "STRUCTDEF", "FNCALL", "ARITHUEXPR", "ARRAYEXPR",
  "INDEXEXPR", "MEMBEREXPR", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,    40,    41,    61,    44,    59,
     123,   125,    46,    91,    93,    33,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,    58
};
# endif

#define YYPACT_NINF (-130)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-15)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      30,  -130,   -16,   -11,    -3,    16,  -130,    30,  -130,    32,
    -130,  -130,  -130,    -9,    -6,  -130,  -130,    21,  -130,  -130,
      28,    33,  -130,  -130,  -130,    91,  -130,    74,    47,    44,
    -130,  -130,    58,    58,  -130,     8,    78,    85,   112,   114,
     139,   108,   113,    91,  -130,  -130,  -130,  -130,  -130,  -130,
     137,  -130,  -130,    46,    74,    74,    13,  -130,  -130,    84,
     151,  -130,  -130,  -130,   111,   138,  -130,  -130,   129,   144,
     134,  -130,  -130,   145,    -8,   156,  -130,   155,   153,  -130,
     157,  -130,  -130,    74,    74,    71,    74,   140,   131,  -130,
    -130,  -130,    46,  -130,    63,   159,    97,  -130,   138,    74,
      74,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    -7,    74,   141,    44,   152,    58,  -130,  -130,   119,
     147,  -130,   162,   166,   164,  -130,  -130,  -130,   160,  -130,
    -130,  -130,  -130,   151,   151,   165,   165,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,   161,    44,  -130,   163,  -130,
      44,  -130,   168,   169,    74,  -130,  -130,  -130,    74,   173,
     146,  -130,    91,    91,  -130,   170,   172,    44,   174,   175,
    -130,    74,  -130,   167,  -130,   176,   178,  -130,    91,   179,
    -130
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     9,    34,     0,     0,     0,     2,     4,     7,     0,
       8,     5,     6,    29,     0,    26,    27,     0,    33,    32,
       0,     0,     1,     3,    17,    52,    39,     0,     0,     0,
      60,    61,    25,    25,    43,     0,     0,     0,     0,     0,
      12,     0,     0,    42,    49,    45,    46,    47,    48,    44,
       0,    13,    14,     0,     0,     0,    82,    81,    38,     0,
      11,    62,    63,    66,    10,    80,    84,    87,    85,    86,
       0,    20,    21,    28,    29,     0,    22,    24,     0,    54,
       0,    50,    51,     0,     0,     0,     0,     0,     0,    40,
      41,    56,     0,    91,     0,    66,     0,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,     0,     0,     0,    18,    25,    88,    53,     0,
       0,    90,    16,     0,     0,    95,    93,    94,     0,    80,
      68,    67,    83,    64,    65,    76,    77,    78,    79,    71,
      73,    70,    72,    74,    75,     0,     0,    37,     0,    28,
       0,    23,     0,     0,     0,    89,    55,    92,     0,    30,
      31,    19,    52,    52,    15,     0,     0,     0,     0,     0,
      36,     0,    30,    58,    59,     0,     0,    35,    52,     0,
      57
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -130,  -130,   186,  -130,   -24,   -25,  -129,  -130,  -130,  -109,
    -130,   -26,   184,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
     -42,  -130,  -130,  -130,  -130,  -130,  -130,    98,   -45,  -130,
     148,   150,   -10,   -36,  -130,   -23,  -130,   -21,  -130,   -19
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,   122,    59,   123,     8,     9,    73,
      75,    76,    77,    15,    16,    17,    18,    19,    10,    26,
      42,    43,    44,    45,    46,    47,    48,    49,    60,    61,
      62,    63,    64,    65,    12,    66,    67,    68,   128,    69
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    90,    50,    58,    51,   149,    52,    78,    27,    94,
     145,    80,    53,    30,    28,   113,    22,    93,    41,    98,
      50,    13,    51,    54,    52,   164,    20,    79,    85,   165,
      29,   114,   146,    55,    21,   -12,   -12,   159,   119,   120,
      31,   161,   175,    32,    96,    56,    57,    98,    98,     1,
      53,    24,    25,    33,   133,   134,   129,     2,   172,     3,
       4,    92,   124,    98,    98,   129,   129,   129,   129,   139,
     140,   141,   142,   143,   144,    53,    99,   100,    53,   130,
      71,    72,    96,    56,    57,    70,    54,   121,   147,    54,
     151,   135,   136,   137,   138,    74,    55,    81,    11,    55,
     101,   102,   103,   104,    82,    11,    87,    88,    56,    57,
      34,    56,    57,   132,   101,   102,   103,   104,     2,    35,
     168,   169,    36,    37,    38,    86,    39,    83,    40,    84,
      87,    88,    99,   100,    89,   152,   179,    41,    41,    50,
      50,    51,    51,    52,    52,   105,   106,   107,   108,   109,
     110,   -13,   -13,    41,    85,    50,    91,    51,   111,    52,
      99,   100,   112,   153,    99,   100,   -14,   -14,   126,   127,
     103,   104,   115,   116,   117,   131,   118,   125,   150,   148,
     154,   158,   155,   156,   157,   167,    14,   160,   162,   163,
     166,   170,   171,    23,     0,   173,   174,   177,   178,     0,
     180,   176,     0,    97,    95
};

static const yytype_int16 yycheck[] =
{
      25,    43,    25,    27,    25,   114,    25,    33,    17,    54,
      17,    35,     4,    19,    23,    23,     0,    53,    43,    55,
      43,    37,    43,    15,    43,   154,    37,    19,    15,   158,
      39,    39,    39,    25,    37,    22,    23,   146,    83,    84,
      19,   150,   171,    15,    54,    37,    38,    83,    84,    19,
       4,    19,    20,    20,    99,   100,    92,    27,   167,    29,
      30,    15,    86,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,     4,    13,    14,     4,    16,
      36,    37,    92,    37,    38,    38,    15,    16,   112,    15,
     116,   101,   102,   103,   104,    37,    25,    19,     0,    25,
       3,     4,     5,     6,    19,     7,    22,    23,    37,    38,
      19,    37,    38,    16,     3,     4,     5,     6,    27,    28,
     162,   163,    31,    32,    33,    17,    35,    15,    37,    15,
      22,    23,    13,    14,    21,    16,   178,   162,   163,   162,
     163,   162,   163,   162,   163,     7,     8,     9,    10,    11,
      12,    22,    23,   178,    15,   178,    19,   178,    24,   178,
      13,    14,    17,    16,    13,    14,    22,    23,    37,    38,
       5,     6,    16,    18,    21,    16,    19,    37,    26,    38,
      18,    20,    16,    19,    24,    39,     2,    24,    20,    20,
      17,    21,    20,     7,    -1,    21,    21,    21,    20,    -1,
      21,    34,    -1,    55,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    27,    29,    30,    41,    42,    43,    47,    48,
      58,    67,    74,    37,    52,    53,    54,    55,    56,    57,
      37,    37,     0,    42,    19,    20,    59,    17,    23,    39,
      19,    19,    15,    20,    19,    28,    31,    32,    33,    35,
      37,    45,    60,    61,    62,    63,    64,    65,    66,    67,
      75,    77,    79,     4,    15,    25,    37,    38,    44,    45,
      68,    69,    70,    71,    72,    73,    75,    76,    77,    79,
      38,    36,    37,    49,    37,    50,    51,    52,    51,    19,
      44,    19,    19,    15,    15,    15,    17,    22,    23,    21,
      60,    19,    15,    73,    68,    71,    72,    70,    73,    13,
      14,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    24,    17,    23,    39,    16,    18,    21,    19,    68,
      68,    16,    44,    46,    44,    37,    37,    38,    78,    73,
      16,    16,    16,    68,    68,    72,    72,    72,    72,    73,
      73,    73,    73,    73,    73,    17,    39,    44,    38,    49,
      26,    51,    16,    16,    18,    16,    19,    24,    20,    49,
      24,    49,    20,    20,    46,    46,    17,    39,    60,    60,
      21,    20,    49,    21,    21,    46,    34,    21,    20,    60,
      21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    43,    43,
      44,    44,    45,    45,    45,    46,    46,    47,    48,    48,
      49,    49,    50,    51,    51,    51,    52,    52,    53,    53,
      54,    54,    55,    55,    55,    56,    56,    57,    57,    58,
      59,    60,    60,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    62,    62,    63,    64,    65,    65,    66,
      67,    67,    68,    68,    69,    69,    70,    70,    70,    70,
      71,    71,    71,    71,    71,    71,    72,    72,    72,    72,
      72,    73,    73,    73,    73,    73,    73,    73,    74,    75,
      75,    76,    77,    78,    78,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     2,     5,     7,
       1,     1,     1,     3,     1,     0,     1,     1,     3,     1,
       6,     4,     1,     1,     0,    10,     8,     5,     3,     2,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     0,     3,     2,     4,     2,    11,     7,     7,
       3,     3,     1,     1,     3,     3,     1,     3,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     3,     1,     1,     1,     1,     5,     4,
       3,     2,     4,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 122 "parser.yacc"
{  
  root = A_Program((yyvsp[0].programElementList));
  (yyval.program) = A_Program((yyvsp[0].programElementList));
}
#line 1550 "y.tab.cpp"
    break;

  case 3:
#line 129 "parser.yacc"
{
  (yyval.programElementList) = A_ProgramElementList((yyvsp[-1].programElement), (yyvsp[0].programElementList));
}
#line 1558 "y.tab.cpp"
    break;

  case 4:
#line 133 "parser.yacc"
{
  (yyval.programElementList) = NULL;
}
#line 1566 "y.tab.cpp"
    break;

  case 5:
#line 139 "parser.yacc"
{
  (yyval.programElement) = A_ProgramVarDeclStmt((yyvsp[0].varDeclStmt)->pos, (yyvsp[0].varDeclStmt));
}
#line 1574 "y.tab.cpp"
    break;

  case 6:
#line 143 "parser.yacc"
{
  (yyval.programElement) = A_ProgramStructDef((yyvsp[0].structDef)->pos, (yyvsp[0].structDef));
}
#line 1582 "y.tab.cpp"
    break;

  case 7:
#line 147 "parser.yacc"
{
  (yyval.programElement) = A_ProgramFnDeclStmt((yyvsp[0].fnDeclStmt)->pos, (yyvsp[0].fnDeclStmt));
}
#line 1590 "y.tab.cpp"
    break;

  case 8:
#line 151 "parser.yacc"
{
  (yyval.programElement) = A_ProgramFnDef((yyvsp[0].fnDef)->pos, (yyvsp[0].fnDef));
}
#line 1598 "y.tab.cpp"
    break;

  case 9:
#line 155 "parser.yacc"
{
  (yyval.programElement) = A_ProgramNullStmt((yyvsp[0].token));
}
#line 1606 "y.tab.cpp"
    break;

  case 10:
#line 161 "parser.yacc"
{
  (yyval.rightVal) = A_ArithExprRVal((yyvsp[0].arithExpr)->pos, (yyvsp[0].arithExpr));
}
#line 1614 "y.tab.cpp"
    break;

  case 11:
#line 165 "parser.yacc"
{
  (yyval.rightVal) = A_BoolExprRVal((yyvsp[0].boolExpr)->pos, (yyvsp[0].boolExpr));
}
#line 1622 "y.tab.cpp"
    break;

  case 12:
#line 171 "parser.yacc"
{
    (yyval.leftVal)=A_IdExprLVal((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 1630 "y.tab.cpp"
    break;

  case 13:
#line 175 "parser.yacc"
{
    (yyval.leftVal)=A_ArrExprLVal((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr));
}
#line 1638 "y.tab.cpp"
    break;

  case 14:
#line 179 "parser.yacc"
{
    (yyval.leftVal)=A_MemberExprLVal((yyvsp[0].memberExpr)->pos, (yyvsp[0].memberExpr));
}
#line 1646 "y.tab.cpp"
    break;

  case 15:
#line 185 "parser.yacc"
{
  (yyval.rightValList)=A_RightValList((yyvsp[-2].rightVal), (yyvsp[0].rightValList));
}
#line 1654 "y.tab.cpp"
    break;

  case 16:
#line 189 "parser.yacc"
{
  (yyval.rightValList)=A_RightValList((yyvsp[0].rightVal), NULL);
}
#line 1662 "y.tab.cpp"
    break;

  case 17:
#line 195 "parser.yacc"
{
  (yyval.fnDeclStmt) = A_FnDeclStmt((yyvsp[-1].fnDecl)->pos, (yyvsp[-1].fnDecl));
}
#line 1670 "y.tab.cpp"
    break;

  case 18:
#line 202 "parser.yacc"
{
  (yyval.fnDecl) = A_FnDecl((yyvsp[-4].key), (yyvsp[-3].tokenId)->id, (yyvsp[-1].paramDecl), NULL);
}
#line 1678 "y.tab.cpp"
    break;

  case 19:
#line 206 "parser.yacc"
{
  (yyval.fnDecl) = A_FnDecl((yyvsp[-6].key), (yyvsp[-5].tokenId)->id, (yyvsp[-3].paramDecl), (yyvsp[0].type));
}
#line 1686 "y.tab.cpp"
    break;

  case 20:
#line 211 "parser.yacc"
{
  (yyval.type) = A_NativeType((yyvsp[0].key), A_intTypeKind);
}
#line 1694 "y.tab.cpp"
    break;

  case 21:
#line 215 "parser.yacc"
{
  (yyval.type) = A_StructType((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 1702 "y.tab.cpp"
    break;

  case 22:
#line 221 "parser.yacc"
{
  (yyval.paramDecl) = A_ParamDecl((yyvsp[0].varDeclList));
}
#line 1710 "y.tab.cpp"
    break;

  case 23:
#line 227 "parser.yacc"
{
  (yyval.varDeclList) = A_VarDeclList((yyvsp[-2].varDecl), (yyvsp[0].varDeclList));
}
#line 1718 "y.tab.cpp"
    break;

  case 24:
#line 231 "parser.yacc"
{
  (yyval.varDeclList) = A_VarDeclList((yyvsp[0].varDecl), NULL);
}
#line 1726 "y.tab.cpp"
    break;

  case 25:
#line 235 "parser.yacc"
{
    (yyval.varDeclList)=NULL;
}
#line 1734 "y.tab.cpp"
    break;

  case 26:
#line 241 "parser.yacc"
{
    (yyval.varDecl)=A_VarDecl_Scalar((yyvsp[0].varDeclScalar)->pos, (yyvsp[0].varDeclScalar));
}
#line 1742 "y.tab.cpp"
    break;

  case 27:
#line 245 "parser.yacc"
{
    (yyval.varDecl)=A_VarDecl_Array((yyvsp[0].varDeclArray)->pos, (yyvsp[0].varDeclArray));
}
#line 1750 "y.tab.cpp"
    break;

  case 28:
#line 251 "parser.yacc"
{
    (yyval.varDeclScalar)=A_VarDeclScalar((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, (yyvsp[0].type));
}
#line 1758 "y.tab.cpp"
    break;

  case 29:
#line 255 "parser.yacc"
{
    (yyval.varDeclScalar)=A_VarDeclScalar((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id, NULL);
}
#line 1766 "y.tab.cpp"
    break;

  case 30:
#line 261 "parser.yacc"
{
    (yyval.varDeclArray)=A_VarDeclArray((yyvsp[-5].tokenId)->pos, (yyvsp[-5].tokenId)->id, (yyvsp[-3].tokenNum)->num, (yyvsp[0].type));
}
#line 1774 "y.tab.cpp"
    break;

  case 31:
#line 265 "parser.yacc"
{
    (yyval.varDeclArray)=A_VarDeclArray((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id, (yyvsp[-1].tokenNum)->num, NULL);
}
#line 1782 "y.tab.cpp"
    break;

  case 32:
#line 271 "parser.yacc"
{
    (yyval.varDef)=A_VarDef_Scalar((yyvsp[0].varDefScalar)->pos, (yyvsp[0].varDefScalar));
}
#line 1790 "y.tab.cpp"
    break;

  case 33:
#line 275 "parser.yacc"
{
    (yyval.varDef)=A_VarDef_Array((yyvsp[0].varDefArray)->pos, (yyvsp[0].varDefArray));
}
#line 1798 "y.tab.cpp"
    break;

  case 34:
#line 279 "parser.yacc"
{
    (yyval.varDef)=NULL;
}
#line 1806 "y.tab.cpp"
    break;

  case 35:
#line 285 "parser.yacc"
{
    (yyval.varDefArray)=A_VarDefArray((yyvsp[-9].tokenId)->pos, (yyvsp[-9].tokenId)->id, (yyvsp[-7].tokenNum)->num, (yyvsp[-4].type), (yyvsp[-1].rightValList));
}
#line 1814 "y.tab.cpp"
    break;

  case 36:
#line 289 "parser.yacc"
{
    (yyval.varDefArray)=A_VarDefArray((yyvsp[-7].tokenId)->pos, (yyvsp[-7].tokenId)->id, (yyvsp[-5].tokenNum)->num, A_NativeType((yyvsp[-7].tokenId)->pos, A_intTypeKind) , (yyvsp[-1].rightValList));
}
#line 1822 "y.tab.cpp"
    break;

  case 37:
#line 295 "parser.yacc"
{
    //printf("vardefscalar\n");
    (yyval.varDefScalar)=A_VarDefScalar((yyvsp[-2].type)->pos, (yyvsp[-4].tokenId)->id, (yyvsp[-2].type), (yyvsp[0].rightVal));
    //printf("eof vardefscalar\n");
}
#line 1832 "y.tab.cpp"
    break;

  case 38:
#line 301 "parser.yacc"
{
    (yyval.varDefScalar)=A_VarDefScalar((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, A_NativeType((yyvsp[-2].tokenId)->pos, A_intTypeKind), (yyvsp[0].rightVal));
}
#line 1840 "y.tab.cpp"
    break;

  case 39:
#line 308 "parser.yacc"
{
  (yyval.fnDef) = A_FnDef((yyvsp[-1].fnDecl)->pos, (yyvsp[-1].fnDecl), (yyvsp[0].codeBlockStmtList));
}
#line 1848 "y.tab.cpp"
    break;

  case 40:
#line 314 "parser.yacc"
{
  (yyval.codeBlockStmtList) = (yyvsp[-1].codeBlockStmtList);
}
#line 1856 "y.tab.cpp"
    break;

  case 41:
#line 319 "parser.yacc"
{
  (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[-1].codeBlockStmt), (yyvsp[0].codeBlockStmtList));
}
#line 1864 "y.tab.cpp"
    break;

  case 42:
#line 323 "parser.yacc"
{
  (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[0].codeBlockStmt), NULL);
}
#line 1872 "y.tab.cpp"
    break;

  case 43:
#line 329 "parser.yacc"
{
    (yyval.codeBlockStmt)=A_BlockNullStmt((yyvsp[0].token));
}
#line 1880 "y.tab.cpp"
    break;

  case 44:
#line 333 "parser.yacc"
{
    (yyval.codeBlockStmt)=A_BlockVarDeclStmt((yyvsp[0].varDeclStmt)->pos, (yyvsp[0].varDeclStmt));
}
#line 1888 "y.tab.cpp"
    break;

  case 45:
#line 337 "parser.yacc"
{
    (yyval.codeBlockStmt)=A_BlockAssignStmt((yyvsp[0].assignStmt)->pos, (yyvsp[0].assignStmt));
}
#line 1896 "y.tab.cpp"
    break;

  case 46:
#line 341 "parser.yacc"
{
    (yyval.codeBlockStmt)=A_BlockCallStmt((yyvsp[0].callStmt)->pos, (yyvsp[0].callStmt));
}
#line 1904 "y.tab.cpp"
    break;

  case 47:
#line 345 "parser.yacc"
{
    (yyval.codeBlockStmt)=A_BlockIfStmt((yyvsp[0].ifStmt)->pos, (yyvsp[0].ifStmt));
}
#line 1912 "y.tab.cpp"
    break;

  case 48:
#line 349 "parser.yacc"
{
    (yyval.codeBlockStmt)=A_BlockWhileStmt((yyvsp[0].whileStmt)->pos, (yyvsp[0].whileStmt));
}
#line 1920 "y.tab.cpp"
    break;

  case 49:
#line 353 "parser.yacc"
{
    (yyval.codeBlockStmt)=A_BlockReturnStmt((yyvsp[0].returnStmt)->pos, (yyvsp[0].returnStmt));
}
#line 1928 "y.tab.cpp"
    break;

  case 50:
#line 357 "parser.yacc"
{
    (yyval.codeBlockStmt)=A_BlockContinueStmt((yyvsp[0].token));
}
#line 1936 "y.tab.cpp"
    break;

  case 51:
#line 361 "parser.yacc"
{
    (yyval.codeBlockStmt)=A_BlockBreakStmt((yyvsp[0].token));
}
#line 1944 "y.tab.cpp"
    break;

  case 52:
#line 365 "parser.yacc"
{
    (yyval.codeBlockStmt)=A_BlockNullStmt(NULL);
}
#line 1952 "y.tab.cpp"
    break;

  case 53:
#line 371 "parser.yacc"
{
    (yyval.returnStmt)=A_ReturnStmt((yyvsp[-2].key), (yyvsp[-1].rightVal));
}
#line 1960 "y.tab.cpp"
    break;

  case 54:
#line 375 "parser.yacc"
{
    (yyval.returnStmt)=A_ReturnStmt((yyvsp[-1].key), NULL);
}
#line 1968 "y.tab.cpp"
    break;

  case 55:
#line 380 "parser.yacc"
{
    // printf("assignstmt\n");
    (yyval.assignStmt)=A_AssignStmt((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), (yyvsp[-1].rightVal));
}
#line 1977 "y.tab.cpp"
    break;

  case 56:
#line 386 "parser.yacc"
{
    (yyval.callStmt)=A_CallStmt((yyvsp[-1].fnCall)->pos, (yyvsp[-1].fnCall));
}
#line 1985 "y.tab.cpp"
    break;

  case 57:
#line 391 "parser.yacc"
{
    (yyval.ifStmt)=A_IfStmt((yyvsp[-10].key), (yyvsp[-8].boolExpr), (yyvsp[-5].codeBlockStmtList), (yyvsp[-1].codeBlockStmtList));
}
#line 1993 "y.tab.cpp"
    break;

  case 58:
#line 395 "parser.yacc"
{
    (yyval.ifStmt)=A_IfStmt((yyvsp[-6].key), (yyvsp[-4].boolExpr), (yyvsp[-1].codeBlockStmtList), NULL);
}
#line 2001 "y.tab.cpp"
    break;

  case 59:
#line 400 "parser.yacc"
{
    (yyval.whileStmt)=A_WhileStmt((yyvsp[-6].key), (yyvsp[-4].boolExpr), (yyvsp[-1].codeBlockStmtList));
}
#line 2009 "y.tab.cpp"
    break;

  case 60:
#line 405 "parser.yacc"
{
  (yyval.varDeclStmt) = A_VarDeclStmt((yyvsp[-2].key), (yyvsp[-1].varDecl));
}
#line 2017 "y.tab.cpp"
    break;

  case 61:
#line 409 "parser.yacc"
{
  (yyval.varDeclStmt) = A_VarDefStmt((yyvsp[-2].key),  (yyvsp[-1].varDef));
}
#line 2025 "y.tab.cpp"
    break;

  case 62:
#line 416 "parser.yacc"
{
  (yyval.boolExpr) = A_BoolBiOp_Expr((yyvsp[0].boolBiOpExpr)->pos, (yyvsp[0].boolBiOpExpr));
}
#line 2033 "y.tab.cpp"
    break;

  case 63:
#line 420 "parser.yacc"
{
  (yyval.boolExpr) = A_BoolExpr((yyvsp[0].boolUnit)->pos, (yyvsp[0].boolUnit));
}
#line 2041 "y.tab.cpp"
    break;

  case 64:
#line 426 "parser.yacc"
{
  (yyval.boolBiOpExpr) = A_BoolBiOpExpr((yyvsp[-2].boolExpr)->pos, A_or, (yyvsp[-2].boolExpr), (yyvsp[0].boolExpr));
}
#line 2049 "y.tab.cpp"
    break;

  case 65:
#line 431 "parser.yacc"
{
  (yyval.boolBiOpExpr) = A_BoolBiOpExpr((yyvsp[-2].boolExpr)->pos, A_and, (yyvsp[-2].boolExpr), (yyvsp[0].boolExpr));
}
#line 2057 "y.tab.cpp"
    break;

  case 66:
#line 437 "parser.yacc"
{
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[0].comExpr)->pos, (yyvsp[0].comExpr));
}
#line 2065 "y.tab.cpp"
    break;

  case 67:
#line 442 "parser.yacc"
{
  (yyval.boolUnit) = A_ComExprUnit((yyvsp[-2].token), (yyvsp[-1].comExpr));
}
#line 2073 "y.tab.cpp"
    break;

  case 68:
#line 446 "parser.yacc"
{
  (yyval.boolUnit) = A_BoolExprUnit((yyvsp[-2].token), (yyvsp[-1].boolExpr));
}
#line 2081 "y.tab.cpp"
    break;

  case 69:
#line 450 "parser.yacc"
{
  (yyval.boolUnit) = A_BoolUOpExprUnit((yyvsp[-1].token), A_BoolUOpExpr((yyvsp[-1].token), A_not, (yyvsp[0].boolUnit)));
}
#line 2089 "y.tab.cpp"
    break;

  case 70:
#line 456 "parser.yacc"
{
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_gt, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 2097 "y.tab.cpp"
    break;

  case 71:
#line 460 "parser.yacc"
{
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_lt, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 2105 "y.tab.cpp"
    break;

  case 72:
#line 464 "parser.yacc"
{
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_ge, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 2113 "y.tab.cpp"
    break;

  case 73:
#line 468 "parser.yacc"
{
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_le, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 2121 "y.tab.cpp"
    break;

  case 74:
#line 472 "parser.yacc"
{
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_eq, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 2129 "y.tab.cpp"
    break;

  case 75:
#line 476 "parser.yacc"
{
  (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_ne, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 2137 "y.tab.cpp"
    break;

  case 76:
#line 481 "parser.yacc"
{
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_add, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 2145 "y.tab.cpp"
    break;

  case 77:
#line 485 "parser.yacc"
{
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_sub, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 2153 "y.tab.cpp"
    break;

  case 78:
#line 489 "parser.yacc"
{
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_mul, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 2161 "y.tab.cpp"
    break;

  case 79:
#line 493 "parser.yacc"
{
  (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_div, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
}
#line 2169 "y.tab.cpp"
    break;

  case 80:
#line 497 "parser.yacc"
{
  (yyval.arithExpr) = A_ExprUnit((yyvsp[0].exprUnit)->pos, (yyvsp[0].exprUnit));
}
#line 2177 "y.tab.cpp"
    break;

  case 81:
#line 503 "parser.yacc"
{
    (yyval.exprUnit)=A_NumExprUnit((yyvsp[0].tokenNum)->pos, (yyvsp[0].tokenNum)->num);
}
#line 2185 "y.tab.cpp"
    break;

  case 82:
#line 507 "parser.yacc"
{
    (yyval.exprUnit)=A_IdExprUnit((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
    // printf("eof exprunit\n");
}
#line 2194 "y.tab.cpp"
    break;

  case 83:
#line 512 "parser.yacc"
{
    (yyval.exprUnit)=A_ArithExprUnit((yyvsp[-1].arithExpr)->pos, (yyvsp[-1].arithExpr));
}
#line 2202 "y.tab.cpp"
    break;

  case 84:
#line 516 "parser.yacc"
{
    (yyval.exprUnit)=A_CallExprUnit((yyvsp[0].fnCall)->pos, (yyvsp[0].fnCall));
}
#line 2210 "y.tab.cpp"
    break;

  case 85:
#line 520 "parser.yacc"
{
    (yyval.exprUnit)=A_ArrayExprUnit((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr));
}
#line 2218 "y.tab.cpp"
    break;

  case 86:
#line 524 "parser.yacc"
{
    (yyval.exprUnit)=A_MemberExprUnit((yyvsp[0].memberExpr)->pos, (yyvsp[0].memberExpr));
}
#line 2226 "y.tab.cpp"
    break;

  case 87:
#line 528 "parser.yacc"
{
    (yyval.exprUnit)=A_ArithUExprUnit((yyvsp[0].arithUExpr)->pos, (yyvsp[0].arithUExpr));
}
#line 2234 "y.tab.cpp"
    break;

  case 88:
#line 534 "parser.yacc"
{
  (yyval.structDef) = A_StructDef((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id, (yyvsp[-1].varDeclList));
}
#line 2242 "y.tab.cpp"
    break;

  case 89:
#line 540 "parser.yacc"
{
  (yyval.fnCall) = A_FnCall((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id,(yyvsp[-1].rightValList));
}
#line 2250 "y.tab.cpp"
    break;

  case 90:
#line 544 "parser.yacc"
{
  (yyval.fnCall) = A_FnCall((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, NULL);
}
#line 2258 "y.tab.cpp"
    break;

  case 91:
#line 550 "parser.yacc"
{
    (yyval.arithUExpr)=A_ArithUExpr((yyvsp[0].exprUnit)->pos, A_neg, (yyvsp[0].exprUnit));
}
#line 2266 "y.tab.cpp"
    break;

  case 92:
#line 556 "parser.yacc"
{
    (yyval.arrayExpr)=A_ArrayExpr((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), (yyvsp[-1].indexExpr));
}
#line 2274 "y.tab.cpp"
    break;

  case 93:
#line 561 "parser.yacc"
{
    (yyval.indexExpr)=A_IdIndexExpr((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 2282 "y.tab.cpp"
    break;

  case 94:
#line 565 "parser.yacc"
{
    (yyval.indexExpr)=A_NumIndexExpr((yyvsp[0].tokenNum)->pos, (yyvsp[0].tokenNum)->num);
}
#line 2290 "y.tab.cpp"
    break;

  case 95:
#line 571 "parser.yacc"
{
    (yyval.memberExpr)=A_MemberExpr((yyvsp[-2].leftVal)->pos, (yyvsp[-2].leftVal), (yyvsp[0].tokenId)->id);
}
#line 2298 "y.tab.cpp"
    break;


#line 2302 "y.tab.cpp"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 576 "parser.yacc"


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


