#include "JSON.h"
#include <algorithm>

JSON::JSON(const mapType& m) : Map(m) {};


JSON JSON::parseFromStream(std::ifstream& unit) {
	mapType d;
	std::string line;
	if (!unit.fail() && unit.is_open()) {
		while (std::getline(unit, line))
		{
			char* c = new char[line.length() + 1];
			for (int i = 0; i < line.size(); i++)
			{
				c[i] = line[i];
			}
			std::map<std::string, std::string> seged = JSON::parseFromString(c);
			d.insert(seged.begin(), seged.end());
			delete[] c;

		}
	}
	return JSON(d);
}
bool JSON::count(const std::string& key) const {
	return Map.count(key);
}
std::map<std::string, std::string> JSON::parseFromString(char*& c) {
	std::string line(c);
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