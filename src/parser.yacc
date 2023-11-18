%{
#include <stdio.h>
#include "TeaplAst.h"

extern A_pos pos;
extern A_program root;

extern int yylex(void);
extern "C"{
extern void yyerror(char *s); 
extern int  yywrap();
}

%}

// TODO:
// your parser
%union
{

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
}

// 终结符的类
%token <token> OP_PLUS OP_MINUS OP_MULTIPLY OP_DIVTION OP_LESS OP_LE OP_GREAT OP_GE OP_EQ OP_NEQ OP_OR OP_AND '(' ')' '=' ',' ';' '{' '}' '.'  '[' ']' '!' OP_ARROW
%token <key> LET RET FN STRUCT CONTINUE BREAK IF ELSE WHILE INT
%token <tokenId> TOKEN_ID
%token <tokenNum> TOKEN_NUM


// 非终结符的类
%type <program>             PROGRAM
%type <programElementList>  PROGRAMELEMENTLIST
%type <programElement>      PROGRAMELEMENT
%type <varDeclStmt>         VARDECLSTMT
%type <structDef>           STRUCTDEF
%type <fnDeclStmt>          FNDECLSTMT
%type <fnDef>               FNDEF
%type <fnDecl>              FNDECL
%type <varDecl>             VARDECL
%type <varDef>              VARDEF
%type <varDeclScalar>       VARDECLSCALAR
%type <varDeclArray>        VARDECLARRAY
%type <varDefScalar>        VARDEFSCALAR
%type <varDefArray>         VARDEFARRAY
%type <rightVal>            RIGHTVAL
%type <type>                TYPE
%type <arithExpr>           ARITHEXPR
%type <boolExpr>            BOOLEXPR
%type <exprUnit>            EXPRUNIT
%type <fnCall>              FNCALL
%type <rightValList>        RIGHTVALLIST
%type <arrayExpr>           ARRAYEXPR
%type <indexExpr>           INDEXEXPR
%type <memberExpr>          MEMBEREXPR
%type <arithUExpr>          ARITHUEXPR
%type <varDeclList>         VARDECLLIST
%type <boolUnit>            BOOLUNIT
%type <comExpr>             COMEXPR
%type <paramDecl>           PARAMDECL
%type <codeBlockStmt>       CODEBLOCKSTMT
%type <codeBlockStmtList>   CODEBLOCKSTMTLIST CODEBLOCK
%type <assignStmt>          ASSIGNSTMT
%type <callStmt>            CALLSTMT
%type <returnStmt>          RETURNSTMT
%type <ifStmt>              IFSTMT
%type <whileStmt>           WHILESTMT
%type <leftVal>             LEFTVAL
%type <boolBiOpExpr>        BOOLBIOPEXPR

%left OP_PLUS OP_MINUS
%left OP_MULTIPLY OP_DIVTION

%start PROGRAM
%%

PROGRAM: PROGRAMELEMENTLIST 
{  
  root = A_Program($1);
  $$ = A_Program($1);
}
;

PROGRAMELEMENTLIST: PROGRAMELEMENT PROGRAMELEMENTLIST
{
  $$ = A_ProgramElementList($1, $2);
}
|
{
  $$ = NULL;
}
;

PROGRAMELEMENT: VARDECLSTMT
{
  $$ = A_ProgramVarDeclStmt($1->pos, $1);
}
| STRUCTDEF
{
  $$ = A_ProgramStructDef($1->pos, $1);
}
| FNDECLSTMT
{
  $$ = A_ProgramFnDeclStmt($1->pos, $1);
}
| FNDEF
{
  $$ = A_ProgramFnDef($1->pos, $1);
}
| ';'
{
  $$ = A_ProgramNullStmt($1);
}
;

RIGHTVAL : ARITHEXPR 
{
  $$ = A_ArithExprRVal($1->pos, $1);
}
| BOOLEXPR
{
  $$ = A_BoolExprRVal($1->pos, $1);
}
;

LEFTVAL : TOKEN_ID
{
    $$=A_IdExprLVal($1->pos, $1->id);
}
| ARRAYEXPR
{
    $$=A_ArrExprLVal($1->pos, $1);
}
| MEMBEREXPR
{
    $$=A_MemberExprLVal($1->pos, $1);
}
;

RIGHTVALLIST:RIGHTVAL ',' RIGHTVALLIST
{
  $$=A_RightValList($1, $3);
}
|RIGHTVAL
{
  $$=A_RightValList($1, NULL);
}
;

FNDECLSTMT : FNDECL ';'
{
  $$ = A_FnDeclStmt($1->pos, $1);
}
;


FNDECL : FN TOKEN_ID '(' PARAMDECL ')' 
{
  $$ = A_FnDecl($1, $2->id, $4, NULL);
}
| FN TOKEN_ID '(' PARAMDECL ')' OP_ARROW TYPE 
{
  $$ = A_FnDecl($1, $2->id, $4, $7);
}
;
TYPE:INT
{
  $$ = A_NativeType($1, A_intTypeKind);
}
|TOKEN_ID
{
  $$ = A_StructType($1->pos, $1->id);
}
;

