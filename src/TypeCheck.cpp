#include "TypeCheck.h"
#include "check.cpp"
#include "TypeCheck.h"
#include <stack>
#include <stdlib.h>
using namespace std;
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

// maps to store the type information.  
typeMap g_token2Type; // global token ids to type
typeMap f_token2Type; // func params token ids to type
typeMap l_token2Type; // local params token ids to type
typeMap t_token2Type; // temporary token ids to type

lengthMap array2len[4]; // array token ids to length
posMap func2pos;    // function token ids to declaration position
boolMap func2state; // function token ids to state: 0 for non-defined, 1 for has-defined
stack<string> l_token_stack;

paramMemberMap func2Param;
paramMemberMap struct2Members;

// private util functions. You can use these functions to help you debug.
void error_print(std::ostream *out, A_pos p, string info)
{
    *out << "Typecheck error in line " << p->line << ", col " << p->col << ": " << info << std::endl;
    exit(0);
}

void print_token_map(typeMap *map)
{
    for (auto it = map->begin(); it != map->end(); it++)
    {
        switch (it->second->type)
        {
        case A_dataType::A_nativeTypeKind:
            switch (it->second->u.nativeType)
            {
            case A_nativeType::A_intTypeKind:
                break;
            default:
                break;
            }
            break;
        case A_dataType::A_structTypeKind:
            break;
        default:
            break;
        }
    }
}

bool token_exist_at(string token, typeMap *map)
{
    return (map->find(token) != map->end());
}

bool token_exist_global(string token) {
    return token_exist_at(token, &g_token2Type);
}

bool token_exist_local(string token) {
    return token_exist_at(token, &l_token2Type);
}

bool token_exist_funcparam(string token) {
    return token_exist_at(token, &f_token2Type);
}

bool token_exist_temp(string token) {
    return token_exist_at(token, &t_token2Type);
}

aA_type find_token_at(string token, typeMap *map)
{
    if (map->empty())
    {
        return nullptr;
    }
    return (map->find(token) != map->end()) ? (*map)[token] : nullptr;
}

aA_type find_token_global(string token)
{
    return find_token_at(token, &g_token2Type);
}

aA_type find_token_local(string token)
{
    return find_token_at(token, &l_token2Type);
}

aA_type find_token_funcparam(string token)
{
    return find_token_at(token, &f_token2Type);
}

bool token_exist(string token, param_level level) {
    switch (level)
    {
    case global:
        return token_exist_global(token);
    case local:
        return token_exist_local(token) || token_exist_funcparam(token) || token_exist_global(token);
    case funcparam:
        return token_exist_funcparam(token);
    case temp:
        return token_exist_temp(token);
    default:
        return false;
    }
}

void check_token_exist(std::ostream *out, string token, A_pos pos, param_level level)
{
    if (!token_exist(token, level))
    {
        error_print(out, pos, "variable " + token + " not defined");
    }
}

aA_type find_token(string token, param_level level)
{
    aA_type type = nullptr;
    switch (level)
    {
    case global:
        return find_token_global(token);
    case local:
        type = find_token_local(token);
        if (!type)
        {
            type = find_token_funcparam(token);
        }
        if (!type)
        {
            type = find_token_global(token);
        }
        return type;
    case funcparam:
        return find_token_funcparam(token);
    default:
        return nullptr;
    }
    return type;
}

void add_token_global(string token, aA_type type)
{
    g_token2Type[token] = type;
}

void add_token_local(string token, aA_type type)
{
    l_token2Type[token] = type;
}

void add_token_funcparam(string token, aA_type type)
{
    f_token2Type[token] = type;
}

void add_token(string token, aA_type type, param_level level)
{
    switch (level)
    {
    case global:
        add_token_global(token, type);
        break;
    case local:
        add_token_local(token, type);
        l_token_stack.push(token);
        break;
    case funcparam:
        add_token_funcparam(token, type);
        break;
    default:
        break;
    }
}

void add_memberMap(string token, vector<aA_varDecl> *members, member_map_type level)
{
    switch (level)
    {
    case struct_:
        struct2Members[token] = members;
        break;
    case func:
        func2Param[token] = members;
        break;
    default:
        break;
    }
}

void check_duplicate(std::ostream *out, param_level checked_level, string id, A_pos pos)
{
    bool is_duplicate = token_exist(id, checked_level);
    if (is_duplicate)
    {
        error_print(out, pos, "variable " + id + " has been declared");
    }
}

