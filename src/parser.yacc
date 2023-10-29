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

// 终结符的类
%token <token> OP_PLUS OP_MINUS OP_MULTIPLY OP_DIVTION OP_LESS OP_LE OP_GREAT OP_GE OP_EQ OP_NEQ OP_OR OP_AND '(' ')' '=' ',' ';' '{' '}' '.'  '[' ']' '!'
%token <key> LET RET FN
%token <tokenId> TOKEN_ID
%token <tokenNum> TOKEN_NUM
%token <pos> POS CONTINUE BREAK NULL IF ELSE WHILE
%token <ntype> NATIVETYPE

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
%type <arithBiOpExpr>       ARITHBIOPEXPR
%type <exprUnit>            EXPRUNIT
%type <arithBiOp>           AIRTHBIOP
%type <arithUOp>            ARITHUOP
%type <fnCall>              FN_CALL
%type <rightValList>        RIGHTVALLIST
%type <arrayExpr>           ARRAYEXPR
%type <indexExpr>           INDEXEXPR
%type <memberExpr>          MEMBEREXPR
%type <arithUExpr>          ARITHUEXPR
%type <varDeclList>         VARDECLLIST
%type <boolBiOpExpr>        BOOLBIOPEXPR
%type <boolBiOp>            BOOLBIOP
%type <comOp>               COMOP
%type <boolUnit>            BOOLUNIT
%type <boolUOpExpr>         BOOLUOPEXPR
%type <comExpr>             COMPEXPR
%type <boolUOp>             BOOLUOP
%type <paramDecl>           PARAMDECL
%type <codeBlockStmt>       CODEBLOCKSTMT
%type <codeBlockStmtList>   CODEBLOCKSTMTLIST
%type <assignStmt>          ASSIGNSTMT
%type <callStmt>            CALLSTMT
%type <returnStmt>          RETURNSTMT
%type <ifStmt>              IFSTMT
%type <whileStmt>           WHILESTMT
%type <leftVal>             LEFTVAL


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

  VARDECLSCALAR : TOKEN_ID ':' TYPE
    {
        $$=A_VarDeclScalar($1->pos, $1->id, $3);
    }
  
  VARDECLARRAY : TOKEN_ID '[' TOKEN_NUM ']' ':' TYPE
    {
        $$=A_VarDeclArray($1->pos, $1->id, $3->num, $6);
    }

  VARDEF : VARDEFSCALAR
    {
        $$=A_VarDef_Scalar($1->pos, $1);
    }
    | VARDEFARRAY
    {
        $$=A_VarDef_Array($1->pos, $1);
    }

  VARDEFSCALAR : TOKEN_ID ':' TYPE '=' RIGHTVAL
    {
        $$=A_VarDefScalar($3->pos, $1->id, $3, $5);
    }
  RIGHTVAL : ARITHEXPR
    {
        $$=A_ArithExprRVal($1->pos, $1);
    }
    | BOOLEXPR
    {
        $$=A_BoolExprRVal($1->pos, $1);
    }
    ARITHEXPR : ARITHBIOPEXPR
    {
        $$=A_ArithBiOp_Expr($1->pos, $1);
    }
    | EXPRUNIT
    {
        $$=A_ExprUnit($1->pos, $1);
    }


    ARITHBIOPEXPR : ARITHEXPR AIRTHBIOP ARITHEXPR
    {
        $$=A_ArithBiOpExpr($2->pos, $2, $1, $3);
    }

    //OP_PLUS OP_MINUS OP_MULTIPLY OP_DIVTION 
    AIRTHBIOP : OP_PLUS
    {
        $$= A_add;
    }
    | OP_MINUS
    {
        $$= A_sub
    }
    | OP_MULTIPLY
    {
        $$= A_mul
    }
    | OP_DIVTION
    {
        $$= A_div
    }


    EXPRUNIT : TOKEN_NUM 
    {
        $$=A_NumExprUnit($1->pos, $1->num);
    }
    | TOKEN_ID
    {
        $$=A_IdExprUnit($1->pos, $1->id);
    }
    | '(' ARITHEXPR ')'
    {
        $$=A_ArithUExprUnit($2->pos, $2);
    }
    | FN_CALL
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

    ARITHUEXPR: ARITHUOP EXPRUNIT
    {
        $$=A_ArithUExprUnit($1->pos, $1, $2);
    }


    ARRAYEXPR: TOKEN_ID '[' INDEXEXPR ']'
    {
        $$=A_ArrayExpr($1->pos, $1->id, $3);
    }
    
    INDEXEXPR: TOKEN_ID
    {
        $$=A_IdIndexExpr($1->pos, $1->id);
    }
    | TOKEN_NUM
    {
        $$=A_NumIndexExpr($1->pos, $1->num);
    }

    MEMBEREXPR: TOKEN_ID '.' TOKEN_ID
    {
        $$=A_MemberExpr($1->pos, $1->id, $3->id);
    }
    

    ARITHUOP : OP_MINUS
    {
        $$=A_neg;
    }

    FN_CALL : TOKEN_ID '(' RIGHTVALLIST ')'
    {
        $$=A_FnCall($1->pos, $1->id, $3);
    }


    RIGHTVALLIST : RIGHTVAL ',' RIGHTVALLIST
    {
        $$=A_RightValList($1->pos, $1, $3);
    }
    | RIGHTVAL
    {
        $$=A_RightValList($1->pos, $1, NULL);
    }

    STRUCTDEF : 'struct' TOKEN_ID '{' VARDECLLIST '}'
    {
        $$=A_StructDef($2->pos, $2->id, $4);
    }

    VARDECLLIST : VARDECL ',' VARDECLLIST
    {
        $$=A_VarDeclList($1->pos, $1, $3);
    }
    | VARDECL
    {
        $$=A_VarDeclList($1->pos, $1, NULL);
    }

    VARDEFARRAY : TOKEN_ID '[' TOKEN_NUM ']' ':' TYPE '=' '{' RIGHTVALLIST '}'
    {
        $$=A_VarDefArray($1->pos, $1->id, $3->num, $6, $9);
    }

    TYPE : TOKEN_ID
    {
        $$=A_StructType($1->pos, $1->id);
    }
    | NATIVETYPE
    {
        $$=A_NativeType($1->pos, $1->ntype);
    }

    BOOLEXPR : BOOLBIOPEXPR 
    {
        $$=A_BoolBiOp_Expr($1->pos, $1);
    }
    | BOOLUNIT
    {
        $$=A_BoolExpr($1->pos, $1);
    }

    BOOLBIOPEXPR :BOOLEXPR BOOLBIOP BOOLUNIT
    {
        $$=A_BoolBiOpExpr($2->pos, $2, $1, $3);
    }
  
    BOOLBIOP : OP_AND
    {
        $$=A_and;
    }
    | OP_OR
    {
        $$=A_or;
    }

    BOOLUNIT : COMPEXPR
    {
        $$=A_ComExpr($1->pos, $1);
    }
    | BOOLEXPR
    {
        $$=A_BoolExprUnit($1->pos, $1);
    }
    | BOOLUOPEXPR
    {
        $$=A_BoolUOpExpr($1->pos, $1);
    }

    COMPEXPR : EXPRUNIT COMOP EXPRUNIT
    {
        $$=A_ComExpr($2->pos, $2, $1, $3);
    }

    COMOP : OP_EQ
    {
        $$=A_eq;
    }
    | OP_NEQ
    {
        $$=A_ne;
    }
    | OP_LE
    {
        $$=A_le;
    }
    | OP_LESS
    {
        $$=A_lt;
    }
    | OP_GREAT
    {
        $$=A_gt;
    }
    | OP_GE
    {
        $$=A_ge;
    }

    BOOLUOPEXPR : BOOLUOP BOOLUNIT
    {
        $$=A_BoolUOpExpr($2->pos, $1, $2);
    }

    BOOLUOP : '!'
    {
        $$=A_not;
    }

    FNDECLSTMT : FNDECL ';'
    {
        $$=A_FnDecl($1->pos, $1);
    }

    FNDECL : FN TOKEN_ID '(' PARAMDECL ')' 
    {
        $$=A_FnDecl($1->pos, $2->id, $4, NULL);
    }
    | FN TOKEN_ID '(' PARAMDECL ')' '-' '>' TYPE
    {
        $$=A_FnDecl($1->pos, $2->id, $4, $8);
    }

    PARAMDECL : VARDECLLIST 
    {
        $$=A_ParamDecl($1->pos, $1);
    }

    FNDEF : FNDECL CODEBLOCKSTMTLIST
    {
        $$=A_FnDef($1->pos, $1, $2);
    }

    CODEBLOCKSTMTLIST : CODEBLOCKSTMT  CODEBLOCKSTMTLIST
    {
        $$=A_CodeBlockStmtList($1->pos, $1, $2);
    }
    | CODEBLOCKSTMT
    {
        $$=A_CodeBlockStmtList($1->pos, $1, NULL);
    }

    //??? pos 从哪里来？
    CODEBLOCKSTMT : '{' NULL ';' '}'
    {
        $$=A_BlockNullStmt($2->pos);
    }
    | '{' VARDECLSTMT '}'
    {
        $$=A_BlockVarDeclStmt($2->pos, $2);
    }
    | '{' ASSIGNSTMT '}'
    {
        $$=A_BlockAssignStmt($2->pos, $2);
    }
    | '{' CALLSTMT '}'
    {
        $$=A_BlockCallStmt($2->pos, $2);
    }
    | '{' IFSTMT '}'
    {
        $$=A_BlockIfStmt($2->pos, $2);
    }
    | '{' WHILESTMT '}'
    {
        $$=A_BlockWhileStmt($2->pos, $2);
    }
    | '{' RETURNSTMT '}'
    {
        $$=A_BlockReturnStmt($2->pos, $2);
    }
    | '{' CONTINUE ';' '}'
    {
        $$=A_BlockContinueStmt($2->pos);
    }
    | '{' BREAK ';' '}'
    {
        $$=A_BlockBreakStmt($2->pos, $2);
    }

    RETURNSTMT : RET RIGHTVAL ';'
    {
        $$=A_ReturnStmt($1->pos, $2);
    }

    ASSIGNSTMT : LEFTVAL '=' RIGHTVAL ';'
    {
        $$=A_AssignStmt($1->pos, $1, $3);
    }

    LEFTVAL : TOKEN_ID
    {
        $$=A_IdLeftVal($1->pos, $1->id);
    }
    | ARRAYEXPR
    {
        $$=A_ArrayLeftVal($1->pos, $1);
    }
    | MEMBEREXPR
    {
        $$=A_MemberLeftVal($1->pos, $1);
    }

    CALLSTMT : FN_CALL ';'
    {
        $$=A_CallStmt($1->pos, $1);
    }

    IFSTMT : IF '(' BOOLEXPR ')' CODEBLOCKSTMT ELSE CODEBLOCKSTMT
    {
        $$=A_IfStmt($1->pos, $3, $5, $7);
    }
    | IF '(' BOOLEXPR ')' CODEBLOCKSTMT
    {
        $$=A_IfStmt($1->pos, $3, $5, NULL);
    }

    WHILESTMT : WHILE '(' BOOLEXPR ')' CODEBLOCKSTMT
    {
        $$=A_WhileStmt($1->pos, $3, $5);
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


