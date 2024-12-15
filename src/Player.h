/**
* Classe Player
* \file   Player.h
* \author Bouisri et Xa
* \date   7 decembre 2024
* Créé le 6 decembre 2024
*/
#pragma once
#include "Actions.h"
#include "Tile.h"
#include <memory>
#include <ostream>
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
	 * @brief Deplace le Player dans une direction donnee
	 * @param direction La direction dans laquelle le joueur se deplace
	 */
	void move(const Direction& direction);
	/**
	 * @brief Ajoute un objet a l'inventaire du Player
	 * @param item L'objet a ajouter
	 */
	void addItem(std::shared_ptr<Item> item);

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
	void setPosition(const Tile* position) { position_ = position; }

	bool take(Takeable& t) override;

	bool use(Useable& u) override;

	/**
	 * @brief Surcharge de l'operateur d'affichage du joueur
	 * @param outputStream Flux de sortie
	 * @param player L'instance de Player a afficher
	 * @return Flux de sortie
	 */
	friend std::ostream& operator<<(std::ostream& outputStream, const Player& player);

private:
	const Tile* position_; ///< Position actuelle du joueur
	std::unordered_map<std::string, shared_ptr<Item>> items_; ///< Inventaire des objets du joueur
};
