// ActionSystem.h
#pragma once
#include <algorithm> // 因为会用到 std::max, std::min
#include <iostream>  // 因为会用到 std::cout

// 需要向前声明 Character 类，因为函数参数用到了它
class Character;

class ActionSystem {
public:
    // 只留下函数的声明，用分号结尾
    void applyDamage(Character& target, int damage);
    void performAttack(Character& attacker, Character& target);
    void performSkill(Character& attacker, Character& target);
    void performBurst(Character& attacker, Character& target);
};