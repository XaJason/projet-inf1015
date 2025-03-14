/**
* Classe Player
* \file   Player.h
* \author Bouisri et Xa
* \date   7 decembre 2024
* Créé le 6 decembre 2024
*/
#pragma once
#include "Actions.h"
#include "Direction.h"
#include "Tile.h"
#include <iosfwd>
#include <memory>
#include <string>
#include <unordered_map>

using namespace actions;
class Item;

/**
 * @class Player
 * @brief Joueur dans le jeu
 * La classe Player permet de controler la position dans le z et les objets collectes par le jeu.
 */
class Player : public Taker, public User {
public:

	/**
	 * @brief Constructeur par defaut d'un Player
	 */



	 /**
	  * @brief Verifie si la position du joueur est invalide
	  * @return `true` si le joueur est dans une position invalide
	  */
	bool isPositionNull() const { return position_ == nullptr; }
	/**
	 * @brief Getter pour la position actuelle du joueur
	 * @return Reference faible vers la case actuelle du joueur
	 */
	const Tile* getPosition() const { return position_; }
	/**
	 * @brief Setter pour la position actuelle du joueur
	 * @param position Pointeur partage vers la case actuelle du joueur
	 */
	void setPosition(Tile* position) { position_ = position; }

	/**
 * @brief Deplace le Player dans une direction donnee
 * @param direction La direction dans laquelle le joueur se deplace
 */
	void moveInDirection(const Direction& direction);

	bool take(Takeable& t) override;

	bool use(Useable& u) override;

	const string take(const string& details);

	const string use(const string& details);

	const string look() const;

	const string look(const string& details) const;

	std::unordered_map<std::string, shared_ptr<Item>>::const_iterator findInInventory(const string& details) const;

	std::unordered_map<std::string, shared_ptr<Item>>::const_iterator findItem(const string& details) const;

	void addItem(std::unordered_map<std::string, std::shared_ptr<Item>>::node_type node);

	/**
	 * @brief Surcharge de l'operateur d'affichage du joueur
	 * @param outputStream Flux de sortie
	 * @param player L'instance de Player a afficher
	 * @return Flux de sortie
	 */
	friend std::ostream& operator<<(std::ostream& outputStream, const Player& player);

private:
	Tile* position_; ///< Position actuelle du joueur
	std::unordered_map<std::string, shared_ptr<Item>> items_; ///< Inventaire des objets du joueur
};
