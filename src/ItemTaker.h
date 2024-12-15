#pragma once
#include "Item.h"

class ItemTaker {
	virtual bool take(const Item& item);
};
