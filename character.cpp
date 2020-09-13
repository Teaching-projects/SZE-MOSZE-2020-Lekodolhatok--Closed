#include "character.h"

Character::Character(std::string name, int hp, int dmg) :Name(name), HP(hp), DMG(dmg) {}

Character::~Character() {}

std::string Character::getName() {
	return Character::Name;
}

void Character::AttackEnemy(Character& enemy) {
	std::cout << Character::Name << " -> " << enemy.Name << std::endl;
	if (enemy.HP - Character::DMG <= 0) {
		enemy.HP = 0;
	}
	else {
		enemy.HP -= Character::DMG;
	}
}

bool Character::isDead() {
	return Character::HP <= 0 ? true : false;
}

std::ostream& operator<<(std::ostream& os, const Character& ch) {
	os << ch.Name << ": HP: " << ch.HP << ", DMG: " << ch.DMG << std::endl;
	return os;
}