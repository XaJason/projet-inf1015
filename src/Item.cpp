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

const Tile* Item::use()
{
	return nullptr;
}

bool Item::use(Taker& t)
{
	return false;
}

std::ostream& operator<<(std::ostream& outputStream, const Item& item)
{
	return outputStream << item.getName() << " : " << item.getDescription();
}

string KeyItem::use(Player& player)
{
	return "used KeyItem";
}

string CompassItem::use(Player& player)
{
	return "used CompassItem";
}

string TrashItem::use(Player& player)
{
	return "used TrashItem";
}

AccessItem::AccessItem(const string& name, const string& description, const unordered_set<string>& keywords, const Tile* destination) : Item(name, description, keywords), destination_(destination)
{
}

string AccessItem::use(Player& player)
{
	player.setPosition(destination_);
	return player.getPosition()->look();
}

const Tile* AccessItem::use()
{
	return destination_;
}

bool Item::containsKeyword(const string& word)
{
	if (keywords_.contains(word))
		return true;

	for (const auto& keyword : keywords_)
		{
			if (word.find(keyword) != string::npos)
				return true;
		}
	return false;
}
