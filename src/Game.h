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
	/**
	 * @brief Deplace le joueur vers une direction donnee
	 * @param direction La direction vers laquelle deplacer le joueur
	 * @param item l'item present a la case vers laquelle le joueur se deplace
	 */
	void moveInDirection(Direction direction, std::string item);
	/**
	 * @brief Inspecte un item en affichant la description
	 * @param item Item a inspecter
	 */
	void look(string item);
private:
	TileMap map_; ///< La carte du jeu
	Player player_; ///< Le joueur
};
