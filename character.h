#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>

class Character {
    const std::string Name;
    int HP;
    int DMG;
public:
    Character(const std::string& name, int hp, int dmg);
    std::string getName() const;
    void attackEnemy(Character& enemy) const;
    bool isDead() const;
    friend std::ostream& operator<<(std::ostream& os, const Character& dt);
};
#endif // !CHARACTER_H
