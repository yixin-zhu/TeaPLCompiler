%{
#include <stdio.h>
#include <string.h>
#include "TeaplAst.h"
#include "y.tab.hpp"
extern int line, col;
%}

// TODO:
// your lexer
%start COMMENT1  COMMENT2
%%
<COMMENT1>"\n" {++line;col=0;BEGIN INITIAL;}
<COMMENT1>. {col+=yyleng;}

<COMMENT2>"*/" {col+=yyleng;BEGIN INITIAL;}
<COMMENT2>"\n" {++line;col=0;}
<COMMENT2>. {col+=yyleng;}

<INITIAL>"//" {col+=yyleng;BEGIN COMMENT1;}
<INITIAL>"/*" {col+=yyleng;BEGIN COMMENT2;}
<INITIAL>"\n" {++line;col=0;}
<INITIAL>" "|"\r"|"\t" {col+=yyleng;}

<INITIAL>"+" {yylval.token = A_Pos(line,col); col+=yyleng; return OP_PLUS; }
<INITIAL>"-" {yylval.token = A_Pos(line,col); col+=yyleng; return OP_MINUS;}
<INITIAL>"*" {yylval.token = A_Pos(line,col); col+=yyleng; return OP_MULTIPLY; }
<INITIAL>"/" {yylval.token = A_Pos(line,col); col+=yyleng; return OP_DIVTION; }
<INITIAL>"<" {yylval.token = A_Pos(line,col); col+=yyleng; return OP_LESS; }
<INITIAL>"<=" {yylval.token = A_Pos(line,col); col+=yyleng; return OP_LE; }
<INITIAL>">" {yylval.token = A_Pos(line,col); col+=yyleng; return OP_GREAT; }
<INITIAL>">=" {yylval.token = A_Pos(line,col); col+=yyleng; return OP_GE; }
<INITIAL>"==" {yylval.token = A_Pos(line,col); col+=yyleng; return OP_EQ; }
<INITIAL>"!=" {yylval.token = A_Pos(line,col); col+=yyleng; return OP_NEQ; }
<INITIAL>"||" {yylval.token = A_Pos(line,col); col+=yyleng; return OP_OR; }
<INITIAL>"&&" {yylval.token = A_Pos(line,col); col+=yyleng; return OP_AND; }

<INITIAL>"("|")"|":"|"="|","|";"|"{"|"}"|"."|"!"|"["|"]" {
    yylval.token=A_Pos(line,col);
    col+=yyleng;
    c = yytext[0];
    return(c);
}
<INITIAL>[a-z_A-Z][a-z_A-Z0-9]* {
    yylval.exp = A_IdExp(A_Pos(line,col),String(yytext));
    col+=yyleng; 
    return ID;
}
<INITIAL>[1-9][0-9]* {
    yylval.exp=A_NumConst(A_Pos(line,col),calculate(yytext,yyleng));
    col+=yyleng; 
    return NUM;
}
<INITIAL> 0 {
    yylval.exp = A_NumConst(A_Pos(line,col),0);
    col+=yyleng;
    return NUM;
}
<INITIAL>. {
    col+=yyleng;
    printf("Illegal input \"%c\"\n", yytext[0]);
}
%%


int calculate(char *s, int len) {
    int ret = 0;
    for(int i = 0; i < len; i++)
        ret = ret * 10 + (s[i] - '0');
    return ret;
}
























