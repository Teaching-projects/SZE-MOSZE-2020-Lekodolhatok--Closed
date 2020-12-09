#ifndef JSON_H
#define JSON_H

#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <variant>
#include <list>
typedef std::map<std::string, std::variant<std::string, int, double>> mapType;
typedef std::pair<std::string, std::variant<std::string, int, double>> pairType;
typedef std::variant<std::string, int> valueType;



class JSON {
private:
	mapType Map;

	static bool isNumeric(const std::string& input);
	JSON(const mapType& m);
public:
	static std::map<std::string, std::string> parseFromString(std::string&);
	static JSON parseFromFile(char*&);
	static JSON parseFromStream(std::ifstream&);
	bool count(const std::string& key) const;

	typedef std::list<std::variant<std::string, int, double>> list;
	template <typename T>
	inline typename std::enable_if<std::is_same<T, JSON::list>::value, JSON::list>::type get(const std::string& key)
	{
		if (!Map.count(key))
		{
			throw "No json key found!";
		}

		JSON::list monsters;

		std::string input_list = std::get<std::string>(Map[key]);
		std::string value;

		int pos = 0;

		while (pos < (int)input_list.length())
		{
			int comma = input_list.find(',', pos);
			if (comma < 0)
			{
				comma = (int)input_list.length();
			}

			value = input_list.substr(pos, comma - pos);
			monsters.push_back(value);

			pos = comma + 1;
		}

		return monsters;
	}

	template <typename T>
	inline typename std::enable_if<!std::is_same<T, JSON::list>::value, T>::type get(const std::string& key)
	{
		if (Map.find(key) == Map.end()) throw "Wrong JSON key!";
		try {
			return std::get<T>(Map[key]);
		}
		catch (const std::exception& e) {
			throw ParseException("Wrong JSON type!");
		}
	}



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
