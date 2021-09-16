#include <solc/CommandLineInterface.h>

#include "solidity/BuildInfo.h"

#include <libsolidity/interface/Version.h>
#include <libsolidity/ast/ASTJsonConverter.h>
#include <libsolidity/ast/ASTJsonImporter.h>
#include <libsolidity/analysis/NameAndTypeResolver.h>
#include <libsolidity/interface/CompilerStack.h>
#include <libsolidity/interface/StandardCompiler.h>
#include <libsolidity/interface/GasEstimator.h>
#include <libsolidity/interface/DebugSettings.h>
#include <libsolidity/interface/ImportRemapper.h>
#include <libsolidity/interface/StorageLayout.h>

#include <libyul/AssemblyStack.h>

#include <libevmasm/Instruction.h>
#include <libevmasm/GasMeter.h>

#include <liblangutil/Exceptions.h>
#include <liblangutil/Scanner.h>
#include <liblangutil/SourceReferenceFormatter.h>

#include <libsmtutil/Exceptions.h>

#include <libsolutil/Common.h>
#include <libsolutil/CommonData.h>
#include <libsolutil/CommonIO.h>
#include <libsolutil/JSON.h>

#include <algorithm>
#include <memory>

#include <range/v3/view/map.hpp>

#include <boost/filesystem.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/range/adaptor/filtered.hpp>
#include <boost/algorithm/string.hpp>

#ifdef _WIN32 // windows
	#include <io.h>
	#define isatty _isatty
	#define fileno _fileno
#else // unix
	#include <unistd.h>
#endif

#include <fstream>

#if !defined(STDERR_FILENO)
	#define STDERR_FILENO 2
#endif


using namespace std;
using namespace solidity;
using namespace solidity::util;
using namespace solidity::langutil;

namespace solidity::frontend
{
class WarpStack: public CompilerStack
{
    m_compiler = make_unique<CompilerStack>(m_fileReader.reader());

	SourceReferenceFormatter formatter(serr(false), *m_compiler, coloredOutput(m_options), m_options.formatting.withErrorIds);

	try
	{
		if (m_options.metadata.literalSources)
			m_compiler->useMetadataLiteralSources(true);
		m_compiler->setMetadataHash(m_options.metadata.hash);
		if (m_options.modelChecker.initialize)
			m_compiler->setModelCheckerSettings(m_options.modelChecker.settings);
		m_compiler->setRemappings(m_options.input.remappings);
		m_compiler->setLibraries(m_options.linker.libraries);
		m_compiler->setViaIR(m_options.output.experimentalViaIR);
		m_compiler->setEVMVersion(m_options.output.evmVersion);
		m_compiler->setRevertStringBehaviour(m_options.output.revertStrings);
		// TODO: Perhaps we should not compile unless requested

		m_compiler->enableIRGeneration(m_options.compiler.outputs.ir || m_options.compiler.outputs.irOptimized);
		m_compiler->enableEwasmGeneration(m_options.compiler.outputs.ewasm);

		OptimiserSettings settings = m_options.optimizer.enabled ? OptimiserSettings::standard() : OptimiserSettings::minimal();
		if (m_options.optimizer.expectedExecutionsPerDeployment.has_value())
			settings.expectedExecutionsPerDeployment = m_options.optimizer.expectedExecutionsPerDeployment.value();
		if (m_options.optimizer.noOptimizeYul)
			settings.runYulOptimiser = false;

		if (m_options.optimizer.yulSteps.has_value())
			settings.yulOptimiserSteps = m_options.optimizer.yulSteps.value();
		settings.optimizeStackAllocation = settings.runYulOptimiser;
		m_compiler->setOptimiserSettings(settings);

		if (m_options.input.mode == InputMode::CompilerWithASTImport)
		{
			try
			{
				m_compiler->importASTs(parseAstFromInput());

				if (!m_compiler->analyze())
				{
					formatter.printErrorInformation(m_compiler->errors());
					astAssert(false, "Analysis of the AST failed");
				}
			}
			catch (Exception const& _exc)
			{
				serr() << string("Failed to import AST: ") << _exc.what() << endl;
				return false;
			}
		}
		else
		{
			m_compiler->setSources(m_fileReader.sourceCodes());
			m_compiler->setParserErrorRecovery(m_options.input.errorRecovery);
		}

		bool successful = m_compiler->compile(m_options.output.stopAfter);

}

};