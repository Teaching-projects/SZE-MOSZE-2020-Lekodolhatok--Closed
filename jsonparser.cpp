#include "jsonparser.h"

std::map<std::string, std::any>& Json::ParseUnit(std::ifstream& unit) {
	std::map<std::string, std::any> d;
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

			std::map<std::string, std::any> seged = Json::ParseUnit(line);
			d.insert(seged.begin(), seged.end());
			//d.insert(seged.begin(), seged.end());
			/*
			int first = line.find("\"", 0);
			int second = line.find("\"", first + 1);
			int third = line.find("\"", second + 1);
			int fourth;
			bool isNumber = false;
			if (third <= 0) {
				third = line.find(":", second + 1);
				fourth = line.find(",", third + 1);
				isNumber = true;
			}
			else {
				fourth = line.find("\"", third + 1);
			}
			if (first >= 0 && second >= 0 && third >= 0) {
				std::cout << "1:" << line.substr(first + 1, second - first - 1) << std::endl;
				std::cout << "2:" << line.substr(third + 1, fourth - third - 1) << std::endl;
				std::string key = line.substr(first + 1, second - first - 1);
				std::string value;
				if (!isNumber) {
					value = line.substr(third + 1, fourth - third - 1);
				}
				else {
					value = std::stod(line.substr(third + 1));
				}
				d.insert(std::pair<std::string, std::any>(key, value));
			}
			std::cout << "LINE.1" << line << "\t";
			line.erase(0, fourth + 1);
			std::cout << "LINE.2" << line << "\n";*/
		}
	}
	for (auto elem : d)
	{
		if (elem.second.type() == typeid(double)) {
			std::cout << elem.first << std::any_cast<double>(elem.second) << "\n";
		}
		else if (elem.second.type() == typeid(std::string)) {
			std::cout << elem.first << std::any_cast<std::string>(elem.second) << "\n";
		}
	}
	return d;
}
std::map<std::string, std::any> Json::ParseUnit(std::string& line) {
	std::ifstream unit("units/" + line);
	if (!unit.fail() && unit.is_open()) {
		Json::ParseUnit(unit);
	}

	std::map<std::string, std::any> d;
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
		bool isNumber = false;
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
			isNumber = true;
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
			if (isNumber) {
				d.insert(std::pair<std::string, std::any>(key, std::stod(value)));
			}
			else {
				d.insert(std::pair<std::string, std::any>(key, value));
			}
		}
		line.erase(0, fourth + 1);
	} while (first > 0 && second > 0 && third > 0 && fourth > 0);

	return d;
}