void check_len_positive(std::ostream *out, int len, A_pos pos)
{
    if (len <= 0)
    {
        error_print(out, pos, "array length must be positive");
    }
}

// check functions
// ----------------------------------------------------------------------------------------
void check_ProgramElement(std::ostream *out, aA_programElement ele, int round = 0)
{
    if (!ele)
        return;
    
    if ((round == 0 && ele->kind == A_programFnDefKind) || 
        (round == 1 && ele->kind != A_programFnDefKind)){
        return;
    }

    switch (ele->kind)
    {
    case A_programElementType::A_programVarDeclStmtKind:
        check_VarDeclStmt(out, ele->u.varDeclStmt, global);
        break;
    case A_programElementType::A_programStructDefKind:
        check_StructDef(out, ele->u.structDef, global);
        break;
    case A_programElementType::A_programFnDeclStmtKind:
        check_FnDeclStmt(out, ele->u.fnDeclStmt, global);
        break;
    case A_programElementType::A_programFnDefKind:
        check_FnDef(out, ele->u.fnDef);
        break;
    default:
        break;
    }
    return;
}
// ----------------------------------------------------------------------------------------
// public functions
// This is the entrace of this file.
// round 0: add all global definitions except function definitions
// round 1: check all function definitions
void check_Prog(std::ostream *out, aA_program p)
{
    // p is the root of AST tree.
    for (auto ele : p->programElements)
    {
        check_ProgramElement(out, ele, 0);
    }

    for (auto ele : p->programElements)
    {
        check_ProgramElement(out, ele, 1);
    }

    (*out) << "Typecheck passed!" << std::endl;
    return;
}

void check_VarDeclStmt(std::ostream *out, aA_varDeclStmt vd, param_level level)
{
    // variable declaration statement
    if (!vd)
        return;
    if (vd->kind == A_varDeclStmtType::A_varDeclKind)
    {
        check_VarDecl(out, vd->u.varDecl, level);
    }
    else if (vd->kind == A_varDeclStmtType::A_varDefKind)
    {
        check_VarDef(out, vd->u.varDef, level);
    }
    return;
}

void add_array_length_record(string id, int len, param_level level)
{
    array2len[level][id] = len;
}
// declaration only
// let a:int;
// let a[5]:int;
void check_VarDecl(std::ostream *out, aA_varDecl vd, param_level level)
{
    if (!vd)
        return;
    string id;
    aA_type type;
    switch (vd->kind)
    {
    case A_varDeclType::A_varDeclScalarKind:
        id = *(vd->u.declScalar->id);
        type = vd->u.declScalar->type;
        check_duplicate(out, level, id, vd->pos);
        break;
    case A_varDeclType::A_varDeclArrayKind:
        id = *(vd->u.declArray->id);
        type = vd->u.declArray->type;
        int len = vd->u.declArray->len;
        check_duplicate(out, level, id, vd->pos);
        check_len_positive(out, len, vd->pos);
        add_array_length_record(id, len, level);
        break;
    default:
        break;
    }
    // add to map
    add_token(id, type, level);
    return;
}

// both declaration and initialization
// let a:int = 5;
void check_VarDef(std::ostream *out, aA_varDef vd, param_level level)
{
    if (!vd)
        return;
    string id;
    aA_type type;
    if (vd->kind == A_varDefType::A_varDefScalarKind)
    {
        id = *(vd->u.defScalar->id);
        type = vd->u.defScalar->type;
        check_duplicate(out, level, id, vd->pos);
    }
    else if (vd->kind == A_varDefType::A_varDefArrayKind)
    {
        id = *(vd->u.defArray->id);
        type = vd->u.defArray->type;
        int len = vd->u.defArray->len;
        vector<aA_rightVal> vals = vd->u.defArray->vals;
        check_duplicate(out, level, id, vd->pos);
        check_len_positive(out, len, vd->pos);
        if (len != vals.size())
        {
            error_print(out, vd->pos, "array length must be equal to the number of initializers");
        }
        for (auto val : vals)
        {
            check_RightVal(out, val, level, type);
        }
    }
    // add to map
    add_token(id, type, level);
    return;
}
aA_type check_ArithBiOpExpr(std::ostream *out, aA_arithBiOpExpr bi, param_level level)
{
    if (!bi)
        return;
    aA_type leftType = check_ArithExpr(out, bi->left, level);
    aA_type rightType = check_ArithExpr(out, bi->right, level);
    check_type_comparable(out, leftType, rightType, bi->pos);
    return leftType;
}

