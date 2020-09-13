#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>

class Character {
	std::string Name;
	int HP;
	int DMG;
public:
	Character(std::string name, int hp, int dmg);
	std::string getName();
	int getHP();
	int getDMG();
};
#endif // !CHARACTER_H