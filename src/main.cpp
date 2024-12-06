///
/// Ce projet utilise quelques librairies disponibles sur Vcpkg et permet entre autre d'en tester le bon fonctionnement.
///


#include <cstddef>
#include <cstdint>

#include <iostream>
#include <iomanip>
#include <string>
#include <memory>

#include <tclap/CmdLine.h> // Librairie « headers-only ».
#include <cppitertools/range.hpp> // Librairie « headers-only ».
#include <boost/regex.hpp> // Librairie compilée.

#include "TileMap.h"
#include "Player.h"
#include "Game.h"




using namespace std;
using namespace std::literals;
using namespace game_universe;
using namespace game_engine;


int main()
{
	vector<std::shared_ptr<Tile>> tiles = {
	std::make_shared<Tile>(Tile("Grand Entrance", "1")),
	std::make_shared<Tile>(Tile("Game Room", "2")),
	std::make_shared<Tile>(Tile("Dance Floor", "3")),
	std::make_shared<Tile>(Tile("Bar & Lounge", "4")),
	std::make_shared<Tile>(Tile("Private Theater", "5")),
	std::make_shared<Tile>(Tile("Music Studio", "6")),
	std::make_shared<Tile>(Tile("Bedroom", "7")),
	std::make_shared<Tile>(Tile("Rooftop Deck", "8")),
	std::make_shared<Tile>(Tile("Private Pool", "9")),
	std::make_shared<Tile>(Tile("Bathroom", "10"))
	};

	tiles[1]->connect(tiles[2], tiles[9], nullptr, nullptr);
	tiles[2]->connect(tiles[3], tiles[1], nullptr, nullptr);
	tiles[3]->connect(tiles[4], tiles[2], nullptr, nullptr);

	TileMap map1 = { "Diddy's Mansion", tiles[1] };

	for (auto&& tile : tiles) {
		map1.addTile(tile);
	}

	Player player1{};
	Game game1 = { map1, player1 };

	for (auto&& tile : map1.getTiles()) {
		std::cout << tile->getName() << endl;
	}

	cout << player1.getPosition().lock();

	game1.startGame();

	//cout << "============================================================================\n";
}

