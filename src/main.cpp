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
using namespace game_world;
using namespace game_logic;

	int main()
	{
		vector<Tile> tiles = {
		Tile("Lobby", "Grand entrance hall with menacing Native totems."),
		Tile("Colorado Lounge", "Abandoned bar. Mirrors reflect impossible scenes."),
		Tile("Kitchen", "Industrial silence. Gleaming knife racks."),
		Tile("Storage Room", "Yellowed newspapers. Dark hotel secrets."),
		Tile("Ballroom", "Phantom dancers from 1921 still celebrate here."),
		Tile("Room 237", "Rotting bathroom. Something moves in the tub."),
		Tile("Boiler Room", "Hissing pipes. Rising pressure. Metal groans."),
		Tile("Gold Hall", "Endless hexagonal carpet. Echoes of children's laughter."),
		Tile("Torrance Apartment", "Family quarters. Danny's tricycle marks the floor.")
		};

		TileMap map1 = { "The Overlook Hotel" };
		for (auto&& tile : tiles) {
			map1.addTile(tile);
		}

		map1["Lobby"]->connect(map1["Colorado Lounge"], nullptr, map1["Boiler Room"], map1["Storage Room"]);
		map1["Colorado Lounge"]->connect(map1["Kitchen"], map1["Lobby"], map1["Boiler Room"], map1["Ballroom"]);
		map1["Kitchen"]->connect(nullptr, map1["Colorado Lounge"], map1["Boiler Room"], map1["Ballroom"]);
		map1["Storage Room"]->connect(map1["Gold Hall"], nullptr, map1["Lobby"], nullptr);
		map1["Ballroom"]->connect(nullptr, map1["Gold Hall"], map1["Colorado Lounge"], map1["Room 237"]);
		map1["Room 237"]->connect(nullptr, map1["Torrance Apartment"], map1["Boiler Room"], nullptr);
		map1["Boiler Room"]->connect(map1["Kitchen"], map1["Lobby"], nullptr, map1["Colorado Lounge"]);
		map1["Gold Hall"]->connect(map1["Ballroom"], map1["Storage Room"], nullptr, map1["Torrance Apartment"]);
		map1["Torrance Apartment"]->connect(map1["Room 237"], map1["Storage Room"], map1["Gold Hall"], nullptr);

		Game game1 = { map1, Player() };

		game1.startGame();
		return 0;
	}


