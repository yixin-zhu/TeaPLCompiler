#include "TypeCheck.h"
#include "check.cpp"
#include "TypeCheck.h"

// maps to store the type information. Feel free to design new data structures if you need.
typeMap g_token2Type; // global token ids to type
typeMap funcparam_token2Type; // func params token ids to type
std::vector<typeMap> local_token2Type;

paramMemberMap func2Param;
paramMemberMap struct2Members;

// private util functions. You can use these functions to help you debug.
void error_print(std::ostream* out, A_pos p, string info)
{
    *out << "Typecheck error in line " << p->line << ", col " << p->col << ": " << info << std::endl;
    exit(0);
}

void print_token_map(typeMap* map){
    for(auto it = map->begin(); it != map->end(); it++){
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

aA_type find_token_global(string token){
    if(g_token2Type.empty() ){
        return nullptr;
    }
    if(g_token2Type.find(token) != g_token2Type.end()){
        return g_token2Type[token];
    }
    else{
        return nullptr;
    }
}

aA_type find_token_local(string token){
    if (local_token2Type.empty()){
        return nullptr;
    }
    if(local_token2Type.back().find(token) != local_token2Type.back().end()){
        return local_token2Type.back()[token];
    }
    else{
        return nullptr;
    }
}

// check functions
// ----------------------------------------------------------------------------------------

void checkVarDecl(std::ostream* out, aA_varDecl vd, int isGlobal){
    if(!vd)
        return;
    string id;
    aA_type type;
    if(vd->kind == A_varDeclType::A_varDeclScalarKind){
        id = *(vd->u.declScalar->id);
        type = vd->u.declScalar->type;
        if(find_token_global(id) != nullptr){
            error_print(out, vd->pos, "variable " + id + " has been declared");
        } 
        if (find_token_local(id)){
            error_print(out, vd->pos, "variable " + id + " has been declared");
        } 
    }
    else if (vd->kind == A_varDeclType::A_varDeclArrayKind){
        id = *(vd->u.declArray->id);
        type = vd->u.declArray->type;
        int len = vd->u.declArray->len;
        if(find_token_global(id)){
            error_print(out, vd->pos, "variable " + id + " has been declared");
        } 
        if (find_token_local(id)){
            error_print(out, vd->pos, "variable " + id + " has been declared");
        } 
        if(len <= 0){
            error_print(out, vd->pos, "array length must be positive");
        }
    }
   
    return;
}

void checkVarDeclStmt(std::ostream* out, aA_varDeclStmt vd, int isGlobal){
    if(!vd)
        return;
    aA_type type;
    if(vd -> kind == A_varDeclStmtType::A_varDeclKind){
        checkVarDecl(out, vd->u.varDecl, isGlobal);
        if(vd->u.varDecl->kind == A_varDeclType::A_varDeclScalarKind){
            type = vd->u.varDecl->u.declScalar->type;
        }
        else{
            type = vd->u.varDecl->u.declArray->type;
        }
    }
    else if (vd -> kind == A_varDeclStmtType::A_varDefKind){
        if(vd->u.varDef->kind == A_varDefType::A_varDefScalarKind){
            type = vd->u.varDef->u.defScalar->type;
        }
        else{
            type = vd->u.varDef->u.defArray->type;
        }
    }

    if(isGlobal){
        g_token2Type[*(vd->u.varDecl->u.declScalar->id)] = type;
    }
    else{
        local_token2Type.back()[*(vd->u.varDecl->u.declScalar->id)] = type;
    }
    return;
}


void checkProgramElement(std::ostream* out, aA_programElement ele){
    if(!ele)
        return;
    switch (ele->kind)
    {
        case A_programElementType::A_programVarDeclStmtKind:
            checkVarDeclStmt(out, ele->u.varDeclStmt, 1);
            break;
            

        default:
            break;
    }
    return;
}


// ----------------------------------------------------------------------------------------
// public functions
// This is the entrace of this file.
void check_Prog(std::ostream* out, aA_program p)
{
    local_token2Type.push_back(typeMap());
    // p is the root of AST tree.
    for (auto ele : p->programElements)
    {
    /*
        Write your code here.

        Hint: 
        1. Design the order of checking the program elements to meet the requirements that funtion declaration and global variable declaration can be used anywhere in the program.

        2. Many types of statements indeed collapse to some same units, so a good abstract design will help you reduce the amount of your code.
    */  checkProgramElement(out, ele);
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


void check_VarDecl(std::ostream* out, aA_varDeclStmt vd)
{
    // variable declaration statement 
    if (!vd)
        return;
    string name;
    if (vd->kind == A_varDeclStmtType::A_varDeclKind){
        // if declaration only 
        // Example:
        //   let a:int;
        //   let a[5]:int;
        
        /* write your code here*/
    }
    else if (vd->kind == A_varDeclStmtType::A_varDefKind){
        // if both declaration and initialization 
        // Example:
        //   let a:int = 5;
        
        /* write your code here */
    }
    return;
}


void check_StructDef(std::ostream* out, aA_structDef sd)
{
    if (!sd)
        return;
    // structure definition
    // Example:
    //      struct A{
    //          a:int;
    //          b:int;
    //      }
    
    /* write your code here */
    return;
}


void check_FnDecl(std::ostream* out, aA_fnDecl fd)
{
    // Example:
    //      fn main(a:int, b:int)->int
    if (!fd)
        return;
        
    /*  
        write your code here
        Hint: you may need to check if the function is already declared
    */
    return;
}


void check_FnDeclStmt(std::ostream* out, aA_fnDeclStmt fd)
{
    // Example:
    //      fn main(a:int, b:int)->int;
    if (!fd)
        return;
    check_FnDecl(out, fd->fnDecl);
    return;
}


void check_FnDef(std::ostream* out, aA_fnDef fd)
{
    // Example:
    //      fn main(a:int, b:int)->int{
    //          let c:int;
    //          c = a + b;
    //          return c;
    //      }
    if (!fd)
        return;
    check_FnDecl(out, fd->fnDecl);
    /*  
        write your code here 
        Hint: you may pay attention to the function parameters, local variables and global variables.
    */
    return;
}


void check_CodeblockStmt(std::ostream* out, aA_codeBlockStmt cs){
    if(!cs)
        return;
    switch (cs->kind)
    {
    case A_codeBlockStmtType::A_varDeclStmtKind:
        check_VarDecl(out, cs->u.varDeclStmt);
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
    return;
}


void check_AssignStmt(std::ostream* out, aA_assignStmt as){
    if(!as)
        return;
    string name;
    switch (as->leftVal->kind)
    {
        case A_leftValType::A_varValKind:{
            /* write your code here */
        }
            break;
        case A_leftValType::A_arrValKind:{
            /* write your code here */
        }
            break;
        case A_leftValType::A_memberValKind:{
            /* write your code here */
        }
            break;
    }
    return;
}


void check_ArrayExpr(std::ostream* out, aA_arrayExpr ae){
    if(!ae)
        return;
    /*
        Example:
            a[1] = 0;
        Hint:
            check the validity of the array index
    */
}


aA_type check_MemberExpr(std::ostream* out, aA_memberExpr me){
    // check if the member exists and return the tyep of the member
    // you may need to check if the type of this expression matches with its 
    // leftvalue or rightvalue, so return its aA_type would be a good way. Feel 
    // free to change the design pattern if you need.
    if(!me)
        return nullptr;
    /*
        Example:
            a.b
    */
    return nullptr;
}


void check_IfStmt(std::ostream* out, aA_ifStmt is){
    if(!is)
        return;
    check_BoolExpr(out, is->boolExpr);
    for(aA_codeBlockStmt s : is->ifStmts){
        check_CodeblockStmt(out, s);
    }
    for(aA_codeBlockStmt s : is->elseStmts){
        check_CodeblockStmt(out, s);
    }
    return;
}


void check_BoolExpr(std::ostream* out, aA_boolExpr be){
    if(!be)
        return;
    switch (be->kind)
    {
    case A_boolExprType::A_boolBiOpExprKind:
        /* write your code here */
        break;
    case A_boolExprType::A_boolUnitKind:
        check_BoolUnit(out, be->u.boolUnit);
        break;
    default:
        break;
    }
    return;
}


void check_BoolUnit(std::ostream* out, aA_boolUnit bu){
    if(!bu)
        return;
    switch (bu->kind)
    {
        case A_boolUnitType::A_comOpExprKind:{
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


aA_type check_ExprUnit(std::ostream* out, aA_exprUnit eu){
    // validate the expression unit and return the aA_type of it
    // you may need to check if the type of this expression matches with its 
    // leftvalue or rightvalue, so return its aA_type would be a good way. 
    // Feel free to change the design pattern if you need.
    if(!eu)
        return nullptr;
    aA_type ret;
    switch (eu->kind)
    {
        case A_exprUnitType::A_idExprKind:{
            /* write your code here */
        }
            break;
        case A_exprUnitType::A_numExprKind:{
            /* write your code here */
        }
            break;
        case A_exprUnitType::A_fnCallKind:{
            /* write your code here */
        }
            break;
        case A_exprUnitType::A_arrayExprKind:{
            /* write your code here */
        }
            break;
        case A_exprUnitType::A_memberExprKind:{
            /* write your code here */
        }
            break;
        case A_exprUnitType::A_arithExprKind:{
            /* write your code here */
        }
            break;
        case A_exprUnitType::A_arithUExprKind:{
            /* write your code here */
        }
            break;
    }
    return ret;
}


void check_FuncCall(std::ostream* out, aA_fnCall fc){
    if(!fc)
        return;
    // Example:
    //      foo(1, 2);

    /* write your code here */
    return ;
}


void check_WhileStmt(std::ostream* out, aA_whileStmt ws){
    if(!ws)
        return;
    check_BoolExpr(out, ws->boolExpr);
    for(aA_codeBlockStmt s : ws->whileStmts){
        check_CodeblockStmt(out, s);
    }
    return;
}


void check_CallStmt(std::ostream* out, aA_callStmt cs){
    if(!cs)
        return;
    check_FuncCall(out, cs->fnCall);
    return;
}


void check_ReturnStmt(std::ostream* out, aA_returnStmt rs){
    if(!rs)
        return;
    return;
}

