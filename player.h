#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>

class Player {
    const std::string Name; //jatekos neve
    int MaxHP; //maximalis eletero
    int HP; //jelenlegi eletero
    const int DMG; //tamado ero
    int Level = 1; //aktualis szint, kezdeti erteke 1
    int XP = 0; //aktualis pontok, kezdeti erteke 0
public:
    Player(const std::string& name, int hp, int dmg); //konstruktor
    const std::string& getName() const; //getter
    const int& remainingHP() const; //maradek eletero
    void attackEnemy(Player& enemy) const; //tamadas
    bool isDead() const; //halott-e a karakter
    static Player parseUnit(const std::string& fname); //elemzes
    friend std::ostream& operator<<(std::ostream& os, const Player& dt);
    int& levelUp(); //szintnoveles
};
#endif // !PLAYER_H
