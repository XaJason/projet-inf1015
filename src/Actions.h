#pragma once
#include <string>

/**
 * @brief Namespace qui contient les classes necessaires pour effectuer des actions
 */
namespace actions {
	// =============
	// 		LOOKING
	// =============

	/**
	 * @brief Classe permettant de definir le comportement d'un element a regarder
	 */
	class Lookable {
		public:
			/**
			 * @brief Construction d'un objet Lookable
			 * @param description La description a afficher
			 */
			Lookable(std::string description) : description_(description) {}

			/**
			 * @brief Methode permettant de regarder un objet. Sa description est affichee.
			 * @param os flux de sortie
			 * @return flux de sortie
			 */
			std::ostream& look(std::ostream& os) {
				return os << this->description_;
			}

		protected:
			std::string description_;
	};

	// =============
	// 		TAKING
	// =============

	/**
	 * @brief Classe de base des objets pouvant etre pris par un type Taker
	 */
	class Takeable {}; 

	/**
	 * @brief Classe de base des objets pouvant prendre un objet Takeable
	 */
	class Taker {
		/**
		 * @brief Ajouter un item a l'inventaire d'une instance de ItemTaker
		 * @param t l'objet Takeable a ajouter a l'inventaire
		 * @return true si l'ajout de l'item a ete effectuee avec succes
		 */
		virtual bool take(Takeable& t) = 0;
	};
	
	// =============
	// 		USING
	// =============
	
	/**
	 * @brief Classe de base des objets pouvant etre utilises par un objet User
	 */
	class Useable {
		/**
		 * @brief Methode permettant d'utiliser un objet Useable, sans aucun parametre.
		 */
		virtual bool use() = 0;
		/**
		 * @brief Methode permettant d'utiliser un objet Useable, avec acces au Taker qui utilise l'objet
		 * @param t Objet necessaire a l'utilisation 
		 */
		virtual bool use(Taker& t) = 0;
	};


	/**
	 * @brief Classe de base des objets pouvant utiliser des objets Useable
	 */
	class User {
		/**
		 * @brief Methode permettant de definir comment utiliser un objet Useable
		 * @param u Reference a un objet Useable
		 */
		virtual bool use(Useable& u) = 0;
	};
};
