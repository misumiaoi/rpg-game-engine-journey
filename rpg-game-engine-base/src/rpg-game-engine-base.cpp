#include <iostream>
#include <memory>

template <typename type>
void print(type input) {
	std::cout << input << std::endl;
}

template <typename type>
void read(type& readed) {
	std::cin >> readed;
}

class Characters {
public:
	enum elements {
		water, fire, grass, rock, electric, ice, wind, hikari, tairitsu
	};

	Characters() {
		atk = 100;
		def = 100;
		crit_rate = 0;
		crit_dmg = 0;
		hp = 1000;
		element_master = 0;
		element = water;
	}

	void setElements(int init) {
		if (init >= water && init <= tairitsu)
			element = static_cast<elements>(init);
	}

	int getHP() { return hp; }
	void setAtk(int init) { atk = init; }
	void setDef(int init) { def = init; }
	void setCritRate(int init) { crit_rate = init; }
	void setCritDmg(int init) { crit_dmg = init; }
	void setHp(int init) { hp = init; }
	void setElementMaster(int init) { element_master = init; }

	int getAtk() { return atk; }
	int getDef() { return def; }
	int getCritRate() { return crit_rate; }
	int getCritDmg() { return crit_dmg; }

	virtual void setElement(int init) {
		if (init >= water && init <= tairitsu)
			element = static_cast<elements>(init);
	}

private:
	int atk, def, crit_rate, crit_dmg, hp, element_master;
	elements element;
	bool is_activated = false;
	bool if_dead = false;
};

class MondstadtCharacter : public Characters {
public:
	MondstadtCharacter() {
		this->setElements(6); // wind
	}

	void setAtk(int init) {
		Characters::setAtk(init + 50);
	}

	void setElement(int init) override {
		if (init == 6)
			Characters::setElement(init);
		else
			std::cout << "Invalid element for MondstadtCharacter. Must be wind." << std::endl;
	}

	~MondstadtCharacter() {
		print("The winds of Mondstadt carry tales of freedom and adventure.");
	}
};

class LiyueCharacter : public Characters {
public:
	LiyueCharacter() {
		this->setElements(3); // rock
	}

	~LiyueCharacter() {
		print("The mountains of Liyue are silent, but their strength remains.");
	}
};

class FontaineCharacter : public Characters {
public:
	FontaineCharacter() {
		this->setElements(0); // water
		this->setCritRate(20);
	}

	~FontaineCharacter() {
		print("The waters of Fontaine whisper secrets of the deep.");
	}
};

class CharacterFromArcaea : public Characters {
public:
	CharacterFromArcaea() {
		print("Was this character born in light or dark?");
		int characterset = 0;
		read(characterset);
		if (characterset == 0)
			this->setElements(7); // hikari
		else if (characterset == 1)
			this->setElements(8); // tairitsu
		else {
			std::cout << "Invalid choice. Defaulting to 'hikari'." << std::endl;
			this->setElements(7);
		}
	}

	~CharacterFromArcaea() {
		print("She diminished in a shade of light, without music or conflict");
	}
};

class CharacterActions : public Characters {
	void attack(Characters& target, int amount) {
		std::cout << "Attacking target!" << std::endl;
		target.setHp(target.getHP() - amount);
	}

	void defend() {
		std::cout << "Defending!" << std::endl;
		// Implement defend logic here
	}

	void heal(Characters& target, int amount) {
		std::cout << "Healing for " << amount << " HP!" << std::endl;
		target.setHp(target.getHP() + amount);
		// Implement healing logic here
	}

	void elementBurst(Characters& target, Characters::elements elementType) {
		std::cout << "Using Element Burst with element type: " << elementType << std::endl;
		int baseAtk = this->getAtk();
		int critRate = this->getCritRate();
		int critDmg = this->getCritDmg();

		int damage = static_cast<int>(baseAtk * 1.5);
		int roll = rand() % 100;
		bool isCrit = (roll < critRate);

		if (isCrit) {
			damage += static_cast<int>(damage * (critDmg / 100.0));
			std::cout << "Critical Hit! ";
		}

		std::cout << "Element Burst deals " << damage << " damage!" << std::endl;
		target.setHp(target.getHP() - damage);
	}

	void elementSkill(Characters& target, Characters::elements elementType) {
		std::cout << "Using Element Skill with element type: " << elementType << std::endl;
		// Implement element skill logic here
	}
};

int main() {

	std::cout << "Welcome to the RPG Game Engine!" << std::endl;
	print("Actually it is still under progress \n coming soon! Please wait for more time~");
	return 0;
}