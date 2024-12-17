#include "Constants.h"
#include "Tile.h"
#include <boost/functional/hash.hpp>
#include <unordered_map>
#include "Item.h"
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost::algorithm;

std::string Tile::look() const {
	std::string result = "\t-- " + name_ + " --\n";
	result += "\t" + description_ + "\n";

	for (const auto& [direction, connection] : connections_) {
		if (connection != nullptr) {
			result += "\n\t" + connection->name_ + " is to the " + ::directionNames.at(direction)[0];
		}
	}

	result += "\n\nYou notice:";
	for (const auto& item : items_) {
		result += "\n\t" + item.second->getName();
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

// TODO: Interface to avoid code repetition with Player
const std::unordered_map<std::string, shared_ptr<Item>>::const_iterator Tile::getItemIterator(const string& details) const {
	return find_if(items_.begin(), items_.end(), [&details](std::pair<const std::string, std::shared_ptr<Item>> item) {
		return item.second->containsKeyword(details);
		});
}

bool Tile::operator==(const Tile& other) const
{
		return name_ == other.name_ && description_ == other.description_;
}

void Tile::dualConnect(Tile* other, Direction direction) {
	static const std::unordered_map<Direction, Direction> inverseDirections = {
	{Direction::north, Direction::south},
	{Direction::south, Direction::north},
	{Direction::west, Direction::east},
	{Direction::east, Direction::west}
	};

	connect(other, direction);
	other->connect(this, inverseDirections.at(direction));
}
