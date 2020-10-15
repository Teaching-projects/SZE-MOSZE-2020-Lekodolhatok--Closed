#include <iostream>
#include "character.h"
#include <vector>
#include <exception>

using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "Bad parameters!" << endl;
		cout << "Using: ./a.out [Player1 file] [Player2 file]" << endl;
		return 1;
	}
	vector<Character> characters;
	try
	{
		for (int i = 1; i < argc; i++)
		{
			characters.push_back(Character::parseUnit(argv[i]));
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
		return 1;
	}
	bool isDead = false;
	int timer = 0;
	do
	{
		characters[0].attackByTimer(characters[1]);
		characters[1].attackByTimer(characters[0]);

		for (const auto& character : characters)
		{
			if (character.isDead()) {
				isDead = true;
			}
		}
		timer += 1;
	} while (!isDead);
	for (const auto& character : characters)
	{
		if (!character.isDead()) {
			cout << character.getName() << " win. Remaining HP: " << character.remainingHP() << endl;
		}
	}
}
