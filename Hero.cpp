#include "Hero.h"
#include "JSON.h"
#include <iostream>

Hero::Hero(const std::string& name, int hp, const int dmg, const int attackspeed) :Name(name), HP(hp), DMG(dmg), AttackSpeed(attackspeed) {
	MaxHP = hp;
}

int Hero::getMaxHealthPoint() const {
    return MaxHP;
}

 int Hero::getLevel() const {
     return Level;
 }

 int Hero::getXP() const {
     return XP;
 }

//szintnoveles
//eletero es tamadoero a 10%-kal no
//maximalis eletero az megvaltozott eletero erteket veszi fel
//XP-t 100-zal csokkentjuk
int Hero::lvlUp() {
	int counter = XP % 100;
	for (int i = 0; i < counter; i++)
	{
		HP = std::round((MaxHP * 1.1));
		DMG = std::round((DMG * 1.1));
		MaxHP = HP;
		Level++;
		XP -= 100;
	}

	return XP;
}

//parse es az attack hiányzik, azt nem tudtam megcsinálni