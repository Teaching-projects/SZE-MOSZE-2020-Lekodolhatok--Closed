#include "jsonparser.h"
#include <algorithm>

std::map<std::string, std::string> Json::ParseUnit(std::ifstream& unit) {
	std::map<std::string, std::string> d;
	std::string name;
	int hp = 0;
	int dmg = 0;

	const std::string lineTypeName = "\"name\"";
	const std::string lineTypeHp = "\"hp\"";
	const std::string lineTypeDmg = "\"dmg\"";
	int findItem = 0;

	std::string line;
	if (!unit.fail() && unit.is_open()) {
		while (std::getline(unit, line))
		{
			std::map<std::string, std::string> seged = Json::ParseUnit(line);
			d.insert(seged.begin(), seged.end());
		}
	}
	return d;
}
std::map<std::string, std::string> Json::ParseUnit(std::string& line) {
	std::ifstream unit("units/" + line);
	if (!unit.fail() && unit.is_open()) {
		Json::ParseUnit(unit);
	}

	std::map<std::string, std::string> d;
	int first;
	int second;
	int third;
	int fourth;
	do
	{
		first = line.find("\"", 0);
		second = line.find("\"", first + 1);
		third = line.find("\"", second + 1);
		fourth;
		bool noend = false;
		int nextcomma = line.find(",", second + 1);
		if (nextcomma < 0) {
			nextcomma = line.find("}", second + 1);
			if (nextcomma < 0) {
				noend = true;
			}
		}
		if (third <= 0 || nextcomma < third) {
			third = line.find(":", second + 1);
			fourth = nextcomma;
		}
		else {
			fourth = line.find("\"", third + 1);
		}
		if (first >= 0 && second >= 0 && third >= 0) {
			std::string key = line.substr(first + 1, second - first - 1);
			std::string value;
			if (!noend) {
				value = line.substr(third + 1, fourth - third - 1);
			}
			else {
				value = line.substr(third + 1);
			}
			value.erase(remove(value.begin(), value.end(), ' '), value.end());
			d.insert(std::pair<std::string, std::string>(key, value));
		}
		line.erase(0, fourth + 1);
	} while (first > 0 && second > 0 && third > 0 && fourth > 0);

	return d;
}