#pragma once

class Characters {

public:
	enum elements {
		water, fire, grass, rock, electric, ice, wind, hikari, tairitsu
	};

	Characters();
	~Characters();

	void setAtk(int init) { atk = init; }
	void setDef(int init) { def = init; }
	void setCritRate(int init) { crit_rate = init; }
	void setCritDmg(int init) { crit_dmg = init; }
	void setHp(int init) { hp = init; }
	void setElementMaster(int init) { element_master = init; }
	void setShield(int init) { shield = init; }
	void setifDead(bool init) { if_dead = init; }

	int getAtk() { return atk; }
	int getDef() { return def; }
	int getCritRate() { return crit_rate; }
	int getCritDmg() { return crit_dmg; }
	int getHP() { return hp; }
	int getShield() { return shield; }
	int getElementMaster() { return element_master; }
	bool getifDead() { return if_dead; }

	virtual void setElement(int init) {
		if (init >= water && init <= tairitsu)
			element = static_cast<elements>(init);
	}

private:
	int atk, def, crit_dmg, hp, element_master;
	float crit_rate;
	elements element;
	int shield; 
	bool is_activated = false;
	bool if_dead = false;

};