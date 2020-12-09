#ifndef HERO_H
#define HERO_H

#include "Monster.h"

class Hero : public Monster {
private:
    int MaxHP; //maximalis eletero
    int Level = 1; //aktualis szint, kezdeti erteke 1
	int XP = 0; //aktualis pontok, kezdeti erteke 0
public:
    //constructor
    Hero(const std::string& name, int hp, const int dmg, const int attackspeed);

    int getMaxHealthPoints() const; //getter of maximum health points

    int getLevel() const; //getter of the actual level

    int getXP() const; //getter of the actual value of XP

	int lvlUp(); //szintnoveles

    void Attack(Monster& enemy);

    Hero parse(const std::string& s);

    static Hero parse(const std::string& fileName);
};
#endif // !HERO_H
