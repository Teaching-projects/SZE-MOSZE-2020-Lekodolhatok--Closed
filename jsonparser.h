#ifndef JSON_H
#define JSON_H
#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <variant>
class Json {
public:
	static std::map<std::string, std::string> ParseUnit(std::string&);
	static std::map<std::string, std::string> ParseUnit(std::ifstream&);
};

#endif // !JSON_H
