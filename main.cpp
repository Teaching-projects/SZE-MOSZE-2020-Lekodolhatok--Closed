#include <iostream>
#include "character.h"
#include <vector>
#include <exception>

using namespace std;
class FileManager : public exception
{
	virtual const char* fileNotFound() const throw()
	{
		return "File is not found!";
	}
} myex;

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Bad parameters!" << endl;
		cout << "Using: ./a.out [Player1 file] [Player2 file]" << endl;
		return 0;
	}
	vector<Character> characters;
	try
	{
		for (int i = 0; i < 1; i++)
		{
			characters.push_back(Character::parseUnit("kakarott.json"));
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	characters.push_back(Character::parseUnit("vakarott.json"));
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
			if (character.isDead()) {
				isDead = true;
			}
		}
	} while (!isDead);
	for (const auto& character : characters)
	{
		if (!character.isDead()) {
			cout << character.getName() << " win. Remaining HP: " << character.remainingHP() << endl;
		}
	}
}