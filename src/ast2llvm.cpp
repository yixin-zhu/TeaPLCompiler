#include "ast2llvm.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <cassert>
#include <list>
#include <stack>

using namespace std;
using namespace LLVMIR;

static unordered_map<string, FuncType> funcReturnMap;
static unordered_map<string, StructInfo> structInfoMap;
static unordered_map<string, Name_name *> globalVarMap;
static unordered_map<string, Temp_temp *> localVarMap;
static list<L_stm *> emit_irs;
typedef struct While_Head
{
    bool isWhile;
    Temp_label *head_label;
    Temp_label *true_label;
    Temp_label *end_label;
} While_Head;
static stack<While_Head> while_head_stack;

LLVMIR::L_prog *ast2llvm(aA_program p)
{
    auto defs = ast2llvmProg_first(p);
    auto funcs = ast2llvmProg_second(p);
    vector<L_func *> funcs_block;
    for (const auto &f : funcs)
    {
        funcs_block.push_back(ast2llvmFuncBlock(f));
    }
    for (auto &f : funcs_block)
    {
        ast2llvm_moveAlloca(f);
    }
    return new L_prog(defs, funcs_block);
}

int ast2llvmRightVal_first(aA_rightVal r)
{
    if (r == nullptr)
    {
        return 0;
    }
    switch (r->kind)
    {
    case A_arithExprValKind:
    {
        return ast2llvmArithExpr_first(r->u.arithExpr);
        break;
    }
    case A_boolExprValKind:
    {
        return ast2llvmBoolExpr_first(r->u.boolExpr);
        break;
    }
    default:
        break;
    }
    return 0;
}

int ast2llvmBoolExpr_first(aA_boolExpr b)
{
    switch (b->kind)
    {
    case A_boolBiOpExprKind:
    {
        return ast2llvmBoolBiOpExpr_first(b->u.boolBiOpExpr);
        break;
    }
    case A_boolUnitKind:
    {
        return ast2llvmBoolUnit_first(b->u.boolUnit);
        break;
    }
    default:
        break;
    }
    return 0;
}

int ast2llvmBoolBiOpExpr_first(aA_boolBiOpExpr b)
{
    int l = ast2llvmBoolExpr_first(b->left);
    int r = ast2llvmBoolExpr_first(b->right);
    if (b->op == A_and)
    {
        return l && r;
    }
    else
    {
        return l || r;
    }
}

int ast2llvmBoolUOpExpr_first(aA_boolUOpExpr b)
{
    if (b->op == A_not)
    {
        return !ast2llvmBoolUnit_first(b->cond);
    }
    return 0;
}

int ast2llvmBoolUnit_first(aA_boolUnit b)
{
    switch (b->kind)
    {
    case A_comOpExprKind:
    {
        return ast2llvmComOpExpr_first(b->u.comExpr);
        break;
    }
    case A_boolExprKind:
    {
        return ast2llvmBoolExpr_first(b->u.boolExpr);
        break;
    }
    case A_boolUOpExprKind:
    {
        return ast2llvmBoolUOpExpr_first(b->u.boolUOpExpr);
        break;
    }
    default:
        break;
    }
    return 0;
}

int ast2llvmComOpExpr_first(aA_comExpr c)
{
    auto l = ast2llvmExprUnit_first(c->left);
    auto r = ast2llvmExprUnit_first(c->right);
    switch (c->op)
    {
    case A_lt:
    {
        return l < r;
        break;
    }
    case A_le:
    {
        return l <= r;
        break;
    }
    case A_gt:
    {
        return l > r;
        break;
    }
    case A_ge:
    {
        return l >= r;
        break;
    }
    case A_eq:
    {
        return l == r;
        break;
    }
    case A_ne:
    {
        return l != r;
        break;
    }
    default:
        break;
    }
    return 0;
}

int ast2llvmArithBiOpExpr_first(aA_arithBiOpExpr a)
{
    auto l = ast2llvmArithExpr_first(a->left);
    auto r = ast2llvmArithExpr_first(a->right);
    switch (a->op)
    {
    case A_add:
    {
        return l + r;
        break;
    }
    case A_sub:
    {
        return l - r;
        break;
    }
    case A_mul:
    {
        return l * r;
        break;
    }
    case A_div:
    {
        return l / r;
        break;
    }
    default:
        break;
    }
    return 0;
}

int ast2llvmArithUExpr_first(aA_arithUExpr a)
{
    if (a->op == A_neg)
    {
        return -ast2llvmExprUnit_first(a->expr);
    }
    return 0;
}

int ast2llvmArithExpr_first(aA_arithExpr a)
{
    switch (a->kind)
    {
    case A_arithBiOpExprKind:
    {
        return ast2llvmArithBiOpExpr_first(a->u.arithBiOpExpr);
        break;
    }
    case A_exprUnitKind:
    {
        return ast2llvmExprUnit_first(a->u.exprUnit);
        break;
    }
    default:
        assert(0);
        break;
    }
    return 0;
}

