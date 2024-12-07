#include "Game.h"
#include <iostream>
#include <functional>
#include <unordered_map>
#include "Exceptions.h"
#include <boost/algorithm/string.hpp>
#include <sstream>
#include <string>
#include "Constants.h"

using namespace std;
using namespace boost::algorithm;
using namespace game_logic;
using namespace game_helper;
using namespace exceptions;
using namespace constants;

namespace game_logic {
	Game::Game(const game_world::TileMap& map, const game_world::Player& player)
		: map_(map), player_(player) {
		player_.setPosition(((map_.getStartingTile()).lock()));
	}

	void Game::startGame() {
		static const std::string cat = R"(
 /\_/\  
( o.o ) 
 > ^ <
)";

		static const std::unordered_map < std::string, std::function<void(string) >> movementCommands = {
			{"n", [this](string item) { moveInDirection(Direction::north, item); }},
			{"s", [this](string item) { moveInDirection(Direction::south, item); }},
			{"w", [this](string item) { moveInDirection(Direction::west, item); }},
			{"e", [this](string item) { moveInDirection(Direction::east, item); }},

			{"north", [this](string item) { moveInDirection(Direction::north, item); }},
			{"south", [this](string item) { moveInDirection(Direction::south, item); }},
			{"west", [this](string item) { moveInDirection(Direction::west, item); }},
			{"east", [this](string item) { moveInDirection(Direction::east, item); }},

			{"up", [this](string item) { moveInDirection(Direction::north, item); }},
			{"down", [this](string item) { moveInDirection(Direction::south, item); }},
			{"left", [this](string item) { moveInDirection(Direction::west, item); }},
			{"right", [this](string item) { moveInDirection(Direction::east, item); }},

			{ "look", [this](string item) {look(item); }},
			{ "take", [this](string item) { cout << "take" << cat; }},
			{ "use", [this](string item) {cout << "use" << item; }}
		};

		std::cout << ">>>>> INF1015 DUNGEON CRAWLER 2024 <<<<<\n"
			<< ">>> GAME OF THE YEAR EDITION <<<\n\n"
			<< "==========================================\n"
			<< "          WELCOME TO THE ADVENTURE!\n"
			<< "==========================================\n\n"
			<< "Map: " << map_.getName() << "\n\n"
			<< player_ << "\n";

		while (true) {
			cout << "> ";
			string input;
			getline(cin, input);
			to_lower(input);

			istringstream stream(input);
			string actionWord, details;
			stream >> actionWord;
			getline(stream, details);

			try {
				movementCommands.at(input)(""); // First parenthesis for first word of input (action word), second parenthesis for remainder of the input (details)
			}
			catch (InvalidMovement) {
				cout << "Well, urmmm, actually, you can't go there\n";
			}
			catch (out_of_range) {
				cout << "Urmmm, what the sigma is that input?\n";
			}

			cout << "\n";
		}
	}

	void game_logic::Game::moveInDirection(Direction direction, string item)
	{
		player_.move(direction);
		if (item.empty()) {
			cout << "Headed " << ::directionNames.at(direction)[2] << "\n\n";
		}
		else {
			cout << "Hol' on, I ain't never seen" << item << " before but we goin " << ::directionNames.at(direction)[2] << ".\n\n";
		}
		cout << player_;
	}

	void game_logic::Game::look(string item)
	{
		if (item.empty()) {
			cout << player_;
		}
		else {
			// Look at item
		}
	}
}