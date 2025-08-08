#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <algorithm> // For std::min, std::max

// --- Forward Declarations ---
// Pre-declaring classes that are used by others before they are fully defined.
class Character;
class ActionSystem;

// --- Pure Data Layer ---
// A simple struct to hold all character stats. No logic, no virtual functions.
struct CharacterData {
    std::string name;
    std::string character_type;
    int atk = 100, def = 100, crit_rate = 5, crit_dmg = 50;
    int hp = 1000, max_hp = 1000, shield = 0;
    int energy = 0, max_energy = 100;
    int skill_cooldown = 0, skill_cooldown_max = 3;

    bool isDead() const { return hp <= 0; }
};

// --- Behavior Interface (Strategy Pattern) ---
// It defines WHAT a character can do, but not HOW.
class ICharacterBehavior {
public:
    virtual ~ICharacterBehavior() = default;
    virtual void performSkill(ActionSystem& ctx, Character& attacker, Character& target) = 0;
    virtual void performBurst(ActionSystem& ctx, Character& attacker, Character& target) = 0;
};

// --- The "Live" Character Class ---
// This class brings together the Data and the Behavior.
class Character {
private:
    CharacterData data;
    std::unique_ptr<ICharacterBehavior> behavior;

public:
    // Constructor takes the data and behavior to "assemble" a character.
    Character(CharacterData d, std::unique_ptr<ICharacterBehavior> b)
        : data(std::move(d)), behavior(std::move(b)) {
    }

    // Provides access to the data and behavior.
    CharacterData& getData() { return data; }
    const CharacterData& getData() const { return data; }
    ICharacterBehavior* getBehavior() { return behavior.get(); }

    // A helper function for turn updates.
    void onTurnStart() {
        if (data.skill_cooldown > 0) {
            data.skill_cooldown--;
        }
        data.energy = std::min(data.max_energy, data.energy + 10);
    }
};

// --- Logic System (The "Game Rules" Engine) ---
// This class is still stateless. It operates on the final Character objects.
class ActionSystem {
public:
    void applyDamage(Character& target, int damage) {
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

    void performAttack(Character& attacker, Character& target) {
        auto& attacker_data = attacker.getData();
        if (attacker_data.isDead()) return;

        std::cout << attacker_data.name << " attacks " << target.getData().name << "!" << std::endl;
        applyDamage(target, attacker_data.atk);
        attacker_data.energy = std::min(attacker_data.max_energy, attacker_data.energy + 20);
    }

    void performSkill(Character& attacker, Character& target) {
        auto& attacker_data = attacker.getData();
        if (attacker_data.isDead()) return;
        if (attacker_data.skill_cooldown > 0) {
            std::cout << attacker_data.name << "'s skill is on cooldown!" << std::endl;
            return;
        }
        // Delegate the "how" to the character's specific behavior object.
        attacker.getBehavior()->performSkill(*this, attacker, target);
        attacker_data.skill_cooldown = attacker_data.skill_cooldown_max;
    }

    void performBurst(Character& attacker, Character& target) {
        auto& attacker_data = attacker.getData();
        if (attacker_data.isDead()) return;
        if (attacker_data.energy < attacker_data.max_energy) {
            std::cout << attacker_data.name << " does not have enough energy!" << std::endl;
            return;
        }
        attacker.getBehavior()->performBurst(*this, attacker, target);
        attacker_data.energy = 0;
    }
};

// --- Concrete Behavior Implementations ---
// These classes provide the actual logic (the "HOW").
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

// --- Character Factory ---
// This class knows how to "build" characters based on a type.
class CharacterFactory {
public:
    std::unique_ptr<Character> createCharacter(const std::string& type, const std::string& name) {
        if (type == "Mondstadt") {
            CharacterData data;
            data.name = name;
            data.character_type = type;
            data.atk += 20;
            return std::make_unique<Character>(std::move(data), std::make_unique<MondstadtBehavior>());
        }
        if (type == "Liyue") {
            CharacterData data;
            data.name = name;
            data.character_type = type;
            data.def += 50;
            data.max_hp += 500;
            data.hp = data.max_hp;
            return std::make_unique<Character>(std::move(data), std::make_unique<LiyueBehavior>());
        }
        throw std::runtime_error("Unknown character type requested.");
    }
};

// --- Main Game Loop ---
int main() {
    CharacterFactory factory;
    ActionSystem actions;

    auto jean = factory.createCharacter("Mondstadt", "Jean");
    auto zhongli = factory.createCharacter("Liyue", "Zhongli");

    std::cout << "--- Battle Start! ---" << std::endl;
    actions.performSkill(*jean, *zhongli);
    std::cout << "--------------------" << std::endl;
    actions.performAttack(*zhongli, *jean);
    std::cout << "--------------------" << std::endl;

    return 0;
}
