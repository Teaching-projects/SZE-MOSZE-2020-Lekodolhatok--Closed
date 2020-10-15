#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>

//Character osztaly letrehozasa
class Character {
    const std::string Name; //karakter neve
    int HP; //eletero
    const int DMG; //tamadoero
public:
    Character(const std::string& name, int hp, int dmg); //konstruktor
    const std::string& getName() const; //getter
    const int& remainingHP() const; //maradek eletero
    void attackEnemy(Character& enemy) const; //ellenseg tamadasa
    bool isDead() const; //meghalt-e a karakter
    static Character parseUnit(const std::string& fname); //elemzes
    friend std::ostream& operator<<(std::ostream& os, const Character& dt);
};
#endif // !CHARACTER_H
