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
	void AttackEnemy(Character& enemy);
	bool isDead();
	friend std::ostream& operator<<(std::ostream& os, const Character& dt);
};
#endif // !CHARACTER_H
