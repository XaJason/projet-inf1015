#include "Item.h"
#include <iostream>

std::ostream& Item::look(std::ostream& os) {
	return os << this->getDescription();
}

bool Item::take(const Player& player)
{
	return false;
}

bool Item::use()
{
	return false;
}

bool Item::use(Taker& t)
{
	return false;
}

std::ostream& operator<<(std::ostream& outputStream, const Item& item)
{
	return outputStream << item.getName() << " : " << item.getDescription();
}

bool KeyItem::use(const Player& player)
{
	return false;
}

bool CompassItem::use(const Player& player)
{
	return false;
}

bool TrashItem::use(const Player& player)
{
	return false;
}