PARAMDECL : VARDECLLIST
{
  $$ = A_ParamDecl($1);
}
;

VARDECLLIST:VARDECL ',' VARDECLLIST
{
  $$ = A_VarDeclList($1, $3);
}
|VARDECL
{
  $$ = A_VarDeclList($1, NULL);
}
|
{
    $$=NULL;
}
;

VARDECL : VARDECLSCALAR
{
    $$=A_VarDecl_Scalar($1->pos, $1);
}
| VARDECLARRAY
{
    $$=A_VarDecl_Array($1->pos, $1);
}
;

VARDECLSCALAR : TOKEN_ID ':' TYPE
{
    $$=A_VarDeclScalar($1->pos, $1->id, $3);
}
| TOKEN_ID
{
    $$=A_VarDeclScalar($1->pos, $1->id, NULL);
}
;

VARDECLARRAY : TOKEN_ID '[' TOKEN_NUM ']' ':' TYPE
{
    $$=A_VarDeclArray($1->pos, $1->id, $3->num, $6);
}
| TOKEN_ID '[' TOKEN_NUM ']'
{
    $$=A_VarDeclArray($1->pos, $1->id, $3->num, NULL);
}
;

VARDEF : VARDEFSCALAR
{
    $$=A_VarDef_Scalar($1->pos, $1);
}
| VARDEFARRAY
{
    $$=A_VarDef_Array($1->pos, $1);
}
|
{
    $$=NULL;
}


VARDEFARRAY : TOKEN_ID '[' TOKEN_NUM ']' ':' TYPE '=' '{' RIGHTVALLIST '}'
{
    $$=A_VarDefArray($1->pos, $1->id, $3->num, $6, $9);
}
| TOKEN_ID '[' TOKEN_NUM ']' '=' '{' RIGHTVALLIST '}'
{
    $$=A_VarDefArray($1->pos, $1->id, $3->num, A_NativeType($1->pos, A_intTypeKind) , $7);
}
;

VARDEFSCALAR : TOKEN_ID ':' TYPE '=' RIGHTVAL
{
    //printf("vardefscalar\n");
    $$=A_VarDefScalar($3->pos, $1->id, $3, $5);
    //printf("eof vardefscalar\n");
}
| TOKEN_ID '=' RIGHTVAL
{
    $$=A_VarDefScalar($1->pos, $1->id, A_NativeType($1->pos, A_intTypeKind), $3);
}
;


FNDEF : FNDECL CODEBLOCK
{
  $$ = A_FnDef($1->pos, $1, $2);
}  
;

CODEBLOCK : '{' CODEBLOCKSTMTLIST '}'
{
  $$ = $2;
} 
;
CODEBLOCKSTMTLIST:CODEBLOCKSTMT CODEBLOCKSTMTLIST
{
  $$ = A_CodeBlockStmtList($1, $2);
}
|CODEBLOCKSTMT
{
  $$ = A_CodeBlockStmtList($1, NULL);
}
;

CODEBLOCKSTMT : ';'
{
    $$=A_BlockNullStmt($1);
}
| VARDECLSTMT 
{
    $$=A_BlockVarDeclStmt($1->pos, $1);
}
|  ASSIGNSTMT 
{
    $$=A_BlockAssignStmt($1->pos, $1);
}
| CALLSTMT 
{
    $$=A_BlockCallStmt($1->pos, $1);
}
|  IFSTMT 
{
    $$=A_BlockIfStmt($1->pos, $1);
}
|  WHILESTMT 
{
    $$=A_BlockWhileStmt($1->pos, $1);
}
| RETURNSTMT 
{
    $$=A_BlockReturnStmt($1->pos, $1);
}
|  CONTINUE ';' 
{
    $$=A_BlockContinueStmt($2);
}
| BREAK ';' 
{
    $$=A_BlockBreakStmt($2);
}
| 
{
    $$=A_BlockNullStmt(NULL);
}
;

RETURNSTMT : RET RIGHTVAL ';'
{
    $$=A_ReturnStmt($1, $2);
}
| RET ';'
{
    $$=A_ReturnStmt($1, NULL);
}

ASSIGNSTMT : LEFTVAL '=' RIGHTVAL ';'
{
    // printf("assignstmt\n");
    $$=A_AssignStmt($1->pos, $1, $3);
}

CALLSTMT : FNCALL ';'
{
    $$=A_CallStmt($1->pos, $1);
}

IFSTMT : IF '(' BOOLEXPR ')' '{' CODEBLOCKSTMTLIST '}' ELSE '{' CODEBLOCKSTMTLIST '}'
{
    $$=A_IfStmt($1, $3, $6, $10);
}
| IF '(' BOOLEXPR ')' '{' CODEBLOCKSTMTLIST '}'
{
    $$=A_IfStmt($1, $3, $6, NULL);
}

