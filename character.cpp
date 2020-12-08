#include "character.h"
#include <fstream>
#include <cmath>

//szintnoveles
//eletero es tamadoero a 10%-kal no
//maximalis eletero az megvaltozott eletero erteket veszi fel
//XP-t 100-zal csokkentjuk
int Character::levelUp() {
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
//Constructor of character class
Character::Character(const std::string& name, int hp, const int dmg, const int attackspeed) :Name(name), HP(hp), DMG(dmg), AttackSpeed(attackspeed) {
	MaxHP = hp;
}

//Getter of character's name
const std::string& Character::getName() const {
	return Character::Name;
}

void Character::attackByTimer(Character& enemy, int time) {
	if (time % Character::AttackSpeed == 0) {
		Character::attackEnemy(enemy);
	}
}
//ha a tamadas soran az eletero 0 ala csokken, akkor az uj eletero 0 lesz, 
//egyebkent kivonodik belole a tamado ero
void Character::attackEnemy(Character& enemy) {
	if (enemy.HP - Character::DMG <= 0) {
		enemy.HP = 0;
		Character::XP = Character::XP + enemy.HP;
	}
	else {
		enemy.HP -= Character::DMG;
		Character::XP = Character::XP + Character::DMG;
	}

	if (Character::XP >= 100) {
		Character::levelUp();
	}
}

//logikai fuggveny, visszaadja, hogy a karakter meghalt-e
bool Character::isDead() const {
	return Character::HP <= 0 ? true : false;
}


//Parsing an Unit from JSON file
Character Character::parseUnit(const std::string& fname) {
	std::string name;
	int hp = 0;
	int dmg = 0;
	double attackspeed = 0.0;
	std::string line;
	const std::string lineTypeName = "\"name\"";
	const std::string lineTypeHp = "\"hp\"";
	const std::string lineTypeDmg = "\"dmg\"";
	const std::string lineTypeAS = "\"attackcooldown\"";

	std::ifstream unit("units/" + fname);

	if (!unit.fail() && unit.is_open()) {

		while (std::getline(unit, line))
		{
			if (line.find(lineTypeName) != std::string::npos) {
				line.erase(0, line.find(lineTypeName) + lineTypeName.size());
				line.erase(0, line.find("\"") + 1);
				int findItem = line.find("\"");
				line.erase(findItem, findItem + 1);
				name = line;
			}
			else if (line.find(lineTypeHp) != std::string::npos) {
				line.erase(0, line.find(lineTypeHp) + lineTypeHp.size());
				line.erase(0, line.find(":") + 1);
				int findItem = line.find(",");
				line.erase(findItem, findItem + 1);
				hp = std::stoi(line);
			}
			else if (line.find(lineTypeAS) != std::string::npos) {
				line.erase(0, line.find(lineTypeAS) + lineTypeAS.size());
				line.erase(0, line.find(":") + 1);
				int findItem = line.find(",");
				line.erase(findItem, findItem + 1);
				attackspeed = std::stod(line);
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
	return Character(name, hp, dmg, attackspeed);
}

//visszaadja a maradek eleterot
const int& Character::remainingHP() const {
	return Character::HP;
}
int Character::getMaxHP() const {
	return MaxHP;
}
int Character::getDMG() const {
	return DMG;
}
int Character::getLevel() const {
	return Level;
}
int Character::getXP() const {
	return XP;
}
const int Character::getAttackSpeed() const {
	return AttackSpeed;
}


std::ostream& operator<<(std::ostream& os, const Character& ch) {
	os << ch.Name << ": HP: " << ch.HP << ", DMG: " << ch.DMG << ", AS: " << ch.AttackSpeed << std::endl;
	return os;
}
bool operator==(const Character& en, const Character& dt) {
	if (en.getName() == dt.getName() || en.remainingHP() == dt.remainingHP() || en.getMaxHP() == dt.getMaxHP()
		|| en.getDMG() == dt.getDMG() || en.getLevel() == dt.getLevel() || en.getXP() == dt.getXP()
		|| en.getAttackSpeed() == dt.getAttackSpeed()) {
		return true;
	}
	else {
		return false;
	}
}

