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
    TOKEN_ID = 275,
    TOKEN_NUM = 276,
    CONTINUE = 277,
    BREAK = 278,
    IF = 279,
    ELSE = 280,
    WHILE = 281,
    INT = 282,
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
#define OP_ARROW 270
#define LET 271
#define RET 272
#define FN 273
#define STRUCT 274
#define TOKEN_ID 275
#define TOKEN_NUM 276
#define CONTINUE 277
#define BREAK 278
#define IF 279
#define ELSE 280
#define WHILE 281
#define INT 282
#define UMINUS 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "parser.yacc"


    A_pos token;
    A_pos key;
    A_pos id;
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

#line 249 "y.tab.cpp"

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
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   149

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  172

#define YYUNDEFTOK  2
#define YYMAXUTOK   283


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
       2,     2,     2,     2,     2,     2,     2,     2,    40,    19,
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
      36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   147,   147,   153,   157,   162,   168,   172,   176,   180,
     187,   191,   198,   206,   213,   218,   225,   230,   236,   241,
     247,   253,   257,   261,   267,   273,   277,   281,   285,   291,
     295,   299,   303,   307,   311,   315,   320,   326,   331,   335,
     340,   346,   351,   357,   361,   366,   371,   375,   380,   385,
     390,   396,   400,   405,   410,   414,   419,   423,   427,   432,
     437,   441,   445,   449,   453,   457,   462,   467,   472,   477,
     481,   486,   491,   496,   500,   506,   510,   516,   520,   524,
     528,   532,   536,   540,   545,   550,   556,   561,   565,   570,
     575,   579,   584
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
  "TOKEN_ID", "TOKEN_NUM", "CONTINUE", "BREAK", "IF", "ELSE", "WHILE",
  "INT", "UMINUS", "':'", "$accept", "PROGRAM", "PROGRAMELEMENTLIST",
  "PROGRAMELEMENT", "VARDECLSTMT", "VARDECL", "VARDECLSCALAR",
  "VARDECLARRAY", "VARDEF", "VARDEFSCALAR", "RIGHTVAL", "ARITHEXPR",
  "ARITHBIOPEXPR", "AIRTHBIOP", "EXPRUNIT", "ARITHUEXPR", "ARRAYEXPR",
  "INDEXEXPR", "MEMBEREXPR", "ARITHUOP", "FN_CALL", "RIGHTVALLIST",
  "STRUCTDEF", "VARDECLLIST", "VARDEFARRAY", "TYPE", "BOOLEXPR",
  "BOOLBIOPEXPR", "BOOLBIOP", "BOOLUNIT", "COMPEXPR", "COMOP",
  "BOOLUOPEXPR", "BOOLUOP", "FNDECLSTMT", "FNDECL", "PARAMDECL", "FNDEF",
  "CODEBLOCKSTMTLIST", "CODEBLOCKSTMT", "RETURNSTMT", "ASSIGNSTMT",
  "LEFTVAL", "CALLSTMT", "IFSTMT", "WHILESTMT", YY_NULLPTR
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
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
      58
};
# endif

