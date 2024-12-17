/**
* Classe Tile
* \file   Tile.h
* \author Bouisri et Xa
* \date   7 decembre 2024
* Créé le 6 decembre 2024
*/
#pragma once
#include "Direction.h"
#include "Actions.h"
#include <array>
#include <boost/functional/hash.hpp>
#include <memory>
#include <string>
#include <unordered_map>

class Item;

using namespace std;
using namespace actions;

/**
  * @class Tile
  * @brief Représente une case dans la carte du jeu.
  *
  * La classe Tile represente une case individuelle dans la carte du jeu.
  * Elle peut etre connectee a d'autres cases dans les directions cardinales
  * et contenir des objets du jeu.
  */
// TODO : derive de Taker (pour ajout d'items)
class Tile : public Lookable {
public:
	/**
	 * @brief Constructeur de la classe Tile
	 * @param name Le nom associe a la case
	 * @param description La description de la case
	 */
	Tile(std::string name = "", std::string description = "") : name_(name), description_(description) {}
	~Tile() = default;

	std::string look() const override;

	/**
	 * @brief Connecte une case a une autre dans une direction donne.
	 * @param other Pointeur vers la case a connecter
	 * @param direction La direction vers laquelle connecter la case
	 */
	void connect(Tile* other, Direction direction);
	/**
	 * @brief Connecte la case à quatre autres cases dans les directions cardinales.
	 * @param northTile Pointeur vers la case au nord.
	 * @param southTile Pointeur vers la case au sud.
	 * @param westTile Pointeur vers la case à l'ouest.
	 * @param eastTile Pointeur vers la case à l'est.
	 */
	void connect(Tile* northTile, Tile* southTile, Tile* westTile, Tile* eastTile);
	/**
	 * @brief Ajoute un objet a la case
	 * @param item L'objet a ajouter
	 */
	void addItem(const shared_ptr<Item>& item);

	const std::unordered_map<std::string, shared_ptr<Item>>::const_iterator getItemIterator(const string& details) const;

	/**
	 * @brief Getter pour le nom de la case
	 * @return Le nom associe a la case
	 */
	std::string getName() const { return name_; }
	/**
	 * @brief Getter pour la description de la case
	 * @return La description de la case
	 */
	std::string getDescription() const { return description_; }
	/**
	 * @brief Getter pour les connections de la case
	 * @rturn Les connections de la case
	 */
	auto getConnections() const { return connections_; }
	/**
	 * @brief Getter pour la connection de cette instance dans une direction donnee
	 * @param direction La direction associee a la connection
	 * @return Reference faible vers la case connectee a cette instance dans la direction donnee
	 */
	const Tile* getConnection(Direction direction) const {
		auto it = connections_.find(direction);
		if (it != connections_.end()) {
			return it->second;
		}
		return nullptr;
	}

	const auto& getItems() const { return items_; }
	/**
	 * @brief Surcharge de l'operateur d'affichage de la case
	 * @param outputStream Flux de sortie
	 * @param tile La case a afficher
	 * @return Le flux de sortie modifie
	 */
	friend std::ostream& operator<<(std::ostream& outputStream, const Tile& tile);

	bool operator==(const Tile& other) const;
	void dualConnect(Tile* other, Direction direction);
private:
	std::string name_; ///< Le nom associe a la case
	std::string description_; ///< La description de la case
	std::unordered_map<Direction, Tile*> connections_; ///< Le map des connections associees a une direction
	std::unordered_map<std::string, shared_ptr<Item>> items_; ///< Le map des objets dans la case
};
