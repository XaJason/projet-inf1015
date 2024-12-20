#include "Actions.h"
#include "Direction.h"
#include "Exceptions.h"
#include "Item.h"
#include "Player.h"
#include "Tile.h"
#include <iosfwd>
#include <iostream>
#include <string>
#include <unordered_set>
#include <utility>

Item::Item(const std::string& name, const std::string& description, const std::string& usage, const std::unordered_set<std::string>& keywords, bool isTakeable) : name_(name), description_(description), usage_(usage), keywords_(keywords), isTakeable_(isTakeable) {}

std::ostream& Item::look(std::ostream& os) {
	return os << this->getDescription();
}

std::string Item::look() const
{
	return getDescription();
}

const string Item::take(Player& player)
{
	return "";
}

string Item::use([[maybe_unused]] Player& player)
{
	return usage_;
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


string CompassItem::use(Player& player)
{
	return "used CompassItem";
}

string TrashItem::use(Player& player)
{
	return "used TrashItem";
}

AccessItem::AccessItem(const string& name, const string& description, const unordered_set<string>& keywords, Tile* destination)
	: Item(name, description, "", keywords, false), destination_(destination)
{
}

string AccessItem::use(Player& player)
{
	player.setPosition(destination_);
	return  "You touched " + name_ + " and you have been teleported to the " + destination_->getName() + ".\n\n" + player.look();
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

KeyItem::KeyItem(const std::string& name, const std::string& description, const std::unordered_set<std::string>& keywords, bool isTakeable, const std::pair<Tile*, Tile*>& linkedTiles, const Direction& direction) : Item(name, description, "", keywords, isTakeable), linkedTiles_(linkedTiles), direction_(direction)
{
}

string KeyItem::use(Player& player)
{
	if (*player.getPosition() == *linkedTiles_.first) {
		linkedTiles_.first->dualConnect(linkedTiles_.second, direction_);
		return "Hello. Come and play with us. come and play with us at " + linkedTiles_.second->getName() + ". Forever... and ever... and ever.";
	}
	else {
		throw InvalidAction(name_ + " doesn't seem to fit anywhere.");
	}
}

bool Item::isTakeable() const
{
	return isTakeable_;
}