#define YYPACT_NINF (-129)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,    14,   -11,    -3,    17,    34,  -129,    14,    14,    14,
      14,     3,    14,  -129,   -14,    39,  -129,  -129,    45,  -129,
    -129,    55,    56,  -129,  -129,  -129,  -129,  -129,  -129,    40,
    -129,    58,  -129,    61,    23,  -129,  -129,    66,    66,    80,
       4,    57,    83,    85,    88,    90,    86,  -129,  -129,    87,
      89,    91,    92,    93,    94,    95,  -129,    96,  -129,  -129,
     100,   -10,   101,  -129,    97,   102,  -129,  -129,     6,  -129,
      57,  -129,    99,    84,  -129,    74,  -129,  -129,  -129,     6,
    -129,    43,  -129,  -129,  -129,  -129,     4,     4,    77,    68,
     105,   106,     4,     4,  -129,  -129,  -129,  -129,     4,  -129,
    -129,  -129,    71,     4,    98,    23,    66,   103,  -129,    11,
    -129,  -129,  -129,  -129,  -129,  -129,     6,  -129,  -129,  -129,
    -129,  -129,  -129,     6,  -129,  -129,  -129,     4,    74,    43,
    -129,   104,   112,  -129,  -129,  -129,   107,  -129,  -129,    78,
      82,   113,    23,  -129,   109,  -129,  -129,    23,  -129,    84,
    -129,  -129,     4,  -129,  -129,    58,    58,  -129,   117,    81,
    -129,  -129,   108,  -129,   116,    23,    58,     4,  -129,  -129,
     118,  -129
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      10,    10,     0,     0,     0,     0,     2,     4,    10,    10,
      10,     0,    10,     9,     0,     0,    13,    14,     0,    17,
      18,     0,     0,     1,     3,     5,     6,     7,    68,     0,
      72,    74,     8,     0,     0,    11,    12,     0,     0,     0,
       0,    86,     0,     0,     0,     0,     0,    87,    88,     0,
       0,     0,     0,     0,     0,     0,    73,     0,    49,    50,
      15,     0,    47,    71,     0,     0,    75,    41,     0,    67,
      30,    29,     0,    20,    22,    23,    35,    33,    34,     0,
      32,    21,    51,    52,    56,    58,     0,     0,     0,     0,
       0,     0,     0,     0,    76,    89,    81,    77,     0,    78,
      79,    80,     0,     0,     0,     0,     0,    69,    45,     0,
      23,    84,    25,    26,    27,    28,     0,    63,    62,    64,
      65,    60,    61,     0,    36,    55,    54,     0,     0,    57,
      52,    44,     0,    40,    38,    39,     0,    82,    83,     0,
       0,     0,     0,    19,     0,    15,    46,     0,    31,    24,
      59,    52,     0,    42,    37,     0,     0,    85,    16,     0,
      70,    43,    91,    92,     0,     0,     0,     0,    16,    90,
       0,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,   130,    41,   111,   136,  -129,  -129,  -129,  -129,
     -38,   -64,  -129,  -129,   -61,  -129,   114,  -129,   119,  -129,
     120,  -128,  -129,   -37,  -129,  -102,   -81,  -129,  -129,   -80,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,   -31,  -129,
    -129,  -129,  -129,  -129,  -129,  -129
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    62,    16,    17,    18,    19,
     131,    73,    74,   116,    75,    76,    77,   136,    78,    79,
      80,   132,     9,    63,    20,    60,    81,    82,   127,    83,
      84,   123,    85,    86,    10,    11,    64,    12,    30,    31,
      50,    51,    52,    53,    54,    55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      56,    65,    72,   145,   109,   129,   130,   110,    67,    33,
      67,   139,   140,   104,   112,   113,   114,   115,   124,    68,
      14,    68,    28,    29,   161,   128,    34,   148,    21,    69,
     105,   128,   128,     1,    23,    70,    71,    70,    71,   170,
     158,     2,    13,     3,     4,   160,   129,   151,    22,    25,
      26,    27,   149,    32,    58,   110,   125,   126,    35,    39,
     141,    59,   150,   168,    36,   143,   128,     2,    40,   146,
      37,    41,    87,    42,    43,    44,    38,    45,    29,    88,
      89,   117,   118,   119,   120,   121,   122,   112,   113,   114,
     115,   125,   126,    57,   155,   125,   126,    61,   156,   134,
     135,    66,    90,    92,    91,    93,    95,    94,   133,    98,
      96,   142,    97,   107,    99,   100,   101,   103,   111,   106,
     102,   165,   152,   108,   162,   163,   137,   138,   153,   147,
     144,   154,   157,   159,   164,   169,   167,    24,    15,   171,
      46,     0,     0,    47,   166,     0,     0,     0,    48,    49
};

