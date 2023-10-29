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
}

// 终结符的类
%token <token> OP_PLUS OP_MINUS OP_MULTIPLY OP_DIVTION OP_LESS OP_LE OP_GREAT OP_GE OP_EQ OP_NEQ OP_OR OP_AND '(' ')' '=' ',' ';' '{' '}' '.'  '[' ']' '!' OP_ARROW
%token <key> LET RET FN STRUCT
%token <tokenId> TOKEN_ID
%token <tokenNum> TOKEN_NUM
%token <key> CONTINUE BREAK IF ELSE WHILE INT


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
%left ';'
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
        $$=A_ProgramElementList($1,$2);
    }
    | PROGRAMELEMENT 
    {
        $$=A_ProgramElementList($1,NULL);
    }

PROGRAMELEMENT : VARDECLSTMT PROGRAMELEMENT
    {
      printf("programelement 1\n");
        $$=A_ProgramVarDeclStmt($1->pos, $1);
      printf("eof programelement 1\n");
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
      printf("programelement 5\n");
        $$=A_ProgramNullStmt($2->pos);
      printf("eof programelement 5\n");
    }
    |
    {
        $$=NULL;
    }

  VARDECLSTMT : LET VARDECL ';'
    {   
        printf("vardeclstmt 1\n");
        printf("pos %d\n", $2->pos->line);
        $$=A_VarDeclStmt($1, $2);
        printf("eof vardeclstmt 1\n");
    }
    | LET VARDEF ';'
    {
        printf("vardeclstmt 2\n");
        printf("pos %d\n", $2->pos->line);
        $$=A_VarDefStmt($2->pos, $2);
        printf("eof vardeclstmt 2\n");
    }

  VARDECL : VARDECLSCALAR
    {
        printf("vardecl\n");
        printf("pos %d\n", $1->pos->line);
        $$=A_VarDecl_Scalar($1->pos, $1);
        printf("eof vardecl\n");
    }
    | VARDECLARRAY
    {
        $$=A_VarDecl_Array($1->pos, $1);
    }

  VARDECLSCALAR : TOKEN_ID ':' TYPE
    {
      printf("vardeclscalar\n");
        $$=A_VarDeclScalar($1->pos, $1->id, $3);
      printf("eof vardeclscalar\n");
    }
  
  VARDECLARRAY : TOKEN_ID '[' TOKEN_NUM ']' ':' TYPE
    {
        $$=A_VarDeclArray($1->pos, $1->id, $3->num, $6);
    }

  VARDEF : VARDEFSCALAR
    {
        printf("vardef\n");
        $$=A_VarDef_Scalar($1->pos, $1);
        printf("eof vardef\n");
    }
    | VARDEFARRAY
    {
        $$=A_VarDef_Array($1->pos, $1);
    }

  VARDEFSCALAR : TOKEN_ID ':' TYPE '=' RIGHTVAL
    {
        printf("vardefscalar\n");
        $$=A_VarDefScalar($3->pos, $1->id, $3, $5);
        printf("eof vardefscalar\n");
    }
  RIGHTVAL : ARITHEXPR
    {
        printf("rightval\n");
        $$=A_ArithExprRVal($1->pos, $1);
        printf("eof rightval\n");
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
        $$=A_ArithBiOpExpr($1->pos, $2, $1, $3);
    }

    //OP_PLUS OP_MINUS OP_MULTIPLY OP_DIVTION 
    AIRTHBIOP : OP_PLUS
    {
        $$= A_add;
    }
    | OP_MINUS
    {
        $$= A_sub;
    }
    | OP_MULTIPLY
    {
        $$= A_mul;
    }
    | OP_DIVTION
    {
        $$= A_div;
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
        $$=A_ArithExprUnit($2->pos, $2);
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
        $$=A_ArithUExpr($2->pos, $1, $2);
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
    

    ARITHUOP : OP_MINUS %prec UMINUS
    {
        $$=A_neg;
    }

    FN_CALL : TOKEN_ID '(' RIGHTVALLIST ')'
    {
        $$=A_FnCall($1->pos, $1->id, $3);
    }


    RIGHTVALLIST : RIGHTVAL ',' RIGHTVALLIST
    {
        $$=A_RightValList($1, $3);
    }
    | RIGHTVAL
    {
        $$=A_RightValList($1, NULL);
    }

    STRUCTDEF: STRUCT TOKEN_ID '{' VARDECLLIST '}'
    {
        $$=A_StructDef($2->pos, $2->id, $4);
    }

    VARDECLLIST : VARDECL ',' VARDECLLIST
    {
        $$=A_VarDeclList($1, $3);
    }
    | VARDECL
    {
        $$=A_VarDeclList($1, NULL);
    }

    VARDEFARRAY : TOKEN_ID '[' TOKEN_NUM ']' ':' TYPE '=' '{' RIGHTVALLIST '}'
    {
        $$=A_VarDefArray($1->pos, $1->id, $3->num, $6, $9);
    }

    TYPE : TOKEN_ID
    {
        printf("type %s\n", $1->id);
        $$=A_StructType($1->pos, $1->id);
    }
    | INT
    {
        printf("type int\n");
        $$=A_NativeType($1, A_intTypeKind);
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
        $$=A_BoolBiOpExpr($1->pos, $2, $1, $3);
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
        $$=A_ComExprUnit($1->pos, $1);
    }
    | BOOLEXPR
    {
        $$=A_BoolExprUnit($1->pos, $1);
    }
    | BOOLUOPEXPR
    {
        $$=A_BoolUOpExprUnit($1->pos, $1);
    }

    COMPEXPR : EXPRUNIT COMOP EXPRUNIT
    {
        $$=A_ComExpr($1->pos, $2, $1, $3);
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
        $$=A_FnDeclStmt($1->pos, $1);
    }

    FNDECL : FN TOKEN_ID '(' PARAMDECL ')' 
    {
        $$=A_FnDecl($1, $2->id, $4, NULL);
    }
    | FN TOKEN_ID '(' PARAMDECL ')' OP_ARROW TYPE
    {
        $$=A_FnDecl($1, $2->id, $4, $7);
    }

    PARAMDECL : VARDECLLIST 
    {
        $$=A_ParamDecl($1);
    }

    FNDEF : FNDECL CODEBLOCKSTMTLIST
    {
        $$=A_FnDef($1->pos, $1, $2);
    }

    CODEBLOCKSTMTLIST : CODEBLOCKSTMT  CODEBLOCKSTMTLIST
    {
        $$=A_CodeBlockStmtList($1, $2);
    }
    | CODEBLOCKSTMT
    {
        $$=A_CodeBlockStmtList($1, NULL);
    }

    //??? pos 从哪里来？
    CODEBLOCKSTMT : '{' ';' '}'
    {
        $$=A_BlockNullStmt($1);
    }
    | '{' VARDECLSTMT '}'
    {
      printf("codeblockstmt\n");
        $$=A_BlockVarDeclStmt($2->pos, $2);
      printf("eof codeblockstmt\n");
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
        $$=A_BlockContinueStmt($2);
    }
    | '{' BREAK ';' '}'
    {
        $$=A_BlockBreakStmt($2);
    }

    RETURNSTMT : RET RIGHTVAL ';'
    {
        $$=A_ReturnStmt($1, $2);
    }

    ASSIGNSTMT : LEFTVAL '=' RIGHTVAL ';'
    {
      printf("assignstmt\n");
        $$=A_AssignStmt($1->pos, $1, $3);
    }

    LEFTVAL : TOKEN_ID
    {
        printf("tokenid\n");
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

    CALLSTMT : FN_CALL ';'
    {
        $$=A_CallStmt($1->pos, $1);
    }

    IFSTMT : IF '(' BOOLEXPR ')' CODEBLOCKSTMTLIST ELSE CODEBLOCKSTMTLIST
    {
        $$=A_IfStmt($1, $3, $5, $7);
    }
    | IF '(' BOOLEXPR ')' CODEBLOCKSTMTLIST
    {
        $$=A_IfStmt($1, $3, $5, NULL);
    }

    WHILESTMT : WHILE '(' BOOLEXPR ')' CODEBLOCKSTMTLIST
    {
        $$=A_WhileStmt($1, $3, $5);
    }
%% 


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


