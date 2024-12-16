#include "Constants.h"
#include "Tile.h"
#include <boost/functional/hash.hpp>
#include <unordered_map>
#include "Item.h"

using namespace std;

std::string Tile::look() const {
	std::string result = "\t-- " + name_ + " --\n";
	result += "\t" + description_ + "\n\n";

	for (const auto& [direction, connection] : connections_) {
		if (connection != nullptr) {
			result += "\t" + connection->name_ + " is to the " + ::directionNames.at(direction)[0] + "\n";
		}
	}

	result += "\nYou notice:\n";
	for (const auto& item : items_) {
		result += "\tA " + item.second->getName() + "\n";
	}
	return result;
}

// PUBLIC
// Constructors
void Tile::connect(Tile* other, Direction direction) {
	connections_[direction] = other;
}

void Tile::connect(Tile* northTile, Tile* southTile, Tile* westTile, Tile* eastTile) {
	connect(northTile, Direction::north);
	connect(southTile, Direction::south);
	connect(westTile, Direction::west);
	connect(eastTile, Direction::east);
}

void Tile::addItem(const shared_ptr<Item>& item) {
	//TODO: use 
	items_[item->getName()] = item;
}

std::ostream& operator<<(std::ostream& outputStream, const Tile& tile)
{
	return outputStream << tile.look();
}

