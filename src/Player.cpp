#include "Exceptions.h"
#include "Player.h"
#include "Item.h"
#include "Actions.h"
#include <boost/algorithm/string.hpp>

using namespace boost::algorithm;

void Player::move(const Direction& direction) {
	if (position_ != nullptr) { // Verification initialization
		const Tile* destination = position_->getConnection(direction);
		if (destination != nullptr) {
			position_ = destination;
		}
		else {
			throw InvalidMovement("Error : No accessible room in this direction.");
		}
	}

}

void Player::addItem(std::shared_ptr<Item> item) { items_[item->getName()] = std::move(item); }

//TODO: Implement the take method
bool Player::take(Takeable& t) {
	return true;
}

//TODO: Implement the use method
bool Player::use(Useable& u) {
	return true;
}

string Player::use(const string& details) {
	return findItem(details)->second->use(*this);
}

std::ostream& operator<<(std::ostream& outputStream, const Player& player)
{
	return outputStream << *player.position_;
}

std::unordered_map<std::string, shared_ptr<Item>>::const_iterator Player::findItem(const string& details) {
	std::unordered_map<std::string, shared_ptr<Item>>::const_iterator iterator = std::find_if(items_.begin(), items_.end(), [&details](std::pair<const std::string, std::shared_ptr<Item>> item) {
		return item.second->containsKeyword(details);
		});

	if (iterator == items_.end()) {
		iterator = position_->getItemIterator(details);
		if (iterator == position_->getItems().end()) {
			throw std::out_of_range("Error: Invalid Item");
		}
	}
	return iterator;
}

