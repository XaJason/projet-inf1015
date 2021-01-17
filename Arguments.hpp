///
/// Traite les arguments de ligne de commande à l'aide de TCLAP.
///

#pragma once


#include <cstddef>
#include <cstdint>

#include <string>

using namespace std;
using namespace std::literals;


struct Arguments
{
	string pattern;
	string text;
};


Arguments parseArgs(int argc, char* argv[]);

