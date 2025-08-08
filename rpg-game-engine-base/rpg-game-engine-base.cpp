#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <algorithm> // For std::min, std::max
#include "CharacterData.h" // Include the CharacterData header for the Character class.
#include "ActionSystem.h"
#include "CharacterBehavior.h"
#include "CharacterData.h"

// --- Forward Declarations ---
// Pre-declaring classes that are used by others before they are fully defined.
class Character;
class ActionSystem;

// --- Pure Data Layer ---
// A simple struct to hold all character stats. No logic, no virtual functions.


// --- Behavior Interface (Strategy Pattern) ---
// It defines WHAT a character can do, but not HOW.


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


// --- Concrete Behavior Implementations ---
// These classes provide the actual logic (the "HOW").

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
