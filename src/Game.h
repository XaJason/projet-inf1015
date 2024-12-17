/**
 * Classe Game
 * \file Game.h
 * \author Bouisri et Xa
 * \date 7 decembre 2024
 * Cree le 6 decembre 2024
 */
#pragma once
#include "Player.h"
#include "TileMap.h"

 /**
  * @class Game
  * @brief Controlleur de la logique principale du jeu
  *
  * La classe Game permet de gerer les interactions entre le joueur `Player` et la carte du jeu `TileMap`.
  */
class Game {
public:
	/**
	 * @brief Constructeur de la classe
	 * @param map Reference vers la carte du jeu `TileMap`
	 * @param player Reference vers le joueur principal
	 */
	Game(const TileMap& map, const Player& player);
	/**
	 * @brief Demarrer le jeu
	 */
	void startGame();

	const string moveInDirection(Direction direction);

	const string look() const;

	const string look(const string& details) const;

	const string take(const string& details);

	const string use(const string& details);

	const string exit();

	/**
 * @brief Deplace le joueur vers une direction donnee
 * @param direction La direction vers laquelle deplacer le joueur
 * @param item l'item present a la case vers laquelle le joueur se deplace
 */
private:
	bool gameOver_ = false;
	TileMap map_; ///< La carte du jeu
	Player player_; ///< Le joueur
};