static const yytype_int16 yycheck[] =
{
      31,    38,    40,   105,    68,    86,    86,    68,     4,    23,
       4,    92,    93,    23,     3,     4,     5,     6,    79,    15,
      31,    15,    19,    20,   152,    86,    40,    16,    31,    25,
      40,    92,    93,    19,     0,    31,    32,    31,    32,   167,
     142,    27,     1,    29,    30,   147,   127,   127,    31,     8,
       9,    10,   116,    12,    31,   116,    13,    14,    19,    19,
      98,    38,   123,   165,    19,   103,   127,    27,    28,   106,
      15,    31,    15,    33,    34,    35,    20,    37,    20,    22,
      23,     7,     8,     9,    10,    11,    12,     3,     4,     5,
       6,    13,    14,    32,    16,    13,    14,    31,    16,    31,
      32,    21,    19,    15,    19,    15,    19,    21,    31,    17,
      21,    40,    21,    16,    21,    21,    21,    17,    19,    18,
      24,    40,    18,    21,   155,   156,    21,    21,    16,    26,
      32,    24,    19,    24,    17,   166,    20,     7,     2,    21,
      29,    -1,    -1,    29,    36,    -1,    -1,    -1,    29,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    27,    29,    30,    42,    43,    44,    45,    63,
      75,    76,    78,    44,    31,    46,    47,    48,    49,    50,
      65,    31,    31,     0,    43,    44,    44,    44,    19,    20,
      79,    80,    44,    23,    40,    19,    19,    15,    20,    19,
      28,    31,    33,    34,    35,    37,    45,    57,    59,    61,
      81,    82,    83,    84,    85,    86,    79,    32,    31,    38,
      66,    31,    46,    64,    77,    64,    21,     4,    15,    25,
      31,    32,    51,    52,    53,    55,    56,    57,    59,    60,
      61,    67,    68,    70,    71,    73,    74,    15,    22,    23,
      19,    19,    15,    15,    21,    19,    21,    21,    17,    21,
      21,    21,    24,    17,    23,    40,    18,    16,    21,    52,
      55,    19,     3,     4,     5,     6,    54,     7,     8,     9,
      10,    11,    12,    72,    55,    13,    14,    69,    55,    67,
      70,    51,    62,    31,    31,    32,    58,    21,    21,    67,
      67,    51,    40,    51,    32,    66,    64,    26,    16,    52,
      55,    70,    18,    16,    24,    16,    16,    19,    66,    24,
      66,    62,    79,    79,    17,    40,    36,    20,    66,    79,
      62,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      44,    45,    45,    46,    46,    47,    48,    49,    49,    50,
      51,    51,    52,    52,    53,    54,    54,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    56,    57,    58,    58,
      59,    60,    61,    62,    62,    63,    64,    64,    65,    66,
      66,    67,    67,    68,    69,    69,    70,    70,    70,    71,
      72,    72,    72,    72,    72,    72,    73,    74,    75,    76,
      76,    77,    78,    79,    79,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    81,    82,    83,    83,    83,    84,
      85,    85,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     2,     2,     2,
       0,     3,     3,     1,     1,     3,     6,     1,     1,     5,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     2,     4,     1,     1,
       3,     1,     4,     3,     1,     5,     3,     1,    10,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     5,
       7,     1,     2,     2,     1,     3,     3,     3,     3,     3,
       3,     3,     4,     4,     3,     4,     1,     1,     1,     2,
       7,     5,     5
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
  printf("##1 yyn %d %d %d %d \n", yyn, YYLAST,yycheck[yyn], yytoken);
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  printf("#2 yyn %d\n", yyn);
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      printf("#21 yyn %d\n", yyn);
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      printf("#22 yyn %d\n", yyn);
      yyn = -yyn;
      goto yyreduce;
      printf("#23 yyn %d\n", yyn);
    }
  printf("#3 yyn %d\n", yyn);
  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  printf("befor shift\n");
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
  printf("# yydefault\n");
  yyn = yydefact[yystate];
  printf("# yydefault yyn %d %d\n", yyn, yystate);
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
#line 148 "parser.yacc"
    {
        root=A_program((yyvsp[0].programElementList));
        (yyval.program)=root;
    }
#line 1548 "y.tab.cpp"
    break;

  case 3:
#line 154 "parser.yacc"
    {
        (yyval.programElementList)=A_ProgramElementList((yyvsp[-1].programElement),(yyvsp[0].programElementList));
    }
#line 1556 "y.tab.cpp"
    break;

  case 4:
#line 158 "parser.yacc"
    {
        (yyval.programElementList)=A_ProgramElementList((yyvsp[0].programElement),NULL);
    }
#line 1564 "y.tab.cpp"
    break;

  case 5:
#line 163 "parser.yacc"
    {
      printf("programelement 1\n");
        (yyval.programElement)=A_ProgramVarDeclStmt((yyvsp[-1].varDeclStmt)->pos, (yyvsp[-1].varDeclStmt));
      printf("eof programelement 1\n");
    }
#line 1574 "y.tab.cpp"
    break;

  case 6:
#line 169 "parser.yacc"
    {
        (yyval.programElement)=A_ProgramStructDef((yyvsp[-1].structDef)->pos, (yyvsp[-1].structDef));
    }
#line 1582 "y.tab.cpp"
    break;

  case 7:
#line 173 "parser.yacc"
    {
        (yyval.programElement)=A_ProgramFnDeclStmt((yyvsp[-1].fnDeclStmt)->pos, (yyvsp[-1].fnDeclStmt));
    }
