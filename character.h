/**
 * \class Characters
 *
 * \brief Characters class
 *
 * This class declares the characters object, which has four parameters at the moment.  The characters class can also read from a JSON file.
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

class Character {
	const std::string Name; ///< This is hte name ofg the character
	int MaxHP; ///< maximalis eletero
	int HP; ///< The health of the hero
	int DMG; ///< The amount of damage he can hits with
	int Level = 1; ///< aktualis szint, kezdeti erteke 1
	int XP = 0; ///< aktualis pontok, kezdeti erteke 0
	int levelUp(); ///< szintnoveles
	const int AttackSpeed; ///< This is the attackspeed of the character
	void attackEnemy(Character& enemy);///< This method can take a damage to another character if his/her Health is not zero
public:
	Character(const std::string& name, int hp, const int dmg, const int attackspeed);///< The constructor sets the parameters of the character
	const std::string& getName() const;///< Const getter of the character's name
	const int& remainingHP() const;///< Return remaining HP
	void attackByTimer(Character& enemy, int time); ///< Call attackEnemy by timer
	bool isDead() const;///< logikai fuggveny, visszaadja, hogy a karakter meghalt-e
	static Character parseUnit(const std::string& fname); ///< Parsing an Unit from JSON file
	friend std::ostream& operator<<(std::ostream& os, const Character& dt); ///< Override << operator
	friend bool operator==(const Character& en, const Character& dt); ///< Override == operator
	int getMaxHP() const; ///< Return MaxHP
	int getDMG() const; ///< Return DMG
	int getLevel() const; ///< Return Level
	int getXP() const; ///< Return XP
	const int getAttackSpeed() const; ///< Return AttackSpeed
};
#endif // !CHARACTER_H
