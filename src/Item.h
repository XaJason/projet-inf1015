#pragma once
#include "Actions.h"
#include "TileMap.h"
#include <string>
#include<unordered_set>

using namespace actions;

class Player;

	/**
	 * @class Item
	 * @brief Represente un objet dans le monde du jeu
	 *
	 * La classe Item represente un objet pouvant etre collecte par le Player.
	 */
class Item : public Lookable, public Takeable, public Useable {
public:
	/**
	 * @brief Constructeur d'un Item
	 * @param name Le nom de l'item
	 * @param description La description de l'item
	 */
	Item(const std::string& name, const std::string& description, const std::string& usage, const std::unordered_set<std::string>& keywords = {});
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
	 * @brief Methode permettant d'afficher la description d'un item
	 * @param os Le flux de sortie
	 */
	std::ostream& look(std::ostream& os);

	std::string look() const override;

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
	virtual string use([[maybe_unused]] Player& player);

	virtual const Tile* use() override;

	 bool use(Taker& t) override;

	 bool containsKeyword(const string& word);

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
	std::string usage_; ///< message d'utilisation de l'item
	std::unordered_set<string> keywords_;
};

/**
 * @class KeyItem
 * @brief Item permettant d'acceder a de nouvelles salles.
 */
class KeyItem : public Item {
public:
	using Item::Item;
	//string use(Player& player) override;
};

/**
 * @class CompassItem
 * @brief Item permettant de trouver la direction de la sortie
 */
class CompassItem : public Item {
public:
	using Item::Item;
	string use(Player& player) override;
};

class TrashItem : public Item {
public:
	using Item::Item;
	string use(Player& player) override;
};

class AccessItem : public Item {
public:
	using Item::Item;
	AccessItem(const string& name, const string& description, const unordered_set<string>& keywords, const Tile* destination);
	string use(Player& player) override;
	const Tile* use() override;
private :
	const Tile* destination_;
};