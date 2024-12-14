/**
* Classe TileMap
* \file   TileMap.h
* \author Bouisri et Xa
* \date   7 decembre 2024
* Créé le 6 decembre 2024
*/

#pragma once

#include "Direction.h"
#include "Tile.h"
#include <functional>
#include <map>
#include <memory>
#include <ostream>
#include <unordered_set>
#include <vector>

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
	TileMap(const std::string& name = "") : name_(name), tiles_(std::make_unique<std::unordered_map < std::string, std::unique_ptr<Tile>>>()), startingTile_() {
	}

	TileMap(const TileMap& other);

	//TileMap(const TileMap&) :
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
	const std::unordered_map <std::string, std::unique_ptr<Tile>>* getTiles() const { return tiles_.get(); }
	/**
	 * @brief Getter pour la premiere case du jeu
	 * @return La premiere case du jeu
	 */
	const Tile* getStartingTile() const { return startingTile_; }

	/**
	 * @brief Acces a un element Tile selon le nom
	 * @param name Le nom associe au Tile
	 * @return Pointeur vers le Tile associe au nom donne
	 */
	Tile* operator[](const std::string& name) const;

private:
	std::string name_; ///< Le nom associe au TileMap
	std::unique_ptr<std::unordered_map <std::string, std::unique_ptr<Tile>>> tiles_; ///< Map des cases de la carte
	Tile* startingTile_; ///< La premiere case de la carte
};
