#pragma once
// ActionSystem.cpp
#include "ActionSystem.h" // 包含自己的头文件
#include "CharacterData.h"    // 包含 Character 的完整定义，因为要用到它的成员函数和数据
#include <iostream>

// 使用 ActionSystem:: 来指明这是在实现 ActionSystem 类的函数
void ActionSystem::applyDamage(Character& target, int damage) {
    auto& data = target.getData();
    if (data.isDead()) return;

    int actual_damage = std::max(0, damage - data.def);
    data.hp -= actual_damage;
    std::cout << data.name << " takes " << actual_damage << " damage. HP: " << data.hp << std::endl;

    if (data.isDead()) {
        data.hp = 0;
        std::cout << data.name << " has been defeated!" << std::endl;
    }
}

void ActionSystem::performAttack(Character& attacker, Character& target) {
    // ...把其他函数的实现也像这样放进来...
}

// ...以此类推...