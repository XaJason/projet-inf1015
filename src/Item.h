#pragma once
#include "Lookable.h"
#include "TileMap.h"
#include <string>
class Player;

// TODO: Interface lookable (useable and takeable ?)
	/**
	 * @class Item
	 * @brief Represente un objet dans le monde du jeu
	 *
	 * La classe Item represente un objet pouvant etre collecte par le Player.
	 */
class Item : public Lookable {
public:
	/**
	 * @brief Constructeur d'un Item
	 * @param name Le nom de l'item
	 * @param description La description de l'item
	 */
	Item(std::string name = "", std::string description = "") : name_(name), Lookable(description) {}
	/**
	 * @brief Getter pour le nom associe a l'item
	 * @return Le nom associe a l'item
	 */
	std::string getName() const { return name_; }
	/**
	 * @brief Getter pour la description de l'item
	 * @return La description de l'item
	 */
	std::string getDescription() const { return description_; }

	/**
	 * @brief Methode permettant d'ajouter un item a l'inventaire d'un joueur
	 * @param player La reference au Player qui prend l'item
	 * @return true si l'item a ete ajoute a l'inventaire du joueur avec succes
	 */
	bool take(const Player& player);

	/**
	 * @brief Methode permettant d'utiliser un item.
	 * @param player Reference au joueur qui utilise l'item
	 * @return true si l'item a ete utilise avec succes
	 */
	virtual bool use(const Player& player) = 0;

	/**
	 * @brief Surcharge de l'operateur d'affichage
	 * @param outputStream flux de sortie
	 * @param item L'item a afficher
	 * @return Flux de sortie
	 */
	friend std::ostream& operator<<(std::ostream& outputStream, const Item& item);

private:
	std::string name_; ///< Nom associe a l'item
	std::string description_; ///< Description de l'item
};

/**
 * @class KeyItem
 * @brief Item permettant d'acceder a de nouvelles salles.
 */
class KeyItem : public Item {
public:
	using Item::Item;
	KeyItem() : Item("Key", "Unlock new rooms") {};
	bool use(const Player& player) override { return false; }
};

/**
 * @class CompassItem
 * @brief Item permettant de trouver la direction de la sortie
 */
class CompassItem : public Item {
public:
	using Item::Item;
	CompassItem() : Item("Compass", "Find the direction of the exit from current position") {};
	bool use(const Player& player) override { return false; }
};

class TrashItem : public Item {
public:
	using Item::Item;
	TrashItem() : Item("Trash", "A waste of space. Don't take it.") {};
	bool use(const Player& player) override { return false; }
};
