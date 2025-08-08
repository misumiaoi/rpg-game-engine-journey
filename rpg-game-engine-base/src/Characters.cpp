#include "characters.h"
#include <iostream>


Characters::Characters() {
	atk = 100;
	def = 100;
	crit_rate = 0;
	crit_dmg = 0;
	hp = 1000;
	element_master = 0;
	element = water; // Default element
	Characters::shield = 0; // Initialize shield
	setifDead(false); // Initialize if_dead

}

Characters::~Characters() {
	std::cout << "Character diminished." << std::endl;
	// Destructor logic if needed
}