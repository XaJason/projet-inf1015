#include "Item.h"
#include <iostream>

std::ostream& Item::look(std::ostream& os) {
	return os << this->getDescription();
}

std::ostream& operator<<(std::ostream& outputStream, const Item& item)
{
	return outputStream << item.getName() << " : " << item.getDescription();
}

/**
 * @brief Methode permettant d'utiliser un item.
 * @param player Reference au joueur qui utilise l'item
 * @return true si l'item a ete utilise avec succes
 */
 bool Item::use(const Player& player) { return true; }
