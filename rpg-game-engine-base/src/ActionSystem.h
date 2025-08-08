#pragma once
#include "Characters.h"
#include <iostream>

class ActionSystem {

	int CountDamage(Characters& chara1, Characters& chara2);
	int ShieldCollect(Characters& chara, int amount);
	void NormalAttack(Characters& chara1, Characters& chara2); 
	void ElementalSkill(Characters& chara1, Characters& chara2);
	void CriticalAttack(Characters& chara1, Characters& chara2);
	void ElementalBurst(Characters& chara1, Characters& chara2);
	void ElementMasterCollect(Characters& chara1, int amount);
	int SelfHeal(Characters& chara, int amount);
	int HealFrom(Characters& chara1, Characters& chara2, int amount);
	int SelfRevive(Characters& chara, int amount);
	void CombatAttack(Characters& chara1, Characters& chara2);
	bool check_ifDeadamongBattle(Characters& chara1, Characters& chara2);
	
};