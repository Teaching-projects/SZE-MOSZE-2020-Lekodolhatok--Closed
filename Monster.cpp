#include "Monster.h"
#include <fstream>
#include <cmath>

//Constructor of monster class
Monster::Monster(const std::string& name, int hp, const int dmg, const int attackspeed) :Name(name), HP(hp), DMG(dmg), AttackSpeed(attackspeed) {};

//Getter of monster's name
const std::string& Monster::getName() const {
	return Monster::Name;
}

//visszaadja a maradek eleterot
const int& Monster::getHealthPoints() const {
	return Monster::HP;
}

const int& Monster::getDamage() const {
	return Monster::DMG;
}

void Monster::setDMG(int d) {
	this->DMG = d;
}

void Monster::setHP(int hp) {
	this->HP = hp;
}

void Monster::getAttacked(const int damage) {
	HP -= damage;
	if (HP < 0) {
		HP = 0;
	}
}

const double Monster::getAttackCoolDown() const {
	return Monster::AttackSpeed;
}

void Monster::fightTilDeath(Monster& other) {
	double player1 = this->getAttackCoolDown();
	double player2 = other.getAttackCoolDown();

	while (this->isAlive() && other.isAlive())
	{
		if (player1 >= player2)
		{
			player1 -= player2;
			player2 = 0;
		}
		else
		{
			player2 -= player1;
			player1 = 0;

		}

		if ((player1 == 0) && (player2 != 0))
		{
			this->Attack(other);
			player1 = this->getAttackCoolDown();
		}
		else if ((player2 == 0) && (player1 != 0))
		{
			other.Attack(*this);
			player2 = other.getAttackCoolDown();
		}
		else if ((player1 == 0) && (player2 == 0))
		{
			this->Attack(other);

			if (other.isAlive())
			{
				other.Attack(*this);

			}
			else
			{
				break;
			}
			player1 = this->getAttackCoolDown();
			player2 = other.getAttackCoolDown();
		}
	}
}

//logikai fuggveny, visszaadja, hogy a karakter meghalt-e
bool Monster::isAlive() const {
	return Monster::HP > 0 ? true : false;
}
 
void Monster::attackByTimer(Monster& enemy, int time) {
	if (time % Monster::AttackSpeed == 0) {
		Monster::Attack(enemy);
	}
}

//ha a tamadas soran az eletero 0 ala csokken, akkor az uj eletero 0 lesz, 
//egyebkent kivonodik belole a tamado ero
/*virtual void Monster::Attack(Monster& enemy) {
	if (enemy.HP - Monster::DMG <= 0) {
		enemy.HP = 0;
		Monster::XP = Monster::XP + enemy.HP;
	}
	else {
		enemy.HP -= Monster::DMG;
		Monster::XP = Monster::XP + Monster::DMG;
	}

	if (Monster::XP >= 100) {
		Monster::levelUp();
	}
}*/


//Parsing an Unit from JSON file
Monster Monster::parse(const std::string& fname) {
	std::string name;
	int hp = 0;
	int dmg = 0;
	int attackspeed=0;
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
				attackspeed = std::stoi(line);
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
	return Monster(name, hp, dmg, attackspeed);
}
void Monster::Attack(Monster& enemy) {
	enemy.getAttacked(this->getDamage());
}

std::ostream& operator<<(std::ostream& os, const Monster& ch) {
	os << ch.Name << ": HP: " << ch.HP << ", DMG: " << ch.DMG << std::endl;
	return os;
}
