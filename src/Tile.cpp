#include "Constants.h"
#include "Tile.h"
#include <boost/functional/hash.hpp>
#include <unordered_map>
#include "Item.h"

using namespace std;

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

void Tile::addItem(const Item& item) {
	items_[item.getName()] = make_shared<TrashItem>();
}

std::ostream& operator<<(std::ostream& outputStream, const Tile& tile)
{


	outputStream
		<< "\t-- " << tile.name_ << " --\n"
		<< "\t" << tile.description_ << "\n\n";

	for (const auto& [direction, connection] : tile.connections_) {
		if (connection != nullptr) {
			outputStream << "\t" << connection->name_ << " is to the " << ::directionNames.at(direction)[0] << "\n";
		}
	}
	return outputStream;
}

