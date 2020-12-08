#include <gtest/gtest.h>
#include <iostream>
#include "../character.h"
#include <map>
#include <string>

TEST(Character, getNameTest) {

	std::string example = "Kakarott";

	Character result = Character("Kakarott", 50000, 9000, 10.0);

	ASSERT_EQ(example, result.getName());
};
TEST(Character, remainingHPTest) {

	int example = 50000;

	Character result = Character("Kakarott", 50000, 9000, 10.0);

	ASSERT_EQ(example, result.remainingHP());
};
TEST(Character, attackByTimerTest) {
	int example = 32000;

	Character enemy = Character("Vakarott", 50000, 9000, 5.0);
	Character result = Character("Kakarott", 50000, 9000, 10.0);

	for (int i = 0; i < 20; i++)
	{
		result.attackByTimer(enemy, i);
	}

	ASSERT_EQ(example, enemy.remainingHP());
};
TEST(Character, isDeadTest) {
	bool example = true;

	Character result = Character("Kakarott", -1, 9000, 10.0);

	ASSERT_EQ(example, result.isDead());

	bool example2 = false;
	Character result2 = Character("Kakarott", 50000, 9000, 10.0);
	ASSERT_EQ(example2, result2.isDead());


};
TEST(Character, ParseUnitTest) {
	Character example = Character("Kakarott", 50000, 9000, 10.0);

	Character result = Character::parseUnit("kakarott.json");

	ASSERT_EQ(example, result.isDead());
};
int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}