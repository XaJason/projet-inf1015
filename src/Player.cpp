#include "Exceptions.h"
#include "Player.h"
#include "Item.h"
#include "Actions.h"

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

std::ostream& operator<<(std::ostream& outputStream, const Player& player)
{
	return outputStream << *player.position_;
}

