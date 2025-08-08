#include <iostream>
#include "CharacterBehavior.h"
#include "CharacterData.h"


class MondstadtBehavior : public ICharacterBehavior {
public:
    void performSkill(ActionSystem& ctx, Character& attacker, Character& target) override {
        std::cout << attacker.getData().name << " uses Gale Blade!" << std::endl;
        ctx.applyDamage(target, attacker.getData().atk * 1.2);
    }
    void performBurst(ActionSystem& ctx, Character& attacker, Character& target) override {
        std::cout << attacker.getData().name << " unleashes Dandelion Breeze!" << std::endl;
        ctx.applyDamage(target, attacker.getData().atk * 2.0);
    }
};

class LiyueBehavior : public ICharacterBehavior {
public:
    void performSkill(ActionSystem& ctx, Character& attacker, Character& target) override {
        std::cout << attacker.getData().name << " summons a Jade Shield!" << std::endl;
        // Logic for shield would go here. For simplicity, we'll just do a small attack.
        ctx.applyDamage(target, attacker.getData().def * 0.5);
    }
    void performBurst(ActionSystem& ctx, Character& attacker, Character& target) override {
        std::cout << attacker.getData().name << " calls down Planet Befall!" << std::endl;
        ctx.applyDamage(target, attacker.getData().max_hp * 0.2);
    }
};
