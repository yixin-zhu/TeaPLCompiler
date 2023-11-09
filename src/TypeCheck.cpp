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

// maps to store the type information. Feel free to design new data structures if you need.
typeMap g_token2Type; // global token ids to type
typeMap f_token2Type; // func params token ids to type
typeMap l_token2Type; // local params token ids to type
typeMap t_token2Type; // temporary token ids to type

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
    bool is_duplicate = false;
    switch (checked_level)
    {
    global:
        is_duplicate = find_token_global(id) != nullptr;
        break;
    local:
        is_duplicate = (find_token_local(id) != nullptr) || (find_token_global(id) != nullptr) || (find_token_funcparam(id) != nullptr);
        break;
    default:
        break;
    }
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
// todo check the type of the expression
void check_ProgramElement(std::ostream *out, aA_programElement ele, param_level level = global)
{
    if (!ele)
        return;
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
// todo: check local
void check_Prog(std::ostream *out, aA_program p)
{
    // p is the root of AST tree.
    for (auto ele : p->programElements)
    {
        check_ProgramElement(out, ele, global);
    }

    for (auto ele : p->programElements)
    {
    }

    for (auto ele : p->programElements)
    {
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
        // todo: record array length
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
    if (!rv)
        return;
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

void check_member_exists(std::ostream *out, A_pos pos, string struct_id, string member_id) {
    //todo
}
// todo
aA_type get_member_type(string struct_id, string member_id) {
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
    add_param_list_to_map(out, fd->fnDecl->paramDecl->varDecls);
    // clear stack
    recover_local_variables(0);
    int before = 0;
    // clear local map
    for (auto stmt : fd->stmts)
    {
        check_CodeblockStmt(out, stmt, local);
    }
    // clear mapping of func params and local variables
    recover_local_variables(before);
    return;
}

void check_CodeblockStmt(std::ostream *out, aA_codeBlockStmt cs, param_level level = local)
{
    if (!cs)
        return;
    int before = l_token_stack.size();
    switch (cs->kind)
    {
    case A_codeBlockStmtType::A_varDeclStmtKind:
        check_VarDeclStmt(out, cs->u.varDeclStmt, local);
        break;
    case A_codeBlockStmtType::A_assignStmtKind:
        check_AssignStmt(out, cs->u.assignStmt);
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
        check_ReturnStmt(out, cs->u.returnStmt);
        break;
    default:
        break;
    }
    recover_local_variables(before);
    return;
}

void check_token_exist(std::ostream *out, aA_type type, string id, A_pos pos)
{
    if (type == nullptr)
    {
        error_print(out, pos, "variable " + id + " not defined");
    }
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
        type = find_token(id, level);
        check_token_exist(out, type, id, lv->pos);
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
        aA_type type = find_token(index_id, level);
        check_token_exist(out, type, index_id, in->pos);
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
aA_type check_ArrayExpr(std::ostream *out, aA_arrayExpr ae, param_level level)
{
    if (!ae)
        return;
    string id = *(ae->arr);
    // check array exists
    aA_type type = find_token(id, level);
    // check array index within range
    aA_indexExpr indexExp = ae->idx;
    // todo: int arr_len = get_arr_len(id, level);
    int arr_len = 0;
    check_IndexExpr(out, indexExp, level, arr_len);
    // return the type of the array
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
    // check struct exists
    check_struct_exist(out, me->pos, struct_id);
    // check member exists
    check_member_exists(out, me->pos, struct_id, member_id);
    return get_member_type(struct_id, member_id);
}
// todo
void check_IfStmt(std::ostream *out, aA_ifStmt is)
{
    if (!is)
        return;
    check_BoolExpr(out, is->boolExpr);
    for (aA_codeBlockStmt s : is->ifStmts)
    {
        check_CodeblockStmt(out, s, local);
    }
    for (aA_codeBlockStmt s : is->elseStmts)
    {
        check_CodeblockStmt(out, s, local);
    }
    return;
}
// huge todo
void check_BoolUnit(std::ostream *out, aA_boolUnit bu, param_level level)
{
    if (!bu)
        return;
    switch (bu->kind)
    {
    case A_boolUnitType::A_comOpExprKind:
    {
        /* write your code here */
    }
    break;
    case A_boolUnitType::A_boolExprKind:
        /* write your code here */
        break;
    case A_boolUnitType::A_boolUOpExprKind:
        /* write your code here */
        break;
    default:
        break;
    }
    return;
}
// huge todo
aA_type check_ExprUnit(std::ostream *out, aA_exprUnit eu, param_level level)
{
    // validate the expression unit and return the aA_type of it
    // you may need to check if the type of this expression matches with its
    // leftvalue or rightvalue, so return its aA_type would be a good way.
    // Feel free to change the design pattern if you need.
    if (!eu)
        return nullptr;
    aA_type ret;
    switch (eu->kind)
    {
    case A_exprUnitType::A_idExprKind:
    {
        /* write your code here */
    }
    break;
    case A_exprUnitType::A_numExprKind:
    {
        /* write your code here */
    }
    break;
    case A_exprUnitType::A_fnCallKind:
    {
        /* write your code here */
    }
    break;
    case A_exprUnitType::A_arrayExprKind:
    {
        /* write your code here */
    }
    break;
    case A_exprUnitType::A_memberExprKind:
    {
        /* write your code here */
    }
    break;
    case A_exprUnitType::A_arithExprKind:
    {
        /* write your code here */
    }
    break;
    case A_exprUnitType::A_arithUExprKind:
    {
        /* write your code here */
    }
    break;
    }
    return ret;
}
// todo
void check_FuncCall(std::ostream *out, aA_fnCall fc)
{
    if (!fc)
        return;
    // Example:
    //      foo(1, 2);

    /* write your code here */
    return;
}
// todo
void check_WhileStmt(std::ostream *out, aA_whileStmt ws)
{
    if (!ws)
        return;
    check_BoolExpr(out, ws->boolExpr);
    for (aA_codeBlockStmt s : ws->whileStmts)
    {
        check_CodeblockStmt(out, s, local);
    }
    return;
}
// todo
void check_CallStmt(std::ostream *out, aA_callStmt cs)
{
    if (!cs)
        return;
    check_FuncCall(out, cs->fnCall);
    return;
}
// todo
void check_ReturnStmt(std::ostream *out, aA_returnStmt rs)
{
    if (!rs)
        return;
    return;
}
