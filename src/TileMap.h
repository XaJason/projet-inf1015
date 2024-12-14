/**
* Classe TileMap
* \file   TileMap.h
* \author Bouisri et Xa
* \date   7 decembre 2024
* Créé le 6 decembre 2024
*/

#pragma once

#include <vector>
#include <memory>
#include "Tile.h"
#include <ostream>
#include "Direction.h"
#include <map>
#include <functional>
#include <unordered_set>

/**
 * @class TileMap
 * @brief Gestionnaire de la carte du jeu
 *
 * La classe TileMap permet de gerer les cases qui composent le jeu.
 * Chaque objet Tile est associe a un nom dans un unordered_map.
 */
class TileMap {
public:

	/**
	 * @brief Constructeur pour une carte du jeu
	 * @param name Le nom de la carte du jeu, vide par defaut
	 */
	TileMap(std::string name = "") : name_(name) {}
	/**
	 * @brief Ajoute une case à la carte
	 * @param tile Reference de la case a ajouter
	 */
	void addTile(const Tile& tile);
	/**
	 * @brief Getter pour le nom de la carte
	 * @return Reference vers le nom de la carte
	 */
	const std::string& getName() const { return name_; }
	/**
	 * @brief Getter pour le map des cases du jeu
	 * @return Le map
	 */
	const std::unordered_map <std::string, std::shared_ptr<Tile>>& getTiles() const { return tiles_; }
	/**
	 * @brief Getter pour la premiere case du jeu
	 * @return La premiere case du jeu
	 */
	const std::weak_ptr<Tile>& getStartingTile() const { return startingTile_; }

	/**
	 * @brief Acces a un element Tile selon le nom
	 * @param name Le nom associe au Tile
	 * @return Pointeur vers le Tile associe au nom donne
	 */
	std::shared_ptr<Tile> operator[](const std::string& name) const { return tiles_.at(name); }

private:
	std::string name_; ///< Le nom associe au TileMap
	std::unordered_map <std::string, std::shared_ptr<Tile>> tiles_; ///< Map des cases de la carte
	std::weak_ptr<Tile> startingTile_; ///< La premiere case de la carte
};
