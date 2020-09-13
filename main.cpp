#include <iostream>
#include "character.h"
#include <list>

using namespace std;

int main(int argc, char* argv[]) {

	list<Character> characters;

	for (int i = 0; i < argc/3; i++)
	{
		characters.push_back(Character((argv[(i*2) + 1], argv[(i*2) + 2], argv[(i*2) + 3]));
	}

//	Character ch1("Maple", 150, 10);
	//Character ch2("Sally", 45, 30);

	std::cout << characters[0];
	std::cout << characters[0];

	ch2.AttackEnemy(ch1);

	do
	{

	} while (!ch1.isDead() || !ch2.isDead());
}