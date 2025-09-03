#pragma once

#include <iostream>
#include <vector>
#include <math.h>
#include <memory>
#include <map>


class GeneralItems {

public:
	enum class ItemType {
		WEAPON,
		POISON,
		ARMOR,
		POTION,
		MISC,
		FOOD
	};

	bool in_use = false, collected = false;
	std::string item_name;
	std::string belongto;
	ItemType item_type;
	static std::map<std::string, std::shared_ptr<GeneralItems>> inventory;
	int level = 1;
	int price = 0;

	

};

class Weapon : public GeneralItems {
	Weapon() 
	{
		this->in_use = true; this->item_type = ItemType::WEAPON;
	}
};

class Food: public GeneralItems {
	Food() 
	{
		this->in_use = false; this->item_type = ItemType::FOOD;
	}
};

class Poison : public GeneralItems {
	Poison() { this->in_use = false; this->item_type = ItemType::POISON; }
};
