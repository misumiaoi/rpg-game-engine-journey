#pragma once
class ICharacterBehavior {
public:
    virtual ~ICharacterBehavior() = default;
    virtual void performSkill(ActionSystem& ctx, Character& attacker, Character& target) = 0;
    virtual void performBurst(ActionSystem& ctx, Character& attacker, Character& target) = 0;
};