/**
 * \class Json
 *
 * \brief Json class
 *
 * \author Stefka Márton
 *
 */
#ifndef JSON_H
#define JSON_H
#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <variant>
class Json {
public:
	static std::map<std::string, std::string> ParseUnitString(std::string&);///< Parsing Unit from string
	static std::map<std::string, std::string> ParseUnitFileName(std::string&); ///< Parsing Unit from filename
	static std::map<std::string, std::string> ParseUnitStream(std::ifstream&); ///< Parsing Unit from stream
};

#endif // !JSON_H
