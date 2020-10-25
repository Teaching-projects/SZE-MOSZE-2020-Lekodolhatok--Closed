#include <gtest/gtest.h>
#include "../jsonparser.h"
#include <any>
#include <map>
#include <string>
#include <fstream>

TEST(JsonParser, FileName) {
    std::map<std::string, std::string> example;
    example.insert(std::pair<std::string, std::string>("name", "Kakarott"));
    example.insert(std::pair<std::string, std::string>("hp", "50000"));
    example.insert(std::pair<std::string, std::string>("dmg", "9000"));

    std::string s = "../units/kakarott.json";
    std::map<std::string, std::string> result = Json::ParseUnitFileName(s);
    ASSERT_EQ(example, result);
};
TEST(JsonParser, FromStream) {
    std::map<std::string, std::string> example;
    example.insert(std::pair<std::string, std::string>("name", "Kakarott"));
    example.insert(std::pair<std::string, std::string>("hp", "50000"));
    example.insert(std::pair<std::string, std::string>("dmg", "9000"));

    std::ifstream unit("../units/kakarott.json");
    std::map<std::string, std::string> result = Json::ParseUnitStream(unit);
    ASSERT_EQ(example, result);
};
TEST(JsonParser, FromString) {
    std::map<std::string, std::string> example;
    example.insert(std::pair<std::string, std::string>("name", "Kakarott"));
    example.insert(std::pair<std::string, std::string>("hp", "50000"));
    example.insert(std::pair<std::string, std::string>("dmg", "9000"));

    std::string s = "{\"name\" : \"Kakarott\",\"hp\" : \"50000\",\"dmg\" : \"9000\"}";
    std::map<std::string, std::string> result = Json::ParseUnitString(s);
    ASSERT_EQ(example, result);
};
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}