aA_type check_ArithExpr(std::ostream *out, aA_arithExpr ar, param_level level)
{
    if (!ar)
        return nullptr;
    switch (ar->kind)
    {
    case A_arithBiOpExprKind:
        aA_arithBiOpExpr bi = ar->u.arithBiOpExpr;
        return check_ArithBiOpExpr(out, bi, level);
        break;
    case A_exprUnitKind:
        aA_exprUnit eu = ar->u.exprUnit;
        return check_ExprUnit(out, eu, level);
        break;
    default:
        break;
    }
    return nullptr;
}

void check_BoolBiOpExpr(std::ostream *out, aA_boolBiOpExpr bi, param_level level)
{
    if (!bi)
        return;
    check_BoolExpr(out, bi->left, level);
    check_BoolExpr(out, bi->right, level);
    return;
}

void check_BoolExpr(std::ostream *out, aA_boolExpr bo, param_level level)
{
    if (!bo)
        return;
    switch (bo->kind)
    {
    case A_boolBiOpExprKind:
        aA_boolBiOpExpr bi = bo->u.boolBiOpExpr;
        check_BoolBiOpExpr(out, bi, level);
        break;
    case A_boolUnitKind:
        aA_boolUnit bu = bo->u.boolUnit;
        check_BoolUnit(out, bu, level);
        break;
    default:
        break;
    }
    return;
}

void check_type_comparable(std::ostream *out, aA_type leftType, aA_type rightType, A_pos pos)
{
    if (leftType == nullptr || rightType == nullptr)
    {
        error_print(out, pos, "type not defined!");
    }
    if (leftType->type != rightType->type)
    {
        error_print(out, pos, "type not comparable!");
    }
    if (leftType->type == A_dataType::A_nativeTypeKind)
    {
        if (leftType->u.nativeType != rightType->u.nativeType)
        {
            error_print(out, pos, "type not comparable!");
        }
    }
    else
    {
        if (*(leftType->u.structType) != *(rightType->u.structType))
        {
            error_print(out, pos, "type not comparable!");
        }
    }
    return;
}

void check_comparable_with_bool(std::ostream *out, aA_type type, A_pos pos)
{
    if (type == nullptr)
    {
        error_print(out, pos, "type not defined!");
    }
    if (type->type != A_dataType::A_nativeTypeKind)
    {
        error_print(out, pos, "type not comparable!");
    }
}

void check_RightVal(std::ostream *out, aA_rightVal rv, param_level level, const aA_type leftType)
{
    if (!rv) {
        if (!leftType) {
            return;
        } else {
            error_print(out, rv->pos, "Right value missing!");
        }
    }
        
    aA_type rightType = nullptr;
    switch (rv->kind)
    {
    case A_rightValType::A_arithExprValKind:
        rightType = check_ArithExpr(out, rv->u.arithExpr, level);
        check_type_comparable(out, leftType, rightType, rv->pos);
        break;
    case A_rightValType::A_boolExprValKind:
        check_BoolExpr(out, rv->u.boolExpr, level);
        check_comparable_with_bool(out, leftType, rv->pos);
        break;
    default:
        break;
    }

    return;
}

// structure definition
//      struct A{
//          a:int;
//          b:int;
//      }
void check_varDecls(std::ostream *out, std::vector<aA_varDecl> varDecls)
{
    t_token2Type.clear();
    for (auto vd : varDecls)
    {
        check_VarDecl(out, vd, temp);
    }
}

void check_StructDef(std::ostream *out, aA_structDef sd, param_level level)
{
    if (!sd)
        return;
    string id = *(sd->id);
    A_pos pos = sd->pos;
    check_duplicate(out, level, id, pos);
    check_varDecls(out, sd->varDecls);
    // add to map
    add_memberMap(id, &(sd->varDecls), struct_);
    return;
}

