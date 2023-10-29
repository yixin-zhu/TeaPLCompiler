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
    PUTINT = 270,
    PUTCH = 271,
    PUTARRAY = 272,
    GETINT = 273,
    GETCH = 274,
    GETARRAY = 275,
    MAIN = 276,
    INT = 277,
    PUBLIC = 278,
    CLASS = 279,
    IF = 280,
    ELSE = 281,
    WHILE = 282,
    CONTINUE = 283,
    BREAK = 284,
    RETURN = 285,
    STARTTIME = 286,
    STOPTIME = 287,
    TTRUE = 288,
    FFALSE = 289,
    LENGTH = 290,
    THIS = 291,
    NEW = 292,
    EXTENDS = 293,
    ID = 294,
    NUM = 295,
    UMINUS = 296
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
#define PUTINT 270
#define PUTCH 271
#define PUTARRAY 272
#define GETINT 273
#define GETCH 274
#define GETARRAY 275
#define MAIN 276
#define INT 277
#define PUBLIC 278
#define CLASS 279
#define IF 280
#define ELSE 281
#define WHILE 282
#define CONTINUE 283
#define BREAK 284
#define RETURN 285
#define STARTTIME 286
#define STOPTIME 287
#define TTRUE 288
#define FFALSE 289
#define LENGTH 290
#define THIS 291
#define NEW 292
#define EXTENDS 293
#define ID 294
#define NUM 295
#define UMINUS 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "parser.yacc"

    A_pos token; // 例：符号
    A_pos key; // 关键字
    A_type type;
    A_program program;
    A_mainMethod mainMethod;
    A_classDecl classDecl;
    A_classDeclList classDeclList;
    A_methodDecl methodDecl;
    A_methodDeclList methodDeclList;
    A_formal formal;
    A_formalList formalList;
    A_varDecl varDecl;
    A_varDeclList varDeclList;
    A_stmList stmList;
    A_stm stm;
    A_exp exp;
    A_expList expList;

#line 239 "y.tab.cpp"

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   708

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  228

#define YYUNDEFTOK  2
#define YYMAXUTOK   296


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
       2,     2,     2,    23,     2,     2,     2,     2,     2,     2,
      15,    16,     2,     2,    18,     2,    22,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    19,
       2,    17,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    24,     2,    25,     2,     2,     2,     2,     2,     2,
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
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    78,    78,    84,    89,    93,    98,   102,   107,   111,
     116,   120,   125,   129,   134,   139,   143,   148,   152,   157,
     161,   166,   171,   175,   180,   184,   189,   194,   199,   204,
     209,   214,   219,   224,   229,   234,   239,   244,   249,   254,
     259,   264,   269,   274,   279,   284,   294,   299,   304,   309,
     314,   319,   324,   329,   334,   339,   344,   349,   354,   359,
     364,   369,   374,   379,   384,   389,   394,   399,   404,   409,
     414,   424,   429,   434,   439,   444,   449,   454,   459,   464,
     469,   474,   480,   486,   491,   496
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
  "'.'", "'!'", "'['", "']'", "PUTINT", "PUTCH", "PUTARRAY", "GETINT",
  "GETCH", "GETARRAY", "MAIN", "INT", "PUBLIC", "CLASS", "IF", "ELSE",
  "WHILE", "CONTINUE", "BREAK", "RETURN", "STARTTIME", "STOPTIME", "TTRUE",
  "FFALSE", "LENGTH", "THIS", "NEW", "EXTENDS", "ID", "NUM", "UMINUS",
  "$accept", "PROG", "STMLIST", "CLASSDECLLIST", "METHODDECLLIST",
  "FORMALLIST", "FORMALRESTLIST", "FORMALREST", "VARDECLLIST", "EXPLIST",
  "EXPRESTLIST", "EXPREST", "NUMBERLIST", "NUMBERRESTLIST", "NUMBERREST",
  "MAINMETHOD", "CLASSDECL", "VARDECL", "METHODDECL", "TYPE", "NUMBER",
  "STM", "EXP", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,    40,    41,    61,    44,    59,
     123,   125,    46,    33,    91,    93,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296
};
# endif

