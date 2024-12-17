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

	static const std::unordered_map < std::string, std::function<void(const string& details) >> movementCommands = {
		{"n", [this](const string& details) { moveInDirection(Direction::north, details); }},
		{"s", [this](const string& details) { moveInDirection(Direction::south, details); }},
		{"w", [this](const string& details) { moveInDirection(Direction::west, details); }},
		{"e", [this](const string& details) { moveInDirection(Direction::east, details); }},

		{"north", [this](const string& details) { moveInDirection(Direction::north, details); }},
		{"south", [this](const string& details) { moveInDirection(Direction::south, details); }},
		{"west", [this](const string& details) { moveInDirection(Direction::west, details); }},
		{"east", [this](const string& details) { moveInDirection(Direction::east, details); }},

		{"up", [this](const string& details) { moveInDirection(Direction::north, details); }},
		{"down", [this](const string& details) { moveInDirection(Direction::south, details); }},
		{"left", [this](const string& details) { moveInDirection(Direction::west, details); }},
		{"right", [this](const string& details) { moveInDirection(Direction::east, details); }},

		{ "look", [this](const string& details) {look(details); }},
		{ "take", [this](const string& details) { take(details); }},
		{ "use", [this](const string& details) {use(details); }},

		{ "close", [this](const string& details) {use(details); } },
		{ "exit", [this](const string& details) {use(details); } },
		{ "quit", [this](const string& details) {use(details); }},
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
		catch (const InvalidMovement& e) {
			cout << e.what();
		}
		catch (const out_of_range& e) {
			cout << "Error: Invalid command " << e.what();
		}

		cout << "\n";
	}
}

void Game::moveInDirection(Direction direction, const string& details)
{
	player_.move(direction);
	if (details.empty()) {
		cout << "Headed " << ::directionNames.at(direction)[2] << "\n\n";
	}
	else {
		throw out_of_range("Error: Invalid item");
	}
	cout << player_;
}

// TODO: Implement the look, take, and use methods
void Game::look(const string& details)
{
	if (details.empty()) {
		cout << player_;
	}
	else {
		// Look at item
	}
}

void Game::take(const string& details)
{
	if (details.empty()) {
		cout << player_;
	}
	else {
		// Look at item
	}
}

void Game::use(const string& details)
{
	if (details.empty()) {
		throw out_of_range("Error: Invalid LeBron");
	}
		cout << player_.use(details);
}

