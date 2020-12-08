#include <gtest/gtest.h>
#include "../character.h"
#include <any>
#include <map>
#include <string>
#include <fstream>

TEST(Character, getName) {

	std::string example = "Kakarott";

	Character result = new Character("Kakarott", 50000, 9000, 10.0);

	ASSERT_EQ(example, result.getName());
};
TEST(Character, remainingHP) {

	int example = 50000;

	Character result = new Character("Kakarott", 50000, 9000, 10.0);

	ASSERT_EQ(example, result.remainingHP());
};
TEST(Character, attackByTimer) {
	int example = 32000;

	Character enemy = new Character("Vakarott", 50000, 9000, 5.0);
	Character result = new Character("Kakarott", 50000, 9000, 10.0);

	for (int i = 0; i < 20; i++)
	{
		result.attackByTimer(enemy, i);
	}

	ASSERT_EQ(example, enemy.remainingHP());
};
TEST(Character, isDead) {
	bool example = true;

	Character result = new Character("Kakarott", -1, 9000, 10.0);

	ASSERT_EQ(example, result.isDead());

	bool example2 = false;
	Character result2 = new Character("Kakarott", 50000, 9000, 10.0);
	ASSERT_EQ(example2, result2.isDead());


};
TEST(Character, ParseUnit) {
	Character example = new Character("Kakarott", 50000, 9000, 10.0);

	Character result = Character::parseUnit("kakarott.json");

	ASSERT_EQ(example, result.isDead());
};
int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}