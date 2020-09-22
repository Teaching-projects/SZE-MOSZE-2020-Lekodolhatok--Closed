#include <iostream>
#include "character.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 7) {
        cout << "Bad parameters!" << endl;
        cout << "Using: ./a.out [Player1 name] [Player1 hp] [Player1 dmg] [Player2 name] [Player2 hp] [Player2 dmg]" << endl;
        return 0;
    }
    vector<Character> characters;
    for (int i = 0; i < argc / 3; i++)
    {
        std::string name(argv[(3 * i + 1)]);
        int hp = std::atoi(argv[(i * 2) + 2 + i]);
        int dmg = std::atoi(argv[(i * 2) + 3 + i]);
        characters.push_back(Character(name, hp, dmg));
    }

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
            cout << character;
            if (character.isDead()) {
                isDead = true;
            }
        }
    } while (!isDead);

    if (characters[0].isDead()) {
        cout << characters[0].getName() << " died. " << characters[1].getName() << " win." << endl;
    }
    else {
        cout << characters[1].getName() << " died. " << characters[0].getName() << " win." << endl;
    }
}