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
	// TILES
	vector<Tile> tiles = {
	Tile("Lobby", "Grand entrance hall with menacing Native totems."),
	Tile("Colorado Lounge", "Abandoned bar. Mirrors reflect impossible scenes."),
	Tile("Kitchen", "Industrial silence. Gleaming knife racks."),
	Tile("Storage Room", "Yellowed newspapers. Dark hotel secrets."),
	Tile("Ballroom", "Phantom dancers from 1921 still celebrate here. There's a door bearing a faint engraving: \"237\"."),
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
	map["Ballroom"]->connect(nullptr, map["Gold Hall"], map["Colorado Lounge"], nullptr);
	map["Room 237"]->connect(nullptr, nullptr, nullptr, nullptr);
	map["Boiler Room"]->connect(map["Kitchen"], map["Lobby"], nullptr, map["Colorado Lounge"]);
	map["Gold Hall"]->connect(map["Ballroom"], map["Storage Room"], nullptr, map["Torrance Apartment"]);
	map["Torrance Apartment"]->connect(nullptr, map["Storage Room"], map["Gold Hall"], nullptr);

	// ITEMS
	unordered_set <string> ladderKeywords = { "golden", "ladder" };
	map["Colorado Lounge"]->addItem(make_shared<AccessItem>("Golden ladder", "It looks old and smells ... rotten.", ladderKeywords, map["Gold Hall"]));

	unordered_set <string> keyKeywords = { "key", "room 237" };
	map["Colorado Lounge"]->addItem(make_shared<KeyItem>("Room 237 Key", "A brass key with \"237\" engraved on it.", keyKeywords, true, make_pair<Tile*, Tile*>(map["Ballroom"], map["Room 237"]), Direction::east));

	unordered_set <string> axeKeywords = { "axe", "shiny", "fire axe" };
	map["Torrance Apartment"]->addItem(make_shared<Item>("Shiny Axe", "A heavy fire axe, its blade gleaming menacingly.", "You swing the axe with force, hearing it thud into the wood. Jack would be proud.", axeKeywords, true));

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




