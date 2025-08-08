#pragma once
// CharacterData.h

#pragma once // 这是一个非常重要的指令，保证这个头文件在编译时只被包含一次，防止重复定义的错误。

#include <string> // 因为用到了 std::string

class ActionSystem; // 向前声明，告诉编译器有这么一个类，但我们不在乎它的细节。

class CharacterData {
public:
    enum Elements { water, fire, grass, rock, electric, ice, wind, hikari, tairitsu };

    CharacterData(); // 只保留声明
    virtual ~CharacterData(); // 只保留声明

    // --- 核心属性 ---
    int atk, def, crit_rate, crit_dmg, hp, max_hp, shield, element_master;
    int energy;
    int max_energy;
    int skill_cooldown;
    int skill_cooldown_max;
	std::string name; // 角色名称
    Elements element;

    // --- 行为定义 ---
    virtual std::string getCharacterType() const = 0;
    virtual void elementSkill(ActionSystem& ctx, CharacterData& self, CharacterData& target) = 0;
    virtual void elementalBurst(ActionSystem& ctx, CharacterData& self, CharacterData& target) = 0;
	virtual void normalAttack(ActionSystem& ctx, CharacterData& self, CharacterData& target) = 0;
    virtual void getName(std::string& name) = 0;

    // --- 状态检查 ---
    bool isDead() const; // 只保留声明

    // --- 回合更新器 ---
    virtual void onTurnStart(); // 只保留声明
};