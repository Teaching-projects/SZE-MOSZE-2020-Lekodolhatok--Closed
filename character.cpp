#include "character.h"
#include <fstream>

//konstruktor
Character::Character(const std::string& name, int hp, const int dmg) :Name(name), HP(hp), DMG(dmg) {}

//getter
const std::string& Character::getName() const {
	return Character::Name;
}

//ha a tamadas soran az eletero 0 ala csokken, akkor az uj eletero 0 lesz, 
//egyebkent kivonodik belole a tamado ero
void Character::attackEnemy(Character& enemy) const {
	if (enemy.HP - Character::DMG <= 0) {
		enemy.HP = 0;
	}
	else {
		enemy.HP -= Character::DMG;
	}
}

//logikai fuggveny, visszaadja, hogy a karakter meghalt-e
bool Character::isDead() const {
	return Character::HP <= 0;
}


Character Character::parseUnit(const std::string& fname) {
	std::string name;
	int hp = 0;
	int dmg = 0;
	std::string line;
	const std::string lineTypeName = "\"name\"";
	const std::string lineTypeHp = "\"hp\"";
	const std::string lineTypeDmg = "\"dmg\"";
	int findItem = 0;

	std::ifstream unit("units/" + fname);

	if (!unit.fail() && unit.is_open()) {

		while (std::getline(unit, line))
		{
			if (line.find(lineTypeName) != std::string::npos) {
				line.erase(0, line.find(lineTypeName) + lineTypeName.size());
				line.erase(0, line.find("\"") + 1);
				findItem = line.find("\"");
				line.erase(findItem, findItem + 1);
				name = line;
			}
			else if (line.find(lineTypeHp) != std::string::npos) {
				line.erase(0, line.find(lineTypeHp) + lineTypeHp.size());
				line.erase(0, line.find(":") + 1);
				findItem = line.find(",");
				line.erase(findItem, findItem + 1);
				hp = std::stoi(line);
			}
			else if (line.find(lineTypeDmg) != std::string::npos) {
				line.erase(0, line.find(lineTypeDmg) + lineTypeDmg.size());
				line.erase(0, line.find(":") + 1);
				dmg = std::stoi(line);
			}
		}
	}
	else {
		throw std::runtime_error("Could not open file: " + fname); ;
	}
	return Character(name, hp, dmg);
}

//visszaadja a maradek eleterot
const int& Character::remainingHP() const {
	return Character::HP;
}


std::ostream& operator<<(std::ostream& os, const Character& ch) {
	os << ch.Name << ": HP: " << ch.HP << ", DMG: " << ch.DMG << std::endl;
	return os;
}
