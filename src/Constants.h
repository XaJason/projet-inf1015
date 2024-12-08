/**
 * Namespace constantes
 * \file Constants.h
 * \author Bouisri et Xa
 * \date 7 decembre 2024
 * Cree le 6 decembre 2024
 */
#pragma once
#include "Direction.h"
#include <string>
#include <unordered_map>

namespace constants {
	extern const std::unordered_map<game_helper::Direction, std::vector<std::string>> directionNames; ///< directions
}
