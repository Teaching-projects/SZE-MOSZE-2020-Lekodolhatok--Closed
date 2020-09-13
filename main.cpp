#include <iostream>
#include "character.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {

	vector<Character> characters;
	for (int i = 0; i < argc / 3; i++)
	{
		std::string name(argv[(i * 2) + 1 + i]);
		int hp = std::atoi(argv[(i * 2) + 2 + i]);
		int dmg = std::atoi(argv[(i * 2) + 3 + i]);
		characters.push_back(Character(name, hp, dmg));
	}

	for (auto character : characters)
	{
		cout << character;
	}

	bool isDead = false;
	int roundCounter = 0;
	do
	{

		if (roundCounter + 1 >= characters.size()) {
			characters[roundCounter].AttackEnemy(characters[0]);
			roundCounter = 0;
		}
		else {
			characters[roundCounter].AttackEnemy(characters[roundCounter + 1]);
			roundCounter += 1;
		}
		for (auto character : characters)
		{
			cout << character;
			if (character.isDead()) {
				isDead = true;
			}
		}
	} while (!isDead);
}