void check_struct_exist(std::ostream *out, A_pos pos, string name)
{
    if (struct2Members.find(name) == struct2Members.end())
    {
        error_print(out, pos, "type not defined!");
    }
}
// struct member can't have same name
aA_type check_struct_and_member_exists(std::ostream *out, A_pos pos, string struct_id, string member_id) {
    check_struct_exist(out, pos, struct_id);
    vector<aA_varDecl> member_decl = *struct2Members[struct_id];
    string id;
    aA_type type;
    for (auto member_exp: member_decl) {
        if (member_exp->kind == A_varDeclType::A_varDeclScalarKind) {
            id = *(member_exp->u.declScalar->id);
            type = member_exp->u.declScalar->type;
        } else if (member_exp->kind == A_varDeclType::A_varDeclArrayKind) {
            id = *(member_exp->u.declArray->id);
            type = member_exp->u.declArray->type;
        }
        if (id == member_id) {
            return type;
        }
    }
    //can't find matching member
    error_print(out, pos, struct_id + ":member " + member_id + " not defined!");
    return nullptr;
}

void check_type_exist(std::ostream *out, aA_type type)
{
    if (type->type == A_dataType::A_nativeTypeKind)
    {
        return;
    }
    // check struct type exists
    A_pos pos = type->pos;
    string struct_type_name = *(type->u.structType);
    check_struct_exist(out, pos, struct_type_name);
}

// todo: [unimplemented] declare then define
//  fn main(a:int, b:int)->int
void check_FnDecl(std::ostream *out, aA_fnDecl fd)
{
    if (!fd)
        return;
    string id = *(fd->id);
    A_pos pos = fd->pos;
    // check function is duplicated declared
    check_duplicate(out, global, id, pos);
    // check function parameters
    check_varDecls(out, fd->paramDecl->varDecls);
    // check function return type
    aA_type type = fd->type;
    check_type_exist(out, type);
    // add to global map
    add_token(id, type, global);
    // add params to map
    add_memberMap(id, &(fd->paramDecl->varDecls), func);
    return;
}

// fn main(a:int, b:int)->int;
void check_FnDeclStmt(std::ostream *out, aA_fnDeclStmt fd, param_level level = global)
{
    if (!fd)
        return;
    check_FnDecl(out, fd->fnDecl);
    return;
}

void add_param_list_to_map(std::ostream *out, std::vector<aA_varDecl> varDecls)
{
    f_token2Type.clear();
    for (auto vd : varDecls)
    {
        add_token(*(vd->u.declScalar->id), vd->u.declScalar->type, funcparam);
    }
}

void recover_local_variables(int remain)
{
    while (l_token_stack.size() > remain)
    {
        l_token2Type.erase(l_token_stack.top());
        l_token_stack.pop();
    }
}

// Example:
//      fn main(a:int, b:int)->int{
//          let c:int;
//          c = a + b;
//          return c;
//      }
/*
        Hint: you may pay attention to the function parameters, local variables and global variables.
*/
void check_FnDef(std::ostream *out, aA_fnDef fd)
{
    if (!fd)
        return;
    check_FnDecl(out, fd->fnDecl);
    aA_type type = fd->fnDecl->type;
    add_param_list_to_map(out, fd->fnDecl->paramDecl->varDecls);
    // clear stack
    recover_local_variables(0);
    int before = 0;
    // clear local map
    for (auto stmt : fd->stmts)
    {
        check_CodeblockStmt(out, stmt, local, type);
    }
    // clear mapping of func params and local variables
    recover_local_variables(before);
    return;
}

void check_CodeblockStmt(std::ostream *out, aA_codeBlockStmt cs, param_level level = local, aA_type func_type = nullptr)
{
    if (!cs)
        return;
    switch (cs->kind)
    {
    case A_codeBlockStmtType::A_varDeclStmtKind:
        check_VarDeclStmt(out, cs->u.varDeclStmt, local);
        break;
    case A_codeBlockStmtType::A_assignStmtKind:
        check_AssignStmt(out, cs->u.assignStmt, local);
        break;
    case A_codeBlockStmtType::A_ifStmtKind:
        check_IfStmt(out, cs->u.ifStmt);
        break;
    case A_codeBlockStmtType::A_whileStmtKind:
        check_WhileStmt(out, cs->u.whileStmt);
        break;
    case A_codeBlockStmtType::A_callStmtKind:
        check_CallStmt(out, cs->u.callStmt);
        break;
    case A_codeBlockStmtType::A_returnStmtKind:
        check_ReturnStmt(out, cs->u.returnStmt, local, func_type);
        break;
    default:
        break;
    }
    return;
}