int ast2llvmExprUnit_first(aA_exprUnit e)
{
    if (e->kind == A_numExprKind)
    {
        return e->u.num;
    }
    else if (e->kind == A_arithExprKind)
    {
        return ast2llvmArithExpr_first(e->u.arithExpr);
    }
    else if (e->kind == A_arithUExprKind)
    {
        return ast2llvmArithUExpr_first(e->u.arithUExpr);
    }
    else
    {
        assert(0);
    }
    return 0;
}

std::vector<LLVMIR::L_def *> ast2llvmProg_first(aA_program p)
{
    vector<L_def *> defs;
    defs.push_back(L_Funcdecl("getch", vector<TempDef>(), FuncType(ReturnType::INT_TYPE)));
    defs.push_back(L_Funcdecl("getint", vector<TempDef>(), FuncType(ReturnType::INT_TYPE)));
    defs.push_back(L_Funcdecl("putch", vector<TempDef>{TempDef(TempType::INT_TEMP)}, FuncType(ReturnType::VOID_TYPE)));
    defs.push_back(L_Funcdecl("putint", vector<TempDef>{TempDef(TempType::INT_TEMP)}, FuncType(ReturnType::VOID_TYPE)));
    defs.push_back(L_Funcdecl("putarray", vector<TempDef>{TempDef(TempType::INT_TEMP), TempDef(TempType::INT_PTR, -1)}, FuncType(ReturnType::VOID_TYPE)));
    defs.push_back(L_Funcdecl("_sysy_starttime", vector<TempDef>{TempDef(TempType::INT_TEMP)}, FuncType(ReturnType::VOID_TYPE)));
    defs.push_back(L_Funcdecl("_sysy_stoptime", vector<TempDef>{TempDef(TempType::INT_TEMP)}, FuncType(ReturnType::VOID_TYPE)));
    for (const auto &v : p->programElements)
    {
        switch (v->kind)
        {
        case A_programNullStmtKind:
        {
            break;
        }
        case A_programVarDeclStmtKind:
        {
            if (v->u.varDeclStmt->kind == A_varDeclKind)
            {
                if (v->u.varDeclStmt->u.varDecl->kind == A_varDeclScalarKind)
                {
                    if (v->u.varDeclStmt->u.varDecl->u.declScalar->type->type == A_structTypeKind)
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDecl->u.declScalar->id,
                                             Name_newname_struct(Temp_newlabel_named(*v->u.varDeclStmt->u.varDecl->u.declScalar->id), *v->u.varDeclStmt->u.varDecl->u.declScalar->type->u.structType));
                        TempDef def(TempType::STRUCT_TEMP, 0, *v->u.varDeclStmt->u.varDecl->u.declScalar->type->u.structType);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDecl->u.declScalar->id, def, vector<int>()));
                    }
                    else
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDecl->u.declScalar->id,
                                             Name_newname_int(Temp_newlabel_named(*v->u.varDeclStmt->u.varDecl->u.declScalar->id)));
                        TempDef def(TempType::INT_TEMP, 0);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDecl->u.declScalar->id, def, vector<int>()));
                    }
                }
                else if (v->u.varDeclStmt->u.varDecl->kind == A_varDeclArrayKind)
                {
                    if (v->u.varDeclStmt->u.varDecl->u.declArray->type->type == A_structTypeKind)
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDecl->u.declArray->id,
                                             Name_newname_struct_ptr(Temp_newlabel_named(*v->u.varDeclStmt->u.varDecl->u.declArray->id), v->u.varDeclStmt->u.varDecl->u.declArray->len, *v->u.varDeclStmt->u.varDecl->u.declArray->type->u.structType));
                        TempDef def(TempType::STRUCT_PTR, v->u.varDeclStmt->u.varDecl->u.declArray->len, *v->u.varDeclStmt->u.varDecl->u.declArray->type->u.structType);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDecl->u.declArray->id, def, vector<int>()));
                    }
                    else
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDecl->u.declArray->id,
                                             Name_newname_int_ptr(Temp_newlabel_named(*v->u.varDeclStmt->u.varDecl->u.declArray->id), v->u.varDeclStmt->u.varDecl->u.declArray->len));
                        TempDef def(TempType::INT_PTR, v->u.varDeclStmt->u.varDecl->u.declArray->len);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDecl->u.declArray->id, def, vector<int>()));
                    }
                }
                else
                {
                    assert(0);
                }
            }
            else if (v->u.varDeclStmt->kind == A_varDefKind)
            {
                if (v->u.varDeclStmt->u.varDef->kind == A_varDefScalarKind)
                {
                    if (v->u.varDeclStmt->u.varDef->u.defScalar->type->type == A_structTypeKind)
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDef->u.defScalar->id,
                                             Name_newname_struct(Temp_newlabel_named(*v->u.varDeclStmt->u.varDef->u.defScalar->id), *v->u.varDeclStmt->u.varDef->u.defScalar->type->u.structType));
                        TempDef def(TempType::STRUCT_TEMP, 0, *v->u.varDeclStmt->u.varDef->u.defScalar->type->u.structType);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDef->u.defScalar->id, def, vector<int>()));
                    }
                    else
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDef->u.defScalar->id,
                                             Name_newname_int(Temp_newlabel_named(*v->u.varDeclStmt->u.varDef->u.defScalar->id)));
                        TempDef def(TempType::INT_TEMP, 0);
                        vector<int> init;
                        init.push_back(ast2llvmRightVal_first(v->u.varDeclStmt->u.varDef->u.defScalar->val));
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDef->u.defScalar->id, def, init));
                    }
                }
                else if (v->u.varDeclStmt->u.varDef->kind == A_varDefArrayKind)
                {
                    if (v->u.varDeclStmt->u.varDef->u.defArray->type->type == A_structTypeKind)
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDef->u.defArray->id,
                                             Name_newname_struct_ptr(Temp_newlabel_named(*v->u.varDeclStmt->u.varDef->u.defArray->id), v->u.varDeclStmt->u.varDef->u.defArray->len, *v->u.varDeclStmt->u.varDef->u.defArray->type->u.structType));
                        TempDef def(TempType::STRUCT_PTR, v->u.varDeclStmt->u.varDef->u.defArray->len, *v->u.varDeclStmt->u.varDef->u.defArray->type->u.structType);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDef->u.defArray->id, def, vector<int>()));
                    }
                    else
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDef->u.defArray->id,
                                             Name_newname_int_ptr(Temp_newlabel_named(*v->u.varDeclStmt->u.varDef->u.defArray->id), v->u.varDeclStmt->u.varDef->u.defArray->len));
                        TempDef def(TempType::INT_PTR, v->u.varDeclStmt->u.varDef->u.defArray->len);
                        vector<int> init;
                        for (auto &el : v->u.varDeclStmt->u.varDef->u.defArray->vals)
                        {
                            init.push_back(ast2llvmRightVal_first(el));
                        }
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDef->u.defArray->id, def, init));
                    }
                }
                else
                {
                    assert(0);
                }
            }
            else
            {
                assert(0);
            }
            break;
        }
        case A_programStructDefKind:
        {
            StructInfo si;
            int off = 0;
            vector<TempDef> members;
            for (const auto &decl : v->u.structDef->varDecls)
            {
                if (decl->kind == A_varDeclScalarKind)
                {
                    if (decl->u.declScalar->type->type == A_structTypeKind)
                    {
                        TempDef def(TempType::STRUCT_TEMP, 0, *decl->u.declScalar->type->u.structType);
                        MemberInfo info(off++, def);
                        si.memberinfos.emplace(*decl->u.declScalar->id, info);
                        members.push_back(def);
                    }
                    else
                    {
                        TempDef def(TempType::INT_TEMP, 0);
                        MemberInfo info(off++, def);
                        si.memberinfos.emplace(*decl->u.declScalar->id, info);
                        members.push_back(def);
                    }
                }
                else if (decl->kind == A_varDeclArrayKind)
                {
                    if (decl->u.declArray->type->type == A_structTypeKind)
                    {
                        TempDef def(TempType::STRUCT_PTR, decl->u.declArray->len, *decl->u.declArray->type->u.structType);
                        MemberInfo info(off++, def);
                        si.memberinfos.emplace(*decl->u.declArray->id, info);
                        members.push_back(def);
                    }
                    else
                    {
                        TempDef def(TempType::INT_PTR, decl->u.declArray->len);
                        MemberInfo info(off++, def);
                        si.memberinfos.emplace(*decl->u.declArray->id, info);
                        members.push_back(def);
                    }
                }
                else
                {
                    assert(0);
                }
            }
            structInfoMap.emplace(*v->u.structDef->id, std::move(si));
            defs.push_back(L_Structdef(*v->u.structDef->id, members));
            break;
        }
        case A_programFnDeclStmtKind:
        {
            FuncType type;
            if (v->u.fnDeclStmt->fnDecl->type == nullptr)
            {
                type.type = ReturnType::VOID_TYPE;
            }
            if (v->u.fnDeclStmt->fnDecl->type->type == A_nativeTypeKind)
            {
                type.type = ReturnType::INT_TYPE;
            }
            else if (v->u.fnDeclStmt->fnDecl->type->type == A_structTypeKind)
            {
                type.type = ReturnType::STRUCT_TYPE;
                type.structname = *v->u.fnDeclStmt->fnDecl->type->u.structType;
            }
            else
            {
                assert(0);
            }
            if (funcReturnMap.find(*v->u.fnDeclStmt->fnDecl->id) == funcReturnMap.end())
                funcReturnMap.emplace(*v->u.fnDeclStmt->fnDecl->id, std::move(type));
            vector<TempDef> args;
            for (const auto &decl : v->u.fnDeclStmt->fnDecl->paramDecl->varDecls)
            {
                if (decl->kind == A_varDeclScalarKind)
                {
                    if (decl->u.declScalar->type->type == A_structTypeKind)
                    {
                        TempDef def(TempType::STRUCT_PTR, 0, *decl->u.declScalar->type->u.structType);
                        args.push_back(def);
                    }
                    else
                    {
                        TempDef def(TempType::INT_TEMP, 0);
                        args.push_back(def);
                    }
                }
                else if (decl->kind == A_varDeclArrayKind)
                {
                    if (decl->u.declArray->type->type == A_structTypeKind)
                    {
                        TempDef def(TempType::STRUCT_PTR, -1, *decl->u.declArray->type->u.structType);
                        args.push_back(def);
                    }
                    else
                    {
                        TempDef def(TempType::INT_PTR, -1);
                        args.push_back(def);
                    }
                }
                else
                {
                    assert(0);
                }
            }
            defs.push_back(L_Funcdecl(*v->u.fnDeclStmt->fnDecl->id, args, type));
            break;
        }
        case A_programFnDefKind:
        {
            if (funcReturnMap.find(*v->u.fnDef->fnDecl->id) == funcReturnMap.end())
            {
                FuncType type;
                if (v->u.fnDef->fnDecl->type == nullptr)
                {
                    type.type = ReturnType::VOID_TYPE;
                }
                else if (v->u.fnDef->fnDecl->type->type == A_nativeTypeKind)
                {
                    type.type = ReturnType::INT_TYPE;
                }
                else if (v->u.fnDef->fnDecl->type->type == A_structTypeKind)
                {
                    type.type = ReturnType::STRUCT_TYPE;
                    type.structname = *v->u.fnDef->fnDecl->type->u.structType;
                }
                else
                {
                    assert(0);
                }
                funcReturnMap.emplace(*v->u.fnDef->fnDecl->id, std::move(type));
            }
            break;
        }
        default:
            assert(0);
            break;
        }
    }
    return defs;
}

