// CharacterData.cpp

#include "CharacterData.h" // 必须包含它自己的头文件，来获取声明
#include <iostream>        // 因为 onTurnStart 用到了 cout
#include <algorithm>       // 因为 onTurnStart 用到了 min

// 使用 CharacterData:: 来指明这是 CharacterData 类的函数实现
CharacterData::CharacterData() :
    atk(100), def(100), crit_rate(5), crit_dmg(50), hp(1000), max_hp(1000),
    shield(0), element_master(0), energy(0), max_energy(100),
    skill_cooldown(0), skill_cooldown_max(3), element(water) {
}

CharacterData::~CharacterData() {
    std::cout << "Character data for '" + getCharacterType() + "' has been cleared." << std::endl;
}

bool CharacterData::isDead() const {
    return hp <= 0;
}

void CharacterData::onTurnStart() {
    std::cout << getCharacterType() + "'s turn begins." << std::endl;
    if (skill_cooldown > 0) {
        skill_cooldown--;
        std::cout << getCharacterType() + "'s skill cooldown is now " + std::to_string(skill_cooldown) << std::endl;
    }
    energy = std::min(max_energy, energy + 10);
}