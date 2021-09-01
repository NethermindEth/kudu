#include <fstream>
#include <iostream>

#include <liblangutil/CharStream.h>
#include <liblangutil/ErrorReporter.h>
#include <libsolidity/ast/AST.h>
#include <libsolidity/ast/ASTVisitor.h>
#include <libsolidity/parsing/Parser.h>

#include "library.h"

using namespace std;
using namespace solidity;

string slurpFile(string_view path)
{
	constexpr size_t BUF_SIZE = 4096;

	string result;
	ifstream is{path.data()};
	is.exceptions(ifstream::badbit);
	string buf(BUF_SIZE, '\0');
	while (is.read(buf.data(), BUF_SIZE))
		result.append(buf, 0, is.gcount());
	result.append(buf, 0, is.gcount());

	return result;
}

class ASTStatistics: public frontend::ASTConstVisitor
{
public:
	[[nodiscard]] unsigned nodesCounted() const { return m_nodesCount; }
	[[nodiscard]] unsigned variableDeclarationsCounted() const { return m_varDeclsCount; }
	[[nodiscard]] unsigned functionDeclarationsCounted() const { return m_funDeclsCount; }
	[[nodiscard]] unsigned maximumMappingNestedness() const { return m_maxMappingNestedness; }

	bool visit(frontend::VariableDeclaration const& _node) override
	{
		++m_varDeclsCount;
		return visitNode(_node);
	}

	bool visit(frontend::FunctionDefinition const& _node) override
	{
		++m_funDeclsCount;
		return visitNode(_node);
	}

	bool visit(frontend::Mapping const& _node) override
	{
		++m_mappingNestedness;
		m_maxMappingNestedness = max(m_mappingNestedness, m_maxMappingNestedness);
		return visitNode(_node);
	}

	void endVisit(frontend::Mapping const& _node) override
	{
		--m_mappingNestedness;
		endVisitNode(_node);
	}

protected:
	bool visitNode(frontend::ASTNode const& node) override
	{
		++m_nodesCount;
		return frontend::ASTConstVisitor::visitNode(node);
	}

private:
	unsigned m_nodesCount = 0;
	unsigned m_varDeclsCount = 0;
	unsigned m_funDeclsCount = 0;
	unsigned m_mappingNestedness = 0;
	unsigned m_maxMappingNestedness = 0;
};

int main(int argc, char* argv[])
{
	hello();

	if (argc != 2)
	{
		cerr << "USAGE: " << argv[0] << " SOLIDITY_CONTRACT" << endl;
		return 1;
	}

	string contractPath = argv[1];

	langutil::ErrorList errors;
	langutil::ErrorReporter errorReporter{errors};
	frontend::Parser parser{errorReporter, langutil::EVMVersion()};

	string contractContents = slurpFile(contractPath);
	langutil::CharStream charStream{contractContents, contractPath};
	auto sourceUnit = parser.parse(charStream);
	ASTStatistics statistics{};
	sourceUnit->accept(statistics);

	cout << "In " << contractPath << " I've counted:" << endl
		 << "- " << statistics.nodesCounted() << " AST nodes;" << endl
		 << "- " << statistics.variableDeclarationsCounted() << " variable declarations;" << endl
		 << "- " << statistics.functionDeclarationsCounted() << " function declarations;" << endl
		 << "- " << statistics.maximumMappingNestedness() << " is the maximum nestedness of a mapping;" << endl;

	return 0;
}
