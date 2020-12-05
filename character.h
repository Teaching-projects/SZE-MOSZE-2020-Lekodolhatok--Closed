/**
 * \class Characters
 *
 * \brief Characters class
 *
 * This class declares the characters object, which has four parameters at the moment.  The Hero class can also read from a JSON file.
 *
 * \author Lekodolhatok
 *
 * \version 1.1
 *
 * \date 2020/10/15 23:48
 *
 */

#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>

 //This is the class of the characters
class Character {
	const std::string Name; ///< This is hte name ofg the character
	int MaxHP; //maximalis eletero
	int HP; ///< The health of the hero
	int DMG; ///<The amount of damage he can hits with
	int Level = 1; //aktualis szint, kezdeti erteke 1
	int XP = 0; //aktualis pontok, kezdeti erteke 0
	int levelUp(); //szintnoveles
	const int AttackSpeed; ///<This is the attackspeed of the character
	/**
			 * \brief Taking damage to a target character
			 *
			 * \param He waits for a character type enemy
			 */
	void attackEnemy(Character& enemy);///< This method can take a damage to another character if his/her Health is not zero
public:
	Character(const std::string& name, int hp, const int dmg, const int attackspeed);///<The constructor sets the parameters of the character
	const std::string& getName() const;///< Const getter of the character's name
	const int& remainingHP() const;
	void attackByTimer(Character& enemy, int time);
	/**
	 * \brief This checks if the unit is dead or not
	 *
	 * \return If unit health point is zero or lower. If lower than zero, it sets to default zero.
	 */
	bool isDead() const;
	/**
	 * \brief Unit parsing from a JSON file.
	 *
	 * \param The string of the filename
	 *
	 * \return Returns with a character type, with character parameters.
	 */
	static Character parseUnit(const std::string& fname); //elemzes
	friend std::ostream& operator<<(std::ostream& os, const Character& dt);

};
#endif // !CHARACTER_H