std::vector<Func_local *> ast2llvmProg_second(aA_program p)
{
    vector<Func_local *> locals;
    for (const auto &v : p->programElements)
    {
        if (v->kind != A_programFnDefKind)
        {
            continue;
        }
        locals.push_back(ast2llvmFunc(v->u.fnDef));
    }
    return locals;
}

Func_local *ast2llvmFunc(aA_fnDef f)
{
    std::string name = get_Func_local_name(f->fnDecl);
    LLVMIR::FuncType ret = get_Func_local_ret(f->fnDecl);
    // clear local var map
    localVarMap.clear();
    std::vector<Temp_temp *> args = get_Func_local_args(f->fnDecl);
    // get irs
    emit_irs.clear();
    get_L_stm_list(f->stmts);
    std::list<LLVMIR::L_stm *> irs = std::list<LLVMIR::L_stm *>(emit_irs);
    Func_local *fl = (Func_local *)malloc(sizeof(Func_local));
    // get Func local
    *fl = Func_local(name, ret, args, irs);
    return fl;
}

std::string get_Func_local_name(aA_fnDecl fd)
{
    return *(fd->id);
}

std::vector<Temp_temp *> get_Func_local_args(aA_fnDecl fd)
{
    std::vector<Temp_temp *> args = std::vector<Temp_temp *>();
    for (auto varDecl : fd->paramDecl->varDecls)
    {
        args.push_back(get_Temp_temp_4_args(varDecl));
    }
    return args;
}

