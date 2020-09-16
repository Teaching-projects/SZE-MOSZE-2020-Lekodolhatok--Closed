#include "character.h"

Character::Character(const std::string& name, const int& hp, const int& dmg) :Name(name), HP(hp), DMG(dmg) {}

Character::~Character() {}

const std::string& Character::getName() {
    return Character::Name;
}

void Character::attackEnemy(Character& enemy) {
    std::cout << Character::Name << " -> " << enemy.Name << std::endl;
    if (enemy.HP - Character::DMG <= 0) {
        enemy.HP = 0;
    }
    else {
        enemy.HP -= Character::DMG;
    }
}

bool Character::isDead() const {
    return Character::HP <= 0;
}

std::ostream& operator<<(std::ostream& os, const Character& ch) {
    os << ch.Name << ": HP: " << ch.HP << ", DMG: " << ch.DMG << std::endl;
    return os;
}