#include "Item.h"
#include <iostream>

std::ostream& operator<<(std::ostream& outputStream, const Item& item)
{
	return outputStream << item.getName() << " : " << item.getDescription();
}
