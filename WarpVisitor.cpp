#include "WarpVisitor.hpp"
#include <boost/algorithm/string.hpp>
#include <libsolutil/IndentedWriter.h>
#include <regex>


std::string str_repace(std::string find, std::string replace, std::string str)
{
	auto str_copy = str;
	size_t index = 0;
	auto size = replace.size();
	index	  = str_copy.find(find, index);
	if (index == std::string::npos)
		return str_copy;
	str_copy.replace(index, size, replace);
	index += size;
	return str_copy;
}


void WarpVisitor::processChanges()
{
	// this->removeDuplicates();
	// 	this->getDynFunctions();
	// 	this->markDynFunctions();
}

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


void WarpVisitor::getDynFunctions()
{
	for (auto i = 0; i < m_publicFunctions.sigs.size(); i++)
	{
		if (hasDynamicArgs(m_publicFunctions.sigs[i]))
		{
			auto sig		= m_publicFunctions.sigs[i];
			auto end		= sig.find('(');
			auto rest		= sig.rfind(')');
			auto name		= std::string(sig.begin(), sig.begin() + end);
			auto markedName = name + "_dynArgs";
			auto markedSig
				= name + "_dynArgs" + "(" + std::string(sig.begin() + 1 + end, sig.end());
			m_publicFunctions.markedSigs.emplace_back(markedSig);
			m_publicFunctions.sigsToReplace.emplace_back(m_publicFunctions.sigs[i]);
		}
	}
}


void WarpVisitor::markDynFunctions(std::string find, std::string replace)
{
	size_t index = 0;
	while (true)
	{
		auto size = replace.size();
		/* Locate the substring to replace. */
		index = m_src.find(find, index);
		if (index == std::string::npos)
			break;

		/* Make the replacement. */
		m_src.replace(index, size, replace);

		/* Advance index forward so the next iteration doesn't pick it up as well. */
		index += size;
	}
	solidity::util::IndentedWriter txt;
	txt.add(m_src);
	m_src = txt.format();
}


bool WarpVisitor::visitNode(solidity::frontend::ASTNode const& node)
{
	return solidity::frontend::ASTConstVisitor::visitNode(node);
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
			auto body
				= std::string(m_src.begin() + bodyStart + 1, m_src.begin() + bodyEnd);
			auto		funcLocation = std::make_pair(functionStart, functionEnd);
			std::string params
				= std::string(m_src.begin() + paramsStart, m_src.begin() + paramsEnd);
			if (not contains_warp(m_storageVars, _node.name()) and hasDynamicArgs(params))
			{
				auto sig = std::string(
					m_src.begin() + _node.location().start + 9,
					m_src.begin() + _node.body().location().start);
				auto markedName = _node.name() + "_dynArgs";
				auto markedSig = markedName + std::string(sig.begin() + sig.find('('), sig.end()) + "{\n";
				markDynFunctions(sig, markedSig);
				// this->m_publicFunctions.names.emplace_back(_node.name());
				// this->m_publicFunctions.parameters.emplace_back(params);
				// this->m_publicFunctions.sigs.emplace_back(sig);
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
