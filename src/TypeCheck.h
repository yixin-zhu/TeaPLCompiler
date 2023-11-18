#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include "TeaplAst.h"
#include "TeaplaAst.h"
#include <unordered_map>

typedef enum param_level
{
    global,
    local,
    funcparam,
    temp
} param_level;

typedef enum member_map_type
{
    struct_,
    func
} member_map_type;

typedef enum fun_decl_type
{
    decl,
    def
} fun_decl_type;
// you can use this type to store the type a token.
typedef std::unordered_map<string, aA_type> typeMap; 
typedef std::unordered_map<string, int> lengthMap;
typedef std::unordered_map<string, A_pos> posMap;
typedef std::unordered_map<string, int> boolMap;
// you can use this map to store the members of a struct or params of a function.
typedef std::unordered_map<string, vector<aA_varDecl>*> paramMemberMap;

void check_Prog(std::ostream* out, aA_program p);
void check_VarDecl(std::ostream* out, aA_varDecl vd, param_level level);
void check_StructDef(std::ostream* out, aA_structDef sd, param_level level);
void check_FnDecl(std::ostream* out, aA_fnDecl fd, fun_decl_type fun_decl_type);
void check_FnDeclStmt(std::ostream* out, aA_fnDeclStmt fd, param_level level);
void check_FnDef(std::ostream* out, aA_fnDef fd);
void check_CodeblockStmt(std::ostream* out, aA_codeBlockStmt cs, param_level level);
void check_AssignStmt(std::ostream* out, aA_assignStmt as, param_level level);
aA_type check_MemberExpr(std::ostream* out, aA_memberExpr me, param_level level, int & arr_len);
void check_IfStmt(std::ostream* out, aA_ifStmt is);
void check_BoolUnit(std::ostream* out, aA_boolUnit bu, param_level level);
aA_type check_ExprUnit(std::ostream* out, aA_exprUnit eu, param_level level);
aA_type check_FuncCall(std::ostream* out, aA_fnCall fc);
void check_WhileStmt(std::ostream* out, aA_whileStmt ws);
void check_CallStmt(std::ostream* out, aA_callStmt cs);
void check_ReturnStmt(std::ostream* out, aA_returnStmt rs, param_level level);
void check_VarDeclStmt(std::ostream *out, aA_varDeclStmt vd, param_level level);
void check_VarDef(std::ostream *out, aA_varDef vd, param_level level);
void check_RightVal(std::ostream *out, aA_rightVal rv, param_level level, const aA_type leftType);
aA_type check_ArithExpr(std::ostream *out, aA_arithExpr ar, param_level level);
void check_type_comparable(std::ostream *out, aA_type leftType, aA_type rightType, A_pos pos);
void check_BoolExpr(std::ostream *out, aA_boolExpr bo, param_level level);
aA_type check_ArrayExpr(std::ostream *out, aA_arrayExpr ae, param_level level);
aA_type check_struct_and_member_exists(std::ostream *out, A_pos pos, aA_type struct_type, string member_id);
void check_struct_exist(std::ostream *out, A_pos pos, aA_type struct_type);
aA_type get_type_of(aA_varDecl vd);
int get_arr_len(string id, param_level level);