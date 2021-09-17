#include "WarpVisitor.hpp"
#include "library.hpp"


void WarpVisitor::processChanges()
{
	this->removeDuplicates();
	this->getDynFunctions();
	this->markDynFunctions();
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
			auto sig  = m_publicFunctions.sigs[i];
			auto end  = sig.find('(');
			auto rest = sig.rfind(')');
			auto name = std::string(sig.begin(), sig.begin() + end);
			auto markedSig
				= name + "_dynArgs" + "(" + std::string(sig.begin() + 1 + end, sig.end());
			m_publicFunctions.markedSigs.emplace_back(markedSig);
			m_publicFunctions.sigsToReplace.emplace_back(m_publicFunctions.sigs[i]);
		}
	}
}


void WarpVisitor::markDynFunctions()
{
	assert(m_publicFunctions.sigsToReplace.size() == m_publicFunctions.markedSigs.size());
	for (auto i = 0; i < m_publicFunctions.sigsToReplace.size(); i++)
	{
		auto   search  = m_publicFunctions.sigsToReplace[i];
		auto   replace = m_publicFunctions.markedSigs[i];
		size_t index   = 0;
		while (true)
		{
			auto size = replace.size();
			/* Locate the substring to replace. */
			index = m_src.find(search, index);
			if (index == std::string::npos)
				break;

			/* Make the replacement. */
			m_src.replace(index, size, replace);

			/* Advance index forward so the next iteration doesn't pick it up as well. */
			index += size;
		}
	}
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
			m_publicFunctionCount++;
			int			paramsStart	  = _node.parameterList().location().start + 1;
			int			paramsEnd	  = _node.parameterList().location().end - 1;
			int			functionStart = _node.location().start;
			int			functionEnd	  = _node.location().end;
			auto		funcLocation  = std::make_pair(functionStart, functionEnd);
			std::string params
				= std::string(m_src.begin() + paramsStart, m_src.begin() + paramsEnd);
			if (not contains_warp(m_storageVars, _node.name()))
			{
				this->m_publicFunctions.names.emplace_back(_node.name());
				this->m_publicFunctions.parameters.emplace_back(params);
				this->m_publicFunctions.sigs.emplace_back(
					_node.name() + "(" + params + ")");
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
