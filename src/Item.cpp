#include "Item.h"
#include <iostream>
#include "Player.h"

std::ostream& Item::look(std::ostream& os) {
	return os << this->getDescription();
}

std::string Item::look() const
{
	return getName() + " : " + getDescription();
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

bool KeyItem::use(Player& player)
{
	return false;
}

bool CompassItem::use(Player& player)
{
	return false;
}

bool TrashItem::use(Player& player)
{
	return false;
}

AccessItem::AccessItem(std::string name, std::string description, const Tile* destination) : Item(name, description), destination_(destination)
{
}

bool AccessItem::use(Player& player)
{
	player.setPosition(destination_);
	return true;
}
