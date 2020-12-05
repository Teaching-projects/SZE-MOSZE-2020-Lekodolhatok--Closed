#ifndef JSON_H
#define JSON_H
#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <variant>
class Json {
public:
	static std::map<std::string, std::string> ParseUnitString(std::string&);
	static std::map<std::string, std::string> ParseUnitFileName(std::string&);
	static std::map<std::string, std::string> ParseUnitStream(std::ifstream&);
};

#endif // !JSON_H
