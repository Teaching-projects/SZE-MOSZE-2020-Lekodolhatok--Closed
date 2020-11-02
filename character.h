#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>

//Character osztaly letrehozasa
class Character {
	const std::string Name; //karakter neve
	double MaxHP; //maximalis eletero
	double HP; //eletero
	double DMG; //tamadoero
	int Level = 1; //aktualis szint, kezdeti erteke 1
	int XP = 0; //aktualis pontok, kezdeti erteke 0
	double levelUp(); //szintnoveles
public:
	Character(const std::string& name, int hp, int dmg); //konstruktor
	const std::string& getName() const; //getter
	const double& remainingHP() const; //maradek eletero
	void attackEnemy(Character& enemy); //ellenseg tamadasa
	bool isDead() const; //meghalt-e a karakter
	static Character parseUnit(const std::string& fname); //elemzes
	friend std::ostream& operator<<(std::ostream& os, const Character& dt);
};
#endif // !CHARACTER_H