aA_type check_LeftVal(std::ostream *out, aA_leftVal lv, param_level level)
{
    if (!lv)
        return nullptr;
    aA_type type = nullptr;
    switch (lv->kind)
    {
    case A_leftValType::A_varValKind:
    {
        string id = *(lv->u.id);
        
    }
    break;
    case A_leftValType::A_arrValKind:
    {
        aA_arrayExpr arrExpr = lv->u.arrExpr;
        type = check_ArrayExpr(out, arrExpr, level);
    }
    break;
    case A_leftValType::A_memberValKind:
    {
        aA_memberExpr memberExpr = lv->u.memberExpr;
        type = check_MemberExpr(out, memberExpr, level);
    }
    break;
    }
    return type;
}

void check_AssignStmt(std::ostream *out, aA_assignStmt as, param_level level)
{
    if (!as)
        return;
    string name;
    aA_type leftType = check_LeftVal(out, as->leftVal, level);
    check_RightVal(out, as->rightVal, level, leftType);
    return;
}

void check_index_out_of_range(std::ostream *out, A_pos pos, int index, int len)
{
    if (index < 0 || index >= len)
        error_print(out, pos, "array index out of range");
}
void check_type_is_int(std::ostream *out, aA_type type, A_pos pos)
{
    if (type->type != A_dataType::A_nativeTypeKind || type->u.nativeType != A_nativeType::A_intTypeKind)
    {
        error_print(out, pos, "array index must be int");
    }
}

void check_IndexExpr(std::ostream *out, aA_indexExpr in, param_level level, int arr_len)
{
    if (!in)
        return;
    switch (in->kind)
    {
    case A_numIndexKind:
    {
        int index = in->u.num;
        check_index_out_of_range(out, in->pos, index, arr_len);
        break;
    }
    case A_idIndexKind:
    {
        string index_id = *(in->u.id);
        check_token_exist(out, index_id, in->pos, level);
        aA_type type = find_token(index_id, level);
        check_type_is_int(out, type, in->pos);
        break;
    }
    default:
        break;
    }
    return;
}
/*
Example:
    a[1] = 0;
Hint:
    check the validity of the array index
*/

int get_arr_len(string id, param_level level)
{
    if (level == global) {
        return array2len[global][id]; 
    } else if (level == local) {
        if (array2len[local].find(id) != array2len[local].end()) {
            return array2len[local][id];
        } else if (array2len[funcparam].find(id) != array2len[funcparam].end()) {
            return array2len[funcparam][id];
        } else {
            return array2len[global][id];
        }
    }
    return 0;
}

aA_type check_ArrayExpr(std::ostream *out, aA_arrayExpr ae, param_level level)
{
    if (!ae)
        return;
    string id = *(ae->arr);
    // check array exists
    check_token_exist(out, id, ae->pos, level);
    // check array index within range
    aA_indexExpr indexExp = ae->idx;
    int arr_len = get_arr_len(id, level);
    check_IndexExpr(out, indexExp, level, arr_len);
    // return the type of the array
    aA_type type = find_token(id, level);
    return type;
}

/*
    Example:
        a.b
*/
// check if the member exists and return the tyep of the member
// you may need to check if the type of this expression matches with its
// leftvalue or rightvalue, so return its aA_type would be a good way. Feel
// free to change the design pattern if you need.
aA_type check_MemberExpr(std::ostream *out, aA_memberExpr me, param_level level)
{
    if (!me)
        return nullptr;
    string struct_id = *(me->structId);
    string member_id = *(me->memberId);
    // check struct and member exists
    aA_type member_type = check_struct_and_member_exists(out, me->pos, struct_id, member_id);
    return member_type;
}

void check_IfStmt(std::ostream *out, aA_ifStmt is)
{
    if (!is)
        return;
    check_BoolExpr(out, is->boolExpr);
    int before = l_token_stack.size();
    for (aA_codeBlockStmt s : is->ifStmts)
    {
        check_CodeblockStmt(out, s, local);
    }
    recover_local_variables(before);
    for (aA_codeBlockStmt s : is->elseStmts)
    {
        check_CodeblockStmt(out, s, local);
    }
    recover_local_variables(before);
    return;
}