#define YYPACT_NINF (-164)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -4,     1,    35,     9,    16,  -164,    17,  -164,     9,    41,
      28,  -164,    43,    -9,    60,   -12,    31,   -12,   -11,    32,
      49,   -12,    64,   134,    63,     8,    39,    -7,    72,    49,
    -164,   -12,   227,   179,   134,   227,    70,    77,    80,    81,
      89,    90,    91,    93,   101,   104,   227,   109,   110,  -164,
    -164,   111,  -164,   -18,  -164,  -164,   106,   134,   322,    78,
       3,  -164,   112,   113,    83,    84,  -164,  -164,    49,     7,
     134,   344,   114,     7,   227,   227,   227,   120,   123,   227,
     227,   227,  -164,  -164,   366,   124,   125,   227,   119,   115,
    -164,  -164,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,    94,   188,    36,    95,  -164,
     126,  -164,   122,  -164,   135,   130,   102,   227,   132,  -164,
    -164,   388,   410,   432,  -164,  -164,   454,   476,   498,  -164,
     136,   137,   520,   227,   142,    55,    55,     7,     7,    14,
      14,    14,    14,   684,   684,   652,   674,   542,   151,   150,
     276,   148,  -164,  -164,  -164,  -164,    -7,  -164,   156,   227,
     167,   168,   227,  -164,   134,    71,  -164,  -164,  -164,   299,
    -164,  -164,   227,   169,  -164,     3,   175,   143,   227,   564,
    -164,  -164,   586,   158,  -164,  -164,  -164,   180,   608,   227,
     176,   182,   178,   183,   189,  -164,   185,   134,   187,   227,
    -164,   194,   186,   195,     3,  -164,   182,   -12,    -7,  -164,
     183,  -164,  -164,  -164,  -164,   630,  -164,   196,  -164,  -164,
    -164,   134,   166,  -164,  -164,   199,  -164,  -164
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     6,     0,     1,     0,     2,     6,     0,
       0,     5,     0,     0,     0,    15,     0,    15,     0,     0,
       8,    15,     0,     4,     0,     0,     0,     0,     0,     8,
      14,    15,     0,     0,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
      73,     0,    76,     0,    75,    71,     0,     4,     0,     0,
       0,    30,     0,    36,     0,     0,    28,     7,     8,    80,
       4,     0,     0,    79,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    49,     0,     0,     0,     0,     0,     0,
      26,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,    29,     0,    35,     0,     0,     0,     0,     0,    81,
      40,     0,     0,     0,    83,    84,     0,     0,     0,    50,
       0,     0,     0,     0,     0,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    70,     0,
       0,     0,    32,    39,    31,    37,    10,    27,    70,     0,
       0,     0,     0,    85,     0,     0,    54,    55,    74,     0,
      78,    45,    17,     0,    68,    22,     0,     0,    17,     0,
      51,    52,     0,    42,    44,    43,    77,     0,    19,    17,
       0,    24,     0,    12,     0,    82,     0,     0,    69,     0,
      16,    19,     0,     0,     0,    21,    24,    15,     0,     9,
      12,    69,    53,    41,    47,    20,    18,     0,    33,    25,
      23,     4,     0,    11,    46,     0,    13,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,  -164,   -33,   213,   -21,  -164,    12,  -164,   -17,  -156,
      27,  -164,  -164,    34,  -164,  -164,  -164,  -164,  -164,  -150,
    -163,  -155,   -30
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    56,     7,    28,   176,   209,   210,    20,   187,
     200,   201,   190,   205,   206,     3,     8,    21,    29,    65,
     110,    57,    58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      23,    72,    69,    71,    30,    73,   177,   108,    67,   183,
     185,    15,   191,    24,    68,    88,    84,    92,    93,    94,
      95,    18,   194,    19,    91,    60,    63,    61,    64,   116,
       1,   117,    89,   202,     4,     5,   116,   118,   117,    25,
      16,   219,   213,     6,   121,   122,   123,   115,     9,   126,
     127,   128,    10,   151,   109,   152,    12,   132,   222,    14,
      94,    95,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,    32,   150,   116,    13,   117,
      17,    22,    26,    27,    31,    74,    33,   150,    59,    62,
     184,    34,    75,    66,    35,    76,    77,    36,    37,    38,
      39,    40,    41,   169,    78,    79,    80,    42,    81,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      82,    54,    55,    83,    85,    86,    87,    90,   107,   179,
     134,   111,   182,   113,   114,   120,   124,   112,    32,   125,
     130,   131,   188,   133,   148,   154,   153,   155,   188,    33,
     156,   157,   158,   159,    34,   166,   167,    35,   170,   188,
      36,    37,    38,    39,    40,    41,   172,   173,   175,   215,
      42,   178,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    32,    54,    55,   180,   181,   225,   189,
     221,   192,    32,   193,    33,   197,   198,   203,   207,    70,
     204,   208,    35,    33,   212,   211,   214,   217,    39,    40,
      41,    35,   199,   149,   218,   224,   226,    39,    40,    41,
     227,    11,   223,    49,    50,    51,    52,    53,   216,    54,
      55,    32,    49,    50,    51,    52,    53,     0,    54,    55,
     220,     0,    33,     0,     0,     0,     0,     0,     0,     0,
      35,     0,     0,     0,     0,     0,    39,    40,    41,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,    50,    51,    52,    53,     0,    54,    55,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,     0,   116,     0,
     117,   174,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
       0,   116,     0,   117,   186,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,     0,     0,   104,
       0,     0,     0,     0,   105,     0,   106,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,     0,
     119,     0,     0,     0,     0,     0,   116,     0,   117,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,     0,     0,     0,   129,     0,     0,   116,     0,
     117,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,     0,   160,     0,     0,     0,     0,     0,
     116,     0,   117,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,     0,   161,     0,     0,     0,
       0,     0,   116,     0,   117,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,     0,     0,     0,
     162,     0,     0,     0,   116,     0,   117,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,     0,
     163,     0,     0,     0,     0,     0,   116,     0,   117,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,   164,     0,     0,     0,     0,     0,   116,     0,
     117,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,     0,   165,     0,     0,     0,     0,     0,
     116,     0,   117,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,     0,   168,     0,     0,     0,
       0,     0,   116,     0,   117,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,     0,     0,     0,
       0,   171,     0,     0,   116,     0,   117,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,     0,
     195,     0,     0,     0,     0,     0,   116,     0,   117,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,   196,     0,     0,     0,     0,     0,   116,     0,
     117,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,     0,     0,     0,   199,     0,     0,     0,
     116,     0,   117,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,     0,   116,     0,   117,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,     0,   103,     0,     0,     0,
       0,     0,     0,     0,   116,     0,   117,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    92,    93,    94,
      95,    96,    97,    98,    99,     0,   116,     0,   117,     0,
       0,     0,     0,     0,     0,     0,   116,     0,   117
};

