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
	~Character();
	std::string getName();
	int getHP();
	int getDMG();
	void AttackEnemy(Character* enemy);
};
#endif // !CHARACTER_H
