///
/// Ce projet utilise quelques librairies disponibles sur Vcpkg et permet entre autre d'en tester le bon fonctionnement.
///


#include <cstddef>
#include <cstdint>

#include <iostream>
#include <iomanip>
#include <string>

#include <tclap/CmdLine.h> // Librairie « headers-only ».
#include <cppitertools/range.hpp> // Librairie « headers-only ».
#include <boost/regex.hpp> // Librairie compilée.

#include "Arguments.hpp"

using namespace std;
using namespace std::literals;


int main(int argc, char* argv[])
{
	// TODO: Faire un hello world.
	cout << "Hello, world!" << "\n";

	// TODO: Traiter les arguments de ligne de commande.
	Arguments args;
	try {
		args = parseArgs(argc, argv);
	} catch (TCLAP::ArgException& e) {
		cout << "Error in parsing arg " << e.argId() << ": " << e.error() << "\n";
		return EXIT_FAILURE;
	}

	// TODO: Afficher les multiples de 3 plus petits que 15.
	for (int i : iter::range(0, 15, 3))
		cout << i << " ";
	cout << "\n";

	// TODO: Appliquer la regex passé en paramètre au texte passé en paramètre.
	boost::regex rgx(args.pattern);
	cout << "Pattern: " << args.pattern << "\n"
	     << "Text: " << args.text << "\n"
	     << "Match? " << boolalpha << boost::regex_match(args.text, rgx) << "\n";
}

