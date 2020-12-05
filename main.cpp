#include <iostream>
#include "character.h"
#include <vector>
#include <exception>

using namespace std;

int main(int argc, char* argv[]) {
	//rossz parameterek megadasa
	if (argc != 3) {
		cout << "Bad parameters!" << endl;
		cout << "Using: ./a.out [Character1 file] [Character2 file]" << endl;
		return 1;
	}
	//Character vektor letrehozasa
	vector<Character> characters;
	//vektor feltoltese
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
	//kezdetben a Character nem halott
	//ciklus addig megy, mig a karakter nem lesz halott
	int timer = 0;
	do
	{
		characters[0].attackByTimer(characters[1],timer);
		characters[1].attackByTimer(characters[0],timer);

		timer += 1;
	} while (!(characters[0].isDead() || characters[1].isDead()));

	for (const auto& character : characters)
	{
		if (!character.isDead()) { //ha a karakter nem halott
			cout << character.getName() << " win. Remaining HP: " << character.remainingHP() << endl;
		} //akkor kiirodik a neve es a maradek eletereje
	}
}
