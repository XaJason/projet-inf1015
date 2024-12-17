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
	static const std::unordered_map < std::string, std::function<const string() >> commandsWithoutDetails = {
		{"n", [this]() { return moveInDirection(Direction::north); }},
		{"s", [this]() { return moveInDirection(Direction::south); }},
		{"w", [this]() { return moveInDirection(Direction::west); }},
		{"e", [this]() { return moveInDirection(Direction::east); }},

		{"north", [this]() { return moveInDirection(Direction::north); }},
		{"south", [this]() { return moveInDirection(Direction::south); }},
		{"west", [this]() { return moveInDirection(Direction::west); }},
		{"east", [this]() { return moveInDirection(Direction::east); }},

		{"up", [this]() { return moveInDirection(Direction::north); }},
		{"down", [this]() { return moveInDirection(Direction::south); }},
		{"left", [this]() { return moveInDirection(Direction::west); }},
		{"right", [this]() { return moveInDirection(Direction::east); }},

		{ "look", [this]() { return look(); }},

		{ "close", [this]() { return exit(); }},
		{ "exit", [this]() { return exit(); }},
		{ "quit", [this]() { return exit(); }}
	};

	static const std::unordered_map < std::string, std::function<const string(const string& details) >> commandsWithDetails = {
	{ "look", [this](const string& details) { return look(details); }},
	{ "take", [this](const string& details) { return take(details); }},
	{ "use", [this](const string& details) { return use(details); }},
	};

	std::cout << ">>>>> INF1015 DUNGEON CRAWLER 2024 <<<<<\n"
		<< ">  >  > GAME OF THE YEAR EDITION <  <  <\n\n"
		<< "==========================================\n"
		<< "          WELCOME TO THE ADVENTURE!\n"
		<< "==========================================\n\n"
		<< "Map: " << map_.getName() << "\n\n"
		<< look() << endl;

	while (!gameOver_) {
		cout << endl << "> ";
		string input;
		getline(cin, input);
		to_lower(input);

		istringstream stream(input);
		string actionWord, details;
		stream >> actionWord;
		
		getline(stream, details);

		try {
			if (details.empty()) {
				cout << commandsWithoutDetails.at(actionWord)() << endl;
			}
			else
				cout << commandsWithDetails.at(actionWord)(details) << endl; // First parenthesis for first word of input (action word), second parenthesis for remainder of the input (details)
		}
		catch (const InvalidMovement& e) {
			cout << e.what() << endl;
		}
		catch (const InvalidItem& e) {
			cout << e.what() << endl;
		}
		catch (const out_of_range&) {
			cout << "Error: Invalid command!" << endl;
		}
	}
}

const string Game::moveInDirection(Direction direction)
{
	player_.move(direction);
	return "Headed " + ::directionNames.at(direction)[1] + "\n\n" + look();
}

const string Game::look() const { return player_.look();  }

// TODO: Implement the look, take, and use methods
const string Game::look(const string& details) const
{
	return player_.look(details);
}

const string Game::take(const string& details)
{
	return "";
}

const string Game::use(const string& details)
{
		return player_.use(details);
}

const string Game::exit() {
	gameOver_ = true;
	return "\nWow! Is that a galaxy? Enough of those and I might make it back to my univer...\n";
}