LLVMIR::FuncType get_Func_local_ret(aA_fnDecl fd)
{
    return (funcReturnMap.find(*fd->id)->second);
}
//get_Temp_temp
Temp_temp *get_Temp_temp_4_args(aA_varDecl vd)
{
    Temp_temp *temp;
    string *id;

    if (vd->kind == A_varDeclScalarKind)
    {
        if (vd->u.declScalar->type->type == A_nativeTypeKind)
        {
            temp = Temp_newtemp_int();
            id = vd->u.declScalar->id;
        }
        else if (vd->u.declScalar->type->type == A_structTypeKind)
        {
            temp = Temp_newtemp_struct(*(vd->u.declScalar->id));
            id = vd->u.declScalar->id;
        }
        else
        {
            assert(0);
        }
    }
    else if (vd->kind == A_varDeclArrayKind)
    {
        if (vd->u.declArray->type->type == A_nativeTypeKind)
        {
            temp = Temp_newtemp_int_ptr(vd->u.declArray->len);
            id = vd->u.declArray->id;
        }
        else if (vd->u.declArray->type->type == A_structTypeKind)
        {
            temp =  Temp_newtemp_struct_ptr(vd->u.declArray->len,
                                           *(vd->u.declArray->id));
            id = vd->u.declArray->id;
        }
        else
        {
            assert(0);
        }
    }
    else
    {
        assert(0);
    }
    localVarMap.insert({*id, temp});
    return temp;
}

void get_L_stm_list(vector<aA_codeBlockStmt> cbss)
{
    for (auto cbs : cbss)
    {
        get_L_stm(cbs);
    }
}

void get_L_stm(aA_codeBlockStmt cbs)
{
    switch (cbs->kind)
    {
    case A_nullStmtKind:
        break;
    case A_varDeclStmtKind:
        varDeclStmt2Lstm(cbs->u.varDeclStmt);
        break;
    case A_assignStmtKind:
        assignStmt2Lstm(cbs->u.assignStmt);
        break;
    case A_callStmtKind:
        callStmt2Lstm(cbs->u.callStmt);
        break;
    case A_ifStmtKind:
        ifStmt2Lstm(cbs->u.ifStmt);
        break;
    case A_whileStmtKind:
        whileStmt2Lstm(cbs->u.whileStmt);
        break;
    case A_returnStmtKind:
        returnStmt2Lstm(cbs->u.returnStmt);
        break;
    case A_continueStmtKind:
        continueStmt2Lstm();
        break;
    case A_breakStmtKind:
        breakStmt2Lstm();
        break;
    default:
        assert(0);
    }
    return;
}

