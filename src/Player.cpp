#include "Exceptions.h"
#include "Player.h"

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

std::ostream& operator<<(std::ostream& outputStream, const Player& player)
{
	return outputStream << *player.position_;
}
