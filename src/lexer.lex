%{
#include <stdio.h>
#include <string.h>
#include "TeaplAst.h"
#include "y.tab.hpp"
extern int line, col;
int c;
int calculate(char *s, int len);
char * text;
%}


%start COMMENT1  COMMENT2
%%
<COMMENT1>"\n" {++line;col=1;BEGIN INITIAL;}
<COMMENT1>. {col+=yyleng;}

<COMMENT2>"*/" {col+=yyleng;BEGIN INITIAL;}
<COMMENT2>"\n" {++line;col=1;}
<COMMENT2>. {col+=yyleng;}

<INITIAL>"//" {col+=yyleng;BEGIN COMMENT1;}
<INITIAL>"/*" {col+=yyleng;BEGIN COMMENT2;}
<INITIAL>"\n" {++line;col=1;}
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


<INITIAL>"let" {
    yylval.key=A_Pos(line,col);
    col+=yyleng;
    return LET;
}
<INITIAL>"ret" {
    yylval.key=A_Pos(line,col);
    col+=yyleng;
    return RET;
}
<INITIAL>"fn" {
    yylval.key=A_Pos(line,col);
    col+=yyleng;
    return FN;
}
<INITIAL>"continue" {
    yylval.key=A_Pos(line,col);
    col+=yyleng;
    return CONTINUE;
}
<INITIAL>"break" {
    yylval.key=A_Pos(line,col);
    col+=yyleng;
    return BREAK;
}
<INITIAL>"if" {
    yylval.key=A_Pos(line,col);
    col+=yyleng;
    return IF;
}
<INITIAL>"else" {
    yylval.key=A_Pos(line,col);
    col+=yyleng;
    return ELSE;
}
<INITIAL>"while" {
    yylval.key=A_Pos(line,col);
    col+=yyleng;
    return WHILE;
}
<INITIAL>"struct" {
    yylval.key=A_Pos(line,col);
    col+=yyleng;
    return STRUCT;
}
<INITIAL>"int" {
    yylval.key=A_Pos(line,col);
    col+=yyleng;
    return INT;
}
<INITIAL>"("|")"|":"|"="|","|";"|"{"|"}"|"."|"!"|"["|"]" {
    yylval.token=A_Pos(line,col);
    col+=yyleng;
    c = yytext[0];
    return(c);
}
<INITIAL>[a-z_A-Z][a-z_A-Z0-9]* {
    strcpy(text,yytext);
    yylval.tokenId = A_TokenId(A_Pos(line,col), text);
    col+=yyleng; 
    return TOKEN_ID;
}
<INITIAL>[1-9][0-9]* {
    yylval.tokenNum = A_TokenNum(A_Pos(line,col),calculate(yytext,yyleng));
    col+=yyleng; 
    return TOKEN_NUM;
}
<INITIAL>0 {
    yylval.tokenNum = A_TokenNum(A_Pos(line,col),0);
    col+=yyleng;
    return TOKEN_NUM;
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
























