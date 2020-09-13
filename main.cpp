#include <iostream>
#include "character.h"

using namespace std;

int main() {
	Character ch1 = new Character("Maple", 150, 10);
	Character ch2 = new Character("Sally", 45, 30);

	std::cout << ch1;
	std::cout << ch2;
}