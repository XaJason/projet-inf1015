#include "Actions.h"
#include "Direction.h"
#include "Exceptions.h"
#include "Item.h"
#include "Player.h"
#include "Tile.h"
#include <boost/algorithm/string.hpp>
#include <iosfwd>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>

using namespace boost::algorithm;
void Player::move(const Direction& direction) {
	if (position_ != nullptr) { // Verification initialization
		Tile* destination = position_->getConnection(direction);
		if (destination != nullptr) {
			position_ = destination;
		}
		else {
			throw InvalidMovement("Error : No accessible room in this direction.");
		}
	}

}

//TODO: Implement the take method
bool Player::take(Takeable& t) {
	return true;
}

//TODO: Implement the use method
bool Player::use(Useable& u) {
	return true;
}

const string Player::take(const string& details) {
	return position_->extractItem(details, *this);;
}

const string Player::use(const string& details) {
	return findItem(details)->second->use(*this);
}

const string Player::look() const {
	string inventory;
	if (!items_.empty()) {
		inventory = "\nYou have :";
		for (const auto& item : items_) {
			inventory += "\n\t" + item.second->getName();
		}
	}
	return position_->look() + inventory;
}

const string Player::look(const string& details) const {
	return findItem(details)->second->look();
}

std::ostream& operator<<(std::ostream& outputStream, const Player& player)
{
	return outputStream << *player.position_;
}

std::unordered_map<std::string, shared_ptr<Item>>::const_iterator Player::findInInventory(const string& details) const {
	std::unordered_map<std::string, shared_ptr<Item>>::const_iterator iterator = std::find_if(items_.begin(), items_.end(), [&details](std::pair<const std::string, std::shared_ptr<Item>> item) {
		return item.second->containsKeyword(details);
		});

	if (iterator == items_.end()) {
		throw InvalidItem("Error: Invalid Item");
	}

	return iterator;
}

std::unordered_map<std::string, shared_ptr<Item>>::const_iterator Player::findItem(const string& details) const {
	std::unordered_map<std::string, shared_ptr<Item>>::const_iterator iterator;
	try {
		iterator = findInInventory(details);
	}
	catch (const InvalidItem&) {
		iterator = position_->getItemIterator(details);
	}
	return iterator;
}

void Player::addItem(std::unordered_map<std::string, std::shared_ptr<Item>>::node_type node) {
	items_.insert(std::move(node));
}
