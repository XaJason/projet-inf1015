#pragma once
#include <stdexcept>

/**
 * @class InvalidMovement
 * @brief Exception pour un deplacement invalide non-autorise
 *
 * La classe InvalidMovement est une exception utilisee lorque le deplacement du joueur est effectue vers une case invalide, c'est-a-dire une case introuvable du TileMap
 */
class InvalidMovement : public std::out_of_range {
public:
	using std::out_of_range::out_of_range;
};
