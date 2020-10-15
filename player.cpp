#include "player.h"
#include <fstream>

//konstruktor
Player::Player(const std::string& name, int hp, const int dmg) :Name(name), HP(hp), DMG(dmg) {
    Player::MaxHP=HP;
}

//getter
const std::string& Player::getName() const {
	return Player::Name;
}

//szintnoveles
//eletero es tamadoero a 10%-kal no
//maximalis eletero az megvaltozott eletero erteket veszi fel
//XP-t 100-zal csokkentjuk
int& Player::levelUp(){
    Player::HP = Player::MaxHP*1.1*(Player::Level-1);
    Player::DMG = Player::DMG*1.1*(Palyer::Level-1);
    Player::MaxHP = Player::HP;
    Playe::Level++;
    return XP-100;
}

//ha a tamadas soran az eletero 0 ala csokken, akkor az uj eletero 0 lesz, 
//egyebkent kivonodik belole a tamado ero
void Player::attackEnemy(Player& enemy) const {
	if (enemy.HP - Player::DMG <= 0) {
		enemy.HP = 0;
	}
	else {
		enemy.HP -= Player::DMG;
        Player::XP += Player::DMG;
        if (Player::XP>=100){
            Player::levelUp();
        }
	}
}

//visszaadja, hogy a karakter halott-e
bool Player::isDead() const {
	return Player::HP <= 0;
}


Player Player::parseUnit(const std::string& fname) {
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
	return Player(name, hp, dmg);
}

//megadja a maradek eleterot
const int& Player::remainingHP() const {
	return Player::HP;
}


std::ostream& operator<<(std::ostream& os, const Player& ch) {
	os << ch.Name << ": HP: " << ch.HP << ", DMG: " << ch.DMG << std::endl;
	return os;
}
