#include "Player.h"
#include "Exceptions.h"

using namespace game_universe;

void Player::move(const Direction& direction) {
	if (auto origin = position_.lock()) { // Verification initialization
		if (auto destination = origin->getNeighbors()[direction].lock()) {
			position_ = destination;
		}
		else {
			throw InvalidMovement("Error : No accessible room in this direction.");
		}
	}

}

ostream& Player::operator<<(ostream& outputStream, const Player& player) {

}