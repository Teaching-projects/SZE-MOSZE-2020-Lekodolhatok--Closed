#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>

class Character {
    const std::string Name;
    int HP;
    const int DMG;
public:
    Character(const std::string& name, int hp, int dmg);
    const std::string& getName() const;
    const int& remainingHP() const;
    void attackEnemy(Character& enemy) const;
    bool isDead() const;
    static Character parseUnit(const std::string& fname);
    friend std::ostream& operator<<(std::ostream& os, const Character& dt);
};
#endif // !CHARACTER_H
