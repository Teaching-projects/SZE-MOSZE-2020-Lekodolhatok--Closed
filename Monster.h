/**
 * \class Monsters
 *
 * \brief Monsters class
 *
 * This class declares the monsters object, which has four parameters at the moment.  The Hero class can also read from a JSON file.
 *
 * \author Lekodolhatok
 *
 * \version 1.1
 *
 * \date 2020/10/15 23:48
 *
 */

#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include <string>
#include "JSON.h"

 //This is the class of the monsters
class Monster {
	const std::string Name; ///< This is the name of the monster
	int HP; ///< The health of the monster
	int DMG; ///<The amount of damage he can hits with
	const int AttackSpeed; ///<This is the attackspeed of the monster
	/**
			 * \brief Taking damage to a target monster
			 *
			 * \param He waits for a monster type enemy
			 */
public:
	Monster(const std::string& name, int hp, const int dmg, const int attackspeed);///<The constructor sets the parameters of the monster

	const std::string& getName() const;///< Const getter of the monster's name

	const int& getHealthPoints() const;

	const int& getDamage() const;

	void getAttacked(const int damage);

	const double getAttackCoolDown() const;

	void fightTilDeath(Monster& other);

	virtual void Attack(Monster& enemy);///< This method can take a damage to another monster if his/her Health is not zero

	void setDMG(int d);

	void setHP(int hp);

	bool isAlive() const;
	/**
	 * \brief Unit parsing from a JSON file.
	 *
	 * \param The string of the filename
	 *
	 * \return Returns with a monster type, with monster parameters.
	 */

	void attackByTimer(Monster& enemy, int time);
	/**
	 * \brief This checks if the unit is dead or not
	 *
	 * \return If unit health point is zero or lower. If lower than zero, it sets to default zero.
	 */
	
	static Monster parse(std::string fname); //elemzes
	friend std::ostream& operator<<(std::ostream& os, const Monster& dt);

};
#endif // !MONSTER_H
