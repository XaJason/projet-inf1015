#include "Item.h"
#include <iostream>

std::ostream& Item::look(std::ostream& os) {
	return os << this->getDescription();
}

std::ostream& operator<<(std::ostream& outputStream, const Item& item)
{
	return outputStream << item.getName() << " : " << item.getDescription();
}
