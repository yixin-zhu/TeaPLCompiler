#include <fstream>
#include "TeaplAst.h"
#include "TeaplaAst.h"
#include "PrintTeaplaAst.h"
#include "y.tab.hpp"

// set YACCDEBUG 1 to turn on yydebug
#define YACCDEBUG 0

using namespace std;

extern int yyparse();
extern YYSTYPE yylval;
extern int yydebug;

int line, col;

A_program root;
aA_program aroot;

int main(int argc, char * argv[]) {

    #if YACCDEBUG
        yydebug = 1;
    #endif

    line = 1;
    col = 1;
    
    freopen(argv[1], "r", stdin);  
    ofstream ASTStream;
    ASTStream.open(argv[2]);
    printf("* Parsing...\n");
    while(!feof(stdin)){
        yyparse();
    }
    //yyparse();
    printf("* Parsing finished.\n");
    aroot = aA_Program(root);
    printf("* Printing AST...\n");
    print_aA_Program(aroot, ASTStream);
    printf("* Printing finished.\n");
    ASTStream.close();
    return 0;
}