WHILESTMT : WHILE '(' BOOLEXPR ')' '{' CODEBLOCKSTMTLIST '}'
{
    $$=A_WhileStmt($1, $3, $6);
}

VARDECLSTMT: LET VARDECL ';'
{
  $$ = A_VarDeclStmt($1, $2);
}
| LET VARDEF ';'
{
  $$ = A_VarDefStmt($1,  $2);
}
;


BOOLEXPR : BOOLBIOPEXPR
{
  $$ = A_BoolBiOp_Expr($1->pos, $1);
}
| BOOLUNIT
{
  $$ = A_BoolExpr($1->pos, $1);
}
;

BOOLBIOPEXPR: BOOLEXPR OP_OR BOOLEXPR
{
  $$ = A_BoolBiOpExpr($1->pos, A_or, $1, $3);
}
|
BOOLEXPR OP_AND BOOLEXPR
{
  $$ = A_BoolBiOpExpr($1->pos, A_and, $1, $3);
}
;

BOOLUNIT : COMEXPR  
{
  $$ = A_ComExprUnit($1->pos, $1);
}
|
 '(' COMEXPR ')'  
{
  $$ = A_ComExprUnit($1, $2);
}
| '(' BOOLEXPR ')'
{
  $$ = A_BoolExprUnit($1, $2);
}
| '!' BOOLUNIT 
{
  $$ = A_BoolUOpExprUnit($1, A_BoolUOpExpr($1, A_not, $2));
}
;

COMEXPR : EXPRUNIT OP_GREAT EXPRUNIT 
{
  $$ = A_ComExpr($1->pos, A_gt, $1, $3);
}
| EXPRUNIT OP_LESS EXPRUNIT 
{
  $$ = A_ComExpr($1->pos, A_lt, $1, $3);
}
| EXPRUNIT OP_GE EXPRUNIT 
{
  $$ = A_ComExpr($1->pos, A_ge, $1, $3);
}
| EXPRUNIT OP_LE EXPRUNIT 
{
  $$ = A_ComExpr($1->pos, A_le, $1, $3);
}
| EXPRUNIT OP_EQ EXPRUNIT 
{
  $$ = A_ComExpr($1->pos, A_eq, $1, $3);
}
| EXPRUNIT OP_NEQ EXPRUNIT 
{
  $$ = A_ComExpr($1->pos, A_ne, $1, $3);
}

ARITHEXPR: ARITHEXPR OP_PLUS ARITHEXPR
{
  $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_add, $1, $3));
}
| ARITHEXPR OP_MINUS ARITHEXPR
{
  $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_sub, $1, $3));
}
| ARITHEXPR OP_MULTIPLY ARITHEXPR
{
  $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_mul, $1, $3));
}
| ARITHEXPR OP_DIVTION ARITHEXPR
{
  $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_div, $1, $3));
}
| EXPRUNIT
{
  $$ = A_ExprUnit($1->pos, $1);
}
;

EXPRUNIT : TOKEN_NUM 
{
    $$=A_NumExprUnit($1->pos, $1->num);
}
| TOKEN_ID
{
    $$=A_IdExprUnit($1->pos, $1->id);
    // printf("eof exprunit\n");
}
| '(' ARITHEXPR ')'
{
    $$=A_ArithExprUnit($2->pos, $2);
}
| FNCALL
{
    $$=A_CallExprUnit($1->pos, $1);
}
| ARRAYEXPR
{
    $$=A_ArrayExprUnit($1->pos, $1);
}
| MEMBEREXPR
{
    $$=A_MemberExprUnit($1->pos, $1);
}
| ARITHUEXPR
{
    $$=A_ArithUExprUnit($1->pos, $1);
}
;

STRUCTDEF: STRUCT TOKEN_ID '{' VARDECLLIST '}'
{
  $$ = A_StructDef($2->pos, $2->id, $4);
}
;

FNCALL : TOKEN_ID '(' RIGHTVALLIST ')'
{
  $$ = A_FnCall($1->pos, $1->id,$3);
}
|TOKEN_ID '(' ')'
{
  $$ = A_FnCall($1->pos, $1->id, NULL);
}
;

ARITHUEXPR: OP_MINUS EXPRUNIT
{
    $$=A_ArithUExpr($2->pos, A_neg, $2);
}
;

ARRAYEXPR: LEFTVAL '[' INDEXEXPR ']'
{
    $$=A_ArrayExpr($1->pos, $1, $3);
}

INDEXEXPR: TOKEN_ID
{
    $$=A_IdIndexExpr($1->pos, $1->id);
}
| TOKEN_NUM
{
    $$=A_NumIndexExpr($1->pos, $1->num);
}
;

MEMBEREXPR: LEFTVAL '.' TOKEN_ID
{
    $$=A_MemberExpr($1->pos, $1, $3->id);
}
;

%%

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