#line 1590 "y.tab.cpp"
    break;

  case 8:
#line 177 "parser.yacc"
    {
        (yyval.programElement)=A_ProgramFnDef((yyvsp[-1].fnDef)->pos, (yyvsp[-1].fnDef));
    }
#line 1598 "y.tab.cpp"
    break;

  case 9:
#line 181 "parser.yacc"
    {
      printf("programelement 5\n");
        (yyval.programElement)=A_ProgramNullStmt((yyvsp[0].programElement)->pos);
      printf("eof programelement 5\n");
    }
#line 1608 "y.tab.cpp"
    break;

  case 10:
#line 187 "parser.yacc"
    {
        (yyval.programElement)=NULL;
    }
#line 1616 "y.tab.cpp"
    break;

  case 11:
#line 192 "parser.yacc"
    {   
        printf("vardeclstmt 1\n");
        printf("pos %d\n", (yyvsp[-1].varDecl)->pos->line);
        (yyval.varDeclStmt)=A_VarDeclStmt((yyvsp[-2].key), (yyvsp[-1].varDecl));
        printf("eof vardeclstmt 1\n");
    }
#line 1627 "y.tab.cpp"
    break;

  case 12:
#line 199 "parser.yacc"
    {
        printf("vardeclstmt 2\n");
        printf("pos %d\n", (yyvsp[-1].varDef)->pos->line);
        (yyval.varDeclStmt)=A_VarDefStmt((yyvsp[-1].varDef)->pos, (yyvsp[-1].varDef));
        printf("eof vardeclstmt 2\n");
    }
#line 1638 "y.tab.cpp"
    break;

  case 13:
#line 207 "parser.yacc"
    {
        printf("vardecl\n");
        printf("pos %d\n", (yyvsp[0].varDeclScalar)->pos->line);
        (yyval.varDecl)=A_VarDecl_Scalar((yyvsp[0].varDeclScalar)->pos, (yyvsp[0].varDeclScalar));
        printf("eof vardecl\n");
    }
#line 1649 "y.tab.cpp"
    break;

  case 14:
#line 214 "parser.yacc"
    {
        (yyval.varDecl)=A_VarDecl_Array((yyvsp[0].varDeclArray)->pos, (yyvsp[0].varDeclArray));
    }
#line 1657 "y.tab.cpp"
    break;

  case 15:
#line 219 "parser.yacc"
    {
      printf("vardeclscalar\n");
        (yyval.varDeclScalar)=A_VarDeclScalar((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, (yyvsp[0].type));
      printf("eof vardeclscalar\n");
    }
#line 1667 "y.tab.cpp"
    break;

  case 16:
#line 226 "parser.yacc"
    {
        (yyval.varDeclArray)=A_VarDeclArray((yyvsp[-5].tokenId)->pos, (yyvsp[-5].tokenId)->id, (yyvsp[-3].tokenNum)->num, (yyvsp[0].type));
    }
#line 1675 "y.tab.cpp"
    break;

  case 17:
#line 231 "parser.yacc"
    {
        printf("vardef\n");
        (yyval.varDef)=A_VarDef_Scalar((yyvsp[0].varDefScalar)->pos, (yyvsp[0].varDefScalar));
        printf("eof vardef\n");
    }
#line 1685 "y.tab.cpp"
    break;

  case 18:
#line 237 "parser.yacc"
    {
        (yyval.varDef)=A_VarDef_Array((yyvsp[0].varDefArray)->pos, (yyvsp[0].varDefArray));
    }
#line 1693 "y.tab.cpp"
    break;

  case 19:
#line 242 "parser.yacc"
    {
        printf("vardefscalar\n");
        (yyval.varDefScalar)=A_VarDefScalar((yyvsp[-2].type)->pos, (yyvsp[-4].tokenId)->id, (yyvsp[-2].type), (yyvsp[0].rightVal));
        printf("eof vardefscalar\n");
    }
#line 1703 "y.tab.cpp"
    break;

  case 20:
#line 248 "parser.yacc"
    {
        printf("rightval\n");
        (yyval.rightVal)=A_ArithExprRVal((yyvsp[0].arithExpr)->pos, (yyvsp[0].arithExpr));
        printf("eof rightval\n");
    }
#line 1713 "y.tab.cpp"
    break;

  case 21:
#line 254 "parser.yacc"
    {
        (yyval.rightVal)=A_BoolExprRVal((yyvsp[0].boolExpr)->pos, (yyvsp[0].boolExpr));
    }
#line 1721 "y.tab.cpp"
    break;

  case 22:
#line 258 "parser.yacc"
    {
        (yyval.arithExpr)=A_ArithBiOp_Expr((yyvsp[0].arithBiOpExpr)->pos, (yyvsp[0].arithBiOpExpr));
    }
#line 1729 "y.tab.cpp"
    break;

  case 23:
#line 262 "parser.yacc"
    {
        (yyval.arithExpr)=A_ExprUnit((yyvsp[0].exprUnit)->pos, (yyvsp[0].exprUnit));
    }
#line 1737 "y.tab.cpp"
    break;

  case 24:
#line 268 "parser.yacc"
    {
        (yyval.arithBiOpExpr)=A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, (yyvsp[-1].arithBiOp), (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr));
    }
