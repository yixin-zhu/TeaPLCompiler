%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "TeaplAst.h"
#include "y.tab.hpp"
extern int line, col;
typedef char *string;
int c;
int calculate(char *s, int len);
char *checked_malloc(int);
string String(char *s);
%}


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
<INITIAL>" "|"\r" {col+=yyleng;}
<INITIAL>" "|"\t" {col+=4;}

<INITIAL>"->" {yylval.token = A_Pos(line,col); col+=yyleng; return OP_ARROW; }
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
    //printf("* let %d\n", yyleng);
    return LET;
}
<INITIAL>"ret" {

    yylval.key=A_Pos(line,col); 
    col+=yyleng;
    // printf("* ret %d\n", yyleng);
    return RET;
}
<INITIAL>"fn" {
    //printf("* fn\n");
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
    //printf("* struct\n");
    yylval.key=A_Pos(line,col);
    col+=yyleng;
    //printf("* struct %d %d\n", yyleng, col);
    return STRUCT;
}
<INITIAL>"int" {
    yylval.key=A_Pos(line,col);
    col+=yyleng;
    //printf("* int\n");
    return INT;
}
<INITIAL>"("|")"|":"|"="|","|";"|"{"|"}"|"."|"!"|"["|"]" {
    yylval.token=A_Pos(line,col);
    col+=yyleng;
    c = yytext[0];
    //printf("* c: %c\n",c);
    return(c);
}
<INITIAL>[a-z_A-Z][a-z_A-Z0-9]* {
    char *s = String(yytext);
    //printf("* TokenID: %s\n", s);
    yylval.tokenId = A_TokenId(A_Pos(line,col), s);
    col+=yyleng; 
    return TOKEN_ID;
}
<INITIAL>[1-9][0-9]* {
    //printf("* %d\n", calculate(yytext,yyleng));
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
    //printf("Illegal input \"%c\"\n", yytext[0]);
}
%%


int calculate(char *s, int len) {
    int ret = 0;
    for(int i = 0; i < len; i++)
        ret = ret * 10 + (s[i] - '0');
    return ret;
}

char *checked_malloc(int len){
    char *p = (char *)malloc(len);
    if (!p) {
        fprintf(stderr,"\nRan out of memory!\n");
        exit(1);
    }
    return p;
}

string String(char *s){
    string p = checked_malloc(strlen(s)+3);
    strcpy(p,s);
    return p;
}