#ifndef JSON_H
#define JSON_H
#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <any>
#include <variant>
class Json {
private:
	std::pair<std::string, std::any>& Pairs(const std::string& line);
public:
	static std::map<std::string, std::any> ParseUnit(std::string&);
	static std::map<std::string, std::any>& ParseUnit(std::ifstream&);
};

#endif // !JSON_H
