#include "character.h"

Character::Character(std::string name, int hp, int dmg) :Name(name), HP(hp), DMG(dmg) {}

Character::~Character() {}

std::string Character::getName() {
	return Character::Name;
}

int Character::getHP() {
	return Character::HP;
}

int Character::getDMG() {
	return Character::DMG;
}

void Character::AttackEnemy(Character& enemy) {
	std::cout << Character::Name << " -> " << enemy.Name << std::endl;
}
std::ostream& operator<<(std::ostream& os, const Character& ch) {
	os << ch.Name << ": HP: " << ch.HP << ", DMG: " << ch.DMG << std::endl;
	return os;
}