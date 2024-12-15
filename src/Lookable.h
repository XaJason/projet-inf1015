#pragma once

#include <ostream>
/**
 * @brief Classe permettant de definir le comportement d'un element a regarder
 */
class Lookable {
	public:
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
