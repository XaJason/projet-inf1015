#pragma once

/**
 * @brief Namespace qui contient les classes necessaires pour ajouter un objet a l'inventaire.
 */
namespace taking {

	/**
	 * @brief Classe de base des objets pouvant etre ajoute a l'inventaire par un objet Taker
	 */
	class Takeable {}; 

	/**
	 * @brief Classe permettant de definir la prise d'un objet Takeable
	 */
	class Taker {
		/**
		 * @brief Ajouter un item a l'inventaire d'une instance de ItemTaker
		 * @param t l'objet Takeable a ajouter a l'inventaire
		 * @return true si l'ajout de l'item a ete effectuee avec succes
		 */
		virtual bool take(Takeable& t);
	};
};
