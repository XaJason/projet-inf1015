/**
* Jeu permettant de deplacer un joueur dans une carte
* \file   main.cpp
* \author Bouisri et Xa
* \date   7 decembre 2024
* Créé le 6 decembre 2024
*/


#include <memory>
#include <string>


#include "Direction.h"
#include "Game.h"
#include "Item.h"
#include "Player.h"
#include "Tile.h"
#include "TileMap.h"
#include <unordered_set>
#include <utility>
#include <vector>




using namespace std;
using namespace std::literals;

/**
 * @brief
 */
static TileMap buildLevel() {
	vector<Tile> tiles = {
	Tile("Lobby", "Grand entrance hall with menacing Native totems and a lot of doors."),
	Tile("Colorado Lounge", "Abandoned bar. Mirrors reflect impossible scenes."),
	Tile("Kitchen", "Industrial silence. Gleaming knife racks."),
	Tile("Storage Room", "Yellowed newspapers. Dark hotel secrets."),
	Tile("Ballroom", "Phantom dancers from 1921 still celebrate here."),
	Tile("Room 237", "Rotting bathroom. Something moves in the tub."),
	Tile("Boiler Room", "Hissing pipes. Rising pressure. Metal groans."),
	Tile("Gold Hall", "Endless hexagonal carpet. Echoes of children's laughter."),
	Tile("Torrance Apartment", "Family quarters. Danny's tricycle marks the floor.")
	};

	TileMap map = { "The Overlook Hotel" };
	for (auto&& tile : tiles) {
		map.addTile(tile);
	}

	map["Lobby"]->connect(map["Colorado Lounge"], nullptr, map["Boiler Room"], map["Storage Room"]);
	map["Colorado Lounge"]->connect(map["Kitchen"], map["Lobby"], map["Boiler Room"], map["Ballroom"]);
	map["Kitchen"]->connect(nullptr, map["Colorado Lounge"], map["Boiler Room"], map["Ballroom"]);
	map["Storage Room"]->connect(map["Gold Hall"], nullptr, map["Lobby"], nullptr);
	map["Ballroom"]->connect(nullptr, map["Gold Hall"], map["Colorado Lounge"], map["Room 237"]);
	map["Room 237"]->connect(nullptr, map["Torrance Apartment"], map["Boiler Room"], nullptr);
	map["Boiler Room"]->connect(map["Kitchen"], map["Lobby"], nullptr, map["Colorado Lounge"]);
	map["Gold Hall"]->connect(map["Ballroom"], map["Storage Room"], nullptr, map["Torrance Apartment"]);
	map["Torrance Apartment"]->connect(map["Room 237"], map["Storage Room"], map["Gold Hall"], nullptr);



	unordered_set <string> ladderKeywords = { "golden", "ladder" };
	map["Colorado Lounge"]->addItem(make_shared<AccessItem>("Golden ladder", "It looks old and smells ... rotten.", ladderKeywords, false, map["Gold Hall"]));

	unordered_set <string> keyKeywords = { "old", "key" };
	map["Colorado Lounge"]->addItem(make_shared<KeyItem>("Old key", "It is rusty and quite old.", keyKeywords, true, make_pair<Tile*, Tile*>(map["Lobby"], map["Kitchen"]), Direction::south));

	return map;
}

int main()
{
	TileMap map = buildLevel();
	Player player = Player();
	Game game = { map, player };

	game.startGame();
	return 0;
}




