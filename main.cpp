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
	//bool isDead = false;
	//aktualis menet szama
	int roundCounter = 0;
	//ciklus addig megy, mig a karakter nem lesz halott
	do
	{
		//isDead = false;
		if (roundCounter == 1) {
			characters[roundCounter].attackEnemy(characters[0]); //akkor a vektor elso karakterevel zajlik le a csata
			roundCounter = 0; //es az aktualis kor erteke 0 lesz
		}
		else { //egyebkent
			characters[roundCounter].attackEnemy(characters[roundCounter + 1]); //a sorban kovetkezo karakter lesz adadva
			roundCounter += 1; //es eggyel no az aktualis kor szama
		}
		/*for (const auto& character : characters) //vegigmegy a ciklus a vektoron
		{
			if (character.isDead()) { //ha a karakter halott
				isDead = character.isDead(); //akkor a valtozo igaz erteket kap
			}
		}*/
	} while (!(characters[0].isDead() || characters[1].isDead()));
	for (const auto& character : characters)//vegigmegy a ciklus a vektoron
	{
		if (!character.isDead()) { //ha a karakter nem halott
			cout << character.getName() << " win. Remaining HP: " << character.remainingHP() << endl;
		} //akkor kiirodik a neve es a maradek eletereje
	}
}