void breakStmt2Lstm()
{
    Temp_label *label = while_head_stack.top().end_label;
    L_stm *jump = L_Jump(label);
    emit_irs.push_back(jump);
    return;
}

void continueStmt2Lstm()
{
    Temp_label *label = while_head_stack.top().true_label;
    L_stm *jump = L_Jump(label);
    emit_irs.push_back(jump);
    return;
}

void returnStmt2Lstm(aA_returnStmt rs)
{
    AS_operand *src = ast2llvmRightVal(rs->retVal);
    L_stm *ret_stm = L_Ret(src);
    emit_irs.push_back(ret_stm);
    return;
}

void varDeclStmt2Lstm(aA_varDeclStmt vds)
{
    switch (vds->kind)
    {
    case A_varDeclKind:
        varDecl2Lstm(vds->u.varDecl);
        break;
    case A_varDefKind:
        varDef2Lstm(vds->u.varDef);
        break;
    default:
        assert(0);
    }
    return;
}

void varDecl2Lstm(aA_varDecl vd)
{
    switch (vd->kind)
    {
    case A_varDeclScalarKind:
        if (vd->u.declScalar->type->type == A_nativeTypeKind)
        {
            Temp_temp *temp = Temp_newtemp_int();
            AS_operand *dst = AS_Operand_Temp(temp);
            L_stm *alloca = L_Alloca(dst);
            emit_irs.push_back(alloca);
            localVarMap.insert({*vd->u.declScalar->id, temp});
        }
        else if (vd->u.declScalar->type->type == A_structTypeKind)
        {
            Temp_temp *temp = Temp_newtemp_struct(*(vd->u.declScalar->type->u.structType));
            AS_operand *dst = AS_Operand_Temp(temp);
            L_stm *alloca = L_Alloca(dst);
            emit_irs.push_back(alloca);
            localVarMap.insert({*vd->u.declScalar->id, temp});
        }
        else
        {
            assert(0);
        }
        break;
    case A_varDeclArrayKind:
        if (vd->u.declArray->type->type == A_nativeTypeKind)
        {
            Temp_temp *temp = Temp_newtemp_int_ptr(vd->u.declArray->len);
            AS_operand *dst = AS_Operand_Temp(temp);
            L_stm *alloca = L_Alloca(dst);
            emit_irs.push_back(alloca);
            localVarMap.insert({*vd->u.declArray->id, temp});
        }
        else if (vd->u.declArray->type->type == A_structTypeKind)
        {
            Temp_temp *temp = Temp_newtemp_struct_ptr(vd->u.declArray->len,
                                                      *(vd->u.declArray->type->u.structType));
            AS_operand *dst = AS_Operand_Temp(temp);
            L_stm *alloca = L_Alloca(dst);
            emit_irs.push_back(alloca);
            localVarMap.insert({*vd->u.declArray->id, temp});
        }
        else
        {
            assert(0);
        }

        break;
    default:
        assert(0);
    }
    return;
}

void varDef2Lstm(aA_varDef vd)
{
    switch (vd->kind)
    {
    case A_varDefScalarKind:
        if (vd->u.defScalar->type->type == A_nativeTypeKind)
        {
            Temp_temp *temp = Temp_newtemp_int();
            AS_operand *dst = AS_Operand_Temp(temp);
            AS_operand *src = ast2llvmRightVal(vd->u.defScalar->val);
            L_stm *alloca = L_Alloca(dst);
            L_stm *store = L_Store(src, dst);
            emit_irs.push_back(alloca);
            emit_irs.push_back(store);
            localVarMap.emplace(*vd->u.defScalar->id, temp);
        }
        else if (vd->u.defScalar->type->type == A_structTypeKind)
        {
            Temp_temp *temp = Temp_newtemp_struct(*(vd->u.defScalar->type->u.structType));
            AS_operand *dst = AS_Operand_Temp(temp);
            AS_operand *src = ast2llvmRightVal(vd->u.defScalar->val);
            L_stm *alloca = L_Alloca(dst);
            L_stm *store = L_Store(src, dst);
            emit_irs.push_back(alloca);
            emit_irs.push_back(store);
            localVarMap.emplace(*vd->u.defScalar->id, temp);
        }
        else
        {
            assert(0);
        }
        break;
    case A_varDefArrayKind:
        if (vd->u.defArray->type->type == A_nativeTypeKind)
        {
            Temp_temp *temp = Temp_newtemp_int_ptr(vd->u.defArray->len);
            AS_operand *dst = AS_Operand_Temp(temp);
            AS_operand *src = ast2llvmRightVal(vd->u.defArray->vals[0]);
            L_stm *alloca = L_Alloca(dst);
            L_stm *store = L_Store(src, dst);
            emit_irs.push_back(alloca);
            emit_irs.push_back(store);
            localVarMap.insert({*vd->u.defArray->id, temp});
        }
        else if (vd->u.defArray->type->type == A_structTypeKind)
        {
            Temp_temp *temp = Temp_newtemp_struct_ptr(vd->u.defArray->len, *(vd->u.defArray->type->u.structType));
            AS_operand *dst = AS_Operand_Temp(temp);
            AS_operand *src = ast2llvmRightVal(vd->u.defArray->vals[0]);
            L_stm *alloca = L_Alloca(dst);
            L_stm *store = L_Store(src, dst);
            emit_irs.push_back(alloca);
            emit_irs.push_back(store);
            localVarMap.insert({*vd->u.defArray->id, temp});
        }
        else
        {
            assert(0);
        }
        break;
    default:
        assert(0);
    }
    return;
}

