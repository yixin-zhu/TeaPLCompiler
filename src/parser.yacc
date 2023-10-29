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
    int num;
    char* token;
    char* key;
    A_pos pos;
    A_varDecl varDecl;
    A_varDef varDef;
    A_rightVal rightVal;
    A_arithExpr arithExpr;
    A_boolExpr boolExpr;
    A_arithBiOpExpr arithBiOpExpr;
    A_arithUExpr arithUExpr;
    A_exprUnit exprUnit;
    A_fnCall fnCall;
    A_indexExpr indexExpr;
    A_arrayExpr arrayExpr;
    A_memberExpr memberExpr;
    A_boolUnit boolUnit;
    A_boolBiOpExpr boolBiOpExpr;
    A_boolUOpExpr boolUOpExpr;
    A_comExpr comExpr;
    A_rightVal comRightVal;
    A_leftVal leftVal;
    A_assignStmt assignStmt;
    A_rightValList rightValList;
    A_varDefScalar varDefScalar;
    A_varDefArray varDefArray;
    A_varDeclScalar varDeclScalar;
    A_varDeclArray varDeclArray;
    A_varDeclStmt varDeclStmt;
    A_varDeclList varDeclList;
    A_structDef structDef;
    A_paramDecl paramDecl;
    A_fnDecl fnDecl;
    A_fnDef fnDef;
    A_codeBlockStmt codeBlockStmt;
    A_ifStmt ifStmt;
    A_whileStmt whileStmt;
    A_fnDeclStmt fnDeclStmt;
    A_callStmt callStmt;
    A_returnStmt returnStmt;
    A_programElement programElement;
    A_codeBlockStmtList codeBlockStmtList;
    A_programElementList programElementList;
    A_program program;
    A_tokenId tokenId;
    A_tokenNum tokenNum;
}

// token的类
%token <token> OP_PLUS OP_MINUS OP_MULTIPLY OP_DIVTION OP_LESS OP_LE OP_GREAT OP_GE OP_EQ OP_NEQ OP_OR OP_AND '(' ')' '=' ',' ';' '{' '}' '.'  '[' ']' '!'
%token <key> LET RET FN

// 非终结符的类
%type<program> PROGRAM
%type<programElementList> PROGRAMELEMENTLIST
%type<programElement> PROGRAMELEMENT
%type<varDeclStmt> VARDECLSTMT
%type<structDef> STRUCTDEF
%type<fnDeclStmt> FNDECLSTMT
%type<fnDef> FNDEF
%type<varDecl> VARDECL
%type<varDef> VARDEF
%type<varDeclScalar> VARDECLSCALAR
%type<varDeclArray> VARDECLARRAY
%type<varDefScalar> VARDEFSCALAR
%type<varDefArray> VARDEFARRAY
%type<rightVal> RIGHTVAL


%right '='
%left OP_OR
%left OP_AND
%left OP_EQ OP_NEQ
%left OP_LE OP_LESS OP_GREAT OP_GE
%left OP_PLUS OP_MINUS
%left OP_MULTIPLY OP_DIVTION
%right '!' UMINUS
%left '[' ']' '(' ')'
%left '.'
%right ELSE

%start PROGRAM
%%

PROGRAM : PROGRAMELEMENTLIST
    {
        root=A_program($1);
        $$=root;
    }

PROGRAMELEMENTLIST : PROGRAMELEMENT PROGRAMELEMENTLIST
    {
        $$=A_programElementList($1,$2);
    }
    |
    {
        $$=NULL;
    }

  PROGRAMELEMENT : VARDECLSTMT PROGRAMELEMENT
    {
        $$=A_ProgramVarDeclStmt($1->pos, $1);
    }
    | STRUCTDEF PROGRAMELEMENT
    {
        $$=A_ProgramStructDef($1->pos, $1);
    } 
    | FNDECLSTMT PROGRAMELEMENT
    {
        $$=A_ProgramFnDeclStmt($1->pos, $1);
    }
    | FNDEF PROGRAMELEMENT
    {
        $$=A_ProgramFnDef($1->pos, $1);
    }
    | ';' PROGRAMELEMENT
    {
        $$=A_ProgramNullStmt($1->pos);
    }
    |
    {
        $$=NULL;
    }

  VARDECLSTMT : LET VARDECL ';'
    {
        $$=A_VarDeclStmt($2->pos, $2);
    }
    | LET VARDEF ';'
    {
        $$=A_VarDefStmt($2->pos, $2);
    }

  VARDECL : VARDECLSCALAR
    {
        $$=A_VarDeclScalar($1->pos, $1);
    }
    | VARDECLARRAY
    {
        $$=A_VarDeclArray($1->pos, $1);
    }

  VARDECLSCALAR : ID ':' TYPE
    {
        $$=A_VarDeclScalar($3->pos, $1, $3);
    }
  
  VARDECLARRAY : ID '[' NUM ']' ':' TYPE
    {
        $$=A_VarDeclArray($6->pos, $1, $3, $6);
    }

  VARDEF : VARDEFSCALAR
    {
        $$=A_VarDef_Scalar($1->pos, $1);
    }
    | VARDEFARRAY
    {
        $$=A_VarDef_Array($1->pos, $1);
    }

  VARDEFSCALAR : ID ':' TYPE '=' RIGHTVAL
    {
        $$=A_VarDefScalar($3->pos, $1, $3, $5);
    }



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


