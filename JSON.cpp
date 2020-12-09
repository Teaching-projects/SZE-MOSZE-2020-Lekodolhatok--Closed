#include "JSON.h"
#include <variant>
#include <algorithm>

JSON::JSON(const mapType& m) : Map(m) {};


JSON JSON::parseFromStream(std::ifstream& unit) {
	mapType d;
	std::string line;
	if (!unit.fail() && unit.is_open()) {
		while (std::getline(unit, line))
		{
			std::map<std::string, std::string> seged = JSON::parseFromString(line);
			d.insert(seged.begin(), seged.end());
		}
	}
	return JSON(d);
}
bool JSON::count(const std::string& key) const {
	return Map.count(key);
}
std::map<std::string, std::string> JSON::parseFromString(std::string& line) {
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
		fourth = 0;
		bool noend = false;
		bool num = false;
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
			num = true;
		}
		else {
			fourth = line.find("\"", third + 1);
		}
		if (first >= 0 && second >= 0 && third >= 0) {
			std::string key = line.substr(first + 1, second - first - 1);
			std::variant<std::string,int> value;
			if (!noend) {
				if (num) {
					value = std::stoi(line.substr(third + 1, fourth - third - 1));
				}
				else {
					value = line.substr(third + 1, fourth - third - 1);
				}
				
			}
			else {
				if (num) {
					value = std::stoi(line.substr(third + 1));
				}
				else {
					value = line.substr(third + 1);
				}
			}
			value.erase(remove(value.begin(), value.end(), ' '), value.end());
			d.insert(std::pair<std::string,std::variant<std::string,int>>(key, value));
		}
		line.erase(0, fourth + 1);
	} while (first > 0 && second > 0 && third > 0 && fourth > 0);

	return d;
}
JSON JSON::parseFromFile(char*& c) {
	std::string line(c);
	std::ifstream unit(line);
	if (!unit.fail() && unit.is_open()) {
		return JSON::parseFromStream(unit);
	}
	else {
		mapType d;
		d.insert(std::pair<std::string, std::string>("", ""));
		return JSON(d);
	}
}