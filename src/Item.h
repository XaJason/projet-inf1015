#pragma once
#include <string>

namespace game_world {
	/**
	 * @class Item
	 * @brief Represente un objet dans le monde du jeu
	 * 
	 * La classe Item represente un objet pouvant etre collecte par le Player.
	 */
	class Item {
	public:
		/**
		 * @brief Constructeur d'un Item
		 * @param name Le nom de l'item
		 * @param description La description de l'item
		 */
		Item(std::string name = "", std::string description = "") : name_(name), description_(description) {}
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
}
