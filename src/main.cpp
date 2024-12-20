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
	Tile("Storage Room", "Yellowed newspapers. Dark hotel secrets. A faint golden glimmer peeks from a locked door, hinting at something beyond."),
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
	map["Storage Room"]->connect(nullptr, nullptr, map["Lobby"], nullptr);
	map["Ballroom"]->connect(nullptr, map["Gold Hall"], map["Colorado Lounge"], nullptr);
	map["Room 237"]->connect(nullptr, nullptr, nullptr, nullptr);
	map["Boiler Room"]->connect(map["Kitchen"], map["Lobby"], nullptr, map["Colorado Lounge"]);
	map["Gold Hall"]->connect(map["Ballroom"], nullptr, nullptr, map["Torrance Apartment"]);
	map["Torrance Apartment"]->connect(nullptr, map["Storage Room"], map["Gold Hall"], nullptr);

	// ITEMS
	// Key items
	unordered_set <string> room237KeyKeywords = { "room 237", "key" };
	map["Colorado Lounge"]->addItem(make_shared<KeyItem>("Room 237 Key", "A brass key with \"237\" engraved on it.", room237KeyKeywords, true, make_pair<Tile*, Tile*>(map["Ballroom"], map["Room 237"]), Direction::east));

	unordered_set <string> goldHallKeyKeywords = { "gold", "hall", "key" };
	map["Storage Room"]->addItem(make_shared<KeyItem>("Gold Hall Key", "A polished golden key labeled \"Gold Hall.\"", goldHallKeyKeywords, true, make_pair<Tile*, Tile*>(map["Storage Room"], map["Gold Hall"]), Direction::north));

	// Access items
	unordered_set <string> phantomMirrorKeywords = { "phantom", "mirror" };
	map["Ballroom"]->addItem(make_shared<AccessItem>("Phantom Mirror", "A tall, ornate mirror reflecting a hallway that isn't there.", phantomMirrorKeywords, map["Lobby"]));

	unordered_set <string> carpetKeywords = { "blood", "soak", "carpet" };
	map["Gold Hall"]->addItem(make_shared<AccessItem>("Boold-Soaked Carpet", "The carpet is soaked with dried blood, forming a trail. It seems to extend endlessly.", carpetKeywords, map["Boiler Room"]));

	// Regular items
	unordered_set <string> axeKeywords = { "jack", "axe" };
	map["Torrance Apartment"]->addItem(make_shared<Item>("Jack's Axe", "Splintered handle, bloodstained blade.", "Here's Johnny! You swing the axe with force.", axeKeywords, true));

	unordered_set <string> canKeywords = { "calumet", "can", "powder", "baking" };
	map["Storage Room"]->addItem(make_shared<Item>("Calumet Can", "A can of Calumet Baking Powder. The Native American chief on the label stares back at you.", "You examine the can. The chief's expression seems to change the longer you look.", canKeywords, true));

	unordered_set <string> tricycleKeywords = { "danny", "tricycle" };
	map["Gold Hall"]->addItem(make_shared<Item>("Danny's Tricycle", "Red trycicle, wheels creak errily.", "You try to ride, but it rolls away on its own", tricycleKeywords, false));

	unordered_set <string> buttonKeywords = { "blood", "elevator", "button" };
	map["Lobby"]->addItem(make_shared<Item>("Bloody Elevator Button", "Bloodstained elevator button.", "You press it, hearing rushing blood.", buttonKeywords, false));

	unordered_set <string> photoKeywords = { "overlook", "photo" };
	map["Ballroom"]->addItem(make_shared<Item>("The Overlook Photograph", "Black-and-white 1921 photo, Jack grins unnervingly.", "The faces seem to shift slightly.", photoKeywords, false));

	unordered_set <string> typewriterKeywords = { "writer" };
	map["Torrance Apartment"]->addItem(make_shared<Item>("Typewriter", "Endless \"All work and no play\" pages.", "Another line appears: All work and no play makes Jack a dull boy.", typewriterKeywords, false));

	unordered_set <string> mirrorKeywords = { "redrum", "mirror" };
	map["Torrance Apartment"]->addItem(make_shared<Item>("Redrum mirror", "A cracked mirror with \"REDRUM\" scrawled in crimson letters.", "You look into the mirror. Flipping the letters, they spell: MURDER.", mirrorKeywords, false));

	unordered_set <string>  cocktailKeywords = { "ghostly", "cocktail", "bourbon", "glass", "alcohool", "drink" };
	map["Ballroom"]->addItem(make_shared<Item>("Ghostly Cocktail", "Bourbon glass, ice never melts.", "You sip, hearing faint party music.", cocktailKeywords, false));

	unordered_set <string> f150Keywords = { "broken", "down", "ford", "150" };
	map["Storage Room"]->addItem(make_shared<Item>("Broken-down Ford F-150", "A weathered Ford F-150, covered in dust and rust. The engine sputters with a weak cough.", "You try to start it, but it makes a pathetic 'vroom' before stalling again.", f150Keywords, true));

	unordered_set <string> lebronKeywords = { "lebron", "james", "action", "figure", "king", "goat", "great", "basketball", "player" };
	map["Kitchen"]->addItem(make_shared<Item>("LeBron James Action Figure", "A melted LeBron James action figure, basketball in hand.", "LeBron's dunk is forever. You feel his gaze.", lebronKeywords, true));

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