#line 1745 "y.tab.cpp"
    break;

  case 25:
#line 274 "parser.yacc"
    {
        (yyval.arithBiOp)= A_add;
    }
#line 1753 "y.tab.cpp"
    break;

  case 26:
#line 278 "parser.yacc"
    {
        (yyval.arithBiOp)= A_sub;
    }
#line 1761 "y.tab.cpp"
    break;

  case 27:
#line 282 "parser.yacc"
    {
        (yyval.arithBiOp)= A_mul;
    }
#line 1769 "y.tab.cpp"
    break;

  case 28:
#line 286 "parser.yacc"
    {
        (yyval.arithBiOp)= A_div;
    }
#line 1777 "y.tab.cpp"
    break;

  case 29:
#line 292 "parser.yacc"
    {
        (yyval.exprUnit)=A_NumExprUnit((yyvsp[0].tokenNum)->pos, (yyvsp[0].tokenNum)->num);
    }
#line 1785 "y.tab.cpp"
    break;

  case 30:
#line 296 "parser.yacc"
    {
        (yyval.exprUnit)=A_IdExprUnit((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
    }
#line 1793 "y.tab.cpp"
    break;

  case 31:
#line 300 "parser.yacc"
    {
        (yyval.exprUnit)=A_ArithExprUnit((yyvsp[-1].arithExpr)->pos, (yyvsp[-1].arithExpr));
    }
#line 1801 "y.tab.cpp"
    break;

  case 32:
#line 304 "parser.yacc"
    {
        (yyval.exprUnit)=A_CallExprUnit((yyvsp[0].fnCall)->pos, (yyvsp[0].fnCall));
    }
#line 1809 "y.tab.cpp"
    break;

  case 33:
#line 308 "parser.yacc"
    {
        (yyval.exprUnit)=A_ArrayExprUnit((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr));
    }
#line 1817 "y.tab.cpp"
    break;

  case 34:
#line 312 "parser.yacc"
    {
        (yyval.exprUnit)=A_MemberExprUnit((yyvsp[0].memberExpr)->pos, (yyvsp[0].memberExpr));
    }
#line 1825 "y.tab.cpp"
    break;

  case 35:
#line 316 "parser.yacc"
    {
        (yyval.exprUnit)=A_ArithUExprUnit((yyvsp[0].arithUExpr)->pos, (yyvsp[0].arithUExpr));
    }
#line 1833 "y.tab.cpp"
    break;

  case 36:
#line 321 "parser.yacc"
    {
        (yyval.arithUExpr)=A_ArithUExpr((yyvsp[0].exprUnit)->pos, (yyvsp[-1].arithUOp), (yyvsp[0].exprUnit));
    }
#line 1841 "y.tab.cpp"
    break;

  case 37:
#line 327 "parser.yacc"
    {
        (yyval.arrayExpr)=A_ArrayExpr((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id, (yyvsp[-1].indexExpr));
    }
#line 1849 "y.tab.cpp"
    break;

  case 38:
#line 332 "parser.yacc"
    {
        (yyval.indexExpr)=A_IdIndexExpr((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
    }
#line 1857 "y.tab.cpp"
    break;

  case 39:
#line 336 "parser.yacc"
    {
        (yyval.indexExpr)=A_NumIndexExpr((yyvsp[0].tokenNum)->pos, (yyvsp[0].tokenNum)->num);
    }
#line 1865 "y.tab.cpp"
    break;

  case 40:
#line 341 "parser.yacc"
    {
        (yyval.memberExpr)=A_MemberExpr((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, (yyvsp[0].tokenId)->id);
    }
#line 1873 "y.tab.cpp"
    break;

  case 41:
#line 347 "parser.yacc"
    {
        (yyval.arithUOp)=A_neg;
    }
#line 1881 "y.tab.cpp"
    break;

  case 42:
#line 352 "parser.yacc"
    {
        (yyval.fnCall)=A_FnCall((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id, (yyvsp[-1].rightValList));
    }
#line 1889 "y.tab.cpp"
    break;

  case 43:
#line 358 "parser.yacc"
    {
        (yyval.rightValList)=A_RightValList((yyvsp[-2].rightVal), (yyvsp[0].rightValList));
    }
#line 1897 "y.tab.cpp"
    break;

  case 44:
#line 362 "parser.yacc"
    {
        (yyval.rightValList)=A_RightValList((yyvsp[0].rightVal), NULL);
    }
#line 1905 "y.tab.cpp"
    break;

  case 45:
#line 367 "parser.yacc"
    {
        (yyval.structDef)=A_StructDef((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id, (yyvsp[-1].varDeclList));
    }
#line 1913 "y.tab.cpp"
    break;

  case 46:
#line 372 "parser.yacc"
    {
        (yyval.varDeclList)=A_VarDeclList((yyvsp[-2].varDecl), (yyvsp[0].varDeclList));
    }
#line 1921 "y.tab.cpp"
    break;

  case 47:
#line 376 "parser.yacc"
    {
        (yyval.varDeclList)=A_VarDeclList((yyvsp[0].varDecl), NULL);
    }
#line 1929 "y.tab.cpp"
    break;

  case 48:
#line 381 "parser.yacc"
    {
        (yyval.varDefArray)=A_VarDefArray((yyvsp[-9].tokenId)->pos, (yyvsp[-9].tokenId)->id, (yyvsp[-7].tokenNum)->num, (yyvsp[-4].type), (yyvsp[-1].rightValList));
    }
#line 1937 "y.tab.cpp"
    break;

  case 49:
#line 386 "parser.yacc"
    {
        printf("type %s\n", (yyvsp[0].tokenId)->id);
        (yyval.type)=A_StructType((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
    }
#line 1946 "y.tab.cpp"
    break;

  case 50:
#line 391 "parser.yacc"
    {
        printf("type int\n");
        (yyval.type)=A_NativeType((yyvsp[0].key), A_intTypeKind);
    }
#line 1955 "y.tab.cpp"
    break;

  case 51:
#line 397 "parser.yacc"
    {
        (yyval.boolExpr)=A_BoolBiOp_Expr((yyvsp[0].boolBiOpExpr)->pos, (yyvsp[0].boolBiOpExpr));
    }
#line 1963 "y.tab.cpp"
    break;

  case 52:
#line 401 "parser.yacc"
    {
        (yyval.boolExpr)=A_BoolExpr((yyvsp[0].boolUnit)->pos, (yyvsp[0].boolUnit));
    }
#line 1971 "y.tab.cpp"
    break;

  case 53:
#line 406 "parser.yacc"
    {
        (yyval.boolBiOpExpr)=A_BoolBiOpExpr((yyvsp[-2].boolExpr)->pos, (yyvsp[-1].boolBiOp), (yyvsp[-2].boolExpr), (yyvsp[0].boolUnit));
    }
#line 1979 "y.tab.cpp"
    break;

  case 54:
#line 411 "parser.yacc"
    {
        (yyval.boolBiOp)=A_and;
    }
#line 1987 "y.tab.cpp"
    break;

  case 55:
#line 415 "parser.yacc"
    {
        (yyval.boolBiOp)=A_or;
    }
#line 1995 "y.tab.cpp"
    break;

  case 56:
#line 420 "parser.yacc"
    {
        (yyval.boolUnit)=A_ComExprUnit((yyvsp[0].comExpr)->pos, (yyvsp[0].comExpr));
    }
#line 2003 "y.tab.cpp"
    break;

  case 57:
#line 424 "parser.yacc"
    {
        (yyval.boolUnit)=A_BoolExprUnit((yyvsp[0].boolExpr)->pos, (yyvsp[0].boolExpr));
    }
#line 2011 "y.tab.cpp"
    break;

  case 58:
#line 428 "parser.yacc"
    {
        (yyval.boolUnit)=A_BoolUOpExprUnit((yyvsp[0].boolUOpExpr)->pos, (yyvsp[0].boolUOpExpr));
    }
#line 2019 "y.tab.cpp"
    break;

  case 59:
#line 433 "parser.yacc"
    {
        (yyval.comExpr)=A_ComExpr((yyvsp[-2].exprUnit)->pos, (yyvsp[-1].comOp), (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
    }
#line 2027 "y.tab.cpp"
    break;

  case 60:
#line 438 "parser.yacc"
    {
        (yyval.comOp)=A_eq;
    }
#line 2035 "y.tab.cpp"
    break;

  case 61:
#line 442 "parser.yacc"
    {
        (yyval.comOp)=A_ne;
    }
#line 2043 "y.tab.cpp"
    break;

  case 62:
#line 446 "parser.yacc"
    {
        (yyval.comOp)=A_le;
    }
#line 2051 "y.tab.cpp"
    break;

  case 63:
#line 450 "parser.yacc"
    {
        (yyval.comOp)=A_lt;
    }
#line 2059 "y.tab.cpp"
    break;

  case 64:
#line 454 "parser.yacc"
    {
        (yyval.comOp)=A_gt;
    }
#line 2067 "y.tab.cpp"
    break;

  case 65:
#line 458 "parser.yacc"
    {
        (yyval.comOp)=A_ge;
    }
#line 2075 "y.tab.cpp"
    break;

  case 66:
#line 463 "parser.yacc"
    {
        (yyval.boolUOpExpr)=A_BoolUOpExpr((yyvsp[0].boolUnit)->pos, (yyvsp[-1].boolUOp), (yyvsp[0].boolUnit));
    }
#line 2083 "y.tab.cpp"
    break;

  case 67:
#line 468 "parser.yacc"
    {
        (yyval.boolUOp)=A_not;
    }
#line 2091 "y.tab.cpp"
    break;

  case 68:
#line 473 "parser.yacc"
    {
        (yyval.fnDeclStmt)=A_FnDeclStmt((yyvsp[-1].fnDecl)->pos, (yyvsp[-1].fnDecl));
    }
#line 2099 "y.tab.cpp"
    break;

  case 69:
#line 478 "parser.yacc"
    {
        (yyval.fnDecl)=A_FnDecl((yyvsp[-4].key), (yyvsp[-3].tokenId)->id, (yyvsp[-1].paramDecl), NULL);
    }
#line 2107 "y.tab.cpp"
    break;

  case 70:
#line 482 "parser.yacc"
    {
        (yyval.fnDecl)=A_FnDecl((yyvsp[-6].key), (yyvsp[-5].tokenId)->id, (yyvsp[-3].paramDecl), (yyvsp[0].type));
    }
#line 2115 "y.tab.cpp"
    break;

  case 71:
#line 487 "parser.yacc"
    {
        (yyval.paramDecl)=A_ParamDecl((yyvsp[0].varDeclList));
    }
#line 2123 "y.tab.cpp"
    break;

  case 72:
#line 492 "parser.yacc"
    {
        (yyval.fnDef)=A_FnDef((yyvsp[-1].fnDecl)->pos, (yyvsp[-1].fnDecl), (yyvsp[0].codeBlockStmtList));
    }
#line 2131 "y.tab.cpp"
    break;

  case 73:
#line 497 "parser.yacc"
    {
        (yyval.codeBlockStmtList)=A_CodeBlockStmtList((yyvsp[-1].codeBlockStmt), (yyvsp[0].codeBlockStmtList));
    }
#line 2139 "y.tab.cpp"
    break;

  case 74:
#line 501 "parser.yacc"
    {
        (yyval.codeBlockStmtList)=A_CodeBlockStmtList((yyvsp[0].codeBlockStmt), NULL);
    }
#line 2147 "y.tab.cpp"
    break;

  case 75:
#line 507 "parser.yacc"
    {
        (yyval.codeBlockStmt)=A_BlockNullStmt((yyvsp[-2].token));
    }
#line 2155 "y.tab.cpp"
    break;

  case 76:
#line 511 "parser.yacc"
    {
      printf("codeblockstmt\n");
        (yyval.codeBlockStmt)=A_BlockVarDeclStmt((yyvsp[-1].varDeclStmt)->pos, (yyvsp[-1].varDeclStmt));
      printf("eof codeblockstmt\n");
    }
#line 2165 "y.tab.cpp"
    break;

  case 77:
#line 517 "parser.yacc"
    {
        (yyval.codeBlockStmt)=A_BlockAssignStmt((yyvsp[-1].assignStmt)->pos, (yyvsp[-1].assignStmt));
    }
#line 2173 "y.tab.cpp"
    break;

  case 78:
#line 521 "parser.yacc"
    {
        (yyval.codeBlockStmt)=A_BlockCallStmt((yyvsp[-1].callStmt)->pos, (yyvsp[-1].callStmt));
    }
#line 2181 "y.tab.cpp"
    break;

  case 79:
#line 525 "parser.yacc"
    {
        (yyval.codeBlockStmt)=A_BlockIfStmt((yyvsp[-1].ifStmt)->pos, (yyvsp[-1].ifStmt));
    }
#line 2189 "y.tab.cpp"
    break;

  case 80:
#line 529 "parser.yacc"
    {
        (yyval.codeBlockStmt)=A_BlockWhileStmt((yyvsp[-1].whileStmt)->pos, (yyvsp[-1].whileStmt));
    }
#line 2197 "y.tab.cpp"
    break;

  case 81:
#line 533 "parser.yacc"
    {
        (yyval.codeBlockStmt)=A_BlockReturnStmt((yyvsp[-1].returnStmt)->pos, (yyvsp[-1].returnStmt));
    }
#line 2205 "y.tab.cpp"
    break;

  case 82:
#line 537 "parser.yacc"
    {
        (yyval.codeBlockStmt)=A_BlockContinueStmt((yyvsp[-2].key));
    }
#line 2213 "y.tab.cpp"
    break;

  case 83:
#line 541 "parser.yacc"
    {
        (yyval.codeBlockStmt)=A_BlockBreakStmt((yyvsp[-2].key));
    }
#line 2221 "y.tab.cpp"
    break;

  case 84:
#line 546 "parser.yacc"
    {
        (yyval.returnStmt)=A_ReturnStmt((yyvsp[-2].key), (yyvsp[-1].rightVal));
    }
#line 2229 "y.tab.cpp"
    break;

  case 85:
#line 551 "parser.yacc"
    {
      printf("assignstmt\n");
        (yyval.assignStmt)=A_AssignStmt((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), (yyvsp[-1].rightVal));
    }
#line 2238 "y.tab.cpp"
    break;

  case 86:
#line 557 "parser.yacc"
    {
        printf("tokenid\n");
        (yyval.leftVal)=A_IdExprLVal((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
    }
#line 2247 "y.tab.cpp"
    break;

  case 87:
#line 562 "parser.yacc"
    {
        (yyval.leftVal)=A_ArrExprLVal((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr));
    }
#line 2255 "y.tab.cpp"
    break;

  case 88:
#line 566 "parser.yacc"
    {
        (yyval.leftVal)=A_MemberExprLVal((yyvsp[0].memberExpr)->pos, (yyvsp[0].memberExpr));
    }
#line 2263 "y.tab.cpp"
    break;

  case 89:
#line 571 "parser.yacc"
    {
        (yyval.callStmt)=A_CallStmt((yyvsp[-1].fnCall)->pos, (yyvsp[-1].fnCall));
    }
#line 2271 "y.tab.cpp"
    break;

  case 90:
#line 576 "parser.yacc"
    {
        (yyval.ifStmt)=A_IfStmt((yyvsp[-6].key), (yyvsp[-4].boolExpr), (yyvsp[-2].codeBlockStmtList), (yyvsp[0].codeBlockStmtList));
    }
#line 2279 "y.tab.cpp"
    break;

  case 91:
#line 580 "parser.yacc"
    {
        (yyval.ifStmt)=A_IfStmt((yyvsp[-4].key), (yyvsp[-2].boolExpr), (yyvsp[0].codeBlockStmtList), NULL);
    }
#line 2287 "y.tab.cpp"
    break;

  case 92:
#line 585 "parser.yacc"
    {
        (yyval.whileStmt)=A_WhileStmt((yyvsp[-4].key), (yyvsp[-2].boolExpr), (yyvsp[0].codeBlockStmtList));
    }
#line 2295 "y.tab.cpp"
    break;


#line 2299 "y.tab.cpp"

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
  printf("# yyerrlab\n");
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      printf("# yyerrstatus\n");
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
  printf("yyerrorlab1\n");
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
#line 588 "parser.yacc"
 


extern "C"{
void yyerror(char * s)
{
  fprintf(stderr, "%s\n",s);
}
int yywrap()
{
  printf("yywrap\n");
  return(1);
}
}