static const yytype_int16 yycheck[] =
{
      17,    34,    32,    33,    21,    35,   156,     4,    29,   164,
     165,    20,   175,    24,    31,    33,    46,     3,     4,     5,
       6,    33,   178,    35,    57,    17,    33,    19,    35,    22,
      34,    24,    50,   189,    33,     0,    22,    70,    24,    50,
      49,   204,   197,    34,    74,    75,    76,    68,    32,    79,
      80,    81,    35,    17,    51,    19,    15,    87,   208,    16,
       5,     6,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     4,   106,    22,    50,    24,
      20,    50,    50,    34,    20,    15,    15,   117,    25,    50,
      19,    20,    15,    21,    23,    15,    15,    26,    27,    28,
      29,    30,    31,   133,    15,    15,    15,    36,    15,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      19,    50,    51,    19,    15,    15,    15,    21,    50,   159,
      15,    19,   162,    50,    50,    21,    16,    24,     4,    16,
      16,    16,   172,    24,    50,    19,    51,    25,   178,    15,
      15,    21,    50,    21,    20,    19,    19,    23,    16,   189,
      26,    27,    28,    29,    30,    31,    15,    17,    20,   199,
      36,    15,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     4,    50,    51,    19,    19,   221,    20,
     207,    16,     4,    50,    15,    37,    16,    21,    20,    20,
      18,    18,    23,    15,    19,    16,    19,    21,    29,    30,
      31,    23,    18,    25,    19,    19,    50,    29,    30,    31,
      21,     8,   210,    44,    45,    46,    47,    48,   201,    50,
      51,     4,    44,    45,    46,    47,    48,    -1,    50,    51,
     206,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    -1,    50,    51,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      24,    25,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    24,    25,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    22,    -1,    24,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    22,    -1,    24,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    19,    -1,    -1,    22,    -1,
      24,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    24,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    24,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    22,    -1,    24,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    22,    -1,    24,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    16,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      24,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    24,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    24,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    19,    -1,    -1,    22,    -1,    24,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    22,    -1,    24,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    16,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      24,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      22,    -1,    24,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    24,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    24,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    22,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    34,    54,    68,    33,     0,    34,    56,    69,    32,
      35,    56,    15,    50,    16,    20,    49,    20,    33,    35,
      61,    70,    50,    61,    24,    50,    50,    34,    57,    71,
      61,    20,     4,    15,    20,    23,    26,    27,    28,    29,
      30,    31,    36,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    50,    51,    55,    74,    75,    25,
      17,    19,    50,    33,    35,    72,    21,    57,    61,    75,
      20,    75,    55,    75,    15,    15,    15,    15,    15,    15,
      15,    15,    19,    19,    75,    15,    15,    15,    33,    50,
      21,    55,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    17,    22,    24,    50,     4,    51,
      73,    19,    24,    50,    50,    57,    22,    24,    55,    16,
      21,    75,    75,    75,    16,    16,    75,    75,    75,    19,
      16,    16,    75,    24,    15,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    50,    25,
      75,    17,    19,    51,    19,    25,    15,    21,    50,    21,
      16,    16,    18,    16,    16,    16,    19,    19,    16,    75,
      16,    19,    15,    17,    25,    20,    58,    72,    15,    75,
      19,    19,    75,    74,    19,    74,    25,    62,    75,    20,
      65,    73,    16,    50,    62,    16,    16,    37,    16,    18,
      63,    64,    62,    21,    18,    66,    67,    20,    18,    59,
      60,    16,    19,    74,    19,    75,    63,    21,    19,    73,
      66,    61,    72,    59,    19,    55,    50,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    57,    57,    58,
      58,    59,    59,    60,    61,    61,    62,    62,    63,    63,
      64,    65,    65,    66,    66,    67,    68,    69,    69,    70,
      70,    70,    70,    70,    71,    72,    72,    72,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     2,     0,     2,     0,     3,
       0,     2,     0,     3,     2,     0,     2,     0,     2,     0,
       2,     2,     0,     2,     0,     2,     9,     9,     7,     4,
       3,     5,     5,     9,    10,     2,     1,     3,     1,     2,
       3,     7,     5,     5,     5,     4,     8,     7,     2,     2,
       3,     5,     5,     7,     4,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     6,
       3,     1,     1,     1,     4,     1,     1,     5,     4,     2,
       2,     3,     6,     3,     3,     4
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
#line 79 "parser.yacc"
    {
        root=A_program((yyvsp[-1].mainMethod)->pos,(yyvsp[-1].mainMethod),(yyvsp[0].classDeclList));
        (yyval.prog)=root;
    }
#line 1657 "y.tab.cpp"
    break;

  case 3:
#line 85 "parser.yacc"
    {
        (yyval.stmList)=A_StmList((yyvsp[-1].stm),(yyvsp[0].stmList));
    }
#line 1665 "y.tab.cpp"
    break;

  case 4:
#line 89 "parser.yacc"
    {
        (yyval.stmList)=NULL;
    }
#line 1673 "y.tab.cpp"
    break;

  case 5:
#line 94 "parser.yacc"
    {
        (yyval.classDeclList)=A_ClassDeclList((yyvsp[-1].classDecl),(yyvsp[0].classDeclList));
    }
#line 1681 "y.tab.cpp"
    break;

  case 6:
#line 98 "parser.yacc"
    {
        (yyval.classDeclList)=NULL;
    }
#line 1689 "y.tab.cpp"
    break;

  case 7:
#line 103 "parser.yacc"
    {
        (yyval.methodDeclList)=A_MethodDeclList((yyvsp[-1].methodDecl),(yyvsp[0].methodDeclList));
    }
#line 1697 "y.tab.cpp"
    break;

  case 8:
#line 107 "parser.yacc"
    {
        (yyval.methodDeclList)=NULL;
    }
#line 1705 "y.tab.cpp"
    break;

  case 9:
#line 112 "parser.yacc"
    {
        (yyval.formalList)=A_FormalList(A_Formal((yyvsp[-2].type)->pos,(yyvsp[-2].type),(yyvsp[-1].exp)->u.v),(yyvsp[0].formalList));
    }
#line 1713 "y.tab.cpp"
    break;

  case 10:
#line 116 "parser.yacc"
    {
        (yyval.formalList)=NULL;
    }
#line 1721 "y.tab.cpp"
    break;

  case 11:
#line 121 "parser.yacc"
    {
        (yyval.formalList)=A_FormalList((yyvsp[-1].formal),(yyvsp[0].formalList));
    }
#line 1729 "y.tab.cpp"
    break;

  case 12:
#line 125 "parser.yacc"
    {
        (yyval.formalList)=NULL;
    }
#line 1737 "y.tab.cpp"
    break;

  case 13:
#line 130 "parser.yacc"
    {
        (yyval.formal)=A_Formal((yyvsp[-2].token),(yyvsp[-1].type),(yyvsp[0].exp)->u.v);
    }
#line 1745 "y.tab.cpp"
    break;

  case 14:
#line 135 "parser.yacc"
    {
        (yyval.varDeclList)=A_VarDeclList((yyvsp[-1].varDecl),(yyvsp[0].varDeclList));
    }
#line 1753 "y.tab.cpp"
    break;

  case 15:
#line 139 "parser.yacc"
    {
        (yyval.varDeclList)=NULL;
    }
#line 1761 "y.tab.cpp"
    break;

  case 16:
#line 144 "parser.yacc"
    {
        (yyval.expList)=A_ExpList((yyvsp[-1].exp), (yyvsp[0].expList));
    }
#line 1769 "y.tab.cpp"
    break;

  case 17:
#line 148 "parser.yacc"
    {
        (yyval.expList)=NULL;
    }
#line 1777 "y.tab.cpp"
    break;

  case 18:
#line 153 "parser.yacc"
    {
        (yyval.expList)=A_ExpList((yyvsp[-1].exp), (yyvsp[0].expList));
    }
#line 1785 "y.tab.cpp"
    break;

  case 19:
#line 157 "parser.yacc"
    {
        (yyval.expList)=NULL;
    }
#line 1793 "y.tab.cpp"
    break;

  case 20:
#line 162 "parser.yacc"
    {
        (yyval.exp)=(yyvsp[0].exp);
    }
#line 1801 "y.tab.cpp"
    break;

  case 21:
#line 167 "parser.yacc"
    {
        (yyval.expList)=A_ExpList((yyvsp[-1].exp),(yyvsp[0].expList));
    }
#line 1809 "y.tab.cpp"
    break;

  case 22:
#line 171 "parser.yacc"
    {
        (yyval.expList)=NULL;
    }
#line 1817 "y.tab.cpp"
    break;

  case 23:
#line 176 "parser.yacc"
    {
        (yyval.expList)=A_ExpList((yyvsp[-1].exp),(yyvsp[0].expList));
    }
#line 1825 "y.tab.cpp"
    break;

  case 24:
#line 180 "parser.yacc"
    {
        (yyval.expList)=NULL;
    }
#line 1833 "y.tab.cpp"
    break;

  case 25:
#line 185 "parser.yacc"
    {
        (yyval.exp)=(yyvsp[0].exp);
    }
#line 1841 "y.tab.cpp"
    break;

  case 26:
#line 190 "parser.yacc"
    {
        (yyval.mainMethod)=A_MainMethod((yyvsp[-8].key),(yyvsp[-2].varDeclList),(yyvsp[-1].stmList));
    }
#line 1849 "y.tab.cpp"
    break;

  case 27:
#line 195 "parser.yacc"
    {   
        (yyval.classDecl)=A_ClassDecl((yyvsp[-8].key), (yyvsp[-6].exp)->u.v, (yyvsp[-4].exp)->u.v, (yyvsp[-2].varDeclList), (yyvsp[-1].methodDeclList));
    }
#line 1857 "y.tab.cpp"
    break;

  case 28:
#line 200 "parser.yacc"
    {
        (yyval.classDecl)=A_ClassDecl((yyvsp[-6].key), (yyvsp[-4].exp)->u.v, NULL , (yyvsp[-2].varDeclList) , (yyvsp[-1].methodDeclList));
    }
#line 1865 "y.tab.cpp"
    break;

  case 29:
#line 205 "parser.yacc"
    {
        (yyval.varDecl)=A_VarDecl((yyvsp[-3].key), A_Type((yyvsp[-3].key),A_idType,(yyvsp[-2].exp)->u.v), (yyvsp[-1].exp)->u.v, NULL);
    }
#line 1873 "y.tab.cpp"
    break;

  case 30:
#line 210 "parser.yacc"
    {
        (yyval.varDecl)=A_VarDecl((yyvsp[-2].key), A_Type((yyvsp[-2].key),A_intType,NULL), (yyvsp[-1].exp)->u.v, NULL);
    }
#line 1881 "y.tab.cpp"
    break;

  case 31:
#line 215 "parser.yacc"
    {
        (yyval.varDecl)=A_VarDecl((yyvsp[-4].key), A_Type((yyvsp[-4].key),A_intType,NULL), (yyvsp[-3].exp)->u.v, A_ExpList((yyvsp[-1].exp),NULL));
    }
#line 1889 "y.tab.cpp"
    break;

  case 32:
#line 220 "parser.yacc"
    {
        (yyval.varDecl)=A_VarDecl((yyvsp[-4].key), A_Type((yyvsp[-4].key),A_intArrType,NULL), (yyvsp[-1].exp)->u.v, NULL);
    }
#line 1897 "y.tab.cpp"
    break;

  case 33:
#line 225 "parser.yacc"
    {
        (yyval.varDecl)=A_VarDecl((yyvsp[-8].key), A_Type((yyvsp[-8].key),A_intArrType,NULL), (yyvsp[-5].exp)->u.v, (yyvsp[-2].expList));
    }
#line 1905 "y.tab.cpp"
    break;

  case 34:
#line 230 "parser.yacc"
    {
        (yyval.methodDecl)=A_MethodDecl((yyvsp[-9].key), (yyvsp[-8].type), (yyvsp[-7].exp)->u.v, (yyvsp[-5].formalList), (yyvsp[-2].varDeclList), (yyvsp[-1].stmList));
    }
#line 1913 "y.tab.cpp"
    break;

  case 35:
#line 235 "parser.yacc"
    {
        (yyval.type)=A_Type((yyvsp[-1].key),A_idType,(yyvsp[0].exp)->u.v);
    }
#line 1921 "y.tab.cpp"
    break;

  case 36:
#line 240 "parser.yacc"
    {
        (yyval.type)=A_Type((yyvsp[0].key),A_intType,NULL);
    }
#line 1929 "y.tab.cpp"
    break;

  case 37:
#line 245 "parser.yacc"
    {
        (yyval.type)=A_Type((yyvsp[-2].key),A_intArrType,NULL);
    }
#line 1937 "y.tab.cpp"
    break;

  case 38:
#line 250 "parser.yacc"
    {
        (yyval.exp)=(yyvsp[0].exp);
    }
#line 1945 "y.tab.cpp"
    break;

  case 39:
#line 255 "parser.yacc"
    {
        (yyval.exp)=A_NumConst((yyvsp[-1].token),-(yyvsp[0].exp)->u.num);
    }
#line 1953 "y.tab.cpp"
    break;

  case 40:
#line 260 "parser.yacc"
    {
        (yyval.stm)=A_NestedStm((yyvsp[-2].token),(yyvsp[-1].stmList));
    }
#line 1961 "y.tab.cpp"
    break;

  case 41:
#line 265 "parser.yacc"
    {
        (yyval.stm)=A_IfStm((yyvsp[-6].key),(yyvsp[-4].exp),(yyvsp[-2].stm),(yyvsp[0].stm));
    }
#line 1969 "y.tab.cpp"
    break;

  case 42:
#line 270 "parser.yacc"
    {
        (yyval.stm)=A_IfStm((yyvsp[-4].key),(yyvsp[-2].exp),(yyvsp[0].stm),NULL);
    }
#line 1977 "y.tab.cpp"
    break;

  case 43:
#line 275 "parser.yacc"
    {
        (yyval.stm)=A_WhileStm((yyvsp[-4].key),(yyvsp[-2].exp),(yyvsp[0].stm));
    }
#line 1985 "y.tab.cpp"
    break;

  case 44:
#line 280 "parser.yacc"
    {
        (yyval.stm)=A_WhileStm((yyvsp[-4].key),(yyvsp[-2].exp),NULL);
    }
#line 1993 "y.tab.cpp"
    break;

  case 45:
#line 285 "parser.yacc"
    {
        (yyval.stm)=A_AssignStm((yyvsp[-3].exp)->pos,(yyvsp[-3].exp),(yyvsp[-1].exp));
    }
#line 2001 "y.tab.cpp"
    break;

  case 46:
#line 295 "parser.yacc"
    {
        (yyval.stm)=A_ArrayInit((yyvsp[-7].exp)->pos,(yyvsp[-7].exp), (yyvsp[-2].expList)); 
    }
#line 2009 "y.tab.cpp"
    break;

  case 47:
#line 300 "parser.yacc"
    {
        (yyval.stm)=A_CallStm((yyvsp[-6].exp)->pos,(yyvsp[-6].exp),(yyvsp[-4].exp)->u.v,(yyvsp[-2].expList));
    }
#line 2017 "y.tab.cpp"
    break;

  case 48:
#line 305 "parser.yacc"
    {
        (yyval.stm)=A_Continue((yyvsp[-1].key));
    }
#line 2025 "y.tab.cpp"
    break;

  case 49:
#line 310 "parser.yacc"
    {
        (yyval.stm)=A_Break((yyvsp[-1].key));
    }
#line 2033 "y.tab.cpp"
    break;

  case 50:
#line 315 "parser.yacc"
    {
        (yyval.stm)=A_Return((yyvsp[-2].key),(yyvsp[-1].exp));
    }
#line 2041 "y.tab.cpp"
    break;

  case 51:
#line 320 "parser.yacc"
    {
        (yyval.stm)=A_Putint((yyvsp[-4].key),(yyvsp[-2].exp));
    }
#line 2049 "y.tab.cpp"
    break;

  case 52:
#line 325 "parser.yacc"
    {
        (yyval.stm)=A_Putch((yyvsp[-4].key),(yyvsp[-2].exp));
    }
#line 2057 "y.tab.cpp"
    break;

  case 53:
#line 330 "parser.yacc"
    {
        (yyval.stm)=A_Putarray((yyvsp[-6].key),(yyvsp[-4].exp),(yyvsp[-2].exp));
    }
#line 2065 "y.tab.cpp"
    break;

  case 54:
#line 335 "parser.yacc"
    {
        (yyval.stm)=A_Starttime((yyvsp[-3].key));
    }
#line 2073 "y.tab.cpp"
    break;

  case 55:
#line 340 "parser.yacc"
    {
        (yyval.stm)=A_Stoptime((yyvsp[-3].key));
    }
#line 2081 "y.tab.cpp"
    break;

  case 56:
#line 345 "parser.yacc"
    {
        (yyval.exp)=A_OpExp((yyvsp[-2].exp)->pos,(yyvsp[-2].exp),A_plus,(yyvsp[0].exp));
    }
#line 2089 "y.tab.cpp"
    break;

  case 57:
#line 350 "parser.yacc"
    {
        (yyval.exp)=A_OpExp((yyvsp[-2].exp)->pos,(yyvsp[-2].exp),A_minus,(yyvsp[0].exp));
    }
#line 2097 "y.tab.cpp"
    break;

  case 58:
#line 355 "parser.yacc"
    {
        (yyval.exp)=A_OpExp((yyvsp[-2].exp)->pos,(yyvsp[-2].exp),A_times,(yyvsp[0].exp));
    }
#line 2105 "y.tab.cpp"
    break;

  case 59:
#line 360 "parser.yacc"
    {
        (yyval.exp)=A_OpExp((yyvsp[-2].exp)->pos,(yyvsp[-2].exp),A_div,(yyvsp[0].exp));
    }
#line 2113 "y.tab.cpp"
    break;

  case 60:
#line 365 "parser.yacc"
    {
        (yyval.exp)=A_OpExp((yyvsp[-2].exp)->pos,(yyvsp[-2].exp),A_less,(yyvsp[0].exp));
    }
#line 2121 "y.tab.cpp"
    break;

  case 61:
#line 370 "parser.yacc"
    {
        (yyval.exp)=A_OpExp((yyvsp[-2].exp)->pos,(yyvsp[-2].exp),A_le,(yyvsp[0].exp));
    }
#line 2129 "y.tab.cpp"
    break;

  case 62:
#line 375 "parser.yacc"
    {
        (yyval.exp)=A_OpExp((yyvsp[-2].exp)->pos,(yyvsp[-2].exp),A_greater,(yyvsp[0].exp));
    }
#line 2137 "y.tab.cpp"
    break;

  case 63:
#line 380 "parser.yacc"
    {
        (yyval.exp)=A_OpExp((yyvsp[-2].exp)->pos,(yyvsp[-2].exp),A_ge,(yyvsp[0].exp));
    }
#line 2145 "y.tab.cpp"
    break;

  case 64:
#line 385 "parser.yacc"
    {
        (yyval.exp)=A_OpExp((yyvsp[-2].exp)->pos,(yyvsp[-2].exp),A_eq,(yyvsp[0].exp));
    }
#line 2153 "y.tab.cpp"
    break;

  case 65:
#line 390 "parser.yacc"
    {
        (yyval.exp)=A_OpExp((yyvsp[-2].exp)->pos,(yyvsp[-2].exp),A_ne,(yyvsp[0].exp));
    }
#line 2161 "y.tab.cpp"
    break;

  case 66:
#line 395 "parser.yacc"
    {
        (yyval.exp)=A_OpExp((yyvsp[-2].exp)->pos,(yyvsp[-2].exp),A_or,(yyvsp[0].exp));
    }
#line 2169 "y.tab.cpp"
    break;

  case 67:
#line 400 "parser.yacc"
    {
        (yyval.exp)=A_OpExp((yyvsp[-2].exp)->pos,(yyvsp[-2].exp),A_and,(yyvsp[0].exp));
    }
#line 2177 "y.tab.cpp"
    break;

  case 68:
#line 405 "parser.yacc"
    {
        (yyval.exp)=A_ArrayExp((yyvsp[-3].exp)->pos,(yyvsp[-3].exp),(yyvsp[-1].exp));
    }
#line 2185 "y.tab.cpp"
    break;

  case 69:
#line 410 "parser.yacc"
    {   
        (yyval.exp)=A_CallExp((yyvsp[-5].exp)->pos,(yyvsp[-5].exp),(yyvsp[-3].exp)->u.v,(yyvsp[-1].expList));
    }
#line 2193 "y.tab.cpp"
    break;

  case 70:
#line 415 "parser.yacc"
    {
        (yyval.exp)=A_ClassVarExp((yyvsp[-2].exp)->pos,(yyvsp[-2].exp),(yyvsp[0].exp)->u.v);
    }
#line 2201 "y.tab.cpp"
    break;

  case 71:
#line 425 "parser.yacc"
    {
        (yyval.exp)=(yyvsp[0].exp);
    }
#line 2209 "y.tab.cpp"
    break;

  case 72:
#line 430 "parser.yacc"
    {
        (yyval.exp)=A_BoolConst((yyvsp[0].key),TRUE);
    }
#line 2217 "y.tab.cpp"
    break;

  case 73:
#line 435 "parser.yacc"
    {
        (yyval.exp)=A_BoolConst((yyvsp[0].key),FALSE);
    }
#line 2225 "y.tab.cpp"
    break;

  case 74:
#line 440 "parser.yacc"
    {
        (yyval.exp)=A_LengthExp((yyvsp[-3].key),(yyvsp[-1].exp));
    }
#line 2233 "y.tab.cpp"
    break;

  case 75:
#line 445 "parser.yacc"
    {
        (yyval.exp)=(yyvsp[0].exp);
    }
#line 2241 "y.tab.cpp"
    break;

  case 76:
#line 450 "parser.yacc"
    {
        (yyval.exp)=A_ThisExp((yyvsp[0].key));
    }
#line 2249 "y.tab.cpp"
    break;

  case 77:
#line 455 "parser.yacc"
    {
        (yyval.exp)=A_NewIntArrExp((yyvsp[-4].key),(yyvsp[-1].exp));
    }
#line 2257 "y.tab.cpp"
    break;

  case 78:
#line 460 "parser.yacc"
    {
        (yyval.exp)=A_NewObjExp((yyvsp[-3].key),(yyvsp[-2].exp)->u.v);
    }
#line 2265 "y.tab.cpp"
    break;

  case 79:
#line 465 "parser.yacc"
    {
        (yyval.exp)=A_NotExp((yyvsp[-1].token),(yyvsp[0].exp));
    }
#line 2273 "y.tab.cpp"
    break;

  case 80:
#line 470 "parser.yacc"
    {
        (yyval.exp)=A_MinusExp((yyvsp[-1].token),(yyvsp[0].exp));
    }
#line 2281 "y.tab.cpp"
    break;

  case 81:
#line 475 "parser.yacc"
    {
        (yyvsp[-1].exp)->pos=(yyvsp[-2].token);
        (yyval.exp)=(yyvsp[-1].exp);
    }
#line 2290 "y.tab.cpp"
    break;

  case 82:
#line 481 "parser.yacc"
    {
        if ((yyvsp[-3].stmList)==NULL) (yyval.exp)=A_EscExp(NULL, (yyvsp[-3].stmList) , (yyvsp[-1].exp));
        else (yyval.exp)=A_EscExp((yyvsp[-3].stmList)->head->pos, (yyvsp[-3].stmList) , (yyvsp[-1].exp));
    }
#line 2299 "y.tab.cpp"
    break;

  case 83:
#line 487 "parser.yacc"
    {
        (yyval.exp)=A_Getint((yyvsp[-2].key));
    }
#line 2307 "y.tab.cpp"
    break;

  case 84:
#line 492 "parser.yacc"
    {
        (yyval.exp)=A_Getch((yyvsp[-2].key));
    }
#line 2315 "y.tab.cpp"
    break;

  case 85:
#line 497 "parser.yacc"
    {
        (yyval.exp)=A_Getarray((yyvsp[-3].key),(yyvsp[-1].exp));
    }
#line 2323 "y.tab.cpp"
    break;


#line 2327 "y.tab.cpp"

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
#line 500 "parser.yacc"



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