// bool unit 和 bool expr 共轭了，直到某一方为null时结束
// 疑惑点：为什么没有id型bool unit
void check_BoolUnit(std::ostream *out, aA_boolUnit bu, param_level level)
{
    if (!bu)
        return;
    switch (bu->kind)
    {
    case A_boolUnitType::A_comOpExprKind:
    {
        aA_comExpr comExpr = bu->u.comExpr;
        aA_type leftType = check_ExprUnit(out, comExpr->left, level);
        aA_type rightType = check_ExprUnit(out, comExpr->right, level);
        check_type_comparable(out, leftType, rightType, comExpr->pos);
    }
    break;

    case A_boolUnitType::A_boolExprKind:
        aA_boolExpr boolExpr = bu->u.boolExpr;
        check_BoolExpr(out, boolExpr, level);
        break;

    case A_boolUnitType::A_boolUOpExprKind:
        aA_boolUnit boolUnit = bu->u.boolUOpExpr->cond;
        check_BoolUnit(out, boolUnit, level);
        break;
    default:
        break;
    }
    return;
}

// validate the expression unit and return the aA_type of it
aA_type check_ExprUnit(std::ostream *out, aA_exprUnit eu, param_level level)
{
    
    if (!eu)
        return nullptr;
    aA_type ret;
    switch (eu->kind)
    {
    case A_exprUnitType::A_idExprKind:
    {
        string id = *(eu->u.id);
        check_token_exist(out, id, eu->pos, level);
        ret = find_token(id, level);
    }
    break;
    case A_exprUnitType::A_numExprKind:
    {
        ret->pos = eu->pos;
        ret->type = A_dataType::A_nativeTypeKind;
        ret->u.nativeType = A_nativeType::A_intTypeKind;
    }
    break;
    case A_exprUnitType::A_fnCallKind:
    {
        aA_fnCall fnCall = eu->u.callExpr;
        ret = check_FuncCall(out, fnCall);
    }
    break;
    case A_exprUnitType::A_arrayExprKind:
    {
        aA_arrayExpr arrayExpr = eu->u.arrayExpr;
        ret = check_ArrayExpr(out, arrayExpr, level);
    }
    break;
    case A_exprUnitType::A_memberExprKind:
    {
        aA_memberExpr memberExpr = eu->u.memberExpr;
        ret = check_MemberExpr(out, memberExpr, level);
    }
    break;
    case A_exprUnitType::A_arithExprKind:
    {
        aA_arithExpr arithExpr = eu->u.arithExpr;
        ret = check_ArithExpr(out, arithExpr, level);
    }
    break;
    case A_exprUnitType::A_arithUExprKind:
    {
        aA_arithUExpr arithUExpr = eu->u.arithUExpr;
        ret = check_ExprUnit(out, arithUExpr->expr, level);
    }
    break;
    }
    return ret;
}

// Example:
//      foo(1, 2);
aA_type check_FuncCall(std::ostream *out, aA_fnCall fc)
{
    if (!fc)
        return;
    //check function exist
    check_token_exist(out, *(fc->fn), fc->pos, global);
    //check params match with function params [quantity and type]
    vector<aA_rightVal> vals = fc->vals;
    vector<aA_varDecl> *params = func2Param[*(fc->fn)];
    if (vals.size() != params->size())
    {
        error_print(out, fc->pos, "function " + *(fc->fn) + " params not match");
    }
    for (int i = 0; i < vals.size(); i++)
    {
        check_RightVal(out, vals[i], local, (*params)[i]->u.declScalar->type);
    }
    return find_token_global(*(fc->fn));
}

void check_WhileStmt(std::ostream *out, aA_whileStmt ws)
{
    if (!ws)
        return;
    check_BoolExpr(out, ws->boolExpr);
    int before = l_token_stack.size();
    for (aA_codeBlockStmt s : ws->whileStmts)
    {
        check_CodeblockStmt(out, s, local);
    }
    recover_local_variables(before);
    return;
}

void check_CallStmt(std::ostream *out, aA_callStmt cs)
{
    if (!cs)
        return;
    check_FuncCall(out, cs->fnCall);
    return;
}

void check_ReturnStmt(std::ostream *out, aA_returnStmt rs, param_level level, aA_type func_type)
{
    if (!rs)
        return;
    //check return type match with function return type
    aA_type type = nullptr;
    check_RightVal(out, rs->retVal, level, func_type);
    return;
}
