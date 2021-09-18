#include "WarpVisitor.hpp"
#include <boost/algorithm/string.hpp>
#include <libsolutil/IndentedWriter.h>
#include <regex>


void WarpVisitor::removeDuplicates()
{
	std::sort(m_publicFunctions.sigs.begin(), m_publicFunctions.sigs.end());
	m_publicFunctions.sigs.erase(
		std::unique(m_publicFunctions.sigs.begin(), m_publicFunctions.sigs.end()),
		m_publicFunctions.sigs.end());
}

bool WarpVisitor::contains_warp(std::vector<std::string> vec, std::string search)
{
	auto it = std::find(vec.begin(), vec.end(), search);
	return it != vec.end();
}


std::string WarpVisitor::exec(std::string cmdStr)
{
	const char*								 cmd = cmdStr.c_str();
	std::array<char, 4096>					 buffer;
	std::string								 result;
	std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
	if (!pipe)
	{
		throw std::runtime_error("popen() failed!");
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
	{
		result += buffer.data();
	}
	return result;
}


std::vector<std::string>
WarpVisitor::getPublicFunchashes(const std::string& contract_path)
{
	std::ostringstream		 cmd;
	std::vector<std::string> hashes;
	std::vector<std::string> hashNames;
	cmd << "solc --combined-json hashes " << contract_path;
	json res	   = json::parse(exec(cmd.str()));
	auto contracts = res["contracts"];
	for (auto contract: contracts)
	{
		for (auto hash: contract["hashes"].items())
		{
			auto		key	 = hash.key();
			auto		end	 = key.find('(');
			std::string name = std::string(key.begin(), key.begin() + end);
			if (not contains_warp(this->m_storageVars, name))
			{
				hashes.emplace_back(hash.value());
				hashNames.emplace_back(name);
			}
		}
	}
	std::sort(hashes.begin(), hashes.end());
	hashes.erase(std::unique(hashes.begin(), hashes.end()), hashes.end());

	std::sort(hashNames.begin(), hashNames.end());
	hashNames.erase(std::unique(hashNames.begin(), hashNames.end()), hashNames.end());
	m_hashNames = hashNames;
	return hashes;
}

bool WarpVisitor::hasDynamicArgs(std::string params)
{
	return params.find("calldata") != std::string::npos
		   || params.find("memory") != std::string::npos;
}

bool WarpVisitor::visitNode(solidity::frontend::ASTNode const& node)
{
	return solidity::frontend::ASTConstVisitor::visitNode(node);
}

int WarpVisitor::getSigEnd(int start)
{
	for (auto i = start; i < m_srcSplit.size(); i++)
	{
		if (m_srcSplit[i].find("{") != std::string::npos)
			return i;
	}
	std::runtime_error("Failed to find end of signature");
}

void WarpVisitor::compressSigs()
{
	std::vector<std::string> newSplit;
	auto					 jump = 1;
	for (auto i = 0; i < m_srcSplit.size(); i += jump)
	{
		if (m_srcSplit[i].find("function") != std::string::npos)
		{
			if (m_srcSplit[i].find("{") != std::string::npos)
			{
				newSplit.emplace_back(m_srcSplit[i]);
			}
			else
			{
				auto end = getSigEnd(i);
				jump	 = end + 1 - (i);
				std::string sig;
				std::for_each(
					m_srcSplit.begin() + i,
					m_srcSplit.begin() + end + 1,
					[&sig](std::string v) { sig += v + "\n"; });
				newSplit.emplace_back(sig);
			}
		}
		else
		{
			newSplit.emplace_back(m_srcSplit[i]);
			jump = 1;
		}
	}
	m_srcSplit = newSplit;
}

[[nodiscard]] bool WarpVisitor::visit(solidity::frontend::FunctionDefinition const& _node)
{
	if (_node.isConstructor())
		return visitNode(_node);
	try
	{
		if (isPublic(_node.visibility()))
		{
			int	 paramsStart   = _node.parameterList().location().start + 1;
			int	 paramsEnd	   = _node.parameterList().location().end - 1;
			int	 functionStart = _node.location().start;
			int	 functionEnd   = _node.location().end;
			int	 bodyStart	   = _node.body().location().start;
			int	 bodyEnd	   = _node.body().location().end;
			auto body		   = std::string(
				 m_src.begin() + bodyStart + 1, m_src.begin() + bodyEnd);
			auto		funcLocation = std::make_pair(functionStart, functionEnd);
			std::string params		 = std::string(
				  m_src.begin() + paramsStart, m_src.begin() + paramsEnd);
			if (not contains_warp(m_storageVars, _node.name()) and hasDynamicArgs(params))
			{
				auto sig = "    "
						   + std::string(
							   m_src.begin() + _node.location().start,
							   m_src.begin() + _node.body().location().start + 1);
				auto match = std::find_if(
					m_srcSplit.begin(),
					m_srcSplit.end(),
					[&sig](std::string v) { return v.find(sig) != std::string::npos; });
				int	 index		= std::distance(m_srcSplit.begin(), match);
				auto markedName = _node.name() + "_dynArgs";
				auto markedSig	= "    function " + markedName
								 + std::string(sig.begin() + sig.find('('), sig.end());
				m_srcSplit[index] = markedSig;
			}
		}
		return visitNode(_node);
	}
	catch (boost::wrapexcept<solidity::langutil::InternalCompilerError> e)
	{
		return visitNode(_node);
	}
}

[[nodiscard]] bool WarpVisitor::isPublic(solidity::frontend::Visibility _visibility)
{
	switch (_visibility)
	{
	case solidity::frontend::Visibility::Public:
	case solidity::frontend::Visibility::External:
	{
		return true;
		break;
	}
	default:
	{
		return false;
		break;
	}
	}
}

void WarpVisitor::writeModifiedSolidity()
{
	std::string solStr;
	for (auto line: m_srcSplit)
		solStr += line + "\n";

	std::fstream solFile;
	solFile.open(m_modifiedSolFilepath, std::ios::out | std::ios::trunc);
	solFile << solStr;
	solFile.close();
	m_src = solStr;
}