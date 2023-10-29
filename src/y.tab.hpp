/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    LET = 270,
    RET = 271,
    FN = 272,
    STRUCT = 273,
    TOKEN_ID = 274,
    TOKEN_NUM = 275,
    CONTINUE = 276,
    BREAK = 277,
    IF = 278,
    ELSE = 279,
    WHILE = 280,
    INT = 281,
    UMINUS = 282
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
#define STRUCT 273
#define TOKEN_ID 274
#define TOKEN_NUM 275
#define CONTINUE 276
#define BREAK 277
#define IF 278
#define ELSE 279
#define WHILE 280
#define INT 281
#define UMINUS 282

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

#line 167 "y.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