void assignStmt2Lstm(aA_assignStmt as)
{
    AS_operand *dst = ast2llvmLeftVal(as->leftVal);
    AS_operand *src = ast2llvmRightVal(as->rightVal);
    L_stm *store = L_Store(src, dst);
    emit_irs.push_back(store);
    return;
}

// can only return int
void callStmt2Lstm(aA_callStmt cs)
{
    AS_operand *res = AS_Operand_Temp(Temp_newtemp_int());
    vector<AS_operand *> args;
    for (aA_rightVal val : cs->fnCall->vals)
    {
        args.push_back(ast2llvmRightVal(val));
    }
    L_stm *call = L_Call(*(cs->fnCall->fn), res, args);
    emit_irs.push_back(call);
    return;
}

void ifStmt2Lstm(aA_ifStmt is)
{
    Temp_label *begin_label = Temp_newlabel();
    Temp_label *true_label = Temp_newlabel();
    Temp_label *false_label = Temp_newlabel();
    Temp_label *end_label = Temp_newlabel();
    emit_irs.push_back(L_Label(begin_label));
    // AS_operand* aso =
    ast2llvmBoolExpr(is->boolExpr, true_label, false_label);
    // L_stm* cjump = L_Cjump(aso, true_label, false_label);
    // emit_irs.push_back(cjump);

    emit_irs.push_back(L_Label(true_label));
    get_L_stm_list(is->ifStmts);
    L_stm *jump1 = L_Jump(end_label);
    emit_irs.push_back(jump1);
    emit_irs.push_back(L_Label(false_label));
    get_L_stm_list(is->elseStmts);
    L_stm *jump2 = L_Jump(end_label);
    emit_irs.push_back(jump2);
    emit_irs.push_back(L_Label(end_label));
    return;
}

void whileStmt2Lstm(aA_whileStmt ws)
{
    Temp_label *begin_label = Temp_newlabel();
    Temp_label *true_label = Temp_newlabel();
    Temp_label *end_label = Temp_newlabel();
    // head
    emit_irs.push_back(L_Label(begin_label));
    // AS_operand* aso =
    ast2llvmBoolExpr(ws->boolExpr, true_label, end_label);
    // L_stm* cjump = L_Cjump(aso, true_label, end_label);
    // emit_irs.push_back(cjump);
    while_head_stack.push({true, begin_label, true_label, end_label});
    // body
    emit_irs.push_back(L_Label(true_label));
    get_L_stm_list(ws->whileStmts);

    L_stm *jump_head = L_Jump(begin_label);
    L_stm *jump2 = L_Jump(end_label);

    emit_irs.push_back(jump_head);
    emit_irs.push_back(L_Label(end_label));
    while_head_stack.pop();
    return;
}

// todo: is this for while block only?
void ast2llvmBlock(aA_codeBlockStmt b, Temp_label *con_label, Temp_label *bre_label)
{
}

/*
typedef enum {
    A_arithExprValKind,
    A_boolExprValKind
} A_rightValType;
*/
AS_operand *ast2llvmRightVal(aA_rightVal r)
{
    switch (r->kind)
    {
    case A_arithExprValKind:
    {
        return ast2llvmArithExpr(r->u.arithExpr);
        break;  
    }
    case A_boolExprValKind:
    {
        Temp_label*  true_lebel = Temp_newlabel();
        Temp_label*  false_lebel = Temp_newlabel();
        ast2llvmBoolExpr(r->u.boolExpr, true_lebel, false_lebel);
        AS_operand* res = AS_Operand_Temp(Temp_newtemp_int());
        emit_irs.push_back(L_Label(true_lebel));
        emit_irs.push_back(L_Load(AS_Operand_Const(1), res));
        emit_irs.push_back(L_Label(false_lebel));
        emit_irs.push_back(L_Load(AS_Operand_Const(0), res));
        return res;
    }
    default:
        assert(0);
    }
    return nullptr;
}

/*
typedef enum {
    A_varValKind,
    A_arrValKind,
    A_memberValKind
} A_leftValType;
union {
        string* id;
        aA_arrayExpr arrExpr;
        aA_memberExpr memberExpr;
    } u;
*/
AS_operand *ast2llvmLeftVal(aA_leftVal l)
{
    AS_operand *temp;
    switch (l->kind)
    {
    case A_varValKind: //a, b, arr1, mystruct1
    {
        temp = ast2llvmIdExpr(l->u.id);
        break;
    }
    case A_arrValKind: // a[10]
    {
        temp = ast2llvmArrayExpr(l->u.arrExpr);
        break;
    }
    case A_memberValKind:
    {
        temp = ast2llvmMemberExpr(l->u.memberExpr);
        break;
    }
    default:
        assert(0);
    }
    return temp;
}

