#include "YulVisitor.hpp"

#include <liblangutil/CharStream.h>
#include <liblangutil/CharStreamProvider.h>
#include <liblangutil/SourceReferenceFormatter.h>
#include <libsolutil/StringUtils.h>
#include <libsolutil/Whiskers.h>
#include <libyul/Utilities.h>
#include <tools/yulPhaser/Program.h>

#include <fstream>

YulVisitor::YulVisitor(string src, string warpConstructorSelector,
                       string warpConstructorName)
    : m_src(src),
      m_constructorSelector(warpConstructorSelector),
      m_constructorName(warpConstructorName) {
    m_dynamicArgsInConstructor =
        (warpConstructorName.find("_DynArgs") != string::npos);
    m_currentPass = PassType::CaseRemoval;
}

void YulVisitor::printSrcAtLocation(langutil::SourceLocation loc) {
    cout << loc << endl;
}

template <class T>
void YulVisitor::visitVectorOfVariants(const vector<T>& _vec) {
    for (auto const& var : _vec) visit(*this, var);
}

void YulVisitor::writeModifiedYul() {
    fstream solFile;
    solFile.open("YUL_PASS", ios::out | ios::trunc);
    solFile << m_src;
    solFile.close();
}

void YulVisitor::refreshYulAST() {
    solidity::langutil::CharStream ir = langutil::CharStream(m_src, "YUL_PASS");
    variant<phaser::Program, langutil::ErrorList> maybeProgram =
        phaser::Program::load(ir);

    if (auto* errorList = get_if<langutil::ErrorList>(&maybeProgram)) {
        langutil::SingletonCharStreamProvider streamProvider{ir};
        langutil::SourceReferenceFormatter{cerr, streamProvider, true, false}
            .printErrorInformation(*errorList);
        cerr << endl;
    }
    auto program = get<phaser::Program>(maybeProgram);
    (*this)(program.ast());
}

void YulVisitor::operator()(const yul::Block& _node) {
    visitVectorOfVariants(_node.statements);
}

void YulVisitor::operator()(const yul::TypedName& _node) {}

void YulVisitor::operator()(const yul::Literal& _node) {}

void YulVisitor::operator()(const yul::Identifier& _node) {}

void YulVisitor::operator()(const yul::Assignment& _node) {
    for (auto const& var : _node.variableNames) (*this)(var);
    if (_node.value) visit(*this, *_node.value);
}

void YulVisitor::operator()(const yul::VariableDeclaration& _node) {
    if (m_currentPass == PassType::AddrCleanerRemoval) {
        auto declr =
            string(m_src.begin() + _node.debugData->nativeLocation.start,
                   m_src.begin() + _node.debugData->nativeLocation.end);
        m_prevDeclr = m_currentDeclr;
        m_prevDeclrLocation[1] = m_currentDeclr[1];
        m_prevDeclrLocation[0] = m_currDeclrLocation[0];
        m_prevDeclrLocation[1] = m_currDeclrLocation[1];
        m_currentDeclr = declr;
        m_currDeclrLocation[0] = _node.debugData->nativeLocation.start;
        m_currDeclrLocation[1] = _node.debugData->nativeLocation.end;
        if (declr.find(":= and(") != string::npos and
            m_prevDeclr.find(":= sub(shl(160, 1), 1)") != string::npos) {
            if (_node.value) {
                const yul::FunctionCall funcCall =
                    get<yul::FunctionCall>(move(*(_node.value)));
                try {
                    const yul::Identifier ident =
                        get<yul::Identifier>(funcCall.arguments[0]);
                    auto assignStr = _node.variables[0].name.str();
                    auto assignStrClean =
                        string(assignStr.begin(),
                               assignStr.begin() + assignStr.find_last_of('_'));
                    string newDeclr =
                        "let " + assignStrClean + " := " + ident.name.str();
                    m_src.erase(m_src.begin() + m_prevDeclrLocation[0],
                                m_src.begin() + m_currDeclrLocation[1]);
                    m_src.insert(m_prevDeclrLocation[0], newDeclr);
                    m_src = yul::reindent(m_src);
                    writeModifiedYul();
                    m_currentPass = PassType::AddrCleanerRemoval;
                    refreshYulAST();
                } catch (...) {
                    cout << "ERRRROOOOR" << endl;
                }
            }
        }
    }
    for (auto const& var : _node.variables) (*this)(var);

    if (_node.value) visit(*this, *_node.value);
}

void YulVisitor::operator()(const yul::FunctionDefinition& _node) {
    m_inEntryFunction = _node.name.str() == "fun_ENTRY_POINT";
    m_currentFunction = _node.name.str();

    if (m_currentFunction == m_constructorName and
        m_currentPass == PassType::Constructor and m_dynamicArgsInConstructor) {
        string constructorPrelude =
            dynamicEntrySeq + "\n" + m_deletedCase.value();
        util::Whiskers templ(R"(
            function fun_warp_constructor_DynArgs()
            {
<body>
            }
)");
        templ("body", constructorPrelude);
        string warpCtor = templ.render();
        int start = _node.debugData->nativeLocation.start;
        m_src.insert(start, warpCtor);
        m_src = yul::reindent(m_src);
        writeModifiedYul();
        m_currentPass = PassType::Skip;
        refreshYulAST();
    }
    for (auto const& var : _node.parameters) (*this)(var);
    for (auto const& var : _node.returnVariables) (*this)(var);
    (*this)(_node.body);
}

void YulVisitor::operator()(const yul::FunctionCall& _node) {
    (*this)(_node.functionName);
    visitVectorOfVariants(_node.arguments);
}

void YulVisitor::operator()(const yul::If& _node) {
    visit(*this, *_node.condition);
    (*this)(_node.body);
}

void YulVisitor::operator()(const yul::Switch& _node) {
    visit(*this, *_node.expression);
    for (auto const& var : _node.cases) (*this)(var);
}

void YulVisitor::operator()(const yul::Case& _node) {
    if (_node.value) {
        if (_node.value->value.str() == m_constructorSelector and
            m_currentPass == PassType::CaseRemoval) {
            m_deletedCase = string(
                m_src.begin() + _node.body.debugData->nativeLocation.start + 1,
                m_src.begin() + _node.body.debugData->nativeLocation.end - 1);
            m_src.erase(m_src.begin() + _node.debugData->nativeLocation.start,
                        m_src.begin() + _node.debugData->nativeLocation.end);
            m_currentPass = PassType::Constructor;
            writeModifiedYul();
            refreshYulAST();
        }
        (*this)(*_node.value);
    }
    (*this)(_node.body);
}

void YulVisitor::operator()(const yul::ForLoop& _node) {
    (*this)(_node.pre);
    (*this)(_node.post);
    (*this)(_node.body);
}

void YulVisitor::operator()(const yul::Break& _node) {}

void YulVisitor::operator()(const yul::Continue& _node) {}

void YulVisitor::operator()(const yul::Leave& _node) {}

void YulVisitor::operator()(const yul::ExpressionStatement& _node) {
    visit(*this, _node.expression);
}
