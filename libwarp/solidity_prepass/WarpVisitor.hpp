#pragma once

#include <libsolidity/ast/AST.h>
#include <libsolidity/ast/ASTVisitor.h>
#include <libsolidity/interface/OptimiserSettings.h>
#include <libsolidity/parsing/Parser.h>
#include <solc/CommandLineInterface.h>

#include <string>

#include "libwarp/solidity_prepass/SolidityModifier.hpp"
#include "libwarp/yul_prepass/YulCleaner.hpp"

using namespace solidity::frontend;
using namespace solidity;

std::string slurpFile(std::string_view path);

struct MarkedFunctions {
    std::vector<std::string> names;
    std::vector<std::string> selectors;
    std::vector<std::vector<Type const*>> parameters;
};

class WarpVisitor : public ASTConstVisitor {
   public:
    enum class PassType {
        ConstructorPass,
        FunctionCallPass,
        FunctionDefinitionPass,
        StorageVarPass,
        StorageFunctionPass,
    };

    WarpVisitor(std::string main_contract, std::string src,
                std::string filepath, bool print_ir);

    std::string getSaferYul();
    std::string yulJSON_AST() { return m_yul_JSON_AST; };
    bool visit(FunctionCall const& _node) override;
    bool visit(FunctionDefinition const& _node) override;
    bool visit(Identifier const& _node) override;
    bool visit(VariableDeclaration const& _node) override;
    bool visitNode(ASTNode const& node) override;

    WarpVisitor& constrcutorPass(const char* solFilepath);
    WarpVisitor& yul();
    WarpVisitor& yulPrepass();
    WarpVisitor& generateYulIR();
    WarpVisitor& generateYulAST();

    bool m_print_ir;

   private:
    bool isPublic(Visibility _visibility);
    bool hasDynamicArgs(std::string params);
    bool checkTypeEqaulity(std::vector<Type const*> const& t1,
                           std::vector<Type const*> t2);
    void generateWarpConstructor();
    FunctionDefinition const* resolveFunctionCall(const ContractDefinition& c,
                                                  FunctionCall const& f);
    FunctionDefinition const* insideWhichFunction(
        langutil::SourceLocation const& location);
    void getInheritedConstructorCalls(
        std::vector<ASTPointer<ModifierInvocation>> const& modifiers);

    std::vector<std::string> m_storageVars;
    std::vector<std::string> m_hashNames;
    MarkedFunctions m_dynArgFunctions;
    SolidityModifier m_solModifier;
    SolidityModifierState* m_solState = &m_solModifier.state;

    bool m_willGenerateConstructor = false;
    std::string m_yulIR;
    std::string m_yul_JSON_AST;
    std::string m_mainContract;
    std::string m_modifiedContractName;
    std::string m_warpConstructor;
    std::string m_warpConstructorName;
    std::string m_warpConstructorSelector;
    std::string m_warpConstructorSig;
    PassType m_currentPass;
};
