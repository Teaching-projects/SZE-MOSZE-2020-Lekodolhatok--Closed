#ifndef JSON_H
#define JSON_H

#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <variant>

class JSON {
private:
	static bool isNumeric(const std::string& input);
public:
	static std::map<std::string, std::string> parseFromString(std::string&);
	static std::map<std::string, std::string> parseFromFile(std::string&);
	static std::map<std::string, std::string> parseFromStream(std::ifstream&);

	class ParseException : public std::runtime_error
	{
	public:
		/**
		 * \brief This is the constructor of the parser exception.
		*/
		ParseException(const std::string& message /** [in] The error message. */) : std::runtime_error(message) {}
	};


};

#endif // !JSON_H
