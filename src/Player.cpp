#include "Exceptions.h"
#include "Player.h"
#include "Item.h"

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

std::ostream& operator<<(std::ostream& outputStream, const Player& player)
{
	return outputStream << *player.position_;
}
