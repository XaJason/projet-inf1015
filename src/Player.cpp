#include "Player.h"
#include "Exceptions.h"

namespace game_universe {

	void Player::move(const Direction& direction) {
		if (auto origin = position_.lock()) { // Verification initialization
			if (auto destination = origin->getConnections()[direction].lock()) {
				position_ = destination;
			}
			else {
				throw InvalidMovement("Error : No accessible room in this direction.");
			}
		}

	}

	std::ostream& operator<<(std::ostream& outputStream, const Player& player)
	{
		return outputStream << *(player.position_.lock());
	}
}