/*
typedef enum {
    A_numIndexKind,
    A_idIndexKind
} A_indexExprKind;
int num
string *id
*/
AS_operand *ast2llvmIndexExpr(aA_indexExpr index)
{
    switch (index->kind)
    {
    case A_numIndexKind:
    {
        return AS_Operand_Const(index->u.num);
    }
    case A_idIndexKind://a[b] --> idx.id = b --> b' val
    {
        return ast2llvmIdExpr(index->u.id);
    }
    default:
        assert(0);
    }
    return nullptr;
}

AS_operand *ast2llvmBoolExpr(aA_boolExpr b, Temp_label *true_label, Temp_label *false_label)
{
    switch (b->kind)
    {
    case A_boolBiOpExprKind:
        ast2llvmBoolBiOpExpr(b->u.boolBiOpExpr, true_label, false_label);
    case A_boolUnitKind:
        ast2llvmBoolUnit(b->u.boolUnit, true_label, false_label);
    default:
        assert(0);
    }
    return nullptr;
}

void ast2llvmBoolBiOpExpr(aA_boolBiOpExpr b, Temp_label *true_label, Temp_label *false_label)
{
    aA_boolExpr left = b->left;
    aA_boolExpr right = b->right;
    Temp_label *middle = Temp_newlabel();

    switch (b->op)
    {
    case A_and:
    {
        ast2llvmBoolExpr(left, middle, false_label);
        emit_irs.push_back(L_Label(middle));
        ast2llvmBoolExpr(right, true_label, false_label);
    }
    case A_or:
    {
        ast2llvmBoolExpr(left, true_label, middle);
        emit_irs.push_back(L_Label(middle));
        ast2llvmBoolExpr(right, true_label, false_label);
    }
    default:
        assert(0);
    }
}

/*
typedef enum {
    A_comOpExprKind,
    A_boolExprKind,
    A_boolUOpExprKind
} A_boolUnitType;
*/
void ast2llvmBoolUnit(aA_boolUnit b, Temp_label *true_label, Temp_label *false_label)
{
    switch (b->kind)
    {
    case A_comOpExprKind:
    {
        ast2llvmComOpExpr(b->u.comExpr, true_label, false_label);
        break;
    }
    case A_boolExprKind:
    {
        ast2llvmBoolExpr(b->u.boolExpr, true_label, false_label);
        break;
    }
    case A_boolUOpExprKind:
    {
        ast2llvmBoolUOpExpr(b->u.boolUOpExpr, true_label, false_label);
        break;
    }
    default:
        assert(0);
    }
}

void ast2llvmComOpExpr(aA_comExpr c, Temp_label *true_label, Temp_label *false_label)
{
    aA_exprUnit left = c->left;
    aA_exprUnit right = c->right;
    AS_operand *l = ast2llvmExprUnit(left);
    AS_operand *r = ast2llvmExprUnit(right);
    AS_operand *dst;
    switch (c->op){
        case A_lt:
            emit_irs.push_back(L_Cmp(L_relopKind::T_lt, l, r, dst));
        case A_le:
            emit_irs.push_back(L_Cmp(L_relopKind::T_le, l, r, dst));
        case A_gt:
            emit_irs.push_back(L_Cmp(L_relopKind::T_gt, l, r, dst));
        case A_ge:
            emit_irs.push_back(L_Cmp(L_relopKind::T_ge, l, r, dst));
        case A_eq:
            emit_irs.push_back(L_Cmp(L_relopKind::T_eq, l, r, dst));
        case A_ne:
            emit_irs.push_back(L_Cmp(L_relopKind::T_ne, l, r, dst));
        default:
            assert(0);
    }
    emit_irs.push_back(L_Cjump(dst, true_label, false_label));
}

void ast2llvmBoolUOpExpr(aA_boolUOpExpr b,Temp_label *true_label,Temp_label *false_label)
{
    switch (b->op)
    {
    case A_not:
    {
        ast2llvmBoolUnit(b->cond, false_label, true_label);
        break;
    }
    default:
        assert(0);
    }
}

AS_operand *ast2llvmArithBiOpExpr(aA_arithBiOpExpr a)
{
    AS_operand *left = ast2llvmArithExpr(a->left);
    AS_operand *right = ast2llvmArithExpr(a->right);
    AS_operand *dst = AS_Operand_Temp(Temp_newtemp_int());
    switch (a->op)
    {
    case A_add:
    {
        emit_irs.push_back(L_Binop(L_binopKind::T_plus, left, right, dst));
        break;
    }
    case A_sub:
    {
        emit_irs.push_back(L_Binop(L_binopKind::T_minus, left, right, dst));
        break;
    }
    case A_mul:
    {
        emit_irs.push_back(L_Binop(L_binopKind::T_mul, left, right, dst));
        break;
    }
    case A_div:
    {
        emit_irs.push_back(L_Binop(L_binopKind::T_div, left, right, dst));
        break;
    }
    default:
        assert(0);
    }
    return dst;
}

