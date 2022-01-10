#pragma once

#include <libsolidity/ast/AST.h>
#include <libsolidity/ast/ASTVisitor.h>
#include <libsolidity/interface/OptimiserSettings.h>
#include <libsolidity/parsing/Parser.h>
#include <solc/CommandLineInterface.h>

#include <string>

#include "libwarp/common/library.hpp"

using namespace std;
using namespace solidity::frontend;
using namespace solidity;

string slurpFile(string_view path);

template <typename T>
using vec = vector<T>;

class WarpVisitor : public ASTConstVisitor {
   public:
    using ImportDirectives = vector<ImportDirective>;

    WarpVisitor(const string& main_contract, const string& src,
                const string& filepath, bool print_ir);

    bool visit(VariableDeclaration const& _node) override;
    bool visit(ImportDirective const& _node) override;
    bool visit(MemberAccess const& _node) override;
    bool visitNode(ASTNode const& node) override;

    WarpVisitor& yulPrepass();
    WarpVisitor& generateYulAST();

    string m_yulIR;
    string m_yul_JSON_AST;
    bool m_print_ir;

   private:
    void consolidateImports();
    void newCompiler();
    void refreshCompilerState(string filepath);
    void setCompilerOptions();
    void writeModifiedSolidity();
    void referencedSourceUnits(const SourceUnit& currSourceUnit);
    string cleanImportedFile(const string& src);
    string removeImportDirectives(string src);
    string removeComments(string src);
    OptimiserSettings optimizerSettings();
    CommandLineInterface getCli(char const* sol_filepath);

    shared_ptr<CompilerStack> m_compiler;
    CommandLineOptions m_options;
    FileReader m_fileReader;
    string m_filepath;
    string m_mainSourceUnit;
    string m_modifiedSourceUnit;
    string m_modifiedSolFilepath;
    string m_src;
    string m_srcOriginal;
    vec<string> m_contractNames;
    string m_modifiedContractName;
    string m_importStr;
    vec<string> m_orderedImportPaths;
    vec<string> m_importedFiles;
};
