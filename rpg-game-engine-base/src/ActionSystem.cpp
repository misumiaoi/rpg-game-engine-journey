#include <iostream>
#include "ActionSystem.h"
#include "Characters.h"

int ActionSystem::CountDamage(Characters& chara1, Characters& chara2) {
	if(chara1.getHP() <= 0 || chara2.getHP() <= 0) {
		std::cout << "One of the characters is already defeated." << std::endl;
		return 0; // No damage if one character is dead
	}
	int damage = chara1.getAtk() - chara2.getDef();
	
	return damage;
}

void ActionSystem::NormalAttack(Characters& chara1, Characters& chara2) {
	if (chara1.getHP() <= 0 || chara2.getHP() <= 0) {
		std::cout << "One of the characters is already defeated." << std::endl;
		return;
	}
	int damage = chara1.getAtk() - chara2.getDef();
	if (damage < 0) damage = 0; // Prevent negative damage
	chara2.setHp(chara2.getHP() - damage);
	std::cout << "Character 1 attacks Character 2 for " << damage << " damage." << std::endl;
	if (chara2.getHP() <= 0) {
		std::cout << "Character 2 has been defeated!" << std::endl;
		chara2.setifDead(true); // Mark character as dead
	} else {
		std::cout << "Character 2's remaining HP: " << chara2.getHP() << std::endl;
	}
}

void ActionSystem::CriticalAttack(Characters& chara1, Characters& chara2) {
	if (chara1.getHP() <= 0 || chara2.getHP() <= 0) {
		std::cout << "One of the characters is already defeated." << std::endl;
		return;
	}
	int critRate = chara1.getCritRate();
	if (rand() % 100 < critRate) { // Check if critical hit occurs
		int damage = (chara1.getAtk() * chara1.getCritDmg()) / 100 - chara2.getDef();
		if (damage < 0) damage = 0; // Prevent negative damage
		chara2.setHp(chara2.getHP() - damage);
		std::cout << "Critical hit! Character 1 attacks Character 2 for " << damage << " damage." << std::endl;
	} else {
		std::cout << "Character 1's attack was not a critical hit." << std::endl;
	}
	if (chara2.getHP() <= 0) {
		std::cout << "Character 2 has been defeated!" << std::endl;
		chara2.setifDead(true); // Mark character as dead
	} else {
		std::cout << "Character 2's remaining HP: " << chara2.getHP() << std::endl;
	}
}

void ActionSystem::ElementalSkill(Characters& chara1, Characters& chara2) {
	if (chara1.getHP() <= 0 || chara2.getHP() <= 0) {
		std::cout << "One of the characters is already defeated." << std::endl;
		return;
	}
	int damage = chara1.getAtk() - chara2.getDef();
	if (damage < 0) damage = 0; // Prevent negative damage
	chara2.setHp(chara2.getHP() - damage);
	std::cout << "Character 1 uses Elemental Skill on Character 2 for " << damage << " damage." << std::endl;
	if (chara2.getHP() <= 0) {
		std::cout << "Character 2 has been defeated!" << std::endl;
		chara2.setifDead(true); // Mark character as dead
	} else {
		std::cout << "Character 2's remaining HP: " << chara2.getHP() << std::endl;
	}
}

void ActionSystem::ElementalBurst(Characters& chara1, Characters& chara2) {
	if (chara1.getHP() <= 0 || chara2.getHP() <= 0) {
		std::cout << "One of the characters is already defeated." << std::endl;
		return;
	}
	int damage = (chara1.getAtk() * 2) - chara2.getDef(); // Elemental Burst deals double damage
	if (damage < 0) damage = 0; // Prevent negative damage
	chara2.setHp(chara2.getHP() - damage);
	std::cout << "Character 1 uses Elemental Burst on Character 2 for " << damage << " damage." << std::endl;
	if (chara2.getHP() <= 0) {
		std::cout << "Character 2 has been defeated!" << std::endl;
		chara2.setifDead(true); // Mark character as dead
	} else {
		std::cout << "Character 2's remaining HP: " << chara2.getHP() << std::endl;
	}
}

void ActionSystem::ElementMasterCollect(Characters& chara1, int amount)
{
	chara1.setElementMaster(chara1.getElementMaster() + amount);
	std::cout << "Character 1 collects " << amount << " Element Master. Total: " << chara1.getElementMaster() << std::endl;
	if (chara1.getElementMaster() < 0) {
		chara1.setElementMaster(0); // Prevent negative Element Master
		std::cout << "Element Master cannot be negative. Reset to 0." << std::endl;
	}
}

void ActionSystem::CombatAttack(Characters& chara1, Characters& chara2) {
	if (chara1.getHP() <= 0 || chara2.getHP() <= 0) {
		std::cout << "One of the characters is already defeated." << std::endl;
		return;
	}
	int damage = CountDamage(chara1, chara2);
	if (damage < 0) damage = 0; // Prevent negative damage
	chara2.setHp(chara2.getHP() - damage);
	std::cout << "Character 1 attacks Character 2 for " << damage << " damage." << std::endl;
	if (chara2.getHP() <= 0) {
		std::cout << "Character 2 has been defeated!" << std::endl;
		chara2.setifDead(true); // Mark character as dead
	} else {
		std::cout << "Character 2's remaining HP: " << chara2.getHP() << std::endl;
	}
}

int ActionSystem::ShieldCollect(Characters& chara, int amount)
{

	return chara.getShield() + amount;
}

int ActionSystem::SelfHeal(Characters& chara, int amount) {
	if (chara.getHP() <= 0) {
		std::cout << "Character is already defeated and cannot heal." << std::endl;
		return 0; // No healing if character is dead
	}
	chara.setHp(chara.getHP() + amount);
	std::cout << "Character heals for " << amount << " HP. Total HP: " << chara.getHP() << std::endl;
	return amount;
}

int ActionSystem::HealFrom(Characters& chara1, Characters& chara2, int amount) {
	if (chara1.getHP() <= 0 || chara2.getHP() <= 0) {
		std::cout << "One of the characters is already defeated and cannot heal." << std::endl;
		return 0; // No healing if one character is dead
	}
	chara1.setHp(chara1.getHP() + amount);
	chara2.setHp(chara2.getHP() - amount); // Character 2 loses the healing amount
	std::cout << "Character 1 heals for " << amount << " HP from Character 2. Total HP: " << chara1.getHP() << std::endl;
	std::cout << "Character 2 loses " << amount << " HP. Remaining HP: " << chara2.getHP() << std::endl;
	return amount;
}

int ActionSystem::SelfRevive(Characters& chara, int amount) {
	if (!chara.getifDead()) {
		std::cout << "Character is not dead and cannot be revived." << std::endl;
		return 0; // No revival if character is not dead
	}
	chara.setHp(amount); // Revive with specified HP
	chara.setifDead(false); // Mark character as alive
	std::cout << "Character revives with " << amount << " HP." << std::endl;
	return amount;
}

bool ActionSystem::check_ifDeadamongBattle(Characters& chara1, Characters& chara2) {
    if (chara1.getifDead()) {
        std::cout << "Character 1 is dead." << std::endl;
    } else {
        std::cout << "Character 1 is alive with " << chara1.getHP() << " HP." << std::endl;
    }
    if (chara2.getifDead()) {
        std::cout << "Character 2 is dead." << std::endl;
    } else {
        std::cout << "Character 2 is alive with " << chara2.getHP() << " HP." << std::endl;
    }
    return chara1.getifDead() || chara2.getifDead();
}