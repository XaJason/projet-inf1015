#include "Constants.h"
#include "Exceptions.h"
#include "Game.h"
#include <boost/algorithm/string.hpp>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
using namespace boost::algorithm;

Game::Game(const TileMap& map, const Player& player)
	: map_(map), player_(player) {
	player_.setPosition(((map_.getStartingTile())));
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
		{ "take", [this](string item) { take(item); }},
		{ "use", [this](string item) {use(item); }}
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
			movementCommands.at(actionWord)(details); // First parenthesis for first word of input (action word), second parenthesis for remainder of the input (details)
		}
		catch (InvalidMovement c) {
			cout << "Well, urmmm, actually, you can't go there\n";
		}
		catch (out_of_range) {
			cout << "Urmmm, what the sigma is that input?\n";
		}

		cout << "\n";
	}
}

void Game::moveInDirection(Direction direction, string item)
{
	player_.move(direction);
	if (item.empty()) {
		cout << "Headed " << ::directionNames.at(direction)[2] << "\n\n";
	}
	else {
		throw out_of_range("Error: Invalid item");
	}
	cout << player_;
}

// TODO: Implement the look, take, and use methods
void Game::look(string item)
{
	if (item.empty()) {
		cout << player_;
	}
	else {
		// Look at item
	}
}

void Game::take(string item)
{
	if (item.empty()) {
		cout << player_;
	}
	else {
		// Look at item
	}
}

void Game::use(string item)
{
	if (item.empty()) {
		cout << player_;
	}
	else {
		// Look at item
	}
}

