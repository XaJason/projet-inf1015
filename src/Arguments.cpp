///
/// Traite les arguments de ligne de commande à l'aide de TCLAP.
///


#include <cstddef>
#include <cstdint>

#include <string>

#include <tclap/CmdLine.h>

#include "Arguments.hpp"

using namespace std;
using namespace std::literals;


Arguments parseArgs(int argc, char* argv[])
{
	TCLAP::CmdLine parser("What is it, citizen?");

	// TODO: Créer l'argument de pattern (-p et --pattern).
	TCLAP::ValueArg<string> patternArg(
		"p",
		"pattern",
		"The regular expression pattern to apply",
		true,
		"",
		"string"
	);
	parser.add(&patternArg);

	// TODO: Créer l'argument de texte (-t et --text)
	TCLAP::ValueArg<string> textArg(
		"t",
		"text",
		"The regular expression pattern to apply",
		true,
		"",
		"string"
	);
	parser.add(&textArg);

	parser.parse(argc, argv);

	return {patternArg.getValue(), textArg.getValue()};
}

