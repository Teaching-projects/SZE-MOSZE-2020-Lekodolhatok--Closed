#include "character.h"

Character::Character(const std::string& name, int hp, const int dmg) :Name(name), HP(hp), DMG(dmg) {}

const std::string& Character::getName() const {
	return Character::Name;
}

void Character::attackEnemy(Character& enemy) const {
	//std::cout << Character::Name << " -> " << enemy.Name << std::endl;
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
Character Character::parseUnit(std::string fname) {
	std::string name;
	int hp = 0;
	int dmg = 0;
	try
	{
		std::string line;
		std::string lineType;
		std::ifstream unit("units/" + fname);

		if (!unit.fail() && unit.is_open()) {

			while (std::getline(unit, line))
			{
				if (line.find("\"name\"") != std::string::npos) {
					lineType = "\"name\"";
					line.erase(0, line.find(lineType) + lineType.length());
					line.erase(0, line.find("\"") + 1);
					line.erase(line.find("\""), line.find("\"") + 1);
					name = line;
				}
				else if (line.find("\"hp\"") != std::string::npos) {
					lineType = "\"hp\"";
					line.erase(0, line.find(lineType) + lineType.length());
					line.erase(0, line.find(":") + 1);
					line.erase(line.find(","), line.find(",") + 1);
					hp = std::atoi(line.c_str());
				}
				else if (line.find("\"dmg\"") != std::string::npos) {
					lineType = "\"dmg\"";
					line.erase(0, line.find(lineType) + lineType.length());
					line.erase(0, line.find(":") + 1);
					dmg = std::atoi(line.c_str());
				}
			}
		}
		std::cout << std::endl;
	}
	catch (const std::exception&)
	{

	}
	return Character(name, hp, dmg);
}
const int& Character::remainingHP() const {
	return Character::HP;
}
std::ostream& operator<<(std::ostream& os, const Character& ch) {
	os << ch.Name << ": HP: " << ch.HP << ", DMG: " << ch.DMG << std::endl;
	return os;
}
