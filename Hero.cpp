#include "Hero.h"
#include "JSON.h"
#include <cmath>
#include <iostream>

Hero::Hero(const std::string& name, int hp, const int dmg, const int attackspeed) : Monster(name, hp, dmg, attackspeed) {
	MaxHP = hp;
}

int Hero::getMaxHealthPoints() const {
	return MaxHP;
}

int Hero::getLevel() const {
	return Level;
}

int Hero::getXP() const {
	return XP;
}
void Hero::Attack(Monster& enemy) {
	if (enemy.getHealthPoints() - this->getDamage() <= 0) {
		this->XP += enemy.getHealthPoints();
		enemy.getAttacked(this->getDamage());
	}
	else {
		this->XP += this->getDamage();
		enemy.getAttacked(this->getDamage());
	}

	if (this->XP >= 100) {
		lvlUp();
	}
}

Hero Hero::parse(char*& s) {
	JSON file = JSON::parseFromFile(s);
	int dmg=file.get<int>("dmg");
	int hp = file.get<int>("hp");
	int as = file.get<int>("attackcooldown");
	std::string name = file.get<int>("name");
	return Hero(name, hp, dmg, as);
}

//szintnoveles
//eletero es tamadoero a 10%-kal no
//maximalis eletero az megvaltozott eletero erteket veszi fel
//XP-t 100-zal csokkentjuk

 int Hero::lvlUp() {
	int counter = XP % 100;
	for (int i = 0; i < counter; i++)
	{
		this->setHP(std::lround((MaxHP * 1.1)));
		this->setDMG(std::lround((this->getDamage() * 1.1)));
		MaxHP = this->getHealthPoints();
		Level++;
		XP -= 100;
	}

	return XP;
}

//parse es az attack hiányzik, azt nem tudtam megcsinálni