AS_operand *ast2llvmArithUExpr(aA_arithUExpr a)
{
    AS_operand *src = ast2llvmExprUnit(a->expr);
    AS_operand *dst = AS_Operand_Temp(Temp_newtemp_int());
    switch (a->op)
    {
    case A_neg:
    {
        emit_irs.push_back(L_Binop(L_binopKind::T_minus, AS_Operand_Const(0), src, dst));
        break;
    }
    default:
        assert(0);
    }
    return dst;
}

/*
typedef enum {
    A_arithBiOpExprKind,
    A_exprUnitKind
} A_arithExprType;
*/
AS_operand *ast2llvmArithExpr(aA_arithExpr a)
{
    switch (a->kind)
    {
        case A_arithBiOpExprKind:
        {
            return ast2llvmArithBiOpExpr(a->u.arithBiOpExpr);
            break;
        }
        case A_exprUnitKind:
        {
            return ast2llvmExprUnit(a->u.exprUnit);
            break;
        }
        default:
            assert(0);
            break;
    }
}

/*
typedef enum {
    A_numExprKind,
    A_idExprKind,
    A_arithExprKind,
    A_fnCallKind,
    A_arrayExprKind,
    A_memberExprKind,
    A_arithUExprKind
} A_exprUnitType;
        int num;
        string* id;
        aA_arithExpr arithExpr;
        aA_fnCall callExpr;
        aA_arrayExpr arrayExpr;
        aA_memberExpr memberExpr;
        aA_arithUExpr arithUExpr;
*/
AS_operand *ast2llvmNumExpr(int num)
{
    return AS_Operand_Const(num);
}
//id
AS_operand *ast2llvmIdExpr(string *id)
{
    if (localVarMap.find(*id) != localVarMap.end())
    {
        return AS_Operand_Temp(localVarMap.find(*id)->second);
    }
    else if (globalVarMap.find(*id) != globalVarMap.end())
    {
        return AS_Operand_Name(globalVarMap.find(*id)->second);
    }
    else
    {
        assert(0);
    }
}

AS_operand *ast2llvmFnCall(aA_fnCall f)
{
    vector<AS_operand *> args;
    for (aA_rightVal val : f->vals)
    {
        args.push_back(ast2llvmRightVal(val));
    }
    AS_operand *res = AS_Operand_Temp(Temp_newtemp_int());
    L_stm *call = L_Call(*(f->fn), res, args);
    emit_irs.push_back(call);
    return res;
}

//a[1].b.c[3]
/*
struct aA_arrayExpr_ {
    A_pos pos;
    aA_leftVal arr;
    aA_indexExpr idx;
};
*/
AS_operand *ast2llvmArrayExpr(aA_arrayExpr a)
{
    AS_operand *base = ast2llvmLeftVal(a->arr);
    AS_operand *index = ast2llvmIndexExpr(a->idx);
    AS_operand *dst = AS_Operand_Temp(Temp_newtemp_int());
    L_stm *load = L_Gep(dst, base, index);
    emit_irs.push_back(load);
    return dst;
}
int getStructMemberOffset(string structId, string membername)
{
    StructInfo si = structInfoMap.find(structId)->second;
    MemberInfo mi = si.memberinfos.find(membername)->second;
    return mi.offset;
}

/*
a.b[10]
struct aA_memberExpr_ {
    A_pos pos;
    aA_leftVal structId;
    string* memberId;
};
*/
AS_operand *ast2llvmMemberExpr(aA_memberExpr m)
{
    AS_operand *base = ast2llvmLeftVal(m->structId);
    string* member_id = m->memberId;
    // struct name 
    string structId;
    if (base->kind == OperandKind::TEMP)
    {
        structId = base->u.TEMP->structname;
    }
    else if (base->kind == OperandKind::NAME)
    {
        structId = base->u.NAME->structname;
    }
    else
    {
        assert(0);
    }
    int offset = getStructMemberOffset(structId, *member_id);
    AS_operand *dst = AS_Operand_Temp(Temp_newtemp_int());
    L_stm *load = L_Gep(dst, base, AS_Operand_Const(offset));
    emit_irs.push_back(load);
    return dst;
}

AS_operand *ast2llvmExprUnit(aA_exprUnit e)
{
    switch (e->kind) {
        case A_numExprKind:
        {
            return ast2llvmNumExpr(e->u.num);
            break;
        }
        case A_idExprKind:
        {
            return ast2llvmIdExpr(e->u.id);
            break;
        }
        case A_arithExprKind:
        {
            return ast2llvmArithExpr(e->u.arithExpr);
            break;
        }
        case A_fnCallKind:
        {
            return ast2llvmFnCall(e->u.callExpr);
            break;
        }
        case A_arrayExprKind:
        {
            return ast2llvmArrayExpr(e->u.arrayExpr);
            break;
        }
        case A_memberExprKind:
        {
            return ast2llvmMemberExpr(e->u.memberExpr);
            break;
        }
        case A_arithUExprKind:
        {
            return ast2llvmArithUExpr(e->u.arithUExpr);
            break;
        }
        default:
            assert(0);
            break;
    }
}
//todo
LLVMIR::L_func *ast2llvmFuncBlock(Func_local *f)
{
}
//todo
void ast2llvm_moveAlloca(LLVMIR::L_func *f)
{
}