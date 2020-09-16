#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>

class Character {
    const std::string Name;
    int HP;
    int DMG;
public:
    Character(const std::string& name, const int& hp, const int& dmg);
    ~Character();
    const std::string& getName();
    void attackEnemy(Character& enemy);
    bool isDead() const;
    friend std::ostream& operator<<(std::ostream& os, const Character& dt);
};
#endif // !CHARACTER_H