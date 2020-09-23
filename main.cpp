#include <iostream>
#include "character.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
   /* if (argc != 7) {
        cout << "Bad parameters!" << endl;
        cout << "Using: ./a.out [Player1 name] [Player1 hp] [Player1 dmg] [Player2 name] [Player2 hp] [Player2 dmg]" << endl;
        return 0;
    }*/

    //Character::parseUnit("Kakarott.json");

    vector<Character> characters;
    for (int i = 0; i < 1 ; i++)
    {
        characters.push_back(Character::parseUnit("kakarott.json"));
    }
    characters.push_back(Character::parseUnit("vakarott.json"));

    for (const auto& character : characters)
    {
        cout << character;
    }
    bool isDead = false;
    int roundCounter = 0;
    do
    {
        if (roundCounter + 1 >= characters.size()) {
            characters[roundCounter].attackEnemy(characters[0]);
            roundCounter = 0;
        }
        else {
            characters[roundCounter].attackEnemy(characters[roundCounter + 1]);
            roundCounter += 1;
        }
        for (const auto& character : characters)
        {
            //cout << character;
            if (character.isDead()) {
                isDead = true;
            }
        }
    } while (!isDead);
    for (const auto& character : characters)
    {
        if (!character.isDead()) {
            cout << character.getName() << " win. Remaining HP: "<<character.remainingHP()<<endl;
        }
    }
    /*if (characters[0].isDead()) {
        cout << characters[0].getName() << " died. " << characters[1].getName() << " win." << endl;
    }
    else {
        cout << characters[1].getName() << " died. " << characters[0].getName() << " win." << endl;